
//三清剑法    
//lestat modi for dtxy 2001

inherit SKILL;
#include <ansi.h>

string* skill_head =({
        "$N身形稍退，使出一招",
        "$N仰天长笑，看也不看，一招",
        "$N轻轻一跃，使了个",
        "$N神态悠闲，一招",
        "$N身形转个不停，突然一招",
        "$N脚下踏了个七星步，一招",
});

string* skill_tail =({
        "，手中$w势若飞瀑向$n拦腰一斩",
        "，手中$w对准$n的$l凌空一斩",
        "，反手将$w对准$n$l一剑刺去",
        "，手中$w轻妙地划向$n的$l",
        "，反手对准$n$l一剑刺去",
        "，趁$n转身之际，挥出一剑",
});



mapping *action = ({
   ([   "action":     "$N使出一招"+HIR"「星河影动」"NOR+"，剑光闪烁不定，若有若无地刺向$n$l",
     "dodge":     0,
     "parry":     15,
     "damage":     35,
     "damage_type":   "刺伤"
   ]),
   ([   "action":     "$N身形转个不停，突然一招"+HIY"「一点灵犀」"NOR+"使出，手中$w划出一道银弧，径刺$n$l",
     "dodge":     -10,
     "parry":     -15,
     "damage":     45,
     "damage_type":   "刺伤"
   ]),
   ([   "action":     "$N脚下踏了个七星步，一招"+HIM"「古道西风」"NOR+"手中$w势若飞瀑向$n拦腰一斩",
     "dodge":     -5,
     "parry":     -15,
     "damage":     40,
     "damage_type":   "劈伤"
   ]),
   ([   "action":     "但见$N连退几步，忽然间纵身跃起，手中$w一式"+HIW"「沧海月明」"NOR+"对准$n的$l凌空一斩",
     "dodge":     -15,
     "parry":     -5,
     "damage":     50,
     "damage_type":   "劈伤"
   ]),
   ([   "action":     "$N轻轻一跃，使了个"+HIB"「乘风归去」"NOR+"，却在转身之际对准$n$l斜斜挥出一剑",
     "dodge":     5,
     "parry":     -25,
     "damage":     35,
     "damage_type":   "刺伤"
   ]),
   ([   "action":     "$N神态悠闲，手中$w凭空一指，一招"+HIC"「白云千载」"NOR+"轻妙地划向$n的$l",
     "dodge":     -10,
     "parry":     -10,
     "damage":     40,
     "damage_type":   "刺伤"
   ]),
   ([   "action":     "$N手中$w向外一分，使一招"+HIG"「曲径通幽」"NOR+"反手对准$n$l一剑刺去",
     "dodge":     0,
     "parry":     -20,
     "damage":     35,
     "damage_type":   "刺伤"
   ]),

	([	"name":                 "三清绝剑",
		"action":
"$N手中$w连续划出几个光环，一阵吸力带得$n向前踏出一步，$N左手一式"+HIC"「三清绝剑」"NOR+"已刺向$n的$l",
		"dodge":		-80,
                "parry":                -20,
		"damage":		75,
		"force":		75,
		"damage_type":		"刺伤"
	]),

});

int valid_learn(object me)
{
   object ob;

   if( (int)me->query("max_force") < 50 )
     return notify_fail("你的内力不够，没有办法练三清剑法。\n");

   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "sword" )
     return notify_fail("你必须先找一把剑才能练剑法。\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
     int i;
	i=me->query_temp("SQJ_perform");
if( !me->query_temp("SQJ_perform") ) {
     mapping* m_actions;
     m_actions=me->query("skill_sanqing-jian");
     if(me->query("skill_sanqing-jian")==0 )
     return action[random(7)];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else 
    return action[random(7)];}
    else {
	return action[i];
	}

}

