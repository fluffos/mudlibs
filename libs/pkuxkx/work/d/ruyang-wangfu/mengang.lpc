//mengang.c -- 门岗
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"门岗"NOR);
  set("long", @LONG
进了王府大门，气氛陡然紧张起来，汝阳王府实际上是外松内紧，王
府门外，看不到一个兵丁，但府门内却是戒备森严，这里就是一道由王府
卫士把守的门岗。
LONG
  );

  set("exits", ([     
      "north" : __DIR__"huishiting", 
      "south" : __DIR__"wangfu-fumen",   
      "east" : __DIR__"weishiying-e",
      "west" : __DIR__"weishiying-w",
  ]));

	set("objects", ([
		__DIR__"npc/weishi-zhang" : 1,
		__DIR__"npc/weishi" : 4,
	]));

  set("outdoors", "luoyang");
  setup();
}

int valid_leave(object me, string dir)
{
	object *inv;
  int i;
		
	if ( objectp(present("weishi", environment(me))) && dir == "north" )
	{
	  inv = all_inventory(me);
    for(i=sizeof(inv)-1; i>=0; i--)
    	if(inv[i]->query("weapon_prop") && inv[i]->query("skill_type") && inv[i]->query("equipped"))
				return notify_fail("王府卫士伸手拦住了你：“什么人？胆敢私带兵刃，擅闯王府！？”\n\n");
	}	
	return ::valid_leave(me, dir);
}
