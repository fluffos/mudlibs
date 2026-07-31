//edit by rock
//2008.10.16
//本文件不会被克隆

#include <ansi.h>
#include <localtime.h>
#include "/d/mirror/sys/list.h"

#define MAX_ROOM_INDEX 20
#define OFFICE_NPC     "/d/mirror/npc/office"
#define MIRROR_MEMORY  "/d/mirror/sys/memory"
#define KILLER_NPC     "/d/mirror/npc/killer"
#define BOSS_NPC       "/d/mirror/npc/boss"
#define MAX_KILLER_INDEX 1

//全局变量
int make_room_index;
int ob_time;

//函数声明
void check_time();
int mirror(object* player,object leader);
void del_npc();
void mirror_ok(object me);
varargs void make_killer(object *player,int boss);

//函数：查询现有量镜像数量
int query_room_amount() { return make_room_index; }

//初始化
void create() { check_time(); }

//检查时间
void check_time()
{
	object npc;

	if(!ob_time)
	{
		//2小时一次
		ob_time = time()+2*3600;
	}
//tell_object(find_player("rock"),"\n时间.......\n");
	if(ob_time <= time())
	{
		//活动通告
		//克隆NPC
		npc = new(OFFICE_NPC);
		if(npc)
		{
			//CHANNEL_D->do_channel( npc, "chat", "扶桑侵犯中原，镜像已经打开，望各位英雄前来救国。\n");
			//放到 /d/city/wumiao
			npc->move("/d/wizard/wizard_room");
			//副本最大数量清零
			make_room_index = 0;
			//激活收起NPC(10分钟)
			call_out("del_npc",600);
			//重设时间
			ob_time = time()+2*3600;
		}
	}
	//时间没到就继续循环
	if((time() + 1800) >= ob_time)
	{
		call_out("check_time",600);
	}
	else if((time() + 600) >= ob_time)
	{
		call_out("check_time",60);
	}
	else call_out("check_time",1800);
}

//NPC调用，创造镜像世界
int mirror(object* player,object leader)
{
	object maps,memory,start_room;
	int i,size,j,index;
	mixed time;
	string fileName;

	if(!player || make_room_index >= MAX_ROOM_INDEX || !leader ) return 0;

	//创建内存
	if(!memory = new(MIRROR_MEMORY)) return 0;

	memory->set("leader",leader);
	//判断所有玩家是否符合要求
	size = sizeof(player);
	for(i=0;i<size;i++)
	{
		if(!player[i] || !userp(player[i]) || !living(player[i]) || !pointerp(player[i]->query_team()))
		{
			destruct(memory);
			return 0;//continue;
		}

		//找出队长
		if(player[i]->is_team_leader())
		{
			leader = player[i];

		}
		memory->set(sprintf("user_id/%d",i),player[i]->query("id"));
		memory->set(sprintf("user/%d",i),player[i]);
		player[i]->set_temp("mirror/mirror_memory",memory);

		tell_object(player[i],HIY"【武动仙途】正在为你制造副本，请稍候......\n"NOR);
		player[i]->disable_player("<进入镜像中>");
		player[i]->set_temp("block_msg/all",1);
	}

	//制造世界
	size = sizeof(mirror_maps);
	for(j=0;j<size;j++)
	{
		maps = new(mirror_maps[j]);
		if(maps)
		{
			//所有地图进memory
			memory->set(sprintf("maps/%d",j),maps);
			sscanf(mirror_maps[j],"/d/mirror/%s",fileName);
			memory->set(fileName,maps);
			maps->set("memory",memory);
			if(maps->query("short") == "中央广场")
			{
				start_room = maps;
			}
			index ++;
		}
		//tell_object(find_player("rock"),sprintf("new_mirror: %d\n",j));
	}
	if(index < 69 || !start_room)
	{
		size = sizeof(player);
		for(i=0;i<size;i++)
		{
			player[i]->enable_player();
			player[i]->delete_temp("block_msg");
			tell_object(player[i],"Error: 镜像制造失败，请联系巫师。\n");
		}

		memory->delete_map();
		destruct(memory);
		time = localtime(time());
		log_file("mirror",sprintf("%d月%d日 %d:%d  虚拟空间创建失败。\n",1+time[LT_MON],time[LT_MDAY],time[LT_HOUR],time[LT_MIN]));
		return 0;
	}
	else
	{
		make_room_index ++;

		size = sizeof(player);
		for(i=0;i<size;i++)
		{
			player[i]->set_temp("mirror/start_room",start_room);
			call_out("mirror_ok",20,player[i]);
		}
		memory->set("mirror_time",time()+900); //任务结束时间
		memory->set("open_time",time());        //任务开始时间
		memory->len_exits(); //连通地图(小心)
		memory->heart(1);  //启动心跳
		call_out("make_killer",60,player);   //一分钟后开始刷怪
	}
}

