// Room: /city/wumiao.c
// YZC 1995/12/04 

#include <room.h>

inherit ROOM;

int is_chat_room() { return 1; }

void create()
{
	set("short", "武庙");
	set("long", @LONG
这里是岳王庙的正殿，内有岳飞像，像上方悬挂岳飞手书“还我河山”的
横匾。殿两侧壁上嵌着“尽忠报国”四个大字。武人到此，都放下武器，毕恭
毕敬地上香礼拜。旁边似乎有一道侧门。
LONG );
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_learn", "1");
	set("no_study", "1");
	set("no_learn", "1");
	set("no_dazuo", "1");
	set("no_sleep_room", "1");

	set("valid_startroom","1");
	set("objects", ([
		__DIR__"obj/box" : 1,
		"/adm/npc/qiandao": 1,
	]));

	set("action_list", ([
		"每日签到" : "day_sign",	
		"推广相关" : "tuiguang",		
		HIY"任务指引"NOR : "qqq",		
	]));

	set("exits", ([
		"east" : __DIR__"beidajie2",
		"north"   : __DIR__"wumiao2",
		"northwest": "/d/wizard/guest_room",
	]));
	create_door("northwest", "竹门", "southeast", DOOR_CLOSED);
	setup();
}

void init()
{
	add_action("do_sign","day_sign");
	add_action((: this_player()->force_me("tg") :),"tuiguang");//++++
	add_action("mrrw","qqq");	
}

int valid_leave(object me, string dir)
{		
	if (dir == "northwest" && ! userp(me) && ! me->is_chatter())
		return 0;
	return ::valid_leave(me, dir);
}


int do_sign(string arg)
{
	object ob,me,xb;
	string hol,file;
	int vlv,last,times,pot,yuanbao_2,gx,xian;
	mapping gifts;

	me = this_player();

    gx = random(5);
	xian = gx;
	last = me->query("last_day_sign");
	times = me->query("day_sign_times");
	if(time()/86400 == last/86400)
		return notify_fail("你本月已经签到累计"+times+"次。\n你今天已经签到过了。\n");
	if(time()/86400 - last/86400 > 1)
	{
		tell_object(me,"由于你昨天未签到，签到累计已清空。\n");
		times = 0;
	}

	me->set("last_day_sign",time());
	times += 1;
	me->set("day_sign_times",times);
	vlv = me->query("zjvip/level");
	pot = times*50+(10000+random(500)*vlv);
	me->add("potential",pot);
	me->add("combat_exp",pot);
	me->set("mgcs",1);
	me->set("wdtcs",1);
	me->add("zjvip/all_pay",xian);
	tell_object(me,"你本月已经签到累计"+times+"次。\n你获得"+pot+"修为和潜能，试练楼次数+1，签到次数 +1，累计签到"+times+"次, 一次迷宫资格。\n");
	log_ufile(me,"sign","连续第"+times+"次签到获得"+pot*2+"修为和"+pot+"潜能。\n");
	if(times==7)
	{
	    me->add("jifeng",100);
		tell_object(me,"恭喜你签到累计"+times+"次，获得了100点券。\n");
	}	
	if(times==15)
	{
	    me->add("jifeng",200);
		tell_object(me,"恭喜你签到累计"+times+"次，获得了200点券。\n");
	}	
	if(times==30)
	{
	    me->add("jifeng",300);
		tell_object(me,"恭喜你签到累计"+times+"次，获得了300点券。\n");
		me->set("day_sign_times",0);
		times = 0;
	}														
	if(times>=0)
	{
		ob = new("/clone/vip/vip2/dan_chongmai1");
	//	xb = new("/clone/shizhe/ling_tiaozhan");
		tell_object(me,"你获得 "+ob->short()+"。\n");
		//tell_object(me,"你获得 "+xb->short()+"。\n");
		ob->move(me);
	}
	if (me->query("ybvip/times")>0)
	{
		me->add("yuanbao",720);
		tell_object(me,"因为灵石周卡的原因，你额外获得720灵石。\n");
	}
	
	GIFT_D->check_gift(me);
	if(hol = "/adm/daemons/payd"->is_hol())
	{
		tell_object(me,HIG"今天是"HIY+hol+HIG"，祝您节日愉快"NOR"。\n");
	}
	else if(localtime(time())[6]==0 || localtime(time())[6]==6)
	{
		tell_object(me,HIG"今天是"HIY"周末"HIG"，祝您周末愉快！"NOR"。\n");
	}
	return 1;
}


int mrrw(string arg)
{
	object me=this_player();
	string type;
	string msg="", line="";
if (!arg) {
		msg = ZJOBLONG+
		      "目前游戏中的日常任务如下[更新中]：\n";
		msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "武馆训练["+me->query("fuben/wuguan/mun")+"/2]:qqq wuguan";
		msg += ZJSEP"伏击金兵["+me->query("fuben/jinbing/mun")+"/2]:qqq jinbing";	
		msg += ZJSEP"单骑破元["+me->query("fuben/poyuan/mun")+"/2]:qqq poyuan";		
		msg += ZJSEP"十三皇陵["+me->query("fuben/huangling/mun")+"/2]:qqq huangling";		
		msg += ZJSEP"荡寇[简单]["+me->query("fuben/dangkou/mun")+"/2]:qqq dangkou";		
		
	}
	else if(arg=="wuguan"){
	msg = ZJOBLONG+"扬州武馆[武馆训练]："ZJBR
	                  "————————————————"ZJBR
                      "新手专属副本"ZJBR
                      "初入江湖难免行走困难，武馆是新人学艺初始的好地方，江湖之路从武馆学艺开始。\n";
	msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "立即前往:qqq wuguan2";	
	}
	else if(arg=="wuguan2"){ 
	me->move("d/city/wuguan/qianting");	
	}
	else if(arg=="jinbing"){
	msg = ZJOBLONG+"关外宁远镇[伏击金兵]："ZJBR
	                  "————————————————"ZJBR
                      "金国一直对我中原贼心不死，经常派密探进入关内刺探军情，阻击密探可获得丰厚奖励。\n";
	msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "立即前往:qqq jinbing2";	
	}
	else if(arg=="jinbing2"){ 
	me->move("d/guanwai/ningyuan");	
	}	
	else if(arg=="poyuan"){
	msg = ZJOBLONG+"襄阳城北草地[单骑破元]："ZJBR
	                  "————————————————"ZJBR
                      "元兵在我襄阳城外虎视眈眈，一旦玄武门被攻破，元兵将直入中原腹地，再无可挡，各方英雄豪杰当用尽自己一生本事灭杀元兵。\n";
	msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "立即前往:qqq poyuan2";	
	}
	else if(arg=="dangkou"){
	msg = ZJOBLONG+"人人有责[荡平倭寇]："ZJBR
	                  "————————————————"ZJBR
                      "倭寇在杭州烧杀抢掠，请个大侠士出手相助，爱护我们美丽的祖国！！\n";
	msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "立即前往:qqq dangkou11";	
	}
	else if(arg=="poyuan2"){ 
	me->move("d/xiangyang/caodi3");	
	}	
	else if(arg=="dangkou11"){ 
	me->move("d/hangzhou/ningyuan");	
	}
	else if(arg=="huangling"){ 
	me->move("d/beijing/huangling");	
	}			
	write(msg + "\n");			
	return 1;
}



