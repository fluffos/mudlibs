
#include "chk_att.h"

#define DAM   ( 3 * (_tpw + random(_tpw )))
#define COST  _tpw * 6 

int lightning(string arg)
{
   object mob;
   string name;

    if (_tp->query_ghost())
    {
        write("You can't do this in your immaterial state !\n"); 
        return 1;
     }
    if (objectp(mob =chk_attack(arg,COST,20)))
    {
        name = mob->query_name();

        write("Suddenly a flash from the sky hits "+name+" badly !\n");
        say("Suddenly a flash from the sky hits "+name+" badly !\n",_tp,mob);
        tell_object(mob,"SCREAM, You are hit by a lightning !\n");

        if (living(mob))
            mob->hit_player(DAM,5);
        if (living(_tp))
            _tp->restore_spell_points(-COST);
       return 1;
     }
   return 0;
}
            
            
        
       
       

