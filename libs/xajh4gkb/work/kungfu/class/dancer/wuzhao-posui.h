// xuan-ku.h for fight and get letter from Xuan
#include <ansi.h>
string *names = ({
//9000级
    "ye gucheng",
	"gui wuyin",
	"jingxu laozu",
	"a fei",
	"feng qingyang",
	"zhang sanfeng",
	"tang laoye",
	"huang shang",
	"zhang tianshi",
	"fahai chanshi",
//10000级
	"damo zushi",
	"ji yanran",
	"afei tianshen",
	"fei tian",
	"ma yun",
	"zi yin",
	"bai xiaosheng",
	"lu ban",
	"shenmi ren",
	"ling xing",
	"jing jing",
	"hades",
});
string *dirs = ({
//9000级
    "/d/hainan/baiyuncheng",
	"/d/xuehepai/shidong",
	"/d/shushan/midao1",
	"/d/dali/hua",
	"/d/huashan/houshan",
	"/d/wudang/xiaoyuan",
	"/d/tangmen/qiushi",
	"/d/wugongzhen/zhongxin",
	"/d/guanwai/tiyun",
	"/d/hangzhou/jinshansi",
//10000级
	"/d/shaolin/damodong",
	"/d/new/lgting",
	"/d/city/zisharoom",
	"/d/flypproom/fightroom88",
	"/d/city/openmarket",
	"/d/city/wumiao",
	"/d/city/mingren",
	"/d/city/shangchang",
	"/d/city/cangbaoge",
	"/d/city2/wenmiao",
	"/d/city2/wenmiao",
	"/d/dali/guangchang",
});
string ask_posui()
{
    mapping skl; 
	object fighter, me, room, monk;
    string *sname;
    int i,j,k,num;
    fighter = this_player();
    me = this_object();

    skl = fighter->query_skills();
    sname  = keys(skl);
	for(i=0; i<sizeof(skl); i++) 
	{
		if (skl[sname[i]] < 4000) 
			return "依我之见，"+ RANK_D->query_respect(fighter) +"的某些功夫还未练到家，恐怕难以领悟破碎虚空。";
	}
	if( (int)fighter->query("breakup")<3 )
		return RANK_D->query_respect(fighter) +  "已是老江湖了，天人之道都还未达到，看来资质甚差啊。";
	if( (int)fighter->query("breakup")>4 )
		return RANK_D->query_respect(fighter) +  "的武功已至化境，这破碎虚空早已领悟，恐怕我还得向你请教呢。";
	if( (int)fighter->query("breakup")==4 )
		return RANK_D->query_respect(fighter) +  "已然破碎虚空转世重修了，无需再来一次。";
	if ( me->query("posui_fighter") )
		return RANK_D->query_respect(fighter) +"，今日已有人领悟破碎虚空，你需要过一段时间再来。";
	if ( (int)fighter->query("renwu/baituo_xunwu")<20 )
		return "破碎虚空不仅仅是对武功的了解，更需要入世修行。我看"+ RANK_D->query_respect(fighter) +"对白驼山寻物任务不甚了解。";
	if ( (int)fighter->query("renwu/banxian_renwu")<20 )
		return "破碎虚空不仅仅是对武功的了解，更需要入世修行。我看"+ RANK_D->query_respect(fighter) +"对朱半仙任务不甚了解。";
	if ( (int)fighter->query("renwu/zhuibu_renwu")<20 )
		return "破碎虚空不仅仅是对武功的了解，更需要入世修行。我看"+ RANK_D->query_respect(fighter) +"对扬州知府颁发的追捕任务不甚了解。";
	if ( (int)fighter->query("renwu/guoxu_yunbiao")<20 )
		return "破碎虚空不仅仅是对武功的了解，更需要入世修行。我看"+ RANK_D->query_respect(fighter) +"对长风镖局护镖任务不甚了解。";
	if ( (int)fighter->query("renwu/ping_fenyao")<20 )
		return "破碎虚空不仅仅是对武功的了解，更需要入世修行。我看"+ RANK_D->query_respect(fighter) +"对平一指分药任务不甚了解。";
	if ( (int)fighter->query("renwu/dukuan_songxin")<20 )
		return "破碎虚空不仅仅是对武功的了解，更需要入世修行。我看"+ RANK_D->query_respect(fighter) +"对驿长杜宽送信任务不甚了解。";
	if ( (int)fighter->query("renwu/lin_yunbiao")<20 )
		return "破碎虚空不仅仅是对武功的了解，更需要入世修行。我看"+ RANK_D->query_respect(fighter) +"对福威镖局运镖任务不甚了解。";
	if ( (int)fighter->query("renwu/xiangyang_duanzao")<20 )
		return "破碎虚空不仅仅是对武功的了解，更需要入世修行。我看"+ RANK_D->query_respect(fighter) +"对襄阳锻造兵器任务不甚了解。";
	if ( (int)fighter->query("renwu/huang_jiaofei")<20 )
		return "破碎虚空不仅仅是对武功的了解，更需要入世修行。我看"+ RANK_D->query_respect(fighter) +"对黄蓉剿匪任务不甚了解。";
	if ( (int)fighter->query("renwu/quanzhou_fanyan")<20 )
		return "破碎虚空不仅仅是对武功的了解，更需要入世修行。我看"+ RANK_D->query_respect(fighter) +"对泉州贩盐任务不甚了解。";
	if ( (int)fighter->query("renwu/duzhai_songxin")<20 )
		return "破碎虚空不仅仅是对武功的了解，更需要入世修行。我看"+ RANK_D->query_respect(fighter) +"对驿使杜窄送信任务不甚了解。";
	if ( (int)fighter->query("renwu/xiangyang_shoucheng")<20 )
		return "破碎虚空不仅仅是对武功的了解，更需要入世修行。我看"+ RANK_D->query_respect(fighter) +"对襄阳守城任务不甚了解。";
	if ( (int)fighter->query("renwu/quanzhou_kangwo")<20 )
		return "破碎虚空不仅仅是对武功的了解，更需要入世修行。我看"+ RANK_D->query_respect(fighter) +"对泉州抗倭任务不甚了解。";
	if ( (int)fighter->query("renwu/wu_kill")<20 )
		return "破碎虚空不仅仅是对武功的了解，更需要入世修行。我看"+ RANK_D->query_respect(fighter) +"对雾中楼杀手任务不甚了解。";
	if ( (int)fighter->query("renwu/kaifeng_houqin")<20 )
		return "破碎虚空不仅仅是对武功的了解，更需要入世修行。我看"+ RANK_D->query_respect(fighter) +"对开封后勤任务不甚了解。";
	if ( (int)fighter->query("renwu/wugong_kaohe")<20 )
		return "破碎虚空不仅仅是对武功的了解，更需要入世修行。我看"+ RANK_D->query_respect(fighter) +"对武功考核任务不甚了解。";
	if ( (int)fighter->query("renwu/huangjingong_tiaozhan")<20 )
		return "破碎虚空不仅仅是对武功的了解，更需要入世修行。我看"+ RANK_D->query_respect(fighter) +"对黄金十二宫挑战不甚了解。";
	if ( (int)fighter->query("renwu/dagong_work")<20 )
		return "破碎虚空不仅仅是对武功的了解，更需要入世修行。我看"+ RANK_D->query_respect(fighter) +"对赚钱养家之道不甚了解。";
	if ( (int)fighter->query("renwu/daniao_renwu")<20 )
		return "破碎虚空不仅仅是对武功的了解，更需要入世修行。我看"+ RANK_D->query_respect(fighter) +"对新手打鸟任务不甚了解。";
	if ((int)fighter->query("family_score")<5)
		return "破碎虚空需要对江湖各门各派均有很深的了解，融汇众家之长，才能窥破天道。";
	if ( fighter->name() != fighter->name(1) )
		return "瞪了你一眼，你是谁呀？先取下面具再说！";
//	if (!wizardp(fighter))
//		return RANK_D->query_respect(fighter) +"，境界突破之法还处于巫师调试之中，暂时没办法举行。";
	fighter->set_temp("posui_tiaozhan", 1);
	message_vision("\n"+me->short()+HIR"说道："+fighter->query("name")+"武功修炼有成，今日有缘相见，若能通过战神殿的考验，将赠予你一桩机缘。\n"NOR,fighter);
	me->set("posui_fighter", fighter->query("id"));
	message_vision("\n"+me->name()+HIG"说到：我已沟通师门传送阵法，即刻传送回战神殿，请"+fighter->query("name")+"做好准备。\n"NOR, fighter);
	fighter->move("/d/zhenjiang/fenjingshanzhuang");
	num = 5+random(5);
	message_vision("\n"+me->short()+HIG"说到：请稍候片刻，我去邀请"HIR+chinese_number(num)+HIG"位武林同道来指点你先天之道。\n"NOR, fighter);
	for(j=0; j<num; j++) 
	{
		k = random(sizeof(names));
//		if (present(names[k], environment(me))) continue;
		if(!( room = find_object(dirs[k])) ) room = load_object(dirs[k]);
		me->move(room);
		if( !objectp(monk = present(names[k], room) ))
        {
			me->move("/d/zhenjiang/fenjingshanzhuang");
//			message_vision("\n"+me->short()+HIC"垂头丧气的走了过来。\n\n"NOR, fighter);
//			command("chat 可惜无法邀请到武林同道（"+names[k]+"），看来 "+fighter->name()+" 机缘还未到，暂时无法领悟破碎虚空！\n"NOR);
//			call_out("do_back", 5, me );
//			return "真是对不起，武林同道中有人不在，无法指点你破碎虚空了。\n";
			message_vision("\n"+me->name()+HIC"垂头丧气的走了过来，看来 "+fighter->name()+" 与（"+names[k]+"）机缘未到，只能再换一位了。\n\n"NOR, fighter);
			num += 1;
			continue;
		}
		if( objectp(monk = present(names[k], room) )) fighter->set_temp("posui_npc/"+(1+j),k);
		fighter->add_temp("posui_num",1);
		message("vision", "\n"+me->short()+HIC"神情肃穆的走了过来，跟" + monk->query("name") + "俯耳轻声说了几句。\n"NOR, room);
		message("vision", "\n"+ monk->query("name") +HIC"点了点头，今日有江湖后生参悟破碎虚空，\n我受"+me->short()+HIC"邀请，去指点"+fighter->query("name")+HIC"破碎虚空的参悟方法，"+ monk->query("name") +HIC"快步走了出去。\n"NOR, room);
		monk->move("/d/zhenjiang/fenjingshanzhuang");
		command("chat 今日"+me->short()+"邀请到 "+ monk->query("name") +NOR" 在战神殿为 "+fighter->name()+" 指点破碎虚空的心得！\n"NOR);
	}
	me->move("/d/zhenjiang/fenjingshanzhuang");
	call_out("waiting", 3, me);
	return "好！大家都到齐了，准备开始吧。\n";
}
int waiting(object me)
{
    object fighter;
    int wait_time;
    if( wait_time == 60 )
    {
        message_vision( "\n"+me->short()+HIG"说道：看来他不会来了，我们回去罢！\n\n"NOR,environment(me));
        call_out("do_back", 1, me);
    }
    if( !objectp( fighter = present( me->query("posui_fighter"), environment(me) ) ) )
    {
        wait_time++;
        call_out("waiting", 1, me);
    }
	else if( !present("wu zhao", environment(me)) || !fighter->query_temp("posui_tiaozhan") )
    {
        if( random(10) == 0 ) 
        message_vision("\n"+me->short()+HIG"说道：" + RANK_D->query_respect(fighter) + "稍等片刻，武林同道们还未到呢。\n"NOR,environment(me));
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
	if(!( room = find_object("/d/zhenjiang/fenjingshanzhuang")) ) room = load_object("/d/zhenjiang/fenjingshanzhuang");
	monk = present("wu zhao", room);
	if (monk)
	{
		message("vision", "\n"+me->short()+HIB"低头与几位武林同道附耳说了几句。\n"NOR, room );
		if ((string)fighter->query("family/family_name")) message("vision", HIG"\n"+ monk->query("name") +"点了点头，说道：今日有"HIY" "+fighter->query("family/family_name")+" "HIG"的传人偶遇战神殿传人，相见即是有缘，「女帝」武曌特邀武林同道指点其破碎虚空。\n\n"NOR, room);
		else message("vision", HIG"\n"+ monk->query("name") +"点了点头，说道：今日有江湖后生巧遇战神殿传人，相见即是有缘，「女帝」武曌特邀武林同道指点其破碎虚空。\n\n"NOR, room);
	}

	message("channel:chat", HIM"【江湖奇遇】"+me->short()+HIY"说道：相逢即是有缘，今日有江湖后生 "+fighter->query("name")+" 得武林前辈指点破碎虚空！\n"NOR,users() );
	message("vision", HIC"只听四周响起沙沙的脚步声，武林前辈施展各自成名绝技，慢慢的围了上来。\n"NOR, room);
	room->delete("exits");

	fighter->delete_temp("posui_tiaozhan");
	fighter->delete_temp("posui_beat_count");
	fighter->set_temp("fighting", 1);
	call_out("fighting", 5, me, fighter, 0);
	return 1;
}
int fighting(object me, object fighter, int count)
{
	object monk1, room1;
	int i,j,num;

	num = (int)fighter->query_temp("posui_num");
	if(!( room1 = find_object("/d/zhenjiang/fenjingshanzhuang")) ) room1 = load_object("/d/zhenjiang/fenjingshanzhuang");
	if( count <= 300 ) 
	{
		message("vision", HIR"武林前辈施展各自成名绝技，一层层地向内收紧！\n" NOR, fighter);
		for(i=0; i<num; i++)
		{
			j = (int)fighter->query_temp("posui_npc/"+(1+i));
			monk1 = present(names[j], room1);
			if (monk1)
			{
				if (!monk1->is_fighting(fighter)) monk1->fight_ob(fighter);
				if (!living(monk1) || monk1->query("qi") <= monk1->query("max_qi")*50/100 ) 
				{
					if (!fighter->query_temp("posui_beat_count/"+(1+i))) fighter->add_temp("posui_beat_count/win",1);
					fighter->set_temp("posui_beat_count/"+(1+i),monk1->query("id"));
				}
			}
			else 
			{
				if (!fighter->query_temp("posui_beat_count/"+(1+i))) fighter->add_temp("posui_beat_count/win",1);
				fighter->set_temp("posui_beat_count/"+(1+i),names[j]);
			}
		}  		
    } else
	{
		message("vision", HIR"武林前辈越战越猛，招式精妙无双，你无法抵挡！\n" NOR, fighter);
		message("channel:chat", HIM"【江湖传言】"HIM + "听说"+fighter->query("name")+"实力不济，与武林前辈比试多时，稍逊一筹！\n"NOR,users() );
		if (fighter->query("xyzx_sys/level", 1)>10) fighter->add("xyzx_sys/level", -10);
		call_out("do_back", 5, me );
	}
	if( !find_player(me->query("posui_fighter")) || !objectp(present(me->query("posui_fighter"), environment(me)) ) || !living(fighter) || fighter->query("qi") <= fighter->query("max_qi")*30/100 || fighter->query("qi") <=1)
	{
		if( objectp(present(me->query("posui_fighter"), environment(me)) )) 
		{
			fighter->delete_temp("fighting");
			fighter->delete_temp("posui_beat_count");
		}
		message("vision", "\n"+me->short()+HIG"摇了摇头，说道：想不到 ... 唉！实力还是差点火候啊。\n"NOR,environment(me));
		message("channel:chat", HIM"【江湖传言】"HIM + "听说"+fighter->query("name")+"不自量力，与武林前辈论武，一败涂地！\n"NOR,users() );
		command("sigh");
		if (fighter->query("xyzx_sys/level", 1)>10) fighter->add("xyzx_sys/level", -10);
		call_out("do_back", 5, me );
    }
	else if( (int)fighter->query_temp("posui_beat_count/win")>=(int)fighter->query_temp("posui_num") )
	{
		command("chat 恭喜"+fighter->name()+"通过了武林前辈的考验，武林前辈将传授你破碎虚空的心得！\n");
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
	mapping skl;
	string *sname;
	string *basic=( {"dodge","unarmed","force","parry","literate","finger","hand","strike","club","staff","fork","hammer","blade","cuff","axe","sword","whip","dagger","spear","throwing","claw","poison","stick","magic","spells",
	                });
	int lev_add,i;
	fighter->delete_temp("posui_tiaozhan");
	fighter->delete_temp("posui_npc");
	fighter->delete_temp("posui_num");
	fighter->delete_temp("posui_beat_count");
	fighter->delete_temp("fighting");
//	fighter->set("posui_winner", 1);
	lev_add = 20+200000/((int)fighter->query("xyzx_sys/level",1)+1000);
	if (!(int)fighter->query("array/posui_exp"))
	{
		fighter->add("potential", 10000000);
		fighter->add("xyzx_sys/level", lev_add, 1);
		fighter->set("array/posui_exp", 1);
		message("vision", HIR"恭喜你通过了武林前辈的考验，获得了武林前辈的破碎虚空修炼心得！\n"NOR,fighter);
	}
	if ((string)fighter->query("family/family_name"))
	{
		command("bow");
		message("channel:chat", HIM"【江湖奇遇】"HIM + ""+me->short()+HIM"说道：今日"+fighter->query("family/family_name")+HIM"传人"+fighter->query("name")+HIC"参悟破碎虚空，打通阴维阳维二脉，窥视到了无上的武学境界！\n"NOR,environment(me));
	}
	else
	{
		command("bow");
		message("channel:chat", HIM"【江湖奇遇】"HIM + ""+me->short()+HIM"说道：今日"+fighter->query("name")+HIM" 参悟破碎虚空，打通阴维阳维二脉，窥视到了无上的武学境界！\n"NOR,environment(me));
	}
	skl = fighter->query_skills();
    sname = keys(skl);
	for(i=0; i<sizeof(skl); i++)
	{
		if (member_array(sname[i],basic)!=-1)
		{
			fighter->set_skill(sname[i],skl[sname[i]]*6/10);
		}
		else fighter->set_skill(sname[i],1);
	}
	fighter->set("max_neili", fighter->query("max_neili")*6/10);
	fighter->set("max_jingli", fighter->query("max_jingli")*6/10);
	fighter->set("combat_exp", 0);
	fighter->set("potential", 0);
	fighter->set("xyzx_sys/level", 1);
	fighter->set("xyzx_sys/jingzhun", 2010);  //设置NPC四维属性
	fighter->set("xyzx_sys/lingxing", 2010 );  //设置NPC四维属性
	fighter->set("xyzx_sys/minjie", 2010 );    //设置NPC四维属性
	fighter->set("xyzx_sys/fanying", 2010 );	  //设置NPC四维属性
	fighter->delete("family");
	fighter->delete("camp");
	fighter->delete("genderbak");
	if ( (string)fighter->query("gender")=="无性" ) fighter->set("gender", "男性");
	fighter->set("breakup", 4);
	fighter->set("cognize",HIR"破碎虚空"NOR);
	me->set("jingmai/yinweimai",1);
	me->set("jingmai/yangweimai",1);
	switch ( random(7) )
	{
		case 0: if(fighter->query("gender")=="女性") fighter->set("body",HIM"姹女媚体"NOR);
				else
				{
					if(random(2)==0) fighter->set("body",HIR"玄阳龙体"NOR);
					else fighter->set("body",CYN"阴阳魔胎"NOR);
				}
			break;
		case 1: fighter->set("body",HIC"太阴灵体"NOR);
			break;
		case 2: fighter->set("body",HIG"苍天霸体"NOR);
			break;
		case 3: fighter->set("body",HIY"太上仙体"NOR);
			break;
		case 4: fighter->set("body",HIB"幽冥邪胎"NOR);
			break;
		case 5: fighter->set("body",HIM"先天道胎"NOR);
			break;
		case 6: fighter->set("body",RED"厄难毒体"NOR);
			break;		
	}
	me->reset_action();
	write(HIR"恭喜你耗费百年修为，修成体质："+fighter->query("body")+HIR"。\n"NOR);
	message("channel:chat", HIM"【江湖传言】"HIM + "听说"+fighter->query("name")+"在破碎虚空时，修炼出"+fighter->query("body")+HIM"体质！\n"NOR,users() );
	call_out("do_back", 5, me );	
	return 1;
}
int do_back(object me)
{
	object monk1, room1, room2;
	int i;
	message("vision", "\n"+me->short()+HIY"挥了挥手， 武林同道随即鱼贯离开战神殿。\n"NOR, environment(me) );
    
	if(!( room1 = find_object("/d/zhenjiang/fenjingshanzhuang")) ) room1 = load_object("/d/zhenjiang/fenjingshanzhuang");
	for(i=0; i<sizeof(names); i++) 
	{
		if(!( room2 = find_object(dirs[i])) ) room2 = load_object(dirs[i]);
		if( objectp( monk1 = present(names[i], room1) ));
		if (monk1) monk1->move(room2);
    }
//	me->delete("posui_fighter");
//	me->move("/d/wudang/sanqingdian");
	room1->set("exits/out", "/d/zhenjiang/shanlu8");

	return 1;
}
