
string is_special(int i,int j)
{
	if(i==query("y")&&j==query("x"))
	{
		if(query("pai")=="中国")
			return BNK+get_damage_color()+"▲"NOR+HIB;
		else
			return BNK+get_damage_color()+"■"NOR+HIB;
	}
	return "NO";
}
void ini_action()
{
	add_action("do_moven","moven");
	add_action("do_moves","moves");
	add_action("do_movew","movew");
	add_action("do_movee","movee");
	add_action("do_qimao","qimao");
	add_action("do_paomao","paomao");
	return;
}
int do_paomao()
{
	object me,cang,*all_user,chuan;
	string *chuansheng;
	me=this_player();
	chuan=this_object();
	chuansheng=query("chuansheng");
	if(!query("canmove")) return notify_fail("已经抛锚了呀?\n");
	tell_object(me,HIW"你抬起操纵杆，抛锚停船!\n"NOR);
	if(get_y()==(get_height()-1)&&get_x()<5&&query("pai")=="中国")
	{
		cang=load_object(chuansheng[1]);
		cang->add("exits/out","/d/yashan/waneast3.lpc");
		message("vision",HIG"舱门吱的一声被打开."+query("shipname")+HIG"已经靠岸了!\n"NOR,cang);
		cang=load_object("/d/yashan/waneast3.lpc");
		if(cang)
		{
			cang->add("exits/"+PATHNAME,file_name(this_object()));
			message("vision",HIG+query("shipname")+HIG"缓缓驶进港口，舱门吱的一声就打开了.\n"NOR,cang);
		}
	}
	chuansheng=chuan->query("chuansheng");
	chuan->set("canmove",0);
	for(int i=0;i<sizeof(chuansheng);i++)
	{
		cang=load_object(chuansheng[i]);
		message("vision",HIY"只听嗖的一声，铁锚已落入水中!\n"NOR,cang);
		all_user=all_inventory(cang);
		for(int j=0;j<sizeof(all_user);j++)
		{
			if(userp(all_user[j]))
				tell_object(all_user[j],HIB"你知道，"+query("shipname")+HIB"已经抛锚了！\n"NOR);
		}
	}
	return 1;
}
int do_qimao()
{
	object me,cang;
	string *chuansheng;
	me=this_player();
	chuansheng=query("chuansheng");
	if(query("canmove")) return notify_fail("已经起锚了呀？\n");
	tell_object(me,HIW"你按下操纵杆，准备起锚!\n"NOR);
	me->set_temp("jwhz/jiashi",1);
	cang=load_object(chuansheng[1]);
	cang->delete("exits/out");
	message("vision",HIG"舱门吱的一声关上了."+query("shipname")+HIG"准备起航!\n"NOR,cang);
	if(query("pai")=="中国") 
	{
		cang=load_object("/d/yashan/waneast3.lpc");
		if(cang)
		{
			cang->delete("exits/"+PATHNAME);
			message("vision",HIG+query("shipname")+HIG"的舱门吱的一下就关上了.\n"NOR,cang);
		}
	}
	remove_call_out("canmove");
	call_out("canmove",1,this_object());
	return 1;
}

