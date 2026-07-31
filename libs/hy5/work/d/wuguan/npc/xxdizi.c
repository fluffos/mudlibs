inherit NPC;
#include <ansi.h>

void create()
{
       set_name("星宿弟子", ({ "xingxiu dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long", "他是一个满脸瘴气的星宿弟子。\n");
       set("combat_exp", 2500);
       set("attitude", "friendly");
       setup();
        carry_object("clone/cloth/cloth")->wear();

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
		case 0: say("星宿弟子嘿嘿说道：加入星宿，心慈手软可不行。这位"+RANK_D->query_respect(ob)+"，想通的话，可以看"BRED"(help xingxiu)"NOR"。\n");
			break;
		case 1: say("星宿弟子奸笑道：如果被我们星宿的化功大法打中，非要哀号数月而死。\n");
			break;
	}

}
