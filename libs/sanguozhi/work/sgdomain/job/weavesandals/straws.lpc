// straws by row
// this is used for the job of 编草鞋底
#include <mudlib.h>
#include <ansi.h>
#define JOBID "weavesandals"
inherit OBJ;
inherit M_INPUT;

string *desc = ({"杂七杂八的"+YEL+"茅草丛"+NOR+"。\n"+
"风吹草动，发出『唰唰』的声音，你可以试着拔一点下来(pull straws)。\n",
"看上去高低不平，好象被人拔过(pull straws)。\n",
"放眼望去，大多只剩下根茎了(pull straws)。\n",});

private int status;
private int pulled;
void setup()
{
	set_id("straws", YEL+"茅草丛"+NOR);
	set_in_room_desc("路边泛黄的"+YEL+"茅草丛"+NOR+"(straws)。");
	status=0;
	pulled=0;
	call_out("grow", 15);
}
string long()
{
	if(status<11)
	return desc[0];
	if(status<21)
	return desc[1];
	if(status<41)
	return desc[2];
}
void grow()
{
	call_out("grow",15);
	pulled=pulled-1;
	if(pulled<0)
	pulled=0;
	if(pulled)
	return;
	status=status-2;
	if(status<0)
	status=0;
}
int pull()
{
	object ob;
	if(this_body()->query_job(JOBID,"beg_time")==0)
	{
	int m_hp;
	m_hp=this_body()->query_cur_hp();
	if (m_hp<10)
	{write("你省省吧。\n");
	return 1;
	}
	m_hp-=15;
	this_body()->set_cur_hp(m_hp);
	this_body()->simple_action(
	"$N抓住几根茅草一用力，结果手掌被划了几个口子。\n");
	return 1;
	}
	if (status<41)
	{
	int m_hp;
	m_hp=this_body()->query_cur_hp();
	if (m_hp<10)
	{write("你太累了，休息一会儿吧。\n");
	return 1;
	}
	m_hp-=15;
	this_body()->set_cur_hp(m_hp);
	status=status+random(5);
	this_body()->simple_action(
	"$N又拉又拽大费周折，总算扯下一把泛黄的"+YEL+"茅草"+NOR+"。\n",);
	ob=new(__DIR__"mcao");
	ob->move(this_body());
	return 1;
	}
	else
	write("茅草被拔光了。\n");
	return 1;
}