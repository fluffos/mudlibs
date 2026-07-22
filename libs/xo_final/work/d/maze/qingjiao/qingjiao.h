#include <ansi.h>

void leave_maze(object me)
{
    if ( !me->query_temp("maze_out") || !me->move(me->query_temp("maze_out")) )
    {
        me->move("/d/city/yangzhou/biaoju/tianjing");
    }

    me->delete_temp("maze_out");
    me->delete_temp("maze/qingjiao");
    me->delete_temp("shilian");
}

string query_enter_file()
{
    string str = query("mazeobj");
    int idx;
    idx = strsrch(str, "/", -1);
    str = str[0..idx-1];
    str += "/enter";
    return str;
}

int alternative_die(object who)
{
    string start;
    int i, lost;
    object target;

    if ( !who )
    {
        return 1;
    }

    if ( !userp(who) )
    {
        destruct(who);
        return 1;
    }

    //无进入标识                
    if ( !who->query_temp("maze/qingjiao") )
    {
        return 1;
    }

    //玩家死亡
    who->add_temp("maze/baihua_died", 1);
    i = who->query_temp("maze/baihua_died");
    if ( i <= 0 )
    {
        i = 1;
    }

    lost = 100 * i;
    if ( lost > 10000 )
    {
        lost = 10000;
    }

    if ( lost > who->query("combat_exp") )
    {
        lost = who->query("combat_exp");
    }

    if ( lost > 0 )
    {	
        who->add("combat_exp", -lost);
        tell_object(who, HIG"【试炼大阵】你损失了" + lost + "点实战经验。\n"NOR);
    }

    who->save();

    start = query_enter_file();
    if ( !start )
    {
        leave_maze(who);
        return 0;
    }

    if ( file_size(start + ".lpc") > 0 )
    {
        who->move(start);
        message("vision","\n\n【试炼大阵】花海翻腾，只见一道血肉模糊的人影跌将出来。。。。\n\n", environment(who), who);
        tell_object(who, "你伤势严重，退回到了起点。\n");
    }
    else
    {
        tell_object(who,HIG"【试炼大阵】副本地图已被销毁，你退出了副本地图。\n"NOR);
        leave_maze(who);
    }

    return 0;
}

