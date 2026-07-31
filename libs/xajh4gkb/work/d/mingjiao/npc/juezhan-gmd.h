// xuan-ku.h for fight and get letter from Xuan
#include <ansi.h>
string *names = ({
    "song yuanqiao",
    "kongwen dashi",
    "mie jue",
    "xian yutong",
    "he taichong",
	"ban shuxian",
    "tang wenliang",
    "zong weixia",
});
string *dirs = ({
    "/d/wudang/sanqingdian",
	"/d/shaolin/shuitan",
	"/d/emei/qingxiudong",
	"/d/huashan/chaopath1",
	"/d/kunlun/dt",
	"/d/kunlun/kjt",
	"/d/gaochang/kongtong",
	"/d/gaochang/kongtong",
});
string ask_juezhan()
{
    mapping skl; 
	object fighter, me, room, monk;
    string *sname;
    int i,j;
    fighter = this_player();
    me = this_object();

    skl = fighter->query_skills();
    sname  = keys(skl);
	for(i=0; i<sizeof(skl); i++) 
	{
		if (skl[sname[i]] < 500) 
			return RANK_D->query_respect(fighter) +  "功夫未学到家，没有资格参加光明顶决战。";
	}
//	if( fighter->query("guangmingding_winner") )
//		return RANK_D->query_respect(fighter) +  "已然战败六大派，可喜可贺。";
//	if ( !(int)fighter->query_temp("jm_taohua3"))
//		return RANK_D->query_respect(fighter) +  "你与明教无任何渊源，何必来趟这趟浑水！";
	if ( me->query("guangmingding_fighter") )
		return RANK_D->query_respect(fighter) +  "，今日已有人击退了六大派，六大派高手暂时退下山了。";
	
	fighter->set_temp("guangmingding_tiaozhan", 1);
	message_vision(HIR"\n杨逍说道：六大派围攻光明顶，声势浩大，你可在此协助我教击退六大派。。。\n"NOR,fighter);
	me->set("guangmingding_fighter", fighter->query("id"));
	message_vision("\n杨逍急匆匆的去通知明教众人，准备与六大派决一死战。\n", fighter);
	fighter->move("/d/mingjiao/guangming-ding");
	for(j=0; j<8; j++) 
	{
		if(!( room = find_object(dirs[j])) ) room = load_object(dirs[j]);
		me->move(room);
		if( !objectp(monk = present(names[j], room) ))
        {
			me->move("/d/mingjiao/guangming-ding");
			message_vision("\n杨逍兴冲冲的走了过来。\n\n", fighter);
			call_out("do_back", 5, me );
			return "哈哈，六大派高手还未上山，就已经全军覆没了。\n";    
		}
		message("vision", "\n杨逍神情肃穆的走了过来，对你说到：六大派攻上光明顶了，请立刻准备。\n", room);
		monk->move("/d/mingjiao/guangming-ding");
		message("vision", monk->query("name") + "大喝一声："HIC+monk->query("family/family_name")+NOR"弟子攻上光明顶！\n", room);
	}
	me->move("/d/mingjiao/guangming-ding");
	call_out("waiting", 3, me);
	return "今日六大派围攻光明顶，"+RANK_D->query_respect(fighter)+"定要助我教一臂之力。\n";
}
int waiting(object me)
{
    object fighter;
    int wait_time;
    if( wait_time == 60 )
    {
        message_vision( HIG"杨逍说道：看来六大派已经被五行旗击败，是无法到达山顶了！\n\n"NOR,environment(me));
        call_out("do_back", 1, me);     
    }
    if( !objectp( fighter = present( me->query("guangmingding_fighter"), environment(me) ) ) )
    {
        wait_time++;
        call_out("waiting", 1, me);
    }
	else if( !present("yang xiao", environment(me)) || !fighter->query_temp("guangmingding_tiaozhan") )
    {
        if( random(10) == 0 ) 
        message_vision(HIG"\n杨逍说道：六大派实力不足，至今还未能攻上山，" + RANK_D->query_respect(fighter) + "稍等片刻。\n"NOR,environment(me));
        wait_time++;
        call_out("waiting", 1, me);
    }
    else 
		call_out("preparing", 1, me, fighter);
    return 1;
}
int preparing(object me, object fighter)
{
	object monk, room;
	if(!( room = find_object("/d/mingjiao/guangming-ding")) ) room = load_object("/d/mingjiao/guangming-ding");

	monk = present("yang xiao", room);
	if (monk)
	{
		message("vision", HIB"杨逍与下属教众低头说了几句。\n"NOR, room );
		if ((string)fighter->query("family/family_name")) message("vision", HIG"\n"+ monk->query("name") +"点了点头，说道：今日有"HIY" "+fighter->query("family/family_name")+" "HIM""+fighter->query("family/master_name")+" "HIG"的传人协助明教，与六大派决一胜负。\n\n"NOR, room);
		else message("vision", HIG"\n"+ monk->query("name") +"点了点头，说道：今日有武林高手协助明教，与六大派决一胜负。\n\n"NOR, room);
	}

	message("channel:chat", HIY"【江湖恩怨】"HIY + "杨逍大声喝到：今日六大派围攻光明顶，我教得"+ fighter->query("name") +"相助，必将战胜六大派！\n\n"NOR,users() );
	message("vision", HIC"只听四周响起沙沙的脚步声，六大派高手杀气腾腾的围攻过来，\n\n"NOR, room);
	room->delete("exits");
	message("vision", HIG"少林 空闻大师"HIM"大喝一声：我寺空见神僧死于谢逊之手，必当剿灭魔教！\n"NOR,room);
	message("vision", HIC"武当 宋远桥"HIM"大喝一声：魔教杨逍夺我殷师弟所爱就罢了，却将其暗算致残，必定是魔教所为！\n"NOR,room);
	message("vision", HIB"峨嵋 灭绝师太"HIM"大喝一声：魔教弟子，人人得而诛之！\n"NOR,room);
	message("vision", HIY"华山 鲜于通"HIM"大喝一声：谢逊杀我派白恒师弟，当诛！\n"NOR,room);
	message("vision", HIY"昆仑 何太冲"HIM"大喝一声：谢逊乱杀无辜，杀人偿命！\n"NOR,room);
	message("vision", HIW"昆仑 班淑娴"HIM"大喝一声：谢逊乱杀无辜，杀人偿命！\n"NOR,room);
	message("vision", HIG"崆峒 唐文亮"HIM"大喝一声：明教谢逊盗我派七伤拳，必爆此仇！\n"NOR,room);
	message("vision", HIC"崆峒 宗维侠"HIM"大喝一声：明教谢逊盗我派七伤拳，必爆此仇！\n"NOR,room);
	fighter->delete_temp("guangmingding_tiaozhan");
	fighter->delete_temp("beat_count");
	fighter->set_temp("fighting", 1);
	call_out("fighting", 5, me, fighter, 0);
	return 1;
}
int fighting(object me, object fighter, int count)
{
	object monk1, room1;
	int i;
	if(!( room1 = find_object("/d/mingjiao/guangming-ding")) ) room1 = load_object("/d/mingjiao/guangming-ding");
	if( count <= 300 ) 
	{
		message("vision", HIR"六大派高手俞攻俞急，攻势不断加强！\n" NOR, fighter);
		for(i=0; i<8; i++) 
		{
			monk1 = present(names[i], room1);
			if (monk1)
			{
				if (!monk1->is_fighting(fighter)) monk1->fight_ob(fighter);
				if (!living(monk1) || monk1->query("qi") <= monk1->query("max_qi")*50/100 ) fighter->set_temp("beat_count/"+(1+i),monk1->query("id"));
			}
			else fighter->set_temp("beat_count/"+(1+i),names[i]);
		}  		
    } else
	{
		message("vision", HIR"你与六大派激战良久，一时难分高下，双方暂时休战！\n" NOR, fighter);
		message("channel:chat", HIM"【江湖传言】"HIM + "听说"+fighter->query("name")+"实力不济，与六大派苦斗多时，还是败下阵来，遭受六大派惩戒！\n"NOR,users() );
		if (fighter->query("xyzx_sys/level", 1)>10) fighter->add("xyzx_sys/level", -1);
		call_out("do_back", 5, me );
	}
	if( !find_player(me->query("guangmingding_fighter")) || !objectp(present(me->query("guangmingding_fighter"), environment(me)) ) || !living(fighter) || fighter->query("qi") <= fighter->query("max_qi")*30/100 || fighter->query("qi") <=1)
	{
		if( objectp(present(me->query("guangmingding_fighter"), environment(me)) )) 
		{
			fighter->delete_temp("fighting");
			fighter->delete_temp("beat_count");
		}
		message("vision", HIG"杨逍说道："+RANK_D->query_respect(fighter)+"实力不济，难以击退六大派！\n"NOR,environment(me));
		message("channel:chat", HIM"【江湖传言】"HIM + "听说"+fighter->query("name")+"不自量力，帮助明教迎战六大派，结果惹怒六大派高手，遭受六大派惩罚！\n"NOR,users() );
		command("sigh");
		if (fighter->query("xyzx_sys/level", 1)>10) fighter->add("xyzx_sys/level", -1);
		call_out("do_back", 5, me );
    }
	else if( fighter->query_temp("beat_count/1") && fighter->query_temp("beat_count/2") && fighter->query_temp("beat_count/3") && fighter->query_temp("beat_count/4") && fighter->query_temp("beat_count/5") && fighter->query_temp("beat_count/6") && fighter->query_temp("beat_count/7") && fighter->query_temp("beat_count/8"))
	{	
		command("chat 恭喜"+fighter->name()+"击败六大派，顿时你在江湖中的威名远播！\n");
		call_out("do_recruit", 5, me, fighter);
	}
	else
	{
		count++;
		call_out("fighting", 3, me, fighter, count);
	}
 
	return 1;
}
int do_recruit(object me, object fighter)
{
	int lev_add;
	fighter->delete_temp("beat_count");
	fighter->delete_temp("fighting");
//	fighter->set("guangmingding_winner", 1);
	lev_add = 20+200000/((int)fighter->query("xyzx_sys/level",1)+1000);
	if (!(int)fighter->query("array/gmd_exp"))
	{
		fighter->add("potential", 10000000);
		fighter->add("xyzx_sys/level", lev_add, 1);
		fighter->set("array/gmd_exp", 1);
		message("vision", HIR"恭喜你帮助明教击退六大派，获得了明教嘉奖！\n"NOR,fighter);
	}
	if ((int)fighter->query_temp("jm_mingjiao2") && fighter->query("family/family_name") == "明教")
	{//明教解密
		fighter->set_temp("jm_mingjiao3",1);
		message("vision", HIM"你武功盖世，帮助明教击退六大派高手，在明教中威望大增。\n"NOR,fighter);
		message("vision", HIM""+RANK_D->query_respect(fighter)+"你可以去找张教主复命了。\n"NOR,fighter);
	}
	if (fighter->query("family/family_name") == "明教")
	{
		command("bow");
		message("vision", HIC"杨逍说道：" + RANK_D->query_respect(fighter) + "能在"+fighter->query("age")+"岁之时击败六大派，实乃本派精英！\n"NOR,environment(me));
		call_out("do_back", 5, me );
	}
	else
	{
		message("vision", HIC"杨逍说道：你助我教击退六大派，我教上下必将铭刻于心！\n"NOR,environment(me));
		call_out("do_back", 5, me );
	}
	
	return 1;
}
int do_back(object me)
{
	object monk1, room1, room2;
	int i;
	message("vision", HIY"杨逍说道：光明顶之战结束。\n"NOR, environment(me) );
    
	if(!( room1 = find_object("/d/mingjiao/guangming-ding")) ) room1 = load_object("/d/mingjiao/guangming-ding");
	for(i=0; i<8; i++) 
	{
		if(!( room2 = find_object(dirs[i])) ) room2 = load_object(dirs[i]);
		if( objectp( monk1 = present(names[i], room1) ));
		if (monk1) monk1->move(room2);
    }
//	me->delete("guangmingding_fighter");
//	me->move("/d/mingjiao/sanqingdian");
	room1->set("exits/west", "/d/mingjiao/tingtang");
	room1->set("exits/north", "/d/mingjiao/houtuqi");
	room1->set("exits/east", "/d/mingjiao/xiangfang_1");
	room1->set("exits/southwest", "/d/mingjiao/qian-ting");
	return 1;
}
