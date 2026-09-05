// Room: /d/shaolin/houyuan.c
// Date: seagate 2010/10/11

#include <ansi.h>
#include <room.h>
inherit ROOM;

void init();
int do_take(string);
string look_dun();
int do_put(string arg);

void create()
{
	set("short", "厨房后院");
	set("long", @LONG
这里是厨房后面的小院，小院里面堆满了刚从山上砍下来
的柴火，柴堆(chai dui)附近有一个劈柴用的木墩(mu dun)，
一个中年僧人拿着斧子忙着将刚送来的木柴劈开。木门旁边
排着一列一人高的水缸(shui gang)，时不时的有挑水的僧人
用山下的溪水装满水缸。
LONG
	);

	set("exits", ([
		"east" : __DIR__"chufang"
	]));

  set("item_desc", ([ /* sizeof() == 1 */
  "mu dun" : (: look_dun :),
  "木墩" : (: look_dun :),
  "dun"  : (: look_dun :),
  "shui gang" : "这是一个一人高的水缸，要将他装满(fill)似乎需要一点点技巧。\n",
  "gang" : "这是一个一人高的水缸，要将他装满(fill)似乎需要一点点技巧。\n",
  "水缸" : "这是一个一人高的水缸，要将他装满(fill)似乎需要一点点技巧。\n",
  "chai dui" : "这是一座像小山一样的木柴堆，堆满了还未作任何处理的木柴，你可以从柴堆上拿(take)走几根木柴。\n",
  "dui" : "这是一座像小山一样的木柴堆，堆满了还未作任何处理的木柴，你可以从柴堆上拿(take)走几根木柴。\n",
  "柴堆" : "这是一座像小山一样的木柴堆，堆满了还未作任何处理的木柴，你可以从柴堆上拿(take)走几根木柴。\n"]));


  set("objects",([
  	__DIR__"npc/seng2" : 1,
  	__DIR__"obj/mutong" : 2
  ]));


  create_door("east","木门","west",DOOR_CLOSED);
	setup();
}

void init()
{
	add_action("do_take", "take");
	add_action("do_put",  "put");
	add_action("do_fill",  "fill");
}

string look_dun()
{
	if(!this_player()->query_temp("quest_pichai/putwood"))
		return "这是一个砍柴用的木墩，将木柴放(put)在木墩上就可以用斧子砍柴了。\n";
	else
		return "这是一个砍柴用的木墩，木墩上放着一根"+this_player()->query_temp("quest_pichai/name")+"。\n";
}

int do_take(string arg)
{
	object ob;
	
	if(arg!="wood"&&arg!="mu chai"&&arg!="chai"&&
		 arg!="木柴"&&arg!="木头")
		return notify_fail("你想从柴堆上拿走什么\n");
	else if(!mapp(this_player()->query_temp("quest_pichai")))
		return notify_fail("旁边一个中年僧人冲了过来，向你喊道：“你想偷柴！”吓得你连忙逃跑。\n");
	else if(this_player()->query_temp("quest_pichai/prepwood")>0)
		return notify_fail("旁边一个中年僧人冲你怒叫道：“上次拿的木柴砍完再来拿。”\n");
	else if(this_player()->is_busy()) {
		printf("你现在正忙着呢。\n");
		return 1;
	}
	else if(this_player()->is_fighting()) {
		printf("你无法在战斗中分心干别的事情！\n");
		return 1;
	}
	
	ob=new(__DIR__"obj/wood");
	ob->move(this_player());
	this_player()->set_temp("quest_pichai/prepwood",1);
	tell_object(this_player(), "你从柴堆上拿走了一根"+YEL+ob->query("name")+NOR+"。\n");
	this_player()->start_busy(1);
	return 1;
}

