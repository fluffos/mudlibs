#include <localtime.h>
// wartime.c
// by listen on Jan 1, 2002


void start(string arg)
{
	int today, tomorrow,war_status;
	int t_time1,t_time2,m_time1,m_time2;
	int next, temp, n_hour, n_min; 
	int *now;
	int shift;
	
	today = localtime(time())[LT_WDAY];
	tomorrow = localtime(time()+24*3600)[LT_WDAY];

	
	if (!DAY_D->get_can_war())
        {
		write("%^H_RED%^&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%^RESET%^\n");
    		write("\n%^H_YELLOW%^汉献帝%^H_CYAN%^诏谕：\n\n    朕观之连年诸侯混战，
    			民不聊生。今上天有好生之德，朕顺应\n天时，令天下各路诸侯%^H_MAGENTA%^"+
 			CHINESE_D->chinese_period(DAY_D->get_change_time())+
 			 "%^H_CYAN%^内不得征战。\n\n                                                   钦此%^RESET%^\n\n");
		write("%^H_RED%^&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%^RESET%^\n");
	}
//	else
//		write("现在战争正开放中.\n");

        if((!arg)||(arg==""))
        {

                write("请用 cmd wartime <nation_id> 来查询具体国家的战争开放时间。\n");
                write("例子：cmd wartime liu bei 查询刘备国的战争开放时间。\n");
                //write("用 help wartime 查看详细帮助。\n");
                return;
        }
        
        if ( !COUNTRY_D->nation_exist(arg))
        {
        	write("没有" + arg + "这个国家，请用info n 来查询国家列表。\n");
        	return;
        }
        war_status = DAY_D->war_status(arg);
	t_time1 = COUNTRY_D->get_wartime(arg,today*2);
	t_time2 = COUNTRY_D->get_wartime(arg,today*2+1);
	m_time1 = COUNTRY_D->get_wartime(arg,tomorrow*2);
	m_time2 = COUNTRY_D->get_wartime(arg,tomorrow*2+1);
        write ("系统当前时间为 " + DAY_D->English_time(time()) + "。\n");
        now = localtime(time());
        n_hour = now[LT_HOUR];
        n_min = now[LT_MIN];
        shift = now[LT_GMTOFF]/3600;
        write (COUNTRY_D->get_country_name(arg) + "战争开放时间如下:\n");
        write ("今日: " + t_time1 + ":00-" + t_time1 +":59 以及 " + t_time2 + ":00-" + t_time2 + ":59。\n");
        write ("明日: " + m_time1 + ":00-" + m_time1 +":59 以及 " + m_time2 + ":00-" + m_time2 + ":59。\n");
        write ("以上时间为24小时制系统当地时间(GMT -" + shift + ")。\n");
        if (war_status == 2)
        {
        	write ("当前状态: %^H_YELLOW%^汉献帝禁止所有的战争%^RESET%^\n");
        	return;
        }
        else if (war_status == 1)
        {
        	write ("当前状态：对" + COUNTRY_D->get_country_name(arg)
        		+ "的战争%^H_CYAN%^关闭%^RESET%^中。\n");
        	//找出最接近的war time 时间
        	//先查看今天
        	if (t_time1 > t_time2)
        	{
        		temp = t_time1;
        		t_time1 = t_time2;
        		t_time2 = temp;
        	}
        	if ( n_hour < t_time1 )
        		next = t_time1*3600 - n_hour*3600 - n_min*60;
        	else if (n_hour < t_time2)
        		next = t_time2*3600 - n_hour*3600 - n_min*60;
        	//再查看明天
        	else
        	{
        		if (m_time1 < m_time2 )
        			next = (24 + m_time1)*3600 - n_hour*3600 - n_min*60;
        		else
        			next = (24 + m_time2)*3600 - n_hour*3600 - n_min*60;
        	}
        	write ("距离最近的" + COUNTRY_D->get_country_name(arg) + "战争开放时间还有: %^H_YELLOW%^"
        		+ CHINESE_D->chinese_period(next) + "%^RESET%^\n");
        }
        else if (war_status == 0)
        {
        	temp = DAY_D->get_temp_wartime (arg);
        	
        	write ("当前状态: 对" + COUNTRY_D->get_country_name(arg)
        			+ "的战争%^H_RED%^开放%^RESET%^中。\n");
        	if ( temp > 0)
        		write ("战争持续时间还有: %^H_YELLOW%^" + CHINESE_D->chinese_period(temp)
        			+ "%^RESET%^\n");
        	else if ( t_time1 == (n_hour+1) || t_time2 == (n_hour+1)) //如果两个wartime 时段是连续的
        		write ("战争持续时间还有: %^H_YELLOW%^" + CHINESE_D->chinese_period((120-n_min)*60)
        			+ "%^RESET%^\n");
        	else
        		write ("战争开放持续时间还有: %^H_YELLOW%^" + CHINESE_D->chinese_period((60-n_min)*60)
        			+ "%^RESET%^\n");
        }
        else
        	write ("请报告巫师,wartime.c 有 BUG!\n");
}