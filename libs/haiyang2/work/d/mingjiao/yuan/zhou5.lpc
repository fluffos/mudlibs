// zhou5.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;

void create()
{
        set_name("周五输", ({ "zhou wushu", "wushu", "zhou"}));
        set("title", HIC "神箭八雄" NOR);
        set("gender", "男性");
        set("age", 25);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("max_qi", 6500);
        set("max_jing", 6200);
        set("max_neili", 6500);
        set("neili", 500);
        set("jiali", 50);
        set("combat_exp", 130000+random(10000));

        set_skill("dodge", 380);
        set_skill("unarmed", 380);
        set_skill("throwing", 380);
        set_skill("xuanyuan-arrow", 380);
        set_skill("changquan", 380);
        set_skill("lingxu-bu", 380);
        map_skill("dodge", "lingxu-bu");
        map_skill("parry", "changquan");
        map_skill("throwing", "xuanyuan-arrow");
        map_skill("unarmed", "changquan");

	set_temp("is_riding", BLK"雪蹄马"NOR);
        setup();
        carry_object(__DIR__"obj/arrow")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver",5);
}
/*
void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
        object obj;
        if( objectp(obj = present("zhao min", environment(ob))) )
        {
                this_object()->set_leader(obj);
        }
}
*/
