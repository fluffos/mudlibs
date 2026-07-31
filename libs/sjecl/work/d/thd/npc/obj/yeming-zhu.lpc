// yeming-zhu.c
// Created by Numa 19990911

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"夜明珠"NOR,({ "yeming zhu","zhu" }));
	set_weight(100);
	if( clonep() )
                set_default_object(__FILE__);
        else
        {
        	set("unit","颗");
        	set("long","这是一个闪闪发光的夜明珠，一看就知道是无价之宝。");
        	set("value",0);
        }
	setup();
}
