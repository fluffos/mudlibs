// Room: /hangzhou/beidajie1.c
// hubo 2008/4/19
// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include "to_song.h"
void create()
{
	set("short", "东大街");
	set("long", @LONG
这是一条贯穿东西从东青门通往钱塘门的临安城主要干道。
LONG);
        set("outdoors", "hangzhou");
        set("exits", ([
                "east" : __DIR__"dongdajie3",
                "west" : __DIR__"fengbo",
                //"west" : __DIR__"xidajie1",
                "north" : __DIR__"yuewang",        
]));
          
	set("dirs_to_song",(["northwest":({"wuxue","西北","武学"}),]));
	set("common_entry",1);
	setup();
	make_entrance();
}

int do_northwest()
{
	object rm,me=this_player();
	if ((me->query("family/family_name")!="朝廷"||me->query("class")!="officer")&&!me->query("song/pro"))
	return 0;
	if (!rm=load_object("/d/song/wuxue"))
	return 0;
	message_vision("$N向着西北面的"+rm->query("short")+"走去。\n",me);
	tell_room(rm,me->name()+"走了过来。\n");
	me->move(rm);
	return 1;
}