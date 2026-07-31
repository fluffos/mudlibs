// Room: /d/menggu/yading
inherit ROOM;

void create()
{
  set ("short", "山崖顶");
  set ("long", @LONG
崖顶是个巨大的平台，积满了皑皑白雪。几块巨大的石头半卧在一边,
形状千奇百怪,上面有许多洞穿的小孔,风过处,如泣如诉.四边的山崖平平
如削,几棵矮树就斜长于崖边.
LONG);

  set("outdoors", "menggu");
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"downxuanya",
]));

  setup();
  replace_program(ROOM);
}
