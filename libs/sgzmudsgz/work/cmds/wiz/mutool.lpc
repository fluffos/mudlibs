// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Davmar/Nevyn
inherit M_ANSI;

#include <mudlib.h>

inherit CMD;


void show_help() {
	write("help not ready yet\n");
	return;
}
void set_con(string p_id,string d,int type) {
	string ret;
	if((d!="e")&&(d!="w")&&(d!="s")&&(d!="n"))
	{write( "请用 e, s, w, n 表示东南西北。\n"); return ;}
	ret=MUSEUM_D->set_room(p_id,d,type);
	write(ret+"\n");
	return;
}
void set_label(string p_id,string layer,string arg) {
	string ret;
	if((!arg)||(arg=="")) {
		ret=MUSEUM_D->set_room(p_id,layer,0);
		write(ret+"\n");
		return;
	}
	if(colour_strlen(arg)>4) {
		write("太长了，最多两个汉字。\n");
		return;
	}
	arg=replace_string(arg,"+"," ");
	switch(strlen(arg)) {
	case 1:
		arg=" "+arg+"  ";
		break;
	case 2:
		arg=" "+arg+" ";
		break;
	case 3:
		arg=arg+" ";
		break;
	}
	ret=MUSEUM_D->set_room(p_id,layer,arg);
	write(ret+"\n");
	return;


}
void set_brief(string p_id,string arg) {
	string ret;
	if((!arg)||(arg=="")) {
		ret=MUSEUM_D->set_room(p_id,"b",0);
		write(ret+"\n");
		return;
	}
	if(colour_strlen(arg)>20) {
		write("太长了，最多十个汉字。\n");
		return;
	}
	ret=MUSEUM_D->set_room(p_id,"b",arg);
	write(ret+"\n");
	return;
}
void update_museum() {
	object *lst;
	lst=objects((:$1->is_in_museum():));
	if(sizeof(lst)) {
		foreach(object o in lst) {
			"/sgdomain/menu/buzzer"->room_update(file_name(o));
		}
	}
	write("ok\n");
	return;
}
private void main( string arg )
{
    object env;
	string cmd, par,id;
	int n;
	if(!arg) { show_help(); return ;}

    env=this_body()->query_room();
	if(!env->is_in_museum()) {
		write("只有在博物馆内才可以使用此工具。\n");
		return;
	}
	id=env->get_id();
	n=sscanf(arg,"%s %s",cmd, par);
	if(n!=2) {
		cmd=arg;
		par="";
	}
	switch(cmd) {
	case "door":
		set_con(id,par,1);
		break;
	case "open":
		set_con(id,par,2);
		break;
	case "block":
		set_con(id,par,0);
		break;
	case "l1":
	case "l2":
		set_label(id,cmd,par);	
		break;
	case "b":
		set_brief(id,par);
		break;
	case "update":
		update_museum();
		return;

	}
	"/sgdomain/menu/buzzer"->room_update(file_name(env));
}

