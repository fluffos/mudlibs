// Room: /d/menggu/xiaolu
inherit ROOM;

void create()
{
  set ("short", "小路");
  set ("long", @LONG
林中的一条小道,高矮不平,时而要从一些挡路的灌木中穿过,七拐
八歪的不远,一座山崖平地而起,山崖半截深入云雾之中,自来无人能得
上去.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"downxuanya",
  "eastdown" : __DIR__"shulin4",
]));
  set("outdoors", "menggu");
  setup();
  replace_program(ROOM);
}
