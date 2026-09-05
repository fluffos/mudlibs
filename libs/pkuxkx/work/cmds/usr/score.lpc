// score.c
//modified by vast 6/1/2003

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

string bar_string = "■■■■■■■■■■■■■■■■■■■■■■■■■";
string blank_string = "□□□□□□□□□□□□□□□□□□□□□□□□□";

string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string tribar_graph(int val, int eff, int max, string color);
string getatt(object obj);
string getdef(object obj);
string getdog(object obj);
string tough_level(int power, int hide_level);
string get_shaqi(object ob);
string get_money(object ob);
string show_combatexp(object ob);
string get_title(object ob);
string get_age(object ob,string str,string marry_type);
string get_marriage(object ob,string str);
string get_gift(object ob,mapping my,string arg);
string get_family(object ob,mapping my,string str);
string get_death(object ob,mapping my,string arg);
string get_level(object ob);
string get_exp(object ob);
string get_shen(object ob);
string get_loyalty(object ob);
void create() { seteuid(ROOT_UID); }
string custom_sc(object me,object ob,mapping my,string str,string arg,string marry_type)
{
	mapping func=(["T":get_title(ob),"A":get_age(ob,str,marry_type),"M":get_marriage(ob,str),"G":get_gift(ob,my,arg),
		"F":get_family(ob,my,str),"D":get_death(ob,my,arg),"S":get_shaqi(ob),"B":get_money(ob),"L":get_level(ob),"E":get_exp(ob),"SH":get_shen(ob),"LO":get_loyalty(ob)]);
	string *paras,line="",body="";
	if (me->query("env/custom_sc")&&stringp(me->query("env/custom_sc")))
	{
		paras=explode(me->query("env/custom_sc"), "-" );
		if (sizeof(paras)<1)
		return "";
		for (int i=0;i<sizeof(paras);i++)
		{
			if (stringp(func[paras[i]]))
			body+=func[paras[i]];
		}
		if (body=="")
		return "";
		line=sprintf(HIG"≡━◎个人档案◎━━━━━━━━━━━━━━━━━━━━━━━━≡\n\n"NOR);
		line+=body;
		line+=sprintf(HIG"≡━━━━━━━━━━━━━━━━━━━━━━◎北大侠客行◎━━≡\n"NOR);
	}
	if (line=="")
	return "";
	return line;
}
int main(object me, string arg)
{
	object ob;
	int kill,win,highestexp,highestpotential,highestlevel, shen, pot, repute;
	mapping my,prepare;
	string line, str, skill_type, temp;
	object weapon;
	int attack_points, dodge_points, parry_points;
	float attack, defense, opp_attack, opp_defense;

	string marry_type;

	if(!arg||arg=="-xiantian")
		ob = me;
	else if (wizardp(me)  || me->query("suicongdizi/npc")) {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob|| !me->visible(ob)) return notify_fail("你要察看谁的状态？\n");
		if(!wizardp(me) && me->query("suicongdizi/npc") != ob) return notify_fail("只有巫师能察看别人的状态。\n");
	} else
		return notify_fail("只有巫师能察看别人的状态。\n");

	my = ob->query_entire_dbase();
	if(me != ob)
	{
		if(my["race"]=="野兽")
			str=" 它";
		else if(my["gender"]=="男性"||my["gender"]=="无性")
			str=" 他";
		else str=" 她";
	}
	else str=" 你";

	if(undefinedp(ob->query("marry/lover"))) marry_type="未婚";
	else marry_type="已婚";
	if (custom_sc(me,ob,my,str,arg,marry_type)!="")
	{
		write(custom_sc(me,ob,my,str,arg,marry_type));
		return 1;
	}
	line = sprintf(HIG"≡━◎个人档案◎━━━━━━━━━━━━━━━━━━━━━━━━≡\n\n"NOR);
	line += get_title(ob);
	line += get_age(ob,str,marry_type);
	line += get_marriage(ob,str);
	line += get_gift(ob,my,arg);
	line += get_family(ob,my,str);
	line += get_death(ob,my,str);
	line += get_shaqi(ob);
	line += get_money(ob);

	//判断score是否溢出，会导致score命令时chinesed出错导致系统变慢。
	if (ob->query("score") < -100000000)
	{
		write(HIR"你的档案出了问题，score值过低，请向巫师查询。\n"NOR);
		destruct(ob);
		return 1;
	}
	line += get_level(ob);
	line += get_exp(ob);
	line += get_shen(ob);
	line += get_loyalty(ob);
	if ( ob->query("xiuxian_player") && ob->query("xiuxian") )
	{
	  line += sprintf(" 休闲玩家当日活跃情况一览表（日期：%s）：\n", ob->query("xiuxian/date") );
	  line += sprintf("   高级任务：%d次\t低级任务：%d次\t劫匪掉宝：%d次\n\n", ob->query("xiuxian/high_exp"), ob->query("xiuxian/low_exp"), ob->query("xiuxian/hubiao_gem") );
	}
	line += sprintf(HIG"≡━━━━━━━━━━━━━━━━━━━━━━◎北大侠客行◎━━≡\n"NOR);
	write(line);
	return 1;
}
string get_title(object ob)
{
	return sprintf( BOLD "%s" NOR "%-s" + "\n\n", RANK_D->query_rank(ob), ob->short(1) );
}
string get_age(object ob,string str,string marry_type)
{
	string line="";
	line += str;
	line += sprintf("是一%s%s岁的%s%s%s，%s生。\n\n",
	ob->query("unit"),
	chinese_number(ob->query("age")),
	marry_type,
	ob->query("gender"),
	ob->query("race"),
	CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) ) );
	return line;
}
string get_marriage(object ob,string str)
{
	string lover_id,lover_sex,lover_title,line="";
	if(!undefinedp(ob->query("couple/married")))
	{        lover_id=ob->query("couple/couple_id");
	if (ob->query("gender")=="女性")
	{    lover_title="老公";
	lover_sex="他";
	}
	else
	{    lover_title="老婆";
	lover_sex="她";
	}
	line += str + sprintf("的%s",lover_title);
	line+=sprintf("是%s。",lover_id);
	if (!find_player(lover_id))
		line+=sprintf(" 可惜%s现在不在连线中。\n\n",lover_sex);
	else
		line+=sprintf(" 目前%s正在连线中，快去接%s呀！\n\n",lover_sex,lover_sex);
	}
	return line;
}
string get_gift(object ob,mapping my,string arg)
{
	string line="",temp;
	if (arg=="-xiantian")
	{
	line += sprintf(
		" 膂力：[%s]  悟性：[%s]  根骨：[%s]  身法：[%s]\n",
		display_attr(my["str"], ob->query("str")),
		display_attr(my["int"], ob->query("int")),
		display_attr(my["con"], ob->query("con")),
		display_attr(my["dex"], ob->query("dex")));
	temp = sprintf(
		" 福缘：[%s]  容貌：[%s]  灵性：[%s]  \n",
		display_attr(my["kar"], ob->query("kar")),
		display_attr(my["per"], ob->query("per")),
		display_attr(my["spi"], 30),
		);
	}
	else
	{
	line += sprintf(
		" 膂力：[%s]  悟性：[%s]  根骨：[%s]  身法：[%s]\n",
		display_attr(my["str"], ob->query_str()),
		display_attr(my["int"], ob->query_int()),
		display_attr(my["con"], ob->query_con()),
		display_attr(my["dex"], ob->query_dex()));
	temp = sprintf(
		" 福缘：[%s]  容貌：[%s]  灵性：[%s]  \n",
		display_attr(my["kar"], ob->query("kar")),
		display_attr(my["per"], ob->query_per()),
		display_attr(my["spi"], ob->query_spi()),
		);
	}
	line += temp;
	return line;
}
string get_family(object ob,mapping my,string str)
{
	string line="";
	if(userp(ob))
	{
		if( mapp(my["family"]) )
		{
			if(my["family"]["generation"]>1 && ob->query("class") != "officer" && ob->query("class") != "eunuch")
				line += "\n" + str + "是"+my["family"]["family_name"]+"第"+chinese_number(my["family"]["generation"])+"代弟子，";
			else if(ob->query("class") == "officer" || ob->query("class") == "eunuch")
				line += "\n" + str + "是" + my["family"]["family_name"] + chinese_number(ob->query("pin"))+"品官员，";
			if( my["family"]["master_name"] )
				line = sprintf("%s" + str + "的师父是%s。\n", line, my["family"]["master_name"] );
		}
		if(ob->query("betrayer")) 
			line += sprintf(str + "曾经背叛过%s次师门。\n", chinese_number(ob->query("betrayer")));
		if(ob->query("chushi/done")) 
			line += sprintf(str + "出师前的门派是：%s。\n\n", ob->query("chushi/last_family"));
		else
			line +="\n";
            
        if(GUIDER_D->is_app(ob->query("id"))!=""&&GUIDER_D->is_app(ob->query("id"))!="is_GUIDER")
        {
            line += sprintf(" 你的导师是：%s\n\n",GUIDER_D->is_app(ob->query("id")));
        }
	}
	else 
		line +="\n";
	return line;
}
string get_death(object ob,mapping my,string str)
{
	string line="";
	line += sprintf("\n" + str + "曾经结束过%s个生命，其中有%s个是其他玩家，%s个是宠物。\n",
		chinese_number(my["MKS"] + my["PKS"]), chinese_number(my["PKS"]), chinese_number(my["PetKills"]));
	line += sprintf( str + "共经历过%s次死亡的痛苦，其中有%s次是命丧其他玩家之手。\n",
		chinese_number(my["fhost"] + my["ghost"]), chinese_number(my["fhost"]));

	//加入死亡情况记录
	if( userp(ob) && (ob->query("last_killed"))){
		line += sprintf(str+"上一次于%s在%s死亡，死因为：%s。"NOR"\n\n",
			ob->query("last_killed/time"),
			ob->query("last_killed/place"),
			ob->query("last_killed/killer"));
	}
	else
		line +="\n";
	return line;
}
string get_shaqi(object ob)
{
	string sq;
	int shaqi = ob->query("shaqi");
    if( shaqi >= 500 ) sq=RED"过重"NOR;
	else if( shaqi >= 400 ) sq=HIR"嗜血"NOR;
	else if( shaqi >= 300 ) sq=CYN"疯狂"NOR;
	else if( shaqi >= 200 ) sq=HIY"紊乱"NOR;
	else if( shaqi >= 100 ) sq=HIC"偏高"NOR;
	else sq="正常";
	return sprintf(" 杀    气：  " HIM "%s\n" NOR, sq );
}
string get_money(object ob)
{
	string balance;
	int money = ob->query("balance"), golds=ob->query("advance_balance");
	if ( golds<=0 )
	{
		if( money > 2000000000 ) balance= "二十万两黄金";
		else if( money <= 0 ) balance= "无";
		else	balance= MONEY_D->money_str(money);
	}
	else
	{
		if( money > 2000000000 ) balance=chinese_number(golds)+"根金条二十万两黄金";
		else if( money <= 0 ) balance=chinese_number(golds)+"根金条";
		else balance=chinese_number(golds)+"根金条"+MONEY_D->money_str(money);
	}
	return sprintf(" 银行存款：  " GRN "%s\n\n" NOR, balance );
}
string get_level(object ob)
{
	return sprintf(" 等    级："+ HIY +"  %s\n"NOR,chinese_number(ob->query("level")));	  
}
string get_exp(object ob)
{
	return sprintf(" 实战经验：  " HIM "%s\n\n" NOR, show_combatexp(ob) );
}
string get_shen(object ob)
{
	string line="";
	int pot,shen=ob->query("shen");
	if ( shen < 10000 &&shen > -10000 )
	line += sprintf(" 道    德：  " RED "%14-d\t\t\t" NOR,shen);
	else if ( (shen < 100000000 && shen>0) ||(shen > -100000000 && shen < 0 ) )
	line += sprintf(" 道    德：  " RED "%.2f万\t\t\t\t" NOR,(shen*1.0)/10000 );
	else
	line += sprintf(" 道    德：  " RED "%.4f亿\t\t\t\t" NOR,(shen*1.0)/100000000 );
	pot=to_int(ob->query("potential") - (int)ob->query("learned_points"));
	if ( pot < 10000 )
	line += sprintf(" 潜    能：  " HIY "%d\n" NOR, pot );
	else if ( pot < 100000000 )
	line += sprintf(" 潜    能：  " HIY "%.2f万\n" NOR, (pot*1.0)/10000 );
	else 
	line += sprintf(" 潜    能：  " HIY "%.4f亿\n" NOR, (pot*1.0)/100000000 );
	return line;
}
string get_loyalty(object ob)
{
	int repute;
	string line="";
	if(ob->query("class") == "officer" || ob->query("class") == "eunuch")
		line += sprintf(" 贡 献 度：  " HIY "%14-d\t\t\t" NOR,  ob->query("score") );
	else
		line += sprintf(" 师门忠诚：  " HIY "%14-d\t\t\t" NOR,  ob->query("score") );
	repute=ob->query("repute");
	if ( repute < 10000 )
	  line += sprintf(" 江湖声望：  " HIY "%14-d\n\n" NOR, repute);
	else if ( repute < 100000000 )
		line += sprintf(" 江湖声望：  " HIY "%.2f万\n\n" NOR, (repute*1.0)/10000);
	else
	line += sprintf(" 江湖声望：  " HIY "%.4f亿\n\n" NOR, (repute*1.0)/100000000);
	if (SECURITY_D->get_status(ob->query("id")) == "(guider)")
	{
		line += sprintf(" 导师积分：  " HIG "%14-d\t\t\t" NOR,  GUIDER_D->guider_score(ob->query("id")) );
		//line += sprintf(" 导师属性：  " HIY "%d\n" NOR, xxx);
		line += "\n\n";
	}
	return line;
}
string display_attr(int gift, int value)
{
	if( value > gift ) return sprintf( HIY "%3d" NOR, to_int(value) );
	else if( value < gift ) return sprintf( CYN "%3d" NOR, to_int(value) );
	else return sprintf("%3d", value);
}

