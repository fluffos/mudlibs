// by Amis 2006-9-23 20:18

#include <ansi.h>
#include <localtime.h>

void init()
{
	add_action("block_cmd","beg",1);
	add_action("block_cmd","steal",1);
	add_action("block_cmd","sleep",1);
	add_action("block_cmd","learn",1);
	add_action("block_cmd","practice",1);
	add_action("do_canwu","canwu",1);
}

int block_cmd()
{
	object ob = this_object();
	if ( ob->query("定做/qiguan") )
	{
		write("由于刚出现慧心横空，附近有不少武林高手在观想天地，你还是收敛点吧！\n");
		return 1;
	}
}

int do_canwu()
{
	object ob,me;	
//	object *usr;
//	string str;	
//	int i,ip_cnt;
	mixed *local;
	int j,skl_num;
	mapping skl;
	string *sname;
	string *mpforce=({"hamagong","bitao-shengong","wangran-xinfa","kumu-shengong","linji-zhuang","shayi-xinfa","huntian-qigong","shenyuan-gong","yunv-xinfa","yunv-xinjing","lengyue-shengong","baiyun-xinfa","zhenyue-jue","honghua-shengong","zixia-shengong","guiyuan-dafa","xuantian-wuji","bahuang-gong","bingxue-xinfa","wuzheng-xinfa","shenghuo-shengong","xuanmen-gangqi","tiangang-zhengqi","xiantian-qigong","kuihua-xinfa","tianmo-shengong","wuji-shengong","shenlong-xinfa","zhenfeng-xinfa","shushan-force","hanbing-zhenqi","panshi-shengong","biyun-xinfa","bibo-shengong","guiyuan-tunafa","fanyun-force","damo-force","wudu-shengong","taiji-shengong","yinyun-ziqi","wudie-xinjing","beiming-shengong","huagong-dafa","lingyuan-xinfa","longxiang","xiaowuxiang","xuedao-xinfa","yiqiguan-riyue","huaxue-dafa","longmen-shengong","mingyu-shengong","yunlong-shengong","hunyuan-yiqi","yijinjing","yijing-force","jiuyang-shengong","jiuyin-zhenjing","xixing-dafa","taixuan-gong","xiaoyao-xinfa",});
	string *order = ( {""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
	string *poem = ({
		"他强任他强，清风拂山岗；他横任他横，明月照大江。他自狠来他自恶，我自一口真气足。",
		"天之道，损有馀而补不足，是故虚胜实，不足胜有馀。其意博，其理奥，其趣深。天地之像分，阴阳之侯烈，变化之由表，死生之兆章。",
		"人徒知枯坐息思为进德之功，殊不知上达之士，圆通定慧，体用双修，即静而动，虽撄而宁。",
		"弱之胜强，柔之胜刚，天下莫不知，莫能行。天下之至柔，驰骋天下之至坚。",
		"阴极在六，何以言九。太极生两仪，天地初刨判。六阴已极，逢七归元太素，太素西方金德，阴之清纯，寒之渊源。",
		"大衍之数五十，其用四十有九，虚其一，天地易位，乾坤扭转，变化始生。",
		"太极者，天地之数也，数由一始，亦从一终，天地之止息幻化，无端无极，终归于太一。",
		"易有太极，是生两仪。太极者，道也；两仪者，阴阳也。阴阳一道也，太极无极也。",
		"人法地，地法天，天法道，道法自然。",
		"道可道，非常道；名可名，非常名。无名，万物之始，有名，万物之母。",
		"北冥有鱼，其名为鲲。鲲之大，不知其几千里也；化而为鸟，其名为鹏。鹏之背，不知其几千里也；怒而飞，其翼若垂天之云。",
		"天地所以能长且久者，以其不自生，故能长生。是以圣人后其身而身先；外其身而身存。非以其无私邪？故能成其私。",
		"天地不仁，以万物为刍狗；圣人不仁，以百姓为刍狗。天地之间，其犹橐龠乎？虚而不屈，动而俞出。多闻数穷，不若守于中。",
		"谷神不死，是谓玄牝。玄牝之门，是谓天地根。绵绵若存，用之不勤。",
		"道生一，一生二，二生三，三生万物。万物负阴而抱阳，冲气以为和。",
		"天之道，其犹张弓与？高者抑之，下者举之；有余者损之，不足者补之。",
		"天之道，损有余而补不足。人之道则不然，损不足以奉有余。孰能有余以奉天下，唯有道者。",
		"天下莫柔弱于水，而攻坚强者莫之能胜，其无以易之。弱之胜强，柔之胜刚，天下莫不知莫能行。",
		});
	ob = this_object();
	me = this_player();
	local = localtime(time());
    skl = me->query_skills();
    sname = keys(skl);
	skl_num = sizeof(skl);
	
	if ( !ob->query("定做/qiguan") ) return 0;	
    if( me->is_busy() || me->is_fighting() ) 
        return notify_fail("你正忙着呢！\n");     
	if ( me->query("jingli") < 1000 || me->query("neili") < 1000)
		return notify_fail("你实在太累了，歇歇吧！\n");
	if ( me->query("xyzx_sys/level",1) < 2000 )
		return notify_fail("以你的实力，参悟天地奥秘恐怕会遭天谴。\n");
	if ( me->query_skill("force",1) < 5000 )
		return notify_fail("你的基本功不够扎实，参悟天地奥秘恐怕会遭天机反噬。\n");
	if ( me->query_skill("literate",1) < 10000 )
		return notify_fail("你大字不识几个，难以参悟天象奇观。\n");
	if ( me->query("max_jingli") < 1000000 || me->query("max_neili") < 1000000)
		return notify_fail("你的精力内力修为太差了，无法抵抗天地奇观的伟力！\n");
	if (skl_num > 50 )
		return notify_fail("你杂学太多了，难以静下心来观想天地。\n");
	if ( local[LT_MDAY] == (int)me->query("qiguan_force"))	//每天
	{
		write(HIR"天象无常而人力有穷，故每天只能参悟天下奇观一次！\n"NOR);
		return 1;
	}
//放开IP管制	
/*	usr = get_all_user();
	str=query_ip_number(me);
	ip_cnt=0;
	for(i=0; i<sizeof(usr); i++)
	{
		if (str==query_ip_number(usr[i]) && usr[i]->query_temp("ip_qiguan")) ip_cnt++;
	}
	if ( ip_cnt > 3 ) 
	{
		write("这个IP上挖流星的玩家太多了，给其他人一个机会吧！\n");	
		return 1;
	}
*/
//这几种写法有何不用？
//	message_vision(HIG"此地慧心横空，天降奇观，$N开始观想天地，试图能参悟出某种武功绝学。\n"NOR, me);
//	write(HIG"此地慧心横空，天降奇观，你开始观想天地，试图能参悟出某种武功绝学。\n"NOR,me);
	write(HIG"此地慧心横空，天降奇观，你开始观想天地，试图能参悟出某种武功绝学。\n"NOR);
	write("\n"+(order[random(sizeof(order))])+"" + poem[random(sizeof(poem))] + "\n"NOR);
	me->set_temp("ip_qiguan", 1);
	me->add("neili", -1000);
	me->add("jingli", -1000);	
	me->start_busy(3);
	
	for (j=0; j<sizeof(mpforce); j++)
	{
		if (member_array(mpforce[j],sname) !=-1) continue;
		if ( random(7500)==1 )
		{
			me->set("qiguan_force", local[LT_MDAY]);
			me->set_skill(mpforce[j],200);
			write(HIY"你在慧心横空之时，观想天地，参悟出了 "+HIM+to_chinese(mpforce[j])+HIY+" ！\n"NOR);
			message("channel:chat", HIR"【天下奇观】"+HIM"听说 "HIG+me->query("name")+HIM" 在慧心横空之地，观想天地，参悟出了 "+HIR+to_chinese(mpforce[j])+HIM+" ！\n"NOR,users() );	
			break;
		}
	}

	return 1;
}

