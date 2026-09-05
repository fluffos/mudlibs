#ifndef MAGE_H
#define MAGE_H

#define HEAL_MAGE_PERIOD (20 - query_intelligence()/6)

/*** mage schools ***/ 
 
int illusion;                  /* illusion spells stat */ 
int charm; 
int conjuration; 
int abjuration; 
int necromancy; 
int evocation; 
int divination; 
int alteration; 
 
int illusion_points;            /* current spell points for illusions */ 
int charm_points; 
int conjuration_points; 
int abjuration_points; 
int necromancy_points; 
int evocation_points; 
int divination_points; 
int alteration_points; 


/***           Mage              ***/ 
 
int set_illusion(int i)    { return illusion = i;    } 
int set_charm(int i)       { return charm = i;       } 
int set_conjuration(int i) { return conjuration = i; } 
int set_abjuration(int i)  { return abjuration = i;  } 
int set_necromancy(int i)  { return necromancy = i;  } 
int set_evocation(int i)   { return evocation = i;   } 
int set_divination(int i)  { return divination = i;  } 
int set_alteration(int i)  { return alteration = i;  } 
 
int query_illusion()    { return illusion;    } 
int query_charm()       { return charm;       } 
int query_conjuration() { return conjuration; } 
int query_abjuration()  { return abjuration;  } 
int query_necromancy()  { return necromancy;  } 
int query_evocation()   { return evocation;   } 
int query_divination()  { return divination;  } 
int query_alteration()  { return alteration;  } 


void clear_mage() {
  illusion = 0; charm = 0; conjuration = 0; abjuration = 0;
  necromancy = 0; evocation = 0; divination = 0;
  divination = 0; illusion_points = 0; charm_points = 0;
  conjuration_points = 0; abjuration_points = 0; necromancy_points = 0;
  evocation_points = 0; divination_points = 0; divination_points = 0;
} 
 
int adj_alteration_points(int i) {
  alteration_points = alteration_points + i;
  if(alteration_points > alteration*2) alteration_points = alteration*2;
  if(alteration_points < 0) alteration_points = 0;
  return alteration_points;
}

int adj_illusion_points(int i) { 
  illusion_points = illusion_points + i; 
  if(illusion_points > illusion * 2)  illusion_points = illusion * 2; 
  if(illusion_points < 0) illusion_points = 0;
  return illusion_points; 
} 
 
int adj_charm_points(int i) { 
  charm_points = charm_points + i; 
  if(charm_points > charm * 2) charm_points = charm * 2; 
  if(charm_points < 0) charm_points = 0;
  return charm_points; 
} 
 
int adj_conjuration_points(int i) { 
  conjuration_points = conjuration_points + i; 
  if(conjuration_points > conjuration*2) conjuration_points = conjuration*2;
  if(conjuration_points < 0) conjuration_points = 0; 
  return conjuration_points; 
} 
 
int adj_abjuration_points(int i) { 
  abjuration_points = abjuration_points + i; 
  if(abjuration_points > abjuration * 2)  abjuration_points = abjuration * 2; 
  if(abjuration_points < 0) abjuration_points = 0;
  return abjuration_points;
} 
 
int adj_necromancy_points(int i) { 
  necromancy_points = necromancy_points + i; 
  if(necromancy_points > necromancy * 2) necromancy_points = necromancy * 2; 
  if(necromancy_points < 0) necromancy_points = 0;
  return necromancy_points; 
} 
 
int adj_evocation_points(int i) { 
  evocation_points = evocation_points + i; 
  if(evocation_points > evocation * 2) evocation_points = evocation * 2; 
  if(evocation_points < 0) evocation_points = 0;
  return evocation_points; 
} 
 
int adj_divination_points(int i) { 
  divination_points = divination_points + i; 
  if(divination_points > divination * 2) divination_points = divination * 2; 
  if(divination_points < 0) divination_points = 0;
  return divination_points; 
} 
 
 
int query_illusion_points(int i)    { return illusion_points;    } 
int query_charm_points(int i)       { return charm_points;       } 
int query_conjuration_points(int i) { return conjuration_points; } 
int query_abjuration_points(int i)  { return abjuration_points;  } 
int query_necromancy_points(int i)  { return necromancy_points;  } 
int query_evocation_points(int i)   { return evocation_points;   } 
int query_divination_points(int i)  { return divination_points;  } 
int query_alteration_points(int i)  { return alteration_points;  } 

void query_mage_stats() {
  string str;

  write("\n         -=[ Mage Schools ]=-\n\n");
  str = " Illusion: "+illusion+"("+illusion_points+" pts)         ";
  str = str[0..25];
  str += " Charm: "+charm+"("+charm_points+" pts)                 ";
  str = str[0..50];
  str += " Conjuration: "+conjuration+"("+conjuration_points+" pts)       ";
  str = str[0..75];
  write(str +"\n");

  str = " Abjuration: "+abjuration+"("+abjuration_points+" pts)           ";
  str = str[0..25];
  str += " Necromancy: "+necromancy+"("+necromancy_points+" pts)          ";
  str = str[0..50];
  str += " Evocation: "+evocation+"("+evocation_points+" pts)             ";
  str = str[0..75];
  write(str +"\n");

  str = " Divination: "+divination+"("+divination_points+" pts)           ";
  str = str[0..25];
  str += " Alteration: "+alteration+"("+alteration_points+" pts)          ";
  str = str[0..50];
  write(str +"\n");
}

void adj_all_mage(int h) {
  adj_alteration_points(h);
  adj_illusion_points(h);
  adj_charm_points(h);
  adj_conjuration_points(h);
  adj_abjuration_points(h);
  adj_necromancy_points(h);
  adj_evocation_points(h);
  adj_divination_points(h); 
} 

void heal_mage() {
  if (random(HEAL_MAGE_PERIOD)) return;
  adj_all_mage(1);
}

#endif /* MAGE_H */

