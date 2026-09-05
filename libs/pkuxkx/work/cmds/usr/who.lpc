// who.c
// modified by banny
// 在who时分清了巫师与玩家，另外who -l时也知道其他人是否在发呆。
// Modified by iszt@pkuxkx, 2007-03-27, removed idle prompt.
// Modified by iszt@pkuxkx, 2007-04-25, added -p -m -f -tj -a

#include <net/dns.h>
#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_MORE;
int filter_ip(string myipfrom,string youripfrom);
void create() { seteuid(getuid()); }

mapping party=([
	"shaolin":	"少林派",
	"wudang":	"武当派",
	"gaibang":	"丐帮",
	"baituo":	"白驼山",
	"xingxiu":	"星宿派",
	"huashan":	"华山派",
	"emei":		"峨嵋派",
	"mingjiao":	"明教",
	"riyue":	"日月神教",
	"gumu":		"古墓派",
	"lingjiu":	"灵鹫宫",
	"quanzhen":	"全真派",
	"tianlong":	"天龙寺",
	"taohua":	"桃花岛",
	"murong":	"姑苏慕容",
	"chaoting":	"朝廷",
	"tiandihui":	"天地会",
	"shenlong":	"神龙教",
	"dalunsi":	"大轮寺",
	"xueshan":	"雪山派",
	"dongchang": "东厂",
]);

string *menpai=({	"白驼山", "朝廷", "峨嵋派", "大轮寺", "东厂", "丐帮",
	                "古墓派", "华山派", "灵鹫宫", "明教", "姑苏慕容",
	                "全真派", "日月神教", "少林派", "神龙教", "桃花岛",
	              "天地会", "天龙寺", "武当派", "星宿派", "雪山派", "无门派", "巫师"});


string opt_party;
string myip_from;

