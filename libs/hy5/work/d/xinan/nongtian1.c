#include <room.h>
inherit ROOM;


void create()
{
        set("short", "农田");
        set("long", @LONG
这里是群山环抱的一块土地，当地人称其为“坝子”，就是山间平地，谷地
的意思。大部分老百姓都聚居在一块块分散的“坝子”上。这里土地肥沃，水源
充分，地势平坦适宜耕种。东边是茂密的原始森林，看上去阴森森的；西面就快
到大理国的国都了。
    路边水田里有许多人在忙碌。
LONG
        );
        set("exits", ([
                "west"     : __DIR__"erhai",
                "east"     : __DIR__"milin1",

        ]));
        set("outdoors","xinan");
	set("objects",([
		__DIR__"npc/cunmin" : 2,
		]) );
        setup();
}
/*
int valid_leave( object me,string dir)
{
// object ob;
    if( dir == "south")
    {
        tell_object(me,"宝宝贝贝笑道：呵呵，南去就是青城山了，现在还没有做好呢！\n");
        return notify_fail("你只得收住脚\n");
    }
    return ::valid_leave(me,dir);
}
*/