void mirror_ok(object me)
{
	object start_room,memory;
	int i,size;
	mapping user_id;

	if(!me) return;

	start_room = (object)me->query_temp("mirror/start_room");
	memory = (object)me->query_temp("mirror/mirror_memory");

	me->enable_player();
	me->delete_temp("block_msg");
	//me->add("fuben",1);

	//没有开始房间
	if(!start_room)
	{
		tell_object(me,"坐标错误，你没能进入镜像。\n");
		user_id = (mapping)memory->query("user_id");
		size = sizeof(user_id);

		for(i=0;i<size;i++)
		{
			if(user_id[sprintf("%d",i)] == me->query("id"))
			{
				memory->set(sprintf("user_id/%d",i),0);
				memory->set(sprintf("user/%d",i),0);
				break;
			}
		}
		return;
	}
	else
	{
		me->move(start_room);
		tell_object(me,HIY"【武动仙途】请各位英雄做好准备，30秒后心魔将到达。\n"NOR); //广告
	}
}

varargs void make_killer(object *player,int boss)
{
	int i,size,killer_level=0,all_level=0,all_exp=0,killer_exp=0;
	object killer,memory,rand_map,n1;
	mapping maps;
	//tell_object(find_player("rock"),sprintf("debug: player = %O\n",player));
	if(!player) return;

	//平均等级
	size = sizeof(player);
	for(i=0;i<size;i++)
	{
      if(!player[i] || !userp(player[i])) continue;
		all_level += player[i]->query("jym_level/level");
		all_exp += player[i]->query("combat_exp");
	}
	killer_exp = all_exp/size;
	killer_level = all_level/size;

	memory = (object)player[0]->query_temp("mirror/mirror_memory");
	if(!memory) return; //防抱错

	//放置主动攻击NPC
	if(!boss) i = MAX_KILLER_INDEX;
	else i = 1;

	while(i--)
	{
		if(memory->query("npc_amount",1) >= 201 ) break;

		if(!boss)
		{
			if(killer = new("/d/mirror/nandu1/xueyue"))
			{
				memory->add("npc_amount",1);
				maps = memory->query("maps");
				size = sizeof(maps);
				rand_map = (object)maps[sprintf("%d",random(size))];  //随机地图

//				killer->set("jym_level",killer_level);
//				killer->set("combat_exp",killer_exp);

				killer->move(rand_map);
				
                 n1 = new("/d/mirror/nandu1/zhaoge");
				n1->move(rand_map);}
		}
		else
		{
			if(killer = new(BOSS_NPC))
			{
				maps = memory->query("maps");
				size = sizeof(maps);
				rand_map = (object)maps[sprintf("%d",random(size))];  //随机地图

				killer->set("jym_level",killer_level*(2+random(9)));
				killer->set("combat_exp",killer_exp);

				killer->move(rand_map);
			}
		}
	}
	//tell_object(find_player("rock"),"????\n");
}

//收起 NPC
void del_npc()
{
	object *office;
	int i,size;

	office = children("/d/mirror/npc/office");

	if(!office) return;

	size = sizeof(office);
	for(i=0;i<size;i++)
	{
		destruct(office[i]);
	}
}