int canmove(object chuan)
{
	object cang,*all_user;
	string *chuansheng;
	chuansheng=chuan->query("chuansheng");
	chuan->set("canmove",1);
	for(int i=0;i<sizeof(chuansheng);i++)
	{
		cang=load_object(chuansheng[i]);
		message("vision",HIY"只听咯咯之响之后，铁锚已从水里拔起了!\n"NOR,cang);
		all_user=all_inventory(cang);
		for(int j=0;j<sizeof(all_user);j++)
		{
			if(userp(all_user[j]))
				tell_object(all_user[j],HIB"你知道，"+query("shipname")+HIB"已经起航了!你抖擞精神准备迎战！\n"NOR);
		}
	}
	return 1;
}
int do_moven()
{
	object me;
	me=this_player();
	if(query("sink")) return 1;
	if(me->is_busy()||me->is_fighting())
	{
		tell_object(me,HIC"你正忙着呢\n"NOR);
		return 1;
	}
	if(!query("canmove"))
	{
		tell_object(this_player(),HIR"船还没启锚呢，怎么开？\n"NOR);
		return 1;
	}
	if(query("y")<=0)
	{
		tell_object(this_player(),HIR"看清楚，再往北已经超出海域了！\n"NOR);
		return 1;
	}
	tell_object(this_player(),HIW"你驾驶着战船向北航行......\n"NOR);
	do_view();	
	me->start_busy(1);
	me->add_temp("jwhz/kongzhi",1);	
	//remove_call_out("change_position");
	call_out("change_position",1,0,-1,me);
	return 1;
}
int do_moves()
{
	object me;
	me=this_player();
	if(query("sink")) return 1;
	if(me->is_busy()||me->is_fighting())
	{
		tell_object(me,HIC"你正忙着呢\n"NOR);
		return 1;
	}
	if(!query("canmove"))
	{
		tell_object(this_player(),HIR"船还没启锚呢，怎么开？\n"NOR);
		return 1;
	}
	if(query("y")>=get_height()-1)
	{
		tell_object(this_player(),HIR"看清楚，再往南已经超出海域了！\n"NOR);
		return 1;
	}
	tell_object(this_player(),HIW"你驾驶着战船向南航行......\n"NOR);
	do_view();	
	me->start_busy(1);
	me->add_temp("jwhz/kongzhi",1);		
	//remove_call_out("change_position");
	call_out("change_position",1,0,1,me);
	return 1;
}
int do_movew()
{
	object me;
	me=this_player();
	if(query("sink")) return 1;
	if(me->is_busy()||me->is_fighting())
	{
		tell_object(me,HIC"你正忙着呢\n"NOR);
		return 1;
	}
	if(!query("canmove"))
	{
		tell_object(this_player(),HIR"船还没启锚呢，怎么开？\n"NOR);
		return 1;
	}
	if(query("x")<=0)
	{
		tell_object(this_player(),HIR"看清楚，再往西已经超出海域了！\n"NOR);
		return 1;
	}
	tell_object(this_player(),HIW"你驾驶着战船向西航行......\n"NOR);
	do_view();	
	me->start_busy(1);
	me->add_temp("jwhz/kongzhi",1);		
	//remove_call_out("change_position");
	call_out("change_position",1,-1,0,me);
	return 1;
}
int do_movee()
{
	object me;
	me=this_player();
	if(query("sink")) return 1;
	if(me->is_busy()||me->is_fighting())
	{
		tell_object(me,HIC"你正忙着呢\n"NOR);
		return 1;
	}
	if(!query("canmove"))
	{
		tell_object(this_player(),HIR"船还没启锚呢，怎么开？\n"NOR);
		return 1;
	}
	if(query("x")>=get_wide()-1)
	{
		tell_object(this_player(),HIR"看清楚，再往东已经超出海域了！\n"NOR);
		return 1;
	}
	tell_object(this_player(),HIW"你驾驶着战船向东航行......\n"NOR);
	do_view();	
	me->start_busy(1);
	me->add_temp("jwhz/kongzhi",1);		
	//remove_call_out("change_position");
	call_out("change_position",1,1,0,me);
	return 1;
}
int change_position(int x,int y,object me)
{
	int moveto_x,moveto_y;
	object jwhz,chuan,cang,thischuan;
	string *chuansheng;
	thischuan=this_object();
	jwhz=load_object("/adm/daemons/jwhz.lpc");
	moveto_x=query("x")+x;
	moveto_y=query("y")+y;
	if(jwhz->position(moveto_y,moveto_x)==NONE)
	{
		jwhz->write_position(query("y"),query("x"),NONE);
		add("x",x);
		add("y",y);
		if(query("pai")=="中国")
			jwhz->write_position(query("y"),query("x"),FRIEND);
		else
			jwhz->write_position(query("y"),query("x"),ENEMY);
	}
	else
	{
		for(int i=0;i<sizeof(china_ship);i++)
		{
			chuan=load_object(china_ship[i]);
			if(moveto_x==chuan->get_x()&&moveto_y==chuan->get_y())
			{//相撞
				chuansheng=(chuan->query("chuansheng"));
				cang=load_object(chuansheng[random(sizeof(chuansheng))]);
				if(!cang) message("vision",HIB"数据出错!\n"NOR,users());
				cang->set("fire",1);
				cang->set("fire_cause","相撞");
				cang->set("sink_cause","相撞");
				cang->checking_fire();
				cang->add_damage(10);
				CHANNEL_D->do_channel(this_object(), "bd", HIR + query("shipname")+HIR"与"+chuan->query("shipname")+HIR"相撞！引发大火！", -1);
				message("vision",HIW+BNK"只听嘣的一声巨响，"+query("shipname")+HIW+BNK"的船头撞到"+chuan->query("shipname")+HIW+BNK"的"+cang->query("short")+HIW+BNK"，引发了漫天的大火！\n"NOR,this_object());
				message("vision",HIW+BNK"只听嘣的一声巨响，"+query("shipname")+HIW+BNK"的船头撞了过来，引发了漫天的大火!\n"NOR,cang);
				thischuan->set("fire",1);
				thischuan->set("fire_cause","相撞");
				thischuan->set("sink_cause","相撞");
				thischuan->checking_fire();
				thischuan->add_damage(10);
				if(is_sink()&&!is_sinking()) 
				{
					checking_sink();
					CHANNEL_D->do_channel(this_object(), "bd", HIR + query("shipname")+HIR"开始沉没！", -1);
				}
				
				if(cang->is_sink()&&!cang->is_sinking())
				{
					cang->checking_sink();
					CHANNEL_D->do_channel(this_object(), "bd", HIR + cang->query("shipname")+HIR"开始沉没！", -1);
				}

				return 1;
			}
		}
		for(int i=0;i<sizeof(japan_ship);i++)
		{
			chuan=load_object(japan_ship[i]);
			if(moveto_x==chuan->query("x")&&moveto_y==chuan->query("y"))
			{//相撞
				chuansheng=(chuan->query("chuansheng"));
				cang=load_object(chuansheng[random(sizeof(chuansheng))]);
				if(!cang) message("vision",HIB"数据出错!\n"NOR,users());
				cang->set("fire",1);
				cang->set("fire_cause","相撞");
				cang->set("sink_cause","相撞");
				cang->checking_fire();
				cang->add_damage(15);
				CHANNEL_D->do_channel(this_object(), "bd", HIR + query("shipname")+HIR"英勇地向"+chuan->query("shipname")+HIR"撞去，想和"+chuan->query("shipname")+HIR"同归于尽！", -1);
				message("vision",HIW+BNK"只听嘣的一声巨响，"+query("shipname")+HIW+BNK"的船头撞到"+chuan->query("shipname")+HIW+BNK"的"+cang->query("short")+HIW+BNK"，引发了漫天的大火！\n"NOR,this_object());
				message("vision",HIW+BNK"只听嘣的一声巨响，"+query("shipname")+HIW+BNK"的船头撞了过来，引发了漫天的大火!\n"NOR,cang);
				thischuan->set("fire",1);
				thischuan->set("fire_cause","相撞");
				thischuan->set("sink_cause","相撞");
				thischuan->checking_fire();
				thischuan->add_damage(15);
				if(is_sink()&&!is_sinking()) 
				{
					checking_sink();
					CHANNEL_D->do_channel(this_object(), "bd", HIR + query("shipname")+HIR"开始沉没！", -1);
					CHANNEL_D->do_channel(this_object(), "bd", HIM + query("shipname")+HIM"与敌人同归于尽的气概真是惊天地、泣鬼神!", -1);
				}
				
				if(cang->is_sink()&&!cang->is_sinking())
				{
					cang->checking_sink();
					CHANNEL_D->do_channel(this_object(), "bd", HIR + cang->query("shipname")+HIR"开始沉没！", -1);
				}
				me->add_temp("jwhz/zhuang",1);
				return 1;
			}
		}
		//触礁
	}
	return 1;
}
int ini_create()
{
	set("item_desc", ([
                "directions" : 
      HIG"驾驶室操作方法：\n"
+HIW"qimao"+HIB": 起锚出发;\n"
+HIW"paomao"+HIB":抛锚停船;\n" 
+HIW"movee"+HIB": 驾驶船只向东（右）行驶；\n"
+HIW"moves"+HIB": 驾驶船只向南（下）行驶；\n"
+HIW"movew"+HIB"：驾驶船只向西（左）行驶；\n"
+HIW"moven"+HIB"：驾驶船只向北（上）行驶．\n"
+HIW"jiuhuo"+HIB":救火.\n"
+HIW"view "+HIB"：浏览海域．\n"
+HIG"图例：\n▲"+HIB"：中方船只(闪烁的是本船位置)；\n"
+HIG"■"HIB+"：日方船只\n"
+HIR"★"HIB+": 炮弹落下的位置（５秒种后会自动消失）\n"
HIG"船只由完好无损到沉没颜色分别表示为：\n"
+HIG"█"+HIY"█"+HIC"█"+HIW"█"+HIM"█"+HIR"█"+BLU"█\n"NOR,
        ]));
	set("damage",0);
	set("max_damage",500);//沉船伤害的最大值。
	set("damage_level",0);//船体伤害程度．
	set("sinking",0);
	set("canmove",0);
	return 1;
}

