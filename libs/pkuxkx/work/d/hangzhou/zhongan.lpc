// Room: /hangzhou/beidajie1.c
// hubo 2008/4/19
// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
int broadcast()
{
	object room;
	mixed * names;
	names=values(query("exits"));
	for (int i=0;i<sizeof(names);i++)
		if (room=load_object(names[i]))
			if (room->isroom())
				tell_room(room,this_object()->query("short")+"方向响起了连续的掌声，似乎热闹非常。\n");
	remove_call_out("broadcast");		
	call_out("broadcast",300);
	return 1;
}
void create()
{
		set("short", "众安桥");
		set("long", @LONG
这里是众安桥，坐落在临安城的中轴线上。
LONG);
        set("outdoors", "hangzhou");
        set("exits", ([
                "west" : __DIR__"dongdajie3",
                "east" : __DIR__"dongdajie1",
                //"west" : __DIR__"xidajie1",
                //"north" : __DIR__"beidajie1",        
]));
		set("objects", ([
		__DIR__"npc/maiyi" : 1,
        ])); 
		setup();
		call_out("broadcast",1);
}

