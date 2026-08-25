// listarea.c
// by fire on 17 June 1998
// this is used to list information of areas
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
    list = sort_array(AREA_D->list_areas(), 1);
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
                p_sw="/?";
        p_f = "^"+translate(p_f)+"$";
		if(p_sw=="/")
			p_sw="/?";
        list = regexp(list, p_f);
        if(!list)
        {
                printf("没有这样的地区．\n");
                return ;
        }
        else
        {
                int i;
                count=sizeof(list);
                switch (p_sw)
                {
                        case "/l" :  // just list
								disp_tmp=sprintf(" 地区代号　　地区名称\n");
								disp+=disp_tmp;
								disp_tmp=sprintf(bar);
								disp+=disp_tmp;
                                for(i=0;i<count;i++)
								{
                                    disp_tmp=sprintf("%9s  %8s\n",list[i],AREA_D->get_area(list[i],"name"));
									disp+=disp_tmp;
								}
								disp_tmp=sprintf(bar);
								disp+=disp_tmp;
                                disp_tmp=sprintf("共查到：%d个地区。\n",count);
								disp+=disp_tmp;
								more(disp);
					            return;
						case "/s":	// system
							disp_tmp=sprintf("   代号　 　名称   别称       地图       土遁     会议室  路径\n");
							disp+=disp_tmp;
							disp_tmp=sprintf(bar);
							disp+=disp_tmp;
							for(i=0;i<count;i++)
							{
								p_f=AREA_D->get_area(list[i],"path");
								if(stringp(p_f))
									p_f=p_f[<14..<1];
								else
									p_f="━━";
								disp_tmp=sprintf("%9s%8s%8s%10s %10s %10s %s\n",list[i],AREA_D->get_area(list[i],"name"),
									AREA_D->get_area(list[i],"area"),
									AREA_D->get_area(list[i],"map"),
									AREA_D->get_area(list[i],"fly"),
									AREA_D->get_area(list[i],"meeting"),
									p_f);
								disp+=disp_tmp;
							}
							disp_tmp=sprintf(bar);
							disp+=disp_tmp;
                            disp_tmp=sprintf("共查到：%d个地区。\n",count);
							disp+=disp_tmp;
							more(disp);
							return;
						case "/1":  // game part 1
							disp_tmp=sprintf("   代号　 　名称  等级  人口  安定 工业 农业 商业  物资 　 粮草   　金\n");
							disp+=disp_tmp;
							disp_tmp=sprintf(bar);
							disp+=disp_tmp;
							for(i=0;i<count;i++)
							{
								disp_tmp=sprintf("%9s%8s %3d %7d %3d  %3d  %3d  %3d%7d %7d%7d\n",list[i],AREA_D->get_area(list[i],"name"),
									AREA_D->get_area(list[i],"level"),
									AREA_D->get_area(list[i],"population"),
									AREA_D->get_area(list[i],"safe"),
									AREA_D->get_area(list[i],"industry"),
									AREA_D->get_area(list[i],"agriculture"),
									AREA_D->get_area(list[i],"business"),
									AREA_D->get_area(list[i],"stuff"),
									AREA_D->get_area(list[i],"food"),
									AREA_D->get_area(list[i],"gold"));
								disp+=disp_tmp;
							}
							disp_tmp=sprintf(bar);
							disp+=disp_tmp;
                            disp_tmp=sprintf("共查到：%d个地区。\n",count);
							disp+=disp_tmp;
							more(disp);
							return;
						case "/2":  // game part 1
							disp_tmp=sprintf("   代号　 　名称    国君   太守    士兵 训练 士气 国税 地税 天气 状态 邻地\n");
							disp+=disp_tmp;
							disp_tmp=sprintf(bar);
							disp+=disp_tmp;
							for(i=0;i<count;i++)
							{
								disp_tmp=sprintf("%9s%8s %6s %6s %7d %3d  %3d  %3d  %3d  %s %s %3d\n",list[i],AREA_D->get_area(list[i],"name"),
								CHAR_D->get_char(AREA_D->get_area(list[i],"nation"),"name"),
								CHAR_D->get_char(AREA_D->get_area(list[i],"leader"),"name"),
									AREA_D->get_area(list[i],"soldier"),
									AREA_D->get_area(list[i],"train"),
									AREA_D->get_area(list[i],"morale"),
									AREA_D->get_area(list[i],"taxnation"),
									AREA_D->get_area(list[i],"taxlocal"),
									DAY_D->get_weather_short(AREA_D->get_area(list[i],"weather")),
									AREA_D->get_area(list[i],"statusstr"),
									sizeof(AREA_D->get_area(list[i],"neighbor")));
								disp+=disp_tmp;
							}
							disp_tmp=sprintf(bar);
							disp+=disp_tmp;
                            disp_tmp=sprintf("共查到：%d个地区。\n",count);
							disp+=disp_tmp;
							more(disp);
							return;
						case "/3":  // game part 1
							disp_tmp=sprintf("   代号　 　名称    金月入 金月出 粮年入 粮年出 物月入 物月出 将数 在野\n");
							disp+=disp_tmp;
							disp_tmp=sprintf(bar);
							disp+=disp_tmp;
							for(i=0;i<count;i++)
							{
								string *alllist;
								string *o_list;
								string p_nation;
								p_nation=AREA_D->get_area(list[i],"nation");
								alllist=CHAR_D->check_char("area",list[i]);
								o_list=filter_array(alllist,(:CHAR_D->get_char($1,"nation")==$(p_nation):));
								disp_tmp=sprintf("%9s%8s %7d%7d%7d%7d%7d%7d %4d %4d\n",list[i],AREA_D->get_area(list[i],"name"),
									AREA_D->get_area(list[i],"goldin"),
			AREA_D->get_area(list[i],"goldout")+
			AREA_D->get_area(list[i],"salary"),
									AREA_D->get_area(list[i],"foodin"),
									AREA_D->get_area(list[i],"foodout"),
									AREA_D->get_area(list[i],"stuffin"),
									AREA_D->get_area(list[i],"stuffout"),
									sizeof(o_list),
									sizeof(alllist)-sizeof(o_list));
								disp+=disp_tmp;
							}
							disp_tmp=sprintf(bar);
							disp+=disp_tmp;
                            disp_tmp=sprintf("共查到：%d个地区。\n",count);
							disp+=disp_tmp;
							more(disp);
							return;
  case "/4":  // game part 4
   disp_tmp=sprintf(
"   代号　 　名称    马匹  弓箭  匪人 \n");
   disp+=disp_tmp;
   disp+=bar;
   for(i=0;i<count;i++)
   {
       disp_tmp=sprintf("%9s%8s %6d%6d%6d\n",list[i],
         AREA_D->get_area(list[i],"name"),
         AREA_D->get_area(list[i],"horse"),
         AREA_D->get_area(list[i],"bow"),
         AREA_D->get_area(list[i],"bandit"));
      disp+=disp_tmp;
   }
   disp+=sprintf(bar);
   disp+=sprintf("共查到：%d个地区。\n",count);
   more(disp);
   return;
  default:
  printf("用法不对，用help listarea看详细帮助。\n");
							return;
                }
        }
}