mixed main(object me, string arg, int remote)
{
	string str, name, str1, *option;
	object *ob, *list;
	int i, j, ppl_cnt, wiz_cnt, total_cnt, idle, all_menpai, tab;
	int opt_long, opt_wiz, opt_male, opt_female, opt_taijian, opt_number, opt_ip,opt_pro, opt_realuser, opt_xiuxian, opt_newguider,opt_craftman,*tmp, *tmp2;

        if(!wizardp(me) && time()-me->query_temp("scan_time") < 5)
		return notify_fail("等等，系统喘气中......\n");
        me->set_temp("scan_time",time());
	opt_party = "null";
	
	if( arg )
	{
		option = explode(arg, " ");
		i = sizeof(option);
		while( i-- )
			switch(option[i])
			{
			case "-l": opt_long = 1; break;
			case "-w": opt_wiz = 1; break;
			case "-p": opt_party = me->query("family/family_name"); break;
			case "-m": opt_male = 1; break;
			case "-f": opt_female = 1; break;
			case "-tj": opt_taijian = 1; break;
			case "-a": opt_number = 1; break;
			case "-i": opt_ip = 1; break;
      case "-v": opt_realuser = 1;break;
      case "-g": opt_newguider = 1; break;
      case "-x": opt_xiuxian=1;break;
			case "-c": opt_craftman = 1; break;
			case "-pro": opt_pro = 1; break;
			default:
				if (option[i][0] == '-' && !undefinedp(party[option[i][1..<1]]))
					opt_party = party[option[i][1..<1]];
				else
					return notify_fail("请用help who查看指令格式。\n");
			}
	}

	if( opt_long )
		if(!wizardp(me))
		{
			if( (int)me->query("qi") < 30 )
				return notify_fail("你的精神太差了，没有办法得知其他玩家的详细资料。\n");
			me->receive_damage("qi", 30);
		}

	str = HIY"◎ "NOR"「" +HIC+ MUD_NAME + NOR + "」";
	if(opt_party != "null")
		if(opt_party)
			str += opt_party;
		else
			str += "无门派";
	str += "在线";
	if(opt_male)
		str += "男性";
	else if(opt_female)
		str += "女性";
	else if(opt_taijian)
		str += "太监";
	else if(opt_pro)
		str += "101级+高手";
	else if(opt_craftman)
		str += "职业工匠";
	else if (opt_realuser)
		str +="实名玩家";
  else if (opt_xiuxian)
    str +="休闲玩家";
	else if (opt_newguider)
		str +="玩家导师";
	if (opt_ip)
		str += "与『" + me->query_temp("ip_from/from1") + "』属同一地区的";
	
	if(opt_wiz)
		str += "巫师";
	else if ( !opt_realuser && !opt_xiuxian && !opt_newguider )
		str += "玩家";
	str += "：\n"NOR;

	str += "------------------------------------------------------------------------\n";

	ob = filter_array(children(USER_OB), (: userp :));
	ob = filter_array(ob, (: environment :));
	if(opt_party != "null")
		ob = filter_array(ob, (: $1->query("family/family_name") == opt_party :) );
	if(opt_male)
		ob = filter_array(ob, (: $1->query("gender") == "男性" :) );
	if(opt_female)
		ob = filter_array(ob, (: $1->query("gender") == "女性" :) );
	if(opt_taijian)
		ob = filter_array(ob, (: $1->query("gender") == "无性" :) );
	if(opt_pro)
		ob = filter_array(ob, (: $1->query("level") >100 :) );
	if(opt_craftman)
		ob = filter_array(ob, (: F_PRO->pro_class($1)!="fighter" :) );
	if (opt_realuser)
		ob = filter_array(ob, (: $1->is_realuser() :) );
  if (opt_xiuxian)
    ob = filter_array(ob, (: $1->query("xiuxian_player") :) );
	if (opt_newguider)
		ob = filter_array(ob, (: SECURITY_D->get_status($1) == "(guider)" :) );
	if(opt_ip) {
		myip_from = me->query_temp("ip_from/from1");
		ob = filter_array(ob, (: filter_ip(myip_from,$1->query_temp("ip_from/from1")) && !$1->query("env/no_ip")  :) );
	}
	if( opt_number )
	{
		list = children(USER_OB);
		j = sizeof(list);
		while(j--)
		{
			if( !environment(list[j]) ) continue;
			if( !me->visible(list[j]) ) continue;
			if (list[j]->query("noDeadNetnoIdle") != "Pkuxkx" && list[j]->query_temp("netdead")) continue;
			if( wizardp(list[j]) )
				wiz_cnt++;
			else
				ppl_cnt++;
		}		
	}
	else if( opt_long || opt_wiz )
	{
		if (!opt_craftman)
		list = sort_array(ob,"sort_family");
		else list=sort_array(ob,"sort_user");
		j = sizeof(list);
		while( j-- ) 
		{
			// Skip those users in login limbo.
			if( !environment(list[j]) ) continue;
			if( !me->visible(list[j]) ) continue;
			if (list[j]->query("noDeadNetnoIdle") != "Pkuxkx" && list[j]->query_temp("netdead")) continue;
			if( wizardp(list[j]) )
				wiz_cnt++;
			else
				ppl_cnt++;
			if( opt_wiz && (!wizardp(list[j]) )) continue;
			if ( !list[j]->query("id") )
			  str = sprintf("%s%12s%s(档案出错)",
				str,
				RANK_D->query_rank(list[j]),
				list[j]->name()
			);
		  else
			str = sprintf("%s%12s%s",
				str,
				RANK_D->query_rank(list[j]),
				list[j]->short()
			);
			str+="\n";
		}
	}
	else {
		list = sort_array(ob,"sort_user");
				
		all_menpai = sizeof(menpai);
		tmp = allocate(all_menpai);
		tmp2 = allocate(all_menpai);
		str1 = "";
		
		for(i = 0; i < all_menpai; i++)
		{
			j = sizeof(list);
			
		while( j-- ) {
			// Skip those users in login limbo.
			if( !environment(list[j]) ) continue;
			if( me && !me->visible(list[j]) ) continue;
			if(opt_wiz && !wizardp(list[j]) ) continue;
            //if(opt_realuser && (!list[j]->is_realuser())) continue;
            //if(opt_newguider && SECURITY_D->get_status(list[j]) != "(guider)") continue;//防止前面的filter里判断了，否则 -l参数会失败 Zine 2013/2/10            
			if (list[j]->query("noDeadNetnoIdle") != "Pkuxkx" && list[j]->query_temp("netdead")) continue;
				
				if( ((i < all_menpai - 2) && list[j]->query("family/family_name") == menpai[i] && !wizardp(list[j])) 
					|| ((i == all_menpai - 2) && !list[j]->query("family") && !wizardp(list[j]))
					|| ((i == all_menpai - 1) && wizardp(list[j])) )
					{
      			name = list[j]->name() + "(";
      			if(!wizardp(list[j]))
      				if(list[j]->query("gender")=="男性")
      					name += CYN;
      				else if(list[j]->query("gender")=="女性")
      					name += MAG;
      				else
      					name += YEL;
      			else
      				name += HIB;
      			if (!list[j]->query("id"))
      				name += capitalize("档案出错")+NOR+")";
      			else
      				name += capitalize(list[j]->query("id"))+NOR+")";
					}
					else continue;
			
			if(!wizardp(list[j]))
				{
					ppl_cnt++;
					tmp[i]++;
				}
			else
				{
					wiz_cnt++;
					tmp2[i]++;
				}

            tab = 24+COLOR_D->color_len(name);
			if(i <= all_menpai - 2)
			str1 = sprintf("%s%-"+tab+"s%s", str1, name,
				//((tmp[i])%3==0? "\n": (strwidth(list[j]->name()+list[j]->query("id"))>13?"\t":"\t\t"))
                  ((tmp[i])%3==0? "\n": "")
			);
			else
			str1 = sprintf("%s%-"+tab+"s%s", str1, name,
				//((tmp2[i])%3==0? "\n": (strwidth(list[j]->name()+list[j]->query("id"))>13?"\t":"\t\t"))
                  ((tmp2[i])%3==0? "\n": "")
			);
		}
			if( tmp[i]%3 ) str1 += "\n";
									
		if (tmp[i] > 0) 			
				str += HBGRN + menpai[i] + "(在线" + tmp[i] + "人)"+ NOR"\n" + str1 + "\n";
		if (tmp2[i] > 0)
				str += HBGRN + menpai[i] + "(在线" + tmp2[i] + "人)"+ NOR"\n" + str1 + "\n";
			

		str1 = "";

	}
}

	str += "------------------------------------------------------------------------\n";
	if (opt_wiz)
		str = sprintf("%s共列出 %d 位巫师，系统负担：%s",
			str, wiz_cnt, query_load_average() + "\n");
	else
		str = sprintf("%s共列出 %d 位玩家和 %d 位巫师，系统负担：%s",
			str, ppl_cnt, wiz_cnt, query_load_average() + "\n");

	if(opt_number)
		str = sprintf(HIC"「%s」"NOR+WHT"共有 %d 位玩家和 %d 位巫师连线中，系统负担：%s"NOR,
			MUD_NAME + HIC, ppl_cnt, wiz_cnt, query_load_average() + "\n");
	if(opt_long)
		me->start_more(str);
	else
//                write(str);
                start_more(str);
	return 1;
}
int sort_craftman(object ob1,object ob2)
{
	mapping craft_id=(["alchemy":1,"herbalism":2,"smithing":3,"mining":4]);
	if (F_PRO->pro_class(ob1)!=F_PRO->pro_class(ob2))
	return craft_id[F_PRO->pro_class(ob2)]-craft_id[F_PRO->pro_class(ob1)];
	else
	return ob2->query_skill(F_PRO->pro_class(ob2),1)-ob1->query_skill(F_PRO->pro_class(ob1),1);
}
int sort_user(object ob1, object ob2)
{
	if (F_PRO->pro_class(ob1)!="fighter"&&F_PRO->pro_class(ob2)!="fighter")
		return sort_craftman(ob1,ob2);
	if( wizardp(ob1) && !wizardp(ob2) )
		return -1;
	
	if( wizardp(ob2) && !wizardp(ob1) )
		return 1;

	if( wizardp(ob1) && wizardp(ob2) )
		return (int)SECURITY_D->get_wiz_level(ob2) 
			- (int)SECURITY_D->get_wiz_level(ob1);

	if( ob1->query("id") && !ob2->query("id") )
		return -1;
	if( ob2->query("id") && !ob1->query("id") )
		return 1;
	if( !ob1->query("id") && !ob2->query("id") )
		return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
	return strcmp(ob2->query("id"), ob1->query("id"));
}

