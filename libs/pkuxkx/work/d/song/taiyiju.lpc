// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "太医局");
	set("long", @LONG
这里是太医局，几个医官正在研究着什么。墙上挂着一张经络图(tu)。
LONG
	);
	set("item_desc", ([
		"tu" : "这是一张经络图，你可以参照修炼内功。\n", 
	    ]));
	set("exits", ([
		"northwest" : "/d/hangzhou/bazi",
		
	]));
	set("objects", ([
          __DIR__"npc/taiyi1" : 1,
		__DIR__"npc/taiyi2" : 1,
        ])); 
	set("at_hangzhou",1);
	setup();
}

int get_xiulian_bonus(object me)
{
    if (member_array(DASONG_D->get_my_pin(me),({1,2,3}))!=-1)
    return 110;
	if (DASONG_D->get_my_pin(me)==4)
    return 108;
	if (DASONG_D->get_my_pin(me)==5)
    return 105;
	if (DASONG_D->get_my_pin(me)==6)
	return 103;
	if (DASONG_D->get_my_pin(me)==7)
	return 102;
	else
	return 100;
}
string get_xiulian_bonus_desc(object me)
{
	if (get_xiulian_bonus(me)>100)
	{
		return "$N对照着墙上的经络图修炼内功，事半功倍。\n";
	}
}
