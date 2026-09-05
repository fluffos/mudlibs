//neizhai-zhengting.c -- 内宅正厅
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", HIC"内宅正厅"NOR);
  set("long", @LONG
这里是内宅正厅，王爷、王妃的日常起居都在这里。房间里被打扫得
干干净净，大红的地毯上绣着蒙古常见吉祥纹饰。房子的东南西北四面墙
上，都有挂着挂毯。最奇的是，每面墙的中间，都镶嵌了一块六横六纵、
精铁铸就的幻方(magic square)，连屋顶正中的天花上也镶嵌了一块，据
说这东西除了可以占卜天象，还可以辟邪镇妖。

LONG
  );

	set("item_desc", ([
		"magic square" : "由于你数术不精，还解不出这个幻方。\n",
	]));

  set("exits", ([     
      "south" : __DIR__"neizhai-qianyuan",   
      "north" : __DIR__"neizhai-houyuan", 
      "east" : __DIR__"wofang-e",
      "west" : __DIR__"wofang-w",
  ]));

	set("objects", ([
		__DIR__"npc/shinv" : 2,
	]));
  
  setup();
  replace_program(ROOM);
}
