// Room: /d/sandboy/inzizhuan
inherit ROOM;

void create()
{
  set ("short", "佛堂");
  set ("long", @LONG
紫竹庵内的佛堂，正中佛龛中供奉着一尊白衣观音，四壁清清爽爽，
地下的水磨砖块抹拭得一尘不染。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"zizhuan",
]));
  setup();
}
