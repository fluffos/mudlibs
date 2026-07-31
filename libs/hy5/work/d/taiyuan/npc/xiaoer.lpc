
inherit NPC;
inherit F_DEALER;
void create()
{
//   reload("ty_xiaoer");
   set_name("店小二",({ "xiao er","xiao","er" }) );
        set("gender", "男性" );
        set("age", 22);
   set("long", "这是这家小茶馆的店小二。\n");
    set("shop_id",({ "xiao er","xiao","er" }) );
   set("combat_exp", 200);
   set("str", 18);
   set("per", 22);
   set("attitude", "friendly");
	set("vendor_goods", ({
	   __DIR__"obj/jiudai",
	   __DIR__"obj/huotui",
	   __DIR__"obj/niurou",
	   __DIR__"obj/huasheng",
	   __DIR__"obj/gourou",
	   __DIR__"obj/zharoupai",
	   __DIR__"obj/rougan",
	   __DIR__"obj/xiancai",
	   __DIR__"obj/yangtui",
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
