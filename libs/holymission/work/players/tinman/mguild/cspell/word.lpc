
#include "defs.h"

#define DAM   (3 * (_tpw + random(_tpw)))
#define COST  _tpw * 5  

int word()
{
    object *inv; 
    int i, sz;

    _chk_ghost();

    if (_tp->query_sp() < DAM)
    {
        write("You are too low on power.\n");
        return 1;
    }
    else if (_tpw < 25)
    {
         write("You are not wise enough to cast that spell !\n");
         return 1;
    }
    inv = all_inventory(_e(_tp));
    sz = sizeof(inv);

    write("Suddenly the whole area is filled with a humming holy voice !\n");
    say("Suddenly the whole area is filled with a humming holy voice !\n");

    while(sz)
    {
       if (inv[(sz-1)]!=_tp && !inv[(sz-1)]->query_invis() && living(inv[(sz-1)])
       && !(inv[(sz-1)]->query_alignment() < 0) && !inv[(sz-1)]->query_familiar())
       {
           inv[(sz-1)]->catch_tell("You feel bad !\n");
           inv[(sz-1)]->hit_player(DAM,7);
       }
       sz--;
    }
    _tp->restore_spell_points(-DAM);
    return 1;
   }
            
            
        
       
       

