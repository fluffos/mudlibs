// 熊洞
// by steel 
#include "ansi.h"
inherit ROOM;

void create()
{
	set("short", "熊洞");
	set("long", @LONG
        你走进了一个山洞,洞里比外面暖和多了。但是有一股浓浓的腥
味。你抬头一看，一头硕大无比的白熊正呆呆的望着你。    
LONG
	);
	
	set("exits", ([
                "northeast" :__DIR__"hole10", 
               ]));
        set("objects",([
               __DIR__"npc/bear":1,
             ]) );   
	setup();
        replace_program(ROOM);
}

