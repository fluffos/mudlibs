inherit "/std/races/standard";

/* the standard race... */
/* Verkho - added the race_size func */




void setup() {
   set_long("A generic four legged herbivore.\n");
   set_race_size(8);

   set_limbs(0);

   bits = ({
      "head", "", ({ 0, 40, 0, 
         "left ear", "right ear", "left eye", "right eye", "nose",
         "tongue", "teeth", "skull" }),
      "left ear", "ear", ({ "head", 1, 0 }),
      "right ear", "ear", ({ "head", 1, 0 }),
      "left eye", "eye", ({ "head", 1, 0 }),
      "right eye", "eye", ({ "head", 1, 0 }),
      "nose", "", ({ "head", 1, 0 }),
      "tongue", "", ({ "head", 2, 0 }),
      "teeth", "", ({ "head", 2, 0 }),
      "skull", "cranium", ({ "head", 20, 0 }),
      "left fore leg", "leg", ({ 0, 80, 0, "left fore hoof" }),
      "right fore leg", "leg", ({ 0, 80, 0, "right fore hoof" }),
      "body","", ({ 0, 400, 0, "heart", "liver", "left kidney",
         "right kidney", "left lung", "right lung", "spleen" }),
      "left fore hoof", "hoof", ({ "left fore leg",1,0 }),
      "right fore hoof", "hoof", ({ "right fore leg",1,0 }),
      
      "heart", "", ({ "torso", 10, 0 }),
      "liver", "", ({ "torso", 5, 0 }),
      "left kidney", "kidney", ({ "torso", 5, 0 }),
      "right kidney", "kidney", ({ "torso", 5, 0 }),
      "left lung", "lung", ({ "torso", 5, 0 }),
      "right lung", "lung", ({ "torso", 5, 0 }),
      "spleen", "", ({ "torso", 5, 0 }),
      "genitals", "", ({ 0, 5, 0 }),  /* sex ????  ohhh yes*/
      "left rear leg", "leg", ({ 0, 300, 0, "left rear hoof" }),
      "right rear leg", "leg", ({ 0, 300, 0, "right rear hoof" }),
      "left rear hoof", "hoof", ({ "left rear leg",1,0 }),
      "right rear hoof", "hoof", ({ "right rear leg",1,0 }),
   });
  set_name("quadruped");
}

/*
   Taniwha, 1997, default atatck messages
   most frequent first 
*/   
string * valid_attacks()
{

	return  ({
        "$att_name$ kicks $def_name$ in the $def_part$",
        "You kick $def_name$ in the $def_part$",
        "$att_name$ kicks you in the $def_part$",
        
        "$att_name$ bites $def_name$ in the $def_part$",
        "You bite $def_name$ in the $def_part$",
        "$att_name$ bite you in the $def_part$",

        "$att_name$ rears and brings $att_his$ front hooves down on $def_name$",
        "You rear and crush $def_name$ with your fore hooves",
        "$att_name$ rears and castches you in the $def_part$ with $att_his$ front hooves",
        
        "$att_name$ headbutts $def_name$",
        "You headbutt $def_name$",
        "$att_name$ headbutts you"
        });
}


