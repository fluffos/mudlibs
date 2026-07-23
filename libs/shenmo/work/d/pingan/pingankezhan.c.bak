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
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
  set("no_dazuo", 1);
  set("no_kill", 1);
  set("valid_startroom", 1);

  setup();
//  replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
	if (dir =="west")
	{
		if ( me->query("PKS") >= 3)
		return notify_fail("你杀过太多的玩家！平安城不欢迎你！\n");
	
		if ( me->query("age") >= 18)
		return notify_fail("你这么大岁数也还想睡觉不用钱？\n");
	
	
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("你想进去拐卖人口？\n");
       		
		}
		
	}

	return ::valid_leave(me, dir);
}
