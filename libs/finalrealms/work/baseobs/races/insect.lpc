/* the standard race... */
/* Verkho - added the race_size func */
inherit "/std/races/standard";
int race_size;
int limbs;

mixed *bits;




void setup() {
   set_long("A gener8ic insect of some kind.\n");
    reset_get();
    race_size = 1; // This is used as a standard 'human' size
    limbs = 6;
    set_limbs(6);
    bits = ({
      "head", "", ({ 0, 40, 0, 
	"left antenna", "right antenna", "left eye", "right eye",  
	"mouthparts", "skull" }),
      "left antenna", "antenna", ({ "head", 1, 0 }),
      "right antenna", "antenna", ({ "head", 1, 0 }),
      "left eye", "eye", ({ "head", 1, 0 }),
      "right eye", "eye", ({ "head", 1, 0 }),
      "mouthparts", "", ({ "head", 2, 0 }),
      "skull", "chitin", ({ "head", 20, 0 }),
      "left forelimb", "forelimb", ({ 0, 80, 0, "left foreclaw" }),
      "right forelimb", "forelimb", ({ 0, 80, 0, "right foreclaw" }),
      "thorax", "chest", ({ 0, 400, 0, "heart"   }),
      "abdomen","body",({0,500,0, "gut"}),
      "left foreclaw",({"left forelimb",1,0}),
      "right foreclaw",({"right forelimb",1,0}),
      "left foreleg", "foreleg", ({ 0, 80, 0, "left claw" }),
      "right foreleg", "foreleg", ({ 0, 80, 0, "right claw" }),
      "left rearleg", "rearleg", ({ 0, 80, 0, "left rearclaw" }),
      "right rearleg", "rearleg", ({ 0, 80, 0, "right rearclaw" }),
      "left claw",({"left foreleg",1,0}),
      "right claw",({"right foreleg",1,0}),
      "left rearclaw",({"left rearleg",1,0}),
      "right rearclaw",({"right rearleg",1,0}),
      "heart", "", ({ "thorax", 10, 0 }),
      "left big toe", "toe", ({ "left foot", 1, 0 }),
    });
    set_name("insect");
    //set_light_limits(LIGHT_STANDARD_LOW, LIGHT_STANDARD_HIGH);
}

/*
   Taniwha, 1997, default atatck messages
   most frequent first 
*/   
string * valid_attacks()
{

    return  ({
   "$att_name$ slashes $def_name$ with $att_his$ foreclaws",
   "You slash $def_name$ with your foreclaws",
   "$att_name$ slashes you with $att_his$ foreclaws",

   "$att_name$ sidekicks $def_name$ in the $def_part$",
   "You sidekick $def_name$ in the $def_part$",
   "$att_name$ sidekicks you in the $def_part$",

   "$att_name$ chews on $def_name$'s $def_part$",
   "You chew on $def_name$'s $def_part$",
   "$att_name$ chews on your $def_part$",

   "$att_name$ hits $def_name$ on the $def_part$ with a chitinous appendage",
   "You hit $def_name$'s $def_part$ with a chitinous appendage",
   "$att_name$ hits your $def_part$ with a chitinous appendage"
    });
}


