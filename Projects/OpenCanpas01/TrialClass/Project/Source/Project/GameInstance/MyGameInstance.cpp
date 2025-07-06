// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "../Bullet/BulletManager.h"

UMyGameInstance::UMyGameInstance()
{
	m_BulletManager = nullptr;
}

void UMyGameInstance::CreateBulletManager()
{
	if (!m_BulletManager)
	{
		m_BulletManager = NewObject<UBulletManager>(this);
		m_BulletManager->AddToRoot();
	}
}

void UMyGameInstance::DeleteBulletManager()
{
	if (m_BulletManager)
	{
		m_BulletManager->RemoveFromRoot();
		m_BulletManager = nullptr;
	}
}
