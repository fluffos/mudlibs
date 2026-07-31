inherit NPC;
inherit F_DEALER;

void create()
{
//   reload("hz_huang");
   set_name("黄先生",({ "huang xiansheng","huang"}) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是药店的老板,他这里的药种类很多的。\n");
    set("shop_id",({ "huang xiansheng","huang"}) );
   set("combat_exp", 60000);
   set("str", 25);
   set("per", 24);
 	set("vendor_goods", ({
	   __DIR__"obj/yangjingdan.c",
	   __DIR__"obj/buxuedan.c",
	}));
   set("attitude", "peaceful");

   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
  
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
