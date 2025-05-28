// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Project/Magician/Magician.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMagician() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
PROJECT_API UClass* Z_Construct_UClass_AMagician();
PROJECT_API UClass* Z_Construct_UClass_AMagician_NoRegister();
PROJECT_API UClass* Z_Construct_UClass_AMagicianBullet_NoRegister();
UPackage* Z_Construct_UPackage__Script_Project();
// End Cross Module References

// Begin Class AMagician
void AMagician::StaticRegisterNativesAMagician()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMagician);
UClass* Z_Construct_UClass_AMagician_NoRegister()
{
	return AMagician::StaticClass();
}
struct Z_Construct_UClass_AMagician_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Magician/Magician.h" },
		{ "ModuleRelativePath", "Magician/Magician.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_InputMap_MetaData[] = {
		{ "Category", "Magician" },
		{ "ModuleRelativePath", "Magician/Magician.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_MoveAction_MetaData[] = {
		{ "Category", "Magician" },
		{ "ModuleRelativePath", "Magician/Magician.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_JumpAction_MetaData[] = {
		{ "Category", "Magician" },
		{ "ModuleRelativePath", "Magician/Magician.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_FireBulletAction_MetaData[] = {
		{ "Category", "Magician" },
		{ "ModuleRelativePath", "Magician/Magician.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_MoveSpeed_MetaData[] = {
		{ "Category", "Magician" },
		{ "ModuleRelativePath", "Magician/Magician.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_Bullet_MetaData[] = {
		{ "Category", "Magician" },
		{ "ModuleRelativePath", "Magician/Magician.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_InputMap;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_JumpAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_FireBulletAction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_m_MoveSpeed;
	static const UECodeGen_Private::FClassPropertyParams NewProp_m_Bullet;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMagician>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagician_Statics::NewProp_m_InputMap = { "m_InputMap", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMagician, m_InputMap), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_InputMap_MetaData), NewProp_m_InputMap_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagician_Statics::NewProp_m_MoveAction = { "m_MoveAction", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMagician, m_MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_MoveAction_MetaData), NewProp_m_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagician_Statics::NewProp_m_JumpAction = { "m_JumpAction", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMagician, m_JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_JumpAction_MetaData), NewProp_m_JumpAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagician_Statics::NewProp_m_FireBulletAction = { "m_FireBulletAction", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMagician, m_FireBulletAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_FireBulletAction_MetaData), NewProp_m_FireBulletAction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMagician_Statics::NewProp_m_MoveSpeed = { "m_MoveSpeed", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMagician, m_MoveSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_MoveSpeed_MetaData), NewProp_m_MoveSpeed_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMagician_Statics::NewProp_m_Bullet = { "m_Bullet", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMagician, m_Bullet), Z_Construct_UClass_UClass, Z_Construct_UClass_AMagicianBullet_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_Bullet_MetaData), NewProp_m_Bullet_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMagician_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagician_Statics::NewProp_m_InputMap,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagician_Statics::NewProp_m_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagician_Statics::NewProp_m_JumpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagician_Statics::NewProp_m_FireBulletAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagician_Statics::NewProp_m_MoveSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagician_Statics::NewProp_m_Bullet,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMagician_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMagician_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMagician_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMagician_Statics::ClassParams = {
	&AMagician::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AMagician_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AMagician_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMagician_Statics::Class_MetaDataParams), Z_Construct_UClass_AMagician_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMagician()
{
	if (!Z_Registration_Info_UClass_AMagician.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMagician.OuterSingleton, Z_Construct_UClass_AMagician_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMagician.OuterSingleton;
}
template<> PROJECT_API UClass* StaticClass<AMagician>()
{
	return AMagician::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMagician);
AMagician::~AMagician() {}
// End Class AMagician

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Magician_Magician_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMagician, AMagician::StaticClass, TEXT("AMagician"), &Z_Registration_Info_UClass_AMagician, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMagician), 2440795535U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Magician_Magician_h_1660325666(TEXT("/Script/Project"),
	Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Magician_Magician_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Magician_Magician_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
