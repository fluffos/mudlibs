inherit "/std/races/standard";
int query_swim_stamina(object player) { return 10000; }
int query_underwater_breathing(object player) { return -1;} 
// sinks eventually but won't drown
string *descs = ({ "A small green frog.\n","A small rather flat looking frog.\n","A desicated amphibian thing, that could once have been a frog.\n","A generic lilly pad jumper.\n" });

void setup() {
   set_long("A small green frog.\n");

   set_name("frog");
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
"left petral leg", "leg", ({ 0, 5, 0, }),
"right petral leg", "leg", ({ 0, 5, 0, }),
"dorsal petral leg", "leg", ({ 0, 5, 0 }),
"tail", 0, ({ 0, 5, 0 }),
});
}

string query_desc(object ob) {
   return "A small green frog.\n";
}
int player_start(object player) {
tell_object(player,"Testing\n");
 player->move("/d/ss/daggerford/board_room");
 return 1;
 }
