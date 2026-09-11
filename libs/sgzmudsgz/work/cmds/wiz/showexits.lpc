// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <daemons.h>

inherit CMD;

private void main(){

    object room = environment(this_body());
    string* directions;
    string base;

    directions = room->query_exit_directions(1);
    if(!sizeof(directions)) {
        out("这个房间没有任何出口。\n");
        return;
    }

    out("目前的出口是：\n");

    foreach (string dir in directions) {
        mixed dest;
        object o;
        string Short;
        
        dest = room->query_exit_value(dir);
        if (dest) {
            if (dest[0] == '#') {
                outf("%s:  %s", dir, dest);
                continue;
            } else
            if (o = load_object(dest))
                Short = o->short() || "";
            else
                Short = "建设中";
        } else
            Short = "无";
        outf("%s:  %s (%s)\n", dir, Short, dest);
    }
}

