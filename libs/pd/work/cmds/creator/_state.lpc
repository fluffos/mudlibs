#include <std.h>
#include <str_fmt.h>
#include <daemons.h>
 
inherit DAEMON;

string do_bar(int begin, int end)
{
 int i, a;
 string st;

 st = "%^BOLD%^%^BLUE%^[%^RESET%^";
 i = percent(begin, end);
 i += i;
 while(a<i)
  {
   if (a < 50)
     st += "%^GREEN%^%^BOLD%^";
   if (a > 50)
     st += "%^YELLOW%^";
   if (a > 120)
     st += "%^RED%^%^BOLD%^";
   st += "*";
   a += 10;
  } 

 if (strlen(TERMINAL_D->no_colours(st)) < 21)
   while(strlen(TERMINAL_D->no_colours(st)) < 21)
    st += "%^BLACK%^%^BOLD%^.%^RESET%^";

 st += "%^BOLD%^%^BLUE%^]%^RESET%^";
 return st;
}
object o;

void money_display();
void language_display();
 
int cmd_state(string str) {
   string name, title, classs, subcls, race, married, guild, sb;
   int level, hp, max_hp, mp, max_mp, sp, max_sp, exp, age;

  if(this_player()->query_ghost()) {
        notify_fail("You cannot do that in an immaterial state.\n");
        return 0;
   }
   if (!(string)this_player()->query_race())
   {
    write("You can not use this command until you have picked a race.");
    return 1;
   }

   if(str) {
        notify_fail("See also <skills> and <stats>\n");
        return 0;
   }
   o = this_player();

   name = (string)o->query_cap_name();
   title = (string)o->query_title();
   classs = (string)o->query_class();
   subcls = (string)o->query_subclass();
   race = (string)o->query_race();
   level = (int)o->query_level();
   exp = (int)o->query_exp();
   hp = (int)o->query_hp();
   max_hp = (int)o->query_max_hp();
   mp = (int)o->query_mp();
   max_mp = (int)o->query_max_mp();
   sp = (int)o->query_sp();
   max_sp = (int)o->query_max_sp();
   married = (string)(o->query_married());
   guild = (string)(o->query_guild());
   age = time() - (int)this_player()->query_birthday();
 
   if(!married) married = "None";
   if(!guild) guild = "None";
   if(!race) race = "Undefined";
   if(!classs) classs = "None";
   if(!subcls) subcls = "None";
message("info", "%^GREEN%^+=+=( %^YELLOW%^Score %^GREEN%^)=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+", this_player());
      sb = arrange_string(sb, 25);
      sb = arrange_string("%^BOLD%^%^BLUE%^Name     : %^RESET%^"+name, 25);
      sb += arrange_string("%^BOLD%^%^BLUE%^Title: %^RESET%^"+title, 43); 
   write(sb);
      sb = arrange_string(sb, 25);
      sb = arrange_string("%^BOLD%^%^BLUE%^Race     : %^RESET%^"+race, 25);
      sb += arrange_string("%^BOLD%^%^BLUE%^Level  : %^RESET%^"+level, 23);
      sb += arrange_string("%^BOLD%^%^BLUE%^Experience: %^RESET%^"+exp, 26);
   write(sb);
      sb = arrange_string(sb, 25);
      sb = arrange_string("%^BOLD%^%^BLUE%^Class    : %^RESET%^"+classs, 25);
      sb += arrange_string("%^BOLD%^%^BLUE%^Gender : %^RESET%^"+(string)o->query_gender(), 23);
      sb += arrange_string("%^BOLD%^%^BLUE%^Alignment : %^RESET%^"+capitalize(o->query_al_title()), 25);
   write(sb);
      sb = arrange_string(sb, 25);
      sb = arrange_string("%^BOLD%^%^BLUE%^Subclass : %^RESET%^"+subcls, 25);
      sb += arrange_string("%^BOLD%^%^BLUE%^Age    : %^RESET%^"+(18 + (age/4320000)), 23);
      sb += arrange_string("%^BOLD%^%^BLUE%^Spouse    : %^RESET%^"+married, 25);
   write(sb);
      sb = arrange_string(sb, 25);
      sb = arrange_string("%^BOLD%^%^BLUE%^Guild    : %^RESET%^"+guild, 25);
      sb += arrange_string("%^BOLD%^%^BLUE%^Quest Completed: %^RESET%^"+(int)o->query_quest_points(), 23);
   write(sb);

  write("%^GREEN%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=");
      sb = arrange_string(sb, 25);
      sb = arrange_string("%^BOLD%^%^MAGENTA%^Hit Points     : %^RESET%^"+hp+"%^BOLD%^%^BLUE%^/%^RESET%^"+max_hp, 35);
      sb += arrange_string("%^BOLD%^%^MAGENTA%^Intoxicated : %^RESET%^ ", 14);
      sb +=  do_bar(this_player()->query_intox(), this_player()->query_healing_formula());
   write(sb);
      sb = arrange_string("%^BOLD%^%^MAGENTA%^Stanima Points : %^RESET%^"+sp+"%^BOLD%^%^BLUE%^/%^RESET%^"+max_sp, 35);
      sb += arrange_string("%^BOLD%^%^MAGENTA%^Stuffed     : %^RESET%^", 14);
      sb +=  do_bar(this_player()->query_stuffed(), this_player()->query_healing_formula());
   write(sb);
      sb = arrange_string("%^BOLD%^%^MAGENTA%^Mana Points    : %^RESET%^"+mp+"%^BOLD%^%^BLUE%^/%^RESET%^"+max_mp, 35);
      sb += arrange_string("%^BOLD%^%^MAGENTA%^Quenched    : %^RESET%^", 14);
      sb +=  do_bar(this_player()->query_quenched(), this_player()->query_healing_formula());
   write(sb);
      sb = arrange_string("%^BOLD%^%^MAGENTA%^Encumberance   : %^RESET%^"+o->query_internal_encumbrance()+"%^BOLD%^%^BLUE%^/%^RESET%^"+o->query_max_internal_encumbrance(), 35);
      sb += arrange_string("%^BOLD%^%^MAGENTA%^Poisoned    : %^BLUE%^%^BOLD%^[", 17);
   if (this_player()->query_poisoning())
      sb +="%^RED%^%^BOLD%^%^FLASH%^Yes!%^RESET%^%^BLUE%^%^BOLD%^]%^RESET%^";
    else sb += "%^RESET%^No  %^BOLD%^%^BLUE%^]%^RESET%^";
   write(sb);
  write("%^GREEN%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=");
      sb = "%^BOLD%^%^RED%^Stat Point Totals :%^RESET%^ ???                 %^BOLD%^%^RED%^Skill Point Totals :%^RESET%^ ???";
   write(sb);
  write("%^GREEN%^-----------------------------------------------------------------------------");
   money_display();
  write("%^GREEN%^.............................................................................");
   this_player()->force_me("age"); 
message("info", "%^GREEN%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=",this_player());

   return 1;
}
 
void money_display() {
    string *currs;
    string borg;
    int i, tmp;
 
    currs = (string *)o->query_currencies();
    if((!currs || !sizeof(currs)) ) {
        message("info", "No money.", this_player());
        return;
    }
    for(borg = "%^BOLD%^Money : %^RESET%^", i=0, tmp = sizeof(currs); i<tmp; i++) {
        borg += ((o->query_money(currs[i]))+" "+currs[i]);
        if(i == tmp-1) borg +=(".");
        else if(tmp > 2 && i == tmp-2) borg += (", and ");
        else if(tmp == 2) borg +=(" and ");
        else borg +=(", ");
    }
    message("info", borg, this_player());
    return;
}
 


void help() {
    message("help",
      "Syntax: <stat [player]>\n\n"
      "Gives you vital information about a player or monster.", this_player());
}

