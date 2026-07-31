
// blacksmith.c 修理师傅
#include <ansi.h>

inherit NPC;
inherit F_VENDOR;



void create()
{
            set_name("铁匠", ({ "blacksmith" }) );
            set("long","修破烂的。如果你的道具破损了。那么就尽管来找他吧。\n");

                set("age", 14);
                set("attitude", "friendly");

                set("max_gin", 2000);
                set("max_kee", 3000);
                set("max_sen", 1000);

                set("str", 33);
                set("cor", 40);
                set("spi", 40);
                set("int", 60);
        set("vendor_goods",({
                   "/d/city/obj/changjian",
                   "/d/city/obj/hammer",
                   "/d/city2/obj/tudao",
		"/d/city/obj/dagger",
                  "/d/xingxiu/obj/tiegun",
                  "/d/city/obj/gangdao",
        }));
        set("force",800);
        set("max_force",800);

                set("combat_exp", 1000);
          
                setup();
                carry_object("/clone/misc/cloth");
                       
}


void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
