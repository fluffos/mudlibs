//Cracked by Roath
inherit NPC;inherit F_DEALER;
void create()
{
    
        set_name("凌汤圆", ({"ling", "ling tangyuan", "tangyuan"}));
        set("title", "汤圆店老板");
        set("gender", "男性");
        set("age", 42);
        set("long", "一个看起来很精明的商人。\n");
   set("str", 30);
   set("con", 30);
   set("spi", 30);
        set("combat_exp", 20000);
	set("combat_exp",20000);	
        set_skill("force", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
   set("neili", 200);
   set("max_neili", 200);
   set("force_factor", 5);
        set("vendor_goods", ({
               "/d/qujing/jz/obj/ty1",
                 "/d/qujing/jz/obj/ty2",
                "/d/qujing/jz/obj/ty3",
                "/d/qujing/jz/obj/ty4",
        }));
        setup();
   add_money("silver", 20);
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
                        say( name()+"笑道：来吃碗汤圆吧！\n");
                        break;
        }
}
