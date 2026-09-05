//make by chenchen
inherit ROOM;

void create()
{
        set("short", "官道");
set("occupied",1);
        set("long", @LONG
这是一个村子，稀稀落落的分布着几十间土坯泥房，村中
中人家不多，由于蒙古兵还没打到这里,这里还保持着往日的宁静.
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"mroad3",
  "south" : __DIR__"mroad1",
  "east"  : __DIR__"mhouse",
]));
        set("no_clean_up", 0);
        set("outdoors", "xxx");

        setup();
        replace_program(ROOM);
}


