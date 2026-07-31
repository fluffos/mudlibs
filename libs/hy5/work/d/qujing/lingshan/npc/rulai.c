// rulai.c
// rulai fo.
// 请尽量使用write函数，别用message_vision
// 这样可以减少信息流量，减轻负担...mudring 11/22/2002

inherit NPC;
#include "/d/migong/romnpc2.c"
#include <obstacle.h>
#include <ansi.h>

#define DEBUG 0

#define LEVEL_NONE 0
#define LEVEL_ASKED 1

string *list=({"yg-jjf","yg-jjf2","yg-jjf3","yg-hyd",
                "yg-fangcun","yg-hell","yg-jjf4","yg-dragon1",
                "yg-dragon2","yg-moon","yg-dragon3","yg-pansi",
                "yg-putuo","yg-shushan","yg-wdd",
        });
int reward_player ();
int recover_death ();

void create()
{
  set_name("如来佛", ({ "rulai fo", "rulai", "fo" }));
  set("title", "佛祖多陀阿伽陀");
  set("long", "大慈大悲灵山雷音古刹佛祖多陀阿伽陀如来佛爷。\n");
  set("gender", "男性");
  set("age", 10000);
  set("attitude", "peaceful");
  set("rank_info/self", "贫僧");
  set("rank_info/respect", "佛祖爷爷");
  //set("class", "bonze");
  set("str",100);
  set("per",100);
  set("max_qi", 10000);
  set("max_jing", 10000);
  set("max_jing", 10000);
  set("neili", 10000);
  set("max_neili", 10000);
  set("force_factor", 500);
  set("max_neili", 10000);
  set("neili", 10000);
  set("mana_factor", 500);
  set("combat_exp", 4000000);
  set("combat_exp", 610000000);


  set("inquiry", ([
  
    "qujing" : (: reward_player :),
    "obstacle" : (: reward_player :),
    "obstacles" : (: reward_player :),
    "取经" : (: reward_player :),
    "经" : (: reward_player :),
  ]) );

  setup();
  initlvl((3000+random(3000)),random(63));
  carry_object("/d/obj/cloth/jia_sha")->wear();
}

void announce (object me, string str)
{
  if (DEBUG)
  { 
    object snowcat = find_player ("snowcat");
    if (snowcat && wizardp(snowcat))
      tell_object (snowcat,"◆ "+str+"\n");
  }
  else
  {
    CHANNEL_D->do_channel(me,"chat",str);
  }
}


void do_reward (object who)
{
  object me = this_object();
  int size1 = sizeof(obstacles);
  int size2;
  string *strs = values(obstacles);
  mapping skills = who->query_skills();
  int i;

  if (! interactive (who))
    return;

  if (who->query("obstacle/reward"))
    return;

  if (who->query_temp("no_move"))
    return;

  if (who->query("obstacle/number") < size1)
    return;

  size2 = sizeof(skills);

  message_vision ("宝殿里紫霞缭绕金光万道，$N见到如来真身浑身一软拜倒在地！\n",
                  who);
  message_vision ("\n$N对$n说："+RANK_D->query_respect(who)+
                  "一路上历经灾愆患难，万里迢迢苦尽功成也。\n",me,who);
  i = (size1+size2+2)*3;
  who->start_busy(i,i);
  who->set_temp("no_move",1);

  strs = (string *)sort_array (strs, 1);
  for (i = 0; i < size1; i++)
  {
    call_out("rewarding1",(i+1)*3,me,who,strs[i]);
  }
  call_out("rewarded1",(size1+1)*3,me,who);
  strs = keys(skills);
  for (i = 0; i < size2; i++)
  {
    call_out("rewarding2",(size1+i+2)*3,me,who,strs[i]);
  }
  call_out("rewarded2",(size1+size2+2)*3,size2,me,who);
}

void rewarding1 (object me, object who, string str)
{
  int i = 880+1800+random(who->query("kar")*88);

  who->add("obstacle/reward",i);
  who->add("combat_exp",i*3);
  who->add("potential",i);
  who->add("mpgx",3);
  message_vision ("\n$N说道："+str+"一关，奖$n"+chinese_number(i*3)+
                  "点经验和"+chinese_number(i)+"点潜能！\n",me,who);
  tell_object(who,"你的门派贡献增加了三点，你的经验增加了"+chinese_number(i*3)+"点！你的潜能增加了"+chinese_number(i)+"点！\n");
}

void rewarded1 (object me, object who)
{
  int i = who->query("obstacle/reward");

  remove_call_out("rewarding1");
  message_vision ("\n$N一点头：共计"+chinese_number(i*3)+"点经验"+chinese_number(i)+"点潜能！\n",me);
  announce (me,who->query("name")+"西天取经历经灾愆，奖励"+chinese_number(i*3)+"点经验 "+
            chinese_number(i)+"点潜能！一百零八点门派贡献！\n");
}

void rewarding2 (object me, object who, string str)
{
  int i = who->query_skill(str,1);
  string name = to_chinese(str);

  who->set_skill(str,i+10);
  message_vision ("\n$N说道：奖励十级"+name+"！\n",me,who);
  tell_object(who,"你的"+name+"增加了十级！\n");
}

void rewarded2 (int size, object me, object who)
{
  remove_call_out("rewarding2");
  message_vision ("\n$N一点头：共计"+chinese_number(size*10)+"级技能！\n",me);
  announce (me,who->query("name")+"西天取经功德无量，奖励"+
            chinese_number(size*10)+"级技能！\n");
  call_out("informing",1,me,who);
}

