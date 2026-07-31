// Write By Yanyang@SJ 2001.9.27
// NPC : /d/changan/npc/daobazhang.c

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("刀疤张", ({ "daoba zhang", "daoba", "zhang"}) );
        set("gender", "男性" );
        set("age", 35);
        set("per", 14);
        set("unique", 1);
        set("long","他脸上一道深深的刀疤，大家都叫他刀疤张。\n");
        set("combat_exp", 10000);
        set("vendor_goods", ({
                (["name":BINGQI_D("sword/sword"),"number":10]),
                (["name":BINGQI_D("blade/blade"),"number":10]),
                (["name":BINGQI_D("hammer/chui"),"number":10]),
                (["name":BINGQI_D("club/gun"),"number":10]),
                (["name":BINGQI_D("staff/gangzhang"),"number":10]),
                (["name":BINGQI_D("whip/whip"),"number":10]),
                (["name":BINGQI_D("hook"),"number":10]),
                (["name":BINGQI_D("stick"),"number":10]),
                (["name":BINGQI_D("axe"),"number":10]),
        }));
        set("chat_chance", 5);
        set("chat_msg", ({
                "刀疤张深深的叹了口气。\n",
                "刀疤张看了看自己，自言自语的不知道说些什么！\n",
        }) );
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}

void init()
{
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}