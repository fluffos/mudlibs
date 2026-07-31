// Room: /d/pingan/pingankezhan
inherit ROOM;

void create ()
{
  set ("short", "平安客栈");
  set ("long", @LONG
这儿是平安城中最有名的客栈，说是最有名但也不大，只有小小的几个
店面，一个和气的店小二站在柜台前面，他笑脸相迎每一个来往的客人。因
为这儿的人没有高低贵贱，人人都是靠自己的劳动过活。不劳动是可耻的行
为。店铺前挂了一个小小的招牌（paizi）。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaoer" : 1,
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "本店急需工作人员，有意者请向小二打听[工作]的事。
",
]));
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"chufang",
  "west" : __DIR__"kefang",
  "south" : __DIR__"tingtang",
  "east" : __DIR__"nan1",
]));
  set("pingan", 1);
  set("no_fight", 1);
  set("valid_startroom", 1);

  setup();
//  replace_program(ROOM);
}
//防止机器人
 int valid_leave(object me, string dir)
{
        if ( random(10)>7 && dir == "west" )
{
        return notify_fail("等一等,现在客房还没准备好！\n");
}
	else 
	{ 
 	return ::valid_leave(me, dir);
	}
}

