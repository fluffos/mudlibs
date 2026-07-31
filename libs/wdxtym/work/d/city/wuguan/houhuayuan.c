//houhuayuan.c 后花园

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG"后花园"NOR);
        set("long", @LONG
这是是武馆的后花园，左侧方有个大池塘，池水甚清，还有一双白鹅，在
水里来回嬉戏。池旁有几块太湖石，石边放着一张小几，小几上放着一个香炉，
香炉中留着三柱残香，好象刚有人在此停留。
LONG
        );       
 
	set("outdoors","武馆");
	set("no_fight",1);
        set("exits", ([
               "south" : __DIR__"xiaojing1",
               "northeast" : __DIR__"citang",
        ]));
        
        set("objects", ([
        ]));
        setup();
}