string status_color(int current, int max)
{
	int percent;

	if( max ) percent = current * 100 / max;
	else percent = 100;

	if( percent > 100 ) return HIC;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return HIY;
	if( percent >= 30 ) return YEL;
	if( percent >= 10 ) return HIR;
	return RED;
}

string tribar_graph(int val, int eff, int max, string color)
{
	return color + bar_string[0..(val*25/max)*2-1]
	+ ((eff > val) ? blank_string[(val*25/max)*2..(eff*25/max)*2-1] : "") + NOR;
}

string getatt(object ob)
{
	object weapon;
	string skill_type;
	int attack_points, hide_level;
	mapping prepare;

	if( objectp(weapon = ob->query_temp("weapon")) )
	{
		skill_type = weapon->query("skill_type");
	}
	else
	{
		prepare = ob->query_skill_prepare();
		if (!sizeof(prepare)) skill_type = "unarmed";
		else skill_type = keys(prepare)[0];
	}

	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	if( intp(hide_level = ob->query_temp("hide_level")) && hide_level > 0)
		return tough_level(attack_points/100, hide_level);
	return tough_level(attack_points/100, 0);
}

string getdef(object ob)
{
	object weapon;
	string skill_type;
	int attack_points, hide_level;
	mapping prepare;

	if( objectp(weapon = ob->query_temp("weapon")) )
	{
		skill_type = weapon->query("skill_type");
	}
	else
	{
		prepare = ob->query_skill_prepare();
		if (!sizeof(prepare)) skill_type = "unarmed";
		else skill_type = keys(prepare)[0];
	}

	attack_points = COMBAT_D->skill_power(ob, "parry", SKILL_USAGE_DEFENSE);
	if( intp(hide_level = ob->query_temp("hide_level")) && hide_level > 0)
		return tough_level(attack_points/100, hide_level);
	return tough_level(attack_points/100, 0);
}
string getdog(object ob)
{
	object weapon;
	string skill_type;
	int attack_points, hide_level;
	mapping prepare;

	if( objectp(weapon = ob->query_temp("weapon")) )
	{
		skill_type = weapon->query("skill_type");
	}
	else
	{
		prepare = ob->query_skill_prepare();
		if (!sizeof(prepare)) skill_type = "unarmed";
		else skill_type = keys(prepare)[0];
	}

	attack_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
	if( intp(hide_level = ob->query_temp("hide_level")) && hide_level > 0)
		return tough_level(attack_points/100, hide_level);
	return tough_level(attack_points/100, 0);
}

