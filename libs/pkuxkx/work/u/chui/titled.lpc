// rankd.c
// 1996-02-15 dts ranking related to "shen"

#include <ansi.h>

string query_rank(object ob)
{
	mapping fam;
	string str;
	string gender,myclass;

	int shen;
	int budd;
        if( stringp(str = ob->query("rank_info/rank")) )
                return str;

	if( ob->is_ghost() ) 
		return HIB "【 鬼  魂 】" NOR;

	if ( (fam = ob->query("family")) && fam["family_name"] == "少林派" ) 
		budd = ob->query_skill("buddhism",1);
	if ( ob->query_temp("apply/name") )
	{
		shen = ob->query_temp("apply/shen");
		gender = ob->query_temp("apply/gender")[0];
		myclass = ob->query_temp("apply/class");
	}
	else
	{
		shen = ob->query("shen");
		gender = ob->query("gender");
		myclass = ob->query("class");
	}
	switch(gender) {
	case "女性":
		switch(wizhood(ob)) {
		case "(admin)":		
			return HIW "【 天  神 】" NOR;
		case "(arch)":		
                        return HIY "【 女  神 】" NOR;
		case "(wizard)":	
			return HIG "【 大仙女 】" NOR;
		case "(apprentice)":	
			return HIC "【 仙  女 】" NOR;
		case "(immortal)":	
			return HIC "【 小仙女 】" NOR;
		default:
//			if( ((int)ob->query("PKS") > 100) &&
//				((int)ob->query("PKS") > (int)ob->query("MKS")) )
//				return "【 杀人魔 】";
//			if( (int)ob->query("thief") > 10 ) 
//				return "【 惯  窃 】";
			if (shen >= 100000)
				return HIC "【旷世侠女】" NOR;
			else if (shen >= 10000)
				return HIC "【 大侠女 】" NOR;
			else if (shen >= 1000)
				return HIC "【 侠  女 】" NOR;
			else if (shen >= 100)
				return HIC "【 小侠女 】" NOR;
			else if (shen <= -100000)
				return HIC "【 女魔王 】" NOR;
			else if (shen <= -10000)
				return HIC "【 大魔女 】" NOR;
			else if (shen <= -1000)
				return HIC "【 魔  女 】" NOR;
			else if (shen <= -100)
				return HIC "【 小魔女 】" NOR;
			else
			switch(myclass) {
			case "bonze":	
				return "【 尼  姑 】";
			case "taoist":	
				return "【 女  冠 】";
			case "bandit":	
				return "【 女飞贼 】";
			case "dancer":	
				return "【 舞  妓 】";
			case "scholar":	
				return "【 才  女 】";
			case "officer":	
				return "【 女  官 】";
			case "fighter":	
				return "【 女武者 】";
			case "swordsman":	
				return "【 女剑士 】";
			case "alchemist":	
				return "【 方  士 】";
			case "shaman":		
				return "【 巫  医 】";
			case "beggar":		
				return "【 叫化子 】";
			default:			
				return "【 民  女 】";
			}
		}
	default:
		switch(wizhood(ob)) {
		case "(admin)":			
			return HIW "【 天  神 】" NOR;
		case "(arch)":			
			return HIY "【 大  神 】" NOR;
		case "(wizard)":		
			return HIG "【 神  仙 】" NOR;
		case "(apprentice)":		
			return HIC "【 仙  人 】" NOR;
		case "(immortal)":		
			return HIC "【 散  仙 】" NOR;
		default:
			if (shen >= 100000)
				return HIC "【旷世大侠】" NOR;
			else if (shen >= 10000)
				return HIC "【 大  侠 】" NOR;
			else if (shen >= 1000)
				return HIC "【 侠  客 】" NOR;
			else if (shen >= 100)
				return HIC "【 少  侠 】" NOR;
			else if (shen <= -100000)
				return HIC "【 魔  王 】" NOR;
			else if (shen <= -10000)
				return HIC "【 大魔头 】" NOR;
			else if (shen <= -1000)
				return HIC "【 魔  头 】" NOR;
			else if (shen <= -100)
				return HIC "【 小  妖 】" NOR;
			else
				switch(myclass) {
				case "bonze":		
					if (budd >= 150)
						return HIY "【 长  老 】" NOR;
					else if (budd >= 120)
						return HIY "【 圣  僧 】" NOR;
					else if (budd >= 90)
						return HIY "【 罗  汉 】" NOR;
					else if (budd >= 60)
						return HIY "【 尊  者 】" NOR;
					else if (budd >= 40)
						return HIY "【 禅  师 】" NOR;
					else if (budd >= 30)
						return HIY "【 比  丘 】" NOR;
					else
						return "【 僧  人 】";
				case "taoist":		
					return "【 道  士 】";
				case "bandit":		
					return "【 盗  贼 】";
				case "scholar":		
					return "【 书  生 】";
				case "officer":		
					return "【 官  差 】";
				case "fighter":		
					return "【 武  者 】";
				case "swordsman":	
					return "【 剑  士 】";
				case "alchemist":	
					return "【 方  士 】";
				case "shaman":		
					return "【 巫  医 】";
				case "beggar":		
					return "【 叫化子 】";
				default:		
					return "【 平  民 】";
				}
		}
	}
}

