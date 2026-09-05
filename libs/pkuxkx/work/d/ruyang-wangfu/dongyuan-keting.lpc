//dongyuan-keting.c -- 东院客厅
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"东院客厅"NOR);
  set("long", @LONG
这里是王府东院的客厅，两张金丝楠木的交椅摆在正中，几张圆凳分
列在两侧，四周的墙上高挂帘帐，屋内门口两侧，各立着一只近一人高的
青花龙纹大瓶，十分抢眼，据说这是先皇御赐的。交椅后面立着一道纯金
打造的屏风，客厅与内宅由此分割开来。普通的客人，不能轻易越屏风一
步。

LONG
  );

  set("exits", ([     
      "south" : __DIR__"dongyuan-menfang",   
      "north" : __DIR__"neizhai-qianyuan", 
      "west" : __DIR__"zoulang-e2",
  ]));

//  set("outdoors", "luoyang");
  setup();
  replace_program(ROOM);
}
