// Room: /d/xiangyang/liwu.c  茅舍里屋
// Date: Feb . 3 2002 by Pound

#include "room.h"

inherit ROOM;
// 胡家弟子可以通过三种渠道获得药物，花房培植(zhonghua)、药房找药(zhao)、自己研制(make)
// 此处即为药房，不同等级的医药知识，所能分辨出的药物不同，等级越高能分辨的药物越多。
// 因找药近似于不劳而获，所以每次刷新后，全部胡家弟子只能找到三种药物。
string* med1 = ({"jingqi", "dieda", "liuhe", });
string* med2 = ({"jingqi", "dieda", "liuhe", "huojin", "qingxin", });
string* med3 = ({"jingqi", "dieda", "liuhe", "huojin", "qingxin", "jiedu", "tianxin", });
string* med4 = ({"jingqi", "dieda", "liuhe", "huojin", "qingxin", "jiedu", "tianxin", "zhending", "tongmai", });
string* med5 = ({"jingqi", "dieda", "liuhe", "huojin", "qingxin", "jiedu", "tianxin", "zhending", "tongmai", "shengsheng", "shengsheng", });

void create()
{
	set("short", "里屋");
	set("long", @LONG
这里是一间密封的小屋，看上去象是收藏珍贵物品的地方。靠北墙处
摆放着一张木橱，仔细看去，里面居然有很多药材和无数小瓷瓶。但是都
没有贴标签，必须要有较高深的医药知识才可能分辨清楚各种药名，找出
有用的丹药（zhao yao）。
LONG);
	set("searched", 0);
	set("exits", ([
	    "south"  : __DIR__"maoshe",
	]));
	create_door("south", "木门", "north", DOOR_CLOSED);
	setup();
}


void init()
{
	add_action("do_search", "zhao");
}


int do_search(string arg)
{
	object ob, me;
	int lvl;
	me = this_player();
	lvl = me->query_skill("yaowang-miaoshu", 1);

	if (! arg || arg == "") 
	    return 0;

	if (me->is_fighting())
		return notify_fail("打架的时候你还有闲工夫找药？\n");
	if (me->is_busy())
		return notify_fail("还是先把手头的事情忙完吧。\n");

	if (me->query("jing") < 300)
		return notify_fail("你现在精神难以集中，无法找药。\n");
	if (lvl < 100 || me->query_skill("medical", 1) < 100)
	    return notify_fail("你看来看去，始终无法分辨各种药物，看来还需要努力钻研医药知识。\n");
    
	if (arg == "yao" || arg == "medicine" || arg == "muchu" || arg == "cabinet")
	{
	    if (query("searched") > 2)
		return notify_fail("经过刚才的一阵翻找，已经很难分辨清楚各种药物了。\n");
	    if (lvl > 150 && lvl <= 180)
		ob = new("/clone/medicine/" + med2[random(sizeof(med2))]);
	    else if (lvl > 180 && lvl <= 210)
		ob = new("/clone/medicine/" + med3[random(sizeof(med3))]);
	    else if (lvl > 210 && lvl <= 240)
		ob = new("/clone/medicine/" + med4[random(sizeof(med4))]);
	    else if (lvl > 240)
		ob = new("/clone/medicine/" + med5[random(sizeof(med5))]);
	    else
		ob = new("/clone/medicine/" + med1[random(sizeof(med1))]);

	    add("searched", 1);     
	    message_vision("$N从一个小瓶子里找到一颗" + ob->query("name") + "。\n", me);
	    ob->move(me);
	    me->add("jing", -100);
	    me->start_busy(2 + random(3));
//增加忙时，使每次刷新出的药物不至于只被一个网速快的弟子全部得到。每位在场弟子都可能有所收获才比较合理。
	    return 1;
	}
}   

