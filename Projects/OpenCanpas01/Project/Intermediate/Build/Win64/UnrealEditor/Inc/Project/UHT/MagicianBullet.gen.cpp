// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Project/Bullet/MagicianBullet.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMagicianBullet() {}

// Begin Cross Module References
PROJECT_API UClass* Z_Construct_UClass_ABulletBase();
PROJECT_API UClass* Z_Construct_UClass_AMagicianBullet();
PROJECT_API UClass* Z_Construct_UClass_AMagicianBullet_NoRegister();
UPackage* Z_Construct_UPackage__Script_Project();
// End Cross Module References

// Begin Class AMagicianBullet
void AMagicianBullet::StaticRegisterNativesAMagicianBullet()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMagicianBullet);
UClass* Z_Construct_UClass_AMagicianBullet_NoRegister()
{
	return AMagicianBullet::StaticClass();
}
struct Z_Construct_UClass_AMagicianBullet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Bullet/MagicianBullet.h" },
		{ "ModuleRelativePath", "Bullet/MagicianBullet.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMagicianBullet>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AMagicianBullet_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABulletBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMagicianBullet_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMagicianBullet_Statics::ClassParams = {
	&AMagicianBullet::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMagicianBullet_Statics::Class_MetaDataParams), Z_Construct_UClass_AMagicianBullet_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMagicianBullet()
{
	if (!Z_Registration_Info_UClass_AMagicianBullet.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMagicianBullet.OuterSingleton, Z_Construct_UClass_AMagicianBullet_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMagicianBullet.OuterSingleton;
}
template<> PROJECT_API UClass* StaticClass<AMagicianBullet>()
{
	return AMagicianBullet::StaticClass();
}
AMagicianBullet::AMagicianBullet() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMagicianBullet);
AMagicianBullet::~AMagicianBullet() {}
// End Class AMagicianBullet

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Bullet_MagicianBullet_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMagicianBullet, AMagicianBullet::StaticClass, TEXT("AMagicianBullet"), &Z_Registration_Info_UClass_AMagicianBullet, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMagicianBullet), 2690051788U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Bullet_MagicianBullet_h_1484047699(TEXT("/Script/Project"),
	Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Bullet_MagicianBullet_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Bullet_MagicianBullet_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
