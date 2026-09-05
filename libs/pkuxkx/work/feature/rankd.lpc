// rankd.c
// 1996-02-15 dts ranking related to "shen"
// Modified by iszt@pkuxkx, 2007-01-18
// 带close的没有改，其他的都改了下
// Modified by iszt@pkuxkx, 2007-03-14, fixed some small bugs
// Added lingjiu/xingxiu/shenlong by whuan 2007-10-17
// 增加东厂 by Vast 2009-3-28

#include <ansi.h>

string query_rank(object ob)
{
//	mapping fam;
	string str;
	string gender,myclass;
	string family;

	int shen;
	int budd;
	int pin;
	int age;
    int exp;
	int divorce = ob->query("divorce");

	if( stringp(str = ob->query("rank_info/rank")) )
		return str;

	if( ob->is_ghost() )
		return HIB "【孤魂野鬼】" NOR;

//增加门派伪装的支持
//by seagate@pkuxkx 2010/12/04
  if ( ob->query_temp("apply/family") )
  	family= ob->query_temp("apply/family");
  else
	  family = ob->query("family/family_name");
    exp=ob->query("combat_exp");
	switch(family)
	{
		case "少林派": budd = ob->query_skill("buddhism",1); break;
		case "大轮寺": budd = ob->query_skill("huanxi-chan",1); break;
		case "武当派": budd = ob->query_skill("taoism",1); break;
		case "丐帮": budd = ob->query_skill("begging",1); break;
		case "桃花岛": budd = ob->query_skill("music",1); break;
		case "星宿派": budd = ob->query_skill("poison",1); break;	
		case "峨嵋派": budd = ob->query_skill("mahayana",1); break;
		case "白驼山": budd = ob->query_skill("hamagong", 1); break;
		case "华山派": budd = ob->query_skill("dugu-jiujian", 1); break;
		case "明教": budd = ob->query_skill("qiankun-danuoyi", 1); break;
		case "日月神教": budd = ob->query_skill("flatter", 1); break;
		case "古墓派": budd = ob->query_skill("xuantie-jian", 1); break;
		case "灵鹫宫": budd = ob->query_skill("bahuang-gong", 1); break;
		case "全真派": budd = ob->query_skill("daoxue-xinfa", 1); break;
		case "天龙寺": budd = ob->query_skill("beiming-shengong", 1); break;
		case "姑苏慕容": budd = ob->query_skill("douzhuan-xingyi", 1); break;
		case "天地会": budd = ob->query_skill("cangming-gong", 1); break;
		case "神龙教": budd = ob->query_skill("shenlong-xinfa", 1); break;
		case "雪山派": budd = ob->query_skill("xueshan-jianfa", 1); break;
		case "大理段家": budd = ob->query_skill("duanjia-xinfa", 1); break;
	  case "红花会": budd = ob->query_skill("duanjia-xinfa", 1); break;
	}

	if ( ob->query("class") == "officer" || ob->query("class") == "eunuch")
		pin = ob->query("pin");
		
	if ( ob->query_temp("apply/name") )
	{
		shen = ob->query_temp("apply/shen");
		gender = ob->query_temp("apply/gender")[0];
		myclass = ob->query_temp("apply/class");
//年龄也提供伪装支持
//by seagate@pkuxkx 2010/12/04
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
		switch(wizhood(ob))
		{
			case "(admin)"		: return HIW "【 天仙子 】" NOR;
			case "(arch)"		: return HIY "【 大仙子 】" NOR;
			case "(wizard)"		: return HIG "【 仙  子 】" NOR;
			case "(apprentice)"	: return HIC "【 小仙子 】" NOR;
			case "(immortal)"	: return HIC "【 散仙子 】" NOR;
		}
		if( (int)ob->query("PKS") > ob->query("combat_exp") / 1000000&&(int)ob->query("PKS") > 10 )
			return HIR"【杀人女魔】"NOR;
        if (ob->query("guider"))
        {
            if (sizeof(ob->query("guider/apps"))>10&&ob->query("guider/score")>1500)
            return HIC"【至圣先师】"NOR;
            if (sizeof(ob->query("guider/apps"))>10)
            return HIC"【万世师表】"NOR;
            else return HIC"【桃李满园】"NOR;
        }
		switch(myclass)
		{
		case "bonze":
			if(budd >= 200)	return HIW"【 神  尼 】"NOR;
			if(budd >= 150)	return HIW"【 法  师 】"NOR;
			if(budd >= 100)	return HIW"【 师  太 】"NOR;
			if(budd >= 50)	return HIW"【 比丘尼 】"NOR;
			if(age > 20)	return HIW"【 尼  姑 】"NOR;
			else 		return WHT"【 小尼姑 】"NOR;
		case "taoist":
			if(budd >= 1000)return HIW"【三清座下】"NOR;
			if(budd >= 200)	return HIW"【 玄  女 】"NOR;
			if(budd >= 150)	return HIW"【 仙  姑 】"NOR;
			if(budd >= 100)	return HIW"【 散  人 】"NOR;
			if(budd >= 50)	return WHT"【 道  姑 】"NOR;
			if(age > 20)	return WHT"【 道  姑 】"NOR;
			else 		return WHT"【 小道姑 】"NOR;
		case "officer":
			if(pin == 1)	return HIM"【一人之下】"NOR;
			if(pin == 2)	return HIM"【 总  兵 】"NOR;
			if(pin == 3)	return HIM"【 参  将 】"NOR;
			if(pin == 4)	return HIM"【 参  领 】"NOR;
			if(pin == 5)	return MAG"【 守  备 】"NOR;
			if(pin == 6)	return MAG"【 女千总 】"NOR;
			if(pin == 7)	return MAG"【 女把总 】"NOR;
			if(pin == 8)	return MAG"【 女校尉 】"NOR;
			else		    return MAG"【 女协领 】"NOR;
		case "huanxi":
            if(budd >= 300&&shen>=exp)	return HIG"【 女活佛 】"NOR;
			if(budd >= 300&&shen<exp)	return HIG"【 圣法王 】"NOR;
			if(budd >= 160)	return HIG"【 飞  天 】"NOR;
			if(budd >= 100)	return HIG"【 乾达婆 】"NOR;
			if(budd >= 80)	return HIG"【 神妙女 】"NOR;
			else		return GRN"【 授  事 】"NOR;
		case "beggar":
			if(family == "丐帮") break;
			if(budd >= 120&&shen>0)	return HIG"【 神  丐 】"NOR;
            if(budd >= 120&&shen<=0)	return HIG"【 魔  丐 】"NOR;
			else		return HIG"【 叫化婆 】"NOR;
		case "bandit":
			return "【 女飞贼 】";
		case "dancer":
			return "【 舞  妓 】";
		case "fighter":
			return "【 女武者 】";
		case "scholar":
			return "【 才  女 】";
		case "swordsman":
			return "【 女剑士 】";
		case "alchemist":
			return "【 方  士 】";
		case "shaman":
			return "【 巫  医 】";
		}


		switch(family)
		{
		case "少林派":
		case "大轮寺":
			if(budd >= 160)	return HIG"【乞净食女】"NOR;
			else		return GRN"【洒扫杂役】"NOR;
		case "武当派":
		case "全真派":	
			if(budd >= 180)	return HIY"【得证大道】"NOR;
			else 		return YEL"【俗家弟子】"NOR;
		case "丐帮":
			if(budd >= 200)	return HIG"【 副帮主 】"NOR;
			if(budd >= 160)	return HIG"【总舵长老】"NOR;
			if(budd >= 120)	return HIG"【分舵龙头】"NOR;
			if(budd >= 80)	return HIG"【分舵香主】"NOR;
			if(budd >= 30)	return GRN"【分舵帮众】"NOR;
			else		return GRN"【 叫化婆 】"NOR;
		case "桃花岛":
			if(budd >= 180)	return HIC"【 逸  仙 】"NOR;
			if(budd >= 140)	return HIC"【 逸  贤 】"NOR;
			if(budd >= 100)	return CYN"【 逸  士 】"NOR;
			if(budd >= 50)	return CYN"【 青  衣 】"NOR;
			if(age >= 18)	return CYN"【 青  衣 】"NOR;
			else break;
    case "神龙教":
    case "星宿派" :
            if (budd >= 600) return HIB"【 毒  圣 】"NOR;
            if (budd >= 400) return HIB"【 毒  后 】"NOR;
            if (budd >= 150) return HIB"【 毒夫人 】"NOR;
            if (budd >= 100) return BLU"【 魔  女 】"NOR;
            if (budd >= 50) return BLU" 【 女魔头 】"NOR;
            if (shen <= -500) return BLU"【 小魔女 】"NOR;
            return BLU"【 钹  手 】"NOR;
		case "峨嵋派":
			if(budd >= 160) return HIW"【 女居士 】"NOR;
			else		return WHT"【 学戒女 】"NOR;
		case "白驼山":
			if(budd >= 500)	return HIY"【 少庄主 】"NOR;
			break;
		case "华山派":
            if(budd >= 600)	return HIM"【 剑  圣 】"NOR;
			if(budd >= 400)	return HIM"【 剑  仙 】"NOR;
			if(budd >= 100)	return MAG"【 女剑侠 】"NOR;
			if(budd >= 50)	return MAG"【 女剑客 】"NOR;
			if(age >= 18)	return MAG"【 女剑客 】"NOR;
			return MAG"【 女剑童 】"NOR;
		case "雪山派":
			if(budd >= 600)	return HIW"【 剑  圣 】"NOR;
			if(budd >= 400)	return HIW"【 剑  仙 】"NOR;
			if(budd >= 100)	return WHT"【 女剑侠 】"NOR;
			if(budd >= 50)	return WHT"【 女剑客 】"NOR;
			if(age >= 18)	return WHT"【 女剑客 】"NOR;
			return WHT"【 女剑童 】"NOR;
		case "明教":
			if(budd >= 600)	return HIR"【 圣  女 】"NOR;
			if(budd >= 400)	return HIR"【宝树神姬】"NOR;
			if(budd >= 200)	return RED"【护教法王】"NOR;
			if(budd >= 150)	return RED"【天门香主】"NOR;
			if(budd >= 100)	return RED"【 女香主 】"NOR;
			if(budd >= 20)	return RED"【 女教众 】"NOR;
			return RED "【 侍  女 】" NOR;
	//	case "日月神教":
		case "大理段家":
			if(budd >= 500)	return HIY"【 郡  主 】"NOR;
			if(budd >= 200)	return HIY"【 女侍卫 】"NOR;				
			break;
		case "红花会":
			if(budd >= 500)	return HIY"【 副舵主 】"NOR;
			if(budd >= 200)	return HIY"【 香  主 】"NOR;				
			break;				
	//	case "天龙寺":
		case "古墓派":
			if(budd >= 600)	return HIW"【 玉  女 】"NOR;
            if(budd >= 300)	return WHT"【 玉  女 】"NOR;
			else		return WHT"【 女弟子 】"NOR;
		case "灵鹫宫":
			if(budd >= 600)	return HIY"【 副宫主 】"NOR;
            if(budd >= 300) return HIY"【 首  领 】"NOR;
			if(budd >= 100)	return HIY"【 副首领 】"NOR;
			if(budd >= 50)	return YEL"【 洞  主 】"NOR;
			if(age >= 18)	return YEL"【 女弟子 】"NOR;
			else		    return YEL"【 侍  女 】"NOR;
		case "姑苏慕容":
			if(budd >= 300)	return HIC"【金枝玉叶】"NOR;
			if(budd >= 180)	return HIC"【 郡  主 】"NOR;
			if(budd >= 120)	return CYN"【 女管家 】"NOR;
			if(budd >= 60)	return CYN"【 侍  书 】"NOR;
			if(budd >= 30)	return CYN"【 大丫鬟 】"NOR;
			else		return CYN"【 丫  鬟 】"NOR;
		case "天地会":
			if(budd >= 400)	return HIC"【副总舵主】"NOR;
	//	
	//	case "雪山派":
		}

		if (divorce > 2) {
			if (age < 50) return "【 荡  妇 】";
			return "【 老荡妇 】";
		}
		if (divorce) {
			if (age < 50) return "【 寡  妇 】";
			return "【 老寡妇 】";
		}

		if(shen >= 100000000)	return HIC"【旷世侠女】"NOR;
		if(shen >= 20000000)	return HIC"【绝世天娇】"NOR;
		if(shen >= 5000000)	return HIC"【巾帼女侠】"NOR;
		if(shen >= 500000)	return HIC"【 女飞侠 】"NOR;
		if(shen >= 50000)	return HIC"【 女  侠 】"NOR;
		if(shen >= 5000)	return CYN"【 小侠女 】"NOR;
		if(shen >= 500)		return CYN"【 信  女 】"NOR;
		if(shen <= -500)	return CYN"【 恶  女 】"NOR;
		if(shen <= -5000)	return HIB"【 女魔头 】"NOR;
		if(shen <= -50000)	return HIB"【 女魔王 】"NOR;
		if(shen <= -500000)	return HIB"【 天魔女 】"NOR;
		if(shen <= -5000000)	return HIB"【魅世妖姬】"NOR;
		if(shen <= -20000000)	return HIB"【灭世罗刹】"NOR;
		if(shen <= -100000000)	return HIB"【旷世魔女】"NOR;
		if (ob->query("marry")) {
			if (age < 30) return "【 少  妇 】";
			if (age < 50) return "【中年妇人】";
			return "【 老妇人 】";
		}
		if (age < 18) return "【 少  女 】";
		if (age < 30) return "【青年女子】";
		if (age < 50) return "【中年女子】";
		return "【 老处女 】";



	case "无性":
		if(wizardp(ob))
			return HIY"【观音菩萨】"NOR;
        if (ob->query("guider"))
        {
            if (sizeof(ob->query("guider/apps"))>10&&ob->query("guider/score")>1500)
            return HIC"【至圣先师】"NOR;
            if (sizeof(ob->query("guider/apps"))>10)
            return HIC"【万世师表】"NOR;
            else return HIC"【桃李满园】"NOR;
        }
		if(myclass == "eunuch")
		{
			switch(pin)
			{
			case 1: return HIM"【只手遮天】"NOR;
			case 2: return HIM"【东厂掌印】"NOR;
			case 3: return HIM"【东厂千户】"NOR;
			case 4:	return HIM"【东厂百户】"NOR;
			case 5:	return MAG"【东厂掌班】"NOR;
			case 6:	return MAG"【东厂领班】"NOR;
			case 7:	return MAG"【东厂司房】"NOR;
			case 8:	return MAG"【东厂役长】"NOR;
			case 9:	return MAG"【东厂番役】"NOR;
			}
		}
		if(family == "日月神教" && ob->query("score") >= 2000)
			return HIR"【日月神使】"NOR;
		budd = (int)ob->query_skill("pixie-jian", 1);
		if(budd >= 200)	return HIR"【 妖  神 】"NOR;
		if(budd >= 30)	return RED"【 人  妖 】"NOR;
		else		return RED"【 阉  人 】" NOR;



	case "男性":
		switch(wizhood(ob))
		{
		case "(admin)":		return HIW"【 天  神 】"NOR;
		case "(arch)":		return HIY"【 大  神 】"NOR;
		case "(wizard)":	return HIG"【 仙  人 】"NOR;
		case "(apprentice)":	return HIC"【 小  仙 】"NOR;
		case "(immortal)":	return HIC"【 散  仙 】"NOR;
		}

		if( (int)ob->query("PKS") > ob->query("combat_exp") / 1000000 &&(int)ob->query("PKS") > 10 )
			return HIR"【杀人狂魔】"NOR;
        if (ob->query("guider"))
        {
            if (sizeof(ob->query("guider/apps"))>10&&ob->query("guider/score")>1500)
            return HIC"【至圣先师】"NOR;
            if (sizeof(ob->query("guider/apps"))>10)
            return HIC"【万世师表】"NOR;
            else return HIC"【桃李满园】"NOR;
        }
		switch(myclass) {
		case "bonze":
            if(budd >= 1000&&exp>100000000)	return HIY"【胁侍菩萨】"NOR;
			if(budd >= 500&&exp>50000000)	return HIY"【 菩  萨 】"NOR;
			if(budd >= 240&&exp>100000000)	return HIY"【 伽  蓝 】"NOR;//珈蓝为佛教护法神，打架专用的。
			if(budd >= 180)	return HIY"【 罗  汉 】"NOR;
			if(budd >= 100)	return HIY"【 金  刚 】"NOR;
			if(budd >= 80)	return HIY"【 尊  者 】"NOR;
			if(budd >= 60)	return YEL"【 禅  师 】"NOR;
			if(budd >= 40)	return YEL"【 比  丘 】"NOR;
			if(age > 20)	return YEL"【 僧  人 】"NOR;
			else 		return YEL"【 沙  弥 】"NOR;
		case "taoist":
			if(budd >= 1000&&exp>100000000)return HIW"【三清座下】"NOR;
			if(budd >= 240)	return HIW"【 天  尊 】"NOR;
			if(budd >= 160)	return HIW"【 天  师 】"NOR;
			if(budd >= 120)	return HIW"【 真  人 】"NOR;
			if(budd >= 80)	return HIW"【 道  长 】"NOR;
			if(budd >= 50)	return WHT"【 道  士 】"NOR;
			if(age >= 20)	return WHT"【 道  士 】"NOR;
			else		return WHT"【 道  童 】"NOR;
		case"officer":
			if(pin == 1)	return HIM"【一人之下】"NOR;
			if(pin == 2)	return HIM"【 总  兵 】"NOR;
			if(pin == 3)	return HIM"【 参  将 】"NOR;
			if(pin == 4)	return HIM"【 参  领 】"NOR;
			if(pin == 5)	return MAG"【 守  备 】"NOR;
			if(pin == 6)	return MAG"【 千  总 】"NOR;
			if(pin == 7)	return MAG"【 把  总 】"NOR;
			if(pin == 8)	return MAG"【 校  尉 】"NOR;
			else		    return MAG"【 协  领 】"NOR;
		case "huanxi":
			if(budd >= 300&&shen>=exp)	return HIG"【 活  佛 】"NOR;
			if(budd >= 300&&shen<exp)	return HIG"【 法  王 】"NOR;
			if(budd >= 160)	return HIG"【 护  法 】"NOR;
			if(budd >= 100)	return HIG"【 化  身 】"NOR;
			if(budd >= 80)	return HIG"【 大喇嘛 】"NOR;
			else		return GRN"【 喇  嘛 】"NOR;
		case "beggar":
			if(family == "丐帮") break;
			if(budd >= 120&&shen>0)	return HIG"【 神  丐 】"NOR;
            if(budd >= 120&&shen<=0)	return HIG"【 魔  丐 】"NOR;
			if(budd >= 70)	return GRN"【云游乞丐】"NOR;
			else		return GRN"【 叫化子 】"NOR;
		case "bandit":
			return "【 盗  贼 】";
		case "scholar":
			return "【 书  生 】";
		case "fighter":
			return "【 武  者 】";
		case "swordsman":
			return "【 剑  士 】";
		case "alchemist":
			return "【 方  士 】";
		case "shaman":
			return "【 巫  医 】";
		}

		switch(family)
		{
		case "少林派":
			if(age >= 20)	return YEL"【 行  者 】"NOR;
			else break;
		case "大轮寺":
			if(budd >= 160)	return HIG"【 上  师 】"NOR;
			else		return GRN"【火工杂役】"NOR;
		case "武当派":
		case "全真派":
			if(budd >= 180)	return HIY"【得证大道】"NOR;
			else 		return YEL"【俗家弟子】"NOR;
		case "丐帮":
			if(budd >= 250)	return HIG"【 副帮主 】"NOR;
			if(budd >= 160)	return HIG"【总舵长老】"NOR;
			if(budd >= 120)	return HIG"【分舵龙头】"NOR;
			if(budd >= 80)	return HIG"【分舵香主】"NOR;
			if(budd >= 20)	return GRN"【分舵帮众】"NOR;
			else		return GRN"【 叫化子 】"NOR;
		case "桃花岛":
			if(budd >= 180)	return HIC"【 逸  圣 】"NOR;
			if(budd >= 140)	return HIC"【 逸  贤 】"NOR;
			if(budd >= 100)	return CYN"【 逸  士 】"NOR;
			if(budd >= 50)	return CYN"【 门  生 】"NOR;
			if(age >= 18)	return CYN"【 门  生 】"NOR;
			else break;
	//	case "星宿派":
		case "峨嵋派":
			if(budd >= 160) return HIW"【 居  士 】"NOR;
		case "白驼山":
			if(budd >= 500)	return HIW"【 少庄主 】"NOR;
			break;
		case "华山派":
            if(budd >= 600)	return HIM"【 剑  神 】"NOR;
			if(budd >= 400)	return HIM"【 剑  尊 】"NOR;
			if(budd >= 100)	return MAG"【 剑  侠 】"NOR;
			if(budd >= 50)	return MAG"【 剑  客 】"NOR;
			if(age >= 18)	return MAG"【 剑  客 】"NOR;
			return MAG"【 剑  童 】"NOR;
		case "雪山派":
			if(budd >= 600)	return HIW"【 剑  神 】"NOR;
			if(budd >= 400)	return HIW"【 剑  尊 】"NOR;
			if(budd >= 100)	return WHT"【 剑  侠 】"NOR;
			if(budd >= 50)	return WHT"【 剑  客 】"NOR;
			if(age >= 18)	return WHT"【 剑  客 】"NOR;
			return WHT"【 剑  童 】"NOR;
		case "明教":
			if(budd >= 600)	return HIR"【 副教主 】"NOR;
			if(budd >= 400)	return HIR"【光明使者】"NOR;
			if(budd >= 200)	return RED"【护教法王】"NOR;
			if(budd >= 150)	return RED"【五旗护法】"NOR;
			if(budd >= 100)	return RED"【 香  主 】"NOR;
			if(budd >= 20)	return RED"【 教  众 】"NOR;
                        return RED "【 侍  从 】" NOR;
	//	case "日月神教":
		case "古墓派":
            if(budd >= 600)	return HIW"【 狂  徒 】"NOR;
            if(budd >= 300)	return WHT"【 狂  徒 】"NOR;
			else		return WHT"【 男弟子 】"NOR;
		case "天龙寺":
			if(budd >= 600)	return HIW"【 隐  圣 】"NOR;
			if(budd >= 400)	return HIY"【 隐  狂 】"NOR;
			if(budd >= 100)	return HIC"【 剑  侠 】"NOR;
			if(budd >= 50)	return YEL"【 剑  客 】"NOR;
			if(age >= 18)	return YEL"【 剑  客 】"NOR;
			else		return YEL"【 剑  童 】"NOR;
		case "大理段家":
			if(budd >= 500)	return HIY"【 侯  爷 】"NOR;
			if(budd >= 200)	return HIY"【 家  臣 】"NOR;				
			break;
		case "红花会":
			if(budd >= 500)	return HIY"【 副舵主 】"NOR;
			if(budd >= 200)	return HIY"【 香  主 】"NOR;				
			break;							
	//	case "全真派":
	//	
	//	case "桃花岛":
		case "姑苏慕容":
			if(budd >= 600)	return HIC"【 世  子 】"NOR;
			if(budd >= 250)	return HIC"【 庄  主 】"NOR;
			if(budd >= 180)	return CYN"【 大管家 】"NOR;
			if(budd >= 60)	return CYN"【 管  家 】"NOR;
			if(budd >= 30)	return CYN"【 护  院 】"NOR;
			else		return CYN"【 庄  丁 】"NOR;
		case "天地会":
			if(budd >= 500)	return HIC"【副总舵主】"NOR;
	  case "星宿派" :
            if(budd >= 600)	return HIB"【 毒  神 】"NOR;
			if(budd >= 400)	return HIB"【 毒  王 】"NOR;
			if(budd >= 100)	return HIB"【 毒  尊 】"NOR;
			if(budd >= 50)	return BLU"【 毒  魔 】"NOR;
			if(age >= 18)	return BLU"【 号  手 】"NOR;
			else		return BLU"【 鼓  手 】"NOR;
    case "神龙教" :                                         
      if (budd >= 200) return HIB"【灭世魔尊】"NOR;   
      if (budd >= 160) return HIB"【盖世狂魔】"NOR;   
      if (budd >= 120) return HIB"【 魔  尊 】"NOR;   
      if (budd >= 80) return BLU"【 魔  王 】"NOR;    
      if (budd >= 50) return BLU"【 魔  头 】"NOR;    
      if (shen <= -500) return BLU"【 恶  徒 】"NOR;  
      return BLU"【 少  年 】"NOR;                          

	//	case "雪山派":
		}

		if (divorce > 2) {
			if (age < 50) return HIM"【花"HIY"花"HIG"公"HIR"子"HIM"】"NOR;
			return "【 老色鬼 】";
		}
		if (divorce) {
			if (age < 50) return "【 鳏  夫 】";
			return "【 老鳏夫 】";
		}

		if(shen >= 100000000)	return HIC"【旷世大侠】"NOR;
		if(shen >= 20000000)	return HIC"【天之骄子】"NOR;
		if(shen >= 5000000)	return HIC"【盖世豪侠】"NOR;
		if(shen >= 500000)	return HIC"【 大  侠 】"NOR;
		if(shen >= 50000)	return HIC"【 侠  客 】"NOR;
		if(shen >= 5000)	return CYN"【 少  侠 】"NOR;
		if(shen >= 500)		return CYN"【 善  人 】"NOR;
		if(shen <= -500)	return CYN"【 恶  徒 】"NOR;
		if(shen <= -5000)	return HIB"【 魔  头 】"NOR;
		if(shen <= -50000)	return HIB"【 魔  王 】"NOR;
		if(shen <= -500000)	return HIB"【 天  魔 】"NOR;
		if(shen <= -5000000)	return HIB"【盖世狂魔】"NOR;
		if(shen <= -20000000)	return HIB"【绝世魔头】"NOR;
		if(shen <= -100000000)	return HIB"【旷世魔王】"NOR;

		if (ob->query("marry")) {
			if (age < 30) return "【青年男子】";
			if (age < 50) return "【中年男子】";
			return "【 老头子 】";
		}
		if (age < 18) return "【 少  年 】";
		if (age < 30) return "【青年男子】";
		if (age < 50) return "【中年男子】";
		return "【 老处男 】";
	default:
		return BNK+HIR"【非男非女】"NOR;
	}
}

