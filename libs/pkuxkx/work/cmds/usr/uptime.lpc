// uptime.c
// From ES2
// Modified by Xiang for XKX (12/15/95)
// Modified by whuan 2007-11-16
#include <mudlib.h>
#include <ansi.h>
inherit F_CLEAN_UP;

// This command is also called by LOGIN_D, so we don't want it use 
// arguments.
int main()
{
        int t, d, h, m, s;
        int flag;
        string time;
        string weekday,month;
        int day,year,second,minute,hour;
        if (sscanf(ctime(time()),"%s %s %d %d:%d:%d %d",weekday,month,day,hour,minute,second,year)!=7)
                write("时间提取出现问题，请通知巫师处理！\n");

        t = uptime();
        
        if     (t>=432000) flag=5;
        else if(t>=345000) flag=4;
        else if(t>=259200) flag=3;
        else if(t>=172800) flag=2;
        else if(t>=43200)  flag=1;
        else flag=0;		

        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;
        


        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";
        if(wizardp(this_player())) 
        write(sprintf("服务器的时间是：%s %s %d %d:%d:%d %d\n",weekday,month,day,hour,minute,second,year));

        write(CHINESE_MUD_NAME + "已经执行了"HIY + time + NOR"。\n");
        /*--------------------------
        write(HIB+"巫师友情提示：");
        switch (flag)
        {
        	case 5:
        		write(HIR"服务器已经运行这么长时间了，哇呀不得了，估计快重启了，随时注意保存和备份啊！\n"NOR);
        	  break;
        	case 4:
        	case 3:
        		write(HIM"服务器运行了三四天了，有点小卡是正常了，你还是多点保存和备份吧！\n"NOR);  
        		break;
        	case 2:
        	case 1:
        		write(HIG"服务器运行平稳，估计比较正常，不过也不要掉以轻心，随时保存和备份！\n"NOR);
        	  break;
        	case 0:
        		write(CYN"服务器刚重启过没多久，不知道怎么搞的，多体谅吧。请注意随时保存！\n"NOR);
        		break;
        	default:
        		break;
        }
        --------------------------*/		
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : uptime
 
这个指令告诉您「侠客行」泥巴游戏已经连续执行了多久.
 
HELP
    );
    return 1;
}
