// Room: /d/sandboy/huangni
inherit ROOM;

void create()
{
  set ("short", "黄泥道");
  set ("long", @LONG
乡间的一条黄泥道,已经给人踩的高低起伏,不过来往的人还是挺多,
因为从此向东可以到达大城市杭州.
LONG);

  set("outdoors", "/d/sandboy");
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/d/hangzhou/dalu1",
  "west" : __DIR__"well",
]));
  setup();
}