string query_respect(object ob)
{
	int age;
	string str,gender,myclass,shen;

	if(!ob->is_character())
		return "神仙";
	if(ob->is_corpse())
		return "前辈";
	if(ob->query_temp("rumor_fail") > 1 + random(4))
		return "漏勺前辈";
	if(ob->query("per") < random(14))
		return "小「美」人儿";
	if( stringp(str = ob->query("rank_info/respect")) )
		return str;
	if (ob->query("race") != "人类")
		return "兄弟";

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
			if(ob->query_per() > 30)
				return "神仙姐姐";
			switch(myclass) {
			case "bonze":
				if( age < 18 ) return "小师太";
				else return "师太";
				break;
			case "taoist":
				if( age < 18 ) return "小仙姑";
				else return "仙姑";
				break;
			case "officer":
				return "大人";
			default:
				if( age < 18 ) return "小姑娘";
				else if( age < 50 ) return "姑娘";
				else return "老婆婆";
				break;
			}
		case "无性":
			if( age < 18 ) return "小公公";
			else return "公公";     
		default:
			switch(myclass)
			{
			case "bonze":
				if( age < 18 ) return "小师父";
				else return "大师";
			case "huanxi":
				if( age < 50 ) return "大师父";
				return "上人";
			case "taoist":
				if( age < 18 ) return "道兄";
				if( age < 50 ) return "道长";
				else return "老道长";
			case "officer":
				return "大人";
			case "fighter":
			case "swordsman":
				if( age < 18 ) return "小老弟";
				else if( age < 40 ) return "壮士";
				else if( age < 50 ) return "阁下";
				else return "老前辈";
			default:
				if( age < 20 ) return "小兄弟";
				else if( age < 40 ) return "壮士";
				else if( age < 50 ) return "阁下";
				else return "老爷子";
			}
	}
}

