
#include "chk_att.h"

#define DAM   (2 * (_tpw + random(_tpw )))
#define COST  _tpd * 2 

int dispel(string arg)
{
   object mob;
   string name;

    if (_tp->query_ghost())
    {
        write("You can't do this in your immaterial state !\n"); 
        return 1;
     }
    if (objectp(mob =chk_attack(arg,COST,15)))
    {
        name = mob->query_name();
        
        if (mob->query_alignment() > 0)
        {
            write(name+" is protected by the gods !\n");
            return 1;
         }
          write(name+" shivers from evilness !\n");
          say(_tpn+" swears damn you "+name+" !\n",_tp,mob);
          tell_object(mob,"You feel bad !\n");

        if (living(mob))
            mob->hit_player(DAM,5);
        if (living(_tp))
            _tp->restore_spell_points(-COST);
       return 1;
     }
   return 0;
}
            
            
        
       
       

