
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("桃花岛弟子", ({ "taohuadao dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一个清秀的桃花岛弟子。\n");
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
			say( "桃花岛弟子说道：这位" + RANK_D->query_respect(ob)
            + "加入桃花岛可不容易，可以看看"BRED"(help taohuadao)"NOR"会对你有帮助的。\n");
			break;
		case 1:
			say( "桃花岛弟子说道：我们岛主黄药师琴棋书画无所不精，他老人家的功夫
 你如能学得一二，就能出人头地了。\n");
			break;
	}

}
