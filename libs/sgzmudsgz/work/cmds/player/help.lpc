// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
#include <mudlib.h>
inherit CMD;
private void main(string arg)
{
	string ret;
	if((!arg)||(arg=="")) arg="main";
	ret=SGHELP_D->get_count(arg);
       if(ret[<3..<1]!="\n") ret+="\n";
       more(ret);
}
