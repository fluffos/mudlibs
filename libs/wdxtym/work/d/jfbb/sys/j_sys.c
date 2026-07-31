#include <ansi.h>
#include <localtime.h>
#include "/d/jfbb/sys/j.h"//房间的数组

#define MAX_ROOM_INDEX 100
#define JOFFICE_NPC     "/d/jfbb/npc/joffice"//副本的传送npc
#define jfbb_JMEM        "/d/jfbb/sys/jmem"//内存管理器
#define JKILLER_NPC     "/d/jfbb/npc/jkiller"//普通怪物
#define JBOSS_NPC       "/d/jfbb/npc/jboss"//boss
#define MAX_KILLER_INDEX 200//npc的总个数

//全局变量
int make_room_index;//副本的最大数量
int ob_time;

//函数声明
//void check_time();取消
private int copy_skill(object me, object ob);
int jfbb(object leader);
//void del_npc();取消
void room_ok(object me);
varargs void make_jkiller(object *player,int jboss);

//函数：查询现有量镜像数量
int query_room_amount() { return make_room_index; }




//NPC调用，创造镜像世界
int jfbb(object leader)//单人
{
	object maps,jmem,start_room;
	int i,size,j,index;
	mixed time;
	string fileName;


	//创建内存
	if(!jmem = new(jfbb_JMEM))
	{
	write("调用内存管理器失败");
	 return 0;
	 }
	jmem->set("leader",leader);
	//判断所有玩家是否符合要求
		if(!leader || !userp(leader) || !living(leader))
		{
			destruct(jmem);			
		tell_object(leader,HIY"【诸子百家】正在为你制造中级副本时检查条件不满足，请调整队伍重试......\n"NOR);
			return 0;//continue;
}
		jmem->set(sprintf("user_id/%d",i),leader->query("id"));
		jmem->set(sprintf("user/%d",i),leader);
		leader->set_temp("jfbb/jfbb_jmem",jmem);//玩家的临时副本参数

		tell_object(leader,HIY"【诸子百家】正在为你制造中级副本挑战幻心密洞，请稍候......\n"NOR);
	leader->disable_player("<进入镜像中>");
		leader->set_temp("block_msg/all",1);

	//制造世界
	size = sizeof(room_maps);//读取个数
	for(j=0;j<size;j++)//开始循环
	{
		maps = new(room_maps[j]);//制作房间
		if(maps)
		{
			//所有地图进jmem
			jmem->set(sprintf("maps/%d",j),maps);
			sscanf(room_maps[j],"/d/jfbb/room/%s",fileName);
			jmem->set(fileName,maps);
			maps->set("jmem",jmem);
			if(maps->query("short") == "入口")//如果这个房间的short是入口，那么作为初始房间
			{
				start_room = maps;
			}
			index ++;
		}
	}
//  tell_object(find_player("jerry"),sprintf("DEBUG: %O",start_room));
	if(index < size || !start_room)
	{
			leader->enable_player();
			leader->delete_temp("block_msg");
			tell_object(leader,"Error: 中级副本JOB制造失败，请联系巫师。\n");
			write("条件缺少.");
		jmem->delete_map();
		destruct(jmem);
		time = localtime(time());
		log_file("jfbb",sprintf("%d月%d日 %d:%d  虚拟空间创建失败。\n",1+time[LT_MON],time[LT_MDAY],time[LT_HOUR],time[LT_MIN]));
		write("条件缺少");
		return 0;
	}
	else
	{
		make_room_index ++;

			leader->set_temp("room/start_room",start_room);
			call_out("room_ok",5,leader);
		jmem->set("jfbb_time",time()+ 10800); //任务结束时间
		jmem->set("open_time",time());        //任务开始时间
		jmem->len_1(); //连通地图(小心)
		jmem->heart(1);  //启动心跳
		call_out("make_jkiller",5,leader);   //一分钟后开始刷怪
	}
	return 1;
}

//制作房间
void room_ok(object me)
{
	object start_room,jmem;
	int i,size;
	mapping user_id;

	if(!me) return;

	start_room = (object)me->query_temp("room/start_room");
	jmem = (object)me->query_temp("jfbb/jfbb_jmem");

	me->enable_player();
	me->delete_temp("block_msg");

	//没有开始房间
	if(!start_room)
	{
		tell_object(me,"坐标错误，你有初始房间，没能进入镜像。\n");
		user_id = (mapping)jmem->query("user_id");
		size = sizeof(user_id);

		for(i=0;i<size;i++)
		{
			if(user_id[sprintf("%d",i)] == me->query("id"))//清除副本标识
			{
				jmem->set(sprintf("user_id/%d",i),0);
				jmem->set(sprintf("user/%d",i),0);
				break;
			}
		}
		return;
	}
	else//成功传送
	{
		me->move(start_room);
		tell_object(me,HIY"【诸子百家】请各位英雄做好准备，30秒后中级副本挑战幻心密洞起动。\n"NOR); //广告
	}
}

