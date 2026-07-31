//houtang.c 后堂
inherit ROOM;
#include <ansi.h>
void create()
{
            set("short", HIW"后堂"NOR);
            set("long",@LONG
这是后堂，借客人在这里歇息，南方一排屏风遮住了视线，绕过屏风就是
一条密道直通大厅了。北面是一条长廊，直通往后花园。
LONG
    );
          
            set("exits",([
                "north": __DIR__"lang1",
                "south": __DIR__"dating",
            ]));

            set("objects",([
                 __DIR__"npc/xiaotong":1,
            ]));                    
            
            set("no_fight", 1);
            setup();
            replace_program(ROOM);
}
