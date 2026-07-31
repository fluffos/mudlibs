
inherit NPC;
inherit F_DEALER;
void create()
{
   //reload("ls_yaodian_song");
   set_name("宋大夫",({ "song daifu","song","daifu"}) );
        set("gender", "男性" );
        set("age", 40);
   set("long", "这是渔阳的王药师，他这里有很多新奇的药物。\n");
    set("shop_id",({ "song daifu","song","daifu"}) );
   set("combat_exp",300000);
   set("str",26);
   set("per", 22);
   set("force",500);
   set("max_force",500);
   set("kee",800);
   set("max_qi",800);
   set("jing",500);
   set("max_jing",500);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
	set("vendor_goods", ({
                __DIR__"obj/qi",
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
