// mudage.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int sec, min, hrs, day, mon, age;
	string out_str;
	
	if( me->query("jing") < 10 )
		return notify_fail("你的精神不能集中来算自己的年岁。\n");
		
	age = (int)me->query("mud_age");
	if (age < 3600) out_str = "零小时";
	else {
		sec = age % 60;
		age /= 60;
		min = age % 60;
		age /= 60;
		hrs = age % 24;
		age /= 24;
		day = age % 30;
		mon = age / 30;
	
		out_str = (mon? chinese_number(mon)+"月":"")
			+ (day? chinese_number(day)+"天":"")
			+ (hrs? chinese_number(hrs)+"小时":"");
	}
	me->add("jing", -5);
  write("你已经在江湖的风雨中漂泊了" + out_str + "了。\n");
	age = (int)me->query("mudage_reduce");
	if (age < 3600) out_str = "零小时";
	else {
		sec = age % 60;
		age /= 60;
		min = age % 60;
		age /= 60;
		hrs = age % 24;
		age /= 24;
		day = age % 30;
		mon = age / 30;
	
		out_str = (mon? chinese_number(mon)+"月":"")
			+ (day? chinese_number(day)+"天":"")
			+ (hrs? chinese_number(hrs)+"小时":"");
	}
  write("获得了" + out_str + "的年龄减值。\n");
	return 1;
}
 
int help(object me)
{
        write(@HELP
指令格式: mudage
 
这个指令可以让你知道自己在江湖中漂泊的时间。
 
HELP
    );
    return 1;
}
