//Cracked by Roath
// murong-xinfa.c

#include <ansi.h>;
inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	int lvl;
	
       lvl = (int)me->query_skill("murong-xinfa", 1);
	
        if( (int)me->query_skill("douzhuan-xingyi",1) < 15 )
                return notify_fail("没有一点斗转星移的基础，难以领悟心法的奥妙。\n");
		
        if (lvl == 200) {
               if (me->query("mrxfgift",1) < 1){
                  me->add("int",1);
                  me->set("mrxfgift",1);
                 tell_object(me, HIW "$N参照斗转星移与慕容心法，心智更加清朗！\n"NOR);
                      return 1;
            }
       }
		
	return 1;
}

int practice_skill(object me)
{	
        return notify_fail("肢体的练习恐怕不能提高这门心法要诀。\n");
}
