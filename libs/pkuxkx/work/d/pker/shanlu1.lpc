//Made by goodtaste
//wanluntai.c

inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
一条弯弯曲曲的山路
LONG
        );
        set("outdoors", "pker");
        set("exits", ([
                "south" : __DIR__"shanlu2",
               "north" : "/adm/npc/shanmen",
                ]));
          set("objects", ([
         __DIR__"npc/jiaofu" : 1,
           ]));
        setup();
        //replace_program(ROOM);
}

void init()
{
  this_player()->set_temp("xia",1);
}


