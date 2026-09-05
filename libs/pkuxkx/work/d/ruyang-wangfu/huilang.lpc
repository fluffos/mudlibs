//huilang.c -- 回廊 
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"回廊"NOR);
  set("long", @LONG
这里是个回廊，东侧连着王府的后院，西侧连着燕怡堂。回廊的两侧
种着几颗青竹，微风吹过，竹叶摇动，竹影婆娑，隐隐约约还能听到燕怡
堂姑娘们的窃窃私语。
LONG
  );

  set("exits", ([     
      "east" : __DIR__"neizhai-houyuan",
      "west" : __DIR__"yanyitang",
  ]));

  set("outdoors", "luoyang");
  setup();
  replace_program(ROOM);
}
