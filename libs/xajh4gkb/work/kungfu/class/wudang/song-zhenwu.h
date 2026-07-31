// xuan-ku.h for fight and get letter from Xuan
#include <ansi.h>
string *names = ({
    "song yuanqiao",
    "yu lianzhou",
    "yu daiyan",
    "zhang songxi",
    "zhang cuishan",
    "yin liting",
    "mo shenggu",
});
string *dirs = ({
    "/d/wudang/sanqingdian",
	"/d/wudang/taiziyan",
	"/d/wudang/fuzhen2",
	"/d/wudang/chaotian",
	"/d/wudang/shesheng",
	"/d/wudang/wulao",
	"/d/wudang/donglang1",
});
string ask_zhenwu()
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
			return RANK_D->query_respect(fighter) +  "功夫未学到家，不够资格闯真武七截阵。";
	}
//	if( fighter->query("zhenwu_winner") )
//		return RANK_D->query_respect(fighter) +  "已然闯过真武七截阵，这可如何是好呢。。。";
//	if ( !(int)fighter->query_temp("jm_taohua3"))
//		return RANK_D->query_respect(fighter) +  "你与我武当派无冤无仇，何苦来闯真武七截阵！";
	if ( me->query("zhenwu_fighter") )
		return RANK_D->query_respect(fighter) +  "，今日已有人挑战真武七截阵，你过一段时间再来吧。";
	
	fighter->set_temp("zhenwu_tiaozhan", 1);
	message_vision(HIR"\n宋远桥说道：什么人竟敢挑衅我武当派，我去通知其他师弟来此地集合，定要让尔等知晓武当剑阵的厉害。。。\n"NOR,fighter);
	me->set("zhenwu_fighter", fighter->query("id"));
	message_vision("\n宋远桥急匆匆的向掌教真人汇报去了。\n", fighter);
	fighter->move("/d/wudang/guangchang");
	for(j=0; j<7; j++) 
	{
		if(!( room = find_object(dirs[j])) ) room = load_object(dirs[j]);
		me->move(room);
		if( !objectp(monk = present(names[j], room) ))
        {
			me->move("/d/wudang/guangchang");
			message_vision("\n宋远桥垂头丧气的走了过来。\n\n", fighter);
			call_out("do_back", 5, me );
			return "真是对不起，武当派中有人不在，无法举行真武七截阵。\n";    
		}
		message("vision", "\n宋远桥神情肃穆的走了过来，跟" + monk->query("name") + "俯耳轻声说了几句。\n", room);
		monk->move("/d/wudang/guangchang");
		message("vision", monk->query("name") + "点了点头，快步走了出去。\n", room);
	}
	me->move("/d/wudang/guangchang");
	call_out("waiting", 3, me);
	return "好！大家都出来了。\n";
}
int waiting(object me)
{
    object fighter;
    int wait_time;
    if( wait_time == 60 )
    {
        message_vision( HIG"宋远桥说道：看来他不会来了，我们回去罢！\n\n"NOR,environment(me));
        call_out("do_back", 1, me);     
    }
    if( !objectp( fighter = present( me->query("zhenwu_fighter"), environment(me) ) ) )
    {
        wait_time++;
        call_out("waiting", 1, me);
    }
	else if( !present("song yuanqiao", environment(me)) || !fighter->query_temp("zhenwu_tiaozhan") )
    {
        if( random(10) == 0 ) 
        message_vision(HIG"\n宋远桥说道：" + RANK_D->query_respect(fighter) + "稍等片刻，师弟们还未到呢。\n"NOR,environment(me));
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
	if(!( room = find_object("/d/wudang/guangchang")) ) room = load_object("/d/wudang/guangchang");
	monk = present("dao tong", room);
	if (monk) monk->move("/d/wudang/liangongfang");
	monk = present("guxu daozhang", room);	
	if (monk) monk->move("/d/wudang/liangongfang");
	monk = present("song yuanqiao", room);
	if (monk)
	{
		message("vision", HIB"宋远桥低头与几位师弟附耳说了几句。\n"NOR, room );
		if ((string)fighter->query("family/family_name")) message("vision", HIG"\n"+ monk->query("name") +"点了点头，说道：今日有"HIY" "+fighter->query("family/family_name")+" "HIM""+fighter->query("family/master_name")+" "HIG"的传人挑战武当真武七截阵，各位师弟定要全力以赴。\n\n"NOR, room);
		else message("vision", HIG"\n"+ monk->query("name") +"点了点头，说道：今日有武林高手挑战武当真武七截阵，各位师弟定要全力以赴。\n\n"NOR, room);
	}

	message("channel:chat", HIY"【江湖恩怨】"HIY + "宋远桥大声喝到：今日有不知天高地厚之人，妄图挑战我武当派的真武七截阵！\n"NOR,users() );
	message("vision", HIC"只听四周响起沙沙的脚步声，武当七子手持长剑，个个神情肃杀，\n"NOR
		HIC"脚踏龟蛇，手持长剑，剑划方圆，慢慢地围了上来。\n"NOR, room);
	room->delete("exits");
	message("vision", HIG"宋远桥"HIM"大喝一声：风樯动，龟蛇静，起宏图！\n"NOR,room);
	message("vision", HIC"俞莲舟"HIM"大喝一声：动静随心，借力用力，阴阳逆转，两仪变幻！\n"NOR,room);
	message("vision", HIB"俞岱岩"HIM"大喝一声：阴阳之侯烈，变化之由表，死生之兆章！\n"NOR,room);
	message("vision", HIY"张松溪"HIM"大喝一声：天下之至柔，驰骋天下之至坚！\n"NOR,room);
	message("vision", HIW"张翠山"HIM"大喝一声：他强任他强，清风拂山岗；他横任他横，明月照大江。！\n"NOR,room);
	message("vision", HIG"殷梨亭"HIM"大喝一声：「沾黏诀」「挤字诀」「引字诀」「按字诀」！\n"NOR,room);
	message("vision", HIC"莫声谷"HIM"大喝一声：以弱胜强，以柔克刚！\n"NOR,room);
	fighter->delete_temp("zhenwu_tiaozhan");
	fighter->delete_temp("beat_count");
	fighter->set_temp("fighting", 1);
	call_out("fighting", 5, me, fighter, 0);
	return 1;
}
int fighting(object me, object fighter, int count)
{
	object monk1, room1;
	int i;
	if(!( room1 = find_object("/d/wudang/guangchang")) ) room1 = load_object("/d/wudang/guangchang");
	if( count <= 300 ) 
	{
		message("vision", HIR"真武七截阵急速地旋转着，一层层地向内收紧！\n" NOR, fighter);
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
		message("vision", HIR"武当七子越战越猛，真武七截阵威力大增，你无法抵挡！\n" NOR, fighter);
		message("channel:chat", HIM"【江湖传言】"HIM + "听说"+fighter->query("name")+"实力不济，未能破解武当派真武七截阵，结果境界下降！\n"NOR,users() );
		if (fighter->query("xyzx_sys/level", 1)>10) fighter->add("xyzx_sys/level", -1);
		call_out("do_back", 5, me );
	}
	if( !find_player(me->query("zhenwu_fighter")) || !objectp(present(me->query("zhenwu_fighter"), environment(me)) ) || !living(fighter) || fighter->query("qi") <= fighter->query("max_qi")*30/100 || fighter->query("qi") <=1)
	{
		if( objectp(present(me->query("zhenwu_fighter"), environment(me)) )) 
		{
			fighter->delete_temp("fighting");
			fighter->delete_temp("beat_count");
		}
		message("vision", HIG"宋远桥摇了摇头，说道：想不到 ... 唉！\n"NOR,environment(me));
		message("channel:chat", HIM"【江湖传言】"HIM + "听说"+fighter->query("name")+"不自量力，挑战武当派真武七截阵失败，结果境界下降！\n"NOR,users() );
		command("sigh");
		if (fighter->query("xyzx_sys/level", 1)>10) fighter->add("xyzx_sys/level", -1);
		call_out("do_back", 5, me );
    }
	else if( fighter->query_temp("beat_count/1") && fighter->query_temp("beat_count/2") && fighter->query_temp("beat_count/3") && fighter->query_temp("beat_count/4") && fighter->query_temp("beat_count/5") && fighter->query_temp("beat_count/6") && fighter->query_temp("beat_count/7"))
	{	
		command("chat 恭喜"+fighter->name()+"闯过了真武七截阵！ 届时必当为武林放一异彩！\n");
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
//	fighter->set("zhenwu_winner", 1);
	lev_add = 20+200000/((int)fighter->query("xyzx_sys/level",1)+1000);
	if (!(int)fighter->query("array/zhenwu_exp"))
	{
		fighter->add("potential", 10000000);
		fighter->add("xyzx_sys/level", lev_add, 1);
		fighter->set("array/zhenwu_exp", 1);
		message("vision", HIR"恭喜你通过了真武七截阵，你的实战能力提高了！\n"NOR,fighter);
	}
	if ((int)fighter->query_temp("jm_wudang6"))
	{//武当派解密
		fighter->set_temp("jm_wudang7",1);
		message("vision", HIM"你使出浑身解数，总算是破了这真武七截阵！武当七侠果然名不虚传。\n"NOR,fighter);
	}
	if (fighter->query("family/family_name") == "武当派")
	{
		command("bow");
		message("vision", HIC"宋远桥说道：" + RANK_D->query_respect(fighter) + "能在"+fighter->query("age")+"岁之时创过本派真武七截阵，实乃本派之福！\n"NOR,environment(me));
		call_out("do_back", 5, me );
	}
	else
	{
		message("vision", HIC"宋远桥神情落寞的说道：你居然闯过了真武七截阵！我等愧对祖师啊！\n"NOR,environment(me));
		call_out("do_back", 5, me );
	}
	
	return 1;
}
int do_back(object me)
{
	object monk1,monk2, room1, room2,room3;
	int i;
	message("vision", HIY"宋远桥挥了挥手， 武当七子随即鱼贯离开广场。\n"NOR, environment(me) );
    
	if(!( room1 = find_object("/d/wudang/guangchang")) ) room1 = load_object("/d/wudang/guangchang");
	for(i=0; i<7; i++) 
	{
		if(!( room2 = find_object(dirs[i])) ) room2 = load_object(dirs[i]);
		if( objectp( monk1 = present(names[i], room1) ));
		if (monk1) monk1->move(room2);
    }
//	me->delete("zhenwu_fighter");
//	me->move("/d/wudang/sanqingdian");
	room1->set("exits/west", "/d/wudang/shijie7");
	room1->set("exits/north", "/d/wudang/sanqingdian");
	room1->set("exits/southdown", "/d/wudang/shijie62");
	if(!( room3 = find_object("/d/wudang/liangongfang")) ) room3 = load_object("/d/wudang/liangongfang");
	monk2 = present("dao tong", room3);
	if (monk2) monk2->move("/d/wudang/guangchang");
	monk2 = present("guxu daozhang", room3);
	if (monk2) monk2->move("/d/wudang/guangchang");
	return 1;
}
