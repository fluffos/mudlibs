// enable.c
#include <ansi.h>
inherit F_CLEAN_UP;
mapping valid_types = ([
        "unarmed":      "拳脚",
        "sword":        "剑法",
        "hammer":       "锤法",
        "blade":        "刀法",
        "stick":        "棒法",
        "axe":          "斧法",
        "staff":        "杖法",
        "club" :    "棍法",
        "throwing":     "暗器",
        "force":        "内功",
        "parry":        "招架",
        "dodge":        "轻功",
        "taoism":       "道学心法",
        "whip":     "鞭法",
]);
object find_player(string target)
{
        int i;
        object *str;
        str=users();
        for (i=0;i<sizeof(str);i++)
                if (str[i]->query("id")==target)
                        return str[i];
        return 0;
}
int main(object me, string arg)
{
        mapping map;
        string *skill, ski, map_to,str;
        int i, modify;
        object ob;
        seteuid(getuid());
        str="";
        if( !arg ||arg=="" ) {
                map = me->query_skill_map();
                if( !mapp(map) || sizeof(map)==0 )
                map=(([ ]));
                skill = keys(valid_types);
                for (i=0; i<sizeof(skill); i++) {
                        if( undefinedp(valid_types[skill[i]]) ) {
                                map_delete(map, skill[i]);
                                continue;
                        }
                        if( !me->query_skill(skill[i]) ) continue;
                        modify = me->query_temp("apply/" + skill[i]);
                        str+=sprintf("  %-20s： %-20s  有效等级：%s%3d\n" NOR, 
                                valid_types[skill[i]] + " (" + skill[i] + ")",
                                undefinedp(map[skill[i]]) ? "无" : to_chinese(map[skill[i]]),
                                (modify==0 ? "" : (modify>0 ? HIC : HIR)),
                                me->query_skill(skill[i]));
                }
                if (str=="")
                        return notify_fail("你目前没有任何特殊技能。\n");
                if (arg!="")    write("以下是你目前使用中的特殊技能。\n");
                write(str);
                return 1;
        }
        if( arg=="?" ) {
                write("以下是可以使用特殊技能的种类：\n");
                skill = sort_array(keys(valid_types), (: strcmp :) );
                for(i=0; i<sizeof(skill); i++) {
                        printf("  %s (%s)\n", valid_types[skill[i]], skill[i] );
                }
                return 1;
        }
        if( wizardp(me) && arg ) {
                ob = find_player(arg);
                if( !ob ) ob = find_living(arg);
                if( !ob ) ob = present(arg, environment(me));
                if (ob) {
                        write(ob->short()+"目前使用中的特殊技能：\n");
                        return main(ob,"");
                }
        }
        if( sscanf(arg, "%s %s", ski, map_to)!=2 )
                return notify_fail("指令格式：enable[<技能种类> <技能名称>|none]\n");
        if( undefinedp(valid_types[ski]) )
                return notify_fail("没有这个技能种类，用 enable ? 可以查看有哪些种类。\n");
        if (map_to == me->query_skill_mapped(ski) )
                return notify_fail("你已经装备好了。\n");

        if( map_to == "none" ) {
            if ((me->query_temp("powerup") || me->query_temp("exercise_cost")) && ski=="force" && stringp(me->query_skill_mapped("force"))){
                me->set_temp("exercise_cost",-1);
                write(RED "你试着换用内功，突然觉得四肢麻木，手脚冰冷。\n显然是气息不能回到丹田。\n"NOR);
                if (me->query("max_neili")>100)
                        me->add("max_neili",-100);
                else    me->delete("max_neili");
                me->unconcious();
                return 1;
            }
                me->map_skill(ski);
                me->reset_action();
                write("Ok.\n");
                return 1;
        } else if( map_to==ski ) {
                write("「" + to_chinese(ski) + "」是所有" + valid_types[ski] + "的基础，不需要 enable。\n");
                return 1;
        }
        if( !me->query_skill(map_to, 1) )
                return notify_fail("你不会这种技能。\n");
        if( !SKILL_D(map_to)->valid_enable(ski) )
                return notify_fail("这个技能不能当成这种用途。\n");
        if ((me->query_temp("powerup") || me->query_temp("exercise_cost") || me->query_temp("protect")) && ski=="force"){
                me->set_temp("exercise_cost",-1);
 
                write(RED "你改用另一种内功，突然觉得四肢麻木，手脚冰冷。\n显然是气息不能回到丹田。\n"NOR);
                if (me->query("max_neili")>100)
                        me->add("max_neili",-100);
                else    me->delete("max_neili");
                me->unconcious();
                return 1;
        }
        me->map_skill(ski, map_to);
        me->reset_action();
        write("Ok.\n");
        
        if( ski=="taoism" ) {
                write("你改用另一种法术系，精力必须重新锻练。\n");
                me->set("jingli", 0);
                me->receive_damage("jing", 0);
        } 
        else if( ski=="force" ) {
                write("你改用另一种内功，内力必须重新锻练。\n");
                me->set("neili", 0);
                me->receive_damage("qi", 0);
        }
        return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : enable [<技能种类> <技能名称> | none]
           enable ?
这个指令让你指定所要用的技能，需指明技能种类和技能名称。如果不加参
数则会显示出技能种类及你目前所使用的技能名称 ，如果加一个？会列出
所有能使用特殊技能的技能种类。
 
HELP
        );
        return 1;
}
