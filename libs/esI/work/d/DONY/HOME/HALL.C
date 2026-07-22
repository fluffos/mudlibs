#include <mudlib.h>
inherit ROOM;

void create()
{
	::create();
        set_short( "transport", "传送站" );
	set_long(
                "this is a transport room\n",
                "这是一个可通往三大陆的传送站\n"
                "    往南是宁丹的工作室，往北则是各个工会的传送室\n\n" 
	);
	set("light",1);

	set( "exits", ([
		"eland" : "/d/eastland/8,5.east",
		"dland": "/d/deathland/city/c1",
		"mland": "/d/noden/14,9.noden",
                "south": "/u/d/dony/home/workroom.c",
                "north": "/u/d/dony/home/trans.c",
               "beggar":"/d/eastland/beggar/area/cross.c",
               "legend":"/d/eastland/legend/lake/mountain0",
               "story":"/u/d/dony/story/wiz/city/southgate"
                  ]) );
     reset();
}

