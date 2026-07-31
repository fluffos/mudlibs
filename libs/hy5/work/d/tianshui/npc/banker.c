// banker.c

inherit NPC;
inherit F_BANKER;
void create()
{
        set_name("鲁得财", ({ "lu decai","lu"}) );
        set("title", "钱庄老板");
        set("gender", "男性" );
        set("age", 46);

        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);

        set("long",@LONG
鲁得财是个看起来相当斯文的人，笑起来
一脸和气，不过有时目光一闪，眼睛里会
露出一丝狡邪的贼光。
LONG
);

	set("combat_exp", 2000);
	set("attitude", "friendly");

	set("max_atman", 500);
	set("atman", 500);
	set("max_force", 1000);
	set("force", 1000);
	set("force_factor", 20);
	set("max_mana", 500);
	set("mana", 500);
set("no_kill",1);
set("no_get",1);
	set_skill("unarmed",100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("force", 100);
	setup();
        
	carry_object("/clone/misc/cloth")->wear();
}

int accept_fight(object me)
{
        command("say 咦... 要打就真打吧，光是较量多没意思？");
        command("grin");
        kill_ob(me);
        return 1;
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
