//Created by whuan@pkuxkx
//朱雀观道士
inherit NPC;
#include <ansi.h>

int do_ask();
void create()
{
	set_name("道士", ({ "dao shi","daoshi","dao" }));
	set("gender", "男性");
	set("age", 15 + random(15));
	set("long", "一个邋遢的道士，看起来古古怪怪的样子。\n");
	set("combat_exp", 100000);
	set("attitude", "peaceful");
	set("per", 15);
	set("str", 10);
	set("int", 30);
	set("con", 30);
	set("dex", 50);
	set("shen",100);   
	set("class","taoist");
	set("max_qi", 20000);
	set("max_jing", 20000);
	set("max_neili", 5000);
	set("neili", 5000);
	set("inquiry", ([
		"土匪":(:do_ask:),
       ]));
	setup();    
  carry_object("/d/city/obj/cloth")->wear();
	add_money("silver", random(5));
}

int do_ask()
{
	object me=this_object();
	object pl=this_player();
  message_vision("$N看了$n一眼，冷冷的道：这里是三清弟子修炼悟道之所，没有什么匪徒，各位请回吧！\n"
		+"说完，匆忙走入道观，从里面将门锁上。",me,pl);
  tell_object(pl,"你望着道士的背影，突然发现道袍之下，竟藏着一把\n钢刀，钢刀之上似有血迹，"
  	+"显然此人并非善类。\n你不由得暗自提高警惕。看来这里就是土匪窝。\n");
	destruct(this_object());
	return 1;
}

void fight_ob(object ob)
{
	command("fear");
	command("help!");
	message_vision("$N尖叫着逃走了。\n",this_object());
	destruct(this_object());
}

void kill_ob(object ob)
{
	command("fear");
	command("help!");
	message_vision("$N尖叫着逃走了。\n",this_object());
	destruct(this_object());
}

int accept_fight(object me)
{
	command("fear");
	command("shake");
	return 0;       
}