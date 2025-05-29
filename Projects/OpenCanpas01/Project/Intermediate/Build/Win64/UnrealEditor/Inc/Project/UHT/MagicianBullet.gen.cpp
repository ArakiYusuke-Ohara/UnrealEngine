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
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_Particle_MetaData[] = {
		{ "Category", "MagicianBullet" },
		{ "ModuleRelativePath", "Bullet/MagicianBullet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_EndEffect_MetaData[] = {
		{ "Category", "MagicianBullet" },
		{ "ModuleRelativePath", "Bullet/MagicianBullet.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_Particle;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_EndEffect;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMagicianBullet>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagicianBullet_Statics::NewProp_m_Particle = { "m_Particle", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMagicianBullet, m_Particle), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_Particle_MetaData), NewProp_m_Particle_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagicianBullet_Statics::NewProp_m_EndEffect = { "m_EndEffect", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMagicianBullet, m_EndEffect), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_EndEffect_MetaData), NewProp_m_EndEffect_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMagicianBullet_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicianBullet_Statics::NewProp_m_Particle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicianBullet_Statics::NewProp_m_EndEffect,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMagicianBullet_Statics::PropPointers) < 2048);
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
	Z_Construct_UClass_AMagicianBullet_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AMagicianBullet_Statics::PropPointers),
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
		{ Z_Construct_UClass_AMagicianBullet, AMagicianBullet::StaticClass, TEXT("AMagicianBullet"), &Z_Registration_Info_UClass_AMagicianBullet, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMagicianBullet), 2557630211U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Bullet_MagicianBullet_h_1795453023(TEXT("/Script/Project"),
	Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Bullet_MagicianBullet_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Bullet_MagicianBullet_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
