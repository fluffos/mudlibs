// by fire@sanguo on Jan, 27 2000
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** call.c
**
**
*/

#include <mudlib.h>

inherit CMD;
private mixed super_query();
private string *inps=({});

private int is_number(string inp) {
	if(inp=="0") return 1;
	if(to_int(inp)!=0) return 1;
	return 0;
}
private mixed query_object(string inp) {
	if(inp==".me") return this_body();
	if(inp==".here") return this_body()->query_room();
	if(inp[0]=='.') {
		object u;
		u=find_body(inp[1..<1]);
		if(objectp(u)) return u;
		u=CHAR_D->find_char(inp[1..<1]);
		if(objectp(u)) return u;
	}
	return inp;
}
private mixed query_val(string inp) {
	if(is_number(inp))
		return to_int(inp);
	return query_object(inp);
}

private mixed query_map() {
	string inp;
	mapping ret=([]);
	while (sizeof(inps)) {
		inp=inps[0];
		inps=inps[1..<1];
		if(inp=="[/mp]") {
			return ret;
		}
		ret[inp]=super_query();
	}
	return ret;
}
private mixed query_array() {
	string inp;
	mixed * ret=({});
	while (sizeof(inps)) {
		inp=inps[0];
		if(inp=="[/ar]") {
			inps=inps[1..<1];
			return ret;
		}
		ret+=({super_query()});
	}
	return ret;
}
private mixed super_query() {
	string inp;
	if(!sizeof(inps)) return ;
	inp=inps[0];
	inps=inps[1..<1];
	if(inp=="[mp]") {
		return query_map();
	}
	if(inp=="[ar]") {
		return query_array();
	}
	return query_val(inp);
}
private void main(string inp)
{
	object own;
	mixed * para;
	int sum,i;
	mixed ret;
    if( !inp )
    {
        write( "用法：call <obj>,<fun> [,paras]\n");
        return;
    }
	if(sizeof(inps)) {
		write( "someone else may be using call now, if you are sure no one else is using, just update /cmds/wiz/call.c and retry.\n");
	}
	inps=explode(inp,",");
	sum=sizeof(inps);
	own=query_object(inps[0]);
	if(!objectp(own))
		own=load_object(inps[0]);
	if(!objectp(own)) {
		write(inps[0]+" is not an object\n");
		return;
	}

	para=({inps[1]});
	inps=inps[2..<1];
	while(sizeof(inps)) {
		para+=({ super_query() });
	}
/*
	for(i=2;i<sum;++i) {
		para+=({query_val(inps[i])});
	}
*/
//	tell_user("fire",sprintf("%O\n",para));
	load_object("/trans/obj/wish")->call_log(inp);
	ret=call_other(own,para);
    out(sprintf("%O\n", ret));
}

