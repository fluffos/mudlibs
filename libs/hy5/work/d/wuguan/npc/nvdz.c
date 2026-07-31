
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("古墓女弟子", ({ "gumu dizi", "gumu dizi" }) );
       set("gender", "女性" );
       set("age", 16);
       set("long",
               "这是是一位古墓女弟子，一身白衣。。\n");
       set("combat_exp", 10500);
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
			say( "古墓女弟子说道：古墓派清尘脱俗，想加入的话，可以看"BRED"(help gumu)"NOR"。\n");
			break;
		case 1:
			say( "古墓女弟子自语道：听说师哥，师姐们已经成为了神雕侠侣的传人，
 什麽时候能带我去看看呢？\n");
			break;
	}

}