string *tough_level_desc = ({
	BLU"不堪一击"NOR,BLU"毫不足虑"NOR,BLU"不知所以"NOR,BLU"新学乍练"NOR,BLU"勉勉强强"NOR,
		BLU"初窥门径"NOR,BLU"初出茅庐"NOR,BLU"略知一二"NOR,BLU"普普通通"NOR,BLU"平平淡淡"NOR,

		HIB"平淡无奇"NOR,HIB"粗通皮毛"NOR,HIB"半生不熟"NOR,HIB"马马虎虎"NOR,HIB"略有小成"NOR,
		HIB"已有小成"NOR,HIB"渐入佳境"NOR,HIB"登堂入室"NOR,HIB"挥洒自如"NOR,HIB"融会贯通"NOR,

		CYN"心领神会"NOR,CYN"炉火纯青"NOR,CYN"了然於胸"NOR,CYN"略有大成"NOR,CYN"已有大成"NOR,
		CYN"豁然贯通"NOR,CYN"出类拔萃"NOR,CYN"无可匹敌"NOR,CYN"技冠群雄"NOR,CYN"神乎其技"NOR,

		HIC"出神入化"NOR,HIC"非同凡响"NOR,HIC"傲视群雄"NOR,HIC"登峰造极"NOR,HIC"无与伦比"NOR,
		HIC"所向披靡"NOR,HIC"一代宗师"NOR,HIC"精深奥妙"NOR,HIC"神功盖世"NOR,HIC"举世无双"NOR,

		HIR"惊世骇俗"NOR,HIR"撼天动地"NOR,HIR"震古铄今"NOR,HIR"超凡入圣"NOR,HIR"威镇寰宇"NOR,
		HIR"空前绝后"NOR,HIR"天人合一"NOR,HIR"深藏不露"NOR,HIR"横扫江湖"NOR,HIR"深不可测"NOR,

		HIY"威不可挡"NOR,HIY"技惊四座"NOR,HIR"强绝天下"NOR,HIY"威镇武林"NOR,HIR"前无古人"NOR,
		HIY"返璞归真"NOR,HIY"独步天下"NOR,HIY"旷古绝伦"NOR,HIY"天下无敌"NOR,HIY"天下第一"NOR,
});

