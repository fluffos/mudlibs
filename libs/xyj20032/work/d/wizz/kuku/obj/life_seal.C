// Created by kuku@SJSH  2004.1.5  智慧符咒

inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("生命符咒", ({"life seal","seal"}));
        set("unit", "张" );
        set_weight(10);
        set("long",@long
一张奇怪的灵符，上面乱七八糟的画了些图形，不知道有什么用。
long );
        set("no_sell","掌柜的摇摇头说：这宝贝小店不敢收。\n");
        set("no_put",1);
        set("life_seal",1);
        setup();
}