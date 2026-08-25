// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
inherit CMD;

#define USAGE "用法：at <生物> <命令>\n" //"Usage: at <living> <command>\n"

private void main( mixed *arg ) {
    string where;
    object start, targ;

    start = environment(this_body());
    targ = environment(arg[0]);
    if(!targ){
        //out("Your target has no environment.\n");
        out("你的目标没有环境。\n");
        return;
    }
    this_body()->move( targ );
    this_user()->force_me(implode(arg[1], " "));
    if(start)
      this_body()->move( start );
}
