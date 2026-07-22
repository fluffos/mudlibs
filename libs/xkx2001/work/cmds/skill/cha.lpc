//Cracked by Roath
// skills.c
// Modified by xQin 04/01 to disable the possibility for players to use this cmd to check whether
// an invisible wiz is online.

#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
        BLU "初学乍练" NOR,
        HIB "粗通皮毛" NOR,
        HIB "半生不熟" NOR,
        HIB "马马虎虎" NOR,
        HIB "驾轻就熟" NOR,
        CYN "出类拔萃" NOR,
        CYN "神乎其技" NOR,
        CYN "出神入化" NOR,
        HIC "登峰造极" NOR,
        HIC "一代宗师" NOR,
        HIW "深不可测" NOR
});

string *knowledge_level_desc = ({
        BLU "新学乍用" NOR,
        HIB "初窥门径" NOR,
        HIB "略知一二" NOR,
        HIB "马马虎虎" NOR,
        HIB "已有小成" NOR,
        CYN "心领神会" NOR,
        CYN "了然於胸" NOR,
        CYN "豁然贯通" NOR,
        HIC "举世无双" NOR,
        HIC "震古铄今" NOR,
        HIW "深不可测" NOR
});

string skill_level(string, int);

int main(object me, string arg)
{
        object ob;
        mapping skl, lrn, map;
        string *sname, *mapped;
        int i;

        seteuid(getuid());

        if(!arg)
                ob = me;
        else{
                ob = present(arg, environment(me));
//        if ( ob->query("SPSKILLS",1)  ) return ob->skills();           
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("你要察看谁的技能？\n");
        }

        if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
        && !me->is_apprentice_of(ob) && !ob->is_spouse_of(me))
                return notify_fail("你要察看谁的技能？\n");

        skl = ob->query_skills();
        if(!sizeof(skl)) {
                write( (ob==me ? "你" : ob->name()) + "目前并没有学会任何技能。\n");
                return 1;
        }
        write( "[44;1m[1;33m"+(ob==me ? "你" : ob->name()) +"[44;1m[1;33m目前所学过的技能：（共"+chinese_number(sizeof(skl))+"项技能）                               [37;0m\n\n");
        sname  = sort_array( keys(skl), (: strcmp :) );
        
        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        
        for(i=0; i<sizeof(skl); i++) {
                printf("%s%s%-40s" NOR " - %-10s %3d/%5d\n", 
                        ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : ""),
                        (member_array(sname[i], mapped)==-1? "  ": "□"),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
        }
        write("\n");
        return 1;
}

string skill_level(string type, int level)
{
        int grade;

        grade = level / 40;

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
指令格式 : skills|cha [<某人>]

这个指令可以让你(你)查询所学过的技能。

你也可以指定一个和你有师徒关系的对象，用 skills 可以查知对方的技能状况。

巫师可以查询任何人或 NPC 的技能状况。

HELP
    );
    return 1;
}
