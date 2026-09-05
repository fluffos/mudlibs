inherit ROOM;
#include <ansi.h>
#include "city_level.h"

void create()
{
        set("short", "尚书省");
        set("long", @LONG
这里是尚书省，里面是吏、户、礼、兵、刑、工等六部官员和尚书省长官
们的办公场所，西面是尚书省的正门敬时楼，东南角是碑林。
LONG        );
        
        set("exits", ([
                "west" : __DIR__"jingshilou",
                "southup" : __DIR__"zoulang1",
                "northup" : __DIR__"zoulang2",
                "southeast" : __DIR__"beilin"
        ]));

        set("objects", ([
          __DIR__"npc/jinwu-6": 2,
        ]));
        
        set("locate_level",1);
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}

int valid_leave(object me,string dir)
{
  object jw; 
  
	jw=present("jin wu", environment(me));
	
	if ( check_obj_enter(me, dir) )
	{
    if (dir=="east" && me->query_condition("cakiller") && objectp(jw))
      return notify_fail("你已被全城通缉，快去避避风头！\n");
    else
		  return ::valid_leave(me, dir);
	}
	else
	  return notify_fail("尚书省重地，无事免入！\n");
}