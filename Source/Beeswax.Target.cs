using UnrealBuildTool;
using System.Collections.Generic;

public class BeeswaxTarget : TargetRules
{
	public BeeswaxTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("Beeswax");
	}
}
