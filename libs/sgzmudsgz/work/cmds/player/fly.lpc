// fly.c by fire on Jec 30 1997
#include <mudlib.h>
#include <ansi.h>
#include <daemons.h>
#define FLY_HELP PHELP+"help_fly.txt"
inherit CMD;
void show_map(string file)
{
        string mapinfo;
		string *list;
		int p_num,i;
        mapinfo=read_file(file);
        printf(mapinfo);
		list = sort_array(AREA_D->list_areas(), 1);
		p_num=sizeof(list);
		for(i=0;i<p_num;i+=2)
		{
			if((i+1)<p_num)
			{
				printf("%12s%12s%16s%12s\n",list[i],AREA_D->get_area(list[i],"name"),
					list[i+1],AREA_D->get_area(list[i+1],"name"));
			}
			else
			{
				printf("%12s%12s\n",list[i],AREA_D->get_area(list[i],"name"));
			}
		}
}
void delay_look()
{
        this_body()->force_look();
}
void delay_fly()
{
this_body()->simple_action(YEL+"$N的身影突然出现在一阵尘土中。"+NOR+"\n\n");
	delay_look();
//        call_out((: delay_look :),0);
}
void fly_map(string file)
{
        int p_level;
        int p_hp;
        object env;
        p_level=this_body()->query_sk_level("qmdj");
        if (p_level<10)
        {
                this_body()->other_action("$N念了半天口诀，可什么事也没发生。\n");
                write("你的奇门遁甲之术还不行呀。\n");
                return;
        }
        p_hp=this_body()->query_cur_hp();
        if (p_hp<30)
        {
                this_body()->other_action("$N念着口诀，一头向地下钻去，结果头上碰了个大胞。\n");
                write("体力不足，会被憋死的。\n");
                return;
        }
        this_body()->simple_action(HIG+"$N念着口诀，一头向地下钻去，转眼就不见了。"+NOR+"\n\n");
        this_body()->move(file);
	delay_fly();
//        call_out((: delay_fly : ),0);
}
void main(string arg) 
{
	mixed p_path,p_name;
	string m_mark="";
        if(!wizardp(this_body()))
        {
                write("人怎么会飞？还是坐马车妥当些。(help yizhan)\n");
 		return;
	}
	if(arg)
	sscanf(arg,"%s %s",arg,m_mark);
    p_path=AREA_D->get_area(arg,"path");
    p_name=AREA_D->get_area(arg,"fly");
        if(stringp(m_mark)&&(m_mark=="m")&&wizardp(this_body()))
		p_name=AREA_D->get_area(arg,"meeting");
        if (!arg)
        {
                show_map(FLY_HELP);
                return;
        }
        if(!stringp(p_path)||!stringp(p_name))
        {
                write("没法土遁到那，用fly查阅可土遁到的地区。\n");
                return;
        }
        fly_map(p_path+p_name); 
        return;
}
