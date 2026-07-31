// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// quest1.c

#include <ansi.h>
 
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        mapping q;
        string name, npc;

        if (me->query("ultra_count"))
                write(sprintf("南贤交给你的宗师任务，你已经连续完成了 %d 个。\n",
                              me->query("ultra_count")));
 
        if (! me->query("ultraquest/npc1"))
        {
                write("你现在没有领任何任务！\n");
                return 1;
        }

        if (me->query("ultraquest/npc5"))  
        {
                npc = me->query("ultraquest/npc5");
                name = me->query("ultraquest/name5");          
        } else
        if (me->query("ultraquest/npc4"))  
        {
                npc = me->query("ultraquest/npc4");
                name = me->query("ultraquest/name4");         
        } else
        if (me->query("ultraquest/npc3"))  
        {
                npc = me->query("ultraquest/npc3"); 
                name = me->query("ultraquest/name3");
        } else
        if (me->query("ultraquest/npc2"))
        { 
                npc = me->query("ultraquest/npc2");
                name = me->query("ultraquest/name2");  
        } else
        {  
                npc = me->query("ultraquest/npc1"); 
                name = me->query("ultraquest/name1");
        }

        if (! mapp(q =  me->query("ultraquest/quest")))
        {
                if (me->query("ultraquest/id"))
                {
                        write("你现在的任务是去杀了幕后黑手" + me->query("ultraquest/name") + "(" +
                              me->query("ultraquest/id") + ")，提他的人头给南贤。\n");
                        return 1;
                }
                write("你现在的任务是去寻找线索知情人" + name + "(" + npc + ")。\n" +
                      "听说他前段日子在" + me->query("ultraquest/place") +"出现过。\n");
                return 1;
        } else
        {
                switch (q["type"])
                {
                case "kill":
                        write(name + "(" + npc + ")吩咐你去割下" HIR + 
                              q["name"] + "(" + q["id"] + ")" + NOR "的人头，回来交差。\n");
                        return 1;
                
                case "give":
                        write(name + "(" + npc + ")吩咐你去把包裹送到" HIR + 
                              q["name"] + "(" + q["id"] + ")" + NOR "的手里，回来交差。\n");                
                        return 1;
                        
                case "send":
                        write(name + "(" + npc + ")吩咐你去把信送到" HIR + 
                              q["name"] + "(" + q["id"] + ")" + NOR "的手里，回来交差。\n");  
                        return 1;
                        
                case "guard":  
                        write(name + "(" + npc + ")吩咐你留在他那里保护他。\n");  
                        return 1; 
                          
                case "mathematics":
                        write(name + "(" + npc + ")吩咐你和他比试演算。\n");
                        return 1;   
                        
                case "literate":
                        write(name + "(" + npc + ")吩咐你和他比试诗词。\n");
                        return 1;
                           
                case "chess":
                        write(name + "(" + npc + ")吩咐你和他比试棋技。\n");
                        return 1;       
                        
                case "calligraphy":
                        write(name + "(" + npc + ")吩咐你帮他写好书法。\n");
                        return 1;       

                case "drawing":
                        write(name + "(" + npc + ")吩咐你帮他绘画。\n");
                        return 1;                                                                             

                case "medical":
                        write(name + "(" + npc + ")吩咐你帮他治病。\n");
                        return 1;      
                }
        }

        write("你现在没有领任何任务！\n");
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : quest1 显示出你当前的宗师任务。
HELP );
        return 1;
}

