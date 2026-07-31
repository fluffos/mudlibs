
inherit NPC;
inherit F_DEALER;
void create()
{
//    reload("suiye_xiaoer");
   set_name("店小二",({ "xiao er","xiao","er" }) );
        set("gender", "男性" );
        set("age", 22);
   set("long", "这是醉仙楼的店小二,每天忙个不停。\n");
       set("shop_id",({ "xiao er","xiao","er" }) );
   set("combat_exp", 200);
   set("str", 18);
   set("per", 22);
   set("attitude", "friendly");
	set("vendor_goods", ({
	   __DIR__"obj/jiudai",
	   __DIR__"obj/kaoya",
		__DIR__"obj/tea1",
		__DIR__"obj/tea2",
		__DIR__"obj/tea3",
		__DIR__"obj/tea4",
	}));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
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
