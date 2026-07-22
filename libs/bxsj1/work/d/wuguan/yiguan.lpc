// yiguan.c 驿馆

#include <ansi.h>
inherit ROOM;
mapping *paizi=({
	([  "name":"江南扬州城",    "id":"Yangzhou",   "value":20   ]),
	([  "name":"西域星宿海",    "id":"Xingxiu",    "value":80   ]),
	([  "name":"河北武当山",    "id":"Wudang",     "value":50   ]),
	([  "name":"湖南铁掌山",    "id":"Tiezhang",   "value":50   ]),
	([  "name":"东海桃花岛",    "id":"Taohuadao",  "value":100  ]),
	([  "name":"神龙岛海滩",    "id":"Shenlong",   "value":30   ]),
	([  "name":"河南嵩山少林",  "id":"Shaolin",    "value":70   ]),
	([  "name":"江南姑苏慕容",  "id":"Murong",     "value":60   ]),
	([  "name":"西域明教",      "id":"Mingjiao",   "value":100  ]),
	([  "name":"昆仑山脉",      "id":"Kunlun",     "value":100  ]),
	([  "name":"西岳华山派",    "id":"Huashan",    "value":40   ]),
	([  "name":"终南山古墓",    "id":"Gumu",       "value":30   ]),
	([  "name":"四川峨嵋山",    "id":"Emei",       "value":40   ]),
	([  "name":"雪山大轮寺",    "id":"Dalunsi",    "value":100  ]),
	([  "name":"西南大理国",    "id":"Dali",       "value":50   ]),
//	([  "name":"终南山全真教",   "id":"Quanzhen",	  "value":30   ]),
});

string look_paizi();
int do_go(string);

void create()
{
	set("short",HIC"驿馆"NOR);
	set("long", @LONG
这是武馆的驿馆，房间很大，弥散着一股牲畜和人夹杂的气味。周围停着
好几辆大车，马儿不停地嘶鸣着。一位老车夫，专门带武馆刚出门的弟子去江
湖各大门派，他一见你走过来，不敢怠慢，带着笑脸连忙迎上前去。驿馆的中
间有根木柱，柱子上挂着一块牌子（paizi）。
LONG
	);
	set("exits",([
		"east" : __DIR__"menlang",
		"south" : "/d/xiangyang/cross2",
	]));

	set("item_desc",([
		"paizi" : (: look_paizi :)
	]));

	set("objects", ([
		__DIR__"npc/chefu" : 1,
	]));

	setup();
}

void init()
{
	 add_action("do_go", "qu");
}

string look_paizi()
{
	string str=HIW"\n价目表：\n"NOR;
	int i=sizeof(paizi);

	while (i--) {
		str += chinese_number(15-i)+"，";
		str += "去"+paizi[i]["name"];
		str += "("HIW + paizi[i]["id"] + NOR")";
		str += " 需"+MONEY_D->price_str(paizi[i]["value"]) + "\n";
	}
	return str;
}

void do_move(object ob, int i)
{
	message_vision(YEL"\n$N把钱交给了车夫，车夫领$N上了一辆大车。\n\n"NOR,ob);
	ob->move(__DIR__"che");
//      ob->move(paizi[i]["file"]);
}

int do_go(string arg)
{
	object ob=this_player();
	int i=sizeof(paizi);

	if (!arg) return notify_fail("你要去哪里？\n");
	arg = capitalize(arg);
	if (ob->is_busy() || ob->is_fighting())
		return notify_fail("你正忙着呢！\n");
	while(i--) {
		if (arg == paizi[i]["id"]) {
			switch (MONEY_D->player_pay(ob, paizi[i]["value"])) {
				case 0:
					return notify_fail("穷光蛋，没钱就别乘车了，往南走就到襄阳了！\n");
				case 2:
					return notify_fail("有零钱吗？没零钱的话只能往南走，那里能到襄阳。\n");
			}
			message_vision(HIG"$N在车夫耳边轻声说出所去之地。\n"NOR, ob);
			ob->start_busy(2);
			ob->set_temp("place", arg);
			call_out("do_move", 3, ob, i);
			return 1;
		}
	}
	return notify_fail("你要去哪里？\n");
}

int valid_leave(object me,string dir)
{
	if( dir == "east")
		return notify_fail("你已经可以去江湖闯荡了，不要再留恋武馆了。\n");
	return ::valid_leave(me, dir);
}
