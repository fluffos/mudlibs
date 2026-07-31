// usersd.c

#include <ansi.h>
#include <mudlib.h>
#include <dbase.h>

inherit F_DBASE;
inherit F_SAVE;

mapping vips;
mapping qiandao;
mapping paym;
mapping vdata;
mapping daoshi;
mapping tgy;	//申请成为推广员的ID以及点券存储
string *tg_ip; 	//填写推广码的IP存储

void create()
{
	seteuid(ROOT_UID);
	if( !restore() )
	{
		vips= ([]);
		qiandao = ([]);
		vdata = ([]);
		paym = ([]);
		daoshi = ([]);
	}
	if( !mapp(vips) )
		vips = ([]);
	if( !mapp(qiandao) )
		qiandao = ([]);
	if( !mapp(vdata) )
		vdata = ([]);
	if( !mapp(paym) )
		paym = ([]);
	if( !mapp(daoshi) )
		daoshi = ([]);
}

int remove()
{
	save();
	return 1;
}

string query_save_file() { return DATA_DIR + "vipd"; }

int add_order(string name)
{
	if( undefinedp(vips["order"]) ) vips["order"]=({});
	vips["order"] += ({name});
	save();
	return 1;
}

int delete_order(string name)
{
	vips["order"] -= ({name});
	save();
	return 1;
}

mixed set_vips(string prop, mixed data)
{
	if( !mapp(vips ) ) vips = ([]);

	if( strsrch(prop, '/')!=-1 )
		return _set( vips , explode(prop, "/"), data );

	return vips[prop] = data;
}

mixed query_vips(string prop)
{
	mixed data;

	if( !mapp(vips) ) return 0;

	if( undefinedp(vips[prop]) && (strsrch(prop, '/')!=-1) )
		data = _query(vips, explode(prop, "/"));
	else
		data = vips[prop];

	return data;
}

mixed set_daoshi(string prop, mixed data)
{
	if( !mapp(daoshi ) ) daoshi = ([]);

	if( strsrch(prop, '/')!=-1 )
		return _set( daoshi , explode(prop, "/"), data );

	return daoshi[prop] = data;
}

int delete_query_qian(string prop)
{
	if( !mapp(daoshi) ) return 0;

	if( (strsrch(prop, '/')!=-1) )
		return _delete(daoshi, explode(prop, "/"));
	else
	{
		map_delete(daoshi,prop);
		return 1;
	}
}

string *list_daoshi()
{
	mixed data;

	if( !mapp(daoshi) ) return 0;

	return keys(daoshi);
}

mixed query_daoshi(string prop)
{
	mixed data;

	if( !mapp(daoshi) ) return 0;

	if( undefinedp(daoshi[prop]) && (strsrch(prop, '/')!=-1) )
		data = _query(daoshi, explode(prop, "/"));
	else
		data = daoshi[prop];

	return data;
}

mixed set_qian(string prop, mixed data)
{
	if( !mapp(qiandao ) ) qiandao = ([]);

	if(intp(data)&&data > 3000 && strsrch(prop,"/jf_used")==-1)
		data = 3000;
	if( strsrch(prop, '/')!=-1 )
		return _set( qiandao , explode(prop, "/"), data );

	return qiandao[prop] = data;
}

mixed query_qian(string prop)
{
	mixed data;

	if( !mapp(qiandao) ) return 0;

	if( undefinedp(qiandao[prop]) && (strsrch(prop, '/')!=-1) )
		data = _query(qiandao, explode(prop, "/"));
	else
		data = qiandao[prop];

	return data;
}

string *list_qian()
{
	mixed data;

	if( !mapp(qiandao) ) return 0;

	return keys(qiandao);
}

int delete_qian(string prop)
{
	if( !mapp(qiandao) ) return 0;

	if( (strsrch(prop, '/')!=-1) )
		return _delete(qiandao, explode(prop, "/"));
	else
	{
		map_delete(qiandao,prop);
		return 1;
	}
}
mixed set_paym(string prop, mixed data)
{
	if( !mapp(paym) ) paym = ([]);

	if( strsrch(prop, '/')!=-1 )
		return _set( paym , explode(prop, "/"), data );

	return paym[prop] = data;
}

mixed query_paym(string prop)
{
	mixed data;

	if( !mapp(paym) ) return 0;

	if( undefinedp(paym[prop]) && (strsrch(prop, '/')!=-1) )
		data = _query(paym, explode(prop, "/"));
	else
		data = paym[prop];

	return data;
}

