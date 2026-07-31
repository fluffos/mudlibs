 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "书房");
        set("long", @LONG
书房是老伯的禁地，在这里无论说什么都不必怕别人听到。不管你是不是老伯
的朋友，无论你多么孤苦穷困，只要你到了菊花园，老伯都会把你带到这儿来，听
你诉说你的问题。他喜欢成全别人，喜欢公正，憎恶一切不公正的事，就像是祈望
丰收的农人，憎恶蝗虫急于除害一样。
LONG
        );
        set("exits", ([ 
                "west" :   __DIR__"garden4",
                "north":        __DIR__"groom2",
        ]));
        set("objects", ([
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
