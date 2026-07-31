//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "厨房");
        set("long", @LONG
一张长长的灶台上放了五六口铁锅,每口锅面前都有一
位大师傅,他们正在汗流浃背地炒着菜。
LONG
        );

        set("exits", ([
                "west" : __DIR__"chenmapo",                
        ]));
        set("objects", ([
                __DIR__"npc/dashifu" : 3,
        ]));
      
        setup();
        replace_program(ROOM);
}

 
