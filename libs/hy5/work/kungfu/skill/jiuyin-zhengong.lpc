// jiuyin-zhengong.c 九阴真功
#include <ansi.h>

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	int lev = (int)me->query_skill("jiuyin-zhengong", 1);
	if (!me->query("jiuyin/full") && !me->query("jiuyin/shang") && !me->query("jiuyin/gumu"))
		return notify_fail("你试图学习九阴真功，但似乎毫无进展。\n");
	if (!me->query("jiuyin/full") && !me->query("jiuyin/shang") && me->query("jiuyin/gumu") && lev > 100)
		return notify_fail("你试图学习九阴真功，但似乎毫无进展。\n");
	if ((int)me->query_skill("force", 1) < 200)
		return notify_fail("你的基本内功火候不够，无法学习九阴真功。\n");
	if (lev > 100 && lev > (int)me->query_skill("daode-jing", 1) && (int)me->query_skill("daode-jing", 1) < 200)
		return notify_fail("你的道德经火候不够，强行修炼九阴真功会导致走火入魔。\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("九阴真功只能研读(yandu)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"jiuyin-zhengong/" + func;
}

mapping exercise_msg(object me)
{
    return ([
	"status_msg" : HIB + me->name() + "双眼微闭，被一股九阴真气围绕著。" NOR,
	"start_my_msg" : HIB"你盘腿坐下，双目微闭，双手掌心相向成虚握太极，天人合一，练气入虚。\n"NOR,
	"start_other_msg" : HIB + me->name() + "盘腿坐下，双目微闭，双手掌心相向成虚握太极。轻风吹过，" + me->name() + "身上的衣袍竟然不为所动。\n"NOR,
	"halt_msg" : "$N周身微微颤动，长出口气，站了起来。\n",
	"end_my_msg" : "你将内息又运了一个小周天，缓缓导入丹田，双臂一震，站了起来。\n",
	"end_other_msg" : me->name() + "的脸上陡然一暗，又立刻隐去。随即双臂一震，站了起来。\n"
    ]);
}

void skill_improved(object me)
{
         int i =3 +random(8);
         if( me->query_skill("jiuyin-zhengong", 1) > 200
          && me->query("jiuyin/gift") + 200 < me->query_skill("jiuyin-zhengong", 1)){
             if( !me->query("jiuyin/gift"))
               me->set("jiuyin/gift", me->query_skill("jiuyin-zhengong", 1) -200);
             else 
               me->add("jiuyin/gift", 1);
             me->add("max_neili", i); 
             tell_object(me,HIW"\n随着九阴真功的提高，你感觉自己内力增加了"+chinese_number(i)+"点。\n"NOR);
         }
}