string query_rude(object ob)
{
	int age;
	string str,gender,myclass,shen;

	if(!ob->is_character())
		return "小东西";
	if(ob->is_corpse())
		return "死鬼";
	if(ob->query_temp("rumor_fail") > 1 + random(4))
		return "倒霉蛋";
	if(ob->query("per") < random(14))
		return "丑八怪";
	if( stringp(str = ob->query("rank_info/rude")) )
		return str;
	if (ob->query("race") != "人类")
		return "畜生";

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
				if( age < 30)
					return "小尼姑";
				else
					return "贼尼";
			case "taoist": return "妖女";
			case "huanxi": return "臭藏尼";
			case "officer" : return "狗官";
			case "beggar" : return "臭要饭的";
			default:
				if( age < 30 ) return "小贱人";
				else if( age < 50 ) return "贱人";
				else return "死老太婆";
				break;
			}
		case "无性":
			return "阉贼";
			break;
		default:
			switch(myclass) {
			case "bonze":
				if( age < 50 ) return "死秃驴";
				else return "老秃驴";
			case "taoist":
				if( age < 80 ) return "死牛鼻子";
				else if(age < 150) return "妖道";
				else return "老不死的";
			case "huanxi":
				if( age < 50 ) return "死番僧";
				return "老秃驴";
			case "officer" :
				if( age < 60 ) return "狗官";
				else return "老不死的";
			case "beggar" : return "臭要饭的";
			default:
				if( age < 20 ) return "小王八蛋";
				else if( age < 50 ) return "臭贼";
				else if( age < 80 ) return "老匹夫";
				else return "老不死的";
			}
	}
}

