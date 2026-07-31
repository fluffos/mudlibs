// rankd.c
// 1996-02-15 dts ranking related to "shen"

#include <ansi.h>

string query_rank(object ob)
{
        mapping fam;

        int exp;
        int shen;
        int budd;
        int age;
string family;
        if( ob->is_ghost() )
                return HIB "【孤魂野鬼】" NOR;

        shen = ob->query("shen");
        exp = ob->query("combat_exp");
        age = ob->query("age");
        family = ob->query("family/family_name");
        if ( (fam = ob->query("family")) && (fam["family_name"] == "少林派"
                || fam["family_name"] == "峨嵋派"
                || fam["family_name"] == "天龙寺"
                || fam["family_name"] == "雪山派"
                || fam["family_name"] == "恒山派"
                ))
                budd = ob->query_skill("buddhism",1);
//        if(exp >=2500000 && shen >=200000)
//                return HIW "【传说中的大侠】" NOR;
//        if(exp >=2500000 && shen <=-200000)
//                return HIW "【传说中的魔王】" NOR;
//        if(exp >=1500000)
//                return HIW "【武林传奇】" NOR;


        switch(ob->query("gender")) {
        case "女性":
                switch(wizhood(ob)) {
                case "(admin)":
                        return HIM "【九天玄女】" NOR;
                case "(arch)":
                        return HIY "【修罗女神】" NOR;
                case "(wizard)":
                        return HIG "【瑶池仙女】" NOR;
                case "(apprentice)":
                        return HIC "【 仙  妃 】" NOR;
                case "(immortal)":
                        return HIC "【海洋使者】" NOR;
                default:
/*if (!ob->query("class") || !family) {
                        if (((int)ob->query("PKS") > 100) &&
                            ((int)ob->query("PKS") > (int)ob->query("MKS")))
                                return HIR "【饮血女魔】" NOR;
                        if ((int)ob->query("thief") > 10 )
                                return HIC "【女 惯 窃】" NOR;
                       if (shen >= 1000000) return HIC "【绝世天娇】" NOR;
                        else if (shen >= 100000 && exp >=800000)
                                return HIC "【旷世女侠】" NOR;
                        else if (shen >= 10000 && exp >=400000)
                                return HIC "【 大女侠 】" NOR;
                        else if (shen >= 1000 && exp >=200000)
                                return HIC "【 女  侠 】" NOR;
                        else if (shen >= 100 && exp >=50000)
                                return HIC "【 女少侠 】" NOR;
                        if (shen <= -1000000) return HIR "【盖世罗刹】" NOR;
                        else if (shen <= -100000 && exp >=800000)
                                return HIC "【旷世女魔】" NOR;
                        else if (shen <= -10000 && exp >=400000)
                                return HIC "【 大女魔 】" NOR;
                        else if (shen <= -1000 && exp >=200000)
                                return HIC "【 女  魔 】" NOR;
                        else if (shen <= -100 && exp >=50000)
                                return HIC "【 女少魔 】" NOR;
}
                        else*/
if (family=="日月神教")
 {
                       if (exp>= 1000000 ) return HIW "【 圣  姑 】" NOR;
                       else if (exp>= 800000 ) return HIW "【 左护法 】" NOR;
                       else if (exp>= 700000) return HIY "【 堂  主 】" NOR;
                       else if (exp>= 600000)  return HIY "【 坛  主 】" NOR;
                       else if (exp>= 50000) return YEL "【 香  主 】" NOR;
                       else if (exp>= 30000 || age >= 20) return CYN "【 女教众 】" NOR;
                       else return CYN "【 女教徒 】" NOR;
 }else
 if (family=="逍遥派" || family=="桃花岛")
 {
                       if (exp>= 1000000 ) return HIW "【 逸  仙 】" NOR;
                       else if (exp>= 800000 ) return HIW "【 逸  贤 】" NOR;
                       else if (exp>= 700000) return HIY "【 逸  士 】" NOR;
                       else if (exp>= 600000)  return HIY "【 逸  士 】" NOR;
                       else if (exp>= 50000) return YEL "【 逸  士 】" NOR;
                       else if (exp>= 30000 || age >= 20) return CYN "【 青  衣 】" NOR;
                       else return CYN "【女 少 冠】" NOR;
 }else
if (family=="雪山寺")
 {
                       if (exp>= 1000000 && shen >= 0) return HIW "【 欢喜佛 】" NOR;
                       else if (exp>= 1000000 && shen < 0) return HIW "【 欢喜魔 】" NOR;
                       else if (exp>= 700000) return HIY "【 圣  女 】" NOR;
                       else if (exp>= 600000)  return HIY "【 飞  天 】" NOR;
                       else if (exp>= 50000) return YEL "【 乾达婆 】" NOR;
                       else if (exp>= 30000 || age >= 20) return CYN "【 神妙女 】" NOR;
                       else return CYN "【 授  事 】" NOR;
 }else
 if (family=="古墓派" || family=="华山派" || family=="凌霄城")
 {
                       if (exp>= 2000000 && shen > 0) return HIW "【惊天一剑】" NOR;
                       else if (exp>= 2000000 && shen < 0) return HIW "【惊魔一剑】" NOR;
                        else if (exp>= 1000000) return HIR "【 剑  圣 】" NOR;
                        else if (exp>= 800000) return HIY "【 剑  仙 】" NOR;
                        else if (exp>= 700000) return HIC "【 女剑侠 】" NOR;
                        else if (exp>= 500000 )  return YEL "【 女剑客 】" NOR; 
                        else return "【 女剑士 】";
 }else
 if (family=="姑苏慕容" || family=="大理段家")
 {
                        if (exp>= 1000000) return HIR "【 王  妃 】" NOR;
                        else if (exp>= 800000) return HIY "【 诰命夫人 】" NOR;
                        else if (exp>= 700000) return HIC "【 女  官 】" NOR;
                        else if (exp>= 500000 )  return YEL "【 女  官 】" NOR; 
                        else if ( age >= 18)  return CYN "【 女  官 】" NOR; 
                        else return "【 女  侍 】";
 }else
  if (family=="灵鹫宫")
 {
                        if (exp>= 1000000) return HIR "【 玄  女 】" NOR;
                        else if (exp>= 800000) return HIY "【 仙  子 】" NOR;
                        else if (exp>= 700000) return HIC "【 天  女 】" NOR;
                        else if (exp>= 500000 )  return YEL "【逍遥女仙】" NOR; 
                        else if ( age >= 18)  return CYN "【 仙  姑 】" NOR; 
                        else return "【 仙  姑 】";
 }else
  if (family=="明教")
 {
						if (exp>10000000)
								return NOR "【"HIR"女副教主"NOR"】";
						if (exp>5000000)
								return NOR "【"HIM" 法  王 "NOR"】";
						if (exp>1000000)
								return NOR "【"GRN"女总护法"NOR"】";
						if (exp>500000)
								return NOR "【"YEL"女 护 法"NOR"】";
						if (exp>300000)
								return NOR "【"YEL"女总堂主"NOR"】";
						if (exp>100000)
								return NOR "【"CYN"女副堂主"NOR"】";
						if (exp>25000)
								return NOR "【"CYN"女 旗 主"NOR"】";
						if (exp>10000)
								return NOR "【"MAG"女副旗主"NOR"】";
						if (exp>5000)
								return NOR "【"MAG"女 教 众"NOR"】";
						return "【  教  众  】" ;
 }else
  if (family=="云龙门")
 {
                        return HIG"【女 义 士】"NOR;
 }else
  if (family=="星宿派")
 {
						if (exp>10000000)
								return NOR "【"HIR"毒   后"NOR"】";
						if (exp>5000000)
								return NOR "【"HIM"毒   姬"NOR"】";
						if (exp>1000000)
								return NOR "【"GRN"毒   妖"NOR"】";
						if (exp>500000)
								return NOR "【"YEL" 毒罗刹 "NOR"】";
						if (exp>300000)
								return NOR "【"YEL" 毒罗刹 "NOR"】";
						if (exp>100000)
								return NOR "【"CYN" 毒罗刹 "NOR"】";
						if (exp>25000)
								return NOR "【"CYN" 毒罗刹 "NOR"】";
						if (exp>10000)
								return NOR "【"MAG" 毒罗刹 "NOR"】";
						if (exp>5000)
								return NOR "【"MAG"毒    怪"NOR"】";
						return "【  马屁虫  】" ;
 }else
  if (family=="五毒教")
 {
						if (exp>10000000)
								return NOR "【"HIR"毒   后"NOR"】";
						if (exp>5000000)
								return NOR "【"HIM"毒   姬"NOR"】";
						if (exp>1000000)
								return NOR "【"GRN"毒   妖"NOR"】";
						if (exp>500000)
								return NOR "【"YEL" 毒罗刹 "NOR"】";
						if (exp>300000)
								return NOR "【"YEL" 毒罗刹 "NOR"】";
						if (exp>100000)
								return NOR "【"CYN" 毒罗刹 "NOR"】";
						if (exp>25000)
								return NOR "【"CYN" 毒罗刹 "NOR"】";
						if (exp>10000)
								return NOR "【"MAG" 毒罗刹 "NOR"】";
						if (exp>5000)
								return NOR "【"MAG"毒    怪"NOR"】";
						return "【  女教众  】" ;
 }else

  if (family=="白驼山派")
 {
	if (shen >= 0)
	return NOR "【"HIR"魔 见 愁"NOR"】";
	else
	return NOR "【"HIR" 狂  魔 "NOR"】";
 }else

                        switch(ob->query("class")) {
                        case "bonze":
  
                             if (budd >= 150)
                                return HIY "【 神  尼 】" NOR;
                             else if (budd >= 120)
                                return HIY "【 圣  尼 】" NOR;
                             else if (budd >= 90)
                                return HIY "【 德  尼 】" NOR;
                             else if (budd >= 60)
                                return HIC "【 贤  尼 】" NOR;
                             else if (budd >= 30)
                                return HIG "【 比丘尼 】" NOR;
                             else if (age <= 16)
                                return HIW "【 沙弥尼 】" NOR;
                             else
                                return HIW "【 学戒女 】" NOR;
                        case "taoist":
                        if (budd >= 180) return HIW "【 玄  女 】" NOR;
                        else if (budd >= 140) return HIY "【 仙  姑 】" NOR;
                        else if (budd >= 100) return YEL "【 散  人 】" NOR;
                        else if (budd >= 50 || age >= 20) return YEL "【 道  姑 】" NOR;
                        else return "【 小道姑 】"; 
                        case "bandit":
                                return HIW "【 女飞贼 】" NOR;
                        case "dancer":
                                return HIW "【绝色舞姬】" NOR;
                        case "scholar":
                             if (age <= 16)
                                return HIW "【 女学童 】" NOR;
                             else if (age <= 30)
                                return HIW "【遥遥佳人】" NOR;
                             else
                                return HIW "【 女学士 】" NOR;
                        case "officer":
                                return HIW "【 女  官 】" NOR;
                        case "fighter":
                                return HIW "【 女武者 】" NOR;
                        case "swordsman":
                        if (exp>= 1000000) return HIR "【 剑  圣 】" NOR;
                        else if (exp>= 800000) return HIY "【 剑  仙 】" NOR;
                        else if (exp>= 700000) return HIC "【 女剑侠 】" NOR;
                        else if (exp>= 500000 )  return YEL "【 女剑客 】" NOR; 
                        else return "【 女剑士 】";
                        case "alchemist":
                                return HIW "【 女方士 】" NOR;
                        case "shaman":
                                return HIW "【 女巫医 】" NOR;
                        case "beggar":
                                return HIW "【 女叫化 】" NOR;
                        case "prostitute":
                                return HIW "【 妓  女 】" NOR;
			    case "mr":
                                return HIB "【 慕容世家 】" NOR;
			    case "tiezhang":
                                return HIY "【 铁掌弟子 】" NOR;
                        default:
                        if (((int)ob->query("PKS") > 100) &&
                            ((int)ob->query("PKS") > (int)ob->query("MKS")))
                                return HIR "【饮血女魔】" NOR;
                        if ((int)ob->query("thief") > 10 )
                                return HIC "【女 惯 窃】" NOR;
                       if (shen >= 1000000) return HIC "【绝世天娇】" NOR;
                        else if (shen >= 100000 && exp >=800000)
                                return HIM "【旷世女侠】" NOR;
                        else if (shen >= 10000 && exp >=400000)
                                return HIG "【巾帼英雄】" NOR;
                        else if (shen >= 1000 && exp >=200000)
                                return HIY "【女中豪杰】" NOR;
                        else if (shen >= 100 && exp >=50000)
                                return CYN "【风尘侠女】" NOR;
                        if (shen <= -1000000) return HIR "【盖世罗刹】" NOR;
                        else if (shen <= -100000 && exp >=800000)
                                return HIG "【旷世女魔】" NOR;
                        else if (shen <= -10000 && exp >=400000)
                                return CYN "【嗜血女魔】" NOR;
                        else if (shen <= -1000 && exp >=200000)
                                return HIY "【饮血魔女】" NOR;
                        else if (shen <= -100 && exp >=50000)
                                return CYN "【刁蛮恶女】" NOR;
                                if (age <= 16)
                                    return HIC "【妙龄少女】" NOR;
                                else
                                    return HIM "【芊芊民女】" NOR;
                        }
                        if (((int)ob->query("PKS") > 100) &&
                            ((int)ob->query("PKS") > (int)ob->query("MKS")))
                                return HIR "【饮血女魔】" NOR;
                        if ((int)ob->query("thief") > 10 )
                                return HIC "【女 惯 窃】" NOR;
                       if (shen >= 1000000) return HIC "【绝世天娇】" NOR;
                        else if (shen >= 100000 && exp >=800000)
                                return HIM "【旷世女侠】" NOR;
                        else if (shen >= 10000 && exp >=400000)
                                return HIG "【巾帼英雄】" NOR;
                        else if (shen >= 1000 && exp >=200000)
                                return HIY "【女中豪杰】" NOR;
                        else if (shen >= 100 && exp >=50000)
                                return CYN "【风尘侠女】" NOR;
                        if (shen <= -1000000) return HIR "【盖世罗刹】" NOR;
                        else if (shen <= -100000 && exp >=800000)
                                return HIG "【旷世女魔】" NOR;
                        else if (shen <= -10000 && exp >=400000)
                                return CYN "【嗜血女魔】" NOR;
                        else if (shen <= -1000 && exp >=200000)
                                return HIY "【饮血魔女】" NOR;
                        else if (shen <= -100 && exp >=50000)
                                return CYN "【刁蛮恶女】" NOR;
                }
        default:
                switch(wizhood(ob)) {
                case "(admin)":
                        return HIM "【 天  帝 】" NOR;
                case "(arch)":
                        return HIY "【 大  神 】" NOR;
                case "(wizard)":
                        return HIG "【 神  仙 】" NOR;
                case "(apprentice)":
                        return HIC "【 散  仙 】" NOR;
                case "(immortal)":
                        return HIC "【 半  仙 】" NOR;
                default:
/*if (!ob->query("class") || !family){
                        if (shen >= 1000000) return HIC "【绝世神侠】" NOR;
                        else if (shen >= 100000 && exp >=800000)
                                return HIC "【旷世大侠】" NOR;
                        else if (shen >= 10000 && exp >=400000)
                                return HIC "【江湖豪杰】" NOR;
                        else if (shen >= 1000 && exp >=200000)
                                return HIC "【武林新秀】" NOR;
                        else if (shen >= 100 && exp >=50000)
                                return HIC "【小有侠义】" NOR;
                        else if (shen <= -1000000) return HIR "【盖世狂魔】" NOR;
                        else if (shen <= -100000 && exp >=800000)
                                return HIC "【混世魔王】" NOR;
                        else if (shen <= -10000 && exp >=400000)
                                return HIC "【恶霸一方】" NOR;
                        else if (shen <= -1000 && exp >=200000)
                                return HIC "【恶名远扬】" NOR;
                        else if (shen <= -100 && exp >=50000)
                                return HIC "【小有恶名】" NOR;
                        else
                        if (((int)ob->query("PKS") > 100) &&
                            ((int)ob->query("PKS") > (int)ob->query("MKS")))
                                return HIR "【 杀人魔 】" NOR;
                        if ((int)ob->query("thief") > 10 )
                                return HIC "【 惯  窃 】" NOR;
}
                        else*/
 if (family=="日月神教")
 {
                       if (exp>= 1000000) return HIW "【 副教主 】" NOR;
                       if (exp>= 800000 ) return HIW "【 左护法 】" NOR;
                       if (exp>= 700000) return HIY "【 堂  主 】" NOR;
                       if (exp>= 600000)  return HIY "【 坛  主 】" NOR;
                       if (exp>= 50000) return YEL "【 香  主 】" NOR;
                       if (exp>= 30000 || age >= 20) return CYN "【 教  众 】" NOR;
                       return CYN "【 教  徒 】" NOR;
 }else
 if (family=="逍遥派" || family=="桃花岛")
 {
                       if (exp>= 1000000 && shen >= 0) return HIW "【 隐  圣 】" NOR;
                       if (exp>= 1000000 && shen < 0) return HIW "【 隐  贤 】" NOR;
                       if (exp>= 700000) return HIY "【 隐  贤 】" NOR;
                       if (exp>= 600000)  return HIY "【 隐  士 】" NOR;
                       if (exp>= 50000) return YEL "【 隐  士 】" NOR;
                       if (exp>= 30000 || age >= 20) return CYN "【 门  生 】" NOR;
                       return CYN "【多情剑客】" NOR;
 }else
 if (family=="铁掌帮")
 {
                       if (exp>= 1000000 && shen >= 0) return HIW "【 山大王 】" NOR;
                       if (exp>= 1000000 && shen < 0) return HIW "【 寨  主 】" NOR;
                       if (exp>= 700000) return HIY "【 寨  主 】" NOR;
                       if (exp>= 600000)  return HIY "【 当  家 】" NOR;
                       if (exp>= 50000) return YEL "【 当  家 】" NOR;
                       if (exp>= 30000 || age >= 20) return CYN "【 头  目 】" NOR;
                       return CYN "【 小喽罗 】" NOR;
 }else
 if (family=="古墓派" || family=="华山派" || family=="凌霄城")
 {
                       if (exp>= 2000000 && shen > 0) return HIW "【惊天一剑】" NOR;
                       else if (exp>= 2000000 && shen < 0) return HIW "【惊魔一剑】" NOR;
                        else 
                        if (exp>= 1000000) return HIR "【 剑  宗 】" NOR;
                        else if (exp>= 800000) return HIY "【 剑  狂 】" NOR;
                        else if (exp>= 700000) return HIC "【 剑  侠 】" NOR;
                        else if (exp>= 500000 )  return YEL "【 剑  客 】" NOR; 
                        else return "【 剑  士 】";
 }else
 if (family=="雪山寺")
 {
                       if (exp>= 1000000 && shen >= 0) return HIW "【 欢喜佛 】" NOR;
                       if (exp>= 1000000 && shen < 0) return HIW "【 欢喜魔 】" NOR;
                       if (exp>= 700000) return HIY "【 天  王 】" NOR;
                       if (exp>= 600000)  return HIY "【 大护法 】" NOR;
                       if (exp>= 50000) return YEL "【 金  刚 】" NOR;
                       if (exp>= 30000 || age >= 20) return CYN "【 力  士 】" NOR;
                       return CYN "【 杂  役 】" NOR;
 }else
 if (family=="姑苏慕容" || family=="大理段家")
 {
                        if (exp>= 1000000) return HIR "【 亲  王 】" NOR;
                        else if (exp>= 800000) return HIY "【 侯  爷 】" NOR;
                        else if (exp>= 700000) return HIC "【 将  官 】" NOR;
                        else if (exp>= 500000 )  return YEL "【 侍  卫 】" NOR; 
                        else if ( age >= 18)  return CYN "【 校  尉 】" NOR; 
                        else return "【 兵  士 】";
 }
 else
  if (family=="明教")
 {
 						if (exp>10000000)
								return NOR "【"HIR"副 教 主"NOR"】";
						if (exp>5000000)
								return NOR "【"HIM" 法  王 "NOR"】";
						if (exp>1000000)
								return NOR "【"GRN"总 护 法"NOR"】";
						if (exp>500000)
								return NOR "【"YEL" 护  法 "NOR"】";
						if (exp>300000)
								return NOR "【"YEL"总 堂 主"NOR"】";
						if (exp>100000)
								return NOR "【"CYN"副 堂 主"NOR"】";
						if (exp>25000)
								return NOR "【"CYN" 旗  主 "NOR"】";
						if (exp>10000)
								return NOR "【"GRN"副 旗 主"NOR"】";
						if (exp>5000)
								return NOR "【"HIB" 教  众 "NOR"】";
						return "【 教  众 】" ;

 }else
  if (family=="云龙门")
 {
                        return HIG"【江湖义士】"NOR;
 }
 else
  if (family=="星宿派")
 {
						if (exp>10000000)
								return NOR "【"HIR"毒   尊"NOR"】";
						if (exp>5000000)
								return NOR "【"HIM"毒   霸"NOR"】";
						if (exp>1000000)
								return NOR "【"GRN"毒   君"NOR"】";
						if (exp>500000)
								return NOR "【"YEL"毒  王 "NOR"】";
						if (exp>300000)
								return NOR "【"YEL"毒  魔 "NOR"】";
						if (exp>100000)
								return NOR "【"CYN"毒   魔"NOR"】";
						if (exp>25000)
								return NOR "【"CYN"毒   魔"NOR"】";
						if (exp>10000)
								return NOR "【"MAG"毒   魔"NOR"】";
						if (exp>5000)
								return NOR "【"MAG"毒   魔"NOR"】";
						return "【  法螺王  】" ;
 }else
  if (family=="五毒教")
 {
						if (exp>10000000)
								return NOR "【"HIR"毒   尊"NOR"】";
						if (exp>5000000)
								return NOR "【"HIM"毒   霸"NOR"】";
						if (exp>1000000)
								return NOR "【"GRN"毒   君"NOR"】";
						if (exp>500000)
								return NOR "【"YEL"毒  王 "NOR"】";
						if (exp>300000)
								return NOR "【"YEL"毒  魔 "NOR"】";
						if (exp>100000)
								return NOR "【"CYN"毒   魔"NOR"】";
						if (exp>25000)
								return NOR "【"CYN"毒   魔"NOR"】";
						if (exp>10000)
								return NOR "【"MAG"毒   魔"NOR"】";
						if (exp>5000)
								return NOR "【"MAG"毒   魔"NOR"】";						return "【  女教众  】" ;
						return "【  男教众  】" ;
 }else
  if (family=="白驼山派")
 {
	if (shen >= 0)
	return NOR "【"HIR"魔 见 愁"NOR"】";
	else
	return NOR "【"HIR" 狂  魔 "NOR"】";
 }else
                                 switch(ob->query("class")) {
                                case "bonze":
                       if (budd >= 180) return HIW "【 神  僧 】" NOR;
                      else if (budd >= 150) return WHT "【 长  老 】" NOR;
                      else if (budd >= 120) return HIY "【 圣  僧 】" NOR;
                      else if (budd >= 80) return HIY "【 罗  汉 】" NOR;
                      else if (budd >= 60) return YEL "【 尊  者 】" NOR;
                      else if (budd >= 40) return YEL "【 禅  师 】" NOR;
                      else if (budd >= 30) return YEL "【 比  丘 】" NOR;
                      return "【 僧  人 】";
                                 case "taoist":
                                        if (ob->query_skill("taoism",1) >= 180) return HIW "【 天  尊 】" NOR;
                                        else if (ob->query_skill("taoism",1) >= 140) return HIY "【 天  师 】" NOR;
                                        else if (ob->query_skill("taoism",1)>100)
                                           return HIW "【 真  人 】" NOR;
                                        else if (age <= 16)
                                           return HIW "【 小道士 】" NOR;
                                        else if (age <= 30)
                                           return HIW "【 道  士 】" NOR;
                                        else
                                           return HIW "【 道  长 】" NOR;
                                case "bandit":
                                 if (exp>= 1000000) return HIC "【 寨  主 】" NOR;
                                 if (exp>= 600000) return CYN "【 当  家 】" NOR;
                                 if (exp>= 100000 || age >= 18)  return CYN "【 头  目 】" NOR; 
                                 return "【 小喽罗 】"; 
                                case "scholar":
                                     if (age <= 16)
                                        return HIW "【 学  童 】" NOR;
                                     else if (age <= 45)
                                        return HIW "【 书  生 】" NOR;
                                     else
                                        return HIW "【 老秀才 】" NOR;
                                case "officer":
                                        return HIW "【 官  差 】" NOR;
                                case "fighter":
                                        return HIW "【 武  者 】" NOR;
                                case "swordsman":
                                if (exp>= 1000000) return HIR "【 剑  宗 】" NOR;
                                if (exp>= 800000) return HIY "【 剑  狂 】" NOR;
                                if (exp>= 500000) return HIC "【 剑  侠 】" NOR;
                                if (exp>= 100000 || age >= 18) return YEL "【 剑  客 】" NOR;
                                return "【 剑  士 】";
                                case "alchemist":
                                        return HIW "【 方  士 】" NOR;
                                case "shaman":
                                        return HIW "【 巫  医 】" NOR;
                                case "mr":
                                return HIB "【 慕容世家 】" NOR;
			            case "tiezhang":
                                return HIY "【 铁掌弟子 】" NOR;
			        	case "beggar":
                                if (exp>= 2000000) return HIW "【 神  丐 】" NOR;
                                else if (exp>= 1000000 && ob->query("shen") >= 0 ) return HIC "【 义  丐 】" NOR;
                                else if (exp>= 1000000 && ob->query("shen") < 0 ) return HIR "【 恶  丐 】" NOR;
                                else if (exp>= 600000) return HIC "【 舵  主 】" NOR;
                                else if (exp>= 200000) return CYN "【 龙  头 】" NOR;
                                else if ( age >= 18)  return CYN "【 叫化子 】" NOR; 
                                else return "【 小乞丐 】";
                                case "eunach":
                                        budd = ob->query_skill("pixie-jian",1);
                                        if (budd >= 110)
                                                return HIY "【大内高手】" NOR;
                                        else if (budd >= 100)
                                                return HIY "【东厂万户】" NOR;
                                        else if (budd >= 90)
                                                return HIY "【东厂千户】" NOR;
                                        else if (budd >= 80)
                                                return HIY "【东厂百户】" NOR;
                                        else if (budd >= 70)
                                                return HIY "【东厂十户】" NOR;
                                        else if (budd >= 60)
                                                return HIY "【东厂公公】" NOR;
                                        else return HIW "【 内  侍 】" NOR;
                                case "prostitute":
                                        return HIM "【 龟  公 】" NOR;
                                default:
                        if (shen >= 1000000) return HIC "【绝世神侠】" NOR;
                        else if (shen >= 100000 && exp >=800000)
                                return HIC "【旷世大侠】" NOR;
                        else if (shen >= 10000 && exp >=400000)
                                return HIG "【江湖豪杰】" NOR;
                        else if (shen >= 1000 && exp >=200000)
                                return HIY "【武林新秀】" NOR;
                        else if (shen >= 100 && exp >=50000)
                                return CYN "【小有侠义】" NOR;
                        else if (shen <= -1000000) return HIR "【盖世狂魔】" NOR;
                        else if (shen <= -100000 && exp >=800000)
                                return RED "【混世魔王】" NOR;
                        else if (shen <= -10000 && exp >=400000)
                                return HIG "【恶霸一方】" NOR;
                        else if (shen <= -1000 && exp >=200000)
                                return HIY "【恶名远扬】" NOR;
                        else if (shen <= -100 && exp >=50000)
                                return BLU "【小有恶名】" NOR;
                        else
                        if (((int)ob->query("PKS") > 100) &&
                            ((int)ob->query("PKS") > (int)ob->query("MKS")))
                                return HIR "【 杀人魔 】" NOR;
                        if ((int)ob->query("thief") > 10 )
                                return HIC "【 惯  窃 】" NOR;
                                        if (age < 18) return HIC"【玉冠少年】"NOR;
                                        else if (age < 30) return HIG"【翩翩才子】"NOR;
                                        else if (age < 50) return HIB"【武林豪杰】"NOR;
                                        else
                                            return HIM "【江湖豪杰】" NOR;
                                }
                        if (shen >= 1000000) return HIC "【绝世神侠】" NOR;
                        else if (shen >= 100000 && exp >=800000)
                                return HIC "【旷世大侠】" NOR;
                        else if (shen >= 10000 && exp >=400000)
                                return HIG "【江湖豪杰】" NOR;
                        else if (shen >= 1000 && exp >=200000)
                                return HIY "【武林新秀】" NOR;
                        else if (shen >= 100 && exp >=50000)
                                return CYN "【小有侠义】" NOR;
                        else if (shen <= -1000000) return HIR "【盖世狂魔】" NOR;
                        else if (shen <= -100000 && exp >=800000)
                                return RED "【混世魔王】" NOR;
                        else if (shen <= -10000 && exp >=400000)
                                return HIG "【恶霸一方】" NOR;
                        else if (shen <= -1000 && exp >=200000)
                                return HIY "【恶名远扬】" NOR;
                        else if (shen <= -100 && exp >=50000)
                                return BLU "【小有恶名】" NOR;
                        else
                        if (((int)ob->query("PKS") > 100) &&
                            ((int)ob->query("PKS") > (int)ob->query("MKS")))
                                return HIR "【 杀人魔 】" NOR;
                        if ((int)ob->query("thief") > 10 )
                                return HIC "【 惯  窃 】" NOR;
                }
        }
}

