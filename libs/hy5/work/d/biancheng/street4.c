 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "南街尽头");
        set("long", @LONG
向南的小街很快就到了尽头，再往前又是荒原，无边无际的荒原，寒风卷起满
天黄沙。一朵残菊在风沙中打着滚，既不知是从哪里吹来的，也不知要被吹到哪里
去。世人岂非也都正如这瓣残菊一样，又有谁能预知自己的命运？
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"zahuopu",
                "north": __DIR__"street3",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
