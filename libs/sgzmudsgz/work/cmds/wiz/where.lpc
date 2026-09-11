// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
inherit CMD;



private void main( mixed * arg )
{
    object*     targets;

    if ( !arg[0] )
        targets = users();
    else
        targets = arg[0];

    outf("%-13s%-30s%-s\n","名字","文件","房间");
    out("---------------------------------------------------------------\n");

    targets = filter(targets->query_body(), (: objectp($1) ? environment($1) : 0 :));

    map_array(targets, (: outf("%-13s%-30s[%-s]\n",
                                 $1->query_userid(),
                                 file_name(environment($1)),
                                 environment($1)->short()) :) );
}
