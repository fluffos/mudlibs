//meridiand.c
/*
meridian/belt
meridian/punching
*/
//by luoyun 2016.6.27



mapping xuewei = ([
	"带脉" : ({ "带脉","五枢","维","天冲","浮白","头窍阴","完骨","本神","阳白", "头临泣","目窗","正营","承灵","脑空","外丘","光明","阳辅","悬钟","丘墟", }),
	"冲脉" : ({ "会阴", "阴交", "气冲", "横骨", "大赫", "气", "四满", "中注", "肓俞", "商曲", "石关", "阴都", "通谷", "幽门", "关门", "太乙", "滑肉门", "天枢", "外陵", "大巨", "水道", "归来", "水突", "气舍", }),
	"阴维脉" : ({ "府舍", "大横", "阳交", "腹哀", "期门", "廉泉", "天突","极泉", "青灵", "少海", "冲门","灵道", "通里", "阴郄", "神门", "少府", "少冲", "筑宾", }),
	"阳维脉" : ({ "金门","阳交","臑俞","天髎","肩井", "头维","本神","阳白","头临泣","目窗","正营","承灵","脑空","风池","风府","哑门","云门","尺泽","孔最","列缺","经渠","太渊","鱼际","少商", }),
	"阴跷脉" : ({ "然谷", "照海", "交信", "阴谷", "横谷", "气冲", "乳根", "盆缺", "人迎", "睛明", "不容", "梁门", "横鼻", "足三里", "丰隆", "解溪", "冲阳", "属兑", }),
	"阳跷脉" : ({ "申脉", "仆参", "跗阳", "居髎", "臑俞", "肩髃", "巨骨", "地仓", "巨髎", "承泣", "风池", "攒竹", "眉冲", "曲差", "五处", "承光", "通天", "络却", "玉枕", "天柱", "承山", "飞扬", "昆仑", }),
	"手三阳经":({ "迎香","禾髎","扶突","天鼎","巨骨","手五里","阳溪","商阳","丝竹空","角孙","天牖","肩髎","清冷渊","四渎","中渚","关冲","听宫","颧髎","天容","天窗","天宗","小海","后溪","少泽",}),
	"手三阴经":({ "天府","尺泽","孔最","列缺","经渠","太渊","鱼际","少商","天池","曲泽","郄门","间使","内关","大陵","劳宫","中冲","极泉","少海","灵道","通里","阴郄","神门","少府","少冲",}),
	//瞳子髎、听会、上关、颔厌、悬颅、悬厘、曲鬓、率谷、天冲、浮白、头窍阴、完骨、本神、阳白、头临泣、目窗、正营、承灵、脑空、风池、肩井、渊液、辄筋、日月、京门、带脉、五枢、维道、居髎、环跳、风市、中渎、膝阳关、阳陵泉、阳交、外丘、光明、阳辅、悬钟、丘墟、足临泣、地五会、侠溪、足窍阴
	//保留前25个穴位
	"足三阳经":({"瞳子髎","听会","上关","颔厌","悬颅","悬厘","曲鬓","率谷","天冲","浮白","头窍阴","完骨","本神","阳白","头临泣","目窗","正营","承灵","脑空","风池","肩井","渊液","辄筋","日月","京门",}),
	"奇经总脉" : ({ "百会", "神庭", "印堂", "素髎", "水沟", "承浆", "廉泉", "天突", "璇玑", "华盖", "紫宫", "玉堂", "膻中", "中庭", "鸠尾", "巨阙", "上脘", "中脘", "建里", "下脘", "水分", "神阙", "阴交", "气海", "石门", "关元", "中极", "曲骨", "会阴", "长强", "腰俞", "命门", "悬枢", "脊中", "至阳", "灵台", "神道", "身柱", "陶道", "大椎", "哑门", "风府", "脑户", "强间", "后顶", "前顶", "囟会", "上星", "通天", "络却", "玉枕", "天柱", "承山", "飞扬", "昆仑", "申脉", "仆参", "跗阳", "居髎", "臑俞", "肩髃", "巨骨", "地仓", "巨髎", "承泣", "攒竹", "风池", "眉冲", "曲差", "五处", "承光", "阳白", "头临泣", "目窗", "正营", "承灵", "脑空", "本神", "青灵", "少海", "神门", "少府", "少冲", "灵道", "通里", "阴郄", "阴谷", "横谷", "睛明", "不容", "梁门", "凤眼", "灵宫", "天池", "气户", "神志", "阳溪", "合谷", "太冲", "丰隆", }),
]);

