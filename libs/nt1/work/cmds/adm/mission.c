// Cmds:/cmds/adm/setmission.c
// Update by Lonely(06/20/2002) 

#include <ansi.h>
inherit F_CLEAN_UP;

int check_mission(string mission, object me);
int main(object me, string arg)
{
        int i, flag = 0;
        string mission, wname, wmin, file;
        string *wmission;
        
        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;

        if(! arg || sscanf(arg, "%s %s", arg, mission) != 2)
                return notify_fail("指令格式：mission <使用者> (目前任务)\n");

        if (member_array(arg, SECURITY_D->query_wizlist()) == -1)
                return notify_fail("他不是巫师。\n");

        // if (! check_mission(mission, me)) return 1;
        // 本来想做中文判断和对称显示，但觉得还是取消的好

        mission = replace_color(mission, 1);
        /*
        // 取消了对称显示的功能，因为本来任务就几个字，而且可以机动的设置
        switch (strlen(mission))
        {
        case 8:
                mission = sprintf("%c%c%c%c%c%c%c%c", mission[0], mission[1],
                                             mission[2], mission[3],
                                             mission[4], mission[5],
                                             mission[6], mission[7]);
                break;
        case 6:
                mission = sprintf("%c%c %c%c %c%c", mission[0], mission[1],
                                             mission[2], mission[3],
                                             mission[4], mission[5]);
                break;
        case 4:
                mission = sprintf("%c%c    %c%c", mission[0], mission[1],
                                             mission[2], mission[3]);
                break;
        }
        */
        file = read_file("/adm/etc/renwu");
        
        if(file)
                wmission = explode(file, "\n");
        else
                wmission = ({ });
        for(i = 0; i < sizeof(wmission); i++)
        {
                if(wmission[i][0] == '#' || 
                   sscanf(wmission[i], "%s %s", wname, wmin) !=2)
                        continue;
                if(wname == arg)
                {
                        wmission[i] = sprintf("%s %s\n", wname, mission);
                        flag = 1;
                        break;
                }
        }
        for(file = "", i = 0; i < sizeof(wmission); i++)
                file += wmission[i] + "\n";
        if(! flag)
                write_file("/adm/etc/renwu", arg + " " + mission + "\n", 0);
        else
                write_file("/adm/etc/renwu", file, 1);
        message_vision("$N将 " HIW + arg + NOR " 的工作任务改为 " HIW + mission + NOR " 。\n", me);
        return 1;
}

int check_mission(string mission, object me)
{
        int i;
        i = strlen(mission);

        if ((strlen(mission) < 4) || (strlen(mission) > 8)) 
        {
                tell_object(me, "任务请定在二到四个字。\n");
                return 0;
        }

        while (i--) 
        {
                if (mission[i]<=' ') 
                {
                        tell_object(me, "对不起，任务中不能用控制字符。\n");
                        return 0;
                }
                if (i%2 == 0 && ! is_chinese(mission[i..<0])) 
                {
                        tell_object(me, "请用「中文」规定任务。\n");
                        return 0;
                }
        }
        return 1;
}
        
int help(object me)
{
        write(@HELP
指令格式 : mission <某人> (目前任务)
用来改变巫师当前工作任务的说明，配套 wizlist 使用。
HELP
        );
        return 1;
}

