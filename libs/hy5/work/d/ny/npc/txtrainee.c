
// txtrainee.c
#include <ansi.h>

inherit NPC;

void create()
{
	string *surname=({"赵","钱","孙","李"});
	string *fname1=({"龙","子","天","鼎"});
	set_name( "天邪派"+(surname[random(4)])+(fname1[random(4)]), ({ "trainee" }) );
        set("shen_type",-1);
	set("gender", "男性" );
	set("age", 19);
	set("long", "你看到一位身材高大的汉子，正在辛苦地操练著。\n");
        set("combat_exp", 5000);
	set_skill("sword",30);
	set_skill("dodge",40);
	set_skill("unarmed",30);
	set_skill("parry",20);
	setup();
	carry_object(__DIR__"obj/bamboo_sword")->wield();
	carry_object(__DIR__"obj/linen")->wear();
}
