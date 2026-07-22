//edit by Jerry
//2008.11.17
//本文件不会被克隆

#include <ansi.h>
#include <localtime.h>
#include "/d/jfb/sys/j.h"

#define MAX_ROOM_INDEX 20
#define JOFFICE_NPC     "/d/jfb/npc/joffice"
#define JFB_JMEM        "/d/jfb/sys/jmem"
#define JKILLER_NPC     "/d/jfb/npc/jkiller"
#define JBOSS_NPC       "/d/jfb/npc/jboss"
#define MAX_KILLER_INDEX 200

//全局变量
int make_room_index;
int ob_time;

//函数声明
void check_time();
int jfb(object* player,object leader);
void del_npc();
void room_ok(object me);
varargs void make_jkiller(object *player,int jboss);

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
		//3小时一次
		ob_time = time()+3*3600;
	}
//tell_object(find_player("jerry"),"\n时间.......\n");
	if(ob_time <= time())
	{
		//活动通告
		//克隆NPC
		npc = new(JOFFICE_NPC);
		if(npc)
		{
			CHANNEL_D->do_channel( npc, "chat", BLINK+HIC"心魔镜像已经打开，望各位英雄前来救回被剥夺魂魄的士兵。\n"NOR);
			//放到 /d/city/chatroom
			npc->move("/d/city/chatroom");
			//副本最大数量清零
			make_room_index = 0;
			//激活收起NPC(10分钟)
			call_out("del_npc",600);
			//重设时间
			ob_time = time()+3*3600;
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
	else call_out("check_time",60);

}



//NPC调用，创造镜像世界
int jfb(object* player,object leader)
{
	object maps,jmem,start_room;
	int i,size,j,index;
	mixed time;
	string fileName;

	if(!player || make_room_index >= MAX_ROOM_INDEX || !leader ) return 0;

	//创建内存
	if(!jmem = new(JFB_JMEM)) return 0;

	jmem->set("leader",leader);
	//判断所有玩家是否符合要求
	size = sizeof(player);
	for(i=0;i<size;i++)
	{
		if(!player[i] || !userp(player[i]) || !living(player[i]) || !pointerp(player[i]->query_team()))
		{
			destruct(jmem);
			return 0;//continue;
		}

		//找出队长
		if(player[i]->is_team_leader())
		{
			leader = player[i];
			
		}
		jmem->set(sprintf("user_id/%d",i),player[i]->query("id"));
		jmem->set(sprintf("user/%d",i),player[i]);
		player[i]->set_temp("jfb/jfb_jmem",jmem);

		tell_object(player[i],HIY"【江湖】正在为你制造中级副本挑战心魔，请稍候......\n"NOR);
		player[i]->disable_player("<进入镜像中>");
		player[i]->set_temp("block_msg/all",1);
	}

	//制造世界
	size = sizeof(room_maps);
	for(j=0;j<size;j++)
	{
		maps = new(room_maps[j]);
		if(maps)
		{
			//所有地图进jmem
			jmem->set(sprintf("maps/%d",j),maps);
			sscanf(room_maps[j],"/d/jfb/room/%s",fileName);
			jmem->set(fileName,maps);
			maps->set("jmem",jmem);
//  tell_object(find_player("jerry"),sprintf("DEBUG: name = %O maps = %O\n",maps->query("short"),maps));
			if(maps->query("short") == "入口")
			{
				start_room = maps;
			}
			index ++;
		}
	}
//  tell_object(find_player("jerry"),sprintf("DEBUG: %O",start_room));
	if(index < size || !start_room)
	{
		size = sizeof(player);
		for(i=0;i<size;i++)
		{
			player[i]->enable_player();
			player[i]->delete_temp("block_msg");
			tell_object(player[i],"Error: 中级副本JOB制造失败，请联系巫师。\n");
		}

		jmem->delete_map();
		destruct(jmem);
		time = localtime(time());
		log_file("jfb",sprintf("%d月%d日 %d:%d  虚拟空间创建失败。\n",1+time[LT_MON],time[LT_MDAY],time[LT_HOUR],time[LT_MIN]));
		return 0;
	}
	else
	{
		make_room_index ++;

		size = sizeof(player);
		for(i=0;i<size;i++)
		{
			player[i]->set_temp("room/start_room",start_room);
			call_out("room_ok",20,player[i]);
		}
		jmem->set("jfb_time",time()+ 5400); //任务结束时间
		jmem->set("open_time",time());        //任务开始时间
		jmem->len_1(); //连通地图(小心)
		jmem->heart(1);  //启动心跳
		call_out("make_jkiller",60,player);   //一分钟后开始刷怪
	}
}

void room_ok(object me)
{
	object start_room,jmem;
	int i,size;
	mapping user_id;

	if(!me) return;

	start_room = (object)me->query_temp("room/start_room");
	jmem = (object)me->query_temp("jfb/jfb_jmem");

	me->enable_player();
	me->delete_temp("block_msg");

	//没有开始房间
	if(!start_room)
	{
		tell_object(me,"坐标错误，你没能进入镜像。\n");
		user_id = (mapping)jmem->query("user_id");
		size = sizeof(user_id);

		for(i=0;i<size;i++)
		{
			if(user_id[sprintf("%d",i)] == me->query("id"))
			{
				jmem->set(sprintf("user_id/%d",i),0);
				jmem->set(sprintf("user/%d",i),0);
				break;
			}
		}
		return;
	}
	else
	{
		me->move(start_room);
		tell_object(me,HIY"【江湖】请各位英雄做好准备，30秒后中级副本挑战心魔起动。\n"NOR); //广告
	}
}

varargs void make_jkiller(object *player,int jboss)
{
	int i,size,killer_level=0,all_level=0,all_exp=0,killer_exp=0;
	object killer,jmem,rand_map;
	mapping maps;

	if(!player) return;

	jmem = (object)player[0]->query_temp("jfb/jfb_jmem");
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

//收起 NPC
void del_npc()
{
	object *joffice;
	int i,size;

	joffice = children("/d/jfb/npc/joffice");

	if(!joffice) return;

	size = sizeof(joffice);
	for(i=0;i<size;i++)
	{
		destruct(joffice[i]);
	}
}
