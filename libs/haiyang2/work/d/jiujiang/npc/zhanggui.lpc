
inherit NPC;
inherit F_DEALER;
void create()
{
   
   set_name("掌柜",({ "zhang gui","zhang","gui" }) );
        set("gender", "男性" );
        set("age",42);
   set("long", "这是春在楼的掌柜。\n");
    set("shop_id",({ "zhang gui","zhang","gui" }) ); 
   set("combat_exp",300000);
   set_skill("parry",130);
   set_skill("dodge",130);
   set_skill("force",130);

   set("attitude", "friendly");
	set("vendor_goods", ({
	   __DIR__"obj/cha",
	   __DIR__"liji",
	   __DIR__"songgao",
	   __DIR__"huasheng",
	   __DIR__"obj/jiu",
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
