// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletManager.h"
#include "BulletBase.h"

UBulletManager::UBulletManager()
{
}

UBulletManager::~UBulletManager()
{
}

ABulletBase* UBulletManager::FireBullet(TSubclassOf<ABulletBase> fireBullet, FVector pos, FRotator rot)
{
	// 配列の中から使ってない弾丸を探す
	for (ABulletBase* bullet : m_Bullets)
	{
		// 同じタイプの弾丸か
		if (bullet->IsA(fireBullet))
		{
			// 使われてない弾丸か
			if (!bullet->IsActive())
			{
				// 再利用して発射
				bullet->Fire(pos, rot);
				return bullet;
			}
		}
	}

	// 全て使用済みであれば新しく生成して発射
	ABulletBase* bullet = GetWorld()->SpawnActor<ABulletBase>(fireBullet);
	bullet->Fire(pos, rot);

	// 配列に追加
	m_Bullets.Add(bullet);

	return bullet;
}
