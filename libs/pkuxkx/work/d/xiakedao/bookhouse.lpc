//书房
//by aiai for xiakedao
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "书房");
        set("long", @LONG

    书房小巧精致，打扫的纤尘不然。靠墙的书架上摆满了各类书籍，一张
红木书桌横在雕花窗前，旁边放了个绣塌。几本翻开的书放在书桌上，左手
边是一盏水晶灯，旁边是一个翠绿欲滴的翡翠花瓶，里面稀疏地插了几只白
色的山茶花。
LONG
        );
        set("exits", ([ 
//		"west" : __DIR__"jinghouse",
//		"south" : __DIR__"juhua",
	]));
        set("objects", ([
		__DIR__"obj/desk" : 1,
        ]) );

        setup();
}
void reset()
{
	object *inv;
	object desk, item;
	::reset();
	desk = present("desk", this_object());
        inv = all_inventory(desk);
        if( !sizeof(inv)) {
		item = new(__DIR__"obj/xkd_book");
		item->move(desk);
	}
}
