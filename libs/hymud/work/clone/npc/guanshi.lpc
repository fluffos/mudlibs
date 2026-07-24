#include <ansi.h>
// liumang.c 流氓
inherit NPC;
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

void create()
{
	set_name("大内管事", ({ "guanshi", "shi" }));
	set("gender", "男性");
	set("age", 19);
	set("long", "他是一个大内管事，知道很多情况，你可以用(datan)命令像他要情报。\n");
	
	set("combat_exp", 5000);
	set("shen_type", 1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 420);
        set_skill("parry", 420);
	set_skill("dodge", 420);
	set_temp("apply/attack", 500);
	set_temp("apply/defense", 500);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",2);
}

int init()
{
        add_action("do_check","datan");
}

int do_check(string arg)
{
	object ob,gold, man, *all;
	mapping fam, skl, lrn, map;
	string *sname, *mapped;
	int sp, dp;
	int i, cost, check_level;
        object me=this_player();
	seteuid(getuid());

	all = all_inventory(environment(me));
	for(i=0; i<sizeof(all); i++) {
		if( living(all[i]) && !userp(all[i]) ) man = all[i];
	}

        gold = present("gold_money", this_player());
        if( !gold) return notify_fail("你身上没有金子。\n");

        if((int) gold->query_amount() < 1)
        return notify_fail("你身上没带够1两金子。\n");
        gold->add_amount(-1);

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
        if (wizardp(ob)&& userp(ob))
                return notify_fail("你要打听谁的技能？\n");


	tell_object(me, "你走上前去，小心翼翼地向" + man->name() + "打听关于" + ob->name() + "的情况 ...\n\n");
	message("vision", "只见" + me->name() + "陪着笑脸跟" + man->name() + "说着话，好象在打听些什么。\n\n", 
		environment(me), ({ me, man }) );

	me->receive_damage("jing", 10 );

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
