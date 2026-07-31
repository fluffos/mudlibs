// skills.c

#include <ansi.h>

inherit F_CLEAN_UP;
string *skill_level_desc = ({
	BLU "初学乍练" NOR,
	HIB "粗通皮毛" NOR,
	YEL "初窥门径" NOR,
	HIY "略知一二" NOR,
	HIB "渐有所悟" NOR,
	YEL "半生不熟" NOR,
	YEL "马马虎虎" NOR,
	HIY "平淡无奇" NOR,
	HIY "触类旁通" NOR,
	HIM "已有小成" NOR,
	HIG "心领神会" NOR,
	HIC "驾轻就熟" NOR,
	RED "了然於胸" NOR,
	HIG "挥洒自如" NOR,
	HIC "出类拔萃" NOR,
	CYN "初入佳境" NOR,
	MAG "威不可当" NOR,
	MAG "出神入化" NOR,
	RED "登峰造极" NOR,
	HIM "一代宗师" NOR,
	HIM "独步天下" NOR,
	HIR "旷古绝伦" NOR,
	HIW "震古铄今" NOR,
	WHT "超凡入圣" NOR,
	HIW "深不可测" NOR
	HIW "返璞归真" NOR,
});

string *knowledge_level_desc = ({
	BLU "新学乍用" NOR,
	BLU "不甚了了" NOR,
	HIB "不知端倪" NOR,
	HIB "平淡无奇" NOR,
	YEL "司空见惯" NOR,
	YEL "初窥门径" NOR,
	HIY "略知一二" NOR,
	HIY "茅塞顿开" NOR,
	CYN "略识之无" NOR,
	CYN "滚瓜烂熟" NOR,
	MAG "马马虎虎" NOR,
	MAG "轻车熟路" NOR,
	HIW "运用自如" NOR,
	HIW "触类旁通" NOR,
	HIM "深入浅出" NOR,
	HIM "已有小成" NOR,
	HIM "心领神会" NOR,
	RED "了然於胸" NOR,
	RED "见多识广" NOR,
	HIR "无所不通" NOR,
	HIR "卓尔不群" NOR,
	HIR "满腹经纶" NOR,
	WHT "豁然贯通" NOR,
	WHT "博古通今" NOR,
	WHT "博大精深" NOR,
	WHT "超群绝伦" NOR,
	WHT "举世无双" NOR,
	WHT "独步天下" NOR,
	HIW "震古铄今" NOR,
	HIW "超凡入圣" NOR,
	HIW "深不可测" NOR
});

string *valid_types = ({
	"force",
	"dodge",
	"unarmed",
	"cuff",
	"strike",
	"finger",
	"hand",
	"claw",
	"sword",
	"blade",
	"staff",
	"hammer",
	"club",
	"whip",
	"dagger",
	"throwing",
	"parry",
	"magic",
	"medical",
	"poison",
	"chuixiao-jifa",
	"tanqin-jifa",
	"guzheng-jifa",
	"cooking",

});
string skill_level(string, int);
int sort_skill(string sk1, string sk2, mapping spos);
int filter_for_enable(string skill, string skill1);
int filter_for_main(string skill, string skill1);
int filter_for_combine(string skill, string skill1);

