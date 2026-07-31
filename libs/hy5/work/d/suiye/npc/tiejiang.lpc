
inherit NPC;
inherit F_DEALER;
void create()
{
//      reload("suiye_tiejiang");
   set_name("铁匠",({ "tie jiang","tie","jiang","tiejiang" }) );
        set("gender", "男性" );
        set("age", 40);
   set("long", "这是碎叶的铁匠，他卖一些兵器挣点外快。\n");
    set("shop_id",({ "tie jiang","tie","jiang","tiejiang" }) ); 
   set("combat_exp",300000);
   set("str",26);
   set("per", 22);
   set("force",500);
   set("max_force",500);
   set("kee",800);
   set("max_kee",800);
   set("sen",500);
   set("max_sen",500);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
	set("vendor_goods", ({
	  __DIR__"obj/changjian",
	  __DIR__"obj/blade",
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
