#ifndef FIGHTER_H
#define FIGHTER_H

int two_weapon;       /* two-weapon use */ 
int unarmed;          /* unarmed combat */ 
int multi_attack;     /* max. number of multiple attacks */
int armoring;         /* repair armor */
int weapon_smith;     /* weapon smithing */
int multi_opponent;   /* max. number of opponents */


/******************************************************************/
/* sets */

int set_unarmed(int i)        { return unarmed = i;        } 
int set_two_weapon(int i)     { return two_weapon = i;     } 
int set_multi_attack(int i)   { return multi_attack = i;   }
int set_multi_opponent(int i) { return multi_opponent = i; }
int set_armoring(int i)       { return armoring = i;       }
int set_weapon_smith(int i)   { return weapon_smith = i;   }

/******************************************************************/
/* query */
 
int query_unarmed()             { return unarmed;        } 
int query_two_weapon()          { return two_weapon;     } 
int query_multi_attack()   { return multi_attack;   }
int query_armoring()       { return armoring;       }
int query_weapon_smith()   { return weapon_smith;   }
int query_multi_opponent() { return multi_opponent; }


void clear_fighter() {
  unarmed = 0; two_weapon = 0; multi_attack = 0; multi_opponent = 0;
  weapon_smith = 0; armoring = 0;
} 

void query_fighter_stats() {
  string str;

  write("\n         -=[ Fighter Skills ]=-\n\n");
  str = "Unarmed: "+unarmed+"                 ";
  str = str[0..12];
  str += " Two Weapon: "+two_weapon+"          ";
  str = str[0..29];
  str += " Multi Attack: "+multi_attack+"         ";
  str = str[0..50];
  str += " Multi Opponent: "+multi_opponent+"             ";
  str = str[0..79];
  write(str +"\n");
  str = "Armoring: "+ armoring +"                     ";
  str = str[0..12];
  str += " Weapon Smith: "+ weapon_smith +"               ";
  str = str[0..29];
  write(str +"\n");
}

#endif /* FIGHTER_H */

