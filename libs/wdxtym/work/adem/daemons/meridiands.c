//meridianssds.c
/*
meridianss/belt
meridianss/punching
*/
//by luoyun 2016.6.27

#include <ansi.h>

mapping xuewei = ([
	"带脉" : ({ "带脉","五枢","维","天冲","浮白","头窍阴","完骨","本神","阳白", "头临泣","目窗","正营","承灵","脑空","外丘","光明","阳辅","悬钟","丘墟", }),
	"冲脉" : ({ "会阴", "阴交", "气冲", "横骨", "大赫", "气", "四满", "中注", "肓俞", "商曲", "石关", "阴都", "通谷", "幽门", "关门", "太乙", "滑肉门", "天枢", "外陵", "大巨", "水道", "归来", "水突", "气舍", }),
	"阴维脉" : ({ "府舍", "大横", "阳交", "腹哀", "期门", "廉泉", "天突","极泉", "青灵", "少海", "冲门","灵道", "通里", "阴郄", "神门", "少府", "少冲", "筑宾", }),
	"阳维脉" : ({ "金门","阳交","臑俞","天髎","肩井", "头维","本神","阳白","头临泣","目窗","正营","承灵","脑空","风池","风府","哑门","云门","尺泽","孔最","列缺","经渠","太渊","鱼际","少商", }),
	"阴跷脉" : ({ "然谷", "照海", "交信", "阴谷", "横谷", "气冲", "乳根", "盆缺", "人迎", "睛明", "不容", "梁门", "横鼻", "足三里", "丰隆", "解溪", "冲阳", "属兑", }),
	"阳跷脉" : ({ "申脉", "仆参", "跗阳", "居髎", "臑俞", "肩髃", "巨骨", "地仓", "巨髎", "承泣", "风池", "攒竹", "眉冲", "曲差", "五处", "承光", "通天", "络却", "玉枕", "天柱", "承山", "飞扬", "昆仑", }),
	"手三阳经":({ "迎香","禾髎","扶突","天鼎","巨骨","手五里","阳溪","商阳","丝竹空","角孙","天牖","肩髎","清冷渊","四渎","中渚","关冲","听宫","颧髎","天容","天窗","天宗","小海","后溪","少泽",}),
	"手三阴经":({ "天府","尺泽","孔最","列缺","经渠","太渊","鱼际","少商","天池","曲泽","郄门","间使","内关","大陵","劳宫","中冲","极泉","少海","灵道","通里","阴郄","神门","少府","少冲",}),
]);

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
	string *strin,card,name,nameb,type;
	int size,i,j,cc_len,tmp,m,n,num;

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
	cc_len = me->query("meridianss/" + name) - 1;
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
	else if(name=="带脉")
	{
		line += "最大气血额外附加"+me->query("gain/max_qi")+"点。\n";
	}
	else if(name=="阳跷脉")
	{
		line += to_chinese(me->query("meridianss/ap"))+"激发等级额外附加"+me->query("gain/attack")+"级。\n";
	}
	else if(name=="阴跷脉")
	{
		line += to_chinese(me->query("meridianss/dp"))+"激发等级额外附加"+me->query("gain/defense")+"级。\n";
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

	return line+"\n";
}

