#include "ntrlObj.h"

using namespace ntrlObj;

effectInfo HealingWaterfall::get()
{
	if (alreadyUsed == true)
		return effectInfo(effects::noEffect, 0);

	alreadyUsed = true;
	return effectInfo(effects::hpIncrease, hpModification);
}

HealingWaterfall::HealingWaterfall()
{
	hpModification = std::rand() % 5 + 20;
}

ntrlObj::PowerStatue::PowerStatue()
{
	powerModification = rand() % 5 + 5;
}

effectInfo ntrlObj::PowerStatue::get()
{
	if (alreadyUsed == true)
		return effectInfo(effects::noEffect, 0);

	alreadyUsed = true;
	return effectInfo(effects::damageIncrease, powerModification);
}

ntrlObj::Trap::Trap()
{
	trapDamage = (std::rand() % 2 + 2) * 20
}

effectInfo ntrlObj::Trap::get()
{
	if (alreadyUsed == true)
		return effectInfo(effects::noEffect, 0);

	alreadyUsed = true;
	return effectInfo(effects::trap, trapDamage);
}
