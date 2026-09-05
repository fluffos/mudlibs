inherit ROOM;

void create()
{
  set("short","山路");
  set("long",@LONG
山路异常难行。时而盘上高山，时而跨过深谷。一路上人烟
稀少，只有一些被你惊起的飞禽走兽。
LONG );
  set("outdoors", "lingjiu");
  set("exits",([
    "northup" : __DIR__"songlin",
      "southwest" : __DIR__"shanlu1",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
