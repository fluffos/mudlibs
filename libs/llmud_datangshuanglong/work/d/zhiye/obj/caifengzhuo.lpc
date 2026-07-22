// caifengzhuo.c
// by augx@sj 10/9/2001
// modified by Ciwei@SJ

// Modified by mxzhao 2004/03/06 caijian => zhizao

#include <ansi.h>
#include <job_mul.h>
inherit ITEM;

void create()
{
	set_name(HIY"裁缝桌"NOR, ({ "caifeng zhuo" , "zhuo" }));
	set_weight(1000000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long",
			HIY"这是一张巨大的裁缝桌，有很多年轻的裁缝们在桌旁日月的忙碌着。\n\n"NOR+
			"你可以用在这张桌子上：
			
			织造(zhizao)：zhizao 防具种类 原料 [with 佩宝]
			（现在可以织造出的防具有：cap，boot，coat，armor，mantle，belt，glove）
			
			修理(xiu):     xiu 防具id
			");
			
			set("value", 3000);
		set("no_get", 1);
	}
	setup();
}

void init()
{
	add_action("do_zhizao","zhizao");
	add_action("do_xiu","xiu");
	add_action("do_xiu","fix");
	//add_action("do_rename","gaiming");
	//add_action("do_rename","rename");
	
	if(inherits(ROOM,environment(this_object()))!=0	) environment(this_object())->set("no_fight",1);
}

