// golder.c

#include <ansi.h>
inherit NPC;
inherit F_DEALER;
int do_make(string arg);

void create()
{
	set_name("老乞丐", ({"beggar","seller"}));
	set("title","痞子帮堂主");
       set("nickname", HIW "乞丐王" NOR );
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 150);
       set_skill("blade", 100);
	set("gender","男性");

	set("force",2000);
	set("max_force",2000);
	set("str",70);
	set("food",200);
	set("water",200);
	set("combat_exp",40000);

	set("age", 37);
	set("long", @LONG
他就是金陵最大的帮会痞子帮的堂主，他看起来三十多岁，
满面红光，太阳穴高高鼓起，一看就只武功不弱。
LONG
);


	set("vendor_goods", ({
		__DIR__"obj/armor",
	}));
	setup();
       set("chat_chance", 40);
       set("chat_msg", ({
                "老乞丐说道：我这里有个宝贝......你要不要呀？\n",
                (: random_move :)
        }) );


	carry_object(__DIR__"obj/linen")->wear();
        carry_object(__DIR__"obj/betbook");

	carry_object(__DIR__"obj/blade")->wield();
}

void init()
{
	::init();
	add_action("do_vendor_list", "list");
	add_action("do_buy", "buy");
}

