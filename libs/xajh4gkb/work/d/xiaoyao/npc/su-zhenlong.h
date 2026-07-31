// xuan-ku.h for fight and get letter from Xuan
#include <ansi.h>
string *names = ({
    "kang guangling",
    "fan bailing",
    "gou du",
    "wu lingjun",
    "xue muhua",
    "feng asan",
    "shi qinglu",
	"li kuilei",
});
string *dirs = ({
    "/d/xiaoyao/muwu1",
	"/d/xiaoyao/xiuxis",
	"/d/xiaoyao/xiaodao1",
	"/d/xiaoyao/muwu5",
	"/d/xiaoyao/muwu2",
	"/d/xiaoyao/muwu3",
	"/d/xiaoyao/muwu4",
	"/d/xiaoyao/liangong",
});
string ask_zhenlong()
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
		if (skl[sname[i]] < 300) 
			return RANK_D->query_respect(fighter) +  "功夫未学到家，不够资格闯珍珑棋局。";
	}
//	if( fighter->query("zhenlong_winner") )
//		return RANK_D->query_respect(fighter) +  "已然闯过珍珑棋局，这可如何是好呢。。。";
//	if ( !(int)fighter->query_temp("jm_xiaoyao3"))
//		return RANK_D->query_respect(fighter) +  "你与我逍遥派无冤无仇，何苦来闯珍珑棋局！";
//	if ( !(int)fighter->query_temp("jm_murong4"))
//		return RANK_D->query_respect(fighter) +  "你与我逍遥派无冤无仇，何苦来闯珍珑棋局！";
	if ( me->query("zhenlong_fighter") )
		return RANK_D->query_respect(fighter) +  "，今日已有人挑战珍珑棋局，你过一段时间再来吧。";
	
	fighter->set_temp("zhenlong_tiaozhan", 1);
	message_vision(HIR"\n聪辩老人苏星河说道："+ RANK_D->query_respect(fighter) +"若想破此珍珑棋局，请稍等片刻。。。\n"NOR,fighter);
	me->set("zhenlong_fighter", fighter->query("id"));

	message_vision("\n苏星河急匆匆走了，去通知函谷八友准备珍珑棋局。\n", fighter);
	
	for(j=0; j<8; j++) 
	{
		if(!( room = find_object(dirs[j])) ) room = load_object(dirs[j]);
		me->move(room);
		if( !objectp(monk = present(names[j], room) ))
        {
			me->move("/d/xiaoyao/qingcaop");
			message_vision("\n苏星河垂头丧气的走了过来。\n\n", fighter);
			call_out("do_back", 5, me );
			return "真是对不起，逍遥派中有人不在，无法举行珍珑棋局。\n";    
		}
		message("vision", "\n苏星河走了过来，对" + fighter->query("name") + "说道：珍珑棋局即将摆好，请"+ RANK_D->query_respect(fighter) +"就位。\n", room);
		monk->move("/d/xiaoyao/shuding");
		message("vision", fighter->query("name") + "点了点头，快步走入棋局之中。\n", room);
	}
    fighter->move("/d/xiaoyao/shuding");
	me->move("/d/xiaoyao/shuding");
	call_out("waiting", 3, me);
	return "好！大家都出来了。\n";
}
int waiting(object me)
{
    object fighter;
    int wait_time;
    if( wait_time == 60 )
    {
        message_vision( HIG"苏星河说道：看来他不会来了，我们回去罢！\n\n"NOR,environment(me));
        call_out("do_back", 1, me);     
    }
    if( !objectp( fighter = present( me->query("zhenlong_fighter"), environment(me) ) ) )
    {
        wait_time++;
        call_out("waiting", 1, me);
    }
	else if( !present("su xinghe", environment(me)) || !fighter->query_temp("zhenlong_tiaozhan") )
    {
        if( random(10) == 0 ) 
        message_vision(HIG"\n苏星河说道：" + RANK_D->query_respect(fighter) + "稍等片刻，棋局还未摆好。\n"NOR,environment(me));
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

	if(!( room = find_object("/d/xiaoyao/shuding")) ) room = load_object("/d/xiaoyao/shuding");
	monk = present("su xinghe", room);
	if (monk)
	{
		message("vision", HIB"苏星河大声说道：珍珑棋局已经摆好，请无关人等离开擂台。\n"NOR, room );
		monk->move("/d/xiaoyao/shuding");
		if ((string)fighter->query("family/family_name")) message("vision", HIG"\n聪辩老人苏星河说道：今日有"HIY" "+fighter->query("family/family_name")+" "HIM""+fighter->query("family/master_name")+" "HIG"的传人欲破解珍珑棋局，各位师弟定要全力以赴。\n\n"NOR, room);
		else message("vision", HIG"\n苏星河说道：今日有武林高手欲破解珍珑棋局，各位师弟定要全力以赴。\n\n"NOR, room);
	}

	message("channel:chat", HIY"【江湖恩怨】"HIY + "苏星河大声喝到：今日有不知天高地厚之人，妄图挑战我逍遥派的珍珑棋局！\n"NOR,users() );
	message("vision", HIC"只听四周响起沙沙的脚步声，函谷八友摆成珍珑棋局，神情各不一样，不一会，棋局纵横交错，黑白棋子变的扑朔迷离。\n"NOR, room);
	room->delete("exits");
	message("vision", HIG"苏星河高声道：" + fighter->query("name") + "请准备，珍珑棋局即刻发动！\n"NOR,room);
	message("vision", HIM"琴颠"HIC"康广陵：纷披灿烂，戈矛纵横！\n"NOR,room);
	message("vision", HIM"棋魔"HIC"范百龄：疾风听雷音，蝴蝶梦庄周！\n"NOR,room);
	message("vision", HIM"书呆"HIC"苟读：子曰：人无远虑，必有近忧。！\n"NOR,room);
	message("vision", HIM"画狂"HIC"吴领军：采菊东篱下，悠然见南山！\n"NOR,room);
	message("vision", HIM"神医"HIC"薛慕华：望闻问切，救死扶伤！\n"NOR,room);
	message("vision", HIM"巧匠"HIC"冯阿三：兴天下之利，除天下之害！\n"NOR,room);
	message("vision", HIM"花痴"HIC"石清露：娇艳的鲜花，我所爱也！\n"NOR,room);
	message("vision", HIM"戏迷"HIC"李傀儡：生旦净末丑---登场！\n"NOR,room);
	fighter->delete_temp("zhenlong_tiaozhan");
	fighter->delete_temp("beat_count");
	fighter->set_temp("fighting", 1);
	call_out("fighting", 5, me, fighter, 0);
	return 1;
}
int fighting(object me, object fighter, int count)
{
	object monk1, room1;
	int i;
	if(!( room1 = find_object("/d/xiaoyao/shuding")) ) room1 = load_object("/d/xiaoyao/shuding");
	if( count <= 300 ) 
	{
		message("vision", HIR"珍珑棋局之中，纵横交错，黑白棋子如迷雾般！\n" NOR, fighter);
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
		message("vision", HIR"函谷八友越战越猛，珍珑棋局威力大增，你无法抵挡！\n" NOR, fighter);
		message("channel:chat", HIM"【江湖传言】"HIM + "听说"+fighter->query("name")+"实力不济，苦思不得其解，陷于珍珑棋局幻境之中，结果境界下降！\n"NOR,users() );
		if (fighter->query("xyzx_sys/level", 1)>10) fighter->add("xyzx_sys/level", -1);
		call_out("do_back", 5, me );
	}
	if( !find_player(me->query("zhenlong_fighter")) || !objectp(present(me->query("zhenlong_fighter"), environment(me)) ) || !living(fighter) || fighter->query("qi") <= fighter->query("max_qi")*30/100 || fighter->query("qi") <=1)
	{
		if( objectp(present(me->query("zhenlong_fighter"), environment(me)) )) 
		{
			fighter->delete_temp("fighting");
			fighter->delete_temp("beat_count");
		}
		message("vision", HIG"苏星河摇了摇头，说道：想不到 ... 唉！\n"NOR,environment(me));
		message("channel:chat", HIM"【江湖传言】"HIM + "听说"+fighter->query("name")+"不自量力，挑战逍遥派珍珑棋局失败，结果境界下降！\n"NOR,users() );
		command("sigh");
		if (fighter->query("xyzx_sys/level", 1)>10) fighter->add("xyzx_sys/level", -1);
		call_out("do_back", 5, me );
    }
	else if( fighter->query_temp("beat_count/1") && fighter->query_temp("beat_count/2") && fighter->query_temp("beat_count/3") && fighter->query_temp("beat_count/4") && fighter->query_temp("beat_count/5") && fighter->query_temp("beat_count/6") && fighter->query_temp("beat_count/7") && fighter->query_temp("beat_count/8"))
	{	
		command("chat 恭喜"+fighter->name()+"福缘深厚，破解了珍珑棋局，江湖又将出现一位武林高手！\n");
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
//	fighter->set("zhenlong_winner", 1);
	lev_add = 20+200000/((int)fighter->query("xyzx_sys/level",1)+1000);
	if (!(int)fighter->query("array/zhenlong_exp"))
	{
		fighter->add("potential", 10000000);
		fighter->add("xyzx_sys/level", lev_add, 1);
		fighter->set("array/zhenlong_exp", 1);
		message("vision", HIR"恭喜你通过了珍珑棋局，你的实战能力提高了！\n"NOR,fighter);
	}

	if ((int)fighter->query_temp("jm_xiaoyao3"))
	{//逍遥派解密
		fighter->set_temp("jm_xiaoyao4",1);
		message("vision", HIM"你一声长笑，只觉世事如意，豪气满胸，一步跃出***我自逍遥随风去***！\n"NOR,fighter);
		message("vision", HIM"逍遥派传人，果然名不虚传！\n"NOR,fighter);
	}
	if ((int)fighter->query_temp("jm_murong4"))
	{//姑苏慕容解密
		fighter->set_temp("jm_murong8",1);
		message("vision", HIM"你一声长笑，使出斗转星移绝技，星河逆转，以其人之道还治其人之身，珍珑棋局顿时瓦解！\n"NOR,fighter);
		message("vision", HIM"姑苏慕容、斗转星移，果然名不虚传！\n"NOR,fighter);
	}	
	if (fighter->query("family/family_name") == "逍遥派")
	{
		command("bow");
		message("vision", HIC"苏星河说道：" + RANK_D->query_respect(fighter) + "能在"+fighter->query("age")+"岁之时破解本派的珍珑棋局，实乃本派之福！\n"NOR,environment(me));
		call_out("do_back", 5, me );
	}
	else
	{
		message("vision", HIC"苏星河笑道：恭喜"+fighter->query("name")+"破解了珍珑棋局！\n"NOR,environment(me));
		call_out("do_back", 5, me );
	}
	
	return 1;
}
int do_back(object me)
{
	object monk, room1, room2;
	int i;
	message("vision", HIY"苏星河挥了挥手， 函谷八友随即鱼贯离开广场。\n"NOR, environment(me) );
    
	if(!( room1 = find_object("/d/xiaoyao/shuding")) ) room1 = load_object("/d/xiaoyao/shuding");
	for(i=0; i<8; i++) 
	{
		if(!( room2 = find_object(dirs[i])) ) room2 = load_object(dirs[i]);
		if( objectp( monk = present(names[i], room1) ));
		if (monk) monk->move(room2);
    }
//	me->delete("zhenlong_fighter");
	me->move("/d/xiaoyao/qingcaop");
	room1->set("exits/down", "/d/xiaoyao/qingcaop");
	return 1;
}
