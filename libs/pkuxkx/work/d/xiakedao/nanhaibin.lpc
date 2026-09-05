//南海之滨
// for xiakedao
// modified by aiai 98/10/27
// Modified by iszt@pkuxkx, 2007-04-02, about var:count

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","南海海滨");
	set("long",@LONG
这里是位于南海渔港的一处海滨。晴空万里，茫茫大海，一望无垠，朵朵浪
花拍打着岸边的岩石，几只海鸥正在天空中飞翔。蔚蓝的海面之上，隐约看到一
艘小船缓缓而来，船头似乎站着一个黄衣大汉(dahan)。
LONG);
	set("exits",([
		"north" : "/d/quanzhou2/nanmen",
		"east" : "/d/bhdao/haibin",
	]));
	set("item_desc",([
		"dahan" : "他正立在船头，双手负在身后。你可以朝他招招手(wave)。\n",
	]));
	set("outdoors", "xiakedao");
        set("count", 5);
	setup();
}

void init()
{
	add_action("do_enter","enter");
	add_action("do_wave","wave");
	add_action("do_wave","yell");
}

void reset()
{
	::reset();
	if(query("count") < 3)
		add("count", 1);
}

int do_wave(string arg)
{
	object me = this_player();
	object person, room;
	int i;
	if (arg != "黄衣大汉" && arg != "dahan")
		return 0;
	if ( present("huangyi dahan", environment(me) ) )
	{
		write("他不就在你跟前吗，你还招什么手？\n");
		return 1;
	}
	message_vision("$N向船上的黄衣大汉招了招手。\n",me);
	if(query("count"))
	{
//                person = new("/d/xiakedao/npc/huangyidahan");
                person = new("/d/xiakedao/npc/dahan");
		message_vision("黄衣大汉从船头纵身一跃，跳上岸来。\n",me);
		person->move(__DIR__"nanhaibin");
		add("count", -1);
	}
	else
	{
		message_vision("黄衣大汉对$N摆摆手，说道：「刚才已经有人过去了，您再等等吧！」\n",me);
	}
	return 1;
}

int do_enter(string arg)
{
	object me = this_player();
	object* inv = deep_inventory(me);
	object room;
	int i;

	if (!arg || arg=="")
		return 0;
	if (arg !="boat")
		return 0;

	if (me->query_temp("marks/去岛") )
	{
		for(i=sizeof(inv)-1; i>=0; i--)
		{
			if(inv[i]->is_character())
				return notify_fail("你不能背着别的玩家上岛！\n");
		  if (inv[i]->query("id")=="qiannian renshen" )
		  {
		  	if (!me->query_temp("warn_renshen"))
		  		{
			  write("黄衣大汉说道：侠客岛灵药多如牛毛，你打算带着人参去展览啊？你红着脸把人参扔在了地上。\n");
			  me->set_temp("warn_renshen",1);
			    }
		    inv[i]->move("/d/xiakedao/nanhaibin");
		  }
		}
		if ( me->query_encumbrance() * 100 / me->query_max_encumbrance() > 40)
		{
			write("你身上背的东西太多，难道不怕把船压翻？还是放下一些吧。\n");
			return 1;
		}

		message_vision("$N从踏板上走上了船。\n",me);
		me->delete_temp("warn_renshen");
		me->move(__DIR__"boat");
	
		if(room=find_object(__DIR__"boat"))
		{
			room->set("exits/out",__FILE__);
			message_vision("$N从踏板上走了进来。\n",me);
		}
		remove_call_out("on_board");
		call_out("on_board",15,me);
		return 1;
	}
	write("好象没有人邀请你去侠客岛，擅自前往会有生命危险的。\n");
	return 1;
}

void on_board(object me)
{
	object room;

	message_vision("黄衣大汉把踏板收起来，船桨一点，小船向南海驶去。\n",me);
	if (room = find_object(__DIR__"boat"))
	{
		room->delete("exits/out");
		message_vision(HIW"那汉子划了几桨，将小舟划离海滩，掉转船头，扯起一张黄色三角帆，吃上\n"
			"了缓缓拂来的北风，向南进发。\n\n"NOR,me);
	}
	remove_call_out("arrive");
	call_out("arrive", 15, me);
}

void arrive(object me)
{
	object room;
	if (room=find_object(__DIR__"boat"))
	{
		room->set("exits/out",__DIR__"shatan1");
		message_vision(HIB"入夜之后，小舟转向东南。在海中航行了三日，到第四日午间，屈指正是腊\n"
			"月初八，那汉子指着前面一条黑线，说道：“那便是侠客岛了。\n"NOR,me);
	}
	me->delete_temp("marks/去岛");
}
