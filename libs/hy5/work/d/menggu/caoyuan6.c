// Room: /d/menggu/caoyuan6
inherit ROOM;

void create()
{
  set ("short", "铁木真部落");
  set ("long", @LONG
铁木真部落是当今蒙古草原上最强盛的一族,由于他有勇有谋,善于用
人,草原上的英雄都愿意为他效力,你目光所到之处,牛肥马壮,连绵的蒙古
包遮盖了举目所见的整的草原.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"buluo",
  "west" : __DIR__"shulin1",
  "southwest" : __DIR__"caoyuan5",
]));
  set("outdoors", "menggu");
  setup();
  replace_program(ROOM);
}
