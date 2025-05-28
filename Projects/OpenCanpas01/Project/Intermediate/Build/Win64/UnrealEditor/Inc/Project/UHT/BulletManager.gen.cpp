// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Project/Bullet/BulletManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBulletManager() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
PROJECT_API UClass* Z_Construct_UClass_UBulletManager();
PROJECT_API UClass* Z_Construct_UClass_UBulletManager_NoRegister();
UPackage* Z_Construct_UPackage__Script_Project();
// End Cross Module References

// Begin Class UBulletManager
void UBulletManager::StaticRegisterNativesUBulletManager()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBulletManager);
UClass* Z_Construct_UClass_UBulletManager_NoRegister()
{
	return UBulletManager::StaticClass();
}
struct Z_Construct_UClass_UBulletManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Bullet/BulletManager.h" },
		{ "ModuleRelativePath", "Bullet/BulletManager.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBulletManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UBulletManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_Project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBulletManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBulletManager_Statics::ClassParams = {
	&UBulletManager::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBulletManager_Statics::Class_MetaDataParams), Z_Construct_UClass_UBulletManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UBulletManager()
{
	if (!Z_Registration_Info_UClass_UBulletManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBulletManager.OuterSingleton, Z_Construct_UClass_UBulletManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBulletManager.OuterSingleton;
}
template<> PROJECT_API UClass* StaticClass<UBulletManager>()
{
	return UBulletManager::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UBulletManager);
// End Class UBulletManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Bullet_BulletManager_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBulletManager, UBulletManager::StaticClass, TEXT("UBulletManager"), &Z_Registration_Info_UClass_UBulletManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBulletManager), 3698849363U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Bullet_BulletManager_h_2538500144(TEXT("/Script/Project"),
	Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Bullet_BulletManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Bullet_BulletManager_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
