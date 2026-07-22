// uptime.c
#include <ansi.h>
#include <mudlib.h>
inherit F_CLEAN_UP;
int main()
{
	int t, d, h, m, s;
	string time;

	t = uptime();
	s = t % 60;		t /= 60;
	m = t % 60;		t /= 60;
	h = t % 24;		t /= 24;
	d = t;

     if(d) time = NOR+chinese_number(d) + "天"NOR;
	else time = "";

       if(h) time += NOR + chinese_number(h) + "小时";
        if(m) time += NOR+ chinese_number(m) + "分";
	time += chinese_number(s) + "秒"NOR;

write("江湖(1.YXJH) 已经运行了"+time+"\n");
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : uptime
 
这个指令告诉您这个泥巴游戏已经连续执行了多久.
 
HELP
    );
    return 1;
}