string query_respect(object ob)
{
	int age;
	string str,gender,myclass,shen;

	if( stringp(str = ob->query("rank_info/respect")) )
		return str;

	if ( ob->query_temp("apply/name") )
	{
		shen = ob->query_temp("apply/shen");
		gender = ob->query_temp("apply/gender")[0];
		myclass = ob->query_temp("apply/class");
		age = ob->query_temp("apply/age")[0];
	}
	else
	{
		shen = ob->query("shen");
		gender = ob->query("gender");
		myclass = ob->query("class");
		age = ob->query("age");
	}
	switch(gender) {
		case "女性":
			switch(myclass) {
			case "bonze":
				if( age < 18 ) return "小师太";
				else return "师太";
				break;
			case "taoist":
				if( age < 18 ) return "小仙姑";
				else return "仙姑";
				break;
			default:
				if( age < 18 ) return "小姑娘";
				else if( age < 50 ) return "姑娘";
				else return "婆婆";
				break;
			}
		case "男性":
		default:
			switch(myclass) {
			case "bonze":
				if( age < 18 ) return "小师父";
				else return "大师";
				break;
			case "taoist":
				if( age < 18 ) return "道兄";
				else return "道长";
				break;
			case "fighter":
			case "swordsman":
				if( age < 18 ) return "小老弟";
				else if( age < 50 ) return "壮士";
				else return "老前辈";
				break;
			default:
				if( age < 20 ) return "小兄弟";
				else if( age < 50 ) return "壮士";
				else return "老爷子";
				break;
			}
	}
}

string query_rude(object ob)
{
	int age;
	string str,gender,myclass,shen;

	if( stringp(str = ob->query("rank_info/respect")) )
		return str;

	if ( ob->query_temp("apply/name") )
	{
		shen = ob->query_temp("apply/shen");
		gender = ob->query_temp("apply/gender")[0];
		myclass = ob->query_temp("apply/class");
		age = ob->query_temp("apply/age")[0];
	}
	else
	{
		shen = ob->query("shen");
		gender = ob->query("gender");
		myclass = ob->query("class");
		age = ob->query("age");
	}
	switch(gender) {
		case "女性":
			switch(myclass) {
			case "bonze":
				return "贼尼";
				break;
			case "taoist":
				return "妖女";
				break;
			default:
				if( age < 30 ) return "小贱人";
				else return "死老太婆";
				break;
			}
		case "男性":
		default:
			switch(myclass) {
			case "bonze":
				if( age < 50 ) return "死秃驴";
				else return "老秃驴";
				break;
			case "taoist":
				return "死牛鼻子";
				break;
			default:
				if( age < 20 ) return "小王八蛋";
				if( age < 50 ) return "臭贼";
				else return "老匹夫";
				break;
			}
	}
}

