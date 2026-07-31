
inherit NPC;
inherit F_DEALER;
void create()
{
//    reload("suiye_xiaoer2");
   set_name("店小二",({ "xiao er","xiao","er" }) );
        set("gender", "男性" );
        set("age", 22);
   set("long", "这是这家杂货铺的店小二。\n");
       set("shop_id",({ "xiao er","xiao","er" }) );
   set("combat_exp", 200);
   set("str", 18);
   set("per", 22);
   set("attitude", "friendly");
	set("vendor_goods", ({
	   __DIR__"obj/jiudai",
	   __DIR__"obj/kaoya",
	   __DIR__"obj/changjian",
                "/d/city/npc/obj/mabudai",
                "/d/city/npc/obj/beixin",
                "/d/city/npc/obj/toukui",
                "/d/city/npc/obj/cycle",
                "/d/city/npc/obj/surcoat",
                "/d/city/npc/obj/shield",
                "/d/city/npc/obj/huwan",
                "/d/city/npc/obj/zhitao",
                "/d/city/npc/obj/huyao",
                "/d/city/npc/obj/caoxie",
                "/d/city/npc/obj/pixue",
                "/d/city/npc/obj/shoutao",
                "/d/city/npc/obj/tieshou",
                "/d/city/npc/obj/jinsijia",
                "/d/xingxiu/obj/fire",	
	}));
   setup();
 //  carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

int regenerate()
{
        set("called", 0);
        return 1;
}
