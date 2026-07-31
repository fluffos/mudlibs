//Cracked by Roath
// tidu.c

#include <ansi.h>

inherit NPC;

string ask_for_join();
string ask_for_leave();
string ask_for_huansu();

void create()
{
	set_name("剃度僧", ({ "tidu seng", "seng" }) );

	set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("class", "bonze");

	set("str", 17);
	set("int", 30);
	set("spi", 30);
	set("con", 30);
	set("cps", 30);
	set("cor", 20);

	

	map_skill("force", "lotusforce");
	map_skill("spells", "buddhism");

	create_family("南海普陀山", 4, "弟子");

	setup();

	carry_object("/d/xiyou/nanhai/obj/sengpao")->wear();
}

