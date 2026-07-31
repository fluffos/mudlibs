// Room: /d/jingzhou/shop.c
//980829 /congw
inherit ROOM;

void create()
{
        set("short", "废园");
	set("long", @LONG
你看到四周芳草萋萋，这里是一座废弃了多年的园子，到处都是老鼠和灰尘，使人
不由得黯然神伤。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dongdajie2",
]));
        set("no_clean_up", 0);

       setup();
        replace_program(ROOM);
}
 
