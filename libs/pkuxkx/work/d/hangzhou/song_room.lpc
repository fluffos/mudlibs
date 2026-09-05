inherit ROOM;
#include <ansi.h>
int valid_leave(object me,string dir)
{
	string msg;
	//return ::valid_leave(me,dir);
	if (!query("exits/"+dir))
	return notify_fail("这个方向没有出口。\n");
	if (me->query_temp("songtasks/dianqian/gate_time")>time()&&stringp(me->query_temp("songtasks/dianqian/gate")))
	{
		return notify_fail("你正在守卫"+me->query_temp("songtasks/dianqian/gate")+"，不能擅离职守。\n");
	}
	if (load_object(query("exits/"+dir))&&load_object(query("exits/"+dir))->query("water_body"))
	{
		if (stringp(msg=load_object(query("exits/"+dir))->query("water_body")))
		return notify_fail(msg);
		return notify_fail("你准备投水自杀吗？\n");
	}
	if (me->query("class")!="officer"&&!me->query_temp("songtasks/pass_palace")&&me->query("song/pro")!="宦"&&strsrch(file_name(load_object(query("exits/"+dir))),"/d/hangzhou/palace/")!=-1)
	{
		if (me->query("song/pro")=="文"&&load_object(query("exits/"+dir))->query("WAICHAO"))
		return ::valid_leave(me,dir);
		if (me->query("song/pro")=="武"&&load_object(query("exits/"+dir))->query("ZHUDI"))
		return ::valid_leave(me,dir);
		return notify_fail("大内禁中，不是随便任何人可以进的。\n");
	}
	if (!userp(me)&&me->query("is_xihu_youren")&&load_object(query("exits/"+dir))->query("forbid_leave_xihu")&&load_object(query("exits/"+dir))->query("forbid_leave_xihu")==dir)
	{
		return notify_fail("npc不准乱跑！\n");
	}
	if (!userp(me)&&query("forbid_npc_dir")==dir)
	return notify_fail("");
	return ::valid_leave(me,dir);
}

int Show_Local_Map()
{
	string file;
	if (this_player()->query("song/pro")&&"/cmds/usr/localmaps"->get_area(base_name(this_object()))=="hangzhou")
	file="/d/song/maps/hangzhou";
	else
	return 0;
	file = read_file(file); //调用map文件
	file = replace_string(file, COLOR_D->uncolor(this_object()->query("short")), BBLU+HIY+this_object()->query("short")+NOR);
	this_player()->start_more(file);
	write(" ___________________________________________________________\n");
	return 1;
}