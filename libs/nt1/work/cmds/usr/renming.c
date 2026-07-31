// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit F_CLEAN_UP;
int check_item(string item);

int main(object me, string arg)
{
        object ob;
        string name, item, zhiwei, id, n1, n2;
        string banghui;
        int lvl, flag;
        
        if (! (banghui = me->query("bunch/bunch_name")))
              return notify_fail("你没有参加任何帮会，无法任命别人职位。\n");
        
        flag = 0;
        
        if (me->query("bunch/level") == 9   
        ||  (intp(me->query("bunch/level")) 
        &&  (int)me->query("bunch/level") > 2))
                flag = 1;               
        
        if (! arg)   
                return notify_fail("指令格式：renming <某人> <职务>或renming <某人> <部门> <职务>\n");
                
        if (! flag)
                return notify_fail("你在帮内职位太低，无权任命别人职位！\n");
                
        if (sscanf(arg, "%s %s %s", id, item, zhiwei) == 3) 
        {
                ob = present(id, environment(me));
                
                if (! ob) return notify_fail("这儿没有这么个人。\n");
                
                if (! ob->is_character())
                        return notify_fail("看清楚，那并不是人！\n");
                                
                if (! playerp(ob))  
                        return notify_fail("你只对本帮会的玩家使用这条命令！\n");
                        
                if (banghui != (string)ob->query("bunch/bunch_name"))
                        return notify_fail("你只对本帮会的玩家使用这条命令！\n");
                        
                if ((int)me->query("bunch/level") < (int)ob->query("bunch/level"))
                        return notify_fail("对方在帮中的职位比你高，你任命他？搞笑！\n");
                        
                if (me->is_busy() || me->is_fighting())
                        return notify_fail("你正忙着呢！\n");
                        
                if (ob->is_busy() || ob->is_fighting())
                        return notify_fail("对方正忙着呢！\n");
                        
                if (ob == me)
                        return notify_fail("自己任命自己？\n");
                        
                if (! check_item(item))
                        return notify_fail("您任命的职务必须是中文，且为二到八字！\n");
                        
                if (zhiwei != "护法" && zhiwei != "舵主" && zhiwei != "坛主" 
                &&  zhiwei != "堂主" && zhiwei != "香主" && zhiwei != "门人"
                &&  zhiwei != "帮众")
                        return notify_fail("任命的职位至上而下为：护法,舵主,坛主,堂主,香主,门人,帮众。\n");
                        
                switch (zhiwei)
                { 
                case "副帮主": 
                        lvl = 6;
                        break;
                case "长老":
                        lvl = 5;
                        break;
                case "护法":
                        lvl = 4;
                        break;
                case "舵主":
                case "坛主":
                case "堂主":
                case "香主":
                        lvl = 3;
                        break;
                case "门人":
                        lvl = 2;
                        break;
                case "帮众":
                        lvl = 1;
                        break;
                }
                
                if ((int)me->query("bunch/level") <= lvl)
                        return notify_fail("你职位太低，无权任命别人这个职位！\n");
                        
                else 
                {
                        ob->set("bunch/title", item + zhiwei);
                        ob->set("bunch/level", lvl);
                        message_vision("$N任命$n为「" + banghui + "」" + item + zhiwei + "！\n", me, ob);
                        return 1;
                }
        }
     
               
        if (sscanf(arg, "%s %s", id, name) == 2) 
        {
                ob = present(id, environment(me));
                
                if (! ob) return notify_fail("这儿没有这么个人。\n");
                
                if (! ob->is_character())
                        return notify_fail("看清楚，那并不是人！\n");
                        
                if (!userp(ob)) return notify_fail("你只对本帮会的玩家使用这条命令！\n");
                
                if (banghui != (string)ob->query("bunch/bunch_name"))
                        return notify_fail("你只对本帮会的玩家使用这条命令！\n");
                        
                if ((int)me->query("bunch/level") <= (int)ob->query("bunch/level"))
                        return notify_fail("对方在帮中的职位比你高，你任命他？搞笑！\n");
                        
                if (me->is_busy() || me->is_fighting())
                        return notify_fail("你正忙着呢！\n");
                        
                if (ob->is_busy() || ob->is_fighting())
                        return notify_fail("对方正忙着呢！\n");
                        
                if (ob == me)
                        return notify_fail("自己任命自己？\n");
                        
                if (name != "副帮主" && name != "长老" && name != "护法" && name != "舵主"
                &&  name != "坛主" && name != "堂主" && name != "香主" && name != "门人"
                &&  name != "帮众")
                        return notify_fail("任命的职位至上而下为：副帮主，长老, 护法, 舵主, 坛主, 堂主, 香主, 门人, 帮众 。\n");
                        
                switch (name)
                { 
                case "副帮主": 
                        lvl = 6;
                        break;
                case "长老":
                        lvl = 5;
                        break;
                case "护法":
                        lvl = 4;
                        break;
                case "舵主":
                case "坛主":
                case "堂主":
                case "香主":
                        lvl = 3;
                        break;
                case "门人":
                        lvl = 2;
                        break;
                case "帮众":
                        lvl = 1;
                        break;
                }
                
                if ((int)me->query("bunch/level") <= lvl)
                        return notify_fail("你职位太低，无权任命别人这个职位！\n");
                        
                else 
                {
                        ob->set("bunch/title", name);
                        ob->set("bunch/level", lvl);
                        message_vision("$N任命$n为「" + banghui + "」" + name + "！\n", me, ob);
                        return 1;
                }
       }
       else     return notify_fail("指令格式：renming <某人> <职务>或renming <某人> <部门> <职务>\n");
}

int check_item(string item)
{
        int i;

        i = strlen(item);

        if( (strlen(item) < 4) || (strlen(item) > 16 ) ) {
                return 0;
        }
        while(i--) {
                if( item[i]<=' ' ) {
                        return 0;
                }
        if( i%2==0 && !is_chinese(item[i..<0]) ) {
                        return 0;
        }
        }
        return 1;
}

int help(object me)
{
        write(@HELP

指令格式：renming <某人> <职务> 或 renming <某人> <部门> <职务>

这条指令是玩家帮会中具有一定地位的人都可以用的命令，可以为本帮会
的玩家帮众分配帮会职务。如坛主、堂主、护法、门人等称谓。

HELP
        );
        return 1;
}


