// skills.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
        BLU "初学乍练" NOR,		BLU "初窥门径" NOR,        BLU "粗通皮毛" NOR,
        HIB "略知一二" NOR,     HIB "半生不熟" NOR,        HIB "马马虎虎" NOR,
        YEL "略有小成" NOR,     YEL "已有小成" NOR,        YEL "渐入佳境" NOR,
        YEL "驾轻就熟" NOR,     YEL "了然于胸" NOR,        YEL "出类拔萃" NOR,
        CYN "略有大成" NOR,     CYN "已有大成" NOR,        CYN "心领神会" NOR,
        CYN "无可匹敌" NOR,		CYN "神乎其技" NOR,        HIC "出神入化" NOR,
        HIC "豁然贯通" NOR,     HIC "登峰造极" NOR,        HIC "技冠群雄" NOR,
        HIC "举世无双" NOR,     HIC "一代宗师" NOR,        HIC "震古铄今" NOR,
        HIC "傲视群雄" NOR,     HIC "所向披靡" NOR,        HIC "惊世骇俗" NOR,
        HIY "独步天下" NOR,     HIY "深不可测" NOR,        HIY "返朴归真" NOR, 
        HIY "天下无敌" NOR
});

string *knowledge_level_desc = ({
        BLU "新学乍用" NOR,        BLU "不甚了了" NOR,        BLU "不知端倪" NOR,
        HIB "平淡无奇" NOR,        HIB "司空见惯" NOR,        HIB "初窥门径" NOR,
        MAG "略知一二" NOR,        MAG "茅塞顿开" NOR,        MAG "略识之无" NOR,
        YEL "滚瓜烂熟" NOR,        YEL "马马虎虎" NOR,        YEL "轻车熟路" NOR,
        HIM "运用自如" NOR,        HIM "触类旁通" NOR,        HIM "深入浅出" NOR,
        CYN "已有小成" NOR,        CYN "心领神会" NOR,        CYN "了然於胸" NOR,
        CYN "见多识广" NOR,        CYN "无所不通" NOR,        CYN "卓尔不群" NOR,
        HIC "满腹经纶" NOR,        HIC "豁然贯通" NOR,        HIC "博古通今" NOR,
        HIC "博大精深" NOR,        HIC "超群绝伦" NOR,        HIC "举世无双" NOR,
        HIY "独步天下" NOR,        HIY "震古铄今" NOR,        HIY "超凡入圣" NOR,
        HIY "深不可测" NOR
});

string skill_level(string, int);

int main(object me, string arg)
{
	object ob, *list, couple_ob;
	mapping skl, lrn, map;
	string *sname, *mapped,target,cardname;
        string *sk;
	int i, marry_flag;

	seteuid(getuid());

	if(!arg)
		ob = me;
	else{
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
                if (!ob) ob = LOGIN_D->find_body(arg);
                if (!ob || !me->visible(ob))
                return notify_fail("你要察看谁的技能？\n");
	}
          
	target = (string) me->query("couple/couple_id");	
	if(stringp(target)) couple_ob = find_player(target);
	if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
	&& !me->is_apprentice_of(ob) && ob!=couple_ob
	&& !ob->query("skill_public") )
		return notify_fail("只有管理或有师徒关系的人能察看他人的技能。\n");

	skl = ob->query_skills();
         sk = keys(skl);
	if(!sizeof(skl)) {
		write( (ob==me ? "你" : ob->name()) + "目前并没有学会任何技能。\n");
		return 1;
	}
	write( (ob==me ? "你" : ob->name()) +"目前共学过"+
chinese_number(sizeof(skl))+"种技能：\n\n");
	sname  = sort_array( keys(skl), (: strcmp :) );

    printf(HIC"≡"HIY"──────────────────────────────"HIC"≡\n"NOR);
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	

	for(i=0; i<sizeof(skl); i++) {
	if( skl[sk[i]]<=0 ) map_delete(skl, sk[i]);
		printf("%s%s%-12s%-28s" NOR " - %-10s %3d/%5d\n", 
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
			(member_array(sname[i], mapped)==-1? "  ": "□"),
			to_chinese(sname[i]) , " (" + sname[i] + ")",
			skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
			skl[sname[i]], (int)lrn[sname[i]],
		);
	}
	printf(HIC"≡"HIY"─────────────────────海 洋 II─────"HIC"≡\n"NOR);
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
string pet_skill(object ob)
{
	string desc;
        object  *list, couple_ob;
        mapping skl, lrn, map;
        string *sname, *mapped,target,cardname;
        int i, marry_flag;
        skl = ob->query_skills();
        if(!sizeof(skl)) {
                desc =  ob->name() + "目前并没有学会任何技能。\n";
                return desc;
        }
        	desc =  ob->name() +"目前所学过的技能：\n\n";
        sname  = sort_array( keys(skl), (: strcmp :) );

        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);

        for(i=0; i<sizeof(skl); i++) {
              desc +=  sprintf("%s%s%-40s" NOR " - %-10s %3d/%5d\n",
                        (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
                        (member_array(sname[i], mapped)==-1? "  ": "＊"),
                        to_chinese(sname[i]) + " (" + sname[i] + ")",
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]],
                );
        }
        return desc +"\n";
}
int help(object me)
{
	write(@HELP
指令格式 : skills [<某人>]

这个指令可以让你查询所学过的技能。

你也可以指定一个和你有师徒关系的对象，用 skills 可以查知对方的技能状况。


HELP
    );
    return 1;
}
