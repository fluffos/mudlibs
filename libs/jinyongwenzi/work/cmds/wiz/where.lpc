// where.c
// 06-14-95

inherit F_CLEAN_UP;

int main(object me, string str)
{
        object ob, where, *ob_list;
        int i;

        if (!str)
                return notify_fail("指令格式：where <人物或档名>\n"); 
        ob = find_player(str);
        if( !ob ) ob = find_living(str);
        if( !ob || !me->visible(ob)) {
                str = resolve_path(me->query("cwd"), str);
                ob_list = filter_array(children(str), (: clonep :));
                write("\n总共找到了"+chinese_number(sizeof(ob_list))+"个复制件：\n");
                for(i=0; i<sizeof(ob_list); i++) {
                	where = environment(ob_list[i]);
                	write(sprintf("  %-50s  in  %s(%s)\n", ob_list[i]->name()+"("+file_name(ob_list[i])+")",
                        where ? (where->is_character() ? where->name() : where->query("short")) : "不详",
                        where ? (where->is_character() ? where->query("id") : base_name(where)) : "none"));
                }
                return 1;
        }
        if (!ob) return notify_fail("现在没这个人.\n");
        where = environment(ob);
        if (!where) return notify_fail("这个人不知道在那里耶...\n");
        printf("%s(%s)现在在%s(%s).\n",
                (string)ob->name(),
                (string)ob->query("id"),
                (string)where->query("short"),
                (string)file_name(where));
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式: where <玩家的 ID>

这个指令是用来得知玩家目前所在的位置.

HELP
        );
        return 1;
}
