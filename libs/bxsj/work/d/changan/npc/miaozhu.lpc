// Write By Yanyang@SJ 2001.9.29
// NPC : /d/changan/npc/miaozhu.c

inherit NPC;

void create()
{
        set_name("庙祝", ({ "miao zhu", "zhu", "keeper" }) );
        set("gender", "男性" );
        set("age", 67);
        set("long","这个老人看起来六十多岁了，年级是大了，但精神却很好。\n");
        set("combat_exp", 21000);
        set("attitude", "friendly");
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
}
void init()
{       
        object ob;

        ::init();
        if (base_name(environment()) != query("startroom")) return;
        if( interactive(ob = this_player()) && visible(ob) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if (!ob || !present(ob, environment())) return;
        switch( random(2) ) {
                case 0:
                        say( "庙祝说道：这位" + RANK_D->query_respect(ob)
                                + "，捐点香火钱积点阴德，修些福缘吧。\n");
                        break;
                case 1:
                        say( "庙祝说道：这位" + RANK_D->query_respect(ob)
                                + "，捐点香火钱吧。\n");
                        break;
        }
}
