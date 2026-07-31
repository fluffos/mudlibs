inherit ROOM;
void create()
{  
     set("short", "模拟实战室");
     set("long", @LONG
这里是军校学生训练的地方。有几个练功用机器人摆在那里，有几个弟子手持
兵器与练功人互相拆招。
LONG );
        set("exits", ([
                "north" : __DIR__"wuchang",
                "south" : __DIR__"lian2",
                "east"  : __DIR__"lian3",
                "west"  : __DIR__"lian4",
        ]));
           set("objects",([
//                __DIR__"npc/lgren" : 5,
        ]));
//      set("no_clean_up", 0);
        set("outdoors", "fenghuang");
        setup();
        replace_program(ROOM);
}

