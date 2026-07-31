//Cracked by Roath

inherit NPC;inherit F_DEALER;
void create()
{
        
        set_name("荷花", ({"he hua", "hua"}));
        set("title", "卖花的");
        set("gender", "女性");
        set("age", 19);
        set("long", "一个很漂亮的小姑娘，真和她的名字相配。\n");
        set("per",30);
        set("combat_exp", 20000);
	set("combat_exp",20000);		
        set("vendor_goods", ({
               "/d/qujing/jz/obj/lan",
                "/d/qujing/jz/obj/mei",
                "/d/qujing/jz/obj/mudan",
               "/d/qujing/jz/obj/purple",
        }));
        setup();
   add_money("silver", 5);
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
     call_out("greeting",1,ob);
        }
        add_action("do_buy", "buy");add_action("do_list", "list");

}
void greeting(object ob)
{
    if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                      say( name()+"笑道：买朵花给你的情人吧！\n");
                        break;
        }
}
