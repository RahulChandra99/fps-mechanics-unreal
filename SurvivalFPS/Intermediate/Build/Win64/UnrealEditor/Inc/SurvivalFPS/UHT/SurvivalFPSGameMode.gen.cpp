// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SurvivalFPS/SurvivalFPSGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSurvivalFPSGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	SURVIVALFPS_API UClass* Z_Construct_UClass_ASurvivalFPSGameMode();
	SURVIVALFPS_API UClass* Z_Construct_UClass_ASurvivalFPSGameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SurvivalFPS();
// End Cross Module References
	void ASurvivalFPSGameMode::StaticRegisterNativesASurvivalFPSGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASurvivalFPSGameMode);
	UClass* Z_Construct_UClass_ASurvivalFPSGameMode_NoRegister()
	{
		return ASurvivalFPSGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ASurvivalFPSGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASurvivalFPSGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_SurvivalFPS,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASurvivalFPSGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "SurvivalFPSGameMode.h" },
		{ "ModuleRelativePath", "SurvivalFPSGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASurvivalFPSGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASurvivalFPSGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASurvivalFPSGameMode_Statics::ClassParams = {
		&ASurvivalFPSGameMode::StaticClass,
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
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ASurvivalFPSGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASurvivalFPSGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASurvivalFPSGameMode()
	{
		if (!Z_Registration_Info_UClass_ASurvivalFPSGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASurvivalFPSGameMode.OuterSingleton, Z_Construct_UClass_ASurvivalFPSGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASurvivalFPSGameMode.OuterSingleton;
	}
	template<> SURVIVALFPS_API UClass* StaticClass<ASurvivalFPSGameMode>()
	{
		return ASurvivalFPSGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASurvivalFPSGameMode);
	ASurvivalFPSGameMode::~ASurvivalFPSGameMode() {}
	struct Z_CompiledInDeferFile_FID_GameDevelopment_UnrealEngine_Projects_FPS_SurvivalFPS_Source_SurvivalFPS_SurvivalFPSGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GameDevelopment_UnrealEngine_Projects_FPS_SurvivalFPS_Source_SurvivalFPS_SurvivalFPSGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASurvivalFPSGameMode, ASurvivalFPSGameMode::StaticClass, TEXT("ASurvivalFPSGameMode"), &Z_Registration_Info_UClass_ASurvivalFPSGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASurvivalFPSGameMode), 4148798432U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GameDevelopment_UnrealEngine_Projects_FPS_SurvivalFPS_Source_SurvivalFPS_SurvivalFPSGameMode_h_2857191413(TEXT("/Script/SurvivalFPS"),
		Z_CompiledInDeferFile_FID_GameDevelopment_UnrealEngine_Projects_FPS_SurvivalFPS_Source_SurvivalFPS_SurvivalFPSGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GameDevelopment_UnrealEngine_Projects_FPS_SurvivalFPS_Source_SurvivalFPS_SurvivalFPSGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
