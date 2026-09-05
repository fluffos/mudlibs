//yangxinju.c
//by zoom
//2004.3.29

inherit ROOM;

void create()
{
        set("short", "养心居");
        set("long", @LONG
这间小室中充满了草药味，细看时发现墙角边有不少药箱，里面
装满了草药。小室正中是一张方桌，桌后坐了一位老者。
LONG );

	set("exits", ([
		       "south" : __DIR__"houtang",
		       ]));

	set("indoors", "train" );
        set("no_fight", 1);

    	set("objects", ([ 
		__DIR__ +"npc/doctor" : 1, 
    	]));

	set("no_clean_up", 1);
	setup();
}
