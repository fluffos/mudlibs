// mutong.c 大木桶 by row
// for makedoufu

#include <ansi.h>
#include <mudlib.h>
inherit OBJ;
inherit M_INPUT;

void set_status();
void do_cold();
int query_status();
int query_isfill();
void set_isfill();
void finish_job();
void empty_it();

string *desc = ({
"这是一只大木桶，是关夫子用来冷却%^B_WHITE%^%^H_YELLOW%^豆浆%^RESET%^的。\n",
"这是一只大木桶，里面满满当当地盛着等待冷却的%^B_WHITE%^%^H_YELLOW%^豆浆%^RESET%^。\n",
"这是一只大木桶，原先点过卤的%^B_WHITE%^%^H_YELLOW%^豆浆%^RESET%^已经完全冷却了，%^B_WHITE%^%^H_GREEN%^翡翠豆腐%^RESET%^做成了！\n"});
int status;
int isfill; // there is doujiang in

void setup()
{
	set_unit("只");
	set_id("mutong","大木桶");
	set_in_room_desc("一只大木桶(mutong)，摆在磨房的地上，可以用来盛东西。");
	status=0;
	isfill=0;
}
string long()
{
	if(isfill==0)
	return desc[0];
	if(isfill==1&&status==0)
	return desc[1];
	return desc[2];
}
void set_status()
{
	status=0;
}
int query_status()
{
	return status;
}
int query_clean_up()
{
	return 1;
}
void set_isfill()
{
	isfill=1;
}
int query_isfill()
{
	return isfill;
}
void empty_it()
{
	isfill=0;
}
void do_cold()
{
	call_out("finish_job",180);
	return;
}
void finish_job()
{
	if(isfill==1&&status==0)
	{
	status=1;
	tell_environment(this_object(),"木桶里点过卤的%^B_WHITE%^%^H_YELLOW%^豆浆%^RESET%^完全冷却了，%^B_WHITE%^%^H_YELLOW%^翡翠豆腐%^RESET%^已经做成了！\n");
	return;
	}
	tell_environment(this_object(),"不知道为什么不行，问问巫师吧。\n");
	return;
}