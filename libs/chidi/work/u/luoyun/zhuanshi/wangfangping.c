#include <ansi.h>

inherit BHNPC;
inherit F_DEALER;

void create()
{
        set_name("王方平", ({ "wang fangping", "wang", "fangping" }));
        set("title", HIR "冥府地藏王殿前" NOR);
        set("nickname", WHT "鬼王" NOR);
        set("shen_type", 1);

        set("gender", "男性");
        set("age", 475);
        set("long", "王方平本是山中道士，后在丰都山修炼成仙，御封「鬼王」。\n");

        set_skill("unarmed", 500);
        set_skill("dodge", 500);
        set_skill("force", 500);
        set_skill("parry", 500);
        set_skill("magic", 500);
        set_temp("apply/damage", 2000);
        set_temp("apply/parry", 2000);
        set_temp("apply/dodge", 2000);
        set_temp("apply/attack", 2000);
        set_temp("apply/force", 2000);

        set("combat_exp", 20000000);
        set("attitude", "friendly");
        /*set("vendor_goods", ({
                __DIR__"/obj/xiandan",
                __DIR__"/obj/weapon1",
                __DIR__"/obj/weapon2",
                __DIR__"/obj/weapon3",
                __DIR__"/obj/weapon4",
                __DIR__"/obj/weapon5",
                __DIR__"/obj/weapon6",
                __DIR__"/obj/weapon7",
                __DIR__"/obj/weapon8",
                __DIR__"/obj/weapon9",
                __DIR__"/obj/weapon10",
                __DIR__"/obj/weapon11",
                __DIR__"/obj/weapon12",
                __DIR__"/obj/weapon13",
                __DIR__"/obj/weapon14",
                __DIR__"/obj/weapon15",
                __DIR__"/obj/weapon16",
                __DIR__"/obj/weapon17",
                __DIR__"/obj/weapon18",
                __DIR__"/obj/weapon19",
                __DIR__"/obj/weapon20",
                __DIR__"/obj/weapon21",
                __DIR__"/obj/weapon22",
                __DIR__"/obj/weapon23",
                __DIR__"/obj/weapon24",
                __DIR__"/obj/weapon25",
                __DIR__"/obj/weapon26",
                __DIR__"/obj/weapon27",
                __DIR__"/obj/weapon28",
                __DIR__"/obj/weapon29",
                __DIR__"/obj/weapon30",
                __DIR__"/obj/weapon31",
                __DIR__"/obj/weapon32",
                __DIR__"/obj/weapon33",
                __DIR__"/obj/weapon34",
                __DIR__"/obj/weapon35",
                __DIR__"/obj/weapon36",
                __DIR__"/obj/weapon37",
                __DIR__"/obj/weapon38",
                __DIR__"/obj/weapon39",
                __DIR__"/obj/weapon40",
                __DIR__"/obj/weapon41",
                __DIR__"/obj/weapon42",
                __DIR__"/obj/weapon43",
                __DIR__"/obj/weapon44",
                __DIR__"/obj/weapon45",
                __DIR__"/obj/weapon46",
                __DIR__"/obj/weapon47",
                __DIR__"/obj/weapon48",
                __DIR__"/obj/weapon49",
                __DIR__"/obj/weapon50",
                __DIR__"/obj/weapon51",
                __DIR__"/obj/weapon52",
                __DIR__"/obj/weapon53",
                __DIR__"/obj/weapon54",
                __DIR__"/obj/weapon55",
                __DIR__"/obj/weapon56",
                __DIR__"/obj/weapon57",
                __DIR__"/obj/weapon58",
                __DIR__"/obj/weapon59",
                __DIR__"/obj/weapon60",
                __DIR__"/obj/weapon61",
                __DIR__"/obj/weapon62",
                __DIR__"/obj/weapon63",
                __DIR__"/obj/weapon64",
                __DIR__"/obj/weapon65",
                __DIR__"/obj/weapon66",
                __DIR__"/obj/weapon67",
                __DIR__"/obj/weapon68",
                __DIR__"/obj/weapon69",
                __DIR__"/obj/weapon70",
                __DIR__"/obj/weapon71",
                __DIR__"/obj/weapon72",
                __DIR__"/obj/weapon73",
                __DIR__"/obj/weapon74",
                __DIR__"/obj/weapon75",
                __DIR__"/obj/weapon76",
                __DIR__"/obj/weapon77",
                __DIR__"/obj/weapon78",
                __DIR__"/obj/weapon79",
                __DIR__"/obj/weapon80",
        }));
        */
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}
/*void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
*/