int is_meridian_completed(object me, string meridian_name);

string *query_xue(string arg)
{
	if(!arg) 
		return ({""});

	if( member_array(arg,keys(xuewei))==-1 ) 
		return ({""});

	return xuewei[arg];
}
string get_xue(string mai,int num)
{
	string *mais;
	if(!(mais=xuewei[mai])) 
		return "";
	if(num<0||num>=sizeof(mais)) 
		return "";
	return mais[num];
}
varargs string do_score(object me,string arg)
{
 string *strin,card,name,nameb;
 int size,i,cc_len,tmp,m,n;

	string line  = "";

	if(!arg)
	{
		strin = keys(xuewei);
		for(i=0;i<sizeof(strin);i++)
		{
			line += strin[i]+":beat "+strin[i];
			if(i<(sizeof(strin)-1)) line += ZJSEP;
		}
		return line;
	}

	if(!xuewei[arg]) return "";
	name = arg;

	strin = query_xue(name);
	size = sizeof(strin);
	cc_len = me->query("meridian/" + name) - 1;
	tmp = 1;
	card = "";
	n=0;
	m=0;

	for(i=0;i<size;i++)
	{
		tmp ++;
		nameb = strin[i];
		nameb += "穴";

		if(i > cc_len)  {
			n++;
			card += sprintf("%-10s"NOR, nameb);
		}
		else  {
			m++;
			card += sprintf(HIG"%-10s"NOR, nameb);
		}
		if(tmp > 5 && i+1 < size)
		{
			card += "\n";
			tmp = 1;
		}
	}
	line += sprintf(HIY"[%s]"NOR" 共%s个穴道\n", name, HIR+size+NOR);
	line += sprintf("%s\n",card);
	line += sprintf("%-20s%s\n", "已经冲开"+m+"个", "还有"+n+"个未冲开");

	if(m==0)
		return line+"\n";

	if(name=="冲脉")
	{
		line += "基础伤害额外附加"+me->query("gain/damage")+"点。\n";
	}
	else if(name=="带脉" || name=="奇经总脉")
	{
		line += "最大气血额外附加（指目前所有经脉气血，不单指一条经脉）"+me->query("gain/max_qi")+"点。\n";
	}
	else if(name=="阳跷脉")
	{
		line += to_chinese(me->query("meridian/ap"))+"激发等级额外附加"+me->query("gain/attack")+"级。\n";
	}
	else if(name=="阴跷脉")
	{
		line += to_chinese(me->query("meridian/dp"))+"激发等级额外附加"+me->query("gain/defense")+"级。\n";
	}
	else if(name=="阳维脉")
	{
		line += "暴击增加"+me->query("gain/2ap")+"点。\n";
	}
	else if(name=="阴维脉")
	{
		line += "抗暴增加"+me->query("gain/2dp")+"点。\n";
	}
	else if(name=="手三阳经")
	{
		line += "破甲增加"+me->query("gain/break")+"点。\n";
	}
	else if(name=="手三阴经")
	{
		line += "护体增加"+me->query("gain/armor")+"点。\n";
	}
	else if(name=="足三阳经")
	{
		line += "忙乱化解系数"+me->query("gain/busy")+"点。\n";
	}
	return line+"\n";
}