int do_zhizao(string arg)
{
	object me = this_player() ,obj,obj2,weapon,fujia;
	int delay,level,i,j,k,time;
	string* status = ({});
        mapping temp;
	string type,bu;
	string jade;//hehe
	mapping myskill;
	mapping shuxing = ([]);
	float updown;
	
	level = (int)me->query_skill("zhizao",1);
	if (me->is_busy()) return notify_fail("你正忙着呢！\n");
	if (me->is_fight()) return notify_fail("你正忙着呢！\n");
	if (!arg) return notify_fail("你要织造什么？\n");        
	if ( sscanf(arg,"%s %s",type,bu)<2 )
		return notify_fail("你要用什么织造什么？\n");
	if(sscanf(bu,"%s with %s",bu,jade)==2)
	{        	
		if ( !objectp(fujia = present(jade, me)) )
			return notify_fail("你身上没有这样东西。\n");
		if ( !objectp(obj = present(bu, me)) )
			return notify_fail("你身上没有这样东西。\n");
		
		if(fujia->query("material_for")!="armor") return notify_fail("你左看右看总觉得"+fujia->name()+"与"+obj->name()+"不合适。\n");
		switch( (int)fujia->query("material_level") ) {
                case 1: break;
                case 2: if(level<120) return notify_fail("你的织造技能不够！\n"); break;
                case 4: if(level<220) return notify_fail("你的织造技能不够！\n"); break;
                case 6: if(level<330) return notify_fail("你的织造技能不够！\n"); break;                
                case 8: if(level<390) return notify_fail("你的织造技能不够！\n"); break;                
                case 10: if(level<400) return notify_fail("你的织造技能不够！\n"); break;
        	}			
	}        
	if ( !objectp(obj = present(bu, me)) )
		return notify_fail("你身上有这样东西吗？\n");
	obj = present(obj->query("id"), me);
	if ( !objectp(obj2= present(obj->query("id")+" 2", me)) )
		return notify_fail("你必须用两匹"+obj->query("name")+"来织造。\n");
	if( !(int)obj->query("bu") || !(int)obj->query("level") )
		return notify_fail("在这里只能织造布匹或丝绸来。\n");
	if( !(int)obj2->query("bu") || !(int)obj2->query("level") )
		return notify_fail("在这里只能织造布匹或丝绸来。\n");
	if ( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="jian dao" )
		return notify_fail("你必须装备剪刀才能来织造。\n");
	if ( !weapon->query("worker_tool"))
		return notify_fail("你必须装备剪刀才能来织造。\n");
	if ( !wizardp(me) && (time()<(int)me->query("worker/zhizao")) )
		return notify_fail("你刚刚织造完，感觉过于劳累！\n");
	
	time = time()- me->query("pk_time");
	if ( time < 432000)
		return notify_fail("你目前的状态无法织造。\n");
	
	if ( level<1 ) return notify_fail("你根本就不会织造！是不是先学习一些织造技能(zhizao)再来织造防具啊？！\n");
	
	
	switch(type) {
	case "cap":
	case "boot":
	case "coat":
	case "armor":
	case "mantle":
	case "belt":
	case "glove": break;
	default:
		return notify_fail("这里不能织造出这样东西。\n");
	}
	
	switch( (int)obj->query_level() ) {
	case 1: break;
	case 2: if(level<40)  return notify_fail("你的织造技能不够！\n"); break;
	case 3: if(level<80)  return notify_fail("你的织造技能不够！\n"); break;
	case 4: if(level<120) return notify_fail("你的织造技能不够！\n"); break;
	case 5: if(level<170) return notify_fail("你的织造技能不够！\n"); break;
	case 6: if(level<220) return notify_fail("你的织造技能不够！\n"); break;
	case 7: if(level<270) return notify_fail("你的织造技能不够！\n"); break;
	case 8: if(level<330) return notify_fail("你的织造技能不够！\n"); break;
	case 9: if(level<390) return notify_fail("你的织造技能不够！\n"); break;
	case 10: if(level<400) return notify_fail("你的织造技能不够！\n"); break;
	}
	myskill = me->query("forging");//当它Quest了
	
	if (!mapp(myskill)) return notify_fail("你还不会任何工匠技能！\n");
	
	if (member_array(type,keys(myskill)) == -1)
		return notify_fail("对于这种防具，您了解不多，还不会织造！\n");
			
	if((int)obj->query_level()!=11){
		if(level>220) k = 10000*level*(int)obj->query_level()/15;
		else k = 10000*level*(int)obj->query_level()/20;
		if(me->query("registered")==3) k = k*2/3;
		if(k>=10000){
			switch(MONEY_D->player_pay(me, k,0,1))
			{
				case 0:return notify_fail("你在钱庄的存款不足支付此次织造。\n");
				default:write("你为此次织造支付了"+MONEY_D->money_str(k)+"。\n");
			}
			//if(me->query("balance")<k) return notify_fail("你在钱庄的存款不足支付此次锻造。\n");
			//me->add("balance",-k);
			//write("你为此次锻造支付了"+MONEY_D->money_str(k)+"。\n");
		}
	}
	//add 工匠技能 这不是职业的 任何人都可以学习 hehe	
	shuxing = WORKER_D->map_add(shuxing,obj->query("material_prop"));
	shuxing = WORKER_D->map_add(shuxing,obj2->query("material_prop"));
	if(objectp(fujia))
	{
		temp = fujia->query("material_props");
        	if(mapp(temp)) status = copy(values(temp));
		shuxing = WORKER_D->map_add(shuxing,fujia->query("material_prop"));
	}	
	//你细心得将棉花（蚕丝）抽丝剥茧，纺纱成布……
	message_vision(HIW"$N细心得将"+obj->query("name")+HIW"抽丝剥茧，纺纱成布……\n"NOR, me);
	obj->change_name();
	message_vision(HIY"$N再把"+obj->query("name")+HIY"放到裁缝桌上，拿起剪刀和尺子开始织造......\n"NOR, me);
	me->set_temp("pending/zhizao",1);
		
	if(level>390) level = 390 + (level-390)*11;
	switch((int)obj->query_level()) {
		case 1: i = 40;  if(level>100) level=100;j=1; break;
                case 2: i = 80;  if(level>150) level=150;j=1; break;
                case 3: i = 120;j=1;
                	if(level>200) j +=random(2);
                	if(level>200) level=200;break;
                case 4: i = 170; if(level>300) level=300;j=2; break;
                case 5: i = 800;j=2;
                	if(level>350) j +=random(2);
                	if(level>350) level=350;break;
                case 6: i = 999; if(level>450) level=450;j=3; break;
                case 7: i = 2000;j=3;
                	if(level>440) j +=random(2);
                	if(level>500) level=500;break;
                case 8: i = 3000;if(level>500) level=500;j=4; break;
                case 9: i = 9999;j=4;
                	if(level>500) j +=random(2);
                	if(level>500) level=500;break;
                case 10: i = 20000;if(level>600) level=600;j=5; break;
		/*
	case 1: i = 40;  if(level>100) level=100;j=1; break;
	case 2: i = 80;  if(level>150) level=150;j=1; break;
	case 3: i = 120; if(level>200) level=200;j=1; break;
	case 4: i = 170; if(level>300) level=300;j=2; break;
	case 5: i = 800; if(level>350) level=350;j=3; break;
	case 6: i = 999; if(level>450) level=450;j=3; break;
	case 7: i = 2000;if(level>500) level=500;j=3+random(2); break;
	case 8: i = 3000;if(level>500) level=500;j=3+random(2); break;
	case 9: i = 9999;if(level>500) level=500;j=3+random(3); break;
	case 10: i = 20000;if(level>600) level=600;j=5; break;	
	*/
	/////////////////	
	case 11:
		if(objectp(present("bosi cai", me))) i=500; else i=0;
		level = 250;
		j = 1;
		break;
	}
	if(wizardp(me) && me->query("env/test") && i>500) i=500;
	
	delay = 10 + random(20);
	k = random(level+i);
	
	updown = WORKER_D->updown(me,type);
	
	//if( k>=((level+i)/2-level/2) && k<=((level+i)/2+level/2) ) 
	if(objectp(fujia) || k>=to_int(((level+i)/2-level/4)/updown) && k<=to_int(((level+i)/2+level/4)*updown) ) {
		if(wizardp(me) && (int)me->query("env/test")) delay = 6;
		//if (j>3) {
		//	WORKER_D->update_UniqueValues("armor","","");
		//	delay = 60;
		//	if(wizardp(me) && (int)me->query("env/test")) delay = 10;
		//}
		if( (int)obj->query_level() != 11 )
			call_out("zhizao_make",delay,me,type,j,obj,delay,shuxing,status);
		else
			call_out("zhizao_finish",delay*2-1,j,me,obj,type,1);
	}
	else {
		if(wizardp(me) && (int)me->query("env/test")) delay = 3;
		call_out("zhizao_finish",delay*2-1,j,me,obj,type,0);
	}
	
	me->start_busy(delay+1);
	destruct(obj2);
	if(objectp(fujia)) destruct(fujia);
	return 1;
}

