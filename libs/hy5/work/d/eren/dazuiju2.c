 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "大嘴居后院");
        set("long", @LONG
后院三面是低低的土墙，墙上爬满藤蔓，角落里放着几个花盆，几朵火红的杜
鹃花正开的绚烂。院子里有一个练功的木人和一个武器架，架上胡乱搁着刀剑。一
个十多岁的少女正在练剑，眉目间流露着淡淡的哀愁。
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"dazuiju1",
        ]));
        set("objects", ([
                __DIR__"npc/pinggu": 1,
                __DIR__"npc/star_bunny": 1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
}   
