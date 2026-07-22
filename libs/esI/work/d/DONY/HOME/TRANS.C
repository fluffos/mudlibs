#include <mudlib.h>
inherit ROOM;

void create()
{
	::create();
        set_short( "transport", "传送站" );
	set_long(
                "this is a transport room\n",
                "这是一个可通往各个公会的传送站\n"
                "    往南则是通往三大陆的传送站\n\n"
	);
	set("light",1);

	set( "exits", ([
		"guard" : "/d/adventurer/hall/adv_guild",
		"scholar": "/d/scholar/scholar/scholar_guild",
                "monk": "/d/monk/guild/monk_guild",
                "knight": "/d/knight/fortress/knight_guild",
                "mage": "/d/mage/tower/mage_guild",
                "healer": "/d/healer/building/healer_guild",
                "thief":"/d/thief/hall/thief_guild", 
		"south" : "/u/d/dony/home/hall.c"
	]) );
     reset();
}