int main(object me, string arg)
{
	object ob;
	mapping skl, lrn, map, pmap;
	string *sname, *mapped, *pmapped, str, mski,skill1, *huanshou_str;
	string skillname, skcolor;
	string *basic;
	string *spec;
	string *text;
	mixed  *lists;
	string *others;
	string fname,space;
	string pops;
	int valid_check;
	int cha_type;
	int lvl;
	int i, k,j,all,page;
	seteuid(getuid());
	skill1 = 0;

	if (! arg)
	{
		ob = me;
		page = 1;
	}
	else if (strlen(arg)<2&&sscanf(arg,"%d",page)==1)
	{
		ob = me;
	}
	else
	{
		string *temp;
		if (sscanf(arg, "%s of %s", skill1, arg) == 2)
			;
		else if (temp = explode(arg, " "))
		{
			if (sizeof(temp) < 2)
				arg = "me";
			else
				arg = implode(temp[0..sizeof(temp) - 2], " ");
			skill1 = temp[sizeof(temp) - 1];
			if(strlen(skill1)<2&&sizeof(temp)>2&&sscanf(skill1,"%d",page)==1)
			{
				skill1 = temp[sizeof(temp) - 2];
				arg = implode(temp[0..sizeof(temp) - 3], " ");
			}

			if (file_size(SKILL_D(skill1) + ".c") <= 0)
			{
				if (sizeof(temp) < 2)
					arg = skill1;
				else
					arg += " " + skill1;
				ob = present(arg, environment(me));
				skill1 = 0;
			}
		}
		else
		{
			if (! wizardp(me) && (! (ob = present(arg, environment(me))) || ! ob->is_character() || ! me->is_apprentice_of(ob)))
			{
				skill1 = arg;
				arg = "me";
			}
		}

		if (ob && ! ob->is_character())
			ob = 0;

		if (skill1 && file_size(SKILL_D(skill1) + ".c") <= 0)
		{
			if (objectp(ob))
			{
				arg = 0;
				skill1 = 0;
			} else
				return notify_fail("没有(" + skill1 +  ")这种技能。\n");
		}

		if (! ob || ! ob->is_character())
		{
			if (arg == "me")
				ob = me;
			else
				ob = present(arg, environment(me));
	
			if (! ob || ! ob->is_character()) ob = find_player(arg);
			if (! ob || ! ob->is_character()) ob = find_living(arg);
		}

		if (! ob || ! ob->is_character())
			return notify_fail("你要察看谁的技能？\n");
	}

	if (ob != me)
	{
		if ((int)ob->skills(me, skill1))
			return 1;
	}
       
	if (ob == me || wizardp(me) || ob->is_apprentice_of(me) || me->is_apprentice_of(ob) || me->query("couple/id") == ob->query("id") || me->is_brother(ob) )
		valid_check = 1;
	else
	{
		fname = me->query("league/league_name");
		if (stringp(fname) && fname == ob->query("league/league_name"))
			valid_check = 1;
		else
			valid_check = 0;
		if (me->query("can_whistle"))
		{
		   huanshou_str=keys(me->query("can_whistle"));
		   if(ob->query("owner")!=me->query("id"))
		   {
		      valid_check = 0;
		   }
		   else
		   {
		      valid_check = 1;
		   }
		}
	}

//	if (! valid_check)
//		return notify_fail("只有巫师或有师徒/夫妻/结拜/主宠/同盟关系的人才能察看他人的技能。\n");

	skl = ob->query_skills();
	if (! sizeof(skl))
	{
		write((ob==me ? "你" : ob->name()) + "目前并没有学会任何技能。\n");
		return 1;
	}

	sname = keys(skl);

	str = ZJOBLONG + (ob == me ? "你" : ob->name()) + "目前所学到的";
	if (skill1)
	{
		// filter the skill array by skill1
		if (member_array(skill1, valid_types) != -1)
		{
			sname = filter_array(sname, (: filter_for_enable :), skill1);
			str += to_chinese(skill1) + "及相关技能\n";
		}
		else if (SKILL_D(skill1)->main_skill() && member_array(SKILL_D(skill1)->main_skill(), sname) == -1)
		{
			mski = SKILL_D(skill1)->main_skill();
			cha_type = 3;
			sname = filter_array(sname, (: filter_for_main :), mski);
			str += to_chinese(skill1) + "中的招式和可以激发的基础武功\n";
		}
		else
		{
			cha_type = 3;
			sname = filter_array(sname, (: filter_for_combine :), skill1);
			str += to_chinese(skill1) + "和可以激发的基础武技与能够组合的技能\n";
		}
	} else
	{
		if(!page) page = 1;
		str += "所有技能：\n";
	}

	if (! sizeof(sname))
	{
		write("你目前还没有掌握该技能。\n");
		return 1;
	}

	basic = filter_array(valid_types, (: member_array($1, $(sname)) != -1 :));

	lists = allocate(sizeof(basic));

	others = ({ });
	spec = ({ });

	sname -= basic;
	for (i = 0; i < sizeof(sname); i++)
	{
		if (! sname[i]) continue;

		// enable for basic skill
		for (k = 0; k < sizeof(basic); k++)
		{
			string main_skill;

			if (SKILL_D(sname[i])->valid_enable(basic[k]))
			{
				// yes, I record this special skill
				if (! lists[k])
					lists[k] = ({ sname[i] });
				else
					lists[k] += ({ sname[i] });

				spec += ({ sname[i] });
				// Is this a sub skill ?
				if (main_skill = SKILL_D(sname[i])->main_skill())
				{
					// yes, I select out all the other sub skills
					int st;
					for (st = i + 1; st < sizeof(sname); st++)
						if (sname[st] && SKILL_D(sname[st])->main_skill() == main_skill)
						{
							spec += ({ sname[st] });
							// record it
							lists[k] += ({ sname[st] });
							sname[st] = 0;
						}
				}

				break;
			}
		}

		if (k == sizeof(basic))
			others += ({ sname[i] });
	}
	sname = ({ });

	for (i = 0; i < sizeof(basic); i++)
	{
		sname += ({ basic[i] });
		if (lists[i]) sname += lists[i];
	}

/*
        spec = sort_array(spec, (: strcmp :));
        basic = sort_array(basic, (: strcmp :));
        others = sort_array(others, (: strcmp :));
	sname += spec;
	sname += basic;
	sname += others;
*/

	sname += others;
	j = (int)sizeof(skl);
	// get the skill map
	map = ob->query_skill_map();
	if (mapp(map)) mapped = values(map);
	if (! mapped) mapped = ({});
	pmap = me->query_skill_prepare();
	if (mapp(pmap)) pmapped = values(pmap);
	if (! pmapped) pmapped = ({});
	lrn = ob->query_learned();
	if (! mapp(lrn)) lrn = ([]);

	str = replace_string(str,"\n",ZJBR);
	if(str[(strlen(str)-4)..(strlen(str)-1)]=="$br#")
		str = str[0..(strlen(str)-5)];
	str += "\n";
	str += ZJOBACTS2+ZJMENUF(3,3,9,30);
	if(!arg)
		str += "　查看激发"ZJBR"　enable:jifa"ZJSEP"　查看准备"ZJBR"　prepare:bei"ZJSEP"　穿戴所有"ZJBR"　wear all:wear all"ZJSEP;
	for (i = 0; i < sizeof(sname); i++)
	{
		int percent;
		skillname = to_chinese(sname[i]);
		if (member_array(sname[i], valid_types) != -1)
			skcolor = CYN;
		else
			skcolor = WHT;

		if (! objectp(find_object(SKILL_D(sname[i]))) && ! objectp(load_object(SKILL_D(sname[i]))))
		{
			write(HIR "Error(No such skill):" + sname[i] + NOR"\n");
			continue;
		}
		lvl = skl[sname[i]];
		percent = lrn[sname[i]] * 100 / ((lvl + 1) * (lvl + 1) + 1);
		if (percent > 100) percent = 100;
		pops = ZJPOPMENU;
		if(ob==me)
		{
			if(!arg)
			{
				if(member_array(sname[i], valid_types) == -1)
				{
					pops += "激发"+to_chinese(sname[i])+"|skills "+sname[i];
					pops += ZJSP2"准备"+to_chinese(sname[i])+"|prepare "+sname[i];
					pops += ZJSP2"研究"+to_chinese(sname[i])+"|yanjiu "+sname[i];
				}
				else
				{
					pops += "练习"+to_chinese(sname[i])+"|lian "+sname[i];
					pops += ZJSP2"研究"+to_chinese(sname[i])+"|yanjiu "+sname[i];
					pops += ZJSP2"只用"+to_chinese(sname[i])+"|jifa "+sname[i]+" none";
				}
				pops += ZJSP2"放弃"+to_chinese(sname[i])+"|abandon "+sname[i];
			}
			else if(cha_type==3)
			{
				if(member_array(sname[i], valid_types) == -1)
				{
					if(!mapp(pmap)||member_array(sname[i], pmapped) == -1)
						pops += "组合"+to_chinese(sname[i])+"|bei "+sname[i]+" "+skill1;
					else
						pops += "撤销组合"+to_chinese(sname[i])+"|bei none";
				}
				else
				{
					pops = "jifa "+sname[i]+" "+skill1;
				}
			}
		}
		else
		{
			pops += "向"+ob->query("name")+"请教"+to_chinese(sname[i])+"|learn "+ob->query("id")+" "+sname[i];
		}
		text +=({ sprintf("%s%s%s%s"NOR ZJBR WHT"　%d/%d%%"NOR":%s",
			skcolor,
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
			(member_array(sname[i], mapped)==-1? "　": RED"㊣"NOR),
			skillname, lvl, percent,pops) });
	}
	all = sizeof(text)/30;
	if(sizeof(text)%30) all += 1;
	if(page<1) page = 1;
	if(page>all) page = all;
	j = (page-1)*30;
	i = page*30;
	if (i >= sizeof(text)) i = sizeof(text);
	i--;
	str += implode(text[j..i], ZJSEP);
	if(all>1)
		str += ZJSEP"上一页:skills "+(page-1)+ZJSEP"下一页:skills "+(page+1);
	tell_object(me,str+"\n");
	return 1;
}

