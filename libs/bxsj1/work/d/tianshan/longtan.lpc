// 龙潭 祭剑系统 
// longtan.c
// Created by Ciwei@SJ 22/3/2004

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",HIY"龙潭"NOR);
	set("long","拨开灌木，你眼前忽然一阵五色眩迷，不闻水声，但见水影，却是山谷中
一湾深不见底的藏青色水潭，令人不寒而栗的是，潭水居然呈通透的黑墨色，
潭中怪石林立，遮掩勾连，仿佛是一条乌金的石龙，盘绕在水潭上，而龙头，
正是斜插在潭水中央一方怪石。整个水潭宁静如死寂之河，只有风吹过竹林，
吹来阵阵的寒意。你凑近一看，潭水虽然漆黑，竟是黑得犹如一面墨色的水镜，
仿佛可以"HIY"照"NOR"见深深的幽冥……
"
	); 
		        
        set("exits",([
                "up" : __DIR__"duanhunya",
        ]));
        
	set("outdoors", "天山");
	set("no_fight",1);
	setup();
}

void init()
{
	add_action("do_show",({"show","zhao"}));	
	add_action("do_jijian",({"jijian","祭剑"}));	
	add_action("do_jiaofu",({"jiaofu","交付"}) );
	add_action("do_qijian",({"zhi","掷","reng" }));
	//drop
}

int do_show(string str)
{
	object me,obj;
	int btime,t;
	string id;
	
	if(!str) return notify_fail("你要在龙潭中照什么东西？\n");
	me = this_player();
	if(me->is_busy() || me->is_fighting()) return notify_fail("你正忙着！\n");
	if(!objectp(obj = present(str, me))) return notify_fail("你身上没有这样东西。\n");
	
	if(me->query_temp("longtanjijian")) return notify_fail("还没照够啊？\n");
	notify_fail("你在龙潭上借光查看"+obj->name()+"发现没什么好看的。\n");
	if (!(int)obj->query("imbued")) return 0;
	if( mapp(obj->query("armor_mp/armor_prop")) && me->query_skill("zhizao",1)<220) return 0;
	if( mapp(obj->query("weapon_mp/weapon_prop")) && me->query_skill("duanzao",1)<220) return 0;
	if(sscanf(obj->query("save_id"), "%s%d%*s",id,btime)!=3) return 0;
	if(id!=getuid(me) && id!="zhujian shi") return 0;
	if(stringp(obj->query("owner")) && obj->query("owner")!="0" && obj->query("owner")!=getuid(me)) return 0;
	t = time();
	//if(t-btime<86400) return 0;//必须在24小时后给别人		
	//if(NATURE_D->query_daytime() != "event_noon") return 0;//正午
	message_vision(HIY"$N"+HIY"见$n"+HIY"在潭水中闪耀着奇异的"+BLINK HIM"光华"NOR NOR+HIY"，总觉得难以洗尽其人间俗垢。\n"NOR,me,obj);
	call_out("do_show2",5+random(5),me,obj);
	me->start_busy(10);
	return 1;
}
void do_show2(object me,object obj)
{
	if(!me || !obj || environment(obj)!=me) return;	
	message_vision(HIM"$N"+HIM"心念一动：莫非真要用自己的生命，才能点醒这潭中之精华，为自己的$n"+HIM"重塑灵气？\n"NOR,me,obj);
	tell_object(me,RED"血，难道就是祭剑(jijian)的真谛？\n"NOR);
	me->start_busy(-1);
	me->interrupt_me();
	me->set_temp("longtanjijian",obj);
	return;
}

int valid_leave(object me, string dir)
{
	if(me) me->delete_temp("longtanjijian");
	return ::valid_leave(me,dir);
}

