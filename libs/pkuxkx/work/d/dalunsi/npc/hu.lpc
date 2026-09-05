// hu.c 胡贵

inherit NPC;
#include <ansi.h>
inherit F_VENDOR;

void create()
{
        set_name("胡贵", ({ "hu gui", "hu" ,"hugui","gui"}));
        set("title", HIW"酒馆老板"NOR);
        set("nickname", RED"烧酒胡"NOR);
        set("shen_type", 1);

        set("str", 20);
        set("gender", "男性");
        set("age", 45);
        set("long", "他是溢香楼的老板，因为酿酒手艺好，得了现在这个绰号。\n");
        set("combat_exp", 2000);
        set("qi", 300);
        set("max_qi", 300);
        set("attitude", "friendly");
        set("unique", 1);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set("vendor_goods", ({
                __DIR__"obj/roubing",
                __DIR__"obj/shaojiu",
                }));

        setup();
        add_money("silver", 50);
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

