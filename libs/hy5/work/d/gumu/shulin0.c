// shulin0.c 树林
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "小树林");
        set("long", @LONG
走在林中，你只闻铮铮琴声，一股淡淡白烟，带着极甜的花香，
自密林深处传出。一群乳白色的蜜蜂在你身旁飞来飞去。只见一块石
碑(shibei)立在当眼ㄦ处。往东是一块空地。其它方向尽是茂密的树
林。
LONG
        );
        set("outdoors", "gumu");
        set("item_desc", ([
                "shibei" : 
"

                        终南古墓，
                        外人止步。

",
        ]));
        set("exits", ([
                "southup" : __DIR__"shulin1",
                "north" : __DIR__"shulin4",
                "west"  : __DIR__"shulin5",
                "east"  : __DIR__"shulin6",
        ]));

        setup();
        replace_program(ROOM);
}
