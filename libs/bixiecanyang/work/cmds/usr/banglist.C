#include <ansi.h>
inherit F_CLEAN_UP;
int sort_user(object,object);

int main(object me, string str)
{
        int i;
        string name;
        object *ob,*list;
        int flag,count;
				if( !me->query("guild") )
					return notify_fail("你无帮无派，想查谁呀？\n");


        str="【"HIW + me->query("guild/name") + NOR"】" + "目前在线的人员有：\n";
        ob = filter_array(objects(), (: userp :));
        ob = filter_array(ob, (: $1->query("guild/name") ==
        	$2->query("guild/name") :), me);
        list = sort_array(ob, (: sort_user :));
        count=0;
        flag=0;
        i = sizeof(list);
        while ( i-- )
        {
        	if( interactive(ob[i]) && list[i]->query("guild/generation")<=2)
        		 name = sprintf( "%s"HIG"%-10s"NOR"(%-11s"NOR"	",
        	" ", list[i]->name(1),
        	capitalize(list[i]->query("id"))+")");
        	else if(list[i]->query_temp("netdead"))
        		name = sprintf( HIR"%s%-10s"NOR"(%-11s"NOR"	",
        		" ", list[i]->name(1),
        		capitalize(list[i]->query("id"))+")");
        	else
        	name = sprintf( "%s%-10s(%-11s"NOR"	",
        	" ", list[i]->name(1),
        	capitalize(list[i]->query("id"))+")");
        	str = sprintf("%s%25s%s", str, name,
        	flag%3==2?"\n":"");
        	if (interactive(list[i])) count++;
        	flag++;
        	reset_eval_cost();
        }
				me->start_more(str);
        
        write("\n合共有: "HIR+chinese_number(count)+NOR" 位。"HIG"绿色"NOR" 表示帮主或长老，"HIR"红色"NOR" 表示断线中。\n");
   
        return 1;
}
int sort_user(object ob1, object ob2)
{
        string name1, name2;
        if( wiz_level(ob1) != wiz_level(ob2) )
                return wiz_level(ob2)
                - wiz_level(ob1);
                name1 = ob1->query("guild/name");
                name2 = ob2->query("guild/name");
        if (intp(name1)) name1 = "";
        if (intp(name2)) name2 = "";
        if (name1 > name2) return -1;
        if (name1 < name2) return 1;
        return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}
int help(object me)
{
write(@HELP
指令格式 : banglist

用途 : 列出目前帮派里所有在线名单。
HELP
     );
     return 1;
}