int do_jijian(string str)
{
	object me,obj;	
	
	object zhong;
	int needdest = 0;
			
	me= this_player();
		
	if(!objectp(obj=me->query_temp("longtanjijian"))) return 0;
	
	zhong = find_object(NPC_D("zhong-shentong"));
	if(!zhong)
	{
		zhong = load_object(NPC_D("zhong-shentong"));
		needdest = 1;
	}
	if( zhong->query("winner") == me->query("id") )
	{
		if(needdest) destruct(zhong);
		return notify_fail("你正忙着！\n");
	}
	
	if(needdest) destruct(zhong);
			
	if(me->is_busy() || me->is_fighting()) return notify_fail("你正忙着！\n");
	if(environment(obj)!=me) return notify_fail(obj->name()+"还在你身上么？\n");
	
	//if( mapp(obj->query("armor_mp/armor_prop")) && me->query_skill("zhizao",1)<350) return notify_fail("你正要运神祭剑,却发现已经力不从心。\n");
	//if( mapp(obj->query("weapon_mp/weapon_prop")) && me->query_skill("duanzao",1)<350) return notify_fail("你正要运神祭剑,却发现已经力不从心。\n");
	if(me->query("neili") < me->query("max_neili"))
	return notify_fail("你正要运神祭剑,却发现已经力不从心。\n");
	
	if(query("longtanjijian")) return notify_fail("潭中的水流已经越来越急,你还是等会再祭剑吧。\n");	
	
	me->delete_temp("longtanjijian");
	message_vision(HIY"$N一咬牙，运神发力，用内劲崩裂自己的虎口。 但见鲜血淋漓，顺着$n"HIY"向下直流入潭水。\n"NOR,me,obj);
	
	set("longtanjijian",obj);
	set("owner",getuid(me));
	
	remove_call_out("delete_jj");
	call_out("delete_jj",120+random(10));
		
	me->start_busy(6);
	call_out("jijian1",4+random(2),me,obj);
	/*
	message_vision(HIY"而龙潭中的黑沉沉的颜色竟逐渐放射出闪亮的光华。$N的血是越流越多，越来越是觉得体力不支。\n"NOR,me,obj);
	message_vision(HIY"而龙潭中的水流却是越来越急。$n"HIY"也发出嗡嗡的共鸣，与潭中巨石呼应。$N觉得天旋地转，已经快要昏迷。\n但见$n"HIY"却一洗尘垢，如同焕发了新的生命。\n"NOR,me,obj);
	tell_object(me,NOR"你究竟要将它交付(jiaofu)何人使用呢？ \n",);
		
	me->set_temp("last_damage_from", "以血祭剑身亡龙潭。");
	me->add("qi",-me->query("max_qi")*4/5);
	me->add("eff_qi",-me->query("max_qi")*4/5);	
	set("longtanjijian",obj);
	set("owner",getuid(me));
	me->start_busy(random(3));
	remove_call_out("delete_jj");
	call_out("delete_jj",60+random(10));
	*/
	return 1;
}

void jijian1(object me,object obj)
{
	remove_call_out("jijian1");
	if(!me || !obj || environment(me)!=this_object()) return;
	message_vision(HIR"鲜血越流越多……\n"NOR,me);
	me->start_busy(6);
	call_out("jijian2",4+random(2),me,obj);	
}

void jijian2(object me,object obj)
{
	remove_call_out("jijian2");
	if(!me || !obj || environment(me)!=this_object()) return;
	message_vision(HIY"而龙潭中的黑沉沉的颜色竟逐渐放射出闪亮的光华。$N的血是越流越多，越来越是觉得体力不支。\n"NOR,me,obj);
	me->start_busy(6);
	call_out("jijian3",4+random(2),me,obj);
}

void jijian3(object me,object obj)
{
	remove_call_out("jijian3");
	if(!me || !obj || environment(me)!=this_object()) return;
	message_vision(HIY"而龙潭中的水流却是越来越急。$n"HIY"也发出嗡嗡的共鸣，与潭中巨石呼应。$N觉得天旋地转，已经快要昏迷。\n但见$n"HIY"却一洗尘垢，如同焕发了新的生命。\n"NOR,me,obj);
	tell_object(me,NOR"你究竟要将它交付(jiaofu)何人使用呢？ \n",);
	me->start_busy(random(3));	
}
void reset()
{
	if(query("longtanjijian")) return;
	::reset();
}
void delete_jj()
{
	delete("longtanjijian");
	delete("owner");
	tell_room(this_object(),HIC"潭中水流又恢复如常。\n"NOR);
}

