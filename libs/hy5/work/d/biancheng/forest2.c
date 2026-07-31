 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "密林");
        set("long", @LONG
密林里一片漆黑，绝无树叶触擦的声音，也绝无夏夜的那种半明半昧的清光。
高大的杈丫狰狞张舞。枯萎丛杂的矮树在林边隙地上瑟瑟作声。长大的野草在寒风
中鳗鲡似地蠕蠕游动。蓁莽屈曲招展，有如伸出了长臂，张爪攫人。
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"forest1",
                "south":        __DIR__"forest3",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1050);
        set("coor/y",30);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
