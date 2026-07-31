// Room: /d/huizhu/xiepo
inherit ROOM;

void create()
{
  set ("short", "斜坡");
  set ("long", @LONG
两边的树林稀稀落落的,在西北边塞的寒风吹动中发出沙沙的响声.北
面的草原上牛羊在吃草,放羊的姑娘轻轻的挥着鞭子,南面的树林中有几个
帐篷,透出一股杀气.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"caoyuan",
  "southup" : __DIR__"buluo2",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}
