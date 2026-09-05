#ifndef CLERIC_H
#define CLERIC_H

#define HEAL_CLERIC_PERIOD (20 - query_wisdom()/6)

/*** cleric spheres ***/ 

int healing_sphere;           /* healing spells stat */ 
int necromancy_sphere;        /* necromancy spells stat */ 
int combat_sphere;            /* combat spells stat */ 
int stellar_sphere;           /* light/travelling/astral spells stat */ 
int protection_sphere;        /* protection spells stat */ 
int nature_sphere;            /* druid spells stat */ 
int divination_sphere;        /* divining/seer spells stat */ 
 
int healing_sphere_points;    /* current spell points for healing spells */     
int necromancy_sphere_points; /* current spell points for necromancy spells */ 
int combat_sphere_points;     /* current spell points for combat spells */ 
int stellar_sphere_points;    /* current spell points for stellar spells */ 
int protection_sphere_points; /* current spell points for protection spells */ 
int nature_sphere_points;     /* current spell points for nature spells */ 
int divination_sphere_points; /* current spell points for divination spells */ 



/***     Cleric            ***/ 
 
int set_healing_sphere(int i)    { return healing_sphere = i;    } 
int set_necromancy_sphere(int i) { return necromancy_sphere = i; } 
int set_combat_sphere(int i)    { return combat_sphere = i;     } 
int set_stellar_sphere(int i)    { return stellar_sphere = i;    } 
int set_protection_sphere(int i) { return protection_sphere = i; } 
int set_nature_sphere(int i)     { return nature_sphere = i;     } 
int set_divination_sphere(int i) { return divination_sphere = i; } 
 
int query_healing_sphere()    { return healing_sphere;    } 
int query_necromancy_sphere() { return necromancy_sphere; } 
int query_combat_sphere()    { return combat_sphere;     } 
int query_stellar_sphere()    { return stellar_sphere;    } 
int query_protection_sphere() { return protection_sphere; } 
int query_nature_sphere()     { return nature_sphere;     } 
int query_divination_sphere() { return divination_sphere; } 


void clear_cleric() {
  healing_sphere = 0; necromancy_sphere = 0; combat_sphere = 0;
  stellar_sphere = 0; protection_sphere = 0; nature_sphere = 0;
  divination_sphere = 0; healing_sphere_points = 0;
  necromancy_sphere_points = 0; combat_sphere_points = 0;
  stellar_sphere_points = 0; protection_sphere_points = 0;
  nature_sphere_points = 0; divination_sphere_points = 0;
} 
   
int adj_combat_sphere_points(int i) {
    combat_sphere_points = combat_sphere_points + i;
    if(combat_sphere_points > combat_sphere * 2)
       combat_sphere_points = combat_sphere * 2;
    if(combat_sphere_points < 0)
       combat_sphere_points = 0;
    return combat_sphere_points;
}

int adj_healing_sphere_points(int i) { 
  healing_sphere_points = healing_sphere_points + i; 
  if(healing_sphere_points > healing_sphere * 2) 
    healing_sphere_points = healing_sphere * 2; 
  if(healing_sphere_points < 0) 
    healing_sphere_points = 0; 
  return healing_sphere_points; 
} 
 
int adj_necromancy_sphere_points(int i) { 
  necromancy_sphere_points = necromancy_sphere_points + i; 
  if(necromancy_sphere_points > necromancy_sphere * 2) 
    necromancy_sphere_points = necromancy_sphere * 2; 
  if(necromancy_sphere_points < 0) 
    necromancy_sphere_points = 0; 
  return necromancy_sphere_points; 
} 
 
int adj_stellar_sphere_points(int i) { 
  stellar_sphere_points = stellar_sphere_points + i; 
  if(stellar_sphere_points > stellar_sphere * 2) 
    stellar_sphere_points = stellar_sphere * 2; 
  if(stellar_sphere_points < 0) 
    stellar_sphere_points = 0; 
  return stellar_sphere_points; 
} 
 
int adj_protection_sphere_points(int i) { 
  protection_sphere_points = protection_sphere_points + i; 
  if(protection_sphere_points > protection_sphere *  2) 
    protection_sphere_points = protection_sphere * 2; 
  if(protection_sphere_points < 0) 
    protection_sphere_points = 0; 
  return protection_sphere_points; 
} 
 
int adj_nature_sphere_points(int i) { 
  nature_sphere_points = nature_sphere_points + i; 
  if(nature_sphere_points > nature_sphere * 2) 
    nature_sphere_points = nature_sphere * 2; 
  if(nature_sphere_points < 0) 
    nature_sphere_points = 0; 
  return nature_sphere_points; 
} 
 
int adj_divination_sphere_points(int i) { 
  divination_sphere_points = divination_sphere_points + i; 
  if(divination_sphere_points > divination_sphere * 2) 
    divination_sphere_points = divination_sphere * 2; 
  if(divination_sphere_points < 0) 
    divination_sphere_points = 0; 
  return divination_sphere_points; 
} 
 
int query_healing_sphere_points(int i)    { return healing_sphere_points;    } 
int query_necromancy_sphere_points(int i) { return necromancy_sphere_points; } 
int query_combat_sphere_points(int i)    { return combat_sphere_points;     } 
int query_stellar_sphere_points(int i)    { return stellar_sphere_points;    } 
int query_protection_sphere_points(int i) { return protection_sphere_points; } 
int query_nature_sphere_points(int i)     { return nature_sphere_points;     } 
int query_divination_sphere_points(int i) { return divination_sphere_points; } 

void query_cleric_stats() {
  string str;

  write("\n         -=[ Cleric Spheres ]=-\n\n");
  str = " Healing: "+healing_sphere;
  str += "("+healing_sphere_points+" pts)         ";
  str = str[0..25];
  str += " Necromancy: "+necromancy_sphere;
  str += "("+necromancy_sphere_points+" pts)      ";
  str = str[0..50];
  str += " Combat: "+combat_sphere;
  str += "("+combat_sphere_points+" pts)          ";
  str = str[0..75];
  write(str +"\n");

  str = " Stellar: "+stellar_sphere;
  str += "("+stellar_sphere_points+" pts)         ";
  str = str[0..25];
  str += " Protection: "+protection_sphere;
  str += "("+protection_sphere_points+" pts)      ";
  str = str[0..50];
  str += " Nature: "+nature_sphere;
  str += "("+nature_sphere_points+" pts)          ";
  str = str[0..75];
  write(str +"\n");

  str = " Divination: "+divination_sphere;
  str += "("+divination_sphere_points+" pts)      ";
  str = str[0..25];
  write(str +"\n");
}             

void adj_all_cleric(int h) {
  adj_combat_sphere_points(h);
  adj_healing_sphere_points(h);
  adj_necromancy_sphere_points(h);
  adj_stellar_sphere_points(h);
  adj_protection_sphere_points(h);
  adj_nature_sphere_points(h);
  adj_divination_sphere_points(h);
}

void heal_cleric() {
  if (random(HEAL_CLERIC_PERIOD)) return;
  adj_all_cleric(1);
}

#endif /* CLERIC_H */

