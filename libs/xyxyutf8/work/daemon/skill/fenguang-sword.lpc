// fengguang-sword 16招
//ephq

inherit SKILL;
#include <ansi.h>;
#include <combat.h>

string* skill_head =({
        "$N身形稍退，使出一招",
        "$N不闪不避，一式",
        "$N使出",
        "$N傲然一笑，一式",
        "$N一个急转，使出",
});

string* skill_tail =({
        "，手中$w化为一道疾光刺向$n的$l。",
        "，手中$w化为一道金光罩向$n。",
        "，手中$w不偏一歪，直刺$n的$l。",
        "，手中$w如飞，发出点点寒光。",
        "，顿时一阵寒气飘向$n",
});



mapping *action = ({
([      "action" : "$N手中$w斜指，一招"+COLOR_D->random_color(2,0,1)+"「混沌一破」"+NOR+"，反身一顿，一刀向$n的$l撩去",
        "damage" : 20,
        "dodge" : -10,
        "skill_name" : "混沌一破",
        "damage_type" : "割伤"
]),
([      "action" : "$N一招"+COLOR_D->random_color(2,0,1)+"「太乙生萌」"+NOR+"，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
        "dodge" : -10,
        "damage" : 35,
        "skill_name" : "太乙生萌",
        "damage_type" : "割伤"
]),
([      "action" : "$N一招"+COLOR_D->random_color(2,0,1)+"「日月晦明」"+NOR+"，$w大开大阖，自上而下划出一个大弧，笔直劈向$n",
        "dodge" : 5,
        "damage" : 25,
        "skill_name" : "日月晦明",
        "damage_type" : "割伤"
]),
([              "action":"\n$N呼的一声拔地而起，一式"+COLOR_D->random_color(2,0,1)+"「日月与同辉」"+NOR+"，$w幻出万道光影，将$n团团围住",
        "dodge" : -15,
                "damage": 40,
                "skill_name" : "日月与同辉",
                "damage_type":  "内伤"
]),
([      "action":"$N身形微侧，左手后摆，右手$w一招"+COLOR_D->random_color(2,0,1)+"「横扫千军」"+NOR+"，直向$n的腰间挥去"NOR,
        "dodge" : -10,
        "parry" : -10,
        "damage": 45,
        "skill_name" : "横扫千军",
        "damage_type":"刺伤"
]),
([      "action":"$N纵身近前，$w斗然弯弯弹出，剑光爆长，一招"+COLOR_D->random_color(2,0,1)+"「峭壁断云」"+NOR+"，猛地刺向$n的胸口"NOR,
        "dodge" : -10,
        "parry" : -15,
        "damage": 55,
        "skill_name" : "峭壁断云",
        "damage_type":"刺伤"
]),
([      "action":"$N左手捏个剑决，平推而出，决指上仰，右手剑朝天不动，一招"+COLOR_D->random_color(2,0,1)+"「仙人指路」"+NOR+"，刺向$n"NOR,
        "dodge" : -10,
        "parry" : -10,
        "damage": 25,
        "skill_name" : "仙人指路",
        "damage_type":"刺伤"
]),
([      "action":"$N抢前一步，$w微微抖动，剑光点点，一招"+COLOR_D->random_color(2,0,1)+"「江河不竭」"+NOR+"，终而复始，绵绵不绝刺向$n"NOR,
        "dodge" : -20,
        "parry" : -20,
        "damage": 25,
        "skill_name" : "江河不竭",
        "damage_type":"刺伤"
]),
([      "action":"$N左手剑鞘一举，快逾电光石光，一招"+COLOR_D->random_color(2,0,1)+"「高塔挂云」"+NOR+"，用剑鞘套住$n手中兵器，$w直指$n的咽喉"NOR,
        "dodge" : -10,
        "parry" : 10,
        "damage": 20,
        "skill_name" : "高塔挂云",
        "damage_type":"刺伤"
]),
([      "action":"$N翻身回剑，剑诀斜引，一招"+COLOR_D->random_color(2,0,1)+"「百丈飞瀑」"+NOR+"，剑锋从半空中直泻下来，罩住$n上方",
        "dodge" : -35,
        "parry" : -35,
        "damage": 15,
        "skill_name" : "百丈飞瀑",
        "damage_type":"刺伤"
]),
([      "action":"$N一式"+COLOR_D->random_color(2,0,1)+"「雪拥蓝桥」"+NOR+"，$N手中剑花团团，一条白练疾风般向卷向$n"NOR,
        "dodge" : -10,
        "parry" : -5,
        "damage": 15,
        "skill_name" : "雪拥蓝桥",
        "damage_type":"刺伤"
]),
([              "skill_name":   "法分玄素",
                "action" : "$N剑尖剑芒暴长，一招"+COLOR_D->random_color(2,0,1)+"「法分玄素」"+NOR+"，手中$w自左下大开大阖，一剑斜上刺向$n的$l",
                "dodge" : -10,
                "damage" : 20,
                "damage_type" : "刺伤"
]),
([              "skill_name":   "道尽阴阳",
                "action" : "$N剑势圈转，手中$w如粘带连，平平展展挥出，一招"+COLOR_D->random_color(2,0,1)+"「道尽阴阳」"+NOR+"轻轻划过$n的$l",
                "dodge" : -20,
                "damage" : 30,
                "damage_type" : "刺伤"
]),
([              "skill_name":   "云含吞吐",
                "action" : "$N剑芒吞吐，幻若灵蛇，右手$w使出一式"+COLOR_D->random_color(2,0,1)+"「云含吞吐」"+NOR+"，剑势极尽曼妙，刺向$n的$l",
                "dodge" : -25,
                "damage" : 40,
                "damage_type" : "刺伤"
]),
([              "skill_name":   "人在遐迩",
                "action" : "$N挥剑分击，剑势自胸前跃出，右手$w一式"+COLOR_D->random_color(2,0,1)+"「人在遐迩」"+NOR+"，毫无留恋之势，刺向$n的$l",
                "dodge" : -15,
                "damage" : 30,
                "damage_type" : "刺伤"
]),
([              "skill_name":   "情系短长",
        "action" : "$N退步，左手剑指划转，腰部一扭，右手$w一记"+COLOR_D->random_color(2,0,1)+"「情系短长」"+NOR+"自下而上刺向$n的$l",
                "dodge" : -35,
                "damage" : 50,
                "damage_type" : "刺伤"
])
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry";  }

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力不够，没有办法练太乙分光剑。\n");
        if(me->query("family/family_name") != "娥眉"
             || me->query_skill("incarnation", 1) < 30)
        return notify_fail("这是仙家绝学,你是从什么地方偷学的呢?\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");
        return 1;
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习太乙分光剑。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍太乙分光剑。\n");
        return 1;
}

mapping query_action(object me, object weapon)
     {
      int i;
      mapping* m_actions;
      i=me->query_action("SS_perform");
      if( ! me->query_temp("SS_perform"))
           {
          if(me->query("skill_fenguang-sword")==0) return action[random(7)];
          if(random(2))return action[random(7)];
          m_actions=me->query("skill_fenguang-sword");
          return m_actions[random(sizeof(m_actions))];
           }
         else
        {
       return action[7];
       }
        return action[random(sizeof(action))];
     }


string perform_action_file( string action)
{
return CLASS_D("emei") + "/fenguang-sword/" + action;
}


void skill_improved(object me)
{
   int m_skill=me->query_skill("fenguang-sword",1);       
   
   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你的太乙分光剑的领悟加深了，你的太乙分光剑进入了一个新的境界！\n"NOR);
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
     tell_object(me,HIW"你突然福至心灵，对千钧棒领悟出了一招新的用法！\n"NOR);
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

   m_actions=me->query("skill_fenguang-sword");
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
//   if(!arg||arg==" ")arg="千钧棒绝技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIG"「"+arg+"」"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_fenguang-sword",m_actions);
   me->add("zichuang/times",1);
}
