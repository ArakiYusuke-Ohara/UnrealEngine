// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameInstance.h"
#include "../Bullet/BulletManager.h"

void UMainGameInstance::CreateBulletManager()
{
	// まだ生成されてなければ生成
	if (!m_BulletManager)
	{
		// UEのクラス生成はNewObjectを使う
		// 引数は親となるクラス
		m_BulletManager = NewObject<UBulletManager>(this);
		m_BulletManager->AddToRoot();// ガベコレが勝手に消さないようにAddToRootを呼ぶ
	}
}

void UMainGameInstance::DeleteBulletManager()
{
	// 生成されていれば削除
	if (m_BulletManager)
	{
		// ガベコレに戻して消えるようにする
		m_BulletManager->RemoveFromRoot();
		// NewObjectで生成されたクラスは参照を切れば自動で削除される
		m_BulletManager = nullptr;
	}
}