string query_self(object ob)
{
	int age;
	string str,gender,myclass,shen;

	if(ob->query_temp("rumor_fail") > 1 + random(4))
		return "本漏勺";
	if( stringp(str = ob->query("rank_info/respect")) )
		return str;
	if(ob->query("race") != "人类")
		return ob->name();

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
			case "huanxi":
				if( age < 50 ) return "贫尼";
				else return "老尼";
			case "taoist":
				return "贫道";
			case "officer":
				if( age < 60 ) return "下官";
				return "老身";
			case "beggar":
				if( age < 30) return "小叫化";
				else return "叫化子";
			default:
				if( age < 30 ) return "小女子";
				else if( age < 50 ) return "妾身";
				else return "老身";
			}
		case "无性":
			return "杂家";
		default:
			switch(myclass) {
			case "bonze":
				if( age < 20 ) return "小僧";
				if( age < 50 ) return "贫僧";
				else return "老衲";
			case "taoist":
				return "贫道";
			case "huanxi":
				if( age < 50 ) return "小僧";
				return "老朽";
			case "officer":
				if( age < 60 ) return "下官";
				return "老朽";
			case "beggar":
				if( age < 30) return "小叫化";
				else if( age < 60 ) return "叫化子";
				else return "老叫化";
			default:
				if( age < 30 ) return "在下";
				else if( age < 60 ) return "不才";
				else return "老朽";
			}
	}
}

