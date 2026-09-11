// string.c
// by fire on Dec 1998
#include <ansi.h>
string get_char_reputation(int sg_shengwang)
{
        if(sg_shengwang<10)
                return "默默无闻" ;
        if(sg_shengwang<100)
                return RED + "小有名声"+NOR ;
        if(sg_shengwang<1000)
                return YEL + "初露锋芒" +NOR;
        if(sg_shengwang<10000)
                return GRN + "称霸一方"+NOR ;
        if(sg_shengwang<100000)
                return HIY + "逐鹿中原"+NOR ;
        if(sg_shengwang<1000000)
                return HIR + "问鼎天下"+NOR ;
        if(sg_shengwang<10000000)
                return HIG + "众心所归"+NOR ;
        return HIC+"一统天下"+NOR ;
        
}
string query_status(int p_status)
{
        switch(p_status)
        {
        case STATUS_NOTFINISHED:
                return "未完";
        case STATUS_SLEEPING:
                return"休眠";
        case STATUS_ACTIVE:
                return"活动";
        case STATUS_ONLINE:
                return"在线";
        default:
                return"未知";
        }
}
