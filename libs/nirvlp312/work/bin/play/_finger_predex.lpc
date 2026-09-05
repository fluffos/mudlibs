#include "security.h"
/* Original code by Bastion (Bastian)
 * Modified by Wizardchild
 * and later by Feldegast
 * fake finger added by wocket
 */
 
#define P(x) pad(x, -5)
 
string hostname;
string old_last;
string name, called_from_ip, title, al_title, guild_name, mailaddr;
string pretitle, lastime, cap_name;
int no_give,level, ex_lv, age;
int experience, money;
int strength, intelligence, stamina, will_power, piety, stealth,
magic_aptitude,luck;
int player_killing;
int guild_rank, guild_exp; string guild_file;
status privs;
string *FAKERS;
int i;

finger(str) { return cmd_finger(str); }
cmd_finger(str) {
  object who;
  if(str=="batarsis" || str=="Batarsis") {
write("Batarsis the Bad (evil)\n");
write("Level:          19+4 \n");
write("Guild name:     none\n");
write("Player killer:   Yes\n");
write("Last called at: ");
if(find_living("batarsis")) write("Not logged off.\n");
else write("Unknown\n");
write("Age: 8 days 7 hours 46 minutes 20 seconds.\n");
return 1;
}
  old_last=0;
  name=0;called_from_ip=0;level=0;ex_lv=0;title=0;mailaddr=0;
  guild_name=0;lastime=0;age=0;cap_name=0;al_title=0;
  if(!str) {
    write("You must enter a player's name.\n");
    return 1;
  }
/*
  restore_object("players/"+lower_case(str));
*/
if(!restore_object("pfiles/"+extract(str,0,0)+"/"+lower_case(str))) {  
     if(restore_object("players/inactive_saved/"+lower_case(str))) {
       write("------------INACTIVE------------INACTIVE------------\n");
       write("-----Reactivation possible after: "+ctime(no_give+1296000)+"\n");
       write("----------------------------------------------------\n");
     }
     if(restore_object("banish/"+lower_case(str))){
       if(file_size("/banish/"+lower_case(str)) < 25){
         FAKERS = ({ "sagan", "shardak" });
         if(member_array(str,FAKERS) != -1){
             cat("/open/fakefin/"+str+".fin");
             return 1;
         }
       }
        write("------------BANISHED------------BANISHED------------\n");
     }
}
  if(!name) {
    write("No such player exists.\n");
    return 1;
  }
  privs = this_player()->query_level() >= INVIS_TELEPORT;
  print_stats();
  return 1;
}
 
print_stats() {
  string header;
  object bb;
  string pname;
  header=(capitalize(name) + " " + title + " (" + al_title + ") ");
if(pretitle)
  header=(pretitle + " " + capitalize(name) + " " + title + " (" + al_title + ") ");
  if(level>19 && level<100)
    header+=("<Wizard>");
  else if(level>99 && level<1000)
    header+=("<Senior Wizard>");
  else if(level >999 && level <10000)
    header+=("<Elder Wizard>");
  else if(level>9999)
    header+=("<God>");
/*
  write(format(header, 75));
*/
  write(header+"\n");
write("Level:"+pad(level+(ex_lv?"+"+ex_lv:""),-14)+(privs?"  Experience:"+pad(experience,-9):"")+"\n");
if(privs) write("Money:"+pad(money,-14)+"\n");
  if(!guild_name)
    guild_name = "none";
  guild_name=lower_case(guild_name);
guild_name = capitalize(guild_name);
if(strlen(guild_name) > 8) write("Guild name: "+guild_name+"\n");
else write("Guild name: "+pad(guild_name,-8)+"\n");
  if(privs) {
write("Guild Rank:"+pad(guild_rank,-9)+"  Guild Exp:"+pad(guild_exp,-10)+"\n");
    write("Attributes:\n");
write("Mag:"+P(magic_aptitude)+"  Sta:"+P(stamina)+"  Str:"+P(strength)+"  Ste:"+P(stealth)+"\n");
write("Int:"+P(intelligence)+"  Wil:"+P(will_power)+"  Pie:"+P(piety)+"  Luc:"+P(luck)+"\n");
    write("Player killer: "+(player_killing?"Yes":"No")+"\n");
    if(!mailaddr) mailaddr = "none";
    write("E-mail address: "+mailaddr+"\n");
    write("Last called from: " + hostname + " " + ((hostname != called_from_ip) ? "("+called_from_ip+")" : "") + "\n");
  } else write("Player killer: "+pad((player_killing?"Yes":"No"),-5)+"\n");
  bb = find_player(name);
  if((bb && !bb->query_invis()) || (bb && bb->query_invis() && bb->query_level() < this_player()->query_level()))
  {
    string vTest, vTest2;
    if(sscanf((string)bb->query_lastime(), "%s to %s", vTest, vTest2) == 2)
      write("Not logged off.\n");
   write("Logged on since: " + (string)bb->query_lastime() + ".\n");
  }
  else if(bb && bb->query_lastime()) write("Last called at: " + bb->query_lastime()+"\n");
  else if(level > 20 && old_last) write("Last called at: " + old_last+"\n");
   else write("Last called at: " + lastime + "\n");
  display_age();

  pname = "/players/"+lower_case(name)+"/PLAN";
  if(level > 20 && this_player()->query_level() > 20 && file_size(pname) >-1) {
    write("Plan:\n");
    cat(pname);
  }
  if((int)this_player()->query_level() <= APPRENTICE) {
    if(file_size("/open/pub_plans/" + name + ".plan") > 0)
      write("Plan:\n");
      cat("/open/pub_plans/" + name + ".plan");
    return 1; }
  return 1;
}
 
display_age() {
  int i;
  write("Age: ");
  i=age;
  if(i/43200) {
    write(i/43200 + " days ");
    i=i - (i/43200) * 43200;
  }
  if(i/1800) {
    write(i/1800 + " hours ");
    i=i - (i/1800) * 1800;
  }
  if(i/30) {
    write(i/30 + " minutes ");
    i=i - (i/30) * 30;
  }
  write(i*2 + " seconds.\n");
}



