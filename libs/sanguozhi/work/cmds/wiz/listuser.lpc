// listuser.c
// by fire on 17 June 1998
// this is used to list information of users
#include <mudlib.h>
#include <daemons.h>
#include <security.h>
// inherit M_ACCESS;
inherit CMD;
inherit M_GLOB;
string bar="〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n";
private void main(string arg)
{
    mixed list;
    int count;
    string p_f,p_sw;
    int i;
	string p_level,p_name,p_ip;
	int p_time,c_time,p_isonline;
	string p_disgroup="",p_sort="id";
    string disp="";
    string disp_tmp;
	mixed para;
	mixed * id_list=({});
	mixed us=([]);
	mixed m_unknow;
    set_privilege(1);
    list = LAST_LOGIN_D->query_times();
    count = sizeof(list);
	c_time=time();
	
	for(i=0;i<count;++i)
	{
		us[list[i][1]]=([]);
		p_time=c_time-list[i][0];
		p_ip=list[i][2];
//                m_unknow=unguarded(1, (: call_other, USER_D, "query_variable", list[i][1], ({ "chinese_id", }) :));
		if(sizeof(m_unknow))
			p_name=m_unknow[0];
		else
			p_name="______";
p_name=FINGER_D->get_chinese_id(list[i][1]);
		p_level=adminp(list[i][1]) ? "a" : wizardp(list[i][1]) ? "w" : "p";
		p_isonline=objectp(find_user(list[i][1]));
		if(p_time>600)
			p_time=p_time-(p_time%60);
		if(p_time>36000)
			p_time=p_time-(p_time%3600);
		if(p_time>864000)
                        p_time=p_time-(p_time%86400);
		if(!wizardp(this_body()))
			p_ip="255.255.255.1";
		us[list[i][1]]=({p_name,p_level,p_isonline,p_time,p_ip});
		id_list+=({list[i][1]});
	}
	if(!arg)
            arg="";
    if(sscanf(arg, "%s %s", p_f,p_sw)!=2)
            p_f=arg;
    if(!p_f || (p_f==""))
            p_f="*";
    else if ( !has_magic(p_f) )
        p_f=p_f+"*";
    if (p_f[0..0]=="/")
    {       p_sw=p_f[0..<2]+" "+p_sw;
            p_f="*";
    }
	p_sw=" "+p_sw;
	para=explode(p_sw," /");
	for(i=0;i<sizeof(para);++i)
	{
		switch(para[i][0])
		{
			case 'w':
			case 'a':
			case 'p':
				p_disgroup=para[i][0..0];
				break;
			case 's':
				if(sizeof(para[i])>1)
				{
                                        switch (para[i][1..1])
					{
					case "p":
					case "n":
					case "t":
                                                p_sort=para[i][1..1];
						break;
					}
				}
		}
	}
    p_f = "^"+translate(p_f)+"$";
    id_list = regexp(id_list, p_f);
	switch(p_disgroup)
	{
	case "p":
		id_list=filter_array(id_list,(:$(us)[$1][1]=="p":));
		break;
	case "a":
		id_list=filter_array(id_list,(:$(us)[$1][1]=="a":));
		break;
	case "w":
		id_list=filter_array(id_list,(:$(us)[$1][1]!="p":));
		break;
	}
        switch(p_sort)
	{
	case "p":
		id_list=sort_array(id_list,
			(: ( $(us)[$1][4]>$(us)[$2][4]) ? 1 : -1 :));
		break;
	case "n":
		id_list=sort_array(id_list,
			(: ( $(us)[$1][0]>$(us)[$2][0]) ? 1 : -1 :));
		break;
	case "t":
		id_list=sort_array(id_list,
                        (: ( $(us)[$1][2]<$(us)[$2][2]) ? 1 : 
		($(us)[$1][3]>$(us)[$2][3]) ? 1 : -1 :));
		break;
	default:
		id_list=sort_array(id_list,1);
	}
		
	if(!id_list)
    {
        printf("没有这样的用户．\n");
        return ;
    }
    disp_tmp=sprintf("ＩＤ　    姓名　    身分　联离线时间　          ＩＰ\n");
    disp+=disp_tmp;
    disp_tmp=sprintf(bar);
    disp+=disp_tmp;
    count=sizeof(id_list);
	for(i=0;i<count;i++)
	{
        disp_tmp=sprintf("%-8s  %-8s  %4s  %6s%-16s %s\n",
			id_list[i],
			us[id_list[i]][0],
			(us[id_list[i]][1]=="p" ? "玩家": 
			us[id_list[i]][1]=="w" ? "巫师" : "大神"),
			(us[id_list[i]][2] ? "联线：" : "离线："),
			CHINESE_D->chinese_period(us[id_list[i]][3]),
			us[id_list[i]][4]);
			disp+=disp_tmp;
	}
	disp+=sprintf("共查到%d名用户．\n",count);
	more(disp);
}
