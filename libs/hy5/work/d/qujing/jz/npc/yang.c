//Cracked by Roath
 
inherit NPC;inherit F_DEALER;

void create()
{
  set_name("伙计", ({"huoji"}));
  set("shop_id", ({"huoji"}));
  set("shop_title", "小伙计");
  set("gender", "男性" );
  set("age", 18);
  set("per", 25);
  set("combat_exp", 1000);
	set("combat_exp",1000);	
  set("max_qi", 300);
  set("max_jing", 300);
  set("attitude", "friendly");
  set("per", 15);
  set("vendor_goods", ({
           "/d/qujing/jz/obj/fuchen",
           "/d/qujing/jz/obj/dadao",
           "/d/qujing/jz/obj/zhujian",
"/d/obj/qjzp",

     }));
  setup();
  add_money ("coin", 50+random(300));
  carry_object("/d/obj/cloth/linen")->wear();
}
void init()
{
  ::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}
