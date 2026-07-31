// zjb /2002/3/15/
inherit ROOM;

void create()
{
        set("short", "秘道");
        set("long", @LONG
这个秘道 四璧出奇地没有长满苔菌一类最喜湿暗的植物，
空气闷浊得可令人窒息，如果不会武功的人进来,肯定因空
气不够而窒息死亡!
LONG
        );

        set("exits", ([
                "east" : __DIR__"tongdao4", 
            "south" : __DIR__"tongdao3", 
      "west" : __DIR__"tongdao2", 
    "north" : __DIR__"tongdao3",
                         ]));

        setup();
        replace_program(ROOM);
}


