
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("峨嵋小师太", ({ "xiao shitai", "xiao" }) );
       set("gender", "女性" );
       set("age", 16);
       set("long",
               "这是是一位峨嵋的小师太，长的眉清目秀。\n");
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
			say( "小师太微微笑着说道：善哉，善哉，这位施主，想加入峨嵋的话，可以看"BRED"(help emei)"NOR"。\n");
			break;
		case 1:
			say( "小师太微笑道：峨嵋功夫清秀独特，临济十二庄为内功中的绝学。
 雁行刀，回风拂柳剑合壁后，威力无穷。\n");
			break;
	}

}
