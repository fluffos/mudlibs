// Scratmancy.c 茅山道术
// Cracked by 凌惊雪 4-22-2003

inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("spells", 1) < 20
        ||      (int)me->query_skill("spells") <= (int)me->query_skill("scratmancy") )
                return notify_fail("你的法术修为还不够高深，无法学习茅山道术。\n");
        return 1;
}


string cast_spell_file(string spell)
{
        return CLASS_D("sanxian") + "/scratmancy/" + spell;
}

string type() { return "spells"; }

mixed base_damage(){ return 150;}