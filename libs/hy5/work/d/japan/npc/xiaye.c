#include <ansi.h>

inherit NPC;
inherit F_BANKER;
void create()
{
        set_name("下野德康",({"xiaye dekang","xiaye","dekang"}));
//this_object()->init_bhnpc();
//set("area_name","神户钱庄");
//set("area_file","/d/japan/qianzhuang.c");
        set("gender","男性");
         set("title","神户钱庄");
        set("combat_exp",300000);
        set_skill("unarmed",50);
        set_skill("parry",50);
        set_skill("dodge",50);
        set_skill("sword",50);
	set("attitude", "friendly");

        set("inquiry", ([
            "利息":   "我们庄的规矩是提取两成保管费。\n",
            "lixi":   "我们庄的规矩是提取两成保管费。\n",
                       ]) );

	setup();
	
       carry_object("/clone/weapon/changjian")->wield();
       carry_object("/clone/cloth/cloth")->wear();

	add_money("gold", 1);
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
