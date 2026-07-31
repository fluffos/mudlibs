// by name QQ：3468713544
inherit ROOM;
#define PAT "/log/adm/mrt"
void create()
{
	set("short", "名人堂");
	set("channel_id", "名人堂");
	set("long", "行走江湖实力为尊，亮出你的实力，讲实力载入武林史册吧！\n");
	
	set("exits", ([	
		//"north" : __DIR__"wumiao",
		"southwest" : __DIR__"kedian",
		
	]));
	set("action_list",([
		HIY"江湖留名"NOR:"mrt",	
		HIW"江湖秘籍"NOR:"mijishop",	
	]));	
	set("mrt",1);  //默认强度100%
	set_heart_beat(35);
	setup();
}
void init()
{
    add_action("mrt_kill","kills");
	add_action("mijishop","mijishop");
}

int mijishop(string arg)
{
	string *list,str,file,price;
	int i,yuanbao,value;
	object me,ob;
	int amount;
	mapping goods,times;

	me = this_player();
	goods = ([
		"/clone/mingrt/qingmang":30,
	/* 	"/clone/lunjian/dan_chongmai4":3,
		"/clone/lunjian/putao":10,
		"/clone/lunjian/wujueling":100,
		"/clone/lunjian/xyj":50,
		"/clone/lunjian/da-xidian":25, */
	]);
	times = ([
		/* "/clone/lunjian/wujueling":1, */
	]);
	list = keys(goods);
	if (! arg)
	{
		str = ZJOBLONG"你目前有"+me->query("mjf")+"秘籍点券，请选择您想兑换的道具：\n"ZJOBACTS2+ZJMENUF(4,4,8,32);
		for(i=0;i<sizeof(list);i++)
		{
			file = list[i];
			if(!goods[file]||file_size(file+".c")<0) continue;
			yuanbao = goods[file];
			price = yuanbao+"点券";
			str += sprintf("%s"ZJBR"%s:mijishop look %s"ZJSEP,file->query("name"),price,file);
		}
		tell_object(me,str+"\n");
		return 1;
	}
	else if (sscanf(arg,"look %s",file)==1)
	{
		if(file_size(file+".c")<0||!goods[file])
			return notify_fail(HIM"兑换列表中没有这个道具！！"NOR"\n");

		yuanbao = goods[file];
		price = yuanbao+"点券";
		str = ZJOBLONG+"【"+file->query("name")+"】　　价格："+price+NOR+ZJBR"一一一一一一一一一一一一一一一一一一一一一一一"ZJBR;
		if(times[file])
			str += HIR"此物品每个玩家限兑换"+times[file]+"次"NOR ZJBR;
		str += file->long();
		str += ZJOBACTS2+ZJMENUF(4,4,10,28);
		str += "兑换:mijishop buy "+file+"\n";
		tell_object(me,str+"\n");
		return 1;
	}
	else if (sscanf(arg,"buy %s",file)==1)
	{
		if(file_size(file+".c")<0||!goods[file])
			return notify_fail(HIM"兑换列表中没有这个道具！！"NOR"\n");

		yuanbao = goods[file];

		if(times[file])
		{
			if(me->query("lunjian/duihuan/"+file->query("id")) >= times[file])
				return notify_fail(HIM"此物品每个玩家只能兑换"+times[file]+"次！！"NOR"\n");
			me->add("lunjian/duihuan/"+file->query("id"),1);
		}
		if(me->query("mjf") < yuanbao)
			return notify_fail(HIM"你的兑换点券不足，多参加参加名人堂活动吧！！"NOR"\n");
		me->add("mjf",-yuanbao);
		ob = new(file);
		log_ufile(me,"pay/mrt", "兑换了"+ob->short()+"。\n");
		tell_object(me,"你成功兑换到了"+ob->short()+"。"NOR"\n");
		ob->move(me);
		return 1;
	}
	else
		return notify_fail(HIM"你想干什么？？"NOR"\n");

	return 1;
}

int mrt_kill(string arg)
{
mapping skill;
string skills,msg;
object where,npc,me,room;
int lvl,last,nd,i;

me=this_player();
last = me->query("mrt_day_time");	
where = environment(me);

if (!arg)
{
msg = "请选择挑战层次：\n";
msg += ZJOBACTS2+ZJMENUF(3,3,9,32);
for(i=0;i<=me->query("mrt/nd");i++){
msg+="第"+i+"层:kills "+i+""ZJSEP;		
}
msg=ZJOBLONG+msg;
msg+="\n";
write(msg);
}else{	

if(me->query("combat_exp")<1000000)
return notify_fail(HIR"你的修为不足100W，没有资格挑战名人堂高手。\n"NOR);	
if(me->query_skill("force",1)<180)
return notify_fail(HIR"你的内功等级不足180级，没有资格挑战名人堂高手。\n"NOR);	
if(time()/86400 == last/86400)
return notify_fail("你今天已经挑战过名人堂高手了，明天再来吧！\n");	
sscanf(arg,"%d",nd);
if(me->query("mrt/nd")<nd)
return notify_fail("你还没有挑战过这层呢。。\n");	
me->set("mrtnd",nd);
lvl=me->query_skill("force",1)+(me->query_skill("force",1)*query("mrt"))+(me->query_skill("force",1)*nd);
//NPC与ROOM	
npc=new("/cmds/npc");
room=new("/d/city/mrtroom");
skill=npc->query_skills();
//根据强度来设置高手等级，基本属性
    npc->set("qi",to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));
	npc->set("max_qi", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));
	npc->set("eff_qi", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));
	npc->set("eff_jing", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));	
	npc->set("jing", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));
	npc->set("max_jing", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));	
	npc->set("neili", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));
	npc->set("max_neili", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));    
	npc->set("jingli", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));
	npc->set("max_jingli", to_int(100*me->query_skill("force",1)+((me->query_skill("force")*100)*query("mrt"))));		 
	npc->set("combat_exp", to_int(10000*me->query_skill("force",1)+((me->query_skill("force")*10000)*query("mrt"))));	
	npc->set_temp("apply/attack", to_int(10*me->query_skill("force",1)+(me->query_skill("force")*query("mrt"))));
	npc->set_temp("apply/damage", to_int(10*me->query_skill("force",1)+(me->query_skill("force")*query("mrt"))));
	npc->set_temp("apply/defence",to_int(10*me->query_skill("force",1)+(me->query_skill("force")*query("mrt"))));
	npc->set_temp("apply/armor", to_int(10*me->query_skill("force",1)+(me->query_skill("force")*query("mrt"))));
    npc->set_temp("apply/unarmed_damage",to_int(10*me->query_skill("force",1)+(me->query_skill("force")*query("mrt"))));      
    //设置技能   
    foreach(skills in keys(skill)){
    npc->set_skill(skills,to_int(lvl));
   }
 npc->move(room);
 me->move(room);
 me->set("mrt_day_time",time());
 }
 return 1;

}
//30分钟随机一下强度
void heart_beat()
{
float qd;
mixed *sj;
sj = localtime(time());
qd=1+random(10);
if(sj[1]%30==0){
set("mrt",qd/10);
CHANNEL_D->do_channel(this_object(), "chat", "名人堂强度刷新。");
}

//每轮7天
if(sj[3]%7==0&&sj[2]==1&&sj[1]==1&&sj[0]==1)
{
rm("/log/adm/mrt");
}
  
  
}