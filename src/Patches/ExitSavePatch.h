#pragma once

namespace Patches::ExitSavePatch
{
	inline void Install()
	{
		// Disable exit save
		REL::Relocation<std::uintptr_t> target1{ REL::ID(927422), 0x16B };
		REL::safe_fill(target1.address(), REL::NOP, 0x5);

		// Disable exit save message
		REL::Relocation<std::uintptr_t> target2{ REL::ID(870227), 0x4BF + 0x1 };
		REL::safe_write(target2.address(), std::uint16_t{ 0x255 });

		logger::info("installed ExitSave patch"sv);
	}
}