string query_self_rude(object ob)
{
	int age;
	string str,gender,myclass,shen;

	if(ob->query_temp("rumor_fail") > 1 + random(4))
		return "我暴露狂";
	if( stringp(str = ob->query("rank_info/respect")) )
		return str;
	if(ob->query("race") != "人类")
		return ob->name() + "我";

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
			case "huanxi":
				if( age < 50 ) return "贫尼我";
				else return "老尼我";
			case "officer":
				if( age < 80 ) return "本座";
				return "太座";
			case "beggar":
				return "你祖宗我";
			default:
				if (age < 20)  return "本小姐";
				if( age < 50 ) return "本姑娘";
				else return "老娘";
			}
		case "无性": return "公公我";
		default:
			switch(myclass) {
			case "bonze":
				if( age < 50 ) return "大和尚我";
				else return "老和尚我";
				break;
			case "huanxi":
				if( age < 50 ) return "大和尚我";
				return "本佛爷";
			case "taoist":
				return "本山人";
				break;
			case "officer":
				if( age < 30 ) return "本大爷";
				return "老爷我";
			default:
				if( age < 20 ) return "小爷我";
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

	if (objectp(this_player())) //qq channel is not player
	{
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
	                                gender = ob->query("gender"); //对方的gender，by whuan
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
	} else
	{
		gender = ob->query("gender");
		a2=(int)mud_age;
		a1=0;
	}
	
	switch (gender) {
	case "女性" :
		if (a1 >= a2)
			return "美眉";
		else
			return "姊姊";
		break;
	default :
		if (a1 >= a2)
			return "贤弟";
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

	if (objectp(this_player())) //qq channel is not player
	{
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
				return "愚兄";
			else
				return "小弟";
		}
	} else
		return "在下";
}


