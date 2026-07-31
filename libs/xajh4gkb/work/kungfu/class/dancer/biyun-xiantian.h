// xuan-ku.h for fight and get letter from Xuan
#include <ansi.h>
string *names = ({
//5000级
    "bei haishi",
    "wang zhen",
    "mao dongzhu",
    "ming jian",
    "heng dao",
    "xiao sanshao",
    "zhou botong",
	"yuan chengzhi",
	"jian xin",
	"he biweng",
	"lu zhangke",
	"kongwen dashi",
	"ouyang du",
	"zuo lengchan",
	"bai zizai",
	"jing wuming",
	"lin xianer",
	"lan fonghuang",
	"xiang wentian",
	"qiong yadie",
	"ding chunqiu",
	"mie jue",
	"zhu banxian",
	"xie yanke",
	"hu yidao",
	"xu xian",
//6000级
	"kang xi",
	"guo jing",
	"fan yin",
	"qian long",
	"murong bo",
	"xiao yuanshan",
	"he tieshou",
	"yang xiaoxie",
	"jiu jianxian",
	"shushan jianshen",
	"yang guo",
	"xiao longnv",
	"shangguan xiaoxian",
	"shangguan jiannan",
	"jiumo zhi",
	"jinlun fawang",
	"du jie",
	"du e",
	"du nan",
	"lian xing",
	"he zudao",
	"datie seng",
});
string *dirs = ({
//5000级
    "/d/zhenjiang/dating",
	"/d/huanggong/neiwufu",
	"/d/huanggong/dafotang",
	"/d/fairyland/mjszhuang",
	"/d/fairyland/mjszhuang",
	"/d/fairyland/mjszhuang",
	"/d/taohua/dong",
	"/d/sdxl/xiaowu",
	"/d/feitian/pingtai",
	"/d/shouxihu/lvliuzhuang",
	"/d/shouxihu/lvliuzhuang",
	"/d/shaolin/shuitan",
	"/d/xuehepai/center",
	"/d/songshan/huimengtang",
	"/d/lingxiao/dilao",
	"/d/zhongzhou/hutong1",
	"/d/dali/hua",
	"/d/heimuya/zhaoze/room15",
	"/d/heimuya/up3",
	"/d/wudie/wdt",
	"/d/xingxiu/riyuedong",
	"/d/emei/qingxiudong",
	"/d/city/guangchang",
	"/d/xiakedao/mtdating",
	"/d/changbaishan/xueshan",
	"/d/hangzhou/jinshansi",
//6000级
	"/d/huanggong/yushufang",
	"/d/xiangyang/guofuting",
	"/d/hainan/jingtang",
	"/d/hangzhou/liuhed",
	"/d/mr/c14-5",
	"/d/guanwai/road1",
	"/d/wudujiao/huating1",
	"/d/tongchi/xiefj",
	"/d/shushan/zushi",
	"/d/shushan/xianjing",
	"/d/gumu/gmht",
	"/d/gumu/gmht",
	"/d/cxwxm/longfeng",
	"/d/tiezhang/shishi",
	"/d/xueshan/neidian",
	"/d/xueshan/dating",
	"/d/shaolin/fumoquan",
	"/d/shaolin/fumoquan",
	"/d/shaolin/fumoquan",
	"/d/yihua/lianxing",
	"/d/kunlun/mw",
	"/d/shaolin/datiepu",
});
string ask_xiantian()
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
		if (skl[sname[i]] < 2000) 
			return "依我之见，"+ RANK_D->query_respect(fighter) +"的某些功夫还未练到家，恐怕难以领悟先天之道。";
	}
	if( (int)fighter->query("breakup")<1 )
		return RANK_D->query_respect(fighter) +  "初入江湖，区区后天之境都还未达到，有些好高骛远了。";
	if( (int)fighter->query("breakup")>2 )
		return RANK_D->query_respect(fighter) +  "的武功已至化境，这先天之道早已领悟，恐怕我还得向你请教呢。";
	if( (int)fighter->query("breakup")==2 )
		return RANK_D->query_respect(fighter) +  "已然突破到先天意境了，以后需要自行修行。";
	if ( me->query("xiantian_fighter") )
		return RANK_D->query_respect(fighter) +"，今日已有人领悟先天之道，你需要过一段时间再来。";
	if ( fighter->name() != fighter->name(1) )
		return "瞪了你一眼，你是谁呀？先取下面具再说！";