int auto_move()
{
	object jwhz,target,*alive_target,cang;
	int distance,times,sign,level1,wide,height,x,y,target_x,target_y,dx,dy;
	string *chuansheng;
	if(query("sink")) return 1;//沉了，就不动了。
	if(query("pai")=="中国") return 1;//中国的船，不能自动前进!需要玩家操纵。
	wide=get_wide();
	height=get_height();
	level1=(wide/4+1)*(wide/4+1)+(height/4+1)*(height/4+1);
	distance=0;
	dx=0;
	dy=0;
	times=0;
	sign=0;
	jwhz=load_object("/adm/daemons/jwhz.lpc");
	x=get_x();
	y=get_y();
	alive_target=({});
	chuansheng=query("chuansheng");
	for(int i=0;i<sizeof(chuansheng);i++)
	{
		cang=load_object(chuansheng[i]);
		cang->set("fire",0);
	}
	for(int i=0;i<sizeof(china_ship);i++)
	{
		target=load_object(china_ship[i]);
		if(target->query("sink")) continue;
		alive_target+=({target});
	}
	if(sizeof(alive_target)==0) return 1;
	for(int i=0;i<sizeof(alive_target);i++)
	{
		target=alive_target[i];
		target_x=target->get_x();
		target_y=target->get_y();
		distance=(target_x-x)*(target_x-x)+(target_y-y)*(target_y-y);
		if(distance<level1)//如果发现近距离有船就停止前进。
		{
			remove_call_out("auto_move");
			call_out("auto_move",random(10));
			return 1;
		}
	}
	target=alive_target[random(sizeof(alive_target))];
	target_x=target->get_x();
	target_y=target->get_y();
	if(target_x>x)
		dx=random(2);
	else if(target_x<x)
		dx=0-random(2);
	else
		dx=0;
	if(target_y>y)
		dy=random(2);
	else if(target_y<y)
		dy=0-random(2);
	else
		dy=0;
	if(jwhz->position(y+dy,x+dx)==ENEMY)
	{
		remove_call_out("auto_move");
		call_out("auto_move",random(10));
		return 1;
	}
	change_position(dx,dy,this_object());
	chuansheng=target->query("chuansheng");
	for(int i=0;i<sizeof(chuansheng);i++)
	{
		cang=load_object(chuansheng[i]);
	//	if(!cang) message("vision", chuansheng[i],users());
	//	if(cang) message("vision",".........\n",users());
		message("vision",HIB+query("shipname")+HIB"向我方靠近!\n"NOR,cang);
	}
	remove_call_out("auto_move");
	call_out("auto_move", random(15));
	return 1;
}

