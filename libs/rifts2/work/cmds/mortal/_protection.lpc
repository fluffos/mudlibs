//  Protection command....tells your ac.

#include <std.h>
#define DESC_COLOR ({ "", "%^RED%^", \
  "%^RED%^%^BOLD%^", "%^BLUE%^", \
  "%^BLUE%^%^BOLD%^", "%^CYAN%^", \
  "%^CYAN%^%^BOLD%^", "%^MAGENTA%^", \
  "%^MAGENTA%^%^BOLD%^", "%^GREEN%^", \
  "%^GREEN%^%^BOLD%^", "%^YELLOW%^", \
  "%^YELLOW%^%^BOLD%^", "%^RED%^", "%^RED%^%^BOLD%^" })
#define DESCS ({ "none", "very poor", "poor", "low", "below average", "average", "above average", "good", "very good", "extremely good", "superb", "excellent", "awesome", "god awesome", "IMPREGNABLE!" })
#define PHYSICAL ({ "impaling", "impact", "crushing", "cutting" })

int cmd_protection(string str) {
  string *limbs, tmp;
  int ac, i, j, p_ac, idx;

  limbs = this_player()->query_limbs();
  if(!limbs || !(i=sizeof(limbs)) || this_player()->query_ghost()) {
    write("You have no body to protect!");
    return 1;
  }
  i = sizeof(limbs);
  j = sizeof(DAMAGE_TYPES);
  if(!str || str != "limb") {
    tmp =
    "%^BLUE%^+-------------------------------------------------------+%^RESET%^\n"
    "%^BLUE%^|%^RESET%^ %^YELLOW%^%^BOLD%^Protection by Damage Type (avg. over body)            %^RESET%^%^BLUE%^|\n"
    "%^BLUE%^+---------------+---------------------------------------+\n"
    "%^BLUE%^|%^RESET%^ %^YELLOW%^%^BOLD%^Damage Type   %^RESET%^%^BLUE%^|%^RESET%^ %^YELLOW%^%^BOLD%^Protection Level                      %^RESET%^%^BLUE%^|\n"
    "%^BLUE%^+---------------+---------------------------------------+\n";
    while(j--) {
      ac = 0;
      i = sizeof(limbs);
      while(i--)
        ac += (int)this_player()->query_current_protection(limbs[i], DAMAGE_TYPES[j]);
      ac /= sizeof(limbs);
      tmp += "%^BLUE%^|%^RESET%^ ";
      tmp += "%^YELLOW%^%^BOLD%^"+arrange_string(DAMAGE_TYPES[j], 14);
      tmp += "%^RESET%^%^BLUE%^|%^RESET%^ ";
      if(ac <= 1) idx = 0;
      else {
        idx = 1 + ac / 20;
        //if(ac > 50) {
        //  ac -= 50;
       //   idx -= (ac/8) - (ac/20);
       // }
      }
      if(idx > 14) idx = 14;
      tmp += DESC_COLOR[idx] + arrange_string(DESCS[idx], 38);
      tmp += "%^RESET%^%^BLUE%^|\n";
    }
    tmp += "%^BLUE%^+---------------+---------------------------------------+\n";
  }
  else {
    tmp =
    "%^BLUE%^+-------------------------------------------------------+%^RESET%^\n"
    "%^BLUE%^|%^RESET%^ %^YELLOW%^%^BOLD%^Protection by Limb (avg. over types)                  %^RESET%^%^BLUE%^|\n"
    "%^BLUE%^+---------------+---------------------------------------+\n"
    "%^BLUE%^|%^RESET%^ %^YELLOW%^%^BOLD%^Type          %^RESET%^%^BLUE%^|%^RESET%^ %^YELLOW%^%^BOLD%^Protection Level                      %^RESET%^%^BLUE%^|\n"
    "%^BLUE%^+---------------+---------------------------------------+\n";
    while(i--) {
      ac = 0;
      p_ac = 0;
      j = sizeof(DAMAGE_TYPES);
      while(j--) {
        if(member_array(DAMAGE_TYPES[j], PHYSICAL) < 0)
          ac += (int)this_player()->query_current_protection(limbs[i], DAMAGE_TYPES[j]);
        else
          p_ac += (int)this_player()->query_current_protection(limbs[i], DAMAGE_TYPES[j]);
      }
      p_ac /= sizeof(PHYSICAL);
      ac /= (sizeof(DAMAGE_TYPES)-sizeof(PHYSICAL));
      tmp += "%^BLUE%^|%^RESET%^ ";
      tmp += "%^YELLOW%^%^BOLD%^"+arrange_string(limbs[i], 14);
      tmp += "%^RESET%^%^BLUE%^|%^RESET%^ ";
      if(p_ac <= 1) idx = 0;
      else {
        idx = 1 + p_ac / 20;
       // if(p_ac > 50) {
       //   p_ac -= 50;
       //   idx -= (p_ac/8) - (p_ac/20);
       // }
      }
      if(idx > 14) idx = 14;
      tmp += "%^CYAN%^%^BOLD%^Physical: %^RESET%^" + DESC_COLOR[idx] + arrange_string(DESCS[idx], 28);
      tmp += "%^RESET%^%^BLUE%^|\n";
      tmp += "%^BLUE%^|%^RESET%^ ";
      tmp += "%^YELLOW%^%^BOLD%^              ";
      tmp += "%^RESET%^%^BLUE%^|%^RESET%^ ";
      if(ac <= 1) idx = 0;
      else {
        idx = 1 + ac / 20;
  //      if(ac > 40) {
    //      ac -= 40;
     //     idx -= (ac/6) - (ac/17);
     //   }
      }
      if(idx > 14) idx = 14;
      tmp += "%^CYAN%^%^BOLD%^Magical: %^RESET%^" + DESC_COLOR[idx] + arrange_string(DESCS[idx], 29);
      tmp += "%^RESET%^%^BLUE%^|\n";
    }
    tmp += "%^BLUE%^+---------------+---------------------------------------+\n";
  }
  this_player()->more(explode(tmp, "\n"));
  return 1;
}

int help() {
  message("help",
  "Tells the protection you have against various types of damage, including "
  "protection from worn armour, spells, etc.\n\n"
  "Syntax:   'protection' (shows prot. by damage type)\n"
  "          'protection limb' (shows prot. by limb)\n",
  this_player());
  return 1;
}
