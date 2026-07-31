// topd.c 保存所有玩家的排行数据

#include <ansi.h>

#pragma optimize
#pragma save_binary

inherit F_SAVE;
inherit F_DBASE;

static int ok = 0;

void clean_old()
{
	string *ids;
	int i;

	if(!dbase) return;
	ids = keys(dbase);
	for(i=0;i<sizeof(ids);i++)
	{
		if(time()-dbase[ids[i]]["last"] > 86400*30) {
			
			delete(ids[i]);
		}
	}
}

void create()
{
	seteuid(getuid());
	restore();
	set_heart_beat(5);
	//clean_old();
}

void remove()
{
	save();
}

void mud_shutdown()
{
	save();
}

public string *all_users()
{
	if(!dbase)
		return 0;
	return keys(dbase);
}

public void map_user(object user)
{
	string name;
	mapping info;
	int i;

	info = ([]);
	
	if (wizardp(user) || user->query("id") == "jjyy") {
		name = user->query("id");
		info["name"] = user->query("name");
		info["combat_exp"] = 0;
		info["per"] = 0;
		info["yuanbao"] = 0;
		info["zhuanshi"] = 0;

		info["PKS"] = 0;
		info["gold"] = 0;
		info["shimen"] = 0;
		info["balance"] = 0;
	} else {
		name = user->query("id");
		info["balance"] = user->query("balance");
		info["name"] = user->query("name");
		info["per"] = user->query("per");
		info["all_pay"] = user->query("zjvip/all_pay");
		info["yuanbao"] = user->query("yuanbao");
		info["zhuanshi"] = user->query("zhuanshi");

		info["PKS"] = user->query("combat/PKS");
		info["daoshi_exp"] = user->query("zjvip/daoshi_exp");
		info["dizi_fanli"] = user->query("zjvip/dizi_fanli");
		info["combat_exp"] = user->query("combat_exp");
		info["gold"] = MONEY_D->player_carry(user);
		info["last"] = time();
		info["s_last"] = user->query("shimen/last");
		if(!same_week(info["s_last"],info["last"]))
			user->set("shimen/today",0);
		if(i=user->query("shimen/today")) info["shimen"]=i;
		else info["shimen"]=0;
	}
	set(name,info);
}

public void add_shimen(object user)
{
	string name;
	mapping info;

	if( !mapp(dbase ) ) return;
	name = user->query("id");
	if(undefinedp(dbase[name])) return;
	info = dbase[name];
	if(undefinedp(info["shimen"])) info["shimen"]=1;
	else info["shimen"]+=1;
	set(name,info);
}

public void clear_shimen()
{
	string *names;
	int i;

	if( !mapp(dbase ) ) return;
	names = keys(dbase);
	for(i=0;i<sizeof(names);i++)
	{
		set(names[i]+"/shimen",0);
	}
}

mixed set_user(string prop, mixed data)
{
	if( !mapp(dbase ) ) dbase = ([]);

	if( strsrch(prop, '/')!=-1 )
		return _set( dbase , explode(prop, "/"), data );

	dbase[prop] = data;
	return 1;
}

mixed query_user(string prop)
{
	mixed data;

	if( !mapp(dbase) ) return 0;

	if( undefinedp(dbase[prop]) && (strsrch(prop, '/')!=-1) )
		data = _query(dbase, explode(prop, "/"));
	else
	{
		data = dbase[prop];
	}

	return data;
}

string get_name(string id)
{
	string data;

	if( !mapp(dbase) ) return 0;

	if( undefinedp(dbase[id]) )
		data = "无名氏";
	else
	{
		data = dbase[id]["name"];
	}

	return data;
}
void heart_beat()
{
	int GMT = time();
	string d, times;
	int h, s;
	mixed *local;
	int day, min;
	/*
	times = ctime(GMT);
	//Sun(星期日) Mon(星期一)  Tue(星期二)  Wed(星期三)  Thu(星期四)  Fri(星期五)  Sat(星期六)
	d = times[0..2];//星期
	h = to_int(times[10..12]);//时
	s = to_int(times[14..15]);//分
	*/
	
	local = localtime(time());
	//tell_object(find_player("jjyy"),sprintf("local==%O\n", local));
	day = local[6];//星期
	min = local[0];//秒
	//if ((d == "Mon") &&(h == 0) &&(s == 0) && !ok) {
	if (day == 1 && !ok) {
		clear_shimen();
		ok = 1;
	} else if (day != 1)
		ok = 0;
	if(min%30==0) {
		save();
	}
}

string query_save_file() { return DATA_DIR "topd"; }
