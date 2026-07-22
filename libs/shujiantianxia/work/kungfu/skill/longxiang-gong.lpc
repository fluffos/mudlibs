// /kungfu/skill/longxiang-gong.c
// by dubei
// longxiang.c 龙象般若功
 
#include <ansi.h>
inherit FORCE;
#include "force.h"
int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	int i = (int)me->query_skill("longxiang-gong", 1);
         int t = (int)me->query_skill("lamaism", 1);
 

          if ((string)me->query("class") != "lama")
             return notify_fail("你不是喇嘛，学不了高深的龙象般若功。\n");
 

	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("你的基本内功火候不足，不能学龙象般若功。\n");

	if ( me->query("gender") == "无性" )
		return notify_fail("你无根无性，阴阳不调，难以领会高深的龙象般若功。\n");
          
            if ( t < 30)
	return notify_fail("要修炼龙象般若功,先有有一定的密宗心法做基础。\n");

            if ( i < 200 && t <= i )
	return notify_fail("你的密宗心法修为不够，无法领会更高深的龙象般若功。\n");

       return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("龙象般若功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"longxiang-gong/" + func;
}
mapping exercise_msg(object me)
{
  return ([
    "status_msg" : YEL + me->name()+"神色俨然,凝神闭目。"NOR,
      "start_my_msg" : YEL"你盘膝入定,凝聚体内真气,摧动内息将腹中一丝丝游气慢慢增厚。\n"NOR,
          "start_other_msg" :YEL + me->name()+"盘膝坐定,一掌向上推出,一手垂于丹田,面目极是诡异,让人心桤摇动。\n"NOR,
    "halt_msg" : YEL "$N突然双手向胸前一合,压住腹中内息,凌空越起。\n"NOR,
              "end_my_msg" : YEL "你一周天行将下来,顿时浑身发暖,感到腹中内劲又增加一分。\n"NOR,
                  "end_other_msg" : YEL "只见"+me->name()+"头顶白气渐散,双掌向胸前一合,起身站了起来。\n"NOR
                    ]);
}
