// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("趟子手", ({ "tang zishou", "tang" ,"huoji" }));
	set("title",GRN"震远镖局趟子手"NOR);
	set("long",
	"他是振远镖局的趟子手，精明能干，很得总镖头的信任。\n");
	set("gender", "男性");
	set("age", 20+random(20));
	set("attitude", "heroism");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 10000+random(3000));
	set_skill("dodge", 30);
	set_skill("unarmed", 40);
	set_skill("blade", 30);
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/blade")->wield();
}
