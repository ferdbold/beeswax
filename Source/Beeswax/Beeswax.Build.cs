using UnrealBuildTool;

public class Beeswax : ModuleRules
{
	public Beeswax(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"HeadMountedDisplay"
		});

        // Steam integration
        DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
	}
}
