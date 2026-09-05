#include <ansi.h>
#include "/quest/changan/quest.h"
inherit NPC;

int ask_levelup();
int ask_title();

void create()
{
	set_name("李林甫", ({ "libu shangshu", "shangshu" }));
	set("title",CYN"吏部尚书"NOR);
  set("gender", "男性");
	set("age", 50);
	set("long", "唐玄宗李隆基时的著名宰相，奸佞多狡诈，助成安史之乱。\n");
	
	set("combat_exp", 100000);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

  set("inquiry", ([
    "提升爵位" : (: ask_levelup :),
    "爵位" : (: ask_title :),
  ]) );

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

/*处理
    1-开国县男
    2-开国县子
    3-开国县伯
    4-开国县侯
  以上四个爵位的爵位认定工作
*/
int ask_levelup()
{
	if ( this_player()->query("changan/level")<4 )
	  TITLE_RANK->add_level(this_player());
	else
		tell_object(this_player(), "你的爵位太高了，我这里无权处理你的爵位。\n");
	
	return 1;
}

int ask_title()
{
	int rk;
	rk=this_player()->query("changan/level");
	if ( !rk )
		tell_object(this_player(), "你目前并没有爵位。\n");
	else
	  tell_object(this_player(), "你目前的爵位是"+TITLE_RANK->query_rank(this_player()->query("changan/level"))+"。\n");
	  
	TITLE_RANK->query_points(this_player());
	return 1;
}