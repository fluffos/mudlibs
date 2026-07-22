// cracked by vikee 2/09/2002   vikee@263.net
// snshou.c 唢呐手

#include <ansi.h>
inherit NPC;

int do_kill(string);

void create()
{
	set_name("唢呐手", ({ "suona shou", "shou" }));
	set("long", "他就是婚礼上奏礼乐的吹鼓手。\n"
		"他手中拿着一只唢呐，正鼓足力气沉醉地吹着。\n");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("str", 50);
	set("int", 10);
	set("max_kee", 500);
	set("combat_exp", 10000);
	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);

	setup();
}

void init()
{
	add_action("do_kill", "kill");
	add_action("do_kill", "fight");
}

int do_kill(string arg)
{
	if ((arg=="shou" || arg=="suona shou")
		&& environment()!=find_object("/d/moon/yltw")) {
		write("你想坏人好事，太不道德了吧。\n");
		return 1; }
	return 0;
}
