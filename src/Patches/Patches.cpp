#include "Patches/Patches.h"

#include "Patches/AchievementsPatch.h"
#include "Patches/BSMTAManagerPatch.h"
#include "Patches/BSPreCulledObjectsPatch.h"
#include "Patches/BSTextureStreamerLocalHeapPatch.h"
#include "Patches/ExitSavePatch.h"
#include "Patches/HavokMemorySystemPatch.h"
#include "Patches/MaxStdIOPatch.h"
#include "Patches/MemoryManagerPatch.h"
#include "Patches/ScaleformAllocatorPatch.h"
#include "Patches/SmallBlockAllocatorPatch.h"
#include "Patches/WorkshopMenuPatch.h"

namespace Patches
{
	void PreInit()
	{
		if (*Settings::MaxStdIO != -1) {
			MaxStdIOPatch::Install();
		}
	}

	void Preload()
	{
		if (*Settings::Achievements) {
			AchievementsPatch::Install();
		}

		if (*Settings::BSMTAManager) {
			BSMTAManagerPatch::Install();
		}

		if (*Settings::BSPreCulledObjects) {
			BSPreCulledObjectsPatch::Install();
		}

		if (*Settings::BSTextureStreamerLocalHeap) {
			BSTextureStreamerLocalHeapPatch::Install();
		}

		if (*Settings::ExitSave) {
			ExitSavePatch::Install();
		}

		if (*Settings::HavokMemorySystem) {
			HavokMemorySystemPatch::Install();
		}

		if (*Settings::MemoryManager || *Settings::MemoryManagerDebug) {
			MemoryManagerPatch::Install();
		}

		if (*Settings::ScaleformAllocator) {
			ScaleformAllocatorPatch::Install();
		}

		if (*Settings::SmallBlockAllocator) {
			SmallBlockAllocatorPatch::Install();
		}

		if (*Settings::WorkshopMenu) {
			WorkshopMenuPatch::Install();
		}
	}
}
