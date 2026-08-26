/*
** File: _kills.c   ("kills" command)
** Creator: Cyanide@Nightfall's Keep
** Purpose: Tells a player all sorts of information related to 
**      his or her kills information.
** Credits:
**   15 Mar 98    Cyanide created the file.
*/

// Prototypes
string parse_names(string *);

// Constant definitions
#define LINE1 \
"=+=--=+=--=+=--=+=--=+=--=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=\n"
#define LINE2 \
"----------------------------------------------------------------------------\n"

// Code
int cmd_kills() {
   float ratio;
   int mkills, pkills, xp;
   string *killed, *killed_by, str;

   mkills = TP->query("kills");
   pkills = TP->query("pkills");
   mkills-=pkills;

   xp = TP->query("experience");
   ratio = xp/kills;

   killed = TP->query("pkill_list");
   killed_by = TP->query("pdeath_list");

   str = LINE1 + "You have " + mkills + " monster kills and " +
      pkills + " player kills.\n";
   
   str += "Your experience point average is " + ratio +
      " experience points per kill.\n" + LINE2;
   
   str += wrap("You have killed: " + parse_names(killed)) +
      wrap("You have been killed by: " + parse_names(killed_by));

   str += LINE2;
   return 1;
}

string parse_names(string *names) {
   int i, *mapVi;
   string str, *mapKs;
   mapping map = ([]);

   for (i=0; i<sizeof(names); i++) {
      if (member_array(names[i], keys(map)==-1)
         map[names[i]]++;
      else
         map += ([ names[i] : 1 ]);
   }

   mapKs = keys(map);
   mapVi = values(map);
   str = mapKs[0];
   if (mapVi[0]>1) str += "(" + mapVi[0] + " times)";  //Primer

   for (i=1; i<sizeof(mapVi); i++) {
      str += (", " + mapKs[i]);
      if (mapVi[i]>1)
         str += "("+mapVi[i]+" times)";
   }
}

/* EOF */