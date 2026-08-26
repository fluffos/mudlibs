//
// _objfind.c
//
// Finds all instances of file_name given and returns their environments.
//
// -- Tlaloc -- 10/28/21
//

#include <std.h>

inherit DAEMON;

mapping envs = ([  ]);

int cmd_objfind(string str)
{
    object *obs;
    
    obs = objects( (: base_name($1) == $(str) :) );
    map_array(obs, (: envs[$1] = environment($1) :));
    
    printf("%O\n", envs);
    
    return 1;
}   