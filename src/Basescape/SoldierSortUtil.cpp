#include "SoldierSortUtil.h"

#define GET_ATTRIB_STAT_FN(attrib) \
	int OpenXcom::attrib##Stat(Game *game, Soldier *s) { return s->getCurrentStats()->attrib; }
GET_ATTRIB_STAT_FN(tu)
GET_ATTRIB_STAT_FN(stamina)
GET_ATTRIB_STAT_FN(health)
GET_ATTRIB_STAT_FN(bravery)
GET_ATTRIB_STAT_FN(reactions)
GET_ATTRIB_STAT_FN(firing)
GET_ATTRIB_STAT_FN(throwing)
GET_ATTRIB_STAT_FN(strength)
int OpenXcom::psiStrengthStat(Game *game, Soldier *s)
{
	// don't reveal psi strength before it would otherwise be known
	if (s->getCurrentStats()->psiSkill > 0
		|| (Options::psiStrengthEval
		&& game->getSavedGame()->isResearched(game->getMod()->getPsiRequirements())))
	{
		return s->getCurrentStats()->psiStrength;
	}
	return 0;
}
int OpenXcom::psiSkillStat(Game *game, Soldier *s)
{
	// when Options::anytimePsiTraining is turned on, psiSkill can actually have a negative value
	if (s->getCurrentStats()->psiSkill > 0)
	{
		return s->getCurrentStats()->psiSkill;
	}
	return 0;
}
GET_ATTRIB_STAT_FN(melee)
#undef GET_ATTRIB_STAT_FN
#define GET_SOLDIER_STAT_FN(attrib, camelCaseAttrib) \
	int OpenXcom::attrib##Stat(Game *game, Soldier *s) { return s->get##camelCaseAttrib(); }
GET_SOLDIER_STAT_FN(rank, Rank)
GET_SOLDIER_STAT_FN(missions, Missions)
GET_SOLDIER_STAT_FN(kills, Kills)
GET_SOLDIER_STAT_FN(woundRecovery, WoundRecovery)
#undef GET_SOLDIER_STAT_FN