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
(["name": FOOD_D("hamigua"),"number":10]),
(["name": "/d/hj/obj/yangpi","number":10]),
(["name": "/d/hj/obj/jiunang","number":10]),
(["name": "/d/hj/obj/shuinang","number":10]),
  (["name": "/d/hj/obj/cheese","number":2]),
//ddddddddddddddddddddddddddddd
(["name": BINGQI_D("madao"),"number":10]),
(["name": BINGQI_D("mabian"),"number":10]),
(["name": BINGQI_D("wandao"),"number":10]),
(["name": ARMOR_D("qun"),"number":10]),
(["name": ARMOR_D("yangao"),"number":10]),
(["name": "/d/hj/obj/maotan","number":10])
        }) );
        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
"波斯生意人对你狡诈地挤了一下眼睛。\n",
        }));
        carry_object(BINGQI_D("wandao"))->wield();
        carry_object(ARMOR_D("changpao"))->wear();
        add_money("silver", 2);
}

void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
