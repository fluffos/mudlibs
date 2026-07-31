// Room: /d/huizhu/zhangpeng2
inherit ROOM;

void create()
{
  set ("short", "帐篷中");
  set ("long", @LONG
这是顶草草加工的牛皮帐篷，地上铺着张毡子，看来已经很破旧了，
不过洗刷得很干净。一边的箱子上放着个小小的红色盒子，除此之外，帐
篷中就一个白铁水壶和两个水碗。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"buluo2",
]));
  setup();
  replace_program(ROOM);
}
