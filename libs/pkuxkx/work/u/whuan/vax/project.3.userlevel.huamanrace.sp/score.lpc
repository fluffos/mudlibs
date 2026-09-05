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

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
	object ob;
      	int kill,win,highestexp,highestpotential,highestlevel;
	mapping my,prepare;
	string line, str, skill_type, temp;
	object weapon;
	int attack_points, dodge_points, parry_points;

       string marry_type,lover_sex,lover_title,lover_id;
	string my_yinyang, effect;
	float yinyang_factor;

	if(!arg)
		ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
                if (!ob|| !me->visible(ob)) return notify_fail("你要察看谁的状态？\n");
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
        line = sprintf(HIG"≡━◎个人档案◎━━━━━━━━━━━━━━━━━━━━━━━━≡\n\n"NOR);
	line += sprintf( BOLD "%s" NOR "%-s" + "\n\n", RANK_D->query_rank(ob), ob->short(1) );
	line += str;
	line += sprintf("是一%s%s岁的%s%s%s，%s生。\n\n",
		ob->query("unit"),
		chinese_number(ob->query("age")),
                marry_type,
		ob->query("gender"),
		((string)ob->query("race")=="人类")? ob->query("nation"):ob->query("race"),
		CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) ) );
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

		line += sprintf(
			" 膂力：[%s]  悟性：[%s]  根骨：[%s]  身法：[%s]\n",
			display_attr(my["str"], ob->query_str()),
			display_attr(my["int"], ob->query_int()),
			display_attr(my["con"], ob->query_con()),
			display_attr(my["dex"], ob->query_dex()));

	temp = sprintf(
                        " 福缘：[%s]  容貌：[%s]  灵性：[%s]  \n",
			display_attr(my["kar"], ob->query_kar()),
			display_attr(my["per"], ob->query_per()),
			display_attr(my["spi"], ob->query("spi") + 30),
			);
	if(wizardp(me)|| me->query("age") > 17)
	line += temp;

	if(userp(ob))
	{
		if( mapp(my["family"]) )
		{
			 if(my["family"]["generation"]>1 && ob->query("class") != "officer")
			 line += "\n" + str + "是"+my["family"]["family_name"]+"第"+chinese_number(my["family"]["generation"])+"代弟子，";
			 else if(ob->query("class") == "officer")
			 line += "\n" + str + "是" + my["family"]["family_name"] + chinese_number(ob->query("pin"))+"品官员，\n";
			if( my["family"]["master_name"] )
				line = sprintf("%s" + str + "的师父是%s。\n",
					line, my["family"]["master_name"] );
		}
		 if(ob->query("betrayer")) line += sprintf(str + "曾经背叛过%s次师门。\n", chinese_number(ob->query("betrayer")));
	}
	// yinyang show -- dewolf 2005.11.25 both npc && player
	my_yinyang = YINYANG_D->query_yinyang_color(YINYANG_D->query_yinyang(ob));
	if (my_yinyang != "没有")
	{
		yinyang_factor = YINYANG_D->yinyang_factor(ob);
		if (yinyang_factor >= 0.6)
			effect = HIG"共鸣"NOR;
		else if (yinyang_factor >= 0.4)
			effect = HIW"强化"NOR;
		else if (yinyang_factor >= 0.2)
			effect = CYN"支持"NOR;
		else if (yinyang_factor >= -0.1)
			effect = "正常";
		else if (yinyang_factor >= -0.2)
			effect = YEL"阻滞"NOR;
		else if (yinyang_factor >= -0.4)
			effect = RED"冲突"NOR;
		else if (yinyang_factor >= -0.6)
			effect = MAG"排斥"NOR;
		else
			effect = "未知";
		if (wizardp(me))
			effect += "(" + (string)yinyang_factor + ")";
		line += str + "目前的内功种类是：『" + my_yinyang + "』，天地因素对战斗力的影响是：" + effect + "\n\n";
	}
	line += " <精>  " + tribar_graph(my["jing"], my["eff_jing"], my["max_jing"], GRN) + "\n";
	line += " <气>  " + tribar_graph(my["qi"], my["eff_qi"], my["max_qi"], HIR) + "\n";

	prepare = ob->query_skill_prepare();
	if (!mapp(prepare)) prepare = ([]);
	if( objectp(weapon = ob->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else if (!sizeof(prepare))	skill_type = "unarmed";
	else if ( sizeof(prepare))	skill_type = (keys(prepare))[0];
	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, "parry", SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);

	line += sprintf("\n 攻击 " HIW "%s (+%d)" NOR "\t躲闪 " HIW "%s " NOR "\t招架 " HIW "%s (+%d)\n\n" NOR,
		getatt(ob),ob->query_temp("apply/damage"),
		getdog(ob),
		getdef(ob),ob->query_temp("apply/armor"));

        if (wizardp(me))
	line += sprintf(" 攻击 " HIW "%d (+%d)" NOR "\t躲闪 " HIW "%d " NOR "\t招架 " HIW "%d (+%d) \n\n" NOR,
		attack_points,ob->query_temp("apply/damage"),
		dodge_points,
		parry_points,ob->query_temp("apply/armor"));

	line += " 食物：" + tribar_graph(my["food"], ob->max_food_capacity(), ob->max_food_capacity(), YEL) + "\n";
	line += " 饮水：" + tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(), CYN) + "\n";

	line += sprintf("\n" + str + "曾经结束过%s个生命，其中有%s个是其他玩家。\n",
		chinese_number(my["MKS"] + my["PKS"]), chinese_number(my["PKS"]));
	line += sprintf("\n" + str + "共经历过%s次死亡的痛苦，其中有%s次是命丧其他玩家之手。\n\n",
		chinese_number(my["fhost"] + my["ghost"]), chinese_number(my["fhost"]));

        line += sprintf(" 杀    气：  " HIM "%s\n" NOR, get_shaqi(ob) );
        line += sprintf(" 银行存款：  " GRN "%s\n\n" NOR, get_money(ob) );

          line += sprintf(" 道    德：  " RED "%d\n" NOR,ob->query("shen"));
        line += sprintf(" 潜    能：  " HIY "%s\n" NOR,
                chinese_number((int)ob->query("potential") - (int)ob->query("learned_points")) );
         line += sprintf(" 实战经验：  " HIM "%d\n\n" NOR, ob->query("combat_exp") );
        if(ob->query("class") == "officer")
        line += sprintf(" 贡 献 度：  " GRN "%s\n" NOR, chinese_number(ob->query("score")) );
        else
        line += sprintf(" 师门忠诚：  " GRN "%s\n" NOR, chinese_number(ob->query("score")) );
         line += sprintf(" 江湖声望：  " HIY "%d\n\n" NOR, ob->query("repute"));
	line += sprintf(HIG"≡━━━━━━━━━━━━━━━━━━━━━━◎北大侠客行◎━━≡\n"NOR);
	write(line);
	return 1;
}

