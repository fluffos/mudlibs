// created 4/4/1997 by snowcat


inherit NPC;inherit F_DEALER;

void create()
{
  string dir;
  ("nuerguo_old_woman");
  set_name("老婆婆", ({"old woman", "woman"}));
  set("shop_id", ({"popo", "woman"}));
  set("gender", "女性" );
  set("age", 65);
  set("long", "一位白发苍苍，满面风霜的老婆婆。\n");
  set("combat_exp", 100);
  set("attitude", "peaceful");
  set("per", 15);
/*
  dir = __DIR__;
  dir[strlen(dir)-4] = 0;
*/
  dir = "/d/qujing/nuerguo/";
  set("vendor_goods", ({
        dir+"obj/qiongyao",
        dir+"obj/huasheng",
        "/d/obj/food/hulu",
     }));
  setup();
  carry_object("/d/qujing/nuerguo/obj/skirt")->wear();
  add_money ("silver", 2);  
}

void init()
{
  ::init();
  add_action("do_buy", "buy");add_action("do_list", "list");
}

