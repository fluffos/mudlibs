// Room: /d/yandang/luoyan19.c

inherit ROOM;

void create ()
{
  set ("short", "女弟子居室");
  set ("long", @LONG
女弟子居室中比较干净,毕竟女孩子还是很爱整洁的,床前的梳妆台
上除了雕花菱角镜外,还有许多叫不上名的脂粉,一个雨后天青的花瓶里
摆着几支鲜花.
LONG);

  set("sleep_equipment", "木床");
  set("sleep_room", "1");
  set("no_fight", "1");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"luoyan17",
  "south" : __DIR__"luoyan22",
]));

  setup();
}
void init()
{
	add_action("do_qu", "qu");
}

int do_qu(string arg)
{
    object me,ob1;
    me=this_player();

    if ( (arg!="flower")&&(arg!="花")) return 0;
    message_vision(
"$N从花瓶中取出一枝花！\n", me);
      		 ob1=clone_object(__DIR__"obj/hongmeigui.c");
			 ob1->move(me);
        return 1;
}