varargs void make_jkiller(object player,int jboss)//制作房间
{
	int i,size,killer_level=0,all_level=0,all_exp=0,killer_exp=0,skillk;
	object killer,jmem,rand_map;
	mapping maps;
	skillk = player->query_skill("force",1);
	skillk = skillk/2;
	skillk += random(skillk);

	if(!player) return;

	jmem = (object)player->query_temp("jfbb/jfbb_jmem");
	if(!jmem) return; //防抱错
	//放置主动攻击NPC
	if(!jboss) i = MAX_KILLER_INDEX;
	else i = 1;

	while(i--)
	{
		if(jmem->query("npc_amount",1) >= 1201) break;		
		if(!jboss)
		{
			if(killer = new(JKILLER_NPC))
			{
				jmem->add("npc_amount",1);
				maps = jmem->query("maps");
				size = sizeof(maps);
				rand_map = (object)maps[sprintf("%d",random(size))];  //随机地图
      	copy_skill(killer,player);//开始复制玩家技能
		killer->set("name",player->query("name")+"的幻心");
				killer->move(rand_map);
			}
		}
		else
		{
			if(killer = new(JBOSS_NPC))
			{
				maps = jmem->query("maps");
				size = sizeof(maps);
				rand_map = (object)maps[sprintf("%d",random(size))];  //随机地图

				killer->move(rand_map);
			}
		}
	}
}
//物件与物件之间的复制技能
private int copy_skill(object me, object ob)
{
	mapping hp_status, skill_status, map_status, prepare_status;
	mapping my;
	string *sname, *mname, *pname;
	int i, temp;

	if (mapp(skill_status = me->query_skills()))
	{
		skill_status = me->query_skills();
		sname = keys(skill_status);

		temp = sizeof(skill_status);
		for (i = 0; i < temp; i++)
			me->delete_skill(sname[i]);
	}

	if (mapp(skill_status = ob->query_skills()))
	{
		skill_status = ob->query_skills();
		sname = keys(skill_status);

		for (i = 0; i < sizeof(skill_status); i++)
			me->set_skill(sname[i], skill_status[sname[i]]);
	}

	if (mapp(map_status = me->query_skill_map()))
	{
		mname = keys(map_status);

		temp = sizeof(map_status);
		for (i = 0; i < temp; i++)
			me->map_skill(mname[i]);
	}

	if (mapp(map_status = ob->query_skill_map()))
	{
		mname = keys(map_status);

		for(i = 0; i < sizeof(map_status); i++)
			me->map_skill(mname[i], map_status[mname[i]]);
	}

	if (mapp(prepare_status = me->query_skill_prepare()))
	{
		pname = keys(prepare_status);

		temp = sizeof(prepare_status);
		for(i = 0; i < temp; i++)
			me->prepare_skill(pname[i]);
	}

	if (mapp(prepare_status = ob->query_skill_prepare()))
	{
		pname = keys(prepare_status);

		for(i = 0; i < sizeof(prepare_status); i++)
			me->prepare_skill(pname[i], prepare_status[pname[i]]);
	}

	hp_status = ob->query_entire_dbase();
	my = me->query_entire_dbase();

	my["str"] = hp_status["str"];
	my["int"] = hp_status["int"];
	my["con"] = hp_status["con"];
	my["dex"] = hp_status["dex"];

	my["max_qi"]     = hp_status["max_qi"];
	my["eff_qi"]     = hp_status["eff_qi"];
	my["qi"]	 = hp_status["qi"];
	my["max_jing"]   = hp_status["max_jing"];
	my["eff_jing"]   = hp_status["eff_jing"];
	my["jing"]       = hp_status["jing"];
	my["max_neili"]  = hp_status["max_neili"];
	my["neili"]      = hp_status["neili"];
	my["jiali"]      = hp_status["jiali"];
	my["combat_exp"] = hp_status["combat_exp"];

	me->reset_action();
	return 1;
}

