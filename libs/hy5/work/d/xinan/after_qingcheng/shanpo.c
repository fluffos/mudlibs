//writen by lnwm on 97/07/14
//shanpo.c
//写这个地方，累死我了，呜呜。。。。。。。。。。。

#include <ansi.h>
#include <skill.h>

inherit ROOM;


void create()
{
    set("short", "小山坡");
    set("long", @LONG
你弯过山坳，眼前出现了一座小小的山坡，山坡背依群山，朝南向阳，在山坡
上有一座小小的茅屋。用细细的青竹一棵一棵围成四壁，以茅草铺顶，简陋但十分
干净整洁。茅屋正面是小小的柴扉，柴扉两侧开着两个小小的窗户。
LONG
        );
    set("exits", ([ 
        "south"     :       __DIR__ "gudi",
        "enter"     :       __DIR__ "maowu",
    ]));
    set("outdoors","lnwm");
    setup();
}

