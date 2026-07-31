// Room: /city/pomiao.c	
#include <room.h> 
inherit ROOM; 
	
void create() 
{ 
	set("short", "土地庙"); 
	set("long", @LONG 
这是一间破破烂烂的土地庙，庙里破败不堪，土地神像推在一旁，梁上地 
下也布满了灰尘。一看就知道已经很久没有人来清理过了。正中放着个大香案， 
上面零乱地扔着几根吃剩下来的鸡骨头。也许正是因为隐蔽的原因吧，据说丐 
帮江南分舵就被设在此处。 
LONG 
	); 
	set("valid_startroom", 1); 
	set("exits", ([ 
		"west"  : "/d/gaibang/shoushe", 
		"east"  : "/d/gaibang/sheyuan", 
		"south" : __DIR__"ml4",
		"enter" : __DIR__"gbandao",		      
	])); 
	set("objects", ([ 
		CLASS_D("gaibang") + "/lu" : 1, 
		CLASS_D("gaibang") + "/peng" : 1,
		CLASS_D("gaibang") + "/xi" : 1, 
	])); 
	create_door("enter", "小门", "out", DOOR_CLOSED); 
	setup(); 
} 

int valid_leave(object me, string dir) 
{ 
	object ob; 
	mapping myfam; 
       
	myfam = me->query("family"); 
       
	if ((! mapp(myfam) || myfam["family_name"] != "丐帮") && 
	    (dir == "west" || dir == "east") && 
	    objectp(ob = present("lu youjiao", environment(me))) && 
	    living(ob)) 
	{ 
		return notify_fail("鲁有脚拦住你说：此处乃" 
				   "本帮禁地，请止步。\n"); 
	} 
       
	return ::valid_leave(me, dir); 
} 

