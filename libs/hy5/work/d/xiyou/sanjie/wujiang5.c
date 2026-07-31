// sanjie wujiang5.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "乌江边");
  set ("long", @LONG
	
		　　　＃＃＃＃＃
		　　　＃指路牌＃
		　　　＃＃＃＃＃
	
			三界岛
			　↑
		乌江边→你在此←藏尸地

滚滚乌江水，浪花拍打着岸边，白花花的浪花夹着清爽的空
气，让人顿时忘记了曾经在这里发生的一段悲惨故事。
LONG);

  set("exits", ([
  "westdown" : __DIR__"wujiang4",
  "northup" : __DIR__"shanlu1",
  "eastdown" : __DIR__"wujiang6",
]));
  set("outdoors", 1);

  setup();
}
