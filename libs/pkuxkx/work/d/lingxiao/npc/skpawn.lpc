// tang.c 唐老板 

inherit NPC;
//inherit F_VENDOR;

void create()
{
    set_name("小唐", ({ "xiao tang", "tang" }));
    set("title", "当铺老板");
    set("shen_type", 0);
     set("start_room","/d/city/dangpu");

    set("gender", "男性");
    set_max_encumbrance(100000000);
    set("age", 35);
    set("long",
        "据说他是唐楠的后代。\n");
//          set("no_get_from", 1);
//          set("no_get", 1);

    set_skill("unarmed", 60);
    set_skill("dodge", 60);
    set_temp("apply/attack", 30);
    set_temp("apply/attack", 30);
    set_temp("apply/damage", 15);

    set("combat_exp", 50000);
    set("attitude", "friendly");
    
    set("shen_type",1);set("score",200);setup();
}

void init()
{
//        add_action("do_list", "list");
//        add_action("do_buy", "buy");
//        add_action("do_sell", "sell");
//         add_action("do_value", "value");
}

//  void die()
//  {
//         message_vision("\n$N死了。\n", this_object());
//         destruct(this_object());
//  }
