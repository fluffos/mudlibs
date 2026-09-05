//yibinguan.c -- 宜宾馆
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"宜宾馆"NOR);
  set("long", @LONG
这里是汝阳王府的宜宾馆，汝阳王平日应酬颇多，也喜好结交三山五
岳的各色人等，遇到愿意投效的，王爷一般都把他们请到宜宾馆招待，以
备不时之需。

LONG
  );
  
	set("sleep_room",1);

  set("exits", ([     
      "south" : __DIR__"zhishichu",   
      "north" : __DIR__"shuzhai", 
      "east" : __DIR__"zoulang-w2",

  ]));

  setup();
  replace_program(ROOM);
}
