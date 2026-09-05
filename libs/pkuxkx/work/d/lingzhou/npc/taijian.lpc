// zhangfang.c

inherit NPC;

int ask_me();

void create()
{
        set_name("太监", ({"taijian", "gongong"}));
        set("long",
"他长的身材象一个男人，可是举止、言谈和普通男人又有点不一样。\n");
        set("gender", "无性");
        set("attitude", "peacefull");

        set("inquiry",([
                "太监"    : (:ask_me:),
                "公公"    : (: ask_me :),

        ]));

        set("age", 31);
        set("shen_type", 0);
        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("dex", 25);
        set("max_qi", 500);
        set("max_jing", 100);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 100);
        set("combat_exp", 1000);
        set("apply/attack",  30);
        set("apply/defense", 30);

        set("shen_type",1);set("score",200);setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 5);
}

int ask_me()
{
        object me, ob;
        me = this_player();
	ob=this_object();
	command("taijian "+ob->query("id"));
	CHANNEL_D->do_channel(this_object(), "bd", "taijian "+me->query("id"));
        return 1;
}

