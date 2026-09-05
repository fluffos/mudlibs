//weishiying-e.c -- 卫士营（东）
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"卫士营"NOR);
  set("long", @LONG
汝阳王是朝廷重臣，曾经出生入死，为朝廷立下汗马功劳，现在又正
与江湖人士周旋，王爷的安全显得尤为重要。当今圣上特别恩准调拨两营
精勇卫士，就住在王府，随时为王爷护驾。这里就住着其中的一营。
LONG
  );

  set("exits", ([     
      "southeast" : __DIR__"jiaomen-e",   
      "west" : __DIR__"mengang",
  ]));

	set("objects", ([
		__DIR__"npc/weishi" : 4,
	]));
	
  set("outdoors", "luoyang");
  setup();
}

int valid_leave(object me, string dir)
{
	object *inv;
  int i;
		
	if ( objectp(present("weishi", environment(me))) && dir == "west" )
	{
	  inv = all_inventory(me);
    for(i=sizeof(inv)-1; i>=0; i--)
    	if(inv[i]->query("weapon_prop") && inv[i]->query("skill_type") && inv[i]->query("equipped"))
				return notify_fail("王府卫士伸手拦住了你：“什么人？胆敢私带兵刃，擅闯王府！？”\n\n");
	}	
	return ::valid_leave(me, dir);
}

