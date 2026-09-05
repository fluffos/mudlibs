// 马车 Zine 2012.8.1
#include <ansi.h>
inherit ROOM;
#define DACHE "machehang"
void create()
{
        set("short", "马车");
        set("long", @LONG
这是一架普通的马车，驶往(qu)各大城市。你也可以下(xia)车。
LONG);

        setup();
}

mapping *destinations=({
	(["dest_area":"扬州","dest_id":"yangzhou","dest_room":"/d/city/"+DACHE,"x":0,"y":0,"big_area":"中原","small_area":1]),
	(["dest_area":"信阳","dest_id":"xinyang","dest_room":"/d/xinyang/"+DACHE,"x":-2,"y":0,"big_area":"中原","small_area":1]),
	(["dest_area":"曲阜","dest_id":"qufu","dest_room":"/d/qufu/"+DACHE,"x":0,"y":3,"big_area":"中原","small_area":1]),
	(["dest_area":"中原","dest_id":"zhongyuan","dest_room":"/d/zhongyuan/"+DACHE,"x":-2,"y":2,"big_area":"中原","small_area":1]),
	(["dest_area":"襄阳","dest_id":"xiangyang","dest_room":"/d/xiangyang/"+DACHE,"x":-5,"y":0,"big_area":"中原","small_area":1]),
	(["dest_area":"武当山","dest_id":"wudangshan","dest_room":"/d/wudang/"+DACHE,"x":-6,"y":0,"big_area":"中原","small_area":1]),
	(["dest_area":"少林寺","dest_id":"shaolinsi","dest_room":"/d/shaolin/"+DACHE,"x":-3,"y":3,"big_area":"中原","small_area":1]),
	(["dest_area":"洛阳","dest_id":"luoyang","dest_room":"/d/luoyang/"+DACHE,"x":-4,"y":4,"big_area":"中原","small_area":1]),
	(["dest_area":"华山","dest_id":"huashan","dest_room":"/d/huashan/"+DACHE,"x":-5,"y":2,"big_area":"中原","small_area":2]),
	(["dest_area":"小山村","dest_id":"xiaoshancun","dest_room":"/d/village/"+DACHE,"x":-6,"y":1,"big_area":"中原","small_area":2]),
	(["dest_area":"全真","dest_id":"quanzhen","dest_room":"/d/quanzhen/"+DACHE,"x":-7,"y":2,"big_area":"中原","small_area":2]),
	(["dest_area":"古墓","dest_id":"gumu","dest_room":"/d/gumu/"+DACHE,"x":-7,"y":3,"big_area":"中原","small_area":2]),
	(["dest_area":"长安","dest_id":"changan","dest_room":"/d/changan/"+DACHE,"x":-8,"y":4,"big_area":"中原","small_area":2]),
	(["dest_area":"星宿","dest_id":"xingxiu","dest_room":"/d/xingxiu/"+DACHE,"x":-9,"y":5,"big_area":"中原","small_area":2]),
	//(["dest_area":"灵鹫","dest_room":"/d/lingjiu/"+DACHE,"x":-9,"y":7,"big_area":"中原","small_area":2]),//和星宿过于近
	(["dest_area":"灵州","dest_id":"lingzhou","dest_room":"/d/lingzhou/"+DACHE,"x":-10,"y":6,"big_area":"中原","small_area":2]),
	(["dest_area":"建康府北城","dest_id":"jiankangfu","dest_room":"/d/yingtiannorth/"+DACHE,"x":0,"y":0,"big_area":"江南","small_area":1]),
	(["dest_area":"归云庄","dest_id":"guiyunzhuang","dest_room":"/d/guiyunzhuang/"+DACHE,"x":3,"y":0,"big_area":"江南","small_area":1]),
	(["dest_area":"镇江","dest_id":"zhenjiang","dest_room":"/d/zhenjiang/"+DACHE,"x":4,"y":2,"big_area":"江南","small_area":1]),
	(["dest_area":"苏州","dest_id":"suzhou","dest_room":"/d/suzhou/"+DACHE,"x":4,"y":-1,"big_area":"江南","small_area":1]),
	(["dest_area":"嘉兴","dest_id":"jiaxing","dest_room":"/d/quanzhou/"+DACHE,"x":4,"y":-2,"big_area":"江南","small_area":1]),
	(["dest_area":"牙山","dest_id":"yashan","dest_room":"/d/yashan/"+DACHE,"x":5,"y":-2,"big_area":"江南","small_area":1]),
	(["dest_area":"泉州","dest_id":"quanzhou","dest_room":"/d/quanzhou2/"+DACHE,"x":4,"y":-4,"big_area":"江南","small_area":1]),
	(["dest_area":"福州","dest_id":"fuzhou","dest_room":"/d/fuzhou/"+DACHE,"x":5,"y":-3,"big_area":"江南","small_area":1]),
	(["dest_area":"临安府","dest_id":"hangzhou","dest_room":"/d/hangzhou/"+DACHE,"x":2,"y":-2,"big_area":"江南","small_area":1]),
	(["dest_area":"江州","dest_id":"jiangzhou","dest_room":"/d/jiangzhou/"+DACHE,"x":-2,"y":-1,"big_area":"江南","small_area":1]),
	(["dest_area":"岳阳","dest_id":"yueyang","dest_room":"/d/yueyang/"+DACHE,"x":-3,"y":0,"big_area":"江南","small_area":1]),
	(["dest_area":"南昌","dest_id":"nanchang","dest_room":"/d/nanchang/"+DACHE,"x":-2,"y":-3,"big_area":"江南","small_area":1]),
	(["dest_area":"成都","dest_id":"chengdu","dest_room":"/d/chengdu/"+DACHE,"x":-5,"y":-2,"big_area":"江南","small_area":2]),
	(["dest_area":"峨嵋","dest_id":"emei","dest_room":"/d/emei/"+DACHE,"x":-5,"y":-3,"big_area":"江南","small_area":2]),
	(["dest_area":"昆明","dest_id":"kunming","dest_room":"/d/kunming/"+DACHE,"x":-5,"y":-6,"big_area":"江南","small_area":2]),
	(["dest_area":"大理城中","dest_id":"dalichengzhong","dest_room":"/d/dalicheng/"+DACHE,"x":-6,"y":-5,"big_area":"江南","small_area":2]),
	(["dest_area":"天龙寺","dest_id":"tianlongsi","dest_room":"/d/tianlong/"+DACHE,"x":-6,"y":-4,"big_area":"江南","small_area":2]),
	(["dest_area":"大轮寺","dest_id":"dalunsi","dest_room":"/d/dalunsi/"+DACHE,"x":-7,"y":2,"big_area":"江南","small_area":2]),
	(["dest_area":"凌霄城","dest_id":"lingxiaocheng","dest_room":"/d/lingxiao/"+DACHE,"x":-7,"y":3,"big_area":"江南","small_area":2]),
	(["dest_area":"北京","dest_id":"beijing","dest_room":"/d/beijing/"+DACHE,"x":0,"y":0,"big_area":"河北","small_area":1]),
	(["dest_area":"日月神教","dest_id":"riyueshenjiao","dest_room":"/d/riyuejiao/"+DACHE,"x":-1,"y":1,"big_area":"河北","small_area":1]),
	(["dest_area":"晋阳","dest_id":"jinyang","dest_room":"/d/jinyang/"+DACHE,"x":-4,"y":-1,"big_area":"河北","small_area":1]),
	(["dest_area":"张家口","dest_id":"zhangjiakou","dest_room":"/d/saiwai/"+DACHE,"x":-2,"y":2,"big_area":"河北","small_area":1]),
	(["dest_area":"蒙古","dest_id":"menggu","dest_room":"/d/menggu/"+DACHE,"x":-3,"y":3,"big_area":"河北","small_area":1]),
	(["dest_area":"白驼山","dest_id":"baituoshan","dest_room":"/d/baituo/"+DACHE,"x":-1,"y":-2,"big_area":"西域","small_area":1]),
	(["dest_area":"明教","dest_id":"mingjiao","dest_room":"/d/mingjiao/"+DACHE,"x":0,"y":0,"big_area":"西域","small_area":2]),
});