int do_jiaofu(string str)
{
	object me,obj,target;
	mapping worker;
	string* ber;
	string var,type,c_type;
	int i,j;
	string skill;
	mapping skills,learned;
	
	me=this_player();
	if(!objectp(obj=query("longtanjijian"))) return 0;
	if(query("owner")!=getuid(me)) return 0;
	if(me->is_busy() || me->is_fighting()) return notify_fail("你正忙着！\n");
	if(environment(obj)!=me) return notify_fail(obj->name()+"还在你身上么？\n");
	if(!str) return notify_fail("你究竟要将它交付(jiaofu)何人使用呢？ \n");	
	if(!objectp(target = present(str,this_object()))) return notify_fail("你边上没有这个人。\n");
	if(!userp(target)) return notify_fail("你只能交付把"+obj->name()+"给玩家。\n");
	if(target==me) return notify_fail("交付给自己？你吃过早饭了么？\n");
	if(target->is_busy() || target->is_fighting()) return notify_fail(target->name()+"正忙着！\n");
	
	if(mapp(obj->query("weapon_mp")))
	{
		c_type ="skill";
		skill="duanzao";
	}
	else if(mapp(obj->query("armor_mp")))
	{
		c_type ="armor";
		skill="zhizao";
	}
	else notify_fail("意外错误！！请通知巫师。\n");	
	if(mapp(worker = target->query("worker")))
	{
		ber = keys(worker);
		for(i=0;i<sizeof(ber);i++)
		{
			if(!mapp(worker[ber[i]])) continue;
			var = worker[ber[i]]["var"];
			if(var[strsrch(var,",",-1)+1..<1]!=getuid(target)) continue;
			sscanf(var,"%s,%*s",type);
			if(type==obj->query(c_type+"_type")) return notify_fail(target->name()+"已经拥有此类物品你不用白费劲了。\n");
		}
	}
	if(c_type=="skill") c_type = "weapon";
	if(!mapp(worker = obj->query(c_type+"_mp"))) return notify_fail("意外错误！！请通知巫师。\n");
	
	message_vision("$N长叹一声：圣兵利甲，鬼神难容，我以我血，"HIY"鉴此龙潭"NOR"。此$n就留给"+target->query("name")+"("+capitalize(getuid(target))+")吧。\n",me,obj);
	message_vision("$N将$n掷入潭中，潭中涌起鲜血，水流却渐渐平息。\n",me,obj);
	me->set_temp("last_damage_from", "以血祭剑身亡龙潭。");
	
	//me->skill_death_penalty();
	
	skills = me->query_skills();
	learned = me->query_learned();
	
	if(skills && learned && skill)
	{
		j = skills[skill] + 1;
		learned[skill] -= (j*j+1) / 2;
		if (learned[skill] < 0) {
			learned[skill] += (j*j+1) / 2;
			j = skills[skill]--;
			learned[skill] += (j*j+1) / 2;
		}
	}
	me->add("max_neili",-30-random(50));
	if(me->query("max_neili")<0)  me->set("max_neili",0);
	me->unconcious();
	worker["owner"] = getuid(target);
	worker["max_dur"] = worker["max_dur"]*(110+random(20))/100;
	//max_dur
	obj->set(c_type+"_mp",worker);
	obj->set("owner",getuid(target));
	obj->set("max_dur",worker["max_dur"] );
	obj->move(load_object(__DIR__"tannei"));
	remove_call_out("delete_jj");
	call_out("delete_jj",7+random(5));
	//me->start_busy(15);
	call_out("give_reward",2+random(5),target,obj);
	tell_object(target,"你被眼前奇景所惊呆了，竟然步不能移。\n");
	target->start_busy(7);
	return 1;
}

void give_reward(object target,object obj)
{
	if(!target || !obj) return;
	target->start_busy(-1);
	target->interrupt_me();	
	message_vision("潭中水流再次激起，汩汩声响，$N从潭中飞起，跃入$n怀中。\n",obj,target);
	obj->move(target);
}

int do_qijian(string str)
{
	object obj,me;
	
	if(!str) return notify_fail("你要在把什么东西掷入龙潭中？\n");
	me = this_player();
	if(me->is_busy() || me->is_fighting()) return notify_fail("你正忙着！\n");
	if(!objectp(obj = present(str, me))) return notify_fail("你身上没有这样东西。\n");	
	if (!(int)obj->query("imbued")) return notify_fail("别往龙潭里乱丢垃圾。\n");
	if(obj->query("owner") != getuid(me)) return notify_fail("这是你的么？别乱扔。\n");
	if(me->query_skill("dodge") < 130) return notify_fail("看样子得跳得很高才能扔中潭心，你的轻功修为不够啊。\n");
		
	obj->delete("owner");
	obj->delete("armor_mp/owner");
	obj->delete("weapon_mp/owner");
	obj->move(load_object(__DIR__"tannei"));
	message_vision("$N高高跃起，“呼”的一声将$n掷入龙潭内，好一会才听到一声回响。\n",me,obj);
	destruct(obj);
	return 1;
}