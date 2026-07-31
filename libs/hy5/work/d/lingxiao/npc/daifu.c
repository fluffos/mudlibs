// daihu.c

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("戴大夫", ({ "dai daifu", "dai" }));
        set("str", 60);
        set("gender", "男性");
        set("age", 18);
        set("long", "他是凌霄城的名医,在城中救人无数,深得尊敬。\n");
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/clone/misc/jinchuang",
                "/clone/misc/yangjing",
                "/clone/misc/wuchangdan",
                "/clone/misc/zhujingchan",
                "/clone/misc/hedinghong",
                "/clone/misc/bicanfeng",
                "/clone/misc/kongquedan",
        }));

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

