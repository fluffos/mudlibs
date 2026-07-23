
inherit NPC;
inherit F_DEALER;
void create()
{
//   reload("suiye_lilaoban");
   set_name("李老板",({ "li laoban","li"}) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是书铺的老板,他的文化水平也是很高的。\n");
   set("shop_id",({ "piao laoban","piao"}) );
   set("combat_exp", 20000);
   set("str", 25);
   set("per", 24);
 
   set("attitude", "peaceful");
	set("vendor_goods", ({
	  __DIR__"obj/wenxue",	  
	}));
   setup();
  
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