int sort_family(object ob1, object ob2)
{
	string name1, name2;
	int wizlev1,wizlev2;
	wizlev1 = wiz_level(ob1); 
	wizlev2 = wiz_level(ob2);

	if (wizlev1 != wizlev2)
		return wiz_level(ob2)
			- wiz_level(ob1);
	
	name1 = ob1->query("family/family_name");
	name2 = ob2->query("family/family_name");
    
	if (intp(name1)) name1 = "";
	if (intp(name2)) name2 = "";
	if (name1 > name2) return -1;
	if (name1 < name2) return 1;
    if ((int)ob1->query("family/generation")&&(int)ob2->query("family/generation")&&(int)ob1->query("family/generation")!=(int)ob2->query("family/generation"))//希望增加门派荣誉感，先按辈份排，同辈再按exp排
    {
		if (name1=="少林派"&&((ob1->query("family/generation")==2&&ob2->query("family/generation")==3)||(ob1->query("family/generation")==3&&ob2->query("family/generation")==2)))
		return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
		else
		return (int)ob1->query("family/generation")-(int)ob2->query("family/generation");
    }
	if (ob2->query("pin")&&ob1->query("pin")&&(int)ob1->query("pin")!=(int)ob2->query("pin"))
    return (int)ob1->query("pin")-(int)ob2->query("pin");
    if ((ob2->query("chaoting/wang")||ob1->query("chaoting/wang"))&&ob2->query("chaoting/wang")!=ob1->query("chaoting/wang"))
    return (int)ob2->query("chaoting/wang")-(int)ob1->query("chaoting/wang");
    if ((ob2->query("chaoting/jiawang")||ob1->query("chaoting/jiawang"))&&ob2->query("chaoting/jiawang")!=ob1->query("chaoting/jiawang"))
    return (int)ob2->query("chaoting/jiawang")-(int)ob1->query("chaoting/jiawang");
	return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}

