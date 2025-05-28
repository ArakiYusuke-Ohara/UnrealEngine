// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Project/Bullet/BulletBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBulletBase() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
PROJECT_API UClass* Z_Construct_UClass_ABulletBase();
PROJECT_API UClass* Z_Construct_UClass_ABulletBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_Project();
// End Cross Module References

// Begin Class ABulletBase
void ABulletBase::StaticRegisterNativesABulletBase()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABulletBase);
UClass* Z_Construct_UClass_ABulletBase_NoRegister()
{
	return ABulletBase::StaticClass();
}
struct Z_Construct_UClass_ABulletBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Bullet/BulletBase.h" },
		{ "ModuleRelativePath", "Bullet/BulletBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_Life_MetaData[] = {
		{ "Category", "BulletBase" },
		{ "ModuleRelativePath", "Bullet/BulletBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_m_Life;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABulletBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABulletBase_Statics::NewProp_m_Life = { "m_Life", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABulletBase, m_Life), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_Life_MetaData), NewProp_m_Life_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABulletBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABulletBase_Statics::NewProp_m_Life,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABulletBase_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABulletBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABulletBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABulletBase_Statics::ClassParams = {
	&ABulletBase::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ABulletBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ABulletBase_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABulletBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ABulletBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABulletBase()
{
	if (!Z_Registration_Info_UClass_ABulletBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABulletBase.OuterSingleton, Z_Construct_UClass_ABulletBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABulletBase.OuterSingleton;
}
template<> PROJECT_API UClass* StaticClass<ABulletBase>()
{
	return ABulletBase::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABulletBase);
ABulletBase::~ABulletBase() {}
// End Class ABulletBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Bullet_BulletBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABulletBase, ABulletBase::StaticClass, TEXT("ABulletBase"), &Z_Registration_Info_UClass_ABulletBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABulletBase), 797041472U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Bullet_BulletBase_h_2221876731(TEXT("/Script/Project"),
	Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Bullet_BulletBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Bullet_BulletBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
