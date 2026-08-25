// woods by row
// this is used for the job of 砍柴
#include <mudlib.h>
#include <ansi.h>
#define JOBID "chopwoods"
inherit OBJ;
inherit M_CHOPPABLE;
inherit M_INPUT;

string *desc = ({"一片"+GRN+"树林"+NOR+"，看来有几百株上下，完全野生野长。\n"+
"由于吸取天地精华，枝叶繁茂。(chop woods with kanchai dao)\n",
"几棵树上有明显的劈砍印记，一定有人在此砍过柴火。(chop woods with kanchai dao)\n",
"放眼望去，树上都是光秃秃的，能当柴火的枝叶已经不多了。(chop woods with kanchai dao)\n",});

int status;
int chopped;

void setup()
{
	set_id("woods", "一片"+GRN+"树林"+NOR+"","shu lin");
	set_in_room_desc("一片"+GRN+"树林"+NOR+"(woods)");
	status=0;
	chopped=0;
	call_out("grow", 10);
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
	call_out("grow",10);
	chopped=chopped-1;
	if(chopped<0)
	chopped=0;
	if(chopped)
	return;
	status=status-2;
	if(status<0)
	status=0;
}
void chop(object o)
{
	object chopper;
	object ob;
	if(this_body()->query_job(JOBID,"beg_time")==0)
	{
	all_inventory(this_body());
	chopper=present("chopper",this_body());
	this_body()->simple_action(
	"$N一刀向树杈砍去，但"+YEL+"砍柴刀"+NOR+"『啪』地一声断了。\n");
	destruct(chopper);
	return;
	}
	if (status<41)
	{
	int m_hp;
	m_hp=this_body()->query_cur_hp();
	if (m_hp<10)
	{write("你太累了，休息一会儿吧。\n");
	return;
        }
        m_hp-=5;
        this_body()->set_cur_hp(m_hp);
	status=status+random(5);
	this_body()->simple_action( ({"$N挥起"+YEL+"砍柴刀"+NOR+"「啃哧」「啃哧」地砍柴。\n",
	"$N一不留神，被落下的树枝刮破了脸。\n",
	"$N用力过猛，一头撞在树干上，起了个臌包。\n",
	"$N憋足了力气，对准大树丫就是一下，只听「喀嚓」一声，刀起柴落。\n"}) );
        ob=new(__DIR__"firewoods");
        ob->move(this_body());
	}
	else
	write("这片树林光秃秃的，已经砍不到柴火了。\n");
}
