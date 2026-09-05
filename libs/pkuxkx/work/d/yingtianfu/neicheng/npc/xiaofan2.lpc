//Zine

inherit NPC;
inherit F_DEALER;
#include <ansi.h>
#include "die.h"
void create()
{
        string name,*tmp,*pinying;
        string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        set("title", color[random(sizeof(color))]+"杂货铺老板"+NOR);
        set("shen_type", 1);

        set("str", 20);
        set("gender", "男性");
        set("age", random(20)+45);
        set("long",
                "他是这里的杂货铺老板，虽然生意不好，却一直在坚持。\n");
        set("combat_exp", 8000);
        set("attitude", "friendly");
        set("inquiry", ([
                
                "here" : "这里是应天府。\n",
                
        ]));
        set("sinan","yes");
        set("vendor_goods", ({
                "/d/murong/obj/yuer",
                "/d/murong/obj/yugou",
                "/d/jiangzhou/obj/sword",
                "/d/zhenjiang/npc/obj/zhi",
                "/d/zhenjiang/npc/obj/bi",
                "/d/zhenjiang/npc/obj/mo",
                "/d/zhenjiang/npc/obj/yan",
                "/d/xingxiu/npc/obj/case",
				__DIR__"obj/gongpin",
                    }));

        setup();
        
}



void init()
{
        
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