void init()
{
	if (this_player()->query_temp("songtasks/sansishi/wagon_go"))
	return;
	add_action("do_qu","qu");
	add_action("do_xia","xia");
}
int do_xia()
{
	object me=this_player(),place;
	int stay_time;
	if (!me->query_temp("wagon/dest_room_reached"))
	{
		if (place=this_object()->query("from"))
		{
			me->move(place);
		}
		else
		{
			me->move("/d/city/kedian");
		}
	}
	else
	{
		place=me->query_temp("wagon/dest_room_reached");
		if (place->isroom())
		{
			tell_room(place,me->name()+"从"+this_object()->query("short")+"上走了下来。\n");
			me->move(place);
			me->delete_temp("wagon/dest_room_reached");
			if (me->query_temp("wagon/dest_room_reached_time")>0)
			stay_time=time()-me->query_temp("wagon/dest_room_reached_time");
			if (stay_time>120)
			stay_time=120;
			if (stay_time<60)
			stay_time=0;
			if (stay_time>0)
			stay_time+=random(100);
			if (stay_time>0&&MONEY_D->player_pay(me,stay_time))
			tell_object(me,WHT+"到了目的地还久不下车影响了车夫的生意，你心怀歉疚额外给了车夫"+MONEY_D->money_str(stay_time)+"作为补偿。\n"+NOR);
			tell_object(me,"达到了目的地"+HIC+me->query_temp("wagon/to")+NOR+"，你从马车上走了下来。\n");
			destruct(this_object());
			return 1;
		}
		else
		{
			me->move("/d/city/kedian");
		}
	}
	tell_object(me,"你起身走下了马车。\n");
	destruct(this_object());
	return 1;
}
int get_distance(int x1,int y1,int x2,int y2)
{
	float a,b,c,d;
	a=to_float(x1);
	b=to_float(x2);
	c=to_float(y1);
	d=to_float(y2);
	return to_int(sqrt((a-b)*(a-b)+(c-d)*(c-d)));
}
int find_area(string area)
{
	for (int i=0;i<sizeof(destinations);i++)
	{
		if (area==destinations[i]["dest_area"])
		{
			set("x",destinations[i]["x"]);
			set("y",destinations[i]["y"]);
			set("big_area",destinations[i]["big_area"]);
			set("small_area",destinations[i]["small_area"]);
			return 1;
		}
	}
	return 2;
}
int arrive(object me,string dest)
{
	object room,ob=this_object();
	if (!me||!living(me))
	{
		destruct(ob);
		return 1;
	}
	if (environment(me)!=this_object())
	{
		destruct(ob);
		return 1;
	}
	if (room=load_object(dest))
	{
		me->set_temp("wagon/to",AREA_INFO->get_room_area(room));
		me->set_temp("wagon/dest_room_reached",room);
		me->set_temp("wagon/dest_room_reached_time",time());
		tell_object(me,"大车停稳了下来，你可以下车(xia)了。\n");
		return 1;
	}
	me->move("/d/city/kedian");//没找到目的地的情况
	tell_object(me,"大车似乎出了一些故障，你被带回了扬州客店。\n");
	destruct(ob);
	return 1;
}
int abs(int a,int b)
{
	if (a==b)
	{
		return 0;
	}
	else if (a>b)
	{
		return a-b;
	}
	else
	{
		return b-a;
	}
}
int do_qu(string arg)
{
	object ob=this_object(),me=this_player();
	int i,distance,payment;
	string dests="";
	if (ob->query("already_go"))
	{
		return notify_fail("大车已经上路一会了，老老实实地坐着吧。\n");
	}
	if (find_area(ob->query("this_area"))==2)
	{
		return notify_fail("本店暂停营业。\n");
	}
	for (i=0;i<sizeof(destinations);i++)
	{
		if (arg==destinations[i]["dest_area"]||arg==destinations[i]["dest_id"])
		{
			if (destinations[i]["dest_area"]==ob->query("this_area"))
			{
				return notify_fail(destinations[i]["dest_area"]+"不是已经到了吗？\n");
			}
			if (destinations[i]["big_area"]!=ob->query("big_area"))
			{
				return notify_fail("这是马车，可不是渡船！要过江坐船去。\n");
			}
			distance=get_distance(ob->query("x"),ob->query("y"),destinations[i]["x"],destinations[i]["y"]);
			if (distance==0)
			{
				return notify_fail("这里就是你要去的地方吧？\n");
			}
			distance/=2;
			if (distance<1)
			{
				distance=1;
			}
			distance+=abs(ob->query("small_area"),destinations[i]["small_area"]);//有些区域虽然不过河，但是不相连，额外增加一秒时间Zine
			if (!query("price"))
			{
				set("price",100);
			}
			payment=query("price")*distance;
			if (!MONEY_D->player_pay(me,payment))
			{
				tell_object(me,"你身上没有车资"+MONEY_D->money_str(payment)+"，车夫拒绝开车。\n");
				return 1;
			}
			message_vision("在出发前，$N结清了车资共"+MONEY_D->money_str(payment)+"。\n",me);
			me->set_temp("wagon/from",this_object()->query("this_area"));
			remove_call_out("arrive");
			call_out("arrive",distance,me,destinations[i]["dest_room"]);
			ob->set("already_go",1);
			tell_object(me,"马车缓缓开动，向着"+destinations[i]["dest_area"]+"驶去。\n");
			return 1;
		}
		if (ob->query("big_area")==destinations[i]["big_area"])
		dests+=HBCYN+HIW+destinations[i]["dest_area"]+NOR+" ";
	}
	dests+="\n";
	return notify_fail("马车的目的地有"+dests+"请输入qu <地名>到达目的地，输入的地名可以是中文也可以是中文的汉语拼音。\n");
}