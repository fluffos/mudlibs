// listchar.c
// by fire on 26 June 1998
// this is used to list information of chars
#include <mudlib.h>
#include <daemons.h>
inherit CMD;
inherit M_GLOB;
string bar="〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n";
int s_wuli,s_zhimou,s_meili;
mixed p_tmp;
private void main(string arg)
{
    string * list;
    int count;
    string p_f,p_sw;
    mixed data;
    mixed *m;
    mixed * info;
    int i,j;
    string * para;
	string disp="";
	string disp_tmp;
    object ob;
    list = sort_array(CHAR_D->list_chars(), 1);
    count = sizeof(list);
        if(!arg)
	{
                more_file(PHELP+"listchar");
		return;
	}
        if(sscanf(arg, "%s %s", p_f,p_sw)!=2)
                p_f=arg;
        if (p_f[0..0]=="/")
        {       if(p_sw)
			p_sw=p_f+" "+p_sw;
		else
			p_sw=p_f;
                p_f="";
        }
        if(!p_f || (p_f==""))
                p_f="*";
        else if ( !has_magic(p_f) )
                p_f=p_f+"*";
        if(!p_sw)
                p_sw="/l";
        p_f = "^"+translate(p_f)+"$";
		if(p_sw=="/")
			p_sw="/?";
        list = regexp(list, p_f);
		
        p_sw=" /l "+p_sw;
        para=explode(p_sw," /");
        for(i=0;i<sizeof(para);++i)
        {
                switch(para[i][0])
                {
                        case 'l':
                        case '1':
                        case '2':
				p_sw="/"+para[i];
				break;
                        case 'v':
				{
					string p_val;
					string p_para,p_parav;
                                        mixed p_value;
                                        p_val=para[i][2..];
					sscanf(p_val,"%s %s",p_para,p_parav);
					if(!p_parav)
						break;
					if(p_parav=="0")
						p_value=0;
					else if (restore_variable(p_parav))
						p_value=restore_variable(p_parav);
					else
						p_value=p_parav;
					list=filter_array
						(list,(:CHAR_D->get_char(($1),$(p_para))==$(p_value):));
				}
                                 break;
			default:
				p_sw="/l";
				break;
                }
        }
        if(!list)
        {
                printf("没有这样的角色．\n");
                return ;
        }
        else
        {
                count=sizeof(list);
                switch (p_sw)
                {
                        case "/l" :  // just list
								disp_tmp=sprintf("   角色代号　　角色名称\n");
								disp=disp+disp_tmp;
								disp_tmp=sprintf(bar);
								disp=disp+disp_tmp;
                                for(i=0;i<count;i++)
								{
                                        disp_tmp=sprintf("%11s  %8s\n",list[i],CHAR_D->get_char(list[i],"name"));
										disp=disp+disp_tmp;
								}
								disp_tmp=sprintf(bar);
								disp=disp+disp_tmp;
                                disp_tmp=sprintf("共查到：%d个角色。\n",count);
								disp=disp+disp_tmp;
				more(disp);
								return;
                                                case "/1":  
  disp_tmp=sprintf("  角色代号    名称   字 性别 年龄 武力 智谋 魅力 容貌 类型 状态 事务\n");
							disp=disp+disp_tmp;
							disp_tmp=sprintf(bar);
							disp=disp+disp_tmp;
							for(i=0;i<count;i++)
							{
								p_tmp=CHAR_D->get_char(list[i],"skills");
 if(!mapp(p_tmp)) p_tmp=([]);
								s_wuli=p_tmp["sk_wuli"];
								s_zhimou=p_tmp["sk_zhimou"];
								s_meili=p_tmp["sk_meili"];
								p_tmp=CHAR_D->get_char(list[i],"gift");
if(!mapp(p_tmp)) p_tmp=([]);
 disp_tmp=sprintf("%11s %6s %4s  %2s%5d%5d%5d%5d%5d  %3s %4s %4s\n",list[i],
CHAR_D->get_char(list[i],"name"),
									CHAR_D->get_char(list[i],"zi"),
									(CHAR_D->get_char(list[i],"gender")==1 ? "男" :"女"),
									CHAR_D->get_char(list[i],"age"),
									s_wuli,s_zhimou,s_meili,
									p_tmp["rongmao"],
									(CHAR_D->get_char(list[i],"type")==TYPE_NPC ? "NPC" :"PLY"),
  (CHAR_D->get_char(list[i],"statustr")),CHAR_D->get_char(list[i],"taskstr"));
								disp=disp+disp_tmp;
							}
							disp_tmp=sprintf(bar);
							disp=disp+disp_tmp;
                            disp_tmp=sprintf("共查到：%d个角色。\n",count);
							disp=disp+disp_tmp;
				more(disp);
							return;
                                                case "/2":
							disp_tmp=sprintf("  角色代号    名称   升望   所在地 所属国 朝廷官职 地方官 忠诚 俸禄\n");
							disp=disp+disp_tmp;
							disp_tmp=sprintf(bar);
							disp=disp+disp_tmp;
							for(i=0;i<count;i++)
							{
								disp_tmp=sprintf("%11s %6s %8s %6s %6s %8s %6s  %3d %4d\n",list[i],CHAR_D->get_char(list[i],"name"),
									CHAR_D->get_char(list[i],"reputationstr"),
									AREA_D->get_area(CHAR_D->get_char(list[i],"area"),"name"),
									COUNTRY_D->get_country(CHAR_D->get_char(list[i],"nation"),"name"),
									OFFICER_D->query_rank_name(CHAR_D->get_char(list[i],"ranknation")),
									OFFICER_D->query_rank_name(CHAR_D->get_char(list[i],"ranklocal")),
									CHAR_D->get_char(list[i],"loyalty"),
									CHAR_D->get_char(list[i],"salary"));
							disp=disp+disp_tmp;
							}
							disp_tmp=sprintf(bar);
							disp=disp+disp_tmp;
                            disp_tmp=sprintf("共查到：%d个角色。\n",count);
							disp=disp+disp_tmp;
				more(disp);
							return;
						default:
							printf("Please try listchar /1 or listchar /2 or listchar /l\n");
							return;
                }
        }
}