int do_through(object me)
{
	object item;
	int myxue,i,size,index,xue_level,j,jilv, lv,num;
	string *xue, msg, name, dname, obid,str,type;

	if (!me)  
		return 0;

	if(!me->query_temp("meridianss"))
	{		
		tell_object(me, "你试图冲击奇经八脉，但是却徒劳无获！\n");
		return 1;
	}

	name = me->query_temp("meridianss/name");
	dname = me->query_temp("meridianss/dname");

	if(member_array(name,keys(xuewei))==-1)
	{
		tell_object(me, "你试图冲击奇经八脉，但是真气无目的乱转，结果毫无所获！\n");
		return 1;
	}

	if(!wizardp(me)&&( name == "手三阳经1" || name == "手三阴经1"))
	{
		tell_object(me, "手三阳经和手三阴经正在测试中！\n");
		return 1;
	}

	if(!item = present(dname, me))
	{
		tell_object(me,"冲击奇经八脉是十分困难和危险的，还是准备些辅助丹药为妙！\n");
		return 1;
	}

	if (!item->query("needle/level"))
	{
		tell_object(me,"这种东西也拿来辅助冲脉，你想自杀么？\n");
		return 1;
	}

	xue = xuewei[name];
	//获取穴位打通数
	myxue = me->query("meridianss/" + name);

	if (item->query("needle/level")<=myxue)
	{
		tell_object(me,"你使用的药品品级太低了，这样太危险了！\n");
		return 1;
	}

	if (me->query_skill("force")<(100+myxue*10)&&item->query("needle/level")<20)
	{
		tell_object(me,"你目前的内功修为冲击当前穴位尚欠火候，只有用极品丹药辅助才有可能成功！\n");
		return 1;
	}

	//血脉上限多少条
	size = sizeof(xue);
	//
	
	if(myxue >= size)
	{
		tell_object(me,sprintf("你的%s已经全部打通，没有必要再来一遍。\n", name));
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

	//每个穴位冲穴成功率平均2%
	jilv = 25;

	item->add_amount(-1);

	//获取单条脉冲穴最近失败次数，关联当前冲击成功率
	lv = me->query("chongxue/times/"+name);
	if (random(100-lv*3)>jilv||(lv<20&&random(2))) {
		tell_object(me,HIR"你试图用内力冲开"+name+"的「"+xue[myxue]+"」穴位，但是结果不幸失败了。"NOR"\n");
		tell_object(me,HIM"已冲击"+name+"的「"+xue[myxue]+"穴」的次数："+(lv+1)+NOR"\n");
		tell_object(me,"继续冲击"+name+"的"ZJURL("cmds:beat "+name+" with "+dname)+"「"+xue[myxue]+"穴」"NOR"\n");
		me->add("chongxue/times/"+name, 1);
		return 1;
	}

	me->add("meridianss/" + name, 1);
	//冲击成功，重置该经脉冲击失败次数
	me->delete("chongxue/times/"+name);

	//全部打通的奖励
	if(me->query("meridianss/" + name) >= size)
	{
		index = size;
		
		if (name == "冲脉") {//冲脉全部打通后一次奖励(150)
			num = 150;
			me->add("gain/damage", num );
		}else
		if (name == "带脉") {//带脉全部打通后一次奖励(1888)
			num = 1888;
			me->add("gain/max_qi", num );
		}else
		if (name == "阴跷脉") {//阴跷脉全部打通后一次奖励(75)
			num = 75;
			me->add("gain/defense", num );
		}else
		if (name == "阳跷脉") {//阳跷脉全部打通后一次奖励(75)
			num = 75;
			me->add("gain/attack", num );
		}else
		if (name == "阴维脉") {//阴维脉全部打通后一次奖励(12)
			num = 12;
			me->add("gain/2dp", num );
		}else
		if (name == "阳维脉") {//阳维脉全部打通后一次奖励(12)
			num = 12;
			me->add("gain/2ap", num );
		}
		else
		if (name == "手三阳经") {//手三阳经全部打通后一次奖励(155)
			num = 155;
			me->add("gain/break", num );
		}
		else
		if (name == "手三阴经") {//手三阴经全部打通后一次奖励(155)
			num = 155;
			me->add("gain/armor", num );
		}
		
		tell_object(me,sprintf(HIY"恭喜！你的 %s 已全部打通，"+type+"额外加成%d点。"NOR"\n",name, num));
		
		message("channel:rumor", HIR"【系统】"+HIY+me->name()+"通过不懈努力终于将"+name+
					 "的「"+name+"」的穴位全部打通，"+type+"额外增加"+num+"点。"NOR"\n",users());
	}
	else
	{
		index = myxue + 1;
		
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
			else if(index<=7)
			{
				num = 1;
				me->add("gain/2ap", num );
			}
			else if(index<=13)
			{
				num = 2;
				me->add("gain/2ap", num );
			}
			else if(index<=17)
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

		tell_object(me,sprintf(HIG"你运功不断向"+name+"的%s穴冲击……\n你感觉"+name+
					   "的阻塞已经被内力化解开，瞬间全身舒畅无比。"+NOR"\n",xue[myxue]));
		tell_object(me,sprintf(HIG"恭喜你！成功打通"+name+"的【%s穴】，"+type+"增加"+num+"点。"+NOR"\n",xue[myxue]));
		tell_object(me,ZJURL("cmds:beat "+name+" with "+dname)+"继续冲击"NOR"\n");
		
	//	message("channel:rumor", HIR"【系统】"HIY+me->name()+"通过不懈努力，终于将"+name+"的「"+xue[myxue]+"穴」打通了。"NOR"\n",users());
		log_file("meridianss",sprintf("%s：%s(%s)第%d次打通%s的%s穴。\n",ctime(time()),me->query("name"),me->query("id"),lv+1,name,xue[myxue]));
	}
	
	if(me->query("meridianss/冲脉") >=24
	&& me->query("meridianss/带脉") >=19
	&& me->query("meridianss/阳维脉") >=24
	&& me->query("meridianss/阴维脉") >=18
	&& me->query("meridianss/阳跷脉") >=23
	&& me->query("meridianss/阴跷脉") >=18
	&& me->query("meridianss/手三阴经") >=24
	&& me->query("meridianss/手三阳经") >=24)
	{
		me->add("max_neili", 5000);
		me->add("gain/2ap", 8);
		tell_object(me,HIG"恭喜你！成功打通8条经脉，一时间只觉全身真气行走全身，生生不息。"NOR"\n");
		message_vision(HIY"$N长啸一声，啸声清越激昂，连绵不绝！！！"NOR"\n",me);
	}

	return 1;
}