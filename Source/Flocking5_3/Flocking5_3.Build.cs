// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Flocking5_3 : ModuleRules
{
	public Flocking5_3(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
