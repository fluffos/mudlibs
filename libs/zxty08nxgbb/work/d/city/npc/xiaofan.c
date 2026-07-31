// NPC: /d/city/npc/xiaofan.c
// Date: Qianyu 99/11/06

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("小贩", ({"xiao", "xiao fan", "fan"}));
	set("long", "一个看起来精明能干的小贩。\n");
	set("gender", "男性");
        set("combat_exp", 10000);
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 17);
	set("dex", 20);
	set("con", 17);
	set("int", 22);
        set_skill("dodge",20);
        set_skill("unarmed",20);
	set("vendor_goods", ({
     "/clone/weapon/changjian",
      "/clone/cloth/dao-xie",
     "/d/city/obj/zaisheng",
     "/clone/misc/site",
     "/clone/misc/sleepbag",
	}) );
       
        setup();
       add_money("coin", 40+random(30));
}
void init()
{
        object ob;

        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
        set("chat_chance", 10);
        set("chat_msg", ({
            "小贩打了个喷嚏．\n",
            "小贩上上下下打量了你几眼。\n",
        }) );
}