string query_self(object ob)
{
	int age;
	string str,gender,myclass,shen;

	if( stringp(str = ob->query("rank_info/respect")) )
		return str;

	if ( ob->query_temp("apply/name") )
	{
		shen = ob->query_temp("apply/shen");
		gender = ob->query_temp("apply/gender")[0];
		myclass = ob->query_temp("apply/class");
		age = ob->query_temp("apply/age")[0];
	}
	else
	{
		shen = ob->query("shen");
		gender = ob->query("gender");
		myclass = ob->query("class");
		age = ob->query("age");
	}
	switch(gender) {
		case "女性":
			switch(myclass) {
			case "bonze":
				if( age < 50 ) return "贫尼";
				else return "老尼";
				break;
			default:
				if( age < 30 ) return "小女子";
				else return "妾身";
				break;
			}
		case "男性":
		default:
			switch(myclass) {
			case "bonze":
				if( age < 50 ) return "贫僧";
				else return "老纳";
				break;
			case "taoist":
				return "贫道";
				break;
			default:
				if( age < 50 ) return "在下";
				else return "老头子";
				break;
			}
	}
}

string query_self_rude(object ob)
{
	int age;
	string str,gender,myclass,shen;

	if( stringp(str = ob->query("rank_info/respect")) )
		return str;

	if ( ob->query_temp("apply/name") )
	{
		shen = ob->query_temp("apply/shen");
		gender = ob->query_temp("apply/gender")[0];
		myclass = ob->query_temp("apply/class");
		age = ob->query_temp("apply/age")[0];
	}
	else
	{
		shen = ob->query("shen");
		gender = ob->query("gender");
		myclass = ob->query("class");
		age = ob->query("age");
	}
	switch(gender) {
		case "女性":
			switch(myclass) {
			case "bonze":
				if( age < 50 ) return "贫尼";
				else return "老尼";
				break;
			default:
				if( age < 30 ) return "本姑娘";
				else return "老娘";
				break;
			}
		case "男性":
		default:
			switch(myclass) {
			case "bonze":
				if( age < 50 ) return "大和尚我";
				else return "老和尚我";
				break;
			case "taoist":
				return "本山人";
				break;
			default:
				if( age < 50 ) return "大爷我";
				else return "老子";
				break;
			}
	}
}
string query_close(object ob)
{
        int a1, a2;
	int age,mud_age;
	string gender;

	if ( ob->query_temp("apply/name") )
	{
		age = ob->query_temp("apply/age")[0];
		mud_age = ob->query_temp("apply/mud_age");
	}
	else
	{
		age = ob->query("age");
		mud_age = ob->query("mud_age");
	}

	if (objectp(ob))
	{
        	if (a2 = (int)mud_age)
        	{
        		if (this_player()->query_temp("apply/name"))
        		{
        			a1= this_player()->query_temp("apply/mud_age");
        			gender = this_player()->query_temp("apply/gender")[0];
        		}
        		else
        		{
        			a1 = this_player()->query("mud_age");
        			gender = this_player()->query("gender");
        		}
       		} else 
       		{ 	
	       	 	a1 = this_player()->query("age");
			a2 = ob->query("age");
		}
	} else 
	{	
	 	a1 = this_player()->query("age");
	 	a2 = 0;
	}
							
        switch (gender) {
        case "女性" :
                if (a1 >= a2)
                        return "妹妹";
                else
                        return "姐姐";
                break;
        default :
                if (a1 >= a2)
                        return "弟弟";
                else
                        return "哥哥";
        }
}

string query_self_close(object ob)
{
        int a1, a2;
	int age,mud_age;
	string gender;

	if ( ob->query_temp("apply/name") )
	{
		age = ob->query_temp("apply/age")[0];
		mud_age = ob->query_temp("apply/mud_age");
	}
	else
	{
		age = ob->query("age");
		mud_age = ob->query("mud_age");
	}

	if (objectp(ob))
	{
        	if (a2 = (int)mud_age)
        	{
        		if (this_player()->query_temp("apply/name"))
        		{
        			a1= this_player()->query_temp("apply/mud_age");
        			gender = this_player()->query_temp("apply/gender")[0];
        		}
        		else
        		{
        			a1 = this_player()->query("mud_age");
        			gender = this_player()->query("gender");
        		}
       		} else 
       		{ 	
	       	 	a1 = this_player()->query("age");
			a2 = ob->query("age");
		}
	} else 
	{	
	 	a1 = this_player()->query("age");
	 	a2 = 0;
	}
		
        switch (gender) {
        case "女性" :
                if (a1 >= a2)
                        return "姐姐我";
                else
                        return "小妹我";
                break;
        default :
                if (a1 >= a2)
                        return "愚兄我";
                else
                        return "小弟我";
	}
}

