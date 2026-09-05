//Create by whuan@pkuxkx
//铁掌帮
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这是一片树林，你隐隐看到一条出路，但是你走来走去，发现又回到了原地，你
不由得慌乱了起来。 
LONG    );
        set("exits", ([ 
  "northup" : __DIR__"wxiaolu1",
  "north" : __FILE__,  	
  "south" : __DIR__"wshulin5",
  "west" : __FILE__,
  "east" : __FILE__,			
]));

        set("no_clean_up", 0);
        set("outdoors", "tiezhang");

        setup();
        replace_program(ROOM);
}