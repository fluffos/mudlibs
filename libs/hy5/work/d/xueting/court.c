// Room: /d/snow/court.c
inherit ROOM;
void create()
{
        set("short", "乡校");
        set("long", @LONG
这里是雪亭镇的乡校，平常镇民对官府的施政有什么不满的可
以到这里来向校老申诉，所谓的校老就是地方上有德行与声望的老
人，今年担任校老的是开磨坊的杨老爹，但是他最近身体不是很好，
并不常到乡校里来，往南是街道，北边是一间衙堂，当县里派师爷
来这里断事就会在那里开堂。
LONG
        );
        set("outdoors","xueting");
        set("exits", ([ /* sizeof() == 1 */
                "south" : __DIR__"wstreet2",
        ]));
        set("objects", ([
        __DIR__"npc/oldman": 1
        ]));
        setup();
}