int add_paym(string t,mapping paym)
{
	set_paym(t,paym);
	save();
	return 1;
}

int save_vdata(object me)
{
	vdata[me->query("id")] = ([]);
	vdata[me->query("id")]["yuanbao"] = me->query("yuanbao");
	vdata[me->query("id")]["vipgift"] = me->query("zjvip/vipgift");
	vdata[me->query("id")]["all_pay"] = me->query("zjvip/all_pay");
	vdata[me->query("id")]["tap_pinglun"] = me->query("tap_pinglun");	
	save();
	return 1;
}

int restore_vdata(object me)
{
	if(undefinedp(vdata[me->query("id")])) return 1;

	me->set("yuanbao",vdata[me->query("id")]["yuanbao"]);
	me->set("zjvip/vipgift",vdata[me->query("id")]["vipgift"]);
	me->set("zjvip/all_pay",vdata[me->query("id")]["all_pay"]);
	me->set("tap_pinglun",vdata[me->query("id")]["tap_pinglun"]);	
	map_delete(vdata,me->query("id"));
	save();
	return 1;
}


//申请成为推广员
int set_tgy(object player)
{
	string tgy_id;
	if(!player || !userp(player)) return 0;
		
	tgy_id = player->query("id");
	
	
	if(!tgy) tgy = ([ tgy_id:(["jf_all":0,"jf_use":0]) ]);
	else if(!tgy[tgy_id] )
		tgy += ([ tgy_id:(["jf_all":0,"jf_use":0]) ]);
	else return -1;
	this_object()->save();
	return 1;
}

//查询推广员
mapping query_tgy(string tgy_id)
{
	if(!tgy) return 0;
	else return tgy[tgy_id];
}

//新号填写推广码，获得奖励
void use_tgm(string tgy_id,object player)
{
	mapping jfs;
	object ob ;
	string ip = query_ip_number(player);
	if(player->query("combat_exp") < 1500000)
		return tell_object(player,"修为150w才能填写！\n");
	if(!tgy || !(jfs = tgy[tgy_id]) ) return ;
	
	if(sizeof(tg_ip)>0 && member_array(ip,tg_ip) != -1) 
	{
		tell_object(player,"同一个IP地址只能获得一次推广礼包！\n");
		return;
	}
	
	// 

	jfs["jf_all"] += 10000; //填写推广码后增加推广员的点券
	tgy[tgy_id] = jfs;
	if(!tg_ip) tg_ip = ({ip});
	else tg_ip += ({ip});
	this_object()->save();
	
	ob = new("clone/gift/tg_gift");//推广礼包代码
	ob->move(player);
	tell_object(player,"填写推广码成功，你获得礼包【"+ob->name()+"】\n");
	player->set("tgy_id",tgy_id);
}

//点券兑换灵石功能
int tgy_convert(object tgy_ob,int tx_num)
{
	mapping jfs;
	int num1,num2;
	string tgy_id = tgy_ob->query("id");
	if(!tgy || !(jfs = query_tgy(tgy_id)) ) return -1;//没有这个推广员
	num1 = jfs["jf_all"];
	num2 = jfs["jf_use"];
	if(num1 - num2 < tx_num) //剩余点券不够
	return -15;
	jfs["jf_use"] += tx_num;
	tgy[tgy_id] = jfs;
	this_object()->save();
	tx_num = tx_num*3/2;// 点券:灵石的兑换比例(10:1)
	tgy_ob->add("yuanbao",tx_num);
	return tx_num;
}

//修改点券功能
int add_tgy_jf(string tgy_id,int tx_num)
{
	mapping jfs;
	int num1,num2;
	if(!tgy || !(jfs = query_tgy(tgy_id)) ) return -1;//没有这个推广员
	if(tx_num < 0)
	{//扣除点券
		tx_num = abs(tx_num);
		num1 = jfs["jf_all"];
		num2 = jfs["jf_use"];
		if(num1 - num2 < tx_num) //剩余点券不够
			return -15;
		jfs["jf_use"] += tx_num;
	}
	else//增加点券
		jfs["jf_all"] += tx_num;

	tgy[tgy_id] = jfs;
	this_object()->save();
	return tx_num;
}

//重置功能，仅天神权限可用
void reset_tg(object wiz)
{
	tgy = 0;
	tg_ip = 0;
	wiz->delete("tgy_id");
	tell_object(wiz,"当前推广已经重置，你的推广数据也已清空\n");
	this_object()->save();
	wiz->save();
}
