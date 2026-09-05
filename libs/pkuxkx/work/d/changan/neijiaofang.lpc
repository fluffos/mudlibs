
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "内教坊");
        set("long", @LONG
这里是太常寺下辖的内教坊，里面常年有艺人排练各种曲艺节目，
里面也有博士负责钻研各种音乐技巧，旁边设置多个练习室供教坊内
的艺人研习音乐之用。
LONG        );
        
        set("exits", ([
                "north" : __DIR__"taichangsi",
                "west" : __DIR__"lianxishi-1",
                "east" : __DIR__"lianxishi-2",
                "south" : __DIR__"lianxishi-3",
                "southwest" : __DIR__"lianxishi-4",
                "southeast" : __DIR__"lianxishi-5",
                "northwest" : __DIR__"lianxishi-6",
                "northeast" : __DIR__"lianxishi-7",
        ]));
        
        set("locate_level",1);
        set("objects", ([
	        __DIR__"npc/fan-anji" : 1,
	        __DIR__"npc/jinwu-2": 1,
        ]));
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}

int valid_leave(object me,string dir)
{
	object env,item;
	mapping exits=query("exits");
	
	if ( dir=="north" )
	  return ::valid_leave(me, dir);

  if ( me->query_temp("changan/jf_time")>=time() )
  {
  	if(!(env=find_object(exits[dir])))
  		env=load_object(exits[dir]);
  	
  	foreach(item in deep_inventory(env))
  	{
  		if( userp(item) &&
  			  item->query_temp("changan/jf_time")>=time() )
  			return notify_fail("房间中已经有人在研习乐谱，请等对方使用完毕该房间以后再进去。\n");
  		
  		if( userp(item) &&
  			  item->query_temp("changan/jf_time")<time() )
  		{
  			item->move(this_object());
  			message_vision("$N将$n赶出了练习室。\n", me, item);
  		}
  	}
  }
  else
  	return notify_fail("你先向教坊使大人缴纳足额的财物以后才能选择一个无人的房间练习乐谱。\n");
  
  return ::valid_leave(me, dir);
}