 inherit ROOM;
void create()
{
        set("short", "洞内");
        set("long", @LONG
洞里黑暗潮湿，在北面有一丝阳光照进来。它给了你一线
希望。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hole4",
  "south" : __DIR__"hole",
]));
        set("coor/x",-20);
        set("coor/y",2050);
        set("coor/z",80);
        setup();
        replace_program(ROOM);
}   
