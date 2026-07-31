inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("波斯生意人", ({ "shengyi ren", "dealer", "ren" }));
        set("gender", "男性");
        set("age", 40 + random(10));
        set("long", "一个精明的波斯生意人。高鼻蓝眼的, 看着你脸上露出狡诈的笑容。\n");
        set("attitude", "friendly");
        set("combat_exp", 3000);
        set_skill("unarmed", 30);
        set_skill("blade", 30);
        set_skill("parry", 30);
        set_skill("dodge", 30);
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 20);
        set("vendor_goods", ({
                "/d/hj/obj/hamigua",
                "/d/hj/obj/yangpi",             
                "/d/hj/obj/jiunang",
                "/d/hj/obj/shuinang",
                "/d/hj/obj/cheese",
        }) );
        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
"波斯生意人对你狡诈地挤了一下眼睛。\n",
        }));
        carry_object(__DIR__"obj/wandao")->wield();
        carry_object(__DIR__"obj/changpao")->wear();
        add_money("silver", 2);
}

void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}