// chongxu.c 冲虚道长
// seagate@pkuxkx 2010/10/30
#include <ansi.h>
inherit NPC;

#include "/newbiequest/questdefault.h"                       //加载默认的任务处理函数
#include "/newbiequest/wudang/quest_caiqi.h"                 //加载采气任务的处理函数
#include "/newbiequest/wudang/quest_chanting.h"             //加载和诵经任务相关函数
#include "/newbiequest/wudang/quest_liandan.h"               //加载炼丹任务的处理函数
#include "/newbiequest/wudang/quest_zhenfa.h"                //加载阵法演练任务的处理函数
#include "/newbiequest/wudang/quest_fighter.h"               //加载侠客任务的处理函数
mapping newbie_list=
 (["chanting":
 	  (["start": (: start_chanting, "诵经任务", "chanting" :),
 	    "end"  : (: end_public_proc :),
 	    "fail" : (: fail_public_proc :),
 	    "weight" : 100,
 	    "reward" : 100]),
 	 "caiqi":
 	  (["start": (: start_caiqi, "采气任务", "caiqi" :),
 	    "end"  : (: end_caiqi :),
 	    "fail" : (: fail_public_proc :),
 	    "weight" : 100,
 	    "reward" : 100,
 	    "shichen" : ({12,24})]),
   "liandan":
 	  (["start": (: start_liandan, "炼丹任务", "liandan" :),
 	    "end"  : (: end_public_proc :),
 	    "fail" : (: fail_public_proc :),
 	    "weight" : 100,
 	    "reward" : 120]),
   "zhenfa":
 	  (["start": (: start_zhenfa, "阵法演练任务", "zhenfa" :),
 	    "end"  : (: end_public_proc :),
 	    "fail" : (: fail_public_proc :),
 	    "weight" : 100,
 	    "reward" : 100]),
   "fighter":
 	  (["start": (: start_fighter, "侠客任务", "fighter" :),
 	    "end"  : (: end_public_proc :),
 	    "fail" : (: fail_public_proc :),
 	    "weight" : 100,
 	    "reward" : 200,
 	    "explimit" : 50000])]);

#include "/newbiequest/newbiequest.h";                       //新手任务公共头文件

void create()
{
  set_name("冲虚道长", ({ "chongxu daozhang", "chongxu" }));
  set("long",
          "他是武当派的真人冲虚道长，已年过七旬。\n");
  set("title",RED "武当派" NOR + GRN +"真人" NOR);
  set("gender", "男性");
  set("age", 71);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("str", 28);
  set("int", 28);
  set("con", 28);
  set("dex", 28);
  set("chat_chance_combat", 50);
  set("chat_msg_combat", ({
    (: perform_action, "sword.chan" :),
    (: perform_action, "sword.lian" :),
    (: exert_function , "powerup" :)
  }) );
  set("max_qi", 16000);
  set("max_jing", 6000);
  set("neili", 7000);
  set("max_neili", 7000);
  set("jiali", 200);
  set("combat_exp", 25000000);
  set("score", 600000);
  set_skill("force", 400);
  set_skill("taiji-shengong", 400);
  set_skill("dodge", 400);
  set_skill("tiyunzong", 400);
  set_skill("cuff", 400);
  set_skill("taiji-quan", 400);
  set_skill("parry", 400);
  set_skill("sword", 400);
  set_skill("taiji-jian", 400);
  set_skill("taoism",400);
  map_skill("force", "taiji-shengong");
  map_skill("dodge", "tiyunzong");
  map_skill("cuff", "taiji-quan");
  map_skill("parry", "taiji-quan");
  map_skill("sword", "taiji-jian");
  prepare_skill("cuff", "taiji-quan");
  create_family("武当派", 2, "弟子");
  set_temp("apply/armor",200);
  set_temp("apply/attack",200);
  set_temp("apply/damage",200);

	set("inquiry", ([
		"新手任务" : (: newbie_quest :),
		"quest"    : (: newbie_quest :),
		"cancel"   : (: cancel_newbie :),
		"失败"     : (: cancel_newbie :),
		"成功"     : (: over_newbie :),
		"success"  : (: over_newbie :)
	]));
        
  setup();
  carry_object("/clone/weapon/changjian")->wield();
  carry_object("/d/wudang/obj/greyrobe")->wear();
}