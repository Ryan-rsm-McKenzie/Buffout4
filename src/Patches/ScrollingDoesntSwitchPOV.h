#pragma once

namespace Patches
{
    class ScrollingDoesntSwitchPOVPatch
    {
    public:
        static void Install()
        {
            constexpr std::uint8_t BYTE{ 0xEB };

            // First -> Third
            REL::Relocation<std::uintptr_t> target1{ REL::ID(536450), 0x71 };
            REL::safe_write(target1.address(), BYTE);

            // Third -> First
            REL::Relocation<std::uintptr_t> target2{ REL::ID(722407), 0x24B };
            REL::safe_write(target2.address(), BYTE);

            logger::info("installed {}"sv, typeid(ScrollingDoesntSwitchPOVPatch).name());
        }
    };
}
