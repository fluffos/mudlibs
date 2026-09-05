// sample master.c code
// xiake island master.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("龙亦凡", ({"island master", "long", "master"}));
	set("nickname", RED"不败神龙"NOR);
	set("title",GRN "侠客岛" NOR + YEL "岛主" NOR);
        set("gender", "男性");
	set("age", 120);
	set("long", 
		"这难道就是传说中的侠客岛岛主龙亦凡吗？\n他看上去跟一般的中年人无异，可是他已有百岁高龄。\n");
	set("attitude", "peaceful");
	set("shen_type", 1);
        set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);

	set("max_qi", 1800);
        set("max_jing", 800);
        set("neili", 10000);
	set("max_neili", 10000);
	set("jiali", 400);
	
	set("combat_exp", 5000000);
	set("score", 500000);
	
	set_skill("force", 300);
	set_skill("strike", 300);
	set_skill("xiake-strike", 300);
	set_skill("dodge", 300);
	set_skill("xiake-shenfa", 300);
	set_skill("literate", 300);
	set_skill("xiake-shengong",300);
	map_skill("strike", "xiake-strike");
	map_skill("dodge", "xiake-shenfa");
	map_skill("force","xiake-shengong");
	setup();
}
	

