 // girl.c
inherit NPC; 
void create()
{
    set_name("小薏", ({ "xiao yi" }) );
    set("gender", "女性" );
    set("per",30);
    set("age", 18);
        set("long",
        "这位小姑娘正笑咪咪地招呼来往的每位客人。\n");
    set("combat_exp", 500000);
        set("attitude", "friendly");
    set("rank_info/respect", "小姑娘");
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
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
            say( "小薏笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                + "，进来玩几把，放松放松吧。\n");
                        break;
                case 1:
            say( "小薏说道：这位" + RANK_D->query_respect(ob)
                + "，你今天一定能胡个大三元。\n");
                        break;
                case 2:
            say( "小薏说道：这位" + RANK_D->query_respect(ob)
                + "，你今天运气很好，会胡个大满贯的。\n");
                   break;
        }
}     
