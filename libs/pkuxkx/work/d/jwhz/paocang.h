
int ini_create()
{
	set("item_desc", ([
                "directions" : 
HIG"炮舱操作方法：\n"
+HIW"aime"+HIB": 将炮口瞄准点向东（右）移动；\n"
+HIW"aims"+HIB": 将炮口瞄准点向南（下）移动；\n"
+HIW"aimw"+HIB"：将炮口瞄准点向西（左）移动；\n"
+HIW"aimn"+HIB"：将炮口瞄准点向北（上）移动．\n"
+HIW"load"+HIB": 将炮弹放入炮膛．\n"
+HIW"fire"+HIB": 开炮．\n"
+HIW"reset"+HIB":炮口瞄准点复位（回到海域中心)\n"
+HIW"check"+HIB":得到船体损害情况．\n"
+HIW"jiuhuo"+HIB":救火\n"
+HIW"view "+HIB"：浏览海域．\n"
+HIG"图例：\n▲"+HIB"：中方船只(闪烁的是本船位置)；\n"
+HIG"■"HIB+"：日方船只\n"
+HIW"¤"HIB+": 炮口瞄准点(闪烁)\n"
+MAG"⊙"HIB+": 炮口瞄准点与目标物体重合\n"
+HIR"¤"HIB+": 炮口瞄准点超出海域范围\n"
+HIR"★"HIB+": 炮弹落下的位置（５秒种后会自动消失）\n"
HIG"船只由完好无损到沉没颜色分别表示为：\n"
+HIG"█"+HIY"█"+HIC"█"+HIW"█"+HIM"█"+HIR"█"+BLU"█\n"NOR,
        ]));
	set("ready",0);
	set("shoots",50);
    set("objects",([
        __DIR__"obj/paodan.lpc" : 20,
        ]));
	return 1;
}
string is_special(int i,int j)
{
	int shoot_x,shoot_y,x,y,wide,height,sigh;
	object jwhz;
	jwhz=load_object("/adm/daemons/jwhz.lpc");
	wide=jwhz->query("wide");
	height=jwhz->query("height");
	x=get_x();
	y=get_y();
	if(i==get_y()&&j==get_x())
	{
		if(query("pai")=="中国")
			return BNK+get_damage_color()+"▲"NOR+HIB;
		else
			return BNK+get_damage_color()+"■"NOR+HIB;
	}
	shoot_x=query("shoot_x")+x;
	shoot_y=y-query("shoot_y");
	sigh=0;
	if(shoot_x<0) 
	{
		sigh=1;
		shoot_x=0;
	}
	if(shoot_x>=wide)
	{
		sigh=1;
		shoot_x=wide-1;
	}
	if(shoot_y<0)
	{
		sigh=1;
		shoot_y=0;
	}
	if(shoot_y>=height)
	{
		sigh=1;
		shoot_y=height-1;
	}
	if(i==shoot_y&&j==shoot_x)
	{
		if(sigh==0)
			if(jwhz->position(i,j)==FRIEND||jwhz->position(i,j)==ENEMY)
				return BNK+MAG"⊙"NOR+HIB;
			else
				return BNK+""+HIW"¤"NOR+HIB;
		else
		{
			string msg="";
			for(int k=0;k<wide/2-9;k++) msg=msg+" ";
			msg=msg+HIR"瞄准点超出海域范围!\n"HIB;
			tell_object(this_player(),msg);
			return BNK+HIR"¤"NOR+HIB;
		}
	}
	return "NO";
}

void ini_action()
{
	add_action("do_aimn","aimn");
	add_action("do_aims","aims");
	add_action("do_aimw","aimw");
	add_action("do_aime","aime");
	add_action("do_reset","reset");
	add_action("do_fire","fire");
	add_action("do_load","load");
	add_action("do_check","check");
	return;
}

