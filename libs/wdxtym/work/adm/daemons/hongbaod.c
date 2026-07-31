//hongbaod.c
//抢/发红包系统
inherit F_DBASE;

//记录发的红包数据
nosave mapping all_gift=([]);
//红包最多保留时长(秒)
nosave int max_time = 5 *60;
//同时最多只能存在多少个未领红包，当超过此数量时，无法发新红包
nosave int max_index = 50;
void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "老魔");
	CHANNEL_D->do_channel( this_object(), "sys", "红包精灵已经启动。");
	set_heart_beat(10);//10秒心跳一次
}
int clean_up()
{
	return 1;
}

//心跳执行检查，没领完的红包自动返回给玩家
void heart_beat(int coerce)
{
	string id, name, type, *list, index, msg ="", str, type_a;
	int num;
	int time, times;
	int i, is_load,huangjing;
	object ob;
//	huangjing = 
	
	if (i = sizeof(all_gift)) {
		list = keys(all_gift);
		times = time();
		while(i--) {
			index = list[i];
			time = all_gift[index]["time"];
			num = all_gift[index]["num"];
			id = all_gift[index]["id"];
			name = all_gift[index]["name"];
			type = all_gift[index]["type"];
			if (num <1) {
				msg += sprintf("红包为空:%s，删除:%s 数量:%d\n", name+"("+id+")", type, num);
				//空红包，删除
				map_delete(all_gift, index);
				continue;
			}
			//带了强制参数，跳过检测时间，强制将未领完的红包返还给玩家
			if (!coerce) {
				//没有超时的，跳过
				if (times < time +max_time) continue;
			}
			if (!objectp(ob = find_player(id))) {
				ob = UPDATE_D->global_find_player(id);
				is_load = 1;
			}
			if (!objectp(ob))  {
				msg += sprintf("找不到红包主人:%s，删除:%s 数量:%d\n", name+"("+id+")", type, num);
				map_delete(all_gift, index);
				continue;
			}
			if (type == "yuanbao")
				ob->add("yuanbao", num);
			else
			if (type == "balance")
				ob->add("balance", num);
			else
			if (type == "hj")
				ob->add("balance", num*10000);
			/*else
			if (type == "hj")
				ob->add("hj", num);*/
			if (type == "balance") type_a = "铜板";
			else if (type == "yuanbao") type_a = "灵石"; 
			else if (type == "hj") type_a = "黄金"; 
			else type_a = type;
			
			str = sprintf("红包未被领完:%s，返还给玩家:%s 数量:%d\n", type_a, name+"("+id+")", num);
			ob->save();
			if (is_load) {
				destruct(ob);
			} else
				tell_object(ob, str);
			msg += ctime(time())+str;
			map_delete(all_gift, index);
		}
		if (sizeof(msg))
			log_file("hongbaod.log", "时间:" + ctime(time())+" "+msg);
	}
}

//系统重启或抢红包的时间已经结束，如果有没人领的红包，自动返回给发红包的主人。
int mud_shutdown()
{
	heart_beat(1);
	set_heart_beat(0);

	return 1;
}

