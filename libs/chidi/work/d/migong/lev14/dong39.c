#include <room.h>
#include <ansi.h>
inherit ROOM;


void create()
{
		set("short", RED"熔岩洞"NOR);
	set("long", RED @LONG
    滚烫岩浆不断散发着热气，令人喘不过气来，一些前所
未见的巨大生物在这里走动着。正面的墙壁似乎有些松动。
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong04",
		"west" : __DIR__"dong40",
                	]));
	set("no_clean_up", 0);
	setup();
	}

void init()
{
add_action("do_break", "break");
}
int do_break(string arg)
{
      if(  arg == "wall" )
    { 
message_vision(
"$N深吸一口气，双掌同时推出。
只听碰的一声，洞壁被震出个大窟窿，路出一条路来\n", this_player());
            set("exits/enter", __DIR__"dong103");
          remove_call_out("close");
        call_out("close", 10, this_object());
    }
    else 
   {
        write("你要震碎什么?\n");
            }

     return 1;
}
void close(object room)
{
    message("vision","洞顶的石块稀里哗拉坍塌下来，又遮住了洞穴。\n", room);
    room->delete("exits/enter");
}