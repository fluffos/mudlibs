//neizhai-qianyuan.c -- 内宅前院
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", HIC"内宅前院"NOR);
  set("long", @LONG
这里是王府的内宅前院，院子里并排种着两丛洛阳盛产的牡丹，修剪
得十分整齐，那红的、白的硕大的花朵，在绿叶的衬托下显得分外娇艳。
院子的角落里有一口大水缸(jar)，蓄满了水，据说王府以前曾经失过火
，这里的水是随时准备灭火用的。
LONG
  );

	set("item_desc", ([
		"jar" : "一口存水用的大水缸。\n",
	]));
	
  set("exits", ([     
      "south" : __DIR__"dongyuan-keting",   
      "north" : __DIR__"neizhai-zhengting", 
      "east" : __DIR__"shanshichu",
      "west" : __DIR__"canglin",
  ]));
  
  set("objects", ([
		__DIR__"npc/zongguan_neizhai" : 1,
	]));

  set("outdoors", "luoyang");
  setup();
}

int valid_leave(object me, string dir)
{
	object cloth;
	cloth = me->query_temp("armor/cloth");
		
	if ( objectp(present("zong guan", environment(me))) && dir == "north" )
	{
		if ( objectp(cloth) && cloth->query("id") == "puren fu" )
			return ::valid_leave(me, dir);
		else
			return notify_fail("总管太监一把拦住了你：“后面是王府内宅，住的都是汝阳王的家眷，您可不能乱闯啊！”\n\n");
	}	
	return ::valid_leave(me, dir);
}
