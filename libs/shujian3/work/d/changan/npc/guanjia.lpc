// Write By Yanyang@SJ 2001.10.1
// NPC : /d/changan/npc/guanjia.c

inherit NPC;

void create()
{
        set_name("管家", ({ "guan jia", "guanjia" }) );
        set("gender", "男性" );
        set("age", 56);
        set("long","他满头白发，看来为料理府中事务操了不少心。\n");
        set("combat_exp", 10000);
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
                        say( "管家迎上来说道：这位" + RANK_D->query_respect(ob)
                                + "，将军不在家，有事请晚些时候再来吧。\n");
                        break;
                case 1:
                        say( "管家迎上来说道：这位" + RANK_D->query_respect(ob)
                                + "，将军不在家，您坐下来等一等，我这就去上茶。\n");
                        break;
        }
}