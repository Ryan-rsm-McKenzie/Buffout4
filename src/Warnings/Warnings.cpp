#include "Warnings/Warnings.h"

#include "Warnings/CreateTexture2DWarning.h"
#include "Warnings/ImageSpaceAdapterWarning.h"

namespace Warnings
{
	void PreLoad()
	{
		if (*Settings::CreateTexture2D) {
			CreateTexture2DWarning::Install();
		}

		if (*Settings::ImageSpaceAdapter) {
			ImageSpaceAdapterWarning::Install();
		}
	}
}