int do_put(string arg)
{
	object wood;
	
	if(sizeof(arg)>0)
		wood=present(arg,this_player());

	if(sizeof(arg)<4) {
		printf("你想将什么东西放在木墩上？\n");
		return 1;
	}
	else if(!wood) {
		printf("你身上没有这种木柴。\n");
		return 1;
	}
	else if(!wood->query("wood")) {
		printf("木墩上只能放置木柴。\n");
		return 1;
	}
	else if(!mapp(this_player()->query_temp("quest_pichai"))) {
		printf("旁边一个中年僧人冲了过来，向你喊道：“我正在用木墩砍柴，你等会儿再来吧！”\n");
		return 1;
	}
	else if(!this_player()->query_temp("quest_pichai/prepwood")) {
		destruct(wood);
		printf("旁边一个中年僧人怒喊道：“哪来的木柴？是不是偷得！”吓得你扔下木柴就跑。\n");
		this_player()->start_busy(1);
		return 1;
	}
	else if(this_player()->query_temp("quest_pichai/putwood")) {
		this_player()->delete_temp("quest_pichai/prepwood");
		destruct(wood);
		printf("旁边一个中年僧人跑过来一把夺走你的木柴，喊道：“木墩上的那根"+YEL+this_player()->query_temp("quest_pichai/name")+NOR+
		                   "都没有砍完就想砍下一根了？”\n");
		this_player()->start_busy(1);
		return 1;
	}
	else if(this_player()->is_busy()) {
		printf("你现在正忙着呢。\n");
		return 1;
	}
	else if(this_player()->is_fighting()) {
		printf("你无法在战斗中分心干别的事情！\n");
		return 1;
	}
	
	this_player()->delete_temp("quest_pichai/prepwood");                 //删除领木柴的限制
	this_player()->set_temp("quest_pichai/putwood",1);                   //增加放置木柴的标志
	this_player()->set_temp("quest_pichai/name",wood->query("name"));    //增加放置木墩上的木柴名称
	this_player()->set_temp("quest_pichai/size",wood->query("wood"));    //增加放置木墩上的木柴尺寸
	destruct(wood);
	this_player()->start_busy(1);
	tell_object(this_player(),"你将一根"+this_player()->query_temp("quest_pichai/name")+"放置在木墩上。\n");
	return 1;
}

//挑水的流程应该还是非常简单的，就是从这里拿木桶，carry，然后到山下
//佛心井哪里装上水，走会这里把水倒缸里（当然不能走快了，走快了就水撒
//了，轻功太低水也会撒。）把水缸装满了就完成任务。
//临时标志：quest_fillwater里面的值含义
//promoter                                    ---任务发起人
//start                                       ---启动标志
//water                                       ---还需要的水量
//success                                     ---成功
//挑水成功一次获得一次基本轻功的提高，经验计算量级在先天身法为30，基
//本轻功为100级的时候大概是100+150+250=500这个数量级。
int do_fill(string arg)
{
	object ob,me;
	
	me=this_player();
	ob=present("mu tong",me);
	if(!ob) 
		return 0;
	else if(!ob->query("carried"))
		return 0;
	else if(ob->query("water")<=0) {
		printf("手里拎着两个空木桶，快点去山下装水上山！\n");
		return 1;
	}
	else if(arg!="水缸"&&arg!="gang"&&arg!="shui gang") {
		printf("你想把水往哪里倒？\n");
		return 1;
	}
	else if(!me->query_temp("quest_fillwater/start")) {
	  printf("中年僧人一把推开你，嘟囔着：还没有分配你活呢！\n");
	  return 1;
	}
	
	ob->delete("carried");
	me->add_temp("quest_fillwater/water",ob->query("water")*(-1));
	ob->set("water",0);
	ob->move(this_object());
	if(me->query_skill("dodge",1)<=150) {
		tell_object(me,"你在挑水的过程中发现自己的身体更加轻灵许多。\n");
		me->improve_skill("dodge",100+(random(me->query("dex"))+1)*10+random(me->query_skill("dodge",1)*5));
	}
	if(me->query_temp("quest_fillwater/water")<=0) {
		me->set_temp("quest_fillwater/success",1);
		tell_object(me, "你已经把整个水缸都装满了，然后把木桶放回了原处，可以向"+me->query_temp("quest_fillwater/promoter")+"汇报结果了！\n");
	}
	else
		tell_object(me, "你将水桶里的水倒进了水缸，然后把木桶放回了原处，看了看水缸似乎再挑"+chinese_number(me->query_temp("quest_fillwater/water")/100+1)+"趟水就可以把水缸装满了。\n");
	return 1;
}