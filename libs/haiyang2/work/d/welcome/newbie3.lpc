// Room: /d/welcome/newbie3
inherit ROOM;

void create ()
{
  set ("short", "新手训练室");
  set ("long", @LONG
离开入世之路后！你会到达游戏中的第一站！也就是平安城，在平安
城里你可以放心的熟悉一下各种命令，看看帮助文件！因为在平安城里是
决对不会死的你也可以在里面的客栈做做工作挣些钱，也可以在武馆学点
初级的武技好了！让我们祝贺你踏入江湖吧！
这里是最后的大门，踏出这里就走向江湖了。请你记得多保存你的
资料(save),如果累了想离开请(quit),不懂的地方可以看(help),祝你
玩的愉快。这里有8条路分别通向
yz 扬州 bj 北京 xy 襄阳 dl 大理 lz 兰州
qz 泉州 wg 武馆 pa 平安 cd 成都 km 昆明
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "yz" : "/d/city/kedian",
  "bj" : "/d/beijing/kedian",
  "xy" : "/d/xiangyang/kedian",
  "dl" : "/d/dali/kedian",
  "qz" : "/d/quanzhouchen/kedian",
  "wg" : "/d/wuguan/guanmen",
  "pa" : "/d/pingan/pingankezhan",
  "cd" : "/d/chengdu/kedian",
  "lz" : "/d/lanzhou/kedian",
  "km" : "/d/kunming/kedian",		
]));
  set("no_magic", 1);
  set("no_beg",1);
  set("pingan",1);
  set("no_fight", 1);

  setup();
}
int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
	if (dir =="pa")
	{
		if ( me->query("PKS") >= 3)
		return notify_fail("你杀过太多的玩家！平安城不欢迎你！\n");
	
		if ( me->query("age") >= 20)
		return notify_fail("你这么大岁数也还想进平安城？\n");
	
	
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
