// mawude.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("马五德", ({ "ma wude", "ma" }));
	set("title","金牛武馆馆长");
	set("long", "马老爷子是武馆的缔造者，辛苦一辈子了，仍勇于提携后生。\n");
	set("gender", "男性");
	set("age", 65);
	 set("icon","00723");
	set_skill("dodge", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("unarmed", 80);
	set_skill("hand", 80);
	set_skill("blade", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 400000);
	set("shen_type", 1);

	set("vendor_goods", ({
		"/clone/book/advance-sword",
		"/clone/book/advance-blade",
		"/clone/book/advance-dagger",
		"/clone/book/advance-unarmed",
		"/clone/book/advance-dodge",
		"/clone/book/advance-parry",
		"/clone/book/advance-force",
		"/clone/book/advance-staff",
		"/clone/book/advance-whip",
       		"/clone/book/advance-club",
		"/clone/book/advance-throwing",
	}));

	setup();    
}

void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

int recognize_apprentice(object ob)
{
	if (! (int)ob->query_temp("marks/jinniu_paied") == 1) return 0;
	return 1;
}
