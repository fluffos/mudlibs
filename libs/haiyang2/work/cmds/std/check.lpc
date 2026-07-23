// skills.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
        BLU "初学乍练" NOR,
        BLU "初窥门径" NOR,
        BLU "粗通皮毛" NOR,
        HIB "略知一二" NOR,
        HIB "半生不熟" NOR,
        HIB "马马虎虎" NOR,
        YEL "略有小成" NOR,
        YEL "已有小成" NOR,
        YEL "渐入佳境" NOR,
        HIY "驾轻就熟" NOR,
        HIY "了然于胸" NOR,
        HIY "出类拔萃" NOR,
        MAG "略有大成" NOR,
        MAG "已有大成" NOR,
        MAG "心领神会" NOR,
        HIM "神乎其技" NOR,
        HIM "出神入化" NOR,
        HIM "豁然贯通" NOR,
        RED "登峰造极" NOR,
        RED "技冠群雄" NOR,
        RED "举世无双" NOR,
        HIR "一代宗师" NOR,
        HIR "震古铄今" NOR,
        HIR "傲视群雄" NOR,
        WHT "所向披靡" NOR,
        WHT "惊世骇俗" NOR,
        HIW "无可匹敌" NOR,
        HIW "独步天下" NOR,
        HIY "深不"HIR"可测" NOR,
        HIC "返朴" HIW "归真" NOR, 
        HIY "天" HIC "下" HIW "无" HIR "敌" NOR
});

string *knowledge_level_desc = ({
        BLU "新学乍用" NOR,
        BLU "初窥门径" NOR,
        HIB "略知一二" NOR,
        HIB "平淡无奇" NOR,
        YEL "半生不熟" NOR,
        YEL "马马虎虎" NOR,
        HIY "已有小成" NOR,
        HIY "心领神会" NOR,
        MAG "了然于胸" NOR,
        HIM "已有大成" NOR,
        RED "豁然贯通" NOR,
        HIR "出类拔萃" NOR,
        CYN "技冠群雄" NOR,
        HIC "一代宗师" NOR,
        HIW "举世无双" NOR,
        HIC "震古" HIW "铄今" NOR,  
        HIY "深不" HIR "可测" NOR,
        HIY "天" HIC "下" HIW "无" HIR "敌" NOR
});

string skill_level(string, int);

int main(object me, string arg)
{
	object ob, man, *all;
	mapping fam, skl, lrn, map;
	string *sname, *mapped;
	int sp, dp;
	int i, cost, check_level;

	seteuid(getuid());

	all = all_inventory(environment(me));
	for(i=0; i<sizeof(all); i++) {
		if( living(all[i]) && !userp(all[i]) ) man = all[i];
	}

        if ( (!(fam = me->query("family")) || fam["family_name"] != "丐帮") )
		return notify_fail("只有乞丐才能打探别人的技能！\n");

	if ( !objectp(man) )
		return notify_fail("周围没人能帮你去了解别人的技能！\n");

        if ( me->query_skill("checking",1) < 10 )
		return notify_fail("你的打探本领尚未纯熟，无法了解别人的技能！\n");

	if ( !arg )
		return notify_fail("你要打听谁的技能？\n");

        if ( present(arg, environment(me)) )
		return notify_fail("你要打听的人就在边上，在这里问不大妥当吧？\n");

	ob = find_player(arg);
	if (!ob) ob = find_living(arg);
	if (!ob) return notify_fail("你要打听谁的技能？\n");
if (wizardp(ob)) return notify_fail("你要打听谁的技能？\n");
	if ( ob == me )
		return notify_fail("你没这麽笨吧，要别人告诉你自己的技能？\n");

	cost = me->query("max_jing")/(me->query_skill("checking",1)/10) - 10;

	if ( me->query("jing") <= cost )
		return notify_fail("现在你太累了，无法去打听别人的技能。\n");

	tell_object(me, "你走上前去，小心翼翼地向" + man->name() + "打听关于" + ob->name() + "的情况 ...\n\n");
	message("vision", "只见" + me->name() + "陪着笑脸跟" + man->name() + "说着话，好象在打听些什么。\n\n", 
		environment(me), ({ me, man }) );

	sp = me->query_skill("checking")*10 + me->query("kar")*5 + me->query("jing") + man->query("jing");
	dp = ob->query("kar")*5 + ob->query("jing")*2;
	
	if ( random(sp) < random(dp) || ob->query("id") == "princess")
		return notify_fail( man->name() + "摇了摇头，说道：这事我可不清楚，"
		 	+ RANK_D->query_respect(me) + "还是去向别人打听一下吧！\n");

	me->receive_damage("jing", cost );

	skl = ob->query_skills();
	if(!sizeof(skl)) {
		write( man->name() + "告诉你： " + ob->name() + "目前并没有学会任何技能。\n");
		return 1;
	}
	write( man->name() + "告诉你： " + ob->name() +"目前所学过的技能：\n\n");
	sname  = sort_array( keys(skl), (: strcmp :) );
	
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	
	i = random(sizeof(skl));

	printf("%s%s%-40s" NOR " - %-10s %3d/%5d\n", 
		(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
		(member_array(sname[i], mapped)==-1? "  ": "□"),
		to_chinese(sname[i]) + " (" + sname[i] + ")",
		skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
		skl[sname[i]], (int)lrn[sname[i]],
	);
	check_level = me->query_skill("checking", 1);
	if ( (int)me->query("combat_exp") > (check_level*check_level*check_level)/10)
	{
		me->improve_skill("checking", random(me->query("int")));
	}

	write("\n");
	return 1;
}

string skill_level(string type, int level)
{
	int grade;

	grade = level / 10;

	switch(type) {
		case "knowledge":
			if( grade >= sizeof(knowledge_level_desc) )
				grade = sizeof(knowledge_level_desc)-1;
			return knowledge_level_desc[grade];
		default:
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
}

int help(object me)
{
	write(@HELP
指令格式 : check|dating [<某人>]

这个指令可以让你打听别人所学过的技能。

你也可以指定一个和你有师徒关系的对象，用 skills|cha 可以查知对方的技能状况。

此命令为丐帮弟子专用，并需学习相应的技能。

HELP
    );
    return 1;
}
