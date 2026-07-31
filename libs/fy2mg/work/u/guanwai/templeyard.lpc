
inherit ROOM;

void create()
{
        set("short", "寺院");
        set("long", @LONG
壮丽的寺院，光线却十分阴森幽暗。数千只巨烛和用牛油作燃料的青铜
灯在风中闪动着神秘的火焰。高耸的寺墙上有无数的神龛，供奉着面目狰狞
的巨人七色像，在闪动的烛光中，更显得鬼秘可怖。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"dazhaotemple",
  "west" : __DIR__"tower",
  "north" : __DIR__"wallhole",
]));
        set("outdoors", "guanwai");
        setup();
        replace_program(ROOM);

}