string get_shaqi(object ob)
{
	int shaqi = ob->query("shaqi");
	if( shaqi >= 400 ) return HIR"嗜血"NOR;
	if( shaqi >= 300 ) return CYN"疯狂"NOR;
	if( shaqi >= 200 ) return HIY"紊乱"NOR;
	if( shaqi >= 100 ) return HIC"偏高"NOR;
	if( shaqi >= 0 ) return "正常";
}

string get_money(object ob)
{
	int money = ob->query("balance");
	if( money > 2000000000 ) return "二十万两黄金";
	if( money <= 0 ) return "无";
	return MONEY_D->money_str(money);
}

string display_attr(int gift, int value)
{
	if( value > gift ) return sprintf( HIY "%3d" NOR, value );
	else if( value < gift ) return sprintf( CYN "%3d" NOR, value );
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
               return tough_level(attack_points, hide_level);
        return tough_level(attack_points, 0);
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
               return tough_level(attack_points, hide_level);
        return tough_level(attack_points, 0);
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
               return tough_level(attack_points, hide_level);
        return tough_level(attack_points, 0);
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
	rawlvl = (int) pow( (float) power/6.0 , 0.5);
	lvl = to_int(rawlvl/grade);
                        if( lvl >= sizeof(tough_level_desc) )
                                lvl = sizeof(tough_level_desc)-1;
                        return tough_level_desc[((int)lvl)];

}

int help(object me)
{
	write(@HELP
指令格式 : score
           score <对象名称>                   (巫师专用)

这个指令可以显示你(你)或指定对象(含怪物)的基本资料。
基本资料的设定请参阅 'help setup'。

see also : hp
HELP
    );
    return 1;
}
