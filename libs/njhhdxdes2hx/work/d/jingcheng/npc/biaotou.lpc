// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("镖师", ({ "biao shi", "biao" ,"shi" }));
	set("title",GRN"震远镖局镖头"NOR);
	set("long",
	"他是振远镖局的护镖镖师。为生活所迫，加入到护镖的行列。到现在在武林中也算闯\n"
	"出了一点名气。\n");
	set("gender", "男性");
	set("age", 20+random(20));
	set("attitude", "heroism");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 30000+random(5000));
	set_skill("dodge", 60);
	set_skill("unarmed", 50);
	set_skill("blade", 50);
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/blade")->wield();
}
