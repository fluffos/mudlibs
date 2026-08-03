int is_knowledge(string sname)
{
	if (SKILL_D(sname)->type() == "知识技能")
		return 1;
        return 0;
}
int is_other(string sname)
{
	if (SKILL_D(sname)->type() == "杂项技能")
		return 1;
        return 0;
}
int is_normalskill(string sname)
{
	if (SKILL_D(sname)->type() == "基本技能")
		return 1;
        return 0;
}
int is_specialskill(string sname)
{
	if (SKILL_D(sname)->type() == "高级内功"
		||SKILL_D(sname)->type() == "高级法术"
		||SKILL_D(sname)->type() == "高级轻功"
		||SKILL_D(sname)->type() == "高级空手"
		||SKILL_D(sname)->type() == "高级兵器")
		return 1;
        return 0;
}
int is_specialspells(string sname)
{
	if (SKILL_D(sname)->type() == "基本内功")
		return 1;
        return 0;
}
int is_specialforce(string sname)
{
	if (SKILL_D(sname)->type() == "基本法术")
		return 1;
        return 0;
}

int is_forceskill(string sname)
{
	if (SKILL_D(sname)->valid_enable("force"))
		return 1;
        return 0;
}
int is_dodgeskill(string sname)
{
	if (SKILL_D(sname)->valid_enable("dodge"))
		return 1;
        return 0;
}
int is_spellskill(string sname)
{
	if (SKILL_D(sname)->valid_enable("spells"))
		return 1;
        return 0;
}
