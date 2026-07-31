#include <ansi.h>
inherit F_SAVE;
inherit F_DBASE;
/*从以下地点随机挑选任务人物*/
nosave mapping didian =([
	"city":"扬州",
	"xueshan":"雪山",
	"guanwai":"关外",
	"emei":"峨眉",
	"taishan":"泰山",
	"city3":"成都",
	"beijing":"北京",
	"xiangyang":"襄阳",
	"huashan":"华山",
	"quanzhen":"全真",
	"foshan":"佛山",
	"fuzhou":"福州",
]);
nosave int quest_time=0;//0为不限时间 60=一分钟，以此类推

public void quest(object obj)//接取任务
{
	int i,j;
	mixed *files;
	string file;
	object ob,obj1;
	object *inv;
	string *di,di1;
	
	if(time()/86400 == obj->query("dytime")/86400)
	{
	    obj->set("dynumber",0);	
		obj->set("dytime",time());
	}
	
	if(obj->query("dynumber")>=22)
	{
		tell_object(obj,"你今天任务已达到上限！\n");
		obj->delete("daily");
		return;
	}
	if(obj->query("daily/id"))
	{
		tell_object(obj,"你已经接取了日常任务，目标:"+obj->query("daily/name")+"正在"+obj->query("daily/city")+obj->query("daily/place")+"活动！『"ZJURL("cmds:cesy remove")ZJSIZE(10)"放弃"NOR"』\n");	
		return;
	}
	
	di=keys(didian);
	di1=di[random(sizeof(di))];
	
	files = list_dirs("/d/"+di1+"/");
	file = "/d/"+di1+"/"+files[random(sizeof(files))]+".c";	
	if (! (ob = find_object(file)))
	{
		if (file_size(file)>=0)
		ob = load_object(file);
	}
	if(ob)
	{
		if(ob->query("no_fight")==1)
		{
			quest(obj);	
			return;
		}
        inv = all_inventory(ob);
		if(sizeof(inv)<1)
		{
			quest(obj);	
			return;
		}
		obj1=inv[random(sizeof(sizeof(inv)))];
		if (obj1->is_player())  
		{
			quest(obj);	
			return;
		}
		if (! obj1->is_character() || obj1->is_corpse())  
		{
			quest(obj);	
			return;
		}
		obj->set("daily/id",obj1->query("id"));
		obj->set("daily/name",obj1->query("name"));
		obj->set("daily/city",didian[di1]);
		obj->set("daily/place",ob->query("short"));
		if(quest_time>0) obj->set("daily/time",time()+quest_time);
		tell_object(obj,"请去击杀了"+obj1->query("name")+",他正在"+didian[di1]+"的"+ob->query("short")+"活动！\n");
	}else quest(obj);	
}


public void set_shanchu(object me)//删除任务  调用DAILY_D->set_shanchu(object me);
{
	me->delete("daily");
	tell_object(me,"你放弃了日常任务！\n");
}



public void set_rewards(object me)//领取奖励
{
    if(me->query("dynumber")>=22)
	{
		tell_object(me,"你今天任务已达到上限！\n");
		me->delete("daily");
		return;
	}
	
	if(me->query("daily/time")>0&&me->query("daily/time")<time())
	{
		tell_object(me,"任务已经过期！\n");
		me->delete("daily");
		return;		
	}
	//以下添加给me的任务奖励
	
	
	me->set("dytime",time());
	//"/clone/money/thousand-gold",
	//"/clone/vip2/yanzhi",
	me->add("combat_exp",100000);
		me->add("potential",1000000);
		me->add("yuanbao",100);
		if(me->query("zhanling/s8") < 100)
		{
		me->add("zhanling/a8",100);
		me->add("zhanling/s8",100);
		tell_object(me,"你完成了此次任务，获得了100战令修为！\n");
		}
		tell_object(me,"你完成了此次任务，获得了修为10万，潜能100万,100个灵石！\n");
       me->delete("daily");
	   return;
}
