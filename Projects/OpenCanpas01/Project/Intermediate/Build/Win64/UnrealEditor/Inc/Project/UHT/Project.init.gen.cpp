// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProject_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Project;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Project()
	{
		if (!Z_Registration_Info_UPackage__Script_Project.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Project",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x15B1E325,
				0xCB80F08A,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Project.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Project.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Project(Z_Construct_UPackage__Script_Project, TEXT("/Script/Project"), Z_Registration_Info_UPackage__Script_Project, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x15B1E325, 0xCB80F08A));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