//发红包me=物件｜type=类型｜num=分成多少份｜number=发多少总数
int do_fahongbao(object me, string type, int num, int number)
{
	int yb_max;
	int yp_max;
	mixed time;
	string type_a, unit, index;
	
	if (!me) return 0;
	
	if (sizeof(all_gift) >=max_index) {
		tell_object(me, sprintf("红包还有好多没人领取，暂时无法发放。\n"));
		return 0;
	}
	if (number <1) {
		tell_object(me, INPUTTXT("红包至少要分成两份。"ZJBR"格式(灵石 数量 份数)。","fahongbao $txt#")+"\n");
		return 0;
	}
	if (num >100000000000000) {
		tell_object(me, INPUTTXT("红包里面最多只能装10000数量。"ZJBR"格式(灵石 数量 份数)。","fahongbao $txt#")+"\n");
		return 0;
	}
	if (number >num) {
		tell_object(me, INPUTTXT("红包份数过多，数量不够分的。"ZJBR"格式(灵石 数量 份数)。","fahongbao $txt#")+"\n");
		return 0;
	}
	if (number >100) {
		tell_object(me, INPUTTXT("红包最多只能分成一百份。"ZJBR"格式(灵石 数量 份数)。","fahongbao $txt#")+"\n");
		return 0;
	}
	if (type != "yuanbao" && type != "balance" && type != "hj") {
		tell_object(me, sprintf("你想发什么红包(只能发灵石、铜板或黄金)？\n"));
		return 0;
	}
	if (num <1) {
		tell_object(me, INPUTTXT("红包里面的数量不能低于2？"ZJBR"格式(灵石 数量 份数)。","fahongbao $txt#")+"\n");
		return 0;
	}

	if (type == "yuanbao") {
		yb_max = me->query("yuanbao");
		if (yb_max <1) {
			tell_object(me, sprintf("你没有灵石。\n"));
			return 0;
		}
		if (num >yb_max) {
			tell_object(me, sprintf("你没有这么多灵石，少发一点吧。\n"));
			return 0;
		}
		type_a = "灵石";
		unit = "个";
	} else
	if (type == "balance") {
		yb_max = me->query("balance");
		if (yb_max <1) {
			tell_object(me, sprintf("你没有铜板。\n"));
			return 0;
		}
		if (num >yb_max) {
			tell_object(me, sprintf("你没有这么多铜板，少发一点吧。\n"));
			return 0;
		}
		type_a = "铜板";
		unit = "个";
	} else
	if (type == "hj") {
		yb_max = me->query("balance")/10000;
		if (yb_max <1) {
			tell_object(me, sprintf("你没有黄金。\n"));
			return 0;
		}
		if (num >yb_max) {
			tell_object(me, sprintf("你没有这么多黄金，少发一点吧。\n"));
			return 0;
		}
		type_a = "黄金";
		unit = "个";
	}

	time = time();
	index = save_variable(time);
	if (all_gift[index]) {
		time += 1;
		index = save_variable(time);
	} 
	//记录发红包的数据
	all_gift[index] = (["time" :time, "id": me->query("id"), "name" :me->query("name"),
								"type" :type, "num" :num, "number" :number, "qiang" : ({}), ]);
	tell_object(me, sprintf("你将"+num+unit+type_a+"分成"+number+"份红包发放了出去。\n"));
									
	//公共频道发送信息，提供按钮供大家抢。
	CHANNEL_D->do_channel(this_object(), "chat", me->query("name")+"，发出"
										+number+"个"ZJURL("cmds:qianghb "+time)+HIR+ZJSIZE(22)+type_a+"红包"NOR"。");
   if(type == "hj")
	   me->add("balance", -num*10000);
   else me->add(type, -num);
	return 1;
}
//测试用
int set_hongbao()
{
	int time = 1111;
	
	all_gift[time] = (["time" :time, "id": "alll", "name" :"椰白",
				"type" :"yuanbao", "num" :10, "number" :2, "qiang" : ({}), ]);
	return 1;
}
//查询红包数据
mapping query_hongbao()
{
	return all_gift;
}
//抢红包me=物件｜time=红包的索引
int do_qianghongbao(object me, string index) 
{
	int max_num, num, number;
	string myid, id, name, type, type_a, unit, *qiang_list, msg;
		
	if (!me || !index) return 0;
	if (!sizeof(all_gift) || !mapp(all_gift) || !all_gift[index]) {
		tell_object(me, sprintf("没有这个红包或已经被人抢光了。\n"));
		return 0;
	}
	//抢红包的数据
	qiang_list = all_gift[index]["qiang"];
	if (!arrayp(qiang_list)) qiang_list = ({});
		
	myid = me->query("id");
	//已经领过了，不给再次领

	if (member_array(myid, qiang_list) != -1) {
		tell_object(me, sprintf("你已经抢过这个红包了。\n"));
		return 0;
	}

	id =all_gift[index]["id"];
	name =all_gift[index]["name"];
	type =all_gift[index]["type"];
	max_num =all_gift[index]["num"];
	number =all_gift[index]["number"];
	
	//if (myid == id) {
		//tell_object(me, sprintf("你不能抢自己发的红包。\n"));
		//return 0;
	//}
	if (max_num <1) {
		tell_object(me, sprintf("这个红包已经被抢光了。\n"));
		map_delete(all_gift, index);
		return 0;
	}
		
	//随机分派红包内的数量
	if (number >1) {
		num =random(max_num /number *2);
		if (num <1) num = 1;
	}
	else
		num =max_num;
	
	if (type == "yuanbao") {
		type_a = "灵石";
		unit = "个";
		
		me->add("yuanbao", num);
	} else 
	if (type == "balance") {
		type_a = "铜板";
		unit = "个";
		
		me->add("balance", num);
	} else 
	if (type == "hj") {
		type_a = "黄金";
		unit = "个";
		
		me->add("balance", num*10000);
	} 
	
	all_gift[index]["num"] -= num;
	all_gift[index]["number"] -= 1;
	//红包空了，清除数据
	if (all_gift[index]["num"] <1) {
		map_delete(all_gift, index);
	} else
		all_gift[index]["qiang"] += ({myid});

	msg = sprintf("恭喜你成功抢到"+name+"发的红包，拆开一看，原来是"+type_a+""+num+""+unit+"。\n");
	CHANNEL_D->do_channel(this_object(), "chat", me->query("name")+"抢到"+name+"发的红包，里面是"+type_a+""+num+""+unit+"。\n");
	
	tell_object(me, msg);
	return 1;
}


