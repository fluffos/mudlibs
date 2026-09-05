inherit ROOM;
void create()
{
        set("short", "小市场");
        set("long", @LONG
    这里是村里最繁华的地方，南腔北调的人们在谈生意。
LONG
        );
        set("outdoors", "city");
        set("exits", ([
                "north" : __DIR__"kedian",
                "south" : __DIR__"dangpu",
                "west" : __DIR__"ximen",
                "east" : __DIR__"dongmen",
                "southeast" : __DIR__"qianzhuang", 
                "northeast"  :  __DIR__"zuixianlou",       
               "southwest"  :__DIR__"wumiao",]));
        set("objects", ([
             "/d/migong/xiaocun1/npc/yang" : 1,
        ]));
                  
                    
             setup();
        replace_program(ROOM);
}

