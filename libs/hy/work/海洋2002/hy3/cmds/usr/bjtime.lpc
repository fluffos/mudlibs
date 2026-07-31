// uptime.c
// From ES2
// Modified by Yu Jue for JY (1998-3-17)

#include <localtime.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

// This command is also called by LOGIN_D, so we don't want it use 
// arguments.
int main(int i)
{
	int t, y, mo, d, h, m, s;
	mixed *ltime;
	string time;

	ltime = localtime(time());
	s = ltime[LT_SEC];
	m = ltime[LT_MIN];
	h = ltime[LT_HOUR];
	d = ltime[LT_MDAY];
	mo = ltime[LT_MON]+1;
	y = ltime[LT_YEAR];
	time = "年";
	
	if(intp(i)){
	      write("上次当机原因：\n");
	      write(read_file("/log/static/LASTCRASH"));
	}
	
	while (y) {
		time = chinese_number(y%10) + time;
		y /= 10;
	}
	time += chinese_number(mo) + "月";
	time += chinese_number(d) + "日";
	time += chinese_number(h) + "时";
	time += chinese_number(m) + "分";
	time += chinese_number(s) + "秒";

	write("\n现在是北京时间" + time + "。\n");

	t = uptime();
	s = t % 60;		t /= 60;
	m = t % 60;		t /= 60;
	h = t % 24;		t /= 24;
	d = t;

	if(d) time = chinese_number(d) + "天";
	else time = "";

	if(h) time += chinese_number(h) + "小时";
	if(m) time += chinese_number(m) + "分";
	time += chinese_number(s) + "秒";

	write(CHINESE_MUD_NAME + "已经执行了" + time + "。\n");
	
	return 1;
}

int help(object me)
{
	write(
"指令格式 : uptime\n\n"
"这个指令告诉您「" MUD_NAME "」泥巴游戏已经连续执行了多久。\n"
    );
    return 1;
}