string query_respect(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/respect")) )
                return str;

	if(ob->query("race") != "人类") return ob->name();

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
                                else if( age < 30 ) return "姑娘";
                                else if( age < 40 ) return "大婶";
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
                        case "scholar":
                                if( age < 18 ) return "小相公";
                                else if( age < 50 ) return "相公";
                                else return "老先生";
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
                                if( age < 18 ) return "小贼尼";
                                if( age < 30 ) return "贼尼";
                                else return "老贼尼";
                                break;
                        case "taoist":
                                if( age < 18 ) return "小妖女";
                                if( age < 30 ) return "妖女";
                                else return "老妖婆";
                                break;
                        default:
                                if( age < 18 ) return "小娘皮";
                                if( age < 25 ) return "小贱人";
                                if( age < 40 ) return "贼婆娘";
                                else return "死老太婆";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "小贼秃";
                                if( age < 50 ) return "死秃驴";
                                else return "老秃驴";
                                break;
                        case "taoist":
                                if( age < 18 ) return "小杂毛";
                                if( age < 30 ) return "死牛鼻子";
                                else return "老杂毛";
                                break;
                        case "scholar":
                                if( age < 18 ) return "小书呆子";
                                else if( age < 50 ) return "臭书呆子";
                                else return "老童生";
                                break;
                        default:
                                if( age < 20 ) return "小王八蛋";
                                if( age < 30 ) return "直娘贼";
                                if( age < 50 ) return "臭贼";
                                if( age < 80 ) return "老匹夫";
                                else return "老不死";
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
                        case "taoist":
                                return "贫道";
                                break;
                        default:
                                if( age < 20 ) return "小女子";
                                if( age > 50 ) return "老身";
                                else return "妾身";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "小衲";
                                if( age < 40 ) return "贫僧";
                                else return "老衲";
                                break;
                        case "taoist":
                                if( age < 18 ) return "小道";
                                if( age < 30 ) return "贫道";
                                else return "老道";
                                break;
                        case "scholar":
                                if( age < 30 ) return "晚生";
                                else return "不才";
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
                        case "taoist":
                                return "本仙姑";
                                break;
                        default:
                                if( age < 20 ) return "本姑娘";
                                if( age < 30 ) return "本姑奶奶";
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
                                if( age < 30 ) return "本山人";
                                return "老道我";
                                break;
                        case "scholar":
                                if( age < 50 ) return "本相公";
                                else return "老夫子我";
                                break;
                        default:
                                if( age < 20 ) return "本少爷我";
                                if( age < 40 ) return "大爷我";
                                else return "老子";
                                break;
                        }
        }
}
string query_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = (int)ob->query("mud_age"))
                {
                        a1 = this_player()->query("mud_age");
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

        switch (ob->query("gender")) {
        case "女性" :

                if (a2 - a1 >= 24) return "姑姑";
                else if (a1 - a2 >= 24) return "侄女";
                else if (a1 >= a2) return "贤妹";
                else  return "姐姐";
                break;
        default :
                if (a2 - a1 >= 24) return "叔叔";
                else if (a1 - a2 >= 24) return "贤侄";
                else if (a1 >= a2) return "贤弟";
                else  return "哥哥";
        }
}

string query_self_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = (int)ob->query("mud_age"))
                {
                        a1 = this_player()->query("mud_age");
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

        switch (this_player()->query("gender")) {
        case "女性" :
                if (a1 - a2 >= 24) return "姑姑我";
                else if (a2 - a1 >= 24) return "侄女我";
                else if (a1 >= a2) return "姐姐我";
                else return "小妹我";
                break;
        default :
                if (a1 - a2 >= 240) return "叔叔我";
                else if (a2 - a1 >= 240) return "小侄我";
                else if (a1 >= a2) return "愚兄我";
                else return "小弟我";
        }
}

