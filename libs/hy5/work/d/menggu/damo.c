// Room: /d/menggu/damo
inherit ROOM;

void create()
{
  set ("short", "大漠");
  set ("long", @LONG
四周是一望无际的沙漠，在烈日的照射下，你几乎要虚脱了。西北
通向蒙古草原，东边则是京城方向。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"lvzhou",
  "northwest" : __DIR__"mobei",
]));
  set("outdoors", "menggu");
  setup();
  replace_program(ROOM);
}
