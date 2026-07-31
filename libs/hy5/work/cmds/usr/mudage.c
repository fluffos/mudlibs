// mudage.c
//[xiaojl 1999/11/20 海洋II]
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int sec, min, hrs, day, mon, age;
        string out_str;
        
        age = (int)me->query("mud_age");                
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
        
       write("你已经在《海洋II》的世界里生活了" + out_str + "了。\n");
        return 1;
}


