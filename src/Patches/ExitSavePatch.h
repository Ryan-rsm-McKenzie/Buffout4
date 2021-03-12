#pragma once

namespace Patches::ExitSavePatch
{
	namespace detail
	{
		inline void DisableSave()
		{
			constexpr auto start = 0x133;
			constexpr auto end = 0x19C;
			const auto target = REL::ID(927422).address();
			REL::safe_fill(target + start, REL::NOP, end - start);
		}

		inline void DisableMessage()
		{
			REL::Relocation<std::uintptr_t> target{ REL::ID(870227), 0x4BF + 0x1 };
			REL::safe_write(target.address(), std::uint16_t{ 0x255 });
		}
	}

	inline void Install()
	{
		detail::DisableSave();
		detail::DisableMessage();

		logger::info("installed ExitSave patch"sv);
	}
}
