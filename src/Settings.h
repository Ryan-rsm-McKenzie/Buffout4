#pragma once

#define MAKE_SETTING(a_type, a_group, a_key, a_value) \
	inline a_type a_key { a_group##s, #a_key##s, a_value }

namespace Settings
{
	using ISetting = AutoTOML::ISetting;
	using bSetting = AutoTOML::bSetting;
	using iSetting = AutoTOML::iSetting;

	inline void load()
	{
		try {
			const auto table = toml::parse_file("Data/F4SE/Plugins/Buffout4.toml"s);
			for (const auto& setting : ISetting::get_settings()) {
				setting->load(table);
			}
		} catch (const toml::parse_error& e) {
			std::ostringstream ss;
			ss
				<< "Error parsing file \'" << *e.source().path << "\':\n"
				<< '\t' << e.description() << '\n'
				<< "\t\t(" << e.source().begin << ')';
			logger::error(ss.str());
			stl::report_and_fail("failed to load settings"sv);
		} catch (const std::exception& e) {
			stl::report_and_fail(e.what());
		} catch (...) {
			stl::report_and_fail("unknown failure"sv);
		}
	}

	MAKE_SETTING(bSetting, "Fixes", ActorIsHostileToActor, true);
	MAKE_SETTING(bSetting, "Fixes", CellInit, true);
	MAKE_SETTING(bSetting, "Fixes", EncounterZoneReset, true);
	MAKE_SETTING(bSetting, "Fixes", GreyMovies, true);
	MAKE_SETTING(bSetting, "Fixes", MagicEffectApplyEvent, true);
	MAKE_SETTING(bSetting, "Fixes", MovementPlanner, true);
	MAKE_SETTING(bSetting, "Fixes", PackageAllocateLocation, true);
	MAKE_SETTING(bSetting, "Fixes", SafeExit, true);
	MAKE_SETTING(bSetting, "Fixes", UnalignedLoad, true);
	MAKE_SETTING(bSetting, "Fixes", UtilityShader, true);

	MAKE_SETTING(bSetting, "Patches", Achievements, true);
	MAKE_SETTING(bSetting, "Patches", BSMTAManager, true);
	MAKE_SETTING(bSetting, "Patches", BSPreCulledObjects, true);
	MAKE_SETTING(bSetting, "Patches", BSTextureStreamerLocalHeap, true);
	MAKE_SETTING(bSetting, "Patches", ExitSave, false);
	MAKE_SETTING(bSetting, "Patches", HavokMemorySystem, true);
	MAKE_SETTING(bSetting, "Patches", INISettingCollection, true);
	MAKE_SETTING(iSetting, "Patches", MaxStdIO, -1);
	MAKE_SETTING(bSetting, "Patches", MemoryManager, true);
	MAKE_SETTING(bSetting, "Patches", MemoryManagerDebug, false);
	MAKE_SETTING(bSetting, "Patches", ScaleformAllocator, true);
	MAKE_SETTING(bSetting, "Patches", ScrollingDoesntSwitchPOV, false);
	MAKE_SETTING(bSetting, "Patches", SmallBlockAllocator, true);
	MAKE_SETTING(bSetting, "Patches", WorkshopMenu, true);

	MAKE_SETTING(bSetting, "Warnings", CreateTexture2D, true);
	MAKE_SETTING(bSetting, "Warnings", ImageSpaceAdapter, true);

	MAKE_SETTING(bSetting, "Compatibility", F4EE, true);
}

#undef MAKE_SETTING
