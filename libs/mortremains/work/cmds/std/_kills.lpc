/*
** File: _kills.c   ("kills" command)
** Creator: Cyanide@Nightfall's Keep
** Purpose: Tells a player all sorts of information related to 
**      his or her kills information.
** Credits:
**   15 Mar 98    Cyanide created the file.
** (04-06-98) Chronos adds a help() function.
*/

#include "/u/c/cyanide/debug.h"

// Prototypes
string parse_names(string *);

// Constant definitions
#define LINE1 \
"=+=--=+=--=+=--=+=--=+=--=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=\n"
#define LINE2 \
"----------------------------------------------------------------------------\n"

// Code
int cmd_kills(string targ) {
   float ratio, xp;
   int mkills, pkills;
   string *killed, *killed_by, str;
   object obj;

   if (targ && wizardp(TP)) {
      obj = find_player(targ);
      if (!obj) {
         write("Couldn't find player named "+capitalize(targ)+"\n");
         return 1;
      }
      targ = capitalize(targ);
   } else {
      obj = TP;
   }

   mkills = obj->query("kills");
   pkills = obj->query("pkills");
   mkills-=pkills;

   xp = obj->query("experience");
   if (!mkills) ratio = 0.0;
     else (ratio = xp/mkills);

   killed = obj->query("pkill_list");
   killed_by = obj->query("pdeath_list");

   str = LINE1 + (obj==TP ? "You have " : targ+" has ") + 
      mkills + " monster kills and " + pkills + 
      " player kills.\n";
   
   str += (obj==TP ? "Your " : targ+"'s ") + 
      "experience point average is " + ratio +
      " experience points per kill.\n" + LINE2;
   
   targ = (obj==TP ? "You have" : targ+" has");
   str += iwrap(targ+" killed: " + parse_names(killed)) +
      iwrap("\n"+targ+" been killed by: " + parse_names(killed_by));

   str += LINE1;
   write(str);
   return 1;
}

string parse_names(string *names) {
   int i, *mapVi;
   string str, *mapKs;
   mapping map = ([]);

   if (!sizeof(names)) return "Nobody";

   for (i=0; i<sizeof(names); i++) {
      if (member_array(names[i], keys(map)) != -1) 
         map[names[i]]++;         
      else
         map += ([ names[i] : 1 ]);
   }

   mapKs = keys(map);
   mapVi = values(map);
   str = mapKs[0];
   if (mapVi[0]>1) str += " (" + mapVi[0] + " times)";  //Primer

   for (i=1; i<sizeof(mapVi); i++) {
      str += (", " + mapKs[i]);
      if (mapVi[i]>1)
         str += " ("+mapVi[i]+" times)";
   }

   return str;
}

string help() {
  return @ENDHELP
Usage: kills

This command shows you all your relevant combat and killing statistics.
ENDHELP
  ;
}
/* EOF */
