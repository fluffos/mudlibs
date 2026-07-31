// sanjie shanlu1.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG
	
走进来这里看见四处野草丛生，长的怪草怪花有半个人高，
前方有一坐高入云端的大山，还不知道前方有妖怪否。
LONG);

  set("exits", ([
  "northup" : __DIR__"shanlu2",
  "southdown" : __DIR__"wujiang5",
]));
  set("outdoors", 1);

  setup();
}