int filter_for_enable(string skill, string skill1)
{
	return (skill == skill1) || (SKILL_D(skill)->valid_enable(skill1));
}

int filter_for_main(string skill, string skill1)
{
	return  (SKILL_D(skill1)->valid_enable(skill))||(SKILL_D(skill)->main_skill() == skill1);
}

int filter_for_combine(string skill, string skill1)
{
	return (SKILL_D(skill1)->valid_enable(skill)) || (SKILL_D(skill)->valid_combine(skill1));
}
string skill_level(string type, int level)
{
    int grade;
    if (level>=100) if (level<300) grade=(level-100)/20+10 ;else return  NOR "返璞归真" NOR;
    else    grade = level / 10;
    switch(type) {
	case "knowledge":
	    if( grade >= sizeof(knowledge_level_desc) )
		grade = sizeof(knowledge_level_desc)-1;
	    return knowledge_level_desc[grade];
	    break;
	default:
	    if( grade >= sizeof(skill_level_desc) )
		grade = sizeof(skill_level_desc)-1;
	    return skill_level_desc[grade];
    }
}

int help(object me)
{
	write(@HELP
指令格式 : skills|cha [<技能名> of <某人 | me >] | [<某人>]

1. 如果查询一种《基本武功》，将显示所有能够装备的《特殊武功》。

2. 如果查询一种《武技招式》，则显示与之相关的《招式路数》。

3. 如果查询一种《特殊武功》，则显示依赖的《基本武技》与《互备武功》。

	注：显示的所有对象的提示，都是在--已经学会--的基础上
HELP
    );
    return 1;
}
