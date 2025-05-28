// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Project/Levels/TestMap.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTestMap() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
PROJECT_API UClass* Z_Construct_UClass_ATestMap();
PROJECT_API UClass* Z_Construct_UClass_ATestMap_NoRegister();
UPackage* Z_Construct_UPackage__Script_Project();
// End Cross Module References

// Begin Class ATestMap
void ATestMap::StaticRegisterNativesATestMap()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATestMap);
UClass* Z_Construct_UClass_ATestMap_NoRegister()
{
	return ATestMap::StaticClass();
}
struct Z_Construct_UClass_ATestMap_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Levels/TestMap.h" },
		{ "ModuleRelativePath", "Levels/TestMap.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATestMap>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ATestMap_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATestMap_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATestMap_Statics::ClassParams = {
	&ATestMap::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATestMap_Statics::Class_MetaDataParams), Z_Construct_UClass_ATestMap_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ATestMap()
{
	if (!Z_Registration_Info_UClass_ATestMap.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATestMap.OuterSingleton, Z_Construct_UClass_ATestMap_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATestMap.OuterSingleton;
}
template<> PROJECT_API UClass* StaticClass<ATestMap>()
{
	return ATestMap::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ATestMap);
ATestMap::~ATestMap() {}
// End Class ATestMap

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Levels_TestMap_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATestMap, ATestMap::StaticClass, TEXT("ATestMap"), &Z_Registration_Info_UClass_ATestMap, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATestMap), 1986687317U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Levels_TestMap_h_3418415377(TEXT("/Script/Project"),
	Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Levels_TestMap_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_teacher_ArakiYusuke_UnrealEngine_Projects_OpenCanpas01_Project_Source_Project_Levels_TestMap_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
