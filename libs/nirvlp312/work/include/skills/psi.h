#ifndef PSI_H
#define PSI_H

#define HEAL_PSI_PERIOD (20 - query_wisdom()/6)

/*** Psionicist ***/

int clairsentient;         /* sensory effecting powers */
int psycokinetic;          /* object effecting powers  */
int psycometabolic;        /* body effecting powers    */
int psycoportive;          /* space effecting powers   */
int telepathic;            /* thought effecting powers */
int metapsionic;           /* enhancement powers       */

int psionic_points;        /* current psionic points */
int max_psionic_points;    /* maximum psionic points */


/***             Psionicist             ***/ 

int query_clairsentient()    { return clairsentient;  }
int query_psycokinetic()     { return psycokinetic;   }
int query_psycometabolic()   { return psycometabolic; }
int query_psycoportive()     { return psycoportive;   }
int query_telepathic()       { return telepathic;     }
int query_metapsionic()      { return metapsionic;    }

void set_max_psp() {
  max_psionic_points += clairsentient + psycokinetic + psycometabolic;
  max_psionic_points += psycoportive + telepathic + metapsionic;
  max_psionic_points = 2 * max_psionic_points;
}


int set_clairsentient(int i) {
  clairsentient = i;
  set_max_psp();
  return clairsentient;
}

int set_psycokinetic(int i) { 
  psycokinetic = i;
  set_max_psp();
  return psycokinetic;
}

int set_psycometabolic(int i) { 
  psycometabolic = i;
  set_max_psp();
  return psycometabolic;
}

int set_psycoportive(int i) { 
  psycoportive = i;
  set_max_psp();
  return psycoportive;
}

int set_telepathic(int i) {
  telepathic = i;
  set_max_psp();
  return telepathic;
}

int set_metapsionic(int i) { 
  metapsionic = i;
  set_max_psp();
  return metapsionic;
}

int query_psionic_points()   { return psionic_points; }
int query_psp()              { return psionic_points; }

int query_max_psionic_points() { return max_psionic_points; }
int query_max_psp()            { return max_psionic_points; }

int adj_psionic_points(int i) {
  psionic_points = psionic_points + i;
  if(psionic_points > max_psionic_points)
    psionic_points = max_psionic_points;
  return psionic_points;
}

void heal_psionicist() {
  if (random(HEAL_PSI_PERIOD)) return;
  adj_psionic_points(6);
}

void clear_psionicist() {
  clairsentient = 0; psycokinetic = 0; psycometabolic = 0;
  psycoportive = 0; telepathic = 0; metapsionic = 0;
  psionic_points = 0; max_psionic_points = 0;
}

void query_psionicist_stats() {
  string str;

  str = "\n         -=[ Psionicist Disciplines ]=-\n\n";
  str += " Clairsentience: "+clairsentient+"                   ";
  str = str[0..25];
  str += " Psycokinetic: "+psycokinetic+"                     ";
  str = str[0..50];
  str += " Psycometabolism: "+psycometabolic+"                ";
  str = str[0..75];
  write(str +"\n");

  str = " Psycoportive: "+psycoportive+"                      ";
  str = str[0..25];
  str += " Telepathy: "+telepathic+"                          ";
  str = str[0..50];
  str += " Metapsionic: "+metapsionic+"                       ";
  str = str[0..75];
  write(str +"\n");

  write(" Psionic Points: "+psionic_points+"/"+max_psionic_points+"\n");
}

void heal_psionicist(int h) {
  adj_psionic_points(h);
}
  
#endif /* PSI_H */