int do_load()
{
	object me,paodan;
	me=this_player();
	if(query("sink")) return 1;
	if(me->is_busy()||me->is_fighting())
	{
		tell_object(me,HIC"你正忙着呢\n"NOR);
		return 1;
	}
	if(query("ready"))
	{
		tell_object(this_player(),HIR"你的大炮里已经有一发炮弹了！\n"NOR);
		return 1;
	}
	else
	{
		/*
		if(query("shoots")<=0)
		{
			tell_object(this_player(),HIR"你已经没有炮弹了!\n"NOR);
			return 1;
		}*/
		paodan = present("pao dan",me);
		if(!paodan) paodan=present("pao dan",this_object());
		if(!paodan)
		{
			tell_object(this_player(),HIR"你已经没有炮弹了!\n"NOR);
			return 1;
		}
		destruct(paodan);
		me->start_busy(1);
		message_vision(HIW"$N利索地将一枚炮弹装入炮膛.\n"NOR,this_player());
		set("ready",1);
		return 1;
	}
}

int do_aimn()
{
	object me;
	me=this_player();
	if(query("sink")) return 1;
	if(me->is_busy()||me->is_fighting())
	{
		tell_object(me,HIC"你正忙着呢\n"NOR);
		return 1;
	}
	if(query("shoot_y")>=get_height()/2)
	{
		tell_object(this_player(),HIR"你的大炮已经向北瞄准到最大限度了!\n"NOR);
		return 1;
	}
	tell_object(this_player(),HIW"你将打炮的瞄准点向北移动一度！\n"NOR);
//	me->start_busy(1);
	add("shoot_y",1);
	do_view();
	return 1;
}
int do_aims()
{
	object me;
	me=this_player();
	if(query("sink")) return 1;
	if(me->is_busy()||me->is_fighting())
	{
		tell_object(me,HIC"你正忙着呢\n"NOR);
		return 1;
	}
	if(query("shoot_y")<=(0-get_height()/2))
	{
		tell_object(this_player(),HIR"你的大炮已经向南瞄准到最大限度了!\n"NOR);
		return 1;
	}
	tell_object(this_player(),HIW"你将打炮的瞄准点向南移动一度！\n"NOR);
//	me->start_busy(1);
	add("shoot_y",-1);
	do_view();
	return 1;
}
int do_aimw()
{
	object me;
	me=this_player();
	if(query("sink")) return 1;
	if(me->is_busy()||me->is_fighting())
	{
		tell_object(me,HIC"你正忙着呢\n"NOR);
		return 1;
	}
	if(query("shoot_x")<=(0-get_wide()/2))
	{
		tell_object(this_player(),HIR"你的大炮已经向西瞄准到最大限度了!\n"NOR);
		return 1;
	}
	tell_object(this_player(),HIW"你将打炮的瞄准点向西移动一度！\n"NOR);
//	me->start_busy(1);
	add("shoot_x",-1);
	do_view();
	return 1;
}
int do_aime()
{
	object me;
	me=this_player();
	if(query("sink")) return 1;
	if(me->is_busy()||me->is_fighting())
	{
		tell_object(me,HIC"你正忙着呢\n"NOR);
		return 1;
	}
	if(query("shoot_x")>=get_wide()/2)
	{
		tell_object(this_player(),HIR"你的大炮已经向东瞄准到最大限度了!\n"NOR);
		return 1;
	}
	tell_object(this_player(),HIW"你将打炮的瞄准点向东移动一度！\n"NOR);
//	me->start_busy(1);
	add("shoot_x",1);
	do_view();
	return 1;
}
int do_reset()
{
	object me;
	me=this_player();
	if(query("sink")) return 1;
	if(me->is_busy()||me->is_fighting())
	{
		tell_object(me,HIC"你正忙着呢\n"NOR);
		return 1;
	}
	tell_object(this_player(),HIW"大炮炮口复位!\n");
	me->start_busy(1);
	set("shoot_x",get_wide()/2-get_x());
	set("shoot_y",get_y()-get_height()/2);
	do_view();
	return 1;
}
int get_shoot_x()
{
	int x;
	x=get_x()+query("shoot_x");
	if(x>=0&&x<get_wide())
		return x;
	else
		return -1;
}
int get_shoot_y()
{
	int y;
	y=get_y()-query("shoot_y");
	if(y>=0&&y<get_height())
		return y;
	else
		return -1;
}
int do_fire()
{
	int limit,distance,x,y,shoot_x,shoot_y,level_1,level_2,wide,height,china;
	object me;
	china=0;
	if(query("pai")=="中国") china=1;
	if(query("sink")) return 1;
	if(china)
	{
		me=this_player();
		if(me->is_busy()||me->is_fighting())
		{
			tell_object(me,HIC"你正忙着呢\n"NOR);
			return 1;
		}
		if(!query("ready"))
		{
			tell_object(this_player(),HIR"你炮膛里没有炮弹发射什么劲?\n"NOR);
			return 1;
		}
	}
	x=get_x();
	y=get_y();
	shoot_x=get_shoot_x();
	shoot_y=get_shoot_y();
	distance=(x-shoot_x)*(x-shoot_x)+(y-shoot_y)*(y-shoot_y);
	if(distance<3) 
	{
		if (china)
			tell_object(me,HIY"瞄准点太近，无法开炮!\n"NOR);
		return 1;
	}
	wide=get_wide();
	height=get_height();
	level_1=(wide/6+1)*(wide/6+1)+(height/6+1)*(height/6+1);
	level_2=(wide/3+1)*(wide/3+1)+(height/3+1)*(height/3+1);
	add("shoots",-1);
	set("ready",0);
	if(china)
		CHANNEL_D->do_channel(this_object(), "bd", HIM + query("shipname")+HIM+query("short")+HIM"开炮：" + "轰～～～～！", -1);
	else
		CHANNEL_D->do_channel(this_object(), "bd", HIM + query("shipname")+HIM+query("short")+HIM"开炮：" + "轰～～～～！", -1);
	
	if(china) me->start_busy(1);
	if(distance<level_1)
	{
		call_out("shoot",1,shoot_x,shoot_y,this_object(),me,1);
	}
	else if(distance<level_2)
	{
		call_out("shoot",3,shoot_x,shoot_y,this_object(),me,2);
	}
	else
	{
		call_out("shoot",5,shoot_x,shoot_y,this_object(),me,3);
	}	
	return 1;
}
int shoot(int shoot_x,int shoot_y,object shooter,object me,int rand)
{
	int x,y,china;
	string target,*chuansheng;
	object jwhz,chuan,cang,thischuan,all_cang;
	jwhz=load_object("/adm/daemons/jwhz.lpc");
	china=0;
	if(shooter->query("pai")=="中国") china=1;
        if(!china) rand = rand + 2;//嘿嘿，日本要差些了。
        if(random(rand)==0 && random(10) < 9)
	{//击中想击中的位置。
		x=shoot_x;
		y=shoot_y;
	}
	else
	{//偏离
		do{
			if(rand<3)
			{
				x=shoot_x+random(3)-1;
				y=shoot_y+random(3)-1;
			}
			else
			{
				x=shoot_x+random(5)-2;
				y=shoot_y+random(5)-2;
			}
		}while(x==shoot_x&&y==shoot_y);
	}
	if(x<0||y<0||x>=shooter->get_wide()||y>=shooter->get_height())
	{//打出界
		if(!china) return 1;
		if(china) 
		{
			tell_object(me,WHT"很遗憾的告诉你，你的炮弹打到海域之外了!\n"NOR);
			CHANNEL_D->do_channel(this_object(), "bd", HIM + me->query("name")+HIM"的炮弹打到海域之外去了！", -1);
		}
		return 1;
	}
	target=jwhz->position(y,x);
	if(target==FRIEND)
	{
		if(china)
		{
			tell_object(me,BNK+WHT"你击中了自己这一方的船只，你想当叛徒呀？\n"NOR);
			me->add_temp("jwhz/shooted",-1);
		}
		for(int i=0;i<sizeof(china_ship);i++)
		{
			chuan=load_object(china_ship[i]);
			if(x==chuan->get_x()&&y==chuan->get_y())
			{//击中
				chuansheng=(chuan->query("chuansheng"));
				cang=load_object(chuansheng[random(sizeof(chuansheng))]);
				if(!cang) message("vision",HIB"数据出错!"NOR,users());
				cang->set("fire",1);
				cang->set("fire_cause","击中");
				cang->set("sink_cause","击中");
				cang->checking_fire();
				cang->add_damage(30);
				CHANNEL_D->do_channel(this_object(), "bd", HIR + query("shipname")+HIR"击中"+chuan->query("shipname")+HIR"的"+cang->query("short")+HIR"！"+chuan->query("shipname")+HIR"上顿时火光冲天！", -1);
				for(int j=0;j<sizeof(chuansheng);j++)
				{
					all_cang=load_object(chuansheng[j]);
					message("vision",HIW+"你只觉得船体一震，伴随着一声巨响，你知道你的船已经被击中了!\n"NOR,all_cang);
				}
				message("vision",HIB"由于炮弹的击中，你周围顿时陷入一片火海之中!\n"NOR,cang);
				
				if(cang->is_sink()&&!cang->is_sinking())
				{
					cang->checking_sink();
					CHANNEL_D->do_channel(this_object(), "bd", HIR + cang->query("shipname")+HIR"被"+query("shipname")+HIR"击沉！", -1);
				}
			}
		}
	}
	else if(target==ENEMY)
	{
		if(china)
		{
			tell_object(me,BNK+WHT"你击中敌舰！\n"NOR);
			me->add_temp("jwhz/shooted",1);
		}
		for(int i=0;i<sizeof(japan_ship);i++)
		{
			
			chuan=load_object(japan_ship[i]);
		//	message( "channel:" + "chat",HIR + "【甲午战报】"+chinese_number(x)+" "+chinese_number(y)+" "+chinese_number(chuan->get_x())+" "+chinese_number(chuan->get_y())+"击中！！\n"NOR,users());
			if(x==chuan->get_x()&&y==chuan->get_y())
			{//击中
				
				chuansheng=(chuan->query("chuansheng"));
				cang=load_object(chuansheng[random(sizeof(chuansheng))]);
				if(!cang) message("vision",HIB"数据出错!"NOR,users());
				cang->set("fire",1);
				cang->set("fire_cause","击中");
				cang->set("sink_cause","击中");
				cang->checking_fire();
				cang->add_damage(30);
				CHANNEL_D->do_channel(this_object(), "bd", HIR + query("shipname")+HIR"击中"+chuan->query("shipname")+HIR"的"+cang->query("short")+HIR"！"+chuan->query("shipname")+HIR"上顿时火光冲天！", -1);
				for(int j=0;j<sizeof(chuansheng);j++)
				{
					all_cang=load_object(chuansheng[j]);
					message("vision",HIW+BNK"你只觉得船体一震，伴随着一声巨响，你知道你的船已经被击中了!\n"NOR,all_cang);
				}
				message("vision",HIB"由于炮弹的击中，你周围顿时陷入一片火海之中!\n"NOR,cang);
				
				if(cang->is_sink()&&!cang->is_sinking())
				{
					cang->checking_sink();
					CHANNEL_D->do_channel(this_object(), "bd", HIR + cang->query("shipname")+HIR"被"+query("shipname")+HIR"击沉！", -1);
				}
			}
		}
	}
	else
	{
		
//		message( "channel:" + "chat",HIW + "【战场描述】" + "炮弹在水面上溅起了一个巨大的水柱！\n"NOR,users());
		if(china)
		{
			tell_object(me,HIW"你发出的炮弹在水面上溅起了一个巨大的水柱！\n"NOR);
			jwhz->write_position(y,x,shooter->query("id"));
			tell_object(me,WHT"你这一炮没有击中任何目标!\n"NOR);
		}
	}
	call_out("re_peace",5,x,y,shooter);

	return 1;
}
int re_peace(int x,int y,object shooter)
{
	object jwhz;
	jwhz=load_object("/adm/daemons/jwhz");
	if(jwhz->position(y,x)==shooter->query("id"))
		jwhz->write_position(y,x,NONE);
	jwhz->update_all_ships();
	return 1;
}
