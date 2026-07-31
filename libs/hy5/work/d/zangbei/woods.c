 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "白杨树林");
        set("long", @LONG
无边无际的荒原上一排傲然地聳立，象哨兵似的樹木，不很浓密，是西北最常
见的白杨树林。筆直的乾，筆直的枝。乾通常是丈把高，象是加以人工似的，一丈
以內，絕無旁枝；丫枝一律向上，而且緊緊靠攏，也象是加以人工似的，成為一束，
絕無橫斜逸出。
LONG
        );
        set("exits", ([ 
                "northeast" : __DIR__"wild2",
                "west" : __DIR__"woods2",
                "southeast":    __DIR__"forest1",
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
