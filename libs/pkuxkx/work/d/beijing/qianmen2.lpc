// Room: /d/beijing/qianmen2.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"正阳门外大街"NOR);
        set("long",
CYN"大街上挤满了卖杂货的摊贩，商铺一家接一家，招牌旗帜几乎占据了
整条街一半的空间，但东边有一条胡同。\n"NOR
        );
        set("outdoors", "beijing");

        set("exits", ([
                "west" : __DIR__"fenshen",
                "south": __DIR__"qianmen1",
                "east" : __DIR__"picai",
                "north": __DIR__"zhengyangdajie",

        ]));
	set("no_clean_up", 0);
//	set("cost", 2);
        setup();
        replace_program(ROOM);
}
