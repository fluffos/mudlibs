// prepare.c
// YUJ@SJ 2001-0610 支持 prepare basic_skill 的格式
// Modified by iszt@pkuxkx, 2007-03-11

inherit F_CLEAN_UP;

mapping valid_types =
([
        "claw":         "爪法",
        "cuff":         "拳法",
        "finger":       "指法",
        "hand":         "手法",
        "leg":          "腿法",
        "strike":       "掌法",
        "unarmed":      "拳脚",
        "throwing":     "暗器",
]);

int main(object me, string arg)
{
        mapping smap, pmap;
        string *skill, basic1, basic2, arg1, arg2;

        smap = me->query_skill_map();

//        if (arg && (me->query_temp("no_prepare") || me->is_busy() || me->query_temp("thd/xinghe")
        if (arg && (me->query_temp("no_prepare") || me->query_temp("thd/xinghe")))
//        || me->query_condition("no_perform") || me->is_perform()))
                return notify_fail("你现在不能准备特殊技能。\n");

        if (!sizeof(smap))
                return notify_fail("你现在没有激发任何有效特殊技能。\n");

        pmap = me->query_skill_prepare();
        if (!pmap) pmap = ([]);

        if (!arg) {
                if (!sizeof(pmap))
                        return notify_fail("你现在没有准备任何特殊技能。\n");

                skill = keys(pmap);
                write("以下是你目前组合中的特殊技能：\n");
                foreach (string item in skill) {
                        if (!me->query_skill(item))
                                continue;
                        write(valid_types[item] + sprintf("%-10s",
                                "(" + item + ")") +
                                to_chinese(pmap[item]) + "\n"
                        );
                }
                return 1;
        }

        if (arg == "?") {
                write("以下是可以使用的特殊拳脚技能种类：\n");
                skill = sort_array(keys(valid_types), (: strcmp :));
                foreach (string item in skill)
                        write(sprintf("  %s: (%s)\n", valid_types[item], item));
                return 1;
        }

        if (arg == "none") {
                if (!sizeof(pmap))
                        return notify_fail("你现在没有组合任何特殊拳脚技能。\n");

                skill = keys(pmap);
                foreach (string item in skill)
                        me->prepare_skill(item);

                me->reset_action();
                write("取消全部技能准备。\n");
                return 1;
        }

        if (sizeof(pmap) >= 2)
                return notify_fail("你现在已经组合了两种特殊技能。\n");

        if (sscanf(arg, "%*s %*s %*s") == 3)
                return notify_fail("指令格式：prepare|bei [<技能名称一>|<技能名称二>]\n");

        if (sscanf(arg, "%s %s", arg1, arg2) == 2)
        {
                if (sizeof(pmap) == 1)
                        return notify_fail("你已准备有一种技能了。\n");
                if (!undefinedp(valid_types[arg1])) {
                        basic1 = arg1;
                        arg1 = me->query_skill_mapped(basic1);
                        if (!arg1)
                                return notify_fail("你没有激发特殊的" + valid_types[basic1] + "。\n");
                }
                if (!undefinedp(valid_types[arg2])) {
                        basic2 = arg2;
                        arg2 = me->query_skill_mapped(basic2);
                        if (!arg2)
                                return notify_fail("你没有激发特殊的" + valid_types[basic2] + "。\n");
                }
                if (!me->query_skill(arg1, 1) || !me->query_skill(arg2, 1))
                        return notify_fail("你至少不会这两种拳脚技能的其中之一。\n");

                if (!SKILL_D(arg1)->valid_combine(arg2) || !SKILL_D(arg2)->valid_combine(arg1))
                        return notify_fail(to_chinese(arg1)+"和"+to_chinese(arg2)+"不能组合。\n");

                skill = keys(valid_types);
                foreach (string item in skill) {
                        if (!basic1 && smap[item] == arg1) basic1 = item;
                        if (!basic2 && smap[item] == arg2) basic2 = item;
                }

				if ( !basic1 || !basic2 || basic1 == "" || basic2 == "" ) 
                        return notify_fail("这两种技能尚未激发或不是拳脚技能。\n");

                me->prepare_skill(basic1, arg1);
                me->prepare_skill(basic2, arg2);
        } else {
                arg1 = arg;
                if (!undefinedp(valid_types[arg1])) {
                        basic1 = arg1;
                        arg1 = me->query_skill_mapped(basic1);
                        if (!arg1)
                                return notify_fail("你没有激发特殊的" + valid_types[basic1] + "。\n");
                }
                if (!me->query_skill(arg1, 1))
                        return notify_fail("你不会这种技能。\n");

                skill = keys(pmap);
                if ( sizeof(pmap)
                && (!SKILL_D(arg1)->valid_combine(pmap[skill[0]])
                || !SKILL_D(pmap[skill[0]])->valid_combine(arg1)) )
                        return notify_fail(to_chinese(arg1)+"不能用于你现有的拳脚技能组合。\n");

                skill = keys(valid_types);
                foreach (string item in skill)
                        if (!basic1 && smap[item] == arg1) basic1 = item;

                if (!basic1)
                        return notify_fail("这种技能尚未激发或不是拳脚技能。\n");

                me->prepare_skill(basic1, arg1);
        }
        me->reset_action();
        write("完成拳脚技能准备。\n");
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : prepare|bei [<基本或特殊技能一>|<基本或特殊技能二>|none]
           prepare|bei ?

这个指令让你指定所要用的拳脚技能， 需指明一种或以上的相应技能名称。
如果不加参数则会显示出技能种类及你目前所使用的技能名称 ，如果加一
个 ? 会列出所有能使用特殊拳脚技能的技能种类。

HELP
        );
        return 1;
}