int filter_ip(string myipfrom,string youripfrom)
{
	string longipfrom,shortipfrom;
	
	if (myipfrom == youripfrom)
		return 1;
	if (myipfrom && youripfrom)
	{
		if (myipfrom[0..5]=="北京市" && youripfrom[0..5]=="北京市")
			return 1;
		if (myipfrom[0..5]=="上海市" && youripfrom[0..5]=="上海市")
			return 1;		
		if (myipfrom[0..11]==youripfrom[0..11])
			return 1;				
	}
	if (sizeof(myipfrom)>sizeof(youripfrom))
	{
		longipfrom = myipfrom;
		shortipfrom = youripfrom;
	} else if(sizeof(myipfrom) < sizeof(youripfrom))
	{
		longipfrom = youripfrom;
		shortipfrom = myipfrom;
	} else return 0;
	if (strsrch(longipfrom,shortipfrom)>=0)
		return 1;
	return 0;
} 		
int help(object me)
{
	write(@HELP
指令格式 : who [-l|-w]

这个指令可以列出在线的玩家及其部分信息。

-l	列出较详细的讯息。
-w	列出线上没有隐身的巫师。
-p	列出同门派的玩家。
-m	列出游戏中的男玩家。
-f	列出游戏中的女玩家。
-tj	列出游戏中的无性玩家。
-a	只列出当前游戏中的总人数。
-i	列出与你同地区，且没有set no_ip的玩家。
-门派	列出该门派的玩家。
-v  仅列出通过实名认证的玩家。
-g  仅列出所有在线的新手导师。
-x  仅列出休闲玩家
-pro  仅列出所有在线100级以上的玩家。
-c  列出游戏中所有职业工匠。
参数可以组合，例如who -xingxiu -l -tj即可列出星宿派太监的详细讯息。

相关指令： finger
HELP
	);
	return 1;
}
