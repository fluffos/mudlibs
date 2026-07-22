//changan city
// Cracked by 凌惊雪 1-3-2003

inherit ROOM;

void create ()
{
        set ("short", "云碧天");
        set ("long", @LONG
各地的名茶这里都有的卖。这里冲茶的水也是从枫叶泉专程汲来
的。这里冲茶的壶更是名贵的紫砂壶。这里冲茶的方法也是最讲究的。
每壶茶的第一杯是用来养壶的。所以这里冲出的茶都有一种纯厚的香
气。

LONG);

        set("exits", 
        ([ //sizeof() == 4
                "north" : __DIR__"congming1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/teawater" : 1,
        ]));
        set("outdoors", "luoyang");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


