#include <mudlib.h>

inherit F_CLEAN_UP;

void listuser()
{
	object *list;
	string str1,weekday,month,time;
        int j,day,year,second,minute,hour,intmonth,uo,wo;
	int t, d, h, m, s;
	if (sscanf(ctime(time()),"%s %s %d %d:%d:%d %d",weekday,month,day,hour,minute,second,year)!=7)
		write("时间提取出现问题，请通知巫师处理！\n");
	t = uptime();
	s = t % 60;		t /= 60;
	m = t % 60;		t /= 60;
	h = t % 24;		t /= 24;
	d = t;

	if(d) time = chinese_number(d) + "天";
	else time = "";

	if(h) time += chinese_number(h) + "小时";
	if(m) time += chinese_number(m) + "分";
	time += chinese_number(s) + "秒\n";

	list=users();
	j = sizeof(list);
//		printf("onlineuser里记录%d个用户",j);
	rm("/web/files/onlineuser");
	switch(month)
	{
		case "Jan":
			intmonth=1;break;
		case "Feb":
			intmonth=2;break;
		case "Mar":
			intmonth=3;break;
		case "Apr":
			intmonth=4;break;
		case "May":
			intmonth=5;break;
		case "Jun":
			intmonth=6;break;
		case "Jul":
			intmonth=7;break;
		case "Aug":
			intmonth=8;break;
		case "Sep":
			intmonth=9;break;
		case "Oct":
			intmonth=10;break;
		case "Nov":
			intmonth=11;break;
		case "Dec":
			intmonth=12;break;
		default:
			intmonth=0;
	}
        write_file("/web/files/onlineuser",year+"-"+intmonth+"-"+day+" "+hour+":"+minute+":"+second+"\n",0);
	write_file("/web/files/onlineuser",CHINESE_MUD_NAME + "已经执行了" + time + "\n",0);
	while ( j-- )
		{
                      if( !environment(list[j])||list[j]->query("env/invisibility")>1 ) continue;
			str1=list[j]->query("id")+"|"+list[j]->query("name")+"|"+RANK_D->query_rank(list[j])+"|"+list[j]->query("family/family_name")+"|";
			str1=str1+list[j]->query("nickname");

                        str1=str1+"|"+query_idle(list[j]);
                        str1=str1+"|"+query_ip_number(list[j]);
			str1=str1+"\n";
//			printf("%s\n",str1)
                        if(wizardp(list[j]))
                        {
                            if (!list[j]->query("env/invisibility"))
                            {
                            	wo++;
	                        write_file("/web/files/onlineuser",str1,0);
	                    }
                        }
                        else
			{                        
	                    write_file("/web/files/onlineuser",str1,0);
                            uo++;
                        }
		}
        rm("/web/files/onlinenum");
        write_file("/web/files/onlinenum",wo+"\n"+uo,0);
//        remove_call_out("listuser");
//        call_out("listuser",300);
}
void create()
{
	remove_call_out("listuser");
	call_out("listuser",1);
}