void zhizao_make(object me,string type,int qua,object obj,int delay,mapping shuxing,string* status)
{
	object wp,shi;
	string str,st;
	
	if(!objectp(me) || !userp(me) || !objectp(obj)) return;
	/*
	if( qua>3 && WORKER_D->query_UniqueValues("armor","") <0 ) {
	tell_object(me , "网络错误：无法连接同步服务器，你将无法织造出高等级的防具！\n");
	qua = 3;
	delay = 10;
	}
	if( qua==5 && WORKER_D->query_UniqueValues("armor",me->query("id")) <1 ) {
	tell_object(me , "一级防具已经达到限制数，无法织造！\n");
	qua = 3;
	delay = 10;
	}
	if( qua==4 && WORKER_D->query_UniqueValues("armor2",me->query("id"))<1 ) {
	tell_object(me , "二级防具已经达到限制数，无法织造！\n");
	qua = 3;
	delay = 10;
	}
	*/
	wp = WORKER_D->make_armor(me,type,qua,obj->query("material"),shuxing,status);
	wp->set("value" , obj->query("value") * (25+random(40)) / 10 );
	wp->set("armor_mp/value" , wp->query("value"));
	if(!wp) {
		tell_object(me, "防具生成出错! \n");
		return;
	}
	if( !environment(this_object()) || !(shi=present("lao caifeng",environment(this_object()))) ) {
		tell_object(me, "无法找到老裁缝! \n");
		return;
	}
	if(!wp->move(shi)) {
		tell_object(me, "防具移动错误! \n");
		return;
	}
	me->set_temp("worker/wp" , wp);
	
	if( qua>3 ) {
		if ( stringp(wp->query("name_st")) && strlen(wp->query("name_st"))>3 )
			st = wp->query("name_st");
		else
			st = "";
		str = sprintf("save_id=%s&time=%d&level=%d&wscore=%d&wuser=%s&wname=%s&details=%s",wp->query("armor_mp/save_id"),time(),qua,
			WORKER_D->armor_rank(wp),wp->query("maker"),wp->query("name")+"("+wp->query("id")+")",st);
		//WORKER_D->update_UniqueValues("addarmor",str,wp->query("armor_mp/save_id"));
	}
	call_out("zhizao_finish",delay,qua,me,obj,type,1);
}

