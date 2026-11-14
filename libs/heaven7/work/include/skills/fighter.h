#ifndef FIGHTER_H
#define FIGHTER_H

int two_weapon;       /* two-weapon use */ 
int unarmed;          /* unarmed combat */ 
int multi_attack;     /* max. number of multiple attacks */
int armouring;        /* repair armour */
int weapon_smith;     /* weapon smithing */
int multi_opponent;   /* max. number of opponents */


/******************************************************************/
/* sets */

int set_unarmed(int i)        { return unarmed = i;        } 
int set_two_weapon(int i)     { return two_weapon = i;     } 
int set_multi_attack(int i)   { return multi_attack = i;   }
int set_multi_opponent(int i) { return multi_opponent = i; }
int set_armouring(int i)      { return armouring = i;      }
int set_weapon_smith(int i)   { return weapon_smith = i;   }

/******************************************************************/
/* query */
 
int query_unarmed()             { return unarmed;        } 
int query_two_weapon()          { return two_weapon;     } 
int query_multi_attack()   { return multi_attack;   }
int query_armouring()      { return armouring;      }
int query_weapon_smith()   { return weapon_smith;   }
int query_multi_opponent() { return multi_opponent; }


void clear_fighter() {
  unarmed = 0; two_weapon = 0; multi_attack = 0; multi_opponent = 0;
  weapon_smith = 0; armouring = 0;
} 

void query_fighter_stats() {
  string str;

  write("\n         -=[ Fighter Skills ]=-\n\n");
  str = "Unarmed: "+unarmed+"                 ";
  str = extract(str,0,12);
  str += " Two Weapon: "+two_weapon+"          ";
  str = extract(str,0,29);
  str += " Multi Attack: "+multi_attack+"         ";
  str = extract(str, 0, 50);
  str += " Multi Opponent: "+multi_opponent+"             ";
  str = extract(str, 0, 79);
  write(str +"\n");
  str = "Armouring: "+ armouring +"                     ";
  str = extract(str,0,12);
  str += " Weapon Smith: "+ weapon_smith +"               ";
  str = extract(str,0,29);
  write(str +"\n");
}

#endif /* FIGHTER_H */
