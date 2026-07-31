//by luoyun.微笑

#include <ansi.h>

inherit F_DBASE;
varargs int des_fuben(string fuben_sn, int indx);
//副本处理列表
mapping fuben_list = ([
	"heifeng":	([
				"name":"黑风寨",  //名字
				"time":1800, //时间
				"team":5, //最多几人组队进入
			]),
	"wolong":	([
				"name":"卧龙堡",
				"time":1800,
				"team":1,
			]),
    "wuguan":	([
				"name":"武馆试炼",
				"time":1800,
				"team":1,
			]),
    "dangkou":	([
				"name":"荡除倭寇",
				"time":1800,
				"team":1,
			]),
	"huangling" : ([
				"name":"皇陵探险",
				"time":1800,
				"team":1,
			]),
	"poyuan" : ([
				"name":"单骑破元",
				"time":1800,
				"team":1,
			]),
	"jinbing" : ([
				"name":"伏击金兵",
				"time":1800,
				"team":1,
			]),
	"jinbing1" : ([
				"name":"虚拟空间1",
				"time":1800,
				"team":1,
			]),
	"migong" : ([
				"name":"节日副本",
				"time":1800,
				"team":1,
			]),
   "shushan":   ([
				"name":"蜀山",
				"time":1800,
				"team":4,
			]),
  "shushanec":   ([
				"name":"天宫",
				"time":1800,
				"team":4,
			]),
   "tiaozhan":	([
				"name":"妖塔",
				"time":1800,
				"team":1,
			]),
    "cangjingge":	([
				"name":"藏经阁",
				"time":1800,
				"team":1,
            ]),
	"tiguan":	([
				"name":"偷袭武馆",
				"time":1800,
				"team":1,
            ]),
]);

mapping fuben_open;
mapping fuben_where;

void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "副本精灵");
	CHANNEL_D->do_channel( this_object(), "sys", "副本系统已经启动。");
	fuben_open = ([]);
	fuben_where = ([]);
	set_heart_beat(30);
}
//心跳处理，检查副本名称和时间
void heart_beat()
{
	string *fuben, name;
	int i, time, k, j, is_ok;
	string *room_all;
	string *room;
	object *all_inv, ob;
	
	fuben = keys(fuben_open);
	for(i=0;i<sizeof(fuben);i++)
	{
		name = fuben_open[fuben[i]]["name"];
		time = fuben_open[fuben[i]]["time"];//副本开启时间
		if((time()-time)>=fuben_list[name]["time"])//计算时间是否剩余
			des_fuben(fuben[i]);//无indx参数，副本时间到，清除物件
	}
}
//创建副本函数name传进的副本名称
int create_fuben(object me, string name)
{
	string *files,*dirs,fuben_sn,*list;
	object room;
	mapping fb;
	int i,j,k;

	if(!mapp(fuben_list[name]))
	{
		tell_object(me,"创建失败，无此副本！\n");
		return 0;
	}
	files = get_dir("/d/fuben/"+name+"/");
	list = ({});
	fb = ([]);
	fuben_sn = sprintf("%s_%d",me->query("id"),time());
	for(i=0;i<sizeof(files);i++)
	{
		if(file_size("/d/fuben/"+name+"/"+files[i])>0)
		{
			room = new("/d/fuben/"+name+"/"+files[i]);

			room->set("fuben_sn",fuben_sn);
			list += ({ file_name(room) });
			if(files[i]=="enter.c")
			{
				room->set("exits/out",base_name(environment(me)));
				fb["enter"] = file_name(room);
			}
		}
	}
	//联通地图
	for(i=0;i<sizeof(list);i++)
	{
		if(room=find_object(list[i]))
		{
			dirs = keys(room->query("exits"));
			for(j=0;j<sizeof(dirs);j++)
			{
				for(k=0;k<sizeof(list);k++)
				{
					if (strsrch(list[k], room->query("exits/"+dirs[j])+"#")==0) {
						
						room->set("exits/"+dirs[j], list[k]);
						
						if (room->query("anniu_hide"))
						{
							//设置暗室备用的room
							if (dirs[j] == "down") {
								room->set("bei_path", list[k]);
								room->delete("exits/down");
							}
						}
					}
				}
			}
		}
	}

	if(fuben_where[base_name(environment(me))])
		fuben_where[base_name(environment(me))] += ({ fuben_sn });
	else
		fuben_where[base_name(environment(me))] = ({ fuben_sn });

	fb["files"] = list;
	fb["owner"] = me->query("id");
	fb["time"] = time();//记录开启时间
	fb["name"] = name;
	fb["where"] = base_name(environment(me));
	fuben_open[fuben_sn] = fb;
	log_file("fuben_d/fuben", sprintf("%s %s %s\n", me->query("name") + "("+me->query("id")+")", 
		"创建了"+name,
		"位置"+fb["where"]));
	return 1;
}

string *query_where(string where)
{
	if(fuben_where[where]&&sizeof(fuben_where[where]))
		return fuben_where[where];
	else
		return 0;
}

mapping query_info(string fuben)
{
	mapping info;

	if(!mapp(info=fuben_open[fuben]))
		return 0;

	info["cname"] = fuben_list[info["name"]]["name"];
	info["team"] = fuben_list[info["name"]]["team"];
	return info;
}

varargs int des_fuben(string fuben_sn, int indx)
{
	mapping info;
	string *list;
	object room,*inv;
	int i,j;

	info = fuben_open[fuben_sn];
	list = info["files"];
	for(i=0;i<sizeof(list);i++)
	{
		if(!objectp(room = find_object(list[i]))) continue;
		inv = all_inventory(room);
		for(j=0;j<sizeof(inv);j++)
		{
			if(userp(inv[j]))
			{ 
				if (!indx)
					tell_object(inv[j],HIG"你在"+fuben_list[info["name"]]["name"]+"内呆得太久了，不得不退了出来。"NOR"\n");
				else
					tell_object(inv[j],HIG"你感觉"+fuben_list[info["name"]]["name"]+"内太恐怖了，还是先撤离吧。"NOR"\n");
				
				inv[j]->move("where");
			}
		}
		destruct(room);
	}
	fuben_where[info["where"]] -= ({ fuben_sn });
	map_delete(fuben_open, fuben_sn);
	if (sizeof(fuben_where[info["where"]]) < 1)
		map_delete(fuben_where, info["where"]);
	
	return 1;
}

