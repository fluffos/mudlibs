//chensan.c
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("小花",({"xiao hua","hua","xiao"}));
	set("gender", "女性" );
	set("age", 5);
	set("long",
		"她风姿诱人，堪称人间仙子.\n");
	set("title",GRN"桃花岛"NOR+RED"第四代弟子"NOR);
	set("combat_exp", 4000);
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 15);
	set("attitude", "heroism");
	set_skill("force",20);
	set_skill("dodge",20);
	set_skill("hand",20);
	set_skill("finger",20);
	set_skill("bihai-shengong",20);
	set_skill("luoying-shenfa",20);
	set_skill("fuxue-shou",20);
	set_skill("tanzhi-shengong",20);
	map_skill("force","bihai-shengong");
	map_skill("finger","tanzhi-shengong");
	map_skill("dodge","luoying-shenfa");
	map_skill("hand","fuxue-shou");
	prepare_skill("finger","tanzhi-shengong");
	create_family("桃花岛",4,"弟子");
	set("shen_type",1);set("score",200);setup();
	carry_object("/d/city/obj/cloth")->wear();
}
