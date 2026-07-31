// Room: dong1
inherit ROOM;
#include <room.h>

void create()
{
	set("short", "山隙中");
	set("long", @LONG
这里阴森黝暗，伸手不见五指，又极潮湿，仅容一人通过。
向前方望去，却不知有多深远。
LONG
        );

	set("exits", ([ /* sizeof() == 2 */
		"eastup" : __DIR__"dong0",
		"west" : __DIR__"gu",
 
	]));
         
	setup();

}
  
void init()
{
	add_action("do_go","go");

}

int do_go()
{
	if(random(3)){
		this_player()->move(this_object());
		return 1;
	}

}
