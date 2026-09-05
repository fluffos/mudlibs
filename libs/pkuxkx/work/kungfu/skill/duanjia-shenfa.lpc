//whuan
//copy from duanshi-shenfa
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : 
"$n双足一挫，右足点地，一式「旱地拔葱」全身借力跃向半空，忽的硬拔起丈余。\n",
        "dodge"  : 10
]),
([      "action" :
"$n侧身一转，双足一顿，一式「雨燕归巢」猛的往上一窜，向一只雨燕般飞入云端。\n",
        "dodge"  : 20
]),
([      "action" :
"$n左手一引，右手猛的拍向地面，一式「破土而出」顺势飞身跃过$N的头顶。\n",
        "dodge"  : 30
]),
([      "action" :
"$n飞身跃起，一式「无中生有」在半空中猛一提气，身体笔直的又飞起五尺。\n",
        "dodge"  : 40
]),
([      "action" :
"$n使出「乘风而去」，全身真气运转三个周天，刹时飞向半空，有如御风而行。\n",
        "dodge"  : 50
]),
([      "action" :
"$n使出「鲧化大鹏」双臂一伸，运气上提，向一只灵山大鸠，飞起数丈。\n",
        "dodge"  : 60
]),
([      "action" :
"$n忽然脸色一变，双目一闭，一式「青云直上」纵身一挺纵身一挺向一片鸿毛飘入半空。\n",
        "dodge"  : 70
]),
([      "action" :
"$n双足忽然加快，身体猛的后仰，一式「风翔九天」脚一发力，平平的窜入空中。\n",
        "dodge"  : 80
])
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("duanshi-shenfa");

        
        if (level < 80 )
                zhaoshu--;
   
        if (level < 70 )
                zhaoshu--;


        if (level < 60 )
                zhaoshu--;

        if (level < 50 )
                zhaoshu--;

        if (level < 40 )
                zhaoshu--;

        return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
        return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
// The following codes are buggy, because "me" is the attacker instead
// of defender.
/*

        object me, ob;
        mapping action;

        me = this_player();
        action = query_action(me, ob);
        return action["action"];
*/
        return action[random(sizeof(action))]["action"];

}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("你现在气不够，不能练段氏身法。\n");
        me->receive_damage("qi", 30, me);
        return 1;
}
