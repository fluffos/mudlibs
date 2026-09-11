// listcountry.c
// by fire on 2 July 1998
// this is used to list information of countries
#include <mudlib.h>
#include <daemons.h>
inherit CMD;
inherit M_GLOB;
string bar="〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n";
private void main(string arg)
{
    string * list;
    int count;
    string p_f,p_sw;
    mixed data;
    mixed *m;
    mixed * info;
    int j;
    object ob;
	string disp="";
	string disp_tmp;
    list = sort_array(COUNTRY_D->list_countries(), 1);
    count = sizeof(list);
        if(!arg)
                arg="";
        if(sscanf(arg, "%s %s", p_f,p_sw)!=2)
                p_f=arg;
        if(!p_f || (p_f==""))
                p_f="*";
        else if ( !has_magic(p_f) )
                p_f=p_f+"*";
		if (p_f[0..0]=="/")
		{	p_sw=p_f[0..<2];
			p_f="*";
		}
        if(!p_sw)
                p_sw="/l";
        p_f = "^"+translate(p_f)+"$";
		if(p_sw=="/")
			p_sw="/?";
        list = regexp(list, p_f);
		
        if(!list)
        {
                printf("没有这样的国家．\n");
                return ;
        }
        else
        {
                int i;
                count=sizeof(list);
                switch (p_sw)
                {
                        case "/l" :  // just list
							disp_tmp=sprintf("   国家代号　　国家名称\n");
							disp=disp+disp_tmp;
							disp_tmp=sprintf(bar);
							disp=disp+disp_tmp;
                            for(i=0;i<count;i++)
							{
                                disp_tmp=sprintf("%11s  %8s\n",list[i],COUNTRY_D->get_country(list[i],"name"));
								disp=disp+disp_tmp;
							}
							disp_tmp=sprintf(bar);
							disp=disp+disp_tmp;
                            disp_tmp=sprintf("共查到：%d个国家。\n",count);
							disp=disp+disp_tmp;
							more(disp);
							return;
						case "/1":	// system
							disp_tmp=sprintf("   国家代号    名称   首府  官员 领地 大城 城 镇 村 关  总人口  总兵力\n");
							disp=disp+disp_tmp;
							disp_tmp=sprintf(bar);
							disp=disp+disp_tmp;
							for(i=0;i<count;i++)
							{
								disp_tmp=sprintf("%11s %8s %6s %3d  %3d  %3d %3d%3d%3d%3d %7d %7d\n",
									list[i],COUNTRY_D->get_country(list[i],"name"),
									AREA_D->get_area(CHAR_D->get_char(list[i],"area"),"name"),
									sizeof(CHAR_D->check_char("nation",list[i])),
									sizeof(AREA_D->check_area("nation",list[i])),
									sizeof(filter_array(AREA_D->check_area("nation",list[i]),
										(:AREA_D->get_area($1,"level")==5:))),
									sizeof(filter_array(AREA_D->check_area("nation",list[i]),
										(:AREA_D->get_area($1,"level")==4:))),
									sizeof(filter_array(AREA_D->check_area("nation",list[i]),
										(:AREA_D->get_area($1,"level")==3:))),
									sizeof(filter_array(AREA_D->check_area("nation",list[i]),
										(:AREA_D->get_area($1,"level")==2:))),
									sizeof(filter_array(AREA_D->check_area("nation",list[i]),
										(:AREA_D->get_area($1,"level")==1:))),
									COUNTRY_D->get_country(list[i],"population"),
									COUNTRY_D->get_country(list[i],"soldier"));
								disp=disp+disp_tmp;
							}
							disp_tmp=sprintf(bar);
							disp=disp+disp_tmp;
                            disp_tmp=sprintf("共查到：%d个国家。\n",count);
							disp=disp+disp_tmp;
							more(disp);
							return;
						case "/2":	
							disp_tmp=sprintf("   国家代号    名称  国库(金　    粮　 物)  地方(金        粮      物)\n");
							disp=disp+disp_tmp;
							disp_tmp=sprintf(bar);
							disp=disp+disp_tmp;
							for(i=0;i<count;i++)
							{
								disp_tmp=sprintf("%11s %8s%7d%8d%7d%9d%10d%9d\n",
									list[i],COUNTRY_D->get_country(list[i],"name"),
									COUNTRY_D->get_country(list[i],"gold"),
									COUNTRY_D->get_country(list[i],"food"),
									COUNTRY_D->get_country(list[i],"stuff"),
									COUNTRY_D->get_country(list[i],"goldlocal"),
									COUNTRY_D->get_country(list[i],"foodlocal"),
									COUNTRY_D->get_country(list[i],"stufflocal"));
								disp=disp+disp_tmp;
							}
							disp_tmp=sprintf(bar);
							disp=disp+disp_tmp;
                            disp_tmp=sprintf("共查到：%d个国家。\n",count);
							disp=disp+disp_tmp;
							more(disp);
							return;
						default:
							printf("Please try listcountry /1 or listcountry /2 or listcountry /l\n");
							return;
              }
        }
}
