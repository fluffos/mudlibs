// /d/kunming/xiangfan.c
// netkill /98/9/11/


#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",  "厢房" );
        set("long", @LONG
一间不大的厢房，收拾的十分干净，看来是家人平是起居之用，
一扇小窗户透进些光线了，显的十分的舒心。
LONG
        );
          
        set("exits", ([
		"west"   :__DIR__"dongzoulang1",
	
        ]));
	set("sleep_room",1);

        setup();
	replace_program(ROOM);	       
}
	  		