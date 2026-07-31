// rankd.c 
// 1996-02-15 dts ranking related to "shen"
//modified by macrohard@sdyx
#pragma save_binary
#include <tomud.h>
#include <ansi.h> 
string query_rank(object ob)
{
	mapping fam;
	int shen,exp;
	int budd;
	string set_title,menpai;
	
	exp = (int)ob->query("level");
	menpai=ob->query("family/family_name");
	shen = ob->query("shen");
	if(wizardp(ob)&&ob->query("env/own_rank"))
	       return NOR"【"HIW+ob->query("env/own_rank")+NOR" 】"; 
	if( ob->is_ghost() ) 
		return NOR "【"HIB"孤魂野鬼"NOR"】";


	if ( (fam = ob->query("family")) && fam["family_name"] == "少林派" ) 
		budd = ob->query_skill("buddhism",1);
	
	if( (int) ob->query("fight_rank") == 1 )
	{
		if( strlen((string) ob->query("env/my_title")) ==2)
		     {
			  set_title = ob->query("env/my_title");
			  return NOR"【"HIW"天下第一"+set_title+NOR" 】";
		      }
		else 
			  return NOR"【"HIW"天下第一"NOR"】";
	}
	if( (int) ob->query("fight_rank") == 2 )
	{
		if( strlen((string) ob->query("env/my_title")) ==2)
		     {
			  set_title = ob->query("env/my_title");
			  return NOR"【"HIR"天下第二"+set_title+NOR" 】";
		      }
		else 
			  return NOR"【"HIR"天下第二"NOR"】";
	}
	if( (int) ob->query("fight_rank") == 3)
	{
		if( strlen((string) ob->query("env/my_title")) ==2)
		     {
			  set_title = ob->query("env/title_race");
			  return NOR"【"HIG"天下第三"+ set_title +NOR" 】";
		     }
		else 
			  return NOR"【"HIG"天下第三"NOR"】";
	}
	
	switch(ob->query("gender")) {
	case "女性":
		switch(wizhood(ob)) {
		case "(admin)": 
			return NOR "【"HIW"世界创造者"NOR"】";       
		case "(wizard)":	
			return NOR "【"HIC"世界缔造者"NOR"】";
		case "(immortal)":      
			return NOR "【"CYN"世界管理员"NOR"】";
		default:
			if( ((int)ob->query("PKS") > 30) )
				return  "【"HIB"饮血女魔"NOR"】";    
			else if (shen >= 1000000)
				return  "【"HIC"一代天娇"NOR"】";
			else if (shen >= 500000)
				return  "【"HIM"旷世女侠"NOR"】";
			else if (shen >= 100000)
				return  "【"HIY"巾帼英雄"NOR"】";
			else if (shen >= 50000)
				return  "【"YEL"女中豪杰"NOR"】";
			else if (shen >= 10000)
				return  "【"HIC"女 少 侠"NOR"】";
			else if (shen >= 5000)
				return  "【"HIG"风尘侠女"NOR"】";
			else if (shen <= -1000000)
				return  "【"HIW"嗜血女魔"NOR"】";
			else if (shen <= -500000)
				return  "【"HIR"旷世魔女"NOR"】";
			else if (shen <= -100000)
				return  "【"HIM"饮血魔女"NOR"】";
			else if (shen <= -50000)
				return  "【"GRN"塞外妖女"NOR"】";
			else if (shen <= -10000)
				return  "【"RED"女 少 魔"NOR"】" ;
			else if (shen <= -5000)
				return  "【"CYN"刁蛮恶女"NOR"】" ;
			else if( (int)ob->query("thief") > 10 ) 
				return  "【"HIW"女 惯 窃"NOR"】";    
			else
			switch(menpai) {
					case "武当派":
						if (exp>99){
							if (shen >= 0)
								return NOR "【"HIR"女 天 师"NOR"】";
							else
								return NOR "【"HIR"女魔天师"NOR"】";
							}

						if (exp>79)
								return NOR "【"RED"女 国 师"NOR"】";
						if (exp>59)
								return NOR "【"GRN"女 真 人"NOR"】";
						if (exp>49)
								return NOR "【"YEL"女大法师"NOR"】";
						if (exp>39)
								return NOR "【"GRN"女 法 师"NOR"】";
						if (exp>29)
								return NOR "【"CYN"女 道 长"NOR"】";
						if (exp>24)
								return NOR "【"MAG"女 道 姑"NOR"】";
						if (exp>19)
								return NOR "【"HIB"女 道 姑"NOR"】";
						if (exp>9)
								return NOR "【"HIB" 女  冠 "NOR"】";
						return "【女 少 冠】";
					case "华山派":
						if (exp>99) {
							if (shen >= 0 )
								return NOR "【"HIW"惊天一剑"NOR"】";
							else
								return NOR "【"HIW"惊魔一剑"NOR"】";
							}
						if (exp>59) {
							if (shen >= 0)
								return NOR "【"HIR"女 剑 圣"NOR"】";
							else
								return NOR "【"HIM"女 剑 魔"NOR"】";
							}	
						if (exp>59) {
							if (shen >= 0)
								return NOR "【"GRN"女 剑 仙"NOR"】";
							else
								return NOR "【"GRN"女 邪 剑"NOR"】";
							}
						if (exp>49)
								return NOR "【"YEL"女 剑 痴"NOR"】";
						if (exp>39)
								return NOR "【"CYN"女 剑 侠"NOR"】";
						if (exp>29)
								return NOR "【"CYN"女大剑客"NOR"】";
						if (exp>24)
								return NOR "【"RED"女 剑 客"NOR"】";
						if (exp>19)
								return NOR "【"MAG"女大剑士"NOR"】";
						if (exp>9)
								return NOR "【"MAG" 剑  士 "NOR"】";
						return "【女 剑 童】";

					case "丐帮":
						if (exp>99)
								return NOR "【"HIR"女副帮主"NOR"】" NOR;
						if (exp>79)
								return NOR "【"HIM"女大长老"NOR"】" NOR;
						if (exp>59)
								return NOR "【"HIM"女 长 老"NOR"】" NOR;
						if (exp>49)
								return NOR "【"YEL"女传功使"NOR"】" NOR;
						if (exp>39)
								return NOR "【"YEL"女执法使"NOR"】" NOR;
						if (exp>29)
								return NOR "【"RED"女 神 丐"NOR"】" NOR;
						if (exp>24)
								return NOR "【"RED"女小神丐"NOR"】" NOR;
						if (exp>14)
								return HIW "【"GRN"女 乞 丐"NOR"】" NOR;
						if (exp>9)
								return NOR "【"MAG"女小乞丐"NOR"】" NOR;
						return "【 叫 化 子 】" ;

					case "星宿派":
					case "桃花岛":
						if (exp>99) {
							if (shen >= 0)
								return NOR "【"HIR"魔 见 愁"NOR"】";
							else
								return NOR "【"HIR" 狂  魔 "NOR"】";
							}	
						if (exp>79)
								return NOR "【"HIM"隐世侠女"NOR"】";
						if (exp>59)
								return NOR "【"GRN"旷世女侠"NOR"】";
						if (exp>49)
								return NOR "【"YEL"大 侠 女"NOR"】";
						if (exp>39)
								return NOR "【"RED"女 侠 客"NOR"】";
						if (exp>29)
								return NOR "【"MAG"女 游 侠"NOR"】";
						if (exp>24)
								return NOR "【"MAG" 女  侠 "NOR"】";
						if (exp>14)
								return NOR "【"CYN" 女  侠 "NOR"】";
						if (exp>9)
								return NOR "【"CYN"小 女 侠"NOR"】";
						return "【风尘女子】"NOR ;

					case "明教":
						if (exp>99)
								return NOR "【"HIR"女副教主"NOR"】";
						if (exp>79)
								return NOR "【"HIM" 法  王 "NOR"】";
						if (exp>59)
								return NOR "【"GRN"女总护法"NOR"】";
						if (exp>49)
								return NOR "【"YEL"女 护 法"NOR"】";
						if (exp>39)
								return NOR "【"YEL"女总堂主"NOR"】";
						if (exp>29)
								return NOR "【"CYN"女副堂主"NOR"】";
						if (exp>24)
								return NOR "【"CYN"女 旗 主"NOR"】";
						if (exp>19)
								return NOR "【"MAG"女副旗主"NOR"】";
						if (exp>9)
								return NOR "【"MAG"女 教 众"NOR"】";
						return "【  教  众  】" ;
				      default:
			switch(ob->query("class")) {
			case "bonze":   
				return "【 女  尼 】";
			case "yishi":   
				return "【女 义 士】";
			case "taoist":  
				return "【 女  冠 】";			       
			case "bandit":  
				return "【女 飞 贼】";
		       case "dancer":  
				return "【绝色舞姬】";				 
			case "scholar": 
				return "【遥遥佳人】";		  
			case "officer": 
				return "【 女  差 】";
			case "fighter": 
				return "【风尘女子】";		    
			case "swordsman":       
				return "【舞剑少女】";		    
			case "alchemist":       
				return "【女 方 士】";		   
			case "shaman":  
				return "【女 巫 医】";
			case "beggar":  
				return "【女叫花子】";      
			case "shiny":
       case "huanu":       return "【移花宫花奴】"; 
       case "yihuashinv":     return "【移花宫侍女】"; 
       case "chuanren":      return "【移花宫传人】"; 
				return "【光明女使】";
			default:			
				return "【芊芊民女】";	      
			}
		}}
	default:
 switch(wizhood(ob)) {
		case "(admin)":		 
			return NOR "【"HIR"世界创造者"NOR"】" ;
		case "(wizard)":		
			return NOR "【"HIC"世界缔造者"NOR"】" ;
		case "(immortal)":	      
			return NOR "【"HIB"世界管理员"NOR"】" ;
		default:
			if( ((int)ob->query("PKS") > 50) )
				return "【杀人魔王】";
			else if (shen >= 1000000)
				return  "【"HIG"武林泰斗"NOR"】" ;
			else if (shen >= 500000)
				return HIC "【"HIC"旷世大侠"NOR"】" ;
			else if (shen >= 100000)
				return HIC "【"HIC"名满天下"NOR"】" ;
			else if (shen >= 50000)
				return  "【"HIY"名动一时"NOR"】";
			else if (shen >= 10000)
				return  "【"HIY"江湖豪杰"NOR"】";
			else if (shen >= 5000)
				return  "【"HIG"武林新秀"NOR"】";
			else if (shen >= 1000)
				return  "【"HIG"小有名声"NOR"】";	
			else if (shen >= 500)
				return NOR"【"CYN"小有侠义"NOR"】";
			else if (shen <= -1000000)
				return "【"HIW"江湖老怪"NOR"】" ;
			else if (shen <= -500000)
				return "【"HIR"旷世魔头"NOR"】";
			else if (shen <= -100000)
				return "【"RED"恶霸一方"NOR"】";
			else if (shen <= -50000)
				return "【"YEL"恶名远扬"NOR"】";
			else if (shen <= -10000)
				return "【"YEL"小有恶名"NOR"】";	
			else if (shen <= -500)
				return "【"HIB"走上邪道"NOR"】";
			else if( (int)ob->query("thief") > 10 ) 
				return NOR"【"YEL" 神  偷 "NOR"】";
			else
			       switch(menpai) {
					case "武当派":
						if (exp>99){
							if (shen >= 0 )
								return NOR "【"HIR" 天  师 "NOR"】";
							else
								return NOR "【"HIW"恶 天 师"NOR"】";
							}
						if (exp>79)
								return NOR "【"HIM" 国  师 "NOR"】";
						if (exp>59)
								return NOR "【"GRN" 真  人 "NOR"】";
						if (exp>49)
								return NOR "【"YEL"大 法 师"NOR"】";
						if (exp>39)
								return NOR "【"YEL" 法  师 "NOR"】";
						if (exp>29)
								return NOR "【"CYN" 道  长 "NOR"】";
						if (exp>24)
								return NOR "【"CYN" 道  士 "NOR"】";
						if (exp>19)
								return NOR "【"HIB" 道  士 "NOR"】";
						if (exp>9)
								return NOR "【"HIB"大 道 童"NOR"】";
						return "【 道  童 】" ;	

					case "华山派":
						if (exp>99) {
							if (shen >= 0 )
								return NOR "【"HIW"惊天一剑"NOR"】";
							else
								return NOR "【"HIW"惊魔一剑"NOR"】";
							}
						if (exp>79) {
							if (shen >= 0)
								return NOR "【 "HIR"剑  圣"NOR" 】";
							else
								return NOR "【 "HIM"剑  魔"NOR" 】";
							}	
						if (exp>59) {
							if (shen >= 0)
								return NOR "【 "GRN"剑  仙"NOR" 】";
							else
								return NOR "【 "GRN"邪  剑"NOR" 】";
							}
						if (exp>49)
								return NOR "【 "YEL"剑  痴"NOR" 】";
						if (exp>39)
								return NOR "【 "CYN"剑  侠"NOR" 】";
						if (exp>29)
								return NOR "【"CYN"大 剑 客"NOR"】";
						if (exp>24)
								return NOR "【 "RED"剑  客"NOR" 】";
						if (exp>19)
								return NOR "【"MAG"大 剑 士"NOR"】";
						if (exp>9)
								return NOR "【"MAG" 剑  士 "NOR"】";
						return "【 剑  童 】";

					case "丐帮":
						if (exp>99)
								return NOR "【"HIR"副 帮 主"NOR"】";
						if (exp>79)
								return NOR "【"HIW"十袋长老"NOR"】";
						if (exp>59)
								return NOR "【"HIM"九袋长老"NOR"】";
						if (exp>49)
								return NOR "【"YEL"传功长老"NOR"】";
						if (exp>39)
								return NOR "【"YEL"执法长老"NOR"】";
						if (exp>29)
								return NOR "【"RED" 神  丐 "NOR"】";
						if (exp>24)
								return NOR "【"CYN"小 神 丐"NOR"】";
						if (exp>19)
								return NOR"【"CYN"  乞  丐 "NOR"】";
						if (exp>9)
								return NOR "【"HIB"小 乞 丐"NOR"】";
						return "【叫 化 子】"NOR ;

					case "星宿派":
					case "桃花岛":
						if (exp>99) {
							if (shen >= 0)
								return NOR "【"HIR"魔 见 愁"NOR"】";
							else
								return NOR "【"HIR" 狂  魔 "NOR"】";
							}	
						if (exp>79)
								return NOR "【"CYN"世外高人"NOR"】";
						if (exp>59)
								return NOR "【"GRN"旷世奇侠"NOR"】";
						if (exp>49)
								return NOR "【"YEL"大 豪 侠"NOR"】";
						if (exp>39)
								return NOR "【"YEL" 豪  侠 "NOR"】";
						if (exp>29)
								return NOR "【"GRN" 大  侠 "NOR"】";
						if (exp>24)
								return NOR "【"GRN" 侠  士 "NOR"】";
						if (exp>19)
								return NOR "【"CYN" 游  侠 "NOR"】";
						if (exp>9)
								return NOR "【"HIC" 少  侠 "NOR"】";
						return "【武林人物】"NOR ;

					case "明教":
						if (exp>99)
								return NOR "【"HIR"副 教 主"NOR"】";
						if (exp>79)
								return NOR "【"HIM" 法  王 "NOR"】";
						if (exp>59)
								return NOR "【"GRN"总 护 法"NOR"】";
						if (exp>49)
								return NOR "【"YEL" 护  法 "NOR"】";
						if (exp>39)
								return NOR "【"YEL"总 堂 主"NOR"】";
						if (exp>29)
								return NOR "【"CYN"副 堂 主"NOR"】";
						if (exp>24)
								return NOR "【"CYN" 旗  主 "NOR"】";
						if (exp>19)
								return NOR "【"GRN"副 旗 主"NOR"】";
						if (exp>9)
								return NOR "【"HIB" 教  众 "NOR"】";
						return "【 教  众 】" ;

					default:
				switch(ob->query("class")) {
				case "bonze":	   
					if (budd >= 150)
						return  "【"HIY" 长  老"NOR" 】";
					else if (budd >= 120)
						return  "【"HIY" 圣  僧"NOR" 】" ;
					else if (budd >= 90)
						return  "【"HIY" 罗  汉"NOR" 】" ;
					else if (budd >= 60)
						return  "【"YEL" 尊  者"NOR" 】" ;
					else if (budd >= 40)
						return "【 "YEL"禅  师"NOR" 】" ;
					else if (budd >= 30)
						return  "【"YEL" 比  丘"NOR" 】" ;
					else
						return "【 僧  人 】";
				case "yishi":   
						return "【江湖义士】";
				case "taoist":  
						return "【云游道士】";			       
				case "bandit":  
						return "【梁上君子】";
				case "scholar": 
						return "【翩翩才子】";		  
				case "officer": 
						return "【差    人】";
				case "swordsman":       
						return "【多情剑客】";		    
				case "alchemist":       
						return "【 方  士 】";		   
				case "shaman":  
						return "【 巫  医 】";
				case "beggar":  
						return "【穷叫花子】";      
				case "shiny":
						return "【光明使者】";
				default:		
					return "【布衣平民】";
				}
		}
	}
}
}
string query_respect(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/respect")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "女性":
			switch(ob->query("class")) {
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
			switch(ob->query("class")) {
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
	string str;

	if( stringp(str = ob->query("rank_info/rude")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "女性":
			switch(ob->query("class")) {
			case "bonze":
				return "贼尼";
				break;
			case "taoist":
				return "妖女";
				break;
			default:
				if( age < 30 || ob->query("special_skill/youth") ) return "小贱人";
				else return "死老太婆";
				break;
			}
		case "男性":
		default:
			switch(ob->query("class")) {
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
	string str;

	if( stringp(str = ob->query("rank_info/self")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "女性":
			switch(ob->query("class")) {
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
			switch(ob->query("class")) {
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
	string str;

	if( stringp(str = ob->query("rank_info/self_rude")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "女性":
			switch(ob->query("class")) {
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
			switch(ob->query("class")) {
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

string query_close(object ob, int age, string rgender)
{
	int a1, a2;
	string gender;
	if (objectp(ob) )       {
		if( !age )
			a1 = this_player()->query("age");
		else
			a1 = ob->query("age");
		if( !age)
			a2 = ob->query("age");
		else    a2 = age;
	}
	
	if( !rgender )
		gender = ob->query("gender");					   
	else    gender = rgender;

	switch ( gender ) {
	case "女性" :
		if (a1 > a2)
			return "妹妹";
		else
			return "姐姐";
		break;
	default :
		if (a1 > a2)
			return "弟弟";
		else
			return "哥哥";
	}
}

string query_self_close(object ob, int age)
{
	int a1, a2;
	string gender;
	if( objectp(ob) ) 
	{
		if( !age )
			a1 = this_player()->query("age");
		else
			a1 = ob->query("age");
		if( !age)
			a2 = ob->query("age");
		else    a2 = age;
	}

	if( age )
		gender = ob->query("gender");
	else
		gender = this_player()->query("gender");

	switch (gender) 
       {

	case "女性" :
		if (a1 > a2)
			return "姐姐我";
		else
			return "小妹我";
		break;
	default :
		if (a1 > a2)
			return "愚兄我";
		else
			return "小弟我";
	}
}
varargs string new_short( object ob ,int withshort)
{
	mixed tmp;
	string icon="", str;
	if(!objectp(ob))
	{
		CHANNEL_D->do_channel(this_player(),"chat","object参数错误！");
		return "";
	}
	if(!ob->query_temp("apply/id")||!ob->query_temp("apply/name")||!ob->query_temp("apply/short"))
		str = ob->query("name") + "(" +ob->query("id") + ")" +(!withshort?"":ob->short());
	else
		str = ob->query_temp("apply/name")[0] + "(" +ob->query_temp("apply/id")[0] + ")" +(!withshort?"":ob->query_temp("apply/short")[0]);
   
     //房间内更新人物或物品图象
	 //-默认OBJECT的图像--------------------------------------------------------------
     icon="";
     //自制物品的判断
     if(ob->query("icon"))
     {
	     icon=ob->query("icon");
     }
     else
     {
	  if(living(ob)) icon= "00901";   //默认生物为00901
	  else icon ="00961";		 //默认物品为00961
	  if(userp(ob) && !ob->query("icon")) 
	  icon=(ob->query("gender") == "男性" )?"01174":"01173";  //默认玩家头像
	  if(living(ob) && ob->query("family")!=0 && ob->query("gender") == "男性") icon = "00744";  //有家族的男性
	  if(living(ob) && ob->query("family")!=0 && ob->query("gender") == "女性") icon = "00739";  //有家族的女性
	//---笼统的物品图象--------------------------------------------------
	  if(ob->query("id")=="board")  icon="05025";	 //留言板 
	  if(ob->query("id")=="boy") icon = "02149";   //对经常虐待的男孩致敬
	  if(ob->query("id")=="girl") icon = "02111";   //女孩享受同等待遇	
	  if(ob->query("vendor_goods")) icon = "00988";  //最低优先级为卖货，（解决同时存在问题）
	  if(ob->query("teacher")) icon = "05014";	//教书   
	  if(ob->query("id")=="xiao er" || ob->query("id")=="xiaoer") icon = "05024";   //酒楼	
	  if(ob->query("dealer")=="bank") icon = "00842"; //钱庄
	  if(ob->query("dealer")=="pawn") icon = "00957"; //典当行
	  if(ob->query("id")=="zhuang jia") icon = "00923"; //赌场
	  if(ob->query("id")=="yahuan" ) icon = "02121"; //丫鬟
	  if(ob->query("id")=="guan bing" ) icon = "05016"; //官兵
	  if(ob->query("id")=="wu jiang" ) icon = "05010"; //武将
	  if(ob->query("unit")=="朵") icon="00942";   //花
	  if(ob->query("unit")=="本") icon="00906";   //书本      
       //物品图标显示---------------------------------------------
	  if(ob->query("id")=="coin") icon="01013";   //钱，银子
	  if(ob->query("id")=="silver") icon="05012";   //钱，银子
	  if(ob->query("id")=="cash") icon="00955";   //钱，银票
	  if(ob->query("id")=="gold") icon="05001";   //金子
	  
       //武器
	  if(ob->query("skill_type")=="sword") icon="05035";  //剑类武器 
	  if(ob->query("skill_type")=="pin") icon="01059";    //针类武器
	  //if(ob->query("skill_type")=="dagger") icon="05030"; //矛类武器
	  if(ob->query("skill_type")=="axe") icon="05029";    //斧类武器
	  if(ob->query("skill_type")=="dagger") icon="05040"; //匕首武器
	  if(ob->query("skill_type")=="staff") icon="05042";   //棍类武器
	   if(ob->query("skill_type")=="club") icon="05042";   //杖类武器
	  if(ob->query("skill_type")=="blade") icon="05038";  //刀类武器 
	  if(ob->query("skill_type")=="throwing") icon="05049";   //暗器 
	  if(ob->query("skill_type")=="hammer") icon="05050";     //锤 
	   if(ob->query("skill_type")=="fork") icon="05034";     //叉
       //防护装备
	  if(ob->query("armor_type")=="cloth") icon="05000";   //衣服
	   if(ob->query("armor_type")=="armor") icon="05044";   //装甲
	  if(ob->query("armor_type")=="pants") icon="05077";   //裤子
	  if(ob->query("armor_type")=="boots") icon="03007";   //鞋子
	  if(ob->query("armor_type")=="head") icon="03004";   //头
	  if(ob->query("armor_type")=="hands") icon="01980";   //手掌类
	  if(ob->query("armor_type")=="finger") icon="03002";   //手指类
	  if(ob->query("armor_type")=="shield") icon="05017";   //盾牌类
	  if(ob->query("armor_type")=="neck") icon="03006";   //项链
	  if(ob->query("armor_type")=="wrists") icon="03003";  //护腕
   }
    return str + icon;
}