int auto_fire()
{
	object jwhz,target,*alive_target,cang;
	int distance,times,sign,level1,wide,height,x,y,target_x,target_y,shoot_x,shoot_y,min_i;
	string *chuansheng;
	if(query("sink")) return 1;//沉了，就不动了。
	if(query("pai")=="中国") return 1;//中国的船，不能自动开炮!需要玩家操纵。
	jwhz=load_object("/adm/daemons/jwhz.lpc");
	wide=get_wide();
	height=get_height();
	alive_target=({});
	min_i=0;
	x=get_x();
	y=get_y();
	sign=0;
	for(int i=0;i<sizeof(china_ship);i++)
	{
		target=load_object(china_ship[i]);
	/*	chuansheng=target->query("chuansheng");
		for(int j=0;j<sizeof(chuansheng);j++)
		{
			cang=load_object(chuansheng[j]);
			if(cang->query("sink")) 
			{
				sign=1;
			}
		}
		if(sign) continue;
		sign=0;
		alive_target+=({target});*/
		if(!target->query("sink")) alive_target+=({target});
	}
	if(sizeof(alive_target)==0) 
	{
	//	message( "channel:" + "chat",HIR + "【甲午战报】中国北洋舰队全军覆没！\n"NOR,users());
		return 1;//死光了，可以做中国失败的判据。
	}
	level1=10000000;
//	
	for(int i=0;i<sizeof(alive_target);i++)
	{
		target_x=alive_target[i]->get_x();
		target_y=alive_target[i]->get_y();
		distance=(x-target_x)*(x-target_x)+(y-target_y)*(y-target_y);
		if(distance<level1)
		{
			min_i=i;
			level1=distance;
		}
	}
//	message( "channel:" + "chat",HIR + "【甲午战报】2\n"NOR,users());
	target=alive_target[min_i];//取距离最近的中国船只作为攻击目标。
	if(random(6)==0) target=alive_target[random(sizeof(alive_target))];//有1/6的机会选取其他的中国船只作为攻击目标。
	//开炮
	target_x=target->get_x();
	target_y=target->get_y();
	if(fabs(target_x-x)>wide/2||fabs(target_y-y)>height/2)//超过射程
	{
		remove_call_out("auto_fire");
		call_out("auto_fire", 15 + random(15));
		return 1;
	}	
//	message( "channel:" + "chat",HIR + "【甲午战报】3\n"NOR,users());
	chuansheng=query("chuansheng");
	if(sizeof(chuansheng)<2) return 1;//没有炮舱？
	for(int i=1;i<sizeof(chuansheng);i++)
	{
//		message( "channel:" + "chat",HIR + "【甲午战报】4\n"NOR,users());
		cang=load_object(chuansheng[i]);
		cang->set("ready",1);//敌人弹药无限。嘿嘿。
		cang->set("shoot_x",target_x-cang->get_x());
		cang->set("shoot_y",cang->get_y()-target_y);
		call_out("auto_fire_single",random(5),cang);
	}
	CHANNEL_D->do_channel(this_object(), "bd", HIR + query("shipname")+HIR"向"+target->query("shipname")+HIR"开炮!", -1);
	remove_call_out("auto_fire");
	call_out("auto_fire",15 + random(25));
	return 1;
}
int auto_fire_single(object cang)
{
	object jwhz;
	jwhz=load_object("/adm/daemons/jwhz");
	if(!jwhz->query("begin")) return 1;
	cang->do_fire();
	return 1;
}
int fabs(int a)
{
	if(a<0)
		return 0-a;
	else
		return a;
}