int do_through(object me)
{
	object item;
	int myxue, lv,num,size,jilv,index;
	string *xue, name, dname,type;

	if (!me)  
		return 0;

	if(!me->query_temp("meridian"))
	{		
		tell_object(me, "你运转真气试图冲击奇经八脉，但真气浑浊不纯,难以贯通经脉,只得作罢！\n");
		return 1;
	}

	name = me->query_temp("meridian/name");
	dname = me->query_temp("meridian/dname");

	if(member_array(name,keys(xuewei))==-1)
	{
		tell_object(me, "你运转真气欲冲击奇经八脉，却见真气如无头苍蝇般在体内乱窜，毫无章法可言，只得作罢！\n");
		return 1;
	}

	// if(!wizardp(me)&&( name == "手三阳经1" || name == "手三阴经1"))
	// {
	// 	tell_object(me, "手三阳经和手三阴经正在测试中！\n");
	// 	return 1;
	// }

	if(!item = present(dname, me))
	{
		tell_object(me,"冲击奇经八脉乃是武学至高境界，稍有不慎便会走火入魔，还是备些灵丹妙药护体为上！\n");
		return 1;
	}

	if (!item->query("needle/level"))
	{
		tell_object(me,"你拿出这等粗劣之物也想冲击经脉？怕是不想活命了！\n");
		return 1;
	}

	xue = xuewei[name];
	//获取穴位打通数
	myxue = me->query("meridian/" + name);

	//奇经总脉只能使用极品丹药，也就是等级25及以上的丹药
	if (name == "奇经总脉" && item->query("needle/level")<25)
	{
		tell_object(me,"奇经总脉乃人体经络之精华所在，非顶级灵丹妙药不足以助你冲击！\n");
		return 1;
	}

	//如果是奇经总脉，必须bamai-tong存在并且打通了全部的足三阳经脉，总计9条脉才能冲击奇经总脉
	if (name == "奇经总脉" && (!me->query("bamai-tong") || me->query("meridian/足三阳经") < 25)) {
		tell_object(me, "奇经总脉乃人体经络之精华所在，需得先将九条大脉尽数打通，方可尝试冲击。你现在功力未到，还需继续努力！\n");
		return 1;
	}

	if (item->query("needle/level")<=myxue && item->query("needle/level") < 25)
	{
		tell_object(me,"你所用丹药品阶太低,贸然冲击经脉恐有性命之忧！\n");
		return 1;
	}

	if (me->query_skill("force")<(100+myxue*10)&&item->query("needle/level")<20)
	{
		tell_object(me,"你运转真气冲击穴位，却觉得内力浑厚程度尚且不足，除非借助极品丹药之力，否则难以突破瓶颈！\n");
		return 1;
	}

	//血脉上限多少条
	size = sizeof(xue);
	//
	
	if(myxue >= size)
	{
		tell_object(me,sprintf("你的%s经脉已尽数贯通，气血流转自如，再行冲击反而有碍经脉运行。\n", name));
		return 1;
	}
	
	if (name == "冲脉") {
		type = "伤害";
	}
	else if (name == "带脉") {
		type = "气血";
	}
	else if (name == "阴跷脉") {
		type = "防御等级";
	}
	else if (name == "阳跷脉") {
		type = "攻击等级";
	}
	else if (name == "阴维脉") {
		type = "抗暴";
	}
	else if (name == "阳维脉") {
		type = "暴击";
	}
	else if (name == "手三阳经") {
		type = "破甲";
	}
	else if (name == "手三阴经") {
		type = "护体";
	}
	else if (name == "足三阳经") {
		type = "忙乱化解概率";
	}
	else
	if (name == "奇经总脉") {
		type = "气血";
	}
	else {
		type = "未知";
	}

	//每个穴位冲穴成功率平均2%
	jilv = 2;
	// 如果不是宗师则突破概率提升2倍
	if (!me->query("opinion/ultra"))
		jilv = 4;

	item->add_amount(-1);

	//获取单条脉冲穴最近失败次数，关联当前冲击成功率
	lv = me->query("chongxue/times/"+name);
	if ( (random(200-lv*3)>jilv||(lv<20&&random(2))) && !wizardp(me)) {
		tell_object(me,HIR"你运转真气冲击"+name+"的「"+xue[myxue]+"」穴道，却见真气流转受阻，难以贯通。"NOR"\n");
		tell_object(me,HIM"你已尝试冲击"+name+"「"+xue[myxue]+"」穴道"+(lv+1)+"次，或需另寻他法。"NOR"\n");
		if (me->query("env/auto_chongmai"))
		{
			// me->force_me("beat "+name+" with "+dname);
			// 延迟1秒再冲击
			function f = (: call_other, me, "force_me", "beat "+ name+" with "+dname :);

			call_out(f, 1);
			tell_object(me,"自动冲脉中\n");
		}
		else
		{
			tell_object(me,"继续冲击"+name+"的"ZJURL("cmds:beat "+name+" with "+dname)+"「"+xue[myxue]+"穴」"NOR"\n");
		}
		me->add("chongxue/times/"+name, 1);
		return 1;
	}

	me->add("meridian/" + name, 1);
	//冲击成功，重置该经脉冲击失败次数
	me->delete("chongxue/times/"+name);

	//全部打通的奖励
	if(me->query("meridian/" + name) >= size)
	{
		index = size;
		
		if (name == "冲脉") {//冲脉全部打通后一次奖励(120)
			num = 120;
			me->add("gain/damage", num );
		}else
		if (name == "带脉") {//带脉全部打通后一次奖励(1600)
			num = 1600;
			me->add("gain/max_qi", num );
			CHAR_D->setup_char(me);

			// 恢复气血
			me->receive_heal("qi", num);
			me->receive_curing("qi", num);

		}else
		if (name == "阴跷脉") {//阴跷脉全部打通后一次奖励(60)
			num = 60;
			me->add("gain/defense", num );
		}else
		if (name == "阳跷脉") {//阳跷脉全部打通后一次奖励(60)
			num = 60;
			me->add("gain/attack", num );
		}else
		if (name == "阴维脉") {//阴维脉全部打通后一次奖励(6)
			num = 6;
			me->add("gain/2dp", num );
		}else
		if (name == "阳维脉") {//阳维脉全部打通后一次奖励(8)
			num = 8;
			me->add("gain/2ap", num );
		}
		if (name == "手三阳经") {//手三阳经全部打通后一次奖励(120)
			num = 120;
			me->add("gain/break", num );
		}
		else
		if (name == "手三阴经") {//手三阴经全部打通后一次奖励(120)
			num = 120;
			me->add("gain/armor", num );
		}
		else
		if (name == "足三阳经") {//足三阳经全部打通后一次奖励(6)
			num = 6;
			me->add("gain/busy", num );
		}
		else
		if (name == "奇经总脉") {//奇经总脉全部打通后一次奖励(5200)，所有经脉气血上限增加总数为19800 + 5200 = 25000
			num = 5200;
			me->add("gain/max_qi", num );
			CHAR_D->setup_char(me);

			// 恢复气血
			me->receive_heal("qi", num);
			me->receive_curing("qi", num);
		}

		tell_object(me,sprintf(HIR"只见一股暖流游走全身，你感觉%s经脉已尽数贯通，"+type+"修为更上一层楼，增加%d点。"NOR"\n",name, num));
		
		message("channel:rumor", HIM"【武林快报】"+HIC+"听说"+me->name()+"苦心钻研武学，终于将"+name+
					 "经脉中的诸多穴道尽数贯通，"+type+"修为大有精进，武功更上层楼！"NOR"\n",users());
	}
	else
	{
		index = myxue + 1;
		
		// 如果是奇经总脉，每次冲击成功后增加气血上限200点
		if (name == "奇经总脉") {
			num = 200;
			me->add("gain/max_qi", num );
			// 恢复气血
			me->receive_heal("qi", num);
			me->receive_curing("qi", num);
		}
		else
		if (name == "冲脉") {//增加固定伤害力(24个穴道总共增加365伤害)
			if(index<=5)
			{
				num = 10;
				me->add("gain/damage", num);
			}
			else if(index<=10)
			{
				num = 12;
				me->add("gain/damage", num);
			}
			else if(index<=15)
			{
				num = 15;
				me->add("gain/damage", num);
			}
			else
			{
				num = 20;
				me->add("gain/damage", num);
			}
		}else
		if (name == "带脉") {//冲脉增加固定气血上限(19个穴道总共增加9200气血)
			if(index<=5)
			{
				num = 300;
				me->add("gain/max_qi", num );
			}
			else if(index<=10)
			{
				num = 400;
				me->add("gain/max_qi", num );
			}
			else if(index<=15)
			{
				num = 500;
				me->add("gain/max_qi", num );
			}
			else
			{
				num = 800;
				me->add("gain/max_qi", num );
			}
			CHAR_D->setup_char(me);
			// 恢复气血
			me->receive_heal("qi", num);
			me->receive_curing("qi", num);
		}else
		if (name == "阴跷脉") {//阴跷脉增加固定躲闪等级(18个穴道总共增加305防御等级【躲闪招架】)
			if(index<=5)
			{
				num = 10;
				me->add("gain/defense", num );
			}
			else if(index<=10)
			{
				num = 12;
				me->add("gain/defense", num );
			}
			else if(index<=15)
			{
				num = 15;
				me->add("gain/defense", num );
			}
			else
			{
				num = 20;
				me->add("gain/defense", num );
			}
		}else
		if (name == "阳跷脉") {//阳跷脉增加固定命中等级(23个穴道总共增加405攻击等级【命中】)
			if(index<=5)
			{
				num = 10;
				me->add("gain/attack", num );
			}
			else if(index<=10)
			{
				num = 12;
				me->add("gain/attack", num );
			}
			else if(index<=15)
			{
				num = 15;
				me->add("gain/attack", num );
			}
			else
			{
				num = 20;
				me->add("gain/attack", num );
			}
		}else
		if (name == "阴维脉") {//阴维脉增加抗暴击(18个穴道总共增加35点【抗暴】)
			if(index<=5)
			{
				num = 1;
				me->add("gain/2dp", num );
			}
			else if(index<=10)
			{
				num = 1;
				me->add("gain/2dp", num );
			}
			else if(index<=15)
			{
				num = 2;
				me->add("gain/2dp", num );
			}
			else
			{
				num = 3;
				me->add("gain/2dp", num );
			}
		}else
		if (name == "阳维脉") {//阳维脉增加暴击(24个穴道总共增加50点【暴击】)
			if(index<=5)
			{
				num = 1;
				me->add("gain/2ap", num );
			}
			else if(index<=10)
			{
				num = 1;
				me->add("gain/2ap", num );
			}
			else if(index<=15)
			{
				num = 2;
				me->add("gain/2ap", num );
			}
			else if(index<=20)
			{
				num = 2;
				me->add("gain/2ap", num );
			}
			else
			{
				num = 3;
				me->add("gain/2ap", num );
			}
		}
		else
		if (name == "手三阳经") {//增加破甲(24个穴道总共增加365破甲)
			if(index<=5)
			{
				num = 10;
				me->add("gain/break", num);
			}
			else if(index<=10)
			{
				num = 12;
				me->add("gain/break", num);
			}
			else if(index<=15)
			{
				num = 15;
				me->add("gain/break", num);
			}
			else
			{
				num = 20;
				me->add("gain/break", num);
			}
		}else
		if (name == "手三阴经") {//增加护体(24个穴道总共增加365护体)
			if(index<=5)
			{
				num = 10;
				me->add("gain/armor", num);
			}
			else if(index<=10)
			{
				num = 12;
				me->add("gain/armor", num);
			}
			else if(index<=15)
			{
				num = 15;
				me->add("gain/armor", num);
			}
			else
			{
				num = 20;
				me->add("gain/armor", num);
			}
		}
		else //足三阳经 每个穴道增加1点忙乱化解概率
		if (name == "足三阳经") {
			num = 1;
			me->add("gain/busy", num);
		}

		tell_object(me,sprintf(HIG"你运转真气，一股内力如长江大河般奔腾不息，向"+name+"的%s穴汹涌而去……\n"+
					   "只听'嗡'的一声轻响，"+name+"的阻滞豁然贯通，一股暖流遍布全身，说不出的舒泰！"+NOR"\n",xue[myxue]));
		tell_object(me,sprintf(HIG"天助我也！"+name+"的【%s穴】被你一举冲开，"+type+"修为更上一层，增进"+num+"之数。"+NOR"\n",xue[myxue]));
		if (me->query("env/auto_chongmai"))
		{
			// me->force_me("beat "+name+" with "+dname);
			// 延迟1秒再冲击
			function f = (: call_other, me, "force_me", "beat "+name+" with "+dname :);

			call_out(f, 1);
			tell_object(me,"自动冲脉中\n");
		}
		else
		{
			tell_object(me,ZJURL("cmds:beat "+name+" with "+dname)+"继续冲击"NOR"\n");
		}
		
		message("channel:rumor", HIR"【武林快报】"HIG"江湖传闻"+me->name()+"苦心钻研经脉奥秘，一朝顿悟，成功打通"+name+"「"+xue[myxue]+"穴」，实乃武学奇才！"NOR"\n",users());
		log_file("meridian",sprintf("%s：%s(%s)第%d次打通%s的%s穴。\n",ctime(time()),me->query("name"),me->query("id"),lv+1,name,xue[myxue]));
	}

	//是否打通了8条经脉
	//检查是否打通了8条经脉
	if(is_meridian_completed(me, "冲脉") 
	&& is_meridian_completed(me, "带脉")
	&& is_meridian_completed(me, "阳维脉") 
	&& is_meridian_completed(me, "阴维脉")
	&& is_meridian_completed(me, "阳跷脉")
	&& is_meridian_completed(me, "阴跷脉")
	&& is_meridian_completed(me, "手三阴经")
	&& is_meridian_completed(me, "手三阳经")
	&& !me->query("bamai-tong"))
	{
		me->add("max_neili", 5000);
		me->add("gain/2ap", 8); 
		me->set("bamai-tong",1);
		tell_object(me,HIG"恭喜你！成功打通8条经脉，一时间只觉全身真气行走全身，生生不息。"NOR"\n");
		message_vision(HIY"$N长啸一声，啸声清越激昂，连绵不绝！！！"NOR"\n",me);
	}

	//检查是否打通了十脉
	if(is_meridian_completed(me, "冲脉")
	&& is_meridian_completed(me, "带脉")
	&& is_meridian_completed(me, "阳维脉")
	&& is_meridian_completed(me, "阴维脉") 
	&& is_meridian_completed(me, "阳跷脉")
	&& is_meridian_completed(me, "阴跷脉")
	&& is_meridian_completed(me, "手三阴经")
	&& is_meridian_completed(me, "手三阳经")
	&& is_meridian_completed(me, "足三阳经")
	&& is_meridian_completed(me, "奇经总脉")
	&& !me->query("shimai-tong"))
	{
		me->set("shimai-tong",1);
		CHAR_D->setup_char(me);
		tell_object(me,HIG"恭喜你！成功打通十脉，一时间只觉全身真气行走全身，生生不息。"NOR"\n");
		message_vision(HIY"$N长啸一声，啸声清越激昂，连绵不绝！！！"NOR"\n",me);
	}

	return 1;
}


