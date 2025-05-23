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
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
PROJECT_API UClass* Z_Construct_UClass_AMagician();
PROJECT_API UClass* Z_Construct_UClass_AMagician_NoRegister();
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
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMagician>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
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
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
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
		{ Z_Construct_UClass_AMagician, AMagician::StaticClass, TEXT("AMagician"), &Z_Registration_Info_UClass_AMagician, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMagician), 2524391682U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Magician_Magician_h_971459968(TEXT("/Script/Project"),
	Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Magician_Magician_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Magician_Magician_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
