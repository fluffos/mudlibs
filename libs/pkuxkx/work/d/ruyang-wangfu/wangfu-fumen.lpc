//wangfu-fumen.c -- 汝阳王府府门
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", BBLU HIY"=汝阳王府="NOR HIC" 府门"NOR);
  set("long", 
"你正站在汝阳王府的府门前，迎面一排四颗粗大的楠木柱子，支撑着
府门上宽大的房檐，房檐上盖满金黄色的琉璃瓦。门前两只高大的石狮，
一动不动地立在府门两侧，威严地注视着每一个经过府门的人。两扇朱红
的大门上镶嵌着横五纵九共四十五颗黄铜门丁，闪闪发亮。正面门楣上高
挂匾额——
                   ※==※==※==※==※==※
                   ※"BBLU+HIY"  汝  阳  王  府  "NOR"※ 
                   ※==※==※==※==※==※
                     
四个镏金大字，端端正正地书写在匾额中央。汝阳王虽是朝中重臣，但现
在并不得皇上宠信，登门造访的人平时就比较少，眼下王府门前更是冷冷
清清。两个门房呆呆地立在大门两侧，看起来没精打采的。\n"
  );

  set("exits", ([     
      "south" : "/d/luoyang/hutong3",   
      "north" : __DIR__"mengang", 
      "east" : __DIR__"weiqiang-e",
      "west" : __DIR__"weiqiang-w",
  ]));

	set("objects", ([
		__DIR__"npc/menfang" : 2,
	]));

  set("outdoors", "luoyang");
  setup();
  replace_program(ROOM);
}