string tough_level(int power, int hide_level)
{

	int lvl;
	int rawlvl;
	int grade = 1;
	if(power<0) power=0;
	rawlvl = (int) pow( (float) 1.0 * power, 0.3);
	lvl = to_int(rawlvl/grade);
	if( lvl >= sizeof(tough_level_desc) )
		lvl = sizeof(tough_level_desc)-1;
	return tough_level_desc[((int)lvl)];

}

//将经验值显示为多少甲子功力
string show_combatexp(object ob)
{
	int *factexp, jiazi, year, lp;
	string *lvcolor=({HIY, HIG, HIR, MAG, HIW}), str;
	factexp=ob->query_combatexp();
	jiazi=factexp[0]/60;
	year=factexp[0]-jiazi*60;
	if ( jiazi==0 )
		str=sprintf("%s%s年功力"NOR,
		    lvcolor[factexp[1]],chinese_number(year));
  else if ( !year )
  	str=sprintf("%s%s甲子功力"NOR,
  	    lvcolor[factexp[1]],chinese_number(jiazi));
  else
  	str=sprintf("%s%s甲子%s年功力"NOR,
  	    lvcolor[factexp[1]],chinese_number(jiazi),chinese_number(year));
  
  for ( lp=0;lp<5;lp++ )
  {
  	if ( lp < factexp[1] )
  	  str+=lvcolor[lp]+"■"NOR;
  	else
  		str+=lvcolor[lp]+"□"NOR;
  }
  
  str+="\n"+lvcolor[factexp[1]];
  for ( lp=0;lp<40;lp++ )
  {
  	if ( lp < factexp[2]*40/factexp[3] )
  		str+="■";
  	else if ( lp == factexp[2]*40/factexp[3] &&
  		  (factexp[2]*40%factexp[3])*100/factexp[3]>=50 )
  	  str+="■";
  	else
  		str+=YEL"□";
  }
  str+=HIW+sprintf("(%.2f%%)"NOR, (factexp[2]*100.0)/factexp[3]);
  return str;
}

int help(object me)
{
	write(@HELP
指令格式 : score [-xiantian]
score <对象名称>                   (巫师专用)

这个指令可以显示你(你)或指定对象(含怪物)的基本资料。
加"-xiantian"参数显示先天天赋，不加显示后天天赋。
基本资料的设定请参阅 'help setup'。

命令中经验显示前面为以甲子和年来衡量的等级，1甲子=60年。甲子后面的五个不同颜色
小格表示一年中的五个阶段，下一行的40个小格每满一次会增加上面五个小格中一格，五
小格满的时候功力增加一年。

score命令增加个性化设置，set custom_sc，具体意义如下：
-T 显示头衔
-A 显示年龄信息
-G 显示天赋情况
-F 显示门派信息
-D 显示死亡记录
-S 显示杀气
-B 显示存款信息
-L 显示级别信息
-E 显示经验信息
-SH 显示道德和潜能
-LO 显示门忠和声望
以上参数可按意愿自由组合，如不设定则默认为全部显示score信息。
see also : hp
HELP
	   );
	return 1;
}

