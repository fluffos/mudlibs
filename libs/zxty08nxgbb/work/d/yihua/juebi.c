//room: juebi.c

inherit ROOM;

void init();
int do_zou(string);

void create()
{
  set("short","绝壁");
  set("long",@LONG
山道到此突然消失，在你面前是一条绝壁，往下看去云雾缭绕，你根
本无法看清谷底。你向下望去(down)什么也看不见，旁边有一块石碑(bei)。
LONG
     );
  set("outdoors", "yihua");
  set("exits",([
      "southdown" : __DIR__"shandao2",
     ]));
  set("item_desc",([
      "bei" : "『移花宫』禁止男子进入,违者杀无赦！\n" ,
      "down" : "这里没有任何路，你想不通可以(jump)下去。\n" ,
     ]));
  setup();
}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me=this_player(), room;

	if(!arg || arg!="down")
		return notify_fail("你真的想不通吗？\n");

	if(!( room = find_object(__DIR__"xiaojin")) )
		room = load_object(__DIR__"xiaojin");

	if(!objectp(room))
		return notify_fail("ERROR:not found 'xiaojin.c' \n");
	message_vision("$N双眼一闭，纵然跳了下去。\n",me);
//       　message("vision","你只见一个身影从天而降。\n", room);
        me->move(room);
        return 1;
}