void zhizao_finish(int j,object me,object obj,string type,int win)
{
	object tools,wp;
	string str;
	int level, bu, i=1, improve;
	
	if(!objectp(me) || !userp(me) || !objectp(obj)) return;
	me->start_busy(-1);
	me->interrupt_me();
	tools = me->query_temp("weapon");
	level = (int)me->query_skill("zhizao",1);
	if(level>390) level = 390 + (level-390)*11;
	bu = (int)obj->query_level();
	
	message_vision(HIY"$N忙碌了好一阵之后，总算织造完了......\n"NOR, me);
	me->delete_temp("pending/zhizao",1);
	if ( objectp(tools) && tools->query("id")=="jian dao" ) tools->use();
	
	switch(bu) {
	case 1: i = 40;  break;
	case 2: i = 80;  break;
	case 3: i = 120; break;
	case 4: i = 170; break;
	case 5: i = 220; break;
	case 6: i = 270; break;
	case 7: i = 330; break;
	case 8: i = 390; break;
	case 9: i = 500; break;
	case 10:i = 550; break;	
	case 11: i = level; break;
	}
	i = 100 - (level - i)/2;
	if(i>200) i = 200;
	if(i< 10) i = 10;
	
	if ( me->query_temp("user_type") != "worker")
		improve = me->query_int(1)*i/100;
	else
		improve = me->query_int()*i/100;
	
	//improve = improve*ZY_ZHIZAO_MUL/100;
	
	if( win ) {
		if(bu!=11) {			
			WORKER_D->check_impove(me,"zhizao",improve*9,j>=4?3:2);
			//me->improve_skill("zhizao", improve*9);
		}
		else {
			i = (300 + level/2) * 7/5;
			i = i*2/3 + random(i*2/3);
			
			me->add_temp("worker/job3_zhizao",WORKER_D->check_impove(me,"zhizao",i,2));
			//if(me->query_skill("zhizao",1)<220){
			//	me->improve_skill("zhizao", i);
			//	me->add_temp("worker/job3_zhizao",i);
			//}
			obj->change_state2(type);
			obj->set("makeby",me->query("id"));
		}
		if ( environment(me)->query("no_zhiye")
			|| me->query_temp("user_type") == "worker") {
				me->add_exp_combat(random(improve*4/5),0,"织造",1);
				//me->add("combat_exp", random(improve*4/5));
				me->add("potential", random(improve/5*3));
		}
		if(bu!=11) {			
			wp = (object)me->query_temp("worker/wp");
			if(!wp) return;			
			me->delete_temp("worker/wp");
			//if( wp->query("armor_mp/imbued")>3 && WORKER_D->query_UniqueValues("addarmor",wp->query("armor_mp/save_id"))<0 ) {
			//tell_object(me , "网络错误：无法连接同步服务器，防具生成失败！\n");
			//destruct(wp);
			//return;
			//}
			if(!wp->move(me)) {
				wp->move(environment(me));
				tell_object(me , "但是你拿不动了！\n");
			}
			destruct(obj);
		}
		else {
			wp = obj;
		}
		
		message_vision(HIC"$N很得意的拿起刚织造好的"+wp->name()+HIC"左看右看。\n"NOR, me);
	}
	else {
		//if(me->query_skill("zhizao",1)<220) me->improve_skill("zhizao", improve*3);
		WORKER_D->check_impove(me,"zhizao",improve*3,2);
		if ( environment(me)->query("no_zhiye")
			|| me->query_temp("user_type") == "worker")
		{
				me->add_exp_combat(random(improve/3),0,"织造",1);
				//me->add("combat_exp", random(improve/3));
				me->add("potential", random(improve/5));
		}
		message_vision(HIC"但是$N却沮丧的发现剪坏了一条边！\n"NOR, me);
		destruct(obj);
	}
	if ( (int)me->query("potential", 1) > (int)me->query("max_pot", 1) )
		me->set("potential" , me->query("max_pot", 1) );
	me->set("worker/zhizao",time()+10+random(20));
	
	str = WORKER_D->worker_title(me,"zhizao");
	// change to temp title
	me->set_temp("title", str);	
}

int do_xiu(string arg)
{
	object me = this_player() ,obj,obj2,weapon;
	int delay,level;
	string str;
	
	if (me->is_busy()) return notify_fail("你正忙着呢！\n");
	if (me->is_fight()) return notify_fail("你正忙着呢！\n");
	if (!arg) return notify_fail("你要修什么？\n");
	if ( !objectp(obj = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");
	if ( !mapp(obj->query("armor_prop")) || !(int)obj->query("imbued") )
		return notify_fail("在这里只能维修由玩家织造出的防具。\n");
	if ( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="jian dao" )
		return notify_fail("你必须装备剪刀才能来维修防具。\n");
	if ( obj->query("armor_mp/dur") >= obj->query("armor_mp/max_dur") )
		return notify_fail("这件防具完好无损，无需修理。\n");
	if ( obj->query("dur") <= 0  )
		return notify_fail("这件防具已经彻底损坏了，无法修理。\n");
	
	switch( (string)obj->query("material") ) {
	case "longcansi": str =HIY"龙茧蚕丝"NOR;break;
	case "tiancansi": str = WHT"天蚕丝"NOR; break;
	case "bingcansi": str = HIW"冰蚕丝"NOR; break;
	case "yucansi":   str = GRN"玉蚕丝"NOR; break;
	case "mumianhua": str = HIY"木棉花"NOR; break;
	case "cansi":     str = HIW"蚕丝"NOR; break;
	case "zhuma":     str = HIY"苎麻"NOR; break;
	case "dama":      str = YEL"大麻"NOR; break;
	case "yama":      str = YEL"亚麻"NOR; break;
	case "mianhua":   str = HIW"棉花"NOR; break;
	default: str = "布料"; break;
	}
	if ( !objectp(obj2 = present((string)obj->query("material"), me)) )
		return notify_fail("你需要一匹"+str+"，才能维修这件防具。\n");
	
	level = (int)me->query_skill("zhizao",1);
	switch( (int)obj2->query_level() ) {
	case 1: break;
	case 2: if(level<40)  return notify_fail("你的织造技能不够！\n"); break;
	case 3: if(level<80)  return notify_fail("你的织造技能不够！\n"); break;
	case 4: if(level<120) return notify_fail("你的织造技能不够！\n"); break;
	case 5: if(level<170) return notify_fail("你的织造技能不够！\n"); break;
	case 6: if(level<220) return notify_fail("你的织造技能不够！\n"); break;
	case 7: if(level<270) return notify_fail("你的织造技能不够！\n"); break;
	case 8: if(level<330) return notify_fail("你的织造技能不够！\n"); break;
	case 9: if(level<390) return notify_fail("你的织造技能不够！\n"); break;
	}
	
	message_vision(HIY"$N开始仔细的修复"+obj->query("name")+HIY"，不时用剪刀和针线缝缝补补......\n\n"NOR, me);
	delay = 15 + random(30);
	if(wizardp(me) && (int)me->query("env/test")) delay = 3;
	me->start_busy(delay);
	destruct(obj2);
	call_out("xiu_finish",delay*2-1,me,obj);
	return 1;
}

int decvar(object ob,string type,int times,int decmin,int min)
{
	int i,j;
	
	if( times <= 0 ) return 0;
	i = (int)ob->query(type) * 100;
	if( i == 0 ) return 0;
	decmin *= 100;
	min *= 100;
	
	j = i / times;
	if( j < decmin ) j = decmin;
	i = i - j;
	if( i < min ) i = min;
	
	ob->set(type,i/100);
	return i/100;
}

void xiu_finish(object me,object obj)
{
	object tools;
	int i;
	
	if(!objectp(me) || !userp(me) || !objectp(obj) ) return;
	
	message_vision(HIY"$N仔细的维修"+obj->query("name")+HIY+"，总算大致恢复了它的原貌。\n"NOR, me);
	
	WORKER_D->check_impove(me,"zhizao",me->query_int(),2);
	//me->improve_skill("zhizao", me->query_int());	
	i = decvar(obj,"armor_mp/max_dur",9,10,100);
	obj->set("dur",i);
	obj->set("armor_mp/dur",i);
	obj->set("armor_mp/max_dur",i);
	
	decvar(obj,"armor_prop/armor",5+random(8),5,5);
	decvar(obj,"armor_prop/qi",5+random(8),50,10);
	decvar(obj,"armor_prop/jing",5+random(9),50,10);
	decvar(obj,"armor_prop/jingli",5+random(9),50,10);
	decvar(obj,"armor_prop/neili",5+random(8),50,10);
	decvar(obj,"armor_prop/dodge",5+random(9),3,1);
	decvar(obj,"armor_prop/parry",5+random(9),3,1);
	
	i = decvar(obj,"armor_mp/storeneili",8,100,100);
	obj->set("storeneili",i);
	i = decvar(obj,"armor_mp/decdamage",8,3,1);
	obj->set("decdamage",i);
	i = decvar(obj,"armor_mp/value",6,1,1);
	obj->set("value",i);
	
	obj->save_weapon(me);
	
	tools = me->query_temp("weapon");
	if ( objectp(tools) && tools->query("id")=="jian dao" ) tools->use();
}
