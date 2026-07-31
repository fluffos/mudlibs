
inherit NPC;
inherit F_DEALER;
void create()
{
   //reload("ls_xiaoer2");
   set_name("店小二",({ "xiao er","xiao","er"}) );
        set("gender", "男性" );
        set("age", 20);
   set("long", "这是茶馆的店小二。\n");
    set("shop_id",({ "xiao er","xiao","er"}) );
   set("combat_exp",3000+random(3000));
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
	set("vendor_goods", ({
	  __DIR__"obj/jiudai",
	  __DIR__"obj/kaoya",
	  __DIR__"obj/kaoyangrou",
	  __DIR__"obj/gongbao-jiding",
	  __DIR__"obj/liudoufu",
	  __DIR__"obj/jiachang-liangcai",
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
