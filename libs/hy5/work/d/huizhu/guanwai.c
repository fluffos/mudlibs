// Room: /d/huizhu/guanwai
inherit ROOM;

void create()
{
  set ("short", "嘉峪关外");
  set ("long", @LONG
嘉峪关外一片贫嵴，散落的砾石中间几棵小草在风中颤栗。远远的黄
沙被风卷起，黄沙下是一队长长的驼队，一个苍老的声音在唱道『一过嘉
峪关,两眼泪不干,前边是戈壁,后面是沙滩.』歌声苍凉,远播四野。西北一
条荒路通往天山。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"huanglu1",
  "southwest" : __DIR__"shamo",
  "east" : __DIR__"jiayuguan",
  "southeast" : "d/jyguan/ximen",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}