varargs int practice_skill(object me,int flag)
{
	   if( (int)me->query("kee") < 30
   ||   (int)me->query("force") < 3 )
     return notify_fail("你的内力或气不够，没有办法练习三清剑法。\n");
   me->receive_damage("kee", 30);
   me->add("force", -3);
if ( flag )    write("你按着所学练了一遍三清剑法。\n");
   return 1;
}
string perform_action_file( string action)
{
return CLASS_D("zhenyuan") + "/sanqing-jian/" + action;
}


void skill_improved(object me)
{
   int m_skill=me->query_skill("sanqing-jian",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对三清剑的领悟加深了，你的三清剑进入了一个新的境界！\n"NOR);
   if(me->query("zichuang/times")>7){
        tell_object(me,HIW"然而你的功夫已经练至顶峰，不能再创出新招了。\n"NOR);
        return;
     }
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"然而你的心中居然产生了一种失落感！\n"NOR);
        return;
     }
     if((random(me->query("int")/2)+(int)me->query_skill("literate")/50)<10){
       tell_object(me,HIW"然而你的心中升起一种惆怅的感觉，仿佛有一丝重要的东西没有抓住。\n"NOR);
       return;
     }
     tell_object(me,HIW"你突然福至心灵，对三清剑领悟出了一招新的用法！\n"NOR);
     tell_object(me,"请为这招取一个名字：");
     input_to( (: call_other, __FILE__, "name_skill", me:));
   }
   return;
}

void name_skill(object me, string arg)
{
   string *banned_name = ({
                "你", "你", "我", "他", "她", "它", "爸", "妈",
                "爷", "奶", "巫师", "天神", "神仙",
        });
   mapping* m_actions;
   mapping m_act=([]);
   int content, i=strlen(arg);
   string msg;

   m_actions=me->query("skill_sanqing-jian");
 if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+2*me->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+2*me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"刺伤"]);
if (!arg || arg=="") 
     {
          tell_object(me,"请为你的新招式取一个名字：");
          input_to( (: call_other, __FILE__, "name_skill", me:));
          return;
     }
     else while(i--) 
     {
                if( arg[i]<=' ' ) 
                {
                        tell_object(me,"招式名字不能使用控制字元，请重新设定一个名字：");
                        input_to( (: call_other, __FILE__, "name_skill", me:));
                        return;
                }
                if(strsrch(arg, "　") >= 0) 
                {
                        tell_object(me,"招式名字不能有空格，请重新设定一个名字：");
                        input_to( (: call_other, __FILE__, "name_skill", me:));
                        return;
                }
                if(!is_chinese(arg) ) 
                {
                        tell_object(me,"请您用「中文」为你的新招式取名字：");
                        input_to( (: call_other, __FILE__, "name_skill", me:));
                        return;
                }
     }
     if( member_array(arg, banned_name)!=-1 ) 
     {
     tell_object(me,"对不起，这种名字会造成其他人的困扰。请重新设定一个名字：");
     input_to( (: call_other, __FILE__, "name_skill", me:));
     return;
     }
     if( (strlen(arg) < 4) || (strlen(arg) > 8 ) ) 
     {
     tell_object(me,"对不起，招式名字必须是 ４ 到 ８ 个中文字：");
     input_to( (: call_other, __FILE__, "name_skill", me:));
     return;
     }
//   if(!arg||arg==" ")arg="三清剑绝技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIW"「"+arg+"」"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_sanqing-jian",m_actions);
   me->add("zichuang/times",1);
}
 
mixed hit_ob(object me, object victim, int damage)
{
	int p;
	object weapon;
	if( !me || !living(me) || !victim || !me->is_fighting(victim) )
		return 0;
	weapon = me->query_temp("weapon");
	if( !weapon 
	 || (weapon->query("skill_type")!="sword"
	  && weapon->query("use_apply_skill")!="sword") 
	 || me->query_skill_mapped("sword")!="sanqing-jian" ) 
	 	return 0;
	 if( me->query("family/family_name") != "五庄观"
         && me->query("chushi/chushi_wzg")!="yes" )
         	return 0;
         if( me->query_temp("jianmang")<1 )
         	return 0;	
         p = me->is_knowing("wzg_jianmang")+1;
         damage = damage*p/100+1;
         return damage;
}