//	if (!wizardp(fighter))
//		return RANK_D->query_respect(fighter) +"，境界突破之法还处于巫师调试之中，暂时没办法举行。";
	fighter->set_temp("xiantian_tiaozhan", 1);
	message_vision("\n"+me->short()+HIR"说道："+fighter->query("name")+"武功修炼有成，今日有缘相见，若能通过焚静山庄的考验，将赠予你一桩机缘。\n"NOR,fighter);
	me->set("xiantian_fighter", fighter->query("id"));
	message_vision("\n"+me->name()+HIG"说到：我已沟通师门传送阵法，即刻传送回焚静山庄，请"+fighter->query("name")+"做好准备。\n"NOR, fighter);
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
//			message_vision("\n"+me->name()+HIC"垂头丧气的走了过来。\n\n"NOR, fighter);
//			command("chat 可惜无法邀请到武林同道（"+names[k]+"），看来 "+fighter->name()+" 机缘还未到，暂时无法领悟先天之道！\n"NOR);			
//			call_out("do_back", 5, me );
//			return "真是对不起，武林同道中有人不在，无法指点你先天之道了。\n";
			message_vision("\n"+me->name()+HIC"垂头丧气的走了过来，看来 "+fighter->name()+" 与（"+names[k]+"）机缘未到，只能再换一位了。\n\n"NOR, fighter);
			num += 1;
			continue;
		}
		if( objectp(monk = present(names[k], room) )) fighter->set_temp("xiantian_npc/"+(1+j),k);
		fighter->add_temp("xiantian_num",1);
		message("vision", "\n"+me->short()+HIC"神情肃穆的走了过来，跟" + monk->query("name") + "俯耳轻声说了几句。\n"NOR, room);
		message("vision", "\n"+ monk->query("name") +HIC"点了点头，今日有江湖后生参悟先天意境，\n我受"+me->short()+HIC"邀请，去指点"+fighter->query("name")+HIC"先天境界的参悟方法，"+ monk->query("name") +HIC"快步走了出去。\n"NOR, room);
		monk->move("/d/zhenjiang/fenjingshanzhuang");
		command("chat 今日"+me->short()+"邀请到 "+ monk->query("name") +NOR" 在焚静山庄为 "+fighter->name()+" 指点先天意境的心得！\n"NOR);
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
    if( !objectp( fighter = present( me->query("xiantian_fighter"), environment(me) ) ) )
    {
        wait_time++;
        call_out("waiting", 1, me);
    }
	else if( !present("bi yun", environment(me)) || !fighter->query_temp("xiantian_tiaozhan") )
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
	monk = present("bi yun", room);
	if (monk)
	{
		message("vision", "\n"+me->short()+HIB"低头与几位武林同道附耳说了几句。\n"NOR, room );
		if ((string)fighter->query("family/family_name")) message("vision", HIG"\n"+ monk->query("name") +"点了点头，说道：今日有"HIY" "+fighter->query("family/family_name")+" "HIG"的传人偶遇焚静山庄传人，相见即是有缘，「回音仙子」碧云特邀武林同道指点其先天意境。\n\n"NOR, room);
		else message("vision", HIG"\n"+ monk->query("name") +"点了点头，说道：今日有江湖后生巧遇焚静山庄传人，相见即是有缘，「回音仙子」碧云特邀武林同道指点其先天意境。\n\n"NOR, room);
	}

	message("channel:chat", HIM"【江湖奇遇】"+me->short()+HIY"说道：相逢即是有缘，今日有江湖后生 "+fighter->query("name")+" 得武林前辈指点先天之道！\n"NOR,users() );
	message("vision", HIC"只听四周响起沙沙的脚步声，武林前辈施展各自成名绝技，慢慢的围了上来。\n"NOR, room);
	room->delete("exits");

	fighter->delete_temp("xiantian_tiaozhan");
	fighter->delete_temp("xiantian_beat_count");
	fighter->set_temp("fighting", 1);
	call_out("fighting", 5, me, fighter, 0);
	return 1;
}
int fighting(object me, object fighter, int count)
{
	object monk1, room1;
	int i,j,num;

	num = (int)fighter->query_temp("xiantian_num");
	if(!( room1 = find_object("/d/zhenjiang/fenjingshanzhuang")) ) room1 = load_object("/d/zhenjiang/fenjingshanzhuang");
	if( count <= 300 ) 
	{
		message("vision", HIR"武林前辈施展各自成名绝技，一层层地向内收紧！\n" NOR, fighter);
		for(i=0; i<num; i++)
		{
			j = (int)fighter->query_temp("xiantian_npc/"+(1+i));
			monk1 = present(names[j], room1);
			if (monk1)
			{
				if (!monk1->is_fighting(fighter)) monk1->fight_ob(fighter);
				if (!living(monk1) || monk1->query("qi") <= monk1->query("max_qi")*50/100 ) 
				{
					if (!fighter->query_temp("xiantian_beat_count/"+(1+i))) fighter->add_temp("xiantian_beat_count/win",1);
					fighter->set_temp("xiantian_beat_count/"+(1+i),monk1->query("id"));
				}
			}
			else 
			{
				if (!fighter->query_temp("xiantian_beat_count/"+(1+i))) fighter->add_temp("xiantian_beat_count/win",1);
				fighter->set_temp("xiantian_beat_count/"+(1+i),names[j]);
			}
		}  		
    } else
	{
		message("vision", HIR"武林前辈越战越猛，招式精妙无双，你无法抵挡！\n" NOR, fighter);
		message("channel:chat", HIM"【江湖传言】"HIM + "听说"+fighter->query("name")+"实力不济，与武林前辈比试多时，稍逊一筹！\n"NOR,users() );
		if (fighter->query("xyzx_sys/level", 1)>10) fighter->add("xyzx_sys/level", -10);
		call_out("do_back", 5, me );
	}
	if( !find_player(me->query("xiantian_fighter")) || !objectp(present(me->query("xiantian_fighter"), environment(me)) ) || !living(fighter) || fighter->query("qi") <= fighter->query("max_qi")*30/100 || fighter->query("qi") <=1)
	{
		if( objectp(present(me->query("xiantian_fighter"), environment(me)) )) 
		{
			fighter->delete_temp("fighting");
			fighter->delete_temp("xiantian_beat_count");
		}
		message("vision", "\n"+me->short()+HIG"摇了摇头，说道：想不到 ... 唉！实力还是差点火候啊。\n"NOR,environment(me));
		message("channel:chat", HIM"【江湖传言】"HIM + "听说"+fighter->query("name")+"不自量力，与武林前辈论武，一败涂地！\n"NOR,users() );
		command("sigh");
		if (fighter->query("xyzx_sys/level", 1)>10) fighter->add("xyzx_sys/level", -10);
		call_out("do_back", 5, me );
    }
	else if( (int)fighter->query_temp("xiantian_beat_count/win")>=(int)fighter->query_temp("xiantian_num") )
	{
		command("chat 恭喜"+fighter->name()+"通过了武林前辈的考验，武林前辈将传授你先天境界的心得！\n");
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
	fighter->delete_temp("xiantian_tiaozhan");
	fighter->delete_temp("xiantian_npc");
	fighter->delete_temp("xiantian_num");
	fighter->delete_temp("xiantian_beat_count");
	fighter->delete_temp("fighting");
//	fighter->set("xiantian_winner", 1);
	lev_add = 20+200000/((int)fighter->query("xyzx_sys/level",1)+1000);
	if (!(int)fighter->query("array/xiantian_exp"))
	{
		fighter->add("potential", 10000000);
		fighter->add("xyzx_sys/level", lev_add, 1);
		fighter->set("array/xiantian_exp", 1);
		message("vision", HIR"恭喜你通过了武林前辈的考验，获得了武林前辈的先天境界修炼心得！\n"NOR,fighter);
	}
	if ((string)fighter->query("family/family_name"))
	{
		command("bow");
		message("channel:chat", HIM"【江湖奇遇】"HIM + ""+me->short()+HIM"说道：今日"+fighter->query("family/family_name")+HIM"传人"+fighter->query("name")+HIC"参悟先天之道，打通冲带二脉，窥视到了无上的武学境界！\n"NOR,environment(me));
	}
	else
	{
		command("bow");
		message("channel:chat", HIM"【江湖奇遇】"HIM + ""+me->short()+HIM"说道：今日"+fighter->query("name")+HIM" 参悟先天之道，打通冲带二脉，窥视到了无上的武学境界！\n"NOR,environment(me));
	}
	fighter->set("breakup", 2);
	fighter->set("cognize",HIG"先天意境"NOR);
	me->set("jingmai/chongmai",1);
	me->set("jingmai/daimai",1);
	call_out("do_back", 5, me );	
	return 1;
}
int do_back(object me)
{
	object monk1, room1, room2;
	int i;
	message("vision", "\n"+me->short()+HIY"挥了挥手， 武林同道随即鱼贯离开焚静山庄。\n"NOR, environment(me) );
    
	if(!( room1 = find_object("/d/zhenjiang/fenjingshanzhuang")) ) room1 = load_object("/d/zhenjiang/fenjingshanzhuang");
	for(i=0; i<sizeof(names); i++) 
	{
		if(!( room2 = find_object(dirs[i])) ) room2 = load_object(dirs[i]);
		if( objectp( monk1 = present(names[i], room1) ));
		if (monk1) monk1->move(room2);
    }
//	me->delete("xiantian_fighter");
//	me->move("/d/wudang/sanqingdian");
	room1->set("exits/out", "/d/zhenjiang/shanlu9");

	return 1;
}
