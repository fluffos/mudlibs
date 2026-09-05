#include <ansi.h>
#include "/quest/changan/quest.h"
inherit NPC;

string ask_salary();

void create()
{
	set_name("刘晏", ({ "hubu shangshu", "shangshu" }));
	set("title",HIY"户部尚书"NOR);
  set("gender", "男性");
	set("age", 50);
	set("long", "唐朝著名经济改革家和理财家，为安史之乱后的唐朝经济发展做出了重要贡献。\n");
	
	set("combat_exp", 100000);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

  set("inquiry", ([
    "俸禄" : (: ask_salary :),
    "兑换" : "兑换积分需要在我这里查看(list)当前爵位可以兑换服务列表，再从服务列表中选择想要服务。\n"
  ]) );

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
  add_action("do_list", "list");
  add_action("do_duihuan", "duihuan");
}

string ask_salary()
{
  object me=this_player();
  
	if ( TITLE_RANK->query_salary(me)>0 )
	{
	  TITLE_RANK->get_salary(me);
	  return "你从户部结算了当期你的爵位奖励。\n";
	}
	else
	  return "目前你无法领取任何爵位奖励。\n";
}

int do_list(string arg)
{
  object me=this_player();
  int rk;
  string info;
  
  rk=me->query("changan/level");
  if ( !rk )
  {
    tell_object( me, "你未拥有爵位，不能查看兑换服务列表。\n" );
    return 1;
  }
  
  if ( !arg )
  {
    info=TITLE_REWARD->list_reward(rk);
    info+=me->query("name")+"拥有本爵位兑奖积分："+me->query("changan/ext_points")+"点。\n";
  }
  else 
    info=TITLE_REWARD->list_detail(arg);
  
  tell_object(me, info);
  return 1;
}

int do_duihuan(string arg)
{
  object me=this_player();
  int rk;
  
  rk=me->query("changan/level");
  if ( !rk )
  {
    tell_object( me, "你未拥有爵位，不能兑换服务。\n" );
    return 1;
  }
  
  if ( !arg )
  {
    tell_object( me, "请输入要兑换的服务ID。\n" );
    return 1;
  }
  
  return TITLE_REWARD->get_reward(rk, arg, me);
}