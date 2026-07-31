// Room: /d/menggu/caodui
inherit ROOM;

void create()
{
  set ("short", "大草堆");
  set ("long", @LONG
蒙古人一过炎夏，便割草堆积，冬日饲养牲口，烧火取暖，全凭干草，
是以草堆往往比住人的蒙古包还大。一边是个简陋的小茅草屋.
LONG);

  set("outdoors", "menggu");
  set("exits", ([ /* sizeof() == 2 */
  "in" : __DIR__"maowu",
  "west" : __DIR__"byriver",
]));
  setup();
  replace_program(ROOM);
}
