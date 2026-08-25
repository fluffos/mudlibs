// Updated by tset on 24 Sep 1998
// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
inherit CMD;



private void main( mixed * arg )
{
    object*     targets;
    object      target;

    if ( !arg )
        targets = users();
    else
        target = find_body(arg);


    if ( targets ) {
        targets = filter(targets->query_body(), (: objectp($1) ? environment($1) : 0 :));
    outf("%-10s%-14s%-s\n","名字","房间","文件");
    out("---------------------------------------------------------------\n");

        map_array(targets, (: outf("%-10s[%-14s] %-s\n",
                                 $1->query_userid(),
				environment($1)->short(),
				file_name(environment($1))) :) );
    }
    else {
	if(!target) {
	    out("找不到这个玩家。");
	    return;
	}
        out(environment(target)->get_brief()+"\n");
        out(file_name(environment(target))+"\n");
    out(environment(target)->long());
    }
}
