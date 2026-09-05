// diaoren.c 
// Zine 2012/10/14
inherit F_CLEAN_UP;
#include <ansi.h>
#include "cmd_assist.h"
#define GOD "zine"
int help(object me);
int main(object me,string arg)
{
	mixed tm=localtime(time());
	object song,people;
	string pro,pl,posi,msg,benefit="diaoren",type="month",month=sprintf("%d-%d", tm[5], tm[4]+1),*legal_posi=({}),
		*wen=({"同中书门下平章事","参知政事","尚书左仆射","尚书右仆射","门下侍郎","中书侍郎","吏部尚书",}),
		*wu=({"枢密使","枢密副使","知枢密院事","同知枢密院事","殿前都都指挥使"});
	mapping *title;
	int depart,i,count=0;
	if (arg=="-h")
	return help(me);
	if (me->query("id")!=GOD&&!DASONG_D->identification(me,wen)&&!DASONG_D->identification(me,wu))
	return deny(me);
	song_cycle(me,type,benefit);
	if (me->query("song/"+benefit+"/times")>=3&&me->query("id")!=GOD)
	{
		tell_object(me,"本月你已调任过至少三名官员的职务了。\n");
		return 1;
	}
	if (DASONG_D->identification(me,wen)||(me->query("id")==GOD&&me->query("song/pro")=="文"))
	pro="文";
	if (DASONG_D->identification(me,wu)||(me->query("id")==GOD&&me->query("song/pro")=="武"))
	pro="武";
	song=load_object("/d/song/record/positions");
	if (song->query("give_titles"))
	title=song->query("give_titles");
	else
	title=DASONG_D->upper_title();
	if (!arg||arg=="")
	{
		msg="目前可调任的高级职位有：\n";
		for (i=0;i<sizeof(title);i++)
		{
			if (title[i]["pro"]==pro||title[i]["pro"]=="兼")
			{
				if (title[i]["no_diaoren"])
				continue;
				if (title[i]["pin"]<=DASONG_D->get_my_pin(me)&&me->query("id")!=GOD)
				continue;
				/*if (title[i]["term"]&&time()-me->query("song/term/"+title[i]["title"]+"/start_date")<5184000)
				continue;*/
				if (title[i]["owner"]==""||(arrayp(title[i]["owner"])&&title[i]["vacany"]>0))
				{
					legal_posi+=({title[i]["title"]});
					msg+=HIW+"★"+HBRED+HIW+title[i]["title"]+NOR+HIR;
				}
				else
				msg+=WHT+"☆"+WHT+title[i]["title"]+NOR+HIR;
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
	if (member_array(posi,legal_posi)!=-1)
	{
		tell_object(me,posi+"并不满足调任条件，或无空缺。\n");
		return 1;
	}
	if (!people=find_player(pl))
	{
		tell_object(me,pl+"并不在线！\n");
		return 1;
	}
	if (!people->query("song/pro"))
	{
		tell_object(me,people->name()+"并不是大宋官员。\n");
		return 1;
	}
	if (!DASONG_D->jilu_pin(people)||(DASONG_D->jilu_pin(people)>6&&people->query("song/pro")!="文")||(DASONG_D->jilu_pin(people)>5&&people->query("song/pro")=="文"))
	{
		tell_object(me,people->name()+"这样的低级官员，你就不用插手了。\n");
		return 1;
	}
	if (DASONG_D->get_my_pin(people)<2&&me->query("id")!=GOD)
	{
		tell_object(me,people->name()+"这个级别的官员，需要廷推议定。\n");
		return 1;
	}
	if (people->query("song/pro")!=me->query("song/pro")&&me->query("id")!=GOD)
	{
		tell_object(me,"文臣不管武将，武将不管文臣，这是祖制。\n");
		return 1;
	}
	if (month==people->query("song/neige_change")&&me->query("id")!=GOD)
	{
		tell_object(me,"本月调令刚刚生效，此刻不宜调动"+people->query("name")+"。\n");
		return 1;
	}
	for (i=0;i<sizeof(title);i++)
	{
		if (posi==title[i]["title"])
		depart=title[i]["department"];
	}
	if (!depart)
	{
		tell_object(me,"大宋无"+posi+"这样的官衔。\n");
		return 1;
	}
	song=load_object("/d/song/record/positions");
	title=song->query("give_titles");
	if (posi==people->query("song/title"))
	{
		tell_object(me,people->query("name")+"不正在"+posi+"的位置上吗？\n");
		return 1;
	}
	people->set("song/neige_change",month);
	people->set_temp("song/hor_promote",3);
	people->set_temp("song/hor_promote_title",posi);
	people->set_temp("song/hor_promote_depart",depart);
	if (DASONG_D->position_me(people)==-1)
	{
		tell_object(me,"调令签署失效，可能"+people->query("name")+"的功勋度并不足以胜任此职位或这此职位并无空缺。\n");
		return 1;
	}
	message_vision("$N签署调令，将$n调任为"+posi+"。\n",me,people);
	if (me->query("song/pro")=="武")
	CHANNEL_D->do_channel(this_object(), "dasong", me->query("song/title")+me->query("name")+"("+capitalize(me->query("id"))+")签署枢密院调令，将"+people->query("name")+"("+capitalize(people->query("id"))+")职位变更为"+posi+"。", -1);
	else
	CHANNEL_D->do_channel(this_object(), "dasong", me->query("song/title")+me->query("name")+"("+capitalize(me->query("id"))+")签署政事堂调令，将"+people->query("name")+"("+capitalize(people->query("id"))+")职位变更为"+posi+"。", -1);
	people->delete_temp("song/hor_promote");
	people->delete_temp("song/hor_promote_title");
	DASONG_D->reset_positions();
	return 1;
}
int help(object me)
{
    write("
指令格式 : song diaoren <id> to <职位>
调任某大宋官员到另一职位。
"    );
    return 1;
}
