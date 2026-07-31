
inherit ROOM;

void create()
{
        set("short", "翠竹屋");
        set("long", @LONG
青青的软竹搭成小小的翠竹屋。屋中几乎所有的家具都是用青
竹编成的。屋中的竹几上放着一套名贵的紫砂茶具。铁雪山庄的男
女主人正在品茶下棋。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"front_yard",
  "north" : __DIR__"back_yard",
]));
       set("objects", ([
                __DIR__"npc/master" : 1,
                __DIR__"npc/master2" : 1,
                __DIR__"npc/girl" : 1,
        ]) );
        set("valid_startroom", 1);
        setup();
}

