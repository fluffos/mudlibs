//
// _destall.c
//
// Finds all instances of file_name given and destructs them.
//
// -- Tlaloc -- 10/28/21
//

#include <std.h>
#include <security.h>

inherit DAEMON;

mapping envs = ([  ]);

int cmd_objpurge(string str)
{
    object *obs;
    string obshort;
    
    obs = objects( (: base_name($1) == $(str) :) );
    map_array(obs, (: envs[$1] = environment($1) :));
    
    seteuid(UID_ROOT);
    
    foreach(object ob in obs)
    {
        if(!objectp(ob))
            continue;
        
        obshort = ob->query_short();
        
        if(!catch(destruct(ob, 1)))
        {
            if(objectp(ob))
                ob->remove();
            if(objectp(ob))
                ob->dest_effect();
            if(objectp(ob))
                destruct(ob);
            
            if(objectp(ob))
                write("Failed to destruct " + obshort + ".");
            else
                write("You dest " + obshort + ".");
        }
        else
        {
            write("Failed to destruct object.");
            continue;
        }
    }
    
    seteuid(UID_SYSTEM);
    
    //printf("%O\n", envs);
    
    return 1;
}   