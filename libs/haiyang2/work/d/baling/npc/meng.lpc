
inherit NPC;
inherit F_DEALER;
void create()
{
   set_name("孟老板",({ "meng laoban","meng","lao ban" }) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是当铺的老板，心狠手辣。\n");
       
   set("combat_exp", 500000);
   set("no_get",1);
   set("str", 30);
   set("attitude", "friendly");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
  add_action("do_list","list");
  add_action("do_buy","buy");
  add_action("do_sell","sell");
}