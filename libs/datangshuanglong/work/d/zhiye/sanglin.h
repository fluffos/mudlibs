// sanglin.h
// by augx@sj  10/17/2001

// Modified by mxzhao 2004/03/06 caiji => nongsang

#include <ansi.h>
#include <job_mul.h>

#define EXAM_TICK	30
#define FINISH_TICK	1800
#define TIMEOUT_TICK	120
#define DEBUGMODE	0

string* have_items =
	({"can si","yucan si","bingcan si","tiancan si","longjian si",});
string* have_items_c =
	({HIW"蚕丝",GRN"玉蚕丝",HIW"冰蚕丝",WHT"天蚕丝",HIY"龙茧蚕丝",});

void init()
{
	int fib=0;
	int i;
	string biaoji;	
	if(query("outdoors")=="长安郊外"){
		biaoji = "长安农政司布告";
		fib = 4;
	}
	if(query("show_msg")!=1 && fib>0)
        {
        	biaoji = CHINESE_D->get_title(biaoji)+"    此地出产：\n";
		for(i=0;i<fib;i++)
        		biaoji += "\t"+have_items_c[i]+NOR+"("+capitalize(have_items[i])+")"+"\n";
        	biaoji += "\n\t请与城中采购蚕子。\n\t农家以yangcan xxxx 开始养植。\n";
        	set("show_msg",1);
        	set("long",query("long")+"    林边还有一方标记(biaoji)。\n");
        	set("item_desc/biaoji",biaoji);
        	set("no_fight",1);
        }
	add_action("do_yangcan","yangcan");
	add_action("do_weishi" ,"weishi" );
	add_action("do_qingsao","qingsao");
	add_action("do_chousi" ,"chousi" );
	//add_action("do_wah", "wah");
}

int clean_up()
{
	return 1;
}

void decide_action(string u)
{
	if( !mapp(query("user/"+u)) ) return;
	set("user/"+u+"/action" , 1 + random(2) );
	if( !DEBUGMODE ) {
		set("user/"+u+"/atime"  , time() + 2*60 + random(2*60) );
		if( query("user/"+u+"/atime") > (query("user/"+u+"/start")+FINISH_TICK) )
			set("user/"+u+"/action" , 3);
	}
	else {
		set("user/"+u+"/atime"  , time() + 10 + random(20) );
		if( query("user/"+u+"/atime") > (query("user/"+u+"/start")+180) )
			set("user/"+u+"/action" , 3);
	}
}

void exam()
{
	mapping mp;
	mapping * mpv;
	string  * mpk, *overtime;
	object me;
	int i,count;

	remove_call_out("exam");

	if( !mapp(mp = query("user")) || (count=sizeof(mp))<1 ) {
		set("exam",0);
		return;
	}
	mpv = values(mp);
	mpk = keys(mp);

	overtime = ({ });
	for(i=0;i<count;i++) {
		if( time() < mpv[i]["atime"] ) continue;

		me = present(mpk[i], this_object());
		if( time() > (mpv[i]["atime"]+TIMEOUT_TICK) ) {
			if(mpv[i]["action"]==3) {
				if(me && userp(me))
					tell_object(me,RED"你错过了抽丝的时机，蚕蛹已经孵化为蝴蝶，心血都浪费掉了！\n"NOR);
				overtime += ({ mpk[i] });
				continue;
			}
			else {
				if(me && userp(me))
					tell_object(me,HIR"你错过了" + (mpv[i]["action"]==1?"喂食":"清扫") + "的时间，蚕的成长受到影响。\n"NOR);
				mpv[i]["lost"]++;
				decide_action(mpk[i]);
			}
		}
		else {
			if(me && userp(me)) {
				switch (mpv[i]["action"]) {
					case 1: tell_object(me,HIY"你该给你所养的蚕喂食了。\n"NOR); break;
					case 2: tell_object(me,YEL"你该给你所养的蚕清扫了。\n"NOR); break;
					case 3: tell_object(me,HIW"你所养的蚕已经结成蚕茧，你可以开始抽丝了。\n"NOR); break;
				}
			}
		}
	}

	for(i=0;i<sizeof(overtime);i++)
		delete( "user/" + overtime[i] );

	if( !mapp(mp=query("user")) || sizeof(mp)<1 )
		set("exam",0);
	else
		call_out("exam",EXAM_TICK);
}

//////////////////////////////////////////////////////////////////////////////
int do_yangcan(string arg)
{
	object me = this_player() ,zhongzi;
	int level,delay;

	if( objectp( me->query_temp("weapon") ) )
		return notify_fail("你必须空手才能养蚕啊。\n");
	if( !arg ) return notify_fail("你要养什么？\n");
	if ( me->is_busy() )
		return notify_fail("你正忙着呢！\n");
	level = (int)me->query_skill("nongsang",1);
	if ( level<1 ) return notify_fail("你根本就不会农桑技能啊！是不是先学习一些农桑技能(nongsang)再来养蚕啊？！\n");
	
	if ( mapp(query("user/"+me->query("id"))) )
		return notify_fail("你已经开始养蚕了呀！\n");
	if ( !objectp(zhongzi = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");
	if( !(int)zhongzi->query("canzi") )
		return notify_fail("你不能用这样东西来养蚕。\n");

	switch( zhongzi->query_level() ) {
		case 5: if(level<170) return notify_fail("你的农桑技能不够！\n"); break;
		case 7: if(level<270) return notify_fail("你的农桑技能不够！\n"); break;
		case 8: if(level<330) return notify_fail("你的农桑技能不够！\n"); break;
		case 9: if(level<390) return notify_fail("你的农桑技能不够！\n"); break;
		//case 10: if(level<400) return notify_fail("你的农桑技能不够！\n"); break;
		default: return notify_fail("你不能养这种东西！\n"); break;
	}

	set("user/"+me->query("id")+"/start", time());
	set("user/"+me->query("id")+"/product", zhongzi->query_level());
	set("user/"+me->query("id")+"/lost", 0);
	decide_action(me->query("id"));
	if( !query("exam") ) {
		call_out("exam",EXAM_TICK);
		set("exam",1);
	}

	destruct(zhongzi);
	message_vision(HIY"$N开始用蚕卵孵化蚕......\n\n"NOR, me);
	delay = 10 + random(20);
	if(wizardp(me) && (int)me->query("env/test")) delay = 6;
	me->start_busy(delay+1);
	call_out("yangcan_finish",delay*2-1,me);

	return 1;
}

void yangcan_finish(object me)
{
	if(!me) return;
	me->start_busy(-1);
	me->interrupt_me();
	message_vision(YEL"$N忙了半天，蚕总算孵化出来了。\n"NOR, me);
}

//////////////////////////////////////////////////////////////////////////////
int do_weishi(string arg)
{
	object me = this_player();
	int delay;

	if( objectp( me->query_temp("weapon") ) )
		return notify_fail("你必须空手才能喂食啊。\n");
	if( me->is_busy() )
		return notify_fail("你正忙着呢！\n");
	if( !mapp(query("user/"+me->query("id"))) )
		return notify_fail("你还没有开始养蚕，喂什么啊！\n");
	if( query("user/"+me->query("id")+"/action") != 1
	 || query("user/"+me->query("id")+"/atime") > time() )
		return notify_fail("你现在不需要喂食。\n");

	decide_action(me->query("id"));

	message_vision(HIW"$N开始用桑叶给蚕喂食......\n\n"NOR, me);
	delay = 20 + random(20);
	if(wizardp(me) && (int)me->query("env/test")) delay = 2;
	me->start_busy(delay+1);
	call_out("weishi_finish",delay*2-1,me);

	return 1;
}

void weishi_finish(object me)
{
	if(!me) return;
	me->start_busy(-1);
	me->interrupt_me();
	message_vision(HIW"$N累地满头大汗，总算都喂完了。\n"NOR, me);
}

//////////////////////////////////////////////////////////////////////////////
int do_qingsao(string arg)
{
	object me = this_player(),weapon;
	int delay;

	if( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="sao ba" )
		return notify_fail("你必须装备扫把才能清扫。\n");
	if( me->is_busy() )
		return notify_fail("你正忙着呢！\n");
	if( !mapp(query("user/"+me->query("id"))) )
		return notify_fail("你还没有开始养蚕，乱清扫什么啊！\n");
	if( query("user/"+me->query("id")+"/action") != 2
	 || query("user/"+me->query("id")+"/atime") > time() )
		return notify_fail("你现在不需要清扫。\n");

	decide_action(me->query("id"));

	message_vision(HIY"$N开始仔细的清扫养蚕用的竹篓......\n\n"NOR, me);
	delay = 10 + random(20);
	if(wizardp(me) && (int)me->query("env/test")) delay = 2;
	me->start_busy(delay+1);
	call_out("qingsao_finish",delay*2-1,me);

	return 1;
}

void qingsao_finish(object me)
{
	object tools;
	int i;
	if(!me) return;
	me->start_busy(-1);
	me->interrupt_me();
	message_vision(HIY"$N累地满头大汗，总算清扫完了。\n"NOR, me);
	for(i=0;i<3;i++) {
		if ( objectp(tools = me->query_temp("weapon")) && tools->query("id")=="sao ba" )
			tools->use();
	}
}

//////////////////////////////////////////////////////////////////////////////
int do_chousi(string arg)
{
	object me = this_player(),weapon;
	int delay;

	if( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="jian dao" )
		return notify_fail("你必须装备剪刀才能抽丝。\n");
	if( me->is_busy() )
		return notify_fail("你正忙着呢！\n");
	if( !mapp(query("user/"+me->query("id"))) )
		return notify_fail("你还没有开始养蚕，抽什么丝啊！\n");
	if( query("user/"+me->query("id")+"/action") != 3
	 || query("user/"+me->query("id")+"/atime") > time() )
		return notify_fail("现在蚕还没有开始结茧呢。\n");

	decide_action(me->query("id"));

	message_vision(YEL"$N开始小心翼翼的从蚕茧中抽取蚕丝......\n\n"NOR, me);
	delay = 10 + random(20);
	if(wizardp(me) && (int)me->query("env/test")) delay = 2;
	me->start_busy(delay+1);
	call_out("chousi_finish",delay*2-1,me);

	return 1;
}

void chousi_finish(object me)
{
	object tools,obj;
	int i,j,k,level,improve,bu;
	mapping mp;
	float updown;

	if( !me ||!userp(me) ) return;
	me->start_busy(-1);
	me->interrupt_me();
	if( !mapp(mp = query("user/"+me->query("id"))) ) return;
	level = (int)me->query_skill("nongsang",1);
	if(level>390) level = 390 + (level-390)*11;

	for(i=0;i<3;i++) {
		if ( objectp(tools = me->query_temp("weapon")) && tools->query("id")=="jian dao" )
			tools->use();
	}

	switch ( mp["product"] ) {
		case 5: i = 220; break;
		case 7: i = 330; break;
		case 8: i = 410; break;
		case 9: i = 640; break;
		case 10: i = 900; break;
	}
	if ( i>(level*2) ) i=level*2;
	
	improve = me->query_int(1)*i/level;
	improve /= 3;

	switch( mp["product"] ) {
		case 5: i = 250; break;
		case 7: i = 450; break;
		case 8: i = 550; break;
		case 9: i = 850; break;
		case 10: i = 1100; break;
	}
	if( level > i ) level = i;

	updown = WORKER_D->updown(me,"nongsang");
	bu = to_int((13 * 100 * level / i)*updown);
	bu = bu*2/3 + random(bu*2/3);
	if( mp["lost"] ) bu = bu - bu * (1+mp["lost"]*2)/10;
	bu = bu / 100;
	if(bu<1) bu=1;

	j = 0;
	for(i=0;i<bu;i++) {
		//obj = new(__DIR__"obj/buliao");
		obj = WORKER_D->mater_random(me,2,mp["product"]);
		if(!obj) return;
		//obj->set_level(mp["product"]);
		obj->move(environment(me));
		if( !obj->move(me) ) {
			j = 1;
			if( sizeof(all_inventory(environment(me))) > 49 )
				destruct(obj);
		}
	}

	message_vision(YEL"$N总共抽得到"+CHINESE_D->chinese_number(bu)+obj->query("unit")+obj->name()+"。\n"NOR, me);
	if(j) message_vision(YEL"但是$N拿不动那么多，只好把几"+obj->query("unit")+obj->name()+"放到地上。\n"NOR, me);

	improve *= bu;
	improve = improve*2/3 + random(improve*2/3);
	//improve = improve*ZY_NONGSANG_MUL/100;
	i = improve * 12;
	WORKER_D->check_impove(me,"nongsang",i,2);
	j = random(improve)/2;
	
	j = me->add_exp_combat( j ,0,"农桑",1);
	//me->add("combat_exp", j);
	
	k = random(improve)/4;	me->add("potential", k);
	if ( (int)me->query("potential", 1) > (int)me->query("max_pot", 1) )
		me->set("potential" , me->query("max_pot", 1) );

	log_file("job/wnongsang",sprintf("%s(%s)：bu:%d,lost:%d,lvl:%d;cj:%d,exp:%d,pot:%d;ncj:%d,nexp:%d\n",
		me->query("name"),me->query("id"),bu,mp["lost"],mp["product"],i,j,k,me->query_skill("nongsang",1),me->query("combat_exp")),me);
	delete("user/"+me->query("id"));
}
