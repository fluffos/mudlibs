// Room: /d/yanjing/gardon2
inherit ROOM;

void create()
{
  set ("short", "花园");
  set ("long", @LONG
花木间的积雪尚未溶化,几只雪鸡在雪层上来回寻找着食物.几株腊
梅绽开了花朵,风中带着一丝清香,南边的鹅卵石小道通向中院,北边是一
栋黑呼呼的大屋子,看来没多少人来往.
LONG);

  set("outdoors", "yanjing");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road1",
  "north" : __DIR__"room",
]));
  setup();
  replace_program(ROOM);
}
