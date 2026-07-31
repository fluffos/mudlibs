// work.c
//
inherit ROOM;
void create()
{
        set("short", "矿石商店");
        set("long", @LONG
这是一间矿石商店，雪亭镇北边新开发了一个矿场，所以这里
货源还是很充足的。你可以在这里选购矿石然后去冶炼成金属成品；
墙上挂着一个牌子（Sign），东边就是雪亭镇的街道。
LONG
);
       set("no_beg",1);
       set("no_sleep_room",1);
       set("exits", ([ /* sizeof() == 1 */
	"east" : __DIR__"street02",
]));
	        set("objects",([
	__DIR__"npc/kuangshiboss" : 1,
]));
        set("item_desc", ([
                "sign": @TEXT
这里出售各种常见的矿石。
TEXT
        ]) );
    set("no_fight", 1);
    set("no_magic", 1);
    setup();
}