// by fire on Jan 6 1998
// checkemote.c this is used to check the semotes
#include <mudlib.h>
inherit CMD;
inherit M_GLOB;
#define TOO_DAMN_LONG 15
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
    list = sort_array(SOUL_D->list_emotes(), 1);
    count = sizeof(list);
	if(!arg)
		arg="";
	if(sscanf(arg, "%s %s", p_f,p_sw)!=2)
		p_f=arg;
	if(!p_f || (p_f==""))
		p_f="*";
	else if ( !has_magic(p_f) )
		p_f=p_f+"*";
	if(!p_sw)
		p_sw="/l";
        p_f = "^"+translate(p_f)+"$";
        list = regexp(list, p_f);
        if(!list)
	{
		printf("没有这样的semote\n");
		return ;
	}
	else
	{
		int i;
		count=sizeof(list);
		switch (p_sw)
		{
			case "/l" :  // just list
				for(i=0;i<count;i++)
					printf("%s\n",list[i]);
				printf("共查到：%d个semote。\n",count);
				return;
			case "/s" : // similar to show
			        if(!(wizardp(this_body()->query_userid())))
			       {
		                	printf("对不起，这个选项只对巫师开放。\n");
	                		return;
        			}
				for(i=0;i<count;i++)
				{
					printf("【 %s 】\n",list[i]);
					data=SOUL_D->query_emote(list[i]);
					m=keys(data);
					for(j=0;j<sizeof(m);j++)
					{
						if(stringp(data[m[j]]))
						{
							printf("%O -> %s\n",m[j],data[m[j]]);
						}
						else
						{
					            printf("%O -> %s\n", m[j], implode(data[m[j]], "\n\t-> "));
						}
					}
				}
				printf("共查到：%d个semote。\n",count);
                                return;
			case "/c":
            ob=new("/sgdomain/npc/diaochan");
            for(i=0;i<count;i++)
            {
                disp_tmp=sprintf("【 %s 】\n",list[i]);
				disp+=disp_tmp;
                data=SOUL_D->query_emote(list[i]);
                if ( data[""] )
                {
                   info = SOUL_D->get_soul(list[i], "", ({ }));
                   disp_tmp=sprintf("没有目标：%s",info[1][0]);
				   disp+=disp_tmp;
                }
                if ( data["LIV"] )
                {
                    info = SOUL_D->get_soul(list[i], "LIV", ({ ob }));
                    disp_tmp=sprintf("对他人：%s",info[1][0]);
				   disp+=disp_tmp;
                }
                if ( data["STR"] )
                {
                    info = SOUL_D->get_soul(list[i], "LIV", ({ this_body() }));
                    disp_tmp=sprintf("对自己：%s",info[1][0]);
				   disp+=disp_tmp;
                }
            }
            destruct(ob);
            disp_tmp=sprintf("共查到：%d个semote。\n",count);
		   disp+=disp_tmp;
		   more(disp);
		}
	}
}
