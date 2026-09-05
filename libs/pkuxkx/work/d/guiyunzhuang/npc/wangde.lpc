//wangde.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("王德", ({ "wang de", "wang" }) );
	set("gender", "男性" );
	set("age", 29);
	set("long",
		"这是道貌岸然，中等个头，样子挺英俊的.\n");
	set("title",GRN"桃花岛"NOR+RED"第四代弟子"NOR);
	set("combat_exp",11000);
        set("str", 25);
        set("dex", 22);
        set("con", 20);
        set("int", 15);
	set("attitude", "heroism");
	set_skill("force",25);
	set_skill("dodge",25);
	set_skill("hand",25);
	set_skill("finger",25);
	set_skill("bihai-shengong",25);
	set_skill("luoying-shenfa",25);
	set_skill("fuxue-shou",30);
	set_skill("tanzhi-shengong",25);
	map_skill("force","bihai-shengong");
	map_skill("finger","tanzhi-shengong");
	map_skill("dodge","luoying-shenfa");
	map_skill("hand","fuxue-shou");	map_skill("finger","tanzhi-shengong");
	prepare_skill("hand","fuxue-shou");
	create_family("桃花岛",4,"弟子");
	set("shen_type",1);set("score",200);setup();
	carry_object("/d/city/obj/cloth")->wear();
}


	
