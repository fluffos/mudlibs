// pingxinshi.c

inherit ROOM;

void create()
{
        set("short", "平心石");
        set("long", @LONG
百尺峡尽头，两边岩崖势欲相合，中夹两块巨石，前边一块刻有“惊
心石”三字。过此回望，石上刻有“平心石”三字，示人们以险境已经过
去，已进入平安之途了。顿时心情至此一舒。
LONG );
        set("exits", ([ /* sizeof() == 2 */
            "westdown" : __DIR__"baichi",
            "eastup"   : __DIR__"laojun",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
