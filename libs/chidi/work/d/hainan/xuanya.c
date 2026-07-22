// Room: /d/hainan/xuanya
inherit ROOM;

void create ()
{
  set ("short", "悬崖秘洞");
  set ("long", @LONG
隐藏在悬崖间的一个山洞,洞口的山石经过人为的清理,显得十分别 
致.洞壁有许多裂缝,一种不知名的植物从裂缝中生长出来,把岩壁染成一 
片绿色.洞顶的一块莲花形的岩石中间,镶了一颗夜明珠. 
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhonglin.c" : 1,
]));
  set("item_desc", ([ /* sizeof() == 2 */
  "植物" : "一种叶子成雪花六出型的植物,上面结满了红色的果子,不知道 
摘(pick 果子)下来后味道怎样! 
",
  "夜明珠" : "一颗名贵的夜明珠,既使在暗黑的地方,也能发出明洁的广茫. 
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "eastup" : __DIR__"midao",
]));

  setup();
}
void init()
{
    add_action("do_pick","pick");
}
int do_pick(string str)
{ 
	if( !living(this_player()))	return 0;
  if (str!="果子") return notify_fail("你要摘什么?\n");
message_vision("$N从盘绕石壁的植物中摘下一颗红色果子!\n",this_player());
clone_object("/d/hainan/obj/shanhu.c")->move(this_player());
return 1;
}