//返回打通的经脉数量（如果一条经脉的穴道都打通了就代表一条经脉被打通了）
int query_meridian_count(object me)
{
	int count = 0;
	string *strin;
	int size,i;

	if (!me->query("meridian"))
	{
		return 0;
	}

	strin = keys(me->query("meridian"));
	size = sizeof(strin);
	for(i=0;i<size;i++)
	{

		//不是一个数字类型，conti
		if(!intp(me->query("meridian/"+strin[i])))
		{
			continue;
		}

		if(me->query("meridian/"+strin[i])>=sizeof(xuewei[strin[i]]))
		{
			count++;
		}
	}
	return count;
}

/**
 * @brief 检查指定经脉是否已全部打通
 * @param object me 玩家对象
 * @param string meridian_name 经脉名称
 * @return int 1-已全部打通 0-未全部打通
 * @author Lu Dexiang
 */
int is_meridian_completed(object me, string meridian_name)
{
    // 参数检查
    if (!objectp(me) || !stringp(meridian_name)) {
        return 0;
    }

    // 检查经脉是否存在
    if (!me->query("meridian") || !intp(me->query("meridian/" + meridian_name))) {
        return 0;
    }

    // 检查经脉穴位数量是否达标
    if (me->query("meridian/" + meridian_name) >= sizeof(xuewei[meridian_name])) {
        return 1;
    }

    return 0;
}

/**
 * @brief 获取已打通的经脉列表
 * @param object me 玩家对象
 * @return string* 已打通经脉名称数组
 * @author Lu Dexiang
 */
string *get_completed_meridians(object me)
{
    string *completed = ({});
    string *meridians;
    
    // 参数检查
    if (!objectp(me)) {
        return completed;
    }
    
    // 获取所有经脉
    meridians = keys(xuewei);
    
    // 遍历检查每条经脉
    foreach (string meridian in meridians) {
        if (is_meridian_completed(me, meridian)) {
            completed += ({ meridian });
        }
    }
    
    return completed;
}


