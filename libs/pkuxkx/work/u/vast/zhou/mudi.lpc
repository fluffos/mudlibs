inherit ROOM;

void create()
{
         set("short", "墓地");
        set("long", @LONG
这是桃花岛主黄药师的过世夫人冯氏的墓地，墓前
是一个墓碑(bei)。
LONG);
         set("exits", ([ /*sizeof() == 2 */
         "southeast" : __DIR__"taolin7",
         "north" : __DIR__"shanbi",
          ]));
	set("item_desc",([
	"bei" : "这是一个墓碑，上面刻着“桃花岛女主冯氏埋香之冢”十一个大字。\n",
	]));
         set("outdoors","taohuadao");
	setup();
}
void init()
{
//	add_action("do_push","push");
//	add_action("do_enter","enter");
	add_action("do_ketou","ketou");
	add_action("do_ketou","kneel");
}
int do_ketou(string arg)
{
	object me;
	string n, k;
	int d;
	me = this_player();
	if (!arg)
	return notify_fail("你要向谁磕头？\n");
	if( arg == "bei" )
	return notify_fail("你想对墓碑磕头几次？\n");
	sscanf(arg, "%s %s", n, k);
	if( n != "bei" )
	return notify_fail("你要向谁磕头？\n");
	sscanf(arg, "bei %s", n);
	d = atoi(n);
	if(d > 4)
	return notify_fail("有必要磕那么多次吗？\n");
	if (d < 4)
	return notify_fail("你还是多磕几下吧，这样心里也踏实些。\n");
	if (d == 4)
	message_vision("$N在墓前跪倒，恭恭敬敬的拜了四拜。\n", me);
	me->set_temp("zyhb/mudi", 1);
	return 1;
}
/*
int do_push(string arg)
{
	int i,j;
	object me;
	me=this_player();
	if(arg=="left")
	{
	if(!me->query_temp("marks/左"))
	{me->set_temp("marks/左",1);
	message_vision("墓碑往左移动了一点。\n",me);
	return 1;}
	if((int)me->query_temp("marks/左")==1)
	{me->set_temp("marks/左",2);
	message_vision("墓碑往左移动了一点。\n",me);
	return 1;}
	if((int)me->query_temp("marks/左")==2)
	{me->set_temp("marks/左",3);
	message_vision("墓碑往左移动了一点。\n",me);
	return 1;}
	if((int)me->query_temp("marks/左")==3)
	{message_vision("你想把这座碑推倒啊？\n",me);
	me->set_temp("marks/左",0);
	return 1;}
	i=(int)me->query_temp("marks/左");
	return 1;
	}

	if(arg=="right")
	{
	if(!me->query_temp("marks/右"))
	{me->set_temp("marks/右",1);
	message_vision("墓碑往右移动了一点。\n",me);
	return 1;}
	if((int)me->query_temp("marks/右")==1)
	{me->set_temp("marks/右",2);
	message_vision("墓碑往右移动了一点。\n",me);
	return 1;}
	if((int)me->query_temp("marks/右")==2)
	{me->set_temp("marks/右",3);
	message_vision("墓碑往右移动了一点。\n",me);
	return 1;}
	if((int)me->query_temp("marks/右")==3)
	{message_vision("你想把这座碑推倒啊？\n",me);
	me->set_temp("marks/右",0);
	return 1;
	}
	j=(int)me->query_temp("marks/右");
	return 1;
	}
	if(i<=2 && j>=1)
	{i==0;j==0;return 0;}
	if(i==4 && j<=2)
	{i==0;j==0;return 0;}
	if(i==3&&j==3){
	message_vision("$N看见坟墓慢慢露出一条缝，原来这里有一扇石门.\n",me);
	return 1;}

}
int do_enter(string arg)
{
	object me;
	me=this_player();
	if(!arg||arg!="men")
	return notify_fail("你想到哪去?\n");
 	if(me->query_temp("marks/墓") && me->query_temp("marks/墓1"))
	message_vision("$N走进到了坟墓里面。\n",me);
	me->move(__DIR__"munei");
	message_vision("$N从外面走了进来。\n",me);
	me->set_temp("marks/墓",0);
	me->set_temp("marks/墓1",0);
	return 1;
}
*/
