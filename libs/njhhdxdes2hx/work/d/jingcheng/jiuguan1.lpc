#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"醉八仙酒家"NOR);
	set("long", @LONG
这是一家通宵开放的酒馆。这里不但供应本地的各种名酒，
你也可以买到来自西域或南洋的各种美酒。
LONG         
	);
	set("objects", ([ 
        __DIR__"npc/waiter3" : 1,
      ]));

	set("exits", ([ 
 "west" :__DIR__"baih1", 
 
	]));
	setup();
	replace_program(ROOM);
}

