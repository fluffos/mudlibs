// Room: /d/yandang/luoyan39
inherit ROOM;

void create ()
{
  set ("short", "茶室");
  set ("long", @LONG
推开两扇虚掩的小门,是一个小小的斗室,只是摆了几张矮小的座凳
有个小童正在一个红泥小火炉旁不紧不慢的扇着火,壁上有几幅字,写得
纵横开括,细看下,是陆羽的'茶经'.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaotong.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"luoyan38",
  "north" : __DIR__"luoyan13",
]));

  setup();
}
