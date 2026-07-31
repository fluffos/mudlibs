// tang.c 唐老板 

#include <ansi.h>
inherit NPC;
inherit F_BANKER;

int redeem(string arg);

void create()
{
       set_name("彝南柯", ({ "banker" }) );;
        set("title", "彝源老板");
        set("gender", "男性" );
        set("age", 26);
	set_max_encumbrance(100000000);

        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);

        set("long",
                
"彝南柯是个看起来相当斯文的年轻人，不过有时候会有些心不在焉的\n"
                
"样子，宁远城的居民对彝南柯都觉得有点神秘莫测的感觉，为什麽他\n"
                
"年纪轻轻就身为一家大钱庄的老板，还有他一身稀奇古怪的武功，所\n"
                
"幸彝南柯似乎天性恬淡，甚至有些隐者的风骨，只要旁人不去惹他，\n"
                "他也绝不会去招惹旁人。\n");
	set("no_get_from", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_check", "check");
        add_action("do_check", "chazhang");
        add_action("do_convert", "convert");
        add_action("do_convert", "duihuan");
        add_action("do_deposit", "deposit");
        add_action("do_deposit", "cun");
        add_action("do_withdraw", "withdraw");
        add_action("do_withdraw", "qu");
        delete_temp("busy");
}


void die()
{
	message_vision("\n$N死了。\n", this_object());
	destruct(this_object());
}

