#pragma once
#include <random>
#include "Resourses.h"

using namespace resourses;

namespace ntrlObj
{
	struct NtrlBase
	{
		virtual effectInfo get() = 0;
		bool alreadyUsed = false;
	};

	struct HealingWaterfall : public NtrlBase
	{
		HealingWaterfall();
		effectInfo get();

	private:
		size_t hpModification = 0;
	};

	struct PowerStatue : public NtrlBase
	{
		PowerStatue();
		effectInfo get();

	private:
		size_t powerModification = 0;
	};

	struct Trap : public NtrlBase
	{
		Trap();
		effectInfo get();

	private:
		size_t trapDamage = 0;
	};
}