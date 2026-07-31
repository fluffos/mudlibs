//incarnation修仙术

inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
   if( (int)me->query_skill("spells", 1) < 10
     || (int)me->query_skill("spells", 1) <= (int)me->query_skill("incarnation", 1) )
     return notify_fail("你的法术修为还不够高深，无法学习修仙术。\n");
   return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("emei") + "/incarnation/" + spell;
}

string query_shuxing()
{
            return "mu"; 
}

mixed base_damage(){ return 130;}
