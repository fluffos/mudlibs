
#include "chk_att.h"

#define DAM   (_tpw + random(_tpw ))
#define COST  _tpd * 2 

int flamestrike(string arg)
{
   object mob;
   string name;

    if (_tp->query_ghost())
    {
        write("You can't do this in your immaterial state !\n"); 
        return 1;
     }
    if (objectp(mob =chk_attack(arg,COST,2)))
    {
        name = mob->query_name();

        write("You cast a flamestrike at "+name+" !\n");
        say(_tpn+" casts a flamestrike at "+name+" !\n",_tp,mob);
        tell_object(mob,"AUTCH, You are burned badly !\n");

        if (living(mob))
        {
            if (mob->query_race()=="troll")
                mob->hit_player(DAM*2,5);
            else 
                mob->hit_player(DAM,5);
        }
        if (living(_tp))
            _tp->restore_spell_points(-COST);
       return 1;
     }
   return 0;
}
            
            
        
       
       

