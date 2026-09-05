//Cracked by Roath
// seller.c

inherit NPC;
//inherit F_VENDOR;

void create()
{
        set_name("刘老板", ({ "liu laoban", "liu" }) );
        set("gender", "男性" );
        set("age", 32);
        set("long",
                "他就是京城有名的字画商刘老板。\n");
        set("combat_exp", 90000);
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
        set("attitude", "friendly");
/*
        set("vendor_goods", ({
                "/d/beijing/obj/paper",
                "/d/beijing/obj/envelope",
        }) );
*/
        setup();
        carry_object("/d/city/obj/cloth")->wear();
        add_money("silver", 60);
}

#include "/d/beijing/killme.h"
