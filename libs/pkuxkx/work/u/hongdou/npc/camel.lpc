// camel.c
#include <ansi.h>
inherit NPC;
//inherit F_MASTER;
//inherit F_UNIQUE;

void create()
{
        seteuid(getuid());
        set_name("毫毛", ({ "hao mao","mao mao","mao","camel" }) );
        set("title", MAG "铁公鸡" NOR);
        set("gender", "男性" );
        set("age", 53);
        set("long", "一个慈眉善目、道貌岸然的闲人。\n");
        set("attitude", "peaceful");
        set("str", 25);
        set("con", 25);
        set("int", 25);
        set("dex", 25);
        set("max_qi", 150);
        set("max_jing", 100);
        set("neili", 120);
        set("max_neili", 120);
        set("jiali", 110);
        set("shen_type", 0);
        set("startroom","/d/city/guangchang");
        set("thief", 0);
        set("combat_exp", 0);
        set("chat_chance", 20);
        set("chat_msg", ({
                "毫毛说道: 老子功夫天下第一，谁敢跟我叫板，算他倒霉。哼！！！\n",
                "毫毛懒洋洋地打了个哈欠。\n",
        "毫毛看看四周没人，拉开裤子在墙边撒了泡尿！！！ \n",
	"毫毛高声喊道：“相当初，大爷我在馆子里都不要钱，何况吃你几个烂西瓜。\n",
                (: random_move :)
        }) );
        setup();
        carry_object("/clone/weapon/cloth");
        
}
/*
void init()
{
        object ob;
        ::init();
        
        }
}
*/