//[4;53m[1;31mBy tianlin@mhxy for 2002.1.25[2;37;0m
//从新编写
#include <ansi.h>
inherit SKILL;
string* skill_head =({
        "$N身形稍退，使出一招",
        "$N于朦朦胧胧中，使出一招",
        "$N四处游走，一招",
        "$N神态悠闲，一招",
        "$N中宫直进，突然一招",
        "$N双脚一顿，笔直跃起，一招",
});

string* skill_tail =({
        "，手中$w不停地颤抖着",
        "，手中$w对准$n的$l凌空一斩",
        "，反手将$w对准$n$l一剑刺去",
        "，手中$w轻妙地划向$n的$l",
        "，手中$w去势飘忽不定，只看得$n眼花缭乱",
        "，手中$w带起点点寒光，指向$n前胸穴道",
});

mapping *action = ({
        ([    "action":           "$N手中$w的随风而出，一招"HIR"「绝命」"NOR"，$n被笼罩在一片剑光之中",
               "dodge":         -40,
               "parry":         -40,
	       "damage":		30,
              "damage_type":      "刺伤"
        ]),
        ([    "action":           "$N使出夺命十三剑中的"HIB"「夺命」"NOR"，手中$w有如青虹，直划$n的$l",
               "dodge":         -40,
               "parry":         -40,
	       "damage":		30,
              "damage_type":      "割伤"
        ]),
        ([    "action":           "$N一招"HIY"「丧命」"NOR"，$w化作奇异的弧线直取$n的$l",
               "dodge":         -40,
               "parry":         -40,
	       "damage":		30,
              "damage_type":      "割伤"
        ]),
        ([    "action":           "$N手中$w虚实相间，一式"CYN"「亡命」"NOR"，向$n的$l劈出",
               "dodge":         -40,
               "parry":         -40,
	       "damage":		30,
              "damage_type":      "割伤"
        ]),
        ([    "action":           "$N手中$w无影无踪，突的一招"HIR"「无命」"NOR"对准$n$l一下刺去",
               "dodge":         -40,
               "parry":         -40,
	       "damage":		30,
              "damage_type":      "刺伤"
        ]),
});


int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力修为不够深，夺命剑法学了也没用。\n");

	if( (string)me->query_skill_mapped("force")!= "cloudforce")
		return notify_fail("夺命剑法必须配合神剑山庄的内功才能练。\n");

	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一柄剑才能练习剑法。\n");
	return 1;
}

int practice_skill(object me)
{
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("duo-sword");

	if (dod<swo/2)
		return notify_fail("你的身法跟不上剑法，练下去很可能会伤到自己。\n");
	if ((int)me->query("kee") < 30)
		return notify_fail("你体质欠佳，强练夺命剑法有害无益。\n");
	if ((int)me->query("force") < 5)
		return notify_fail("你内力不足，强练夺命剑法有走火入魔的危险。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	message_vision("$N默默回忆了一会儿，然后练了一遍夺命剑法。\n", me);
	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword"||usage=="parry";
}
mapping query_action(object me, object weapon)
{
     mapping* m_actions;
     m_actions=me->query("skill_duo-sword");
     if(me->query("skill_duo-sword")==0 )
     return action[random(sizeof(action))];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else 
    return action[random(sizeof(action))];

}
string perform_action_file(string func)
{
        return __DIR__"duo-sword/" + func;
}
void skill_improved(object me)
{
   int m_skill=me->query_skill("duo-sword",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对夺命剑法的领悟加深了，你的夺命剑法进入了一个新的境界！\n"NOR);

     if(random(me->query("kar"))<20){
        tell_object(me,HIW"然而你的心中居然产生了一种失落感！\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"然而你的心中升起一种惆怅的感觉，仿佛有一丝重要的东西没有抓住。\n"NOR);
       return;
     }
     tell_object(me,HIW"你突然福至心灵，对夺命剑法领悟出了一招新的用法！\n"NOR);
     tell_object(me,"请为这招取一个名字：");
     input_to( (: call_other, __FILE__, "name_skill", me:));
   }
   return;
}

void name_skill(object me, string arg)
{
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=me->query("skill_duo-sword");
 if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+2*me->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"刺伤"]);

   if(!arg||arg==" ")arg="夺命剑法绝技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HBRED+HIW"「"+arg+"」"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_duo-sword",m_actions);
}
