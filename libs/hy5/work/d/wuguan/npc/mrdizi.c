
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("慕容弟子", ({ "murong dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 16);
       set("long",
               "他是一个年纪很清的少年，但是身强力壮。\n");
       set("combat_exp", 12500);
       set("attitude", "friendly");
 
       setup();
 carry_object("/clone/misc/cloth")->wear();
}
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
	 

	if (!ob || !present(ob, environment())) return;
	switch( random(2) ) {
		case 0:
			say( "慕容弟子正颜道：慕容山庄是武林人人景仰的地方。这位" + RANK_D->query_respect(ob)
             + "，想去慕容山庄的话，可以看"BRED"(help murong)"NOR"。\n");
			break;
		case 1:
			say( "慕容弟子认真的练习着斗转星移的武林绝技，脸上充满着自信。\n");
			break;
	}

}
