// [1;31m此文件禁止随意移动和更改[0m
// CMDS /cmds/usr/wkztime.c
// Created by waiwai@2001/07/06

#include <ansi.h>
inherit F_CLEAN_UP;

int main()
{
	string day,season,time;
       	mapping date; 	  
       	int hour;
 	  
       	date=XYJTIME_D->check_time(time());
       	season=XYJTIME_D->check_season();
       	day=date["YEAR"]+date["MONTH"]+date["DAY"]+date["HOUR"]+date["QUARTER"];
       	time=""+MUD_NAME+"纪年时辰："+day+" "+season+" \n"NOR;
       	write( time );

       	return 1;
}

int help()
{
        write("

指令格式：xyjtime 

此命令用来查看现在"+MUD_NAME+"纪年中的日期!

相关信息：time，uptime
");
        return 1;
}

