#ifndef THIEF_H
#define THIEF_H

/*** thief ***/ 

int stealth;          /* hide in shadows/move silently */ 
int locks;            /* pick locks */ 
int steal;            /* pick pockects */ 
int backstab;         /* backstab */ 
int appraisal;        /* value items */ 
int traps;            /* find/set traps in doors/room */ 
int disguise;         /* disguise themselses */

nosave status stealth_on;  
nosave status disguise_on;

/********************************************************************/
/* sets */
 
int set_stealth(int i)    { return stealth = i;    } 
int set_locks(int i)      { return locks = i;      } 
int set_steal(int i)      { return steal = i;      } 
int set_backstab(int i)   { return backstab = i;   } 
int set_appraisal(int i)  { return appraisal = i;  } 
int set_traps(int i)      { return traps = i;      } 
int set_disguise(int i)   { return disguise = i;   }

int set_stealth_on(int i) { return stealth_on = (i) ? 1 : 0; }

/***************************************************************/
/* query */
  
int query_stealth()    { return stealth;    } 
int query_locks()      { return locks;      } 
int query_steal()      { return steal;      } 
int query_backstab()   { return backstab;   } 
int query_appraisal()  { return appraisal;  } 
int query_traps()      { return traps;      } 
int query_disguise()   { return disguise;   }
 
int query_stealth_on() { return stealth_on; } 
int query_disguise_on(){ return disguise_on;}

  
void clear_thief() {
  stealth = 0; locks = 0; steal = 0; backstab = 0;
  appraisal = 0; traps = 0; stealth_on = 0; disguise = 0;
} 
 
status toggle_stealth(status silently)  {  
  if(stealth_on && !silently)
     tell_object(this_object(),"You end your stealthily movements...\n");
  if(!stealth_on && !silently)  
     tell_object(this_object(),"You begin to move with great stealth...\n");
  return stealth_on = !stealth_on; 
} 

status toggle_disguise(status silently) {
  disguise_on = !disguise_on;
  if(!disguise_on && !silently)
     tell_object(this_object(),"You take off your disguise...\n");
  if(disguise_on && !silently)  
     tell_object(this_object(),"You disguise yourself as "+query_name()+"\n");
  return disguise_on;  
} 

void query_thief_stats() {
  string str;

  write("\n         -=[ Thief Skills ]=-\n\n");
  str = " Stealth: "+stealth+"                 ";
  str = str[0..20];
  str += " Locks: "+locks+"                    ";
  str = str[0..40];
  str += " Steal: "+steal+"                    ";
  str = str[0..60]; 
  write(str +"\n");

  str = " Appraisal: "+appraisal+"            ";
  str = str[0..20];
  str += " Traps: "+traps+"                    ";
  str = str[0..40];
  str += " Disguise: "+disguise+"                 ";
  str = str[0..60];
  write(str +"\n");
  str = " Backstab "+backstab+"         ";
  str = str[0..20];
  write(str +"\n");
}

#endif /* THIEF_H */

