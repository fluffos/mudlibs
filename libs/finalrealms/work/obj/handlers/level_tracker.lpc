//#include "leveltrack.h"
inherit "/std/object";
#define LEV_AD "/w/anirudh/levelstuff/level_adjuster"

mapping guild_data = ([ ]);

void save_function() {
  if(m_sizeof(guild_data))
    save_object("/save/leveltracker");
}

void restore_function() {
  if(!m_sizeof(guild_data))
    restore_object("/save/leveltracker");
}

void setup() {
    set_name("leveltracker");
    restore_function();
}

int level_advanced(object playerob) {
  int time_now, level, age, i;
  object g_ob;
  string g_name;
  if(!playerob) return 0;
  if(playerob->query_creator() ||
    strsrch(playerob->query_name(),"test") != -1) return 0;
  restore_function();
  if(!guild_data) guild_data = ([ ]);
  g_ob = playerob->query_guild_ob();
  g_name = g_ob->query_name();
  level = playerob->query_level();
  age = playerob->query_time_on();
  if(!guild_data[g_name]) guild_data[g_name] = ({ });
  for(i=sizeof(guild_data[g_name]);i<(2*level+1);i++)
    guild_data[g_name]+=({ 0 });
  guild_data[g_name][2*level-2]++;
  guild_data[g_name][2*level-1]+=age/60;
  save_function();
  LEV_AD->level_advanced(playerob);
  return 1;
}

void query_total_guild_data() {
  string *ind;
  int *avgs = ({ }),i,j;
  ind = m_indices(guild_data);
  for(i=0;i<sizeof(ind);i++) {
    for(j=sizeof(avgs);j<sizeof(guild_data[ind[i]]);j++)
      avgs+=({ 0 });
    for(j=0;j<sizeof(guild_data[ind[i]]);j++)
      avgs[j]+=guild_data[ind[i]][j];
  }
  for(i=0;i<sizeof(avgs);i+=2)
    if(avgs[i])
      write((i/2+1)+" "+avgs[i]+" "+(-avgs[i+1]/avgs[i]/60)+"\n");
}

void query_guild_totals() {
  int i,j,sum;
  string *ind;
  ind = m_indices(guild_data);
  for(i=0;i<sizeof(ind);i++) {
    sum = 0;
    for(j=0;j<sizeof(guild_data[ind[i]]);j+=2)
     sum += guild_data[ind[i]][j];
    write(ind[i]+":  "+sum+"\n");
  }
}

void query_one_guild_data(string guild) {
  int i;
  for(i=0;i<sizeof(guild_data[guild]);i+=2)
    if(guild_data[guild][i])
      write((i/2+1)+" "+guild_data[guild][i]+" "+(-guild_data[guild][i+1]/
        guild_data[guild][i]/60)+"\n");
}

mapping query_guild_data() {
    return guild_data;
}

mapping reset_guild_data() {
    guild_data = ([ ]);
    save_object("/save/leveltracker");
    return guild_data;
}

mapping reset_one_guild(string guild) {
    if(guild_data[guild]) guild_data = m_delete(guild_data,guild);
    return guild_data;
}

void dest_me() {
    save_function();
    ::dest_me();
}
