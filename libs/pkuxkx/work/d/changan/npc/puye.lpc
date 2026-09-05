#include <ansi.h>
inherit NPC;

int ask_title();

void create()
{
	set_name("房玄龄", ({ "shangshu puye", "puye" }));
	set("title",HIY"尚书左仆射"NOR);
  set("gender", "男性");
	set("age", 50);
	set("long", "唐初名相，任尚书省长官，负责整个政府的日常事务。\n");
	
	set("combat_exp", 100000);
	set("shen_type", 1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

  set("inquiry", ([
    "爵位" : (: ask_title :),
  ]) );

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

int ask_title()
{
	write("任务正在开发中！\n");
	return 1;
}