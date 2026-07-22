// smith.c
inherit BHNPC;
inherit F_DEALER;
//inherit F_VENDOR_SALE;
////inherit F_BVENDOR;
string query_save_file() { return DATA_DIR + "npc/Ìú½³"; }
void create()
{
        set_name("Ìú½³", ({ "tie jiang", "smith" }));
this_object()->init_bhnpc();
set("area_name","ÑïÖÝÌú½³ÆÌ");
set("area_file","/d/city/datiepu.c");
set("ziyuan","Ìú¿ó");
set("kaifa",20);
set("jizhi",25);
	set("title", "Ìú½³ÆÌÀÏ°å");
	set("shen_type", 1);
        set("gender", "ÄÐÐÔ" );
        set("age", 33);
        set("long", "Ìú½³ÕýÓÃÌúÇ¯¼Ð×¡Ò»¿éºìÈÈµÄÌú¿é·Å½øÂ¯ÖÐ¡£\n");
        set("combat_exp", 400);
	set("attitude", "friendly");
set("vendor_goods", ({
         "/d/city/obj/changjian",
              "/d/city2/obj/tudao",
           "/d/city/obj/dagger",
          "/d/xingxiu/obj/staff",
           "/d/xingxiu/obj/club",
     "/d/city/obj/gangdao",
              "/d/city/obj/gangaxe",
          "/d/obj/feidao",
          "/d/city/obj/whip",
        "/d/obj/feihuangshi",
           "/d/obj/tielianzi",
         }));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{        ::init();
     //add_action("do_vendor_list", "list");
       add_action("do_list", "list");
        add_action("do_buy", "buy");
}
#include <die.h>
