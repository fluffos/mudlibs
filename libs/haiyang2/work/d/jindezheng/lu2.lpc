// Room: /d/jindezheng/lu1
inherit ROOM;

void create()
{
  set ("short", "树林");
  set ("long", @LONG
一片杂树林,地上铺了厚厚一层落叶.有一条小径隐约穿过树林,前
方似乎还升起一缕青烟.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southwest":__DIR__"to_qz",
  "northeast" :__DIR__"lu1",
]));
  set("outdoors", "/d/jindezheng");
  setup();
//  replace_program(ROOM);
}
void init()
{
        add_action("do_go","go");

}

int do_go()
{
if(random(3)){
this_player()->move(this_object());
return 1;
}
}
