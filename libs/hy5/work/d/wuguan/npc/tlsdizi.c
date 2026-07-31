
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("天龙寺弟子", ({ "tianlongsi dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 18);
       set("long",
               "他是一个天龙寺的小师傅。\n");
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
			say( "天龙寺弟子说道：这位" + RANK_D->query_respect(ob)
          + "加入天龙寺的话，可以看看"BRED"(help tianlongsi)"NOR"会对你有帮助的。\n");
			break;
		case 1:
			say( "天龙寺弟子说道：一阳指，枯荣禅功可是佛门绝学，你要是再能学到六脉神剑的话，
  必能傲视群雄。\n");
			break;
	}

}
