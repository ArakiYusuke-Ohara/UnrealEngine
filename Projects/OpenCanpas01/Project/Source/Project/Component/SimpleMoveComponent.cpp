// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleMoveComponent.h"
#include "../Stage/Object/SimpleMoveObject.h"

// Sets default values for this component's properties
USimpleMoveComponent::USimpleMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	// UPROPERTY
	m_IsLoop = false;
	m_IsRoundTrip = false;
	m_Time = 0.0f;
	m_MoveCurve = nullptr;

	// PRIVATE
	m_IsStop = false;
	m_Direction = 0;
	m_TimeCount = 0;
	m_StartPos = FVector::Zero();
	m_EndPos = FVector::Zero();
}


// Called when the game starts
void USimpleMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	// 開始位置と終了位置を設定
	if (ASimpleMoveObject* owner = Cast<ASimpleMoveObject>(GetOwner()))
	{
		// 開始位置は配置されている場所
		m_StartPos = owner->GetActorLocation();
		// 終了位置は終了位置用のコンポーネントから取得
		m_EndPos = owner->GetEndPoint()->GetComponentLocation();
	}

	// 向き
	m_Direction = 1;
}


// Called every frame
void USimpleMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	// 停止中は何もしない
	if (m_IsStop) return;

	// 進捗を計算
	float progress = FMath::Clamp(m_TimeCount / m_Time, 0.0f, 1.0f);

	// カーブがあればカーブから取得した値を優先する
	if (m_MoveCurve)
	{
		progress = m_MoveCurve->GetFloatValue(progress);
	}

	// 座標をLerpで取得
	FVector pos = FMath::Lerp(m_StartPos, m_EndPos, progress);


	// オーナーアクターを移動
	if (AActor* owner = GetOwner())
	{
		owner->SetActorLocation(pos);
	}

	// 時間を進める
	m_TimeCount += DeltaTime * m_Direction;

	if (m_TimeCount >= m_Time)
	{
		// ループ
		if (m_IsLoop)
		{
			m_TimeCount = 0.0f;
		}
		// 往復
		else if (m_IsRoundTrip)
		{
			m_TimeCount = m_Time;
			m_Direction = -m_Direction;
		}
		// 停止
		else
		{
			m_IsStop = true;
			m_TimeCount = m_Time;
		}
	}
	else if (m_IsRoundTrip && m_TimeCount <= 0.0f)
	{
		m_TimeCount = 0.0f;
		m_Direction = -m_Direction;
	}
}

