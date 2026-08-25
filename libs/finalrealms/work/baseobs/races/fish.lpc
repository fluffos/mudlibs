inherit "/std/races/standard";
int query_swim_stamina(object player) { return -1; } // fully aquatic.
int query_underwater_breathing(object player) { return -1; }
int query_aquatic(object player)
{
    return player->query_con() * 50;
}

void setup() {
   set_long("Fish,  yes.  A fish.  Nice generic standard fish thing.\n");
   set_name("fish");
   /* throw away human bits and replace totally */
   bits = ({ 
"head", 0, ({ 0, 2, 0, "left eye", "right eye", "left gill", "right gill" }),
"left eye", "eye", ({ "head", 1, 0 }),
"right eye", "eye", ({ "head", 1, 0 }),
"left gill", "gill", ({ "head", 1, 0 }),
"right gill", "gill", ({ "head", 1, 0 }),
"torso", "guts", ({ 0, 400, 0, "heart", "liver", "left kidney",
    "right kidney", "spleen" }),
"heart", "", ({ "guts", 10, 0 }),
"liver", "", ({ "guts", 5, 0 }),
"left kidney", "kidney", ({ "guts", 5, 0 }),
"right kidney", "kidney", ({ "guts", 5, 0 }),
"spleen", "", ({ "guts", 5, 0 }),
"genitals", "", ({ 0, 5, 0 }),  /* sex ????  ohhh yes*/
"left petral fin", "fin", ({ 0, 5, 0, }),
"right petral fin", "fin", ({ 0, 5, 0, }),
"dorsal petral fin", "fin", ({ 0, 5, 0 }),
"tail", 0, ({ 0, 5, 0 }),
});
  set_race_size(1);
}

string query_desc(object ob) {
   return "A fish, the type with fins.\n";
}
string *valid_attacks()
{
   return ({
	"$att_name$ bites $def_name$ on the $def_part$",
	"You bite $def_name$ on the $def_part$",
	"$att_name$ bites you on the $def_part$",

	"$att_name$'s tail swats $def_name$ on the $def_part$",
	"You swat $def_name$ with your tail",
	"$att_name$ swats you with it's tail",

	"$att_name$ rasps $def_name$ with it's scales",
	"You rasp $def_name$ with your scales",
	"$att_name$ rasps you with it's scales",

  	"$att_name$ tears a chunk of flesh from $def_name$'s $def_part$",
	"You tear a chunk of flesh from $def_name$'s $def_part$",
	"$att_name$ tears a chunk of flesh from your $def_part$",
	});
}
	
