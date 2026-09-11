// this is used to call a npcchar to current
// place. this should be a wiz command
// but in test period, put it in /cmds/player first
// by fire on July 13, 1998
#include <mudlib.h>
#include <daemons.h>
#include <char.h>
inherit CMD;
inherit M_GLOB;
private string ret="\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
private string spc="                                                               \n";
void end_magic(object rom,object o) {
	string dis;
	if(!objectp(rom)) return;
	dis=ret+"一阵红光闪过，";
	if(objectp(o))
		dis+=o->short()+"消失了。\n\n";
	else
		dis+="一个人不见了。\n\n";
	tell_from_inside(rom,dis);
}

void show_magic(object o,object rom) {
	string dis;
	int i;
	if(!objectp(rom)) return;
	dis=ret+"%^B_RED%^";
	for(i=0;i<5;++i)
		dis+=spc;
	dis+="\n\n\n\n%^RESET%^";
	tell_from_inside(rom,dis);
	call_out("end_magic",1,rom,o);
	return ;

}
private void main(string arg)
{
	object o,rom;
	string s_room;
    if(!arg)
	{
		write("用法：callchar <char id>\n");
	}
	s_room=file_name(environment(this_body()));

	o=CHAR_D->find_char(arg);
	if(!objectp(o)) {

		if((CHAR_D->put_char(arg,s_room))==PC_SUCCESSFUL)
			write("召唤成功\n");
		else
			write("召唤失败\n");
		return;
	}
	rom=o->query_room();
	if(rom==this_body()->query_room()) // some room
	{
		if((CHAR_D->put_char(arg,s_room))==PC_SUCCESSFUL)
			write("召唤成功\n");
		else
			write("召唤失败\n");
		return;
	}

	if((CHAR_D->put_char(arg,s_room))==PC_SUCCESSFUL) {
		show_magic(o,rom);
		write("召唤成功\n");
	}
		else
		write("召唤失败\n");
	return;

}
