inherit F_CLEAN_UP;
int check_name(string name);

int main(object me, string arg)
{
        object ob;
        string name,id;
        string banghui;
        int rank_lv;

        if(! arg) return notify_fail("指令格式：renming <某人> <职务> <等级>\n");
        if(! stringp(banghui=me->query("banghui/name")) 
           || me->query("banghui/rank_lv") < 8 )
           return notify_fail("只有帮主或副帮主才能使用本命令。\n");
        if(sscanf(arg,"%s %s %d",id,name,rank_lv) == 3 )      {
                ob=present(id,environment(me));
                if(! ob)  return notify_fail("这儿没有这么个人。\n");
                if(! ob->is_character())
                          return notify_fail("看清楚，那并不是人！\n");
                if(! userp(ob) ) return notify_fail("你只能对玩家进行任命！\n");
                if(banghui!=(string)ob->query("banghui/name"))
                           return notify_fail("你只对本帮会的成员使用这条命令！\n");
                if(me->is_busy()||me->is_fighting())
                           return notify_fail("你正忙着呢！\n");
                if(ob->is_busy()||ob->is_fighting())
                           return notify_fail("对方正忙着呢！\n");
                if(! check_name(name) || name=="帮主")
                           return notify_fail("您任命的职务必须是中文，且为二到八字！\n");
                if( ob->query("banghui/rank_lv") >= me->query("banghui/rank_lv"))
                return notify_fail("你无权任命对方！\n");  
                if( me->query("banghui/rank_lv") < 9 && rank_lv > 6 )  
                return notify_fail("更高等级的任命必须通过帮主的批准！\n");
                if( rank_lv >= 9 )
                return notify_fail("什么，你该不会是想请对方做帮主吧！\n");
                ob->set("banghui/rank",name);
                ob->set("banghui/rank_lv",rank_lv);
                message_vision("$N任命$n为「"+banghui+"」"+name+"！\n",me,ob);
                return 1;
        }
        else    return notify_fail("指令格式：renming <某人> <职务> <等级>\n");
}

int check_name(string name)
{
        int i;

        i = strlen(name);

        if( (strlen(name) < 4) || (strlen(name) > 16 ) ) {
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        return 0;
                }
        if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        return 0;
        }
        }
        return 1;
}

int help(object me)
{
        write(@HELP

指令格式：renming <player's id> <职务名称> <等级>

这条指令是玩家帮会的帮主专用命令，可以为本帮会
的玩家帮众分配帮会职务。如坛主、堂主、护法、使
者等称谓。
注意：凡是任命为副帮主的玩家，可以代替帮主行使
邀请(yaoqing)的权力。
HELP
        );
        return 1;
}

