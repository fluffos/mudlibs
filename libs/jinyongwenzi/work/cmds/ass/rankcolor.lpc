// rankcolor.c
//

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me,string arg)
{
        object ob;
        string color;
        //if( me != this_player() ) return 0;
        if( !arg || sscanf(arg, "%s %s", ob, color) != 2 )
                return notify_fail("你想为谁设置什么颜色？\n");
        if(!(ob = present(ob, environment(me))) )
                return notify_fail("没有这个人 。\n");
        if( wiz_level(me) < wiz_level(ob) )
               return notify_fail("你没有这种权力。\n");
        ob->set("rankcolor",color);
        return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : rankcolor <id, color>
 
这个指令能让你修改rank的颜色，目前可修改的颜色有：
BLK - 黑色              NOR - 恢复正常颜色
RED - 红色              HIR - 亮红色
GRN - 绿色              HIG - 亮绿色
YEL - 土黄色    HIY - 黄色
BLU - 深蓝色    HIB - 蓝色
MAG - 浅紫色    HIM - 粉红色
CYN - 蓝绿色    HIC - 天青色
WHT - 浅灰色    HIW - 白色
HELP
        );
        return 1;
}

