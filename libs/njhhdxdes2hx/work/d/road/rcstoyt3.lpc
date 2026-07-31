#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short", "马鞍山");
	set("long", @LONG
登高远望，一片大好河山，凉风习习，实在是个好地方。
可是你现在可能没有心思欣赏这一切，因为最近这老虎出没。
LONG
	);
	set("exits", ([ 
  "westdown"  : __DIR__"rcstoyt2",
  "eastdown" : __DIR__"rcstoyt4",
]));
       set("objects", ([
                "/obj/npc/tiger" : 3,
 ]) );


	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