void informing (object me, object who)
{
  object ob;	
  int i=random(4);
  who->interrupt_me();
  who->set_temp("no_move",0);
  who->save();
  ob=new("/p/newweapon/weaponobj/kuangshi9");
  ob->move(who);
  ob=new("/p/newweapon/weaponobj/kuangshi9");
  ob->move(who);
  announce (me,who->query("name")+"西天取经功德无量，奖励"+
           ob->query("name")+"二份！\n");

  ob=new("/p/newweapon/weaponobj/buliao9");
  ob->move(who);
  announce (me,who->query("name")+"西天取经功德无量，奖励"+
           ob->query("name")+"一份！\n");

if (i==0)
{
  ob=new("/p/newweapon/weaponobj/buliao9");
  ob->move(who);
  announce (me,who->query("name")+"西天取经功德无量，奖励"+
           ob->query("name")+"一份！\n");
}
if (i==1)
{
  ob=new("/p/newweapon/weaponobj/kuangshi9");
  ob->move(who);
  ob=new("/p/newweapon/weaponobj/kuangshi9");
  ob->move(who);

  announce (me,who->query("name")+"西天取经功德无量，奖励"+
           ob->query("name")+"二份！\n");
}
 if (i==2)          
{
  ob=new("/p/newweapon/weaponobj/material5");
  ob->move(who);
  announce (me,who->query("name")+"西天取经功德无量，奖励"+
           ob->query("name")+"一份！\n");           
}
if (i==3)
{
ob=new("/p/newweapon/weaponobj/material11");
  ob->move(who);
  announce (me,who->query("name")+"西天取经功德无量，奖励"+
           ob->query("name")+"一份！\n");           
}
  
  me->set("my_level",LEVEL_NONE);
  me->delete_temp("invite");
  message_vision ("\n$N对$n说：起身，可去宝阁取真经一本。\n",me,who);

}

int reward_player ()
{
  object me = this_object();
  object who = this_player();
  object *all, *list;
  int size1 = sizeof(obstacles);
  int i, j;

  if (me->query("my_level") == LEVEL_ASKED)
  {
    message_vision ("$N对$n摇头说道：老夫正忙。\n",me,who);
    return 1;
  }

  if (who->query("obstacle/reward"))
  {
    message_vision ("$N对$n说道：你不是已经来过了吗？\n",me,who);
    return 1;
  }

  if (who->query_temp("no_move"))
  {
    message_vision ("$N对$n摇摇头。\n",me,who);
    return 1;
  }

  if (who->query("obstacle/number") < size1)
  {
    message_vision ("$N对$n摇头说道：你尚未历尽难关。\n",me,who);
    return 1;
  }




//   if ((i/4-j) > 0)

  announce (me,"西天取真经观礼："+who->query("name")+"大雄宝殿拜礼！\n");

  me->set("my_level",LEVEL_ASKED);
  do_reward (who);
  return 1;
}

void inviting (object me)
{
  int i;
  object *list;

  if (! me->query_temp("invite"))
    return;
  
  remove_call_out ("inviting");
  call_out ("inviting",4+random(4),me);

  list = users();
  i = sizeof(list);
  while  (i--)
  {
    string here, there;

    reset_eval_cost();
    if (!environment(list[i]))
      continue;
    if (environment(list[i])->query("unit")) // not a room
      continue;
    if (list[i]->is_fighting())
      continue;
    if (list[i]->is_busy())
      continue;
    if (list[i]->query_temp("no_move"))
      continue;
    if (list[i]->is_ghost()) // Checking ghost
      continue;
    if (!living(list[i]))
      continue;
    if ((string)list[i]->query_temp("accept")!=me->query("id"))
      continue;

    list[i]->set_temp("accept",0);
    here = (string)environment(me);
    there = (string)environment(list[i]);
    if (here == there)
      continue;

    message_vision("$N若有所思地向远方伸出手……\n",me);
    list[i]->set_temp("accept",0);
    list[i]->set_temp("lingshan/from",there);
    message_vision("一团祥云飘来，云中伸出一只巨大的佛手将$N轻轻托起，消失在天空。\n",list[i]);
    list[i]->move(here);
    message_vision("……$N轻轻一翻掌，$n稳稳地跳下来落在地上。\n",me,list[i]);
    break;
  }
}

int do_back(string arg)
{
  object who = this_player();
  object me = this_object();
  string here = (string)environment(me);
  string there = who->query_temp("lingshan/from");

  message_vision("$N请求$n送$N回返。\n",who,me);
  //if (!there)
  //  there = "/d/city/kedian";
  there = "/d/city/kedian";

  who->set_temp("accept",0);
  message_vision("$N的手掌轻轻托起$n向远方伸去……\n",me,who);
  who->move(there);
  message_vision("……云中伸出一只巨大的佛手轻轻一翻，只见$N从里面跳出来。\n",who);

  
  return 1;
}

void die()
{
  if (environment())
    message("sound", "\n\n如来缓缓一点头：佛法无边！\n\n", environment());

  set("eff_qi", 100000);
  set("eff_jing", 100000);
  set("eff_jing", 100000);
  set("qi", 100000);
  set("jing", 100000);
  set("jing", 100000);
  set("neili", 100000);
  set("neili", 100000);
}

void unconcious()
{
  die ();
}


