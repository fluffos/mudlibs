// Room: /d/yanjing/to_yj2
inherit ROOM;

void create()
{
  set ("short", "盛京大道");
  set ("long", @LONG
纷纷扬扬的雪下得越发大了,头顶很快就戴上了雪帽.脚下先前还能
看到的脚窝印,很快就被雪花填没了.北边不远就是[盛京]了.
LONG);

  set("outdoors", "yanjing");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"to_yj3",
  "southwest" : __DIR__"to_yj5",
]));
  setup();
  replace_program(ROOM);
}
