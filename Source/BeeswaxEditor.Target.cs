using UnrealBuildTool;
using System.Collections.Generic;

public class BeeswaxEditorTarget : TargetRules
{
	public BeeswaxEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("Beeswax");
	}
}
