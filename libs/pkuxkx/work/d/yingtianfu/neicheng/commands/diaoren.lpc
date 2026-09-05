// diaoren.c 
// Zine 2012/10/14
#include <ansi.h>
#include "cmd_assist.h"
inherit F_CLEAN_UP;
#include "/d/yingtianfu/neicheng/npc/promote.h"
int help(object me);
int main(object me,string arg)
{
	mixed tm=localtime(time());
	object ming,people;
	string pl,posi,msg,benefit="diaoren",type="month",month=sprintf("%d-%d", tm[5], tm[4]+1);
	mapping *title;
	int depart,i,count=0,pin;
	if (arg=="-h")
	return help(me);
	if (me->query("id")!="zine"&&!identifications(me,({"保和殿大学士","文华殿大学士","武英殿大学士","文渊阁大学士","体仁阁大学士","东阁大学士","五军都督府 大都督","五军都督府 左都督","五军都督府 右都督","五军都督府 都督同知"})))
	return deny(me);
	ming_cycle(me,type,benefit);
	if (me->query("ming/"+benefit+"/times")>=3&&me->query("id")!="zine")
	{
		tell_object(me,"本月，你已调任过至少三名官员的职务了。\n");
		return 1;
	}
	if (!arg||arg=="")
	{
		ming=load_object("/d/yingtianfu/neicheng/shengzhi");
		ming->restore();
		if (ming->query("give_titles"))
		title=ming->query("give_titles");
		else
		title=upper_title;
		msg="目前可调任的高级职位有：\n";
		for (i=0;i<sizeof(title);i++)
		{
			if (title[i]["pro"]==me->query("ming/pro"))
			{
				if (title[i]["owner"]!="")
				msg+=WHT+"☆"+WHT+title[i]["title"]+NOR+HIR;
				else
				msg+=HIW+"★"+HBRED+HIW+title[i]["title"]+NOR+HIR;
				switch (title[i]["pin"])
				{
				case 1:
				msg+=" 一品";
				break;
				case 2:
				msg+=" 二品";
				break;
				case 3:
				msg+=" 三品";
				break;
				}
				msg+=" "+NOR;
				count+=1;
				if (count%4==0&&count!=0)
				{
					msg+="\n";
				}
			}
		}
		msg+="\n";
		msg+=HIW"★"+NOR+"表示可调任官职，"+WHT+"☆"+NOR+"表示已占用官职。\n";
		tell_object(me,msg);
		return 1;
	}
	if( sscanf(arg, "%s to %s", pl, posi)!=2 )
	{
		tell_object(me,"调任的格式是diaoren <人名> to <职位>。\n");
		return 1;
	}
	if (!people=find_player(pl))
	{
		tell_object(me,pl+"并不在线！\n");
		return 1;
	}
	if (!people->query("mingpin"))
	{
		tell_object(me,people->name()+"并不是大明官员。\n");
		return 1;
	}
	if (people->query("mingpin")>3)
	{
		tell_object(me,people->name()+"这样的低级官员，你就不用插手了。\n");
		return 1;
	}
	if (people->query("mingpin")<2&&me->query("id")!="zine")
	{
		tell_object(me,people->name()+"这个级别的官员，需要廷推议定。\n");
		return 1;
	}
	if (people->query("ming/pro")!=me->query("ming/pro")&&me->query("id")!="zine")
	{
		tell_object(me,"文臣不管武将，武将不管文臣，这是祖制。\n");
		return 1;
	}
	if (month==people->query("ming/neige_change")&&me->query("id")!="zine")
	{
		tell_object(me,"本月调令刚刚生效，此刻不宜调动"+people->query("name")+"。\n");
		return 1;
	}
	for (i=0;i<sizeof(upper_title);i++)
	{
		if (posi==upper_title[i]["title"])
		{
			pin=upper_title[i]["pin"];
			depart=upper_title[i]["department"];
		}
	}
	if (!depart)
	{
		tell_object(me,"大明无"+posi+"这样的官衔。\n");
		return 1;
	}
	if (pin!=people->query("mingpin"))
	{
		tell_object(me,WHT+people->name()+WHT+"的官品("+chinese_number(people->query("mingpin"))+"品)与"+posi+"所需的官品不符。\n"+NOR);
		return 1;
	}
	ming=load_object("/d/yingtianfu/neicheng/shengzhi");
	ming->restore();
	title=ming->query("give_titles");
	for (i=0;i<sizeof(title);i++)
	{
		if (posi==title[i]["title"]&&title[i]["owner"]!="")
		{
			if (title[i]["owner"]==people->query("id"))
			{
				tell_object(me,people->query("name")+"不正在"+posi+"的位置上吗？\n");
				return 1;
			}
			else
			{
				tell_object(me,posi+"此刻并无空缺。\n");
				return 1;
			}
		}
	}
	people->set("ming/neige_change",month);
	people->set_temp("ming/hor_promote",3);
	people->set_temp("ming/hor_promote_title",posi);
	people->set_temp("ming/hor_promote_depart",depart);
    position_me(people);
	message_vision("$N签署调令，将$n调任为"+posi+"。\n",me,people);
	if (me->query("ming/pro")=="武")
	message("daming",HIW"【大明】"+me->query("ming/title")+me->query("name")+HIW+"("+capitalize(me->query("id"))+")签署五军都督府调令，将"+people->query("name")+HIW+"("+capitalize(people->query("id"))+")职位变更为"+posi+"。\n"NOR,users());
	else
	message("daming",HIW"【大明】"+me->query("ming/title")+me->query("name")+HIW+"("+capitalize(me->query("id"))+")签署内阁调令，将"+people->query("name")+HIW+"("+capitalize(people->query("id"))+")职位变更为"+posi+"。\n"NOR,users());
	people->delete_temp("ming/hor_promote");
	people->delete_temp("ming/hor_promote_title");
	DAMING_D->reset_positions();
	return 1;
}
int help(object me)
{
    write("
指令格式 : ming diaoren <id> to <职位>
调任某大明官员到另一职位。
"    );
    return 1;
}
