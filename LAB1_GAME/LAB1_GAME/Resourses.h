#pragma once

namespace resourses
{
	enum class fieldParams : char
	{
		grass,
		water,
		mountain
	};

	enum class returnCode : int
	{
		correntPlacement,
		uncorrectPlacement
	};

	enum class unitTypes : char
	{
		noUnit,
		archer,
		warrior,
		magician,
		heale
	};

	enum class effects : char
	{
		hpIncrease,
		damageIncrease,
		trap,
		noEffect,
		poison
	};

	struct effectInfo
	{
		effectInfo(effects new_action, size_t new_actionPower) : action(new_action), actionPower(new_actionPower)
		{}

		effects action;
		size_t actionPower;
	};
}