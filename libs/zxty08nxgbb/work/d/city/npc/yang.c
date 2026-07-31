// yang.c 杨老板 
inherit F_DEALER;
inherit BHNPC;
 string query_save_file() { return DATA_DIR + "npc/yangyongfu"; }

string ask_huolei();
void create()
{

        set_name("杨永福", ({ "Yang yongfu", "yang" }));
        set("title", "杂货铺老板");
        this_object()->init_bhnpc();
        set("area_name","杂货店");
        set("area_id","zahuodian");
        set("area_file","/d/city/zahuopu");
        set("kaifa",38);
        set("jizhi",46);
        set("ziyuan","黄金");
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 45);
        set("long",
                "杨老板是土生土长的扬州人，做了几十年的小买卖。\n");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);
        set("combat_exp", 40000);
        set("attitude", "friendly");
            set("inquiry", ([ 
        "火雷弹":(:ask_huolei:), 
        "huolei":(:ask_huolei:), 
            ]) ); 
        set("vendor_goods", ({
                __DIR__"obj/mabudai",
                __DIR__"obj/beixin",
                __DIR__"obj/sleepbag",
                __DIR__"obj/toukui",
                __DIR__"obj/cycle",
                __DIR__"obj/surcoat",
                __DIR__"obj/shield",
                __DIR__"obj/huwan",
                __DIR__"obj/zhitao",
                __DIR__"obj/huyao",
                __DIR__"obj/caoxie",
                __DIR__"obj/pixue",
                __DIR__"obj/shoutao",
                __DIR__"obj/tieshou",
//"/d/obj/quest/tu",
 "/d/city/obj/tiechan",
 "/clone/misc/chutou",
"/clone/misc/yaodai",
"/clone/ling",
        }));
        
        setup();
        carry_object("/clone/misc/changpao")->wear();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
string ask_huolei()
{
     object ob;
     if (this_player()->query("zjb_money") < 10)
     return "火雷弹这玩意可是好东西，没十枚星空币打死我也不卖！";

     ob = new("/d/zjb/obj/huolei");   
     ob->move(this_player()); ;
     this_player()->add("zjb_money",-10);
     return "欢迎您的光临，这钱我已经直接送钱庄帮你转过来了!";
}
#include <die.h>

