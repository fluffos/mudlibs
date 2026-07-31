// xuan-ku.h for fight and get letter from Xuan
#include <ansi.h>
string *names = ({
    "ma yu",
    "qiu chuji",
    "tan chuduan",
    "sun buer",
    "wang chuyi",
    "hao datong",
    "liu chuxuan",
});
string *dirs = ({
    "/d/quanzhen/neishi",
	"/d/quanzhen/cangjingge2",
	"/d/quanzhen/zhujianshi",
	"/d/quanzhen/lingguandian",
	"/d/quanzhen/yuanchendian",
	"/d/quanzhen/disandian",
	"/d/quanzhen/xiaolu1",
});
string ask_me()
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
			return RANK_D->query_respect(fighter) +  "功夫未学到家，不够资格闯天罡北斗阵。";
	}
//	if( fighter->query("qixing_winner") )
//		return RANK_D->query_respect(fighter) +  "已然闯过天罡北斗阵，这可如何是好呢。。。";
//	if ( !(int)fighter->query_temp("jm_taohua3"))
//		return RANK_D->query_respect(fighter) +  "你与我全真教无冤无仇，何苦来闯天罡北斗阵！";
	if ( me->query("qixing_fighter") )
		return RANK_D->query_respect(fighter) +  "，今日已有人挑战天罡北斗阵，你过一段时间再来吧。";
	
	fighter->set_temp("qixing_tiaozhan", 1);
	message_vision(HIR"\n赵志敬说道：什么人竟敢挑衅我全真教，我去报告长老们来此地集合，你给我等着。。。\n"NOR,fighter);
	me->set("qixing_fighter", fighter->query("id"));

	message_vision("\n赵志敬急匆匆的向掌教打小报告去了。\n", fighter);
	
	for(j=0; j<7; j++) 
	{
		if(!( room = find_object(dirs[j])) ) room = load_object(dirs[j]);
		me->move(room);
		if( !objectp(monk = present(names[j], room) ))
        {
			me->move("/d/quanzhen/guangchang");
			message_vision("\n赵志敬垂头丧气的走了过来。\n\n", fighter);
			call_out("do_back", 5, me );
			return "真是对不起，全真教中有人不在，无法举行天罡北斗阵。\n";    
		}
		message("vision", "\n赵志敬一脸阴险的走了过来，跟" + monk->query("name") + "俯耳轻声说了几句。\n", room);
		monk->move("/d/quanzhen/guangchang");
		message("vision", monk->query("name") + "长老点了点头，快步走了出去。\n", room);
	}
    
	me->move("/d/quanzhen/guangchang");
	call_out("waiting", 3, me);
	return "好！大家都出来了。\n";
}
int waiting(object me)
{
    object fighter;
    int wait_time;
    if( wait_time == 60 )
    {
        message_vision( HIG"赵志敬说道：看来他不会来了，我们回去罢！\n\n"NOR,environment(me));
        call_out("do_back", 1, me);     
    }
    if( !objectp( fighter = present( me->query("qixing_fighter"), environment(me) ) ) )
    {
        wait_time++;
        call_out("waiting", 1, me);
    }
	else if( !present("ma yu", environment(me)) || !fighter->query_temp("qixing_tiaozhan") )
    {
        if( random(10) == 0 ) 
        message_vision(HIG"\n赵志敬说道：" + RANK_D->query_respect(fighter) + "稍等片刻，掌教真人还未到呢。\n"NOR,environment(me));
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

	if(!( room = find_object("/d/quanzhen/guangchang")) ) room = load_object("/d/quanzhen/guangchang");
	monk = present("ma yu", room);
	if (monk)
	{
		message("vision", HIB"赵志敬大师跟马钰掌教俯耳轻声说了几句。\n"NOR, room );
		monk->move("/d/quanzhen/guangchang");
		if ((string)fighter->query("family/family_name")) message("vision", HIG"\n"+ monk->query("name") +"掌教点了点头，说道：今日有"HIY" "+fighter->query("family/family_name")+" "HIM""+fighter->query("family/master_name")+" "HIG"的传人挑战天罡北斗大阵，各位长老定要全力以赴。\n\n"NOR, room);
		else message("vision", HIG"\n"+ monk->query("name") +"掌教点了点头，说道：今日有武林高手挑战天罡北斗大阵，各位长老定要全力以赴。\n\n"NOR, room);
	}

	message("channel:chat", HIY"【江湖恩怨】"HIY + "赵志敬大声喝到：今日有不知天高地厚之人，妄图挑战我全真教的天罡北斗阵！\n"NOR,users() );
	message("vision", HIC"只听四周响起沙沙的脚步声，全真七子手持长剑，个个神情肃杀，\n"NOR
		HIC"脚踏七星，手持兵器，慢慢地围了上来，堵住了通路。\n"NOR, room);
	room->delete("exits");
	message("vision", HIG"马钰掌教高声道：准备，天罡北斗阵即刻发动！\n"NOR,room);
	message("vision", HIM"丹阳子"HIC"马钰：天枢------就位！\n"NOR,room);
	message("vision", HIM"长春子"HIC"丘处机：天璇------就位！\n"NOR,room);
	message("vision", HIM"长真子"HIC"谭处端：天玑------就位！\n"NOR,room);
	message("vision", HIM"清静散人"HIC"孙不二：天权------就位！\n"NOR,room);
	message("vision", HIM"玉阳子"HIC"王处一：玉衡------就位！\n"NOR,room);
	message("vision", HIM"广宁子"HIC"郝大通：开阳------就位！\n"NOR,room);
	message("vision", HIM"长生子"HIC"刘处玄：摇光------就位！\n"NOR,room);
	fighter->delete_temp("qixing_tiaozhan");
	fighter->delete_temp("beat_count");
	fighter->set_temp("fighting", 1);
	call_out("fighting", 5, me, fighter, 0);
	return 1;
}
int fighting(object me, object fighter, int count)
{
	object monk1, room1;
	int i;
	if(!( room1 = find_object("/d/quanzhen/guangchang")) ) room1 = load_object("/d/quanzhen/guangchang");
	if( count <= 300 ) 
	{
		message("vision", HIR"天罡北斗阵急速地旋转着，一层层地向内收紧！\n" NOR, fighter);
		for(i=0; i<7; i++) 
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
		message("vision", HIR"全真七子越战越猛，天罡北斗阵威力大增，你无法抵挡！\n" NOR, fighter);
		message("channel:chat", HIM"【江湖传言】"HIM + "听说"+fighter->query("name")+"实力不济，战斗良久也未能破开天罡北斗阵，结果境界下降！\n"NOR,users() );
		if (fighter->query("xyzx_sys/level", 1)>10) fighter->add("xyzx_sys/level", -1);
		call_out("do_back", 5, me );
	}
	if( !find_player(me->query("qixing_fighter")) || !objectp(present(me->query("qixing_fighter"), environment(me)) ) || !living(fighter) || fighter->query("qi") <= fighter->query("max_qi")*30/100 || fighter->query("qi") <=1)
	{
		if( objectp(present(me->query("qixing_fighter"), environment(me)) )) 
		{
			fighter->delete_temp("fighting");
			fighter->delete_temp("beat_count");
		}
		message("vision", HIG"赵志敬摇了摇头，说道：想不到 ... 唉！\n"NOR,environment(me));
		message("channel:chat", HIM"【江湖传言】"HIM + "听说"+fighter->query("name")+"不自量力，挑战全真教天罡北斗阵失败，结果境界下降！\n"NOR,users() );
		command("sigh");
		if (fighter->query("xyzx_sys/level", 1)>10) fighter->add("xyzx_sys/level", -1);
		call_out("do_back", 5, me );
    }
	else if( fighter->query_temp("beat_count/1") && fighter->query_temp("beat_count/2") && fighter->query_temp("beat_count/3") && fighter->query_temp("beat_count/4") && fighter->query_temp("beat_count/5") && fighter->query_temp("beat_count/6") && fighter->query_temp("beat_count/7"))
	{	
		command("chat 恭喜"+fighter->name()+"闯过了天罡北斗阵！ 届时必当为武林放一异彩！\n");
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
	object obj;
	int lev_add;
	fighter->delete_temp("beat_count");
	fighter->delete_temp("fighting");
//	fighter->set("qixing_winner", 1);
	lev_add = 20+200000/((int)fighter->query("xyzx_sys/level",1)+1000);
	if (!(int)fighter->query("array/qixing_exp"))
	{
		fighter->add("potential", 10000000);
		fighter->add("xyzx_sys/level", lev_add, 1);
		fighter->set("array/qixing_exp", 1);
		message("vision", HIR"恭喜你通过了天罡北斗阵，你的实战能力提高了！\n"NOR,fighter);
	}
	obj=present("taohua ling",fighter);
	if (obj && (int)fighter->query_temp("jm_taohua3"))
	{
		fighter->set_temp("jm_taohua5",1);
		message("vision", HIM"你风轻云淡的笑道：天罡北斗阵！名不副实！全真七子！沽名钓誉之辈！\n"NOR,fighter);
		message("vision", HIM"桃花岛传人，果然名不虚传！\n"NOR,fighter);
	}
	if (fighter->query("family/family_name") == "全真教")
	{
		command("bow");
		message("vision", HIC"赵志敬说道：" + RANK_D->query_respect(fighter) + "能在"+fighter->query("age")+"岁之时创过本教天罡北斗大阵，乃吾辈楷模！\n"NOR,environment(me));
		call_out("do_back", 5, me );
	}
	else
	{
		message("vision", HIC"赵志敬惊恐的说道：你居然闯过了天罡北斗阵！这可如何是好！\n"NOR,environment(me));
		call_out("do_back", 5, me );
	}
	
	return 1;
}
int do_back(object me)
{
	object monk, room1, room2;
	int i;
	message("vision", HIY"马钰掌教挥了挥手， 全真教长老们随即鱼贯离开广场。\n"NOR, environment(me) );
    
	if(!( room1 = find_object("/d/quanzhen/guangchang")) ) room1 = load_object("/d/quanzhen/guangchang");
	for(i=0; i<7; i++) 
	{
		if(!( room2 = find_object(dirs[i])) ) room2 = load_object(dirs[i]);
		if( objectp( monk = present(names[i], room1) ));
		if (monk) monk->move(room2);
    }
//	me->delete("qixing_fighter");
	me->move("/d/quanzhen/guangchang");
	room1->set("exits/west", "/d/quanzhen/lwc1");
	room1->set("exits/east", "/d/quanzhen/bwc");
	room1->set("exits/north", "/d/quanzhen/yuhuangdian");
	room1->set("exits/southdown", "/d/quanzhen/tyroad2");
	return 1;
}
