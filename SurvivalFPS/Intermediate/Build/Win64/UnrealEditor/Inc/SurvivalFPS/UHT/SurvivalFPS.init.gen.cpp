// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSurvivalFPS_init() {}
	SURVIVALFPS_API UFunction* Z_Construct_UDelegateFunction_SurvivalFPS_OnPickUp__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_SurvivalFPS;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_SurvivalFPS()
	{
		if (!Z_Registration_Info_UPackage__Script_SurvivalFPS.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_SurvivalFPS_OnPickUp__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/SurvivalFPS",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x6471CBDA,
				0x94C49C56,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_SurvivalFPS.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_SurvivalFPS.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_SurvivalFPS(Z_Construct_UPackage__Script_SurvivalFPS, TEXT("/Script/SurvivalFPS"), Z_Registration_Info_UPackage__Script_SurvivalFPS, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x6471CBDA, 0x94C49C56));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
