// Room: /d/japan/guancai
inherit ROOM;

void create()
{
  set ("short", "棺材铺");
  set ("long", @LONG
刚进门,你就打了个突,房间里面摆满了大大小小的棺材,在房间的四
周,还点着些蜡烛,光影在屋子中晃动,看来十分恐怖.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jiedaoe2",
]));
  setup();
}
