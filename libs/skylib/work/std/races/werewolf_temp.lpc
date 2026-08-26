/* the Werewolf */
/* a serious upgrade */
/* Archana   /12/17/99 */

#include <weather.h>
#define SHADOW "/std/races/shadows/were_race"
inherit "/std/races/base";

void setup() {
  if(!WEATHER->query_moon_state()>3) {         
   set_long("The Werewolf, in wolf form.\n");
   set_name("werewolf");
   set_weight(3000);
   set_height(250);
   set_desc( "a nasty violent monster");
   add_ac( "blunt", "blunt", 3 );
   add_ac( "pierce", "pierce", 2 );
   add_ac( "sharp", "sharp", 2 );
   set_stats( ({ 10, 11, 9, 12, 0 }) );
   set_sight( ({ 5, 20, 200, 300 }) );
   
   bits = ({
  "head", "head", ({ 0, 10, ({"/std/bit", 1}), "left eye", "right eye", "nose", "skull",
           "left ear", "right ear", "tongue" }),
  "left eye", "eye", ({ "head", 1, ({"/std/bit", 1}) }),
  "right eye", "eye", ({ "head", 1, ({"/std/bit", 1}) }),
  "skull", "cranium", ({ "head", 5, ({"/std/bit", 1}), "brain", "teeth" }),
  "brain", "brain", ({ "skull", 3, ({"/std/bit", 1}) }),
  "left ear", "ear", ({"head", 1, ({"/std/bit", 1}) }),
  "right ear", "ear", ({"head", 1, ({"/std/bit", 1}) }),
  "nose", "nose", ({ "head", 1, ({"/std/bit", 1}) }),
  "teeth", "teeth", ({ "skull", 3, ({"/std/bit_set",1}), "tooth" }),
  "tooth", "tooth", ({ "teeth", 1, ({"/std/bit", 48}) }),
  "tongue", "tongue", ({ "head", 1, ({"/std/bit", 1}) }),
  "neck", "neck", ({ 0, 14, ({"/std/bit", 1}) }),
  "torso", "body", ({ 0, 200, ({"/std/bit", 1}), "heart", "liver", "left kidney",
                  "right kidney", "left lung", "right lung", "spleen",
                  "intestine", "pancreas" }),
  "heart", "heart", ({ "torso", 3, ({"/std/bit", 1}) }),
  "liver", "liver", ({ "torso", 5, ({"/std/bit", 1}) }),
  "left kidney", "kidney", ({ "torso", 4, ({"/std/bit", 1}) }),
  "right kidney", "kidney", ({ "torso",4, ({"/std/bit", 1}) }),
  "left lung", "lung", ({ "torso", 7, ({"/std/bit", 1}) }),
  "right lung", "lung", ({ "torso", 7, ({"/std/bit", 1}) }),
  "spleen", "spleen", ({ "torso", 6, ({"/std/bit", 1}) }),
  "intestine", "gut", ({ "torso", 9, ({"/std/bit", 1}) }),
  "pancreas", "pancreas", ({ "torso", 8, ({"/std/bit", 1}) }),
  "left front leg","leg",({ 0,15,({"/std/bit", 1}),"left front paw"}),
  "left front paw","paw", ({ "left front leg",6,({"/std/bit", 1}),"claw"}),
  "claw","claw",({"left front paw",1,({"/std/bit", 4})}),
  "right front leg","leg",({ 0,15,({"/std/bit", 1}),"right front paw"}),
  "right front paw","paw", ({ "right front leg",6,({"/std/bit", 1}),"claw"}),
  "claw","claw",({"right front paw",1,({"/std/bit", 4})}),
  "left rear leg","leg",({ 0,15,({"/std/bit", 1}),"left rear paw"}),
  "left rear paw","paw", ({ "left rear leg",6,({"/std/bit", 1}),"claw"}),
  "claw","claw",({"left rear paw",1,({"/std/bit", 4})}),
  "right rear leg","leg",({ 0,15,({"/std/bit", 1}),"right rear paw"}),
  "right rear paw","paw",({"right rear leg",6,({"/std/bit", 1}),"claw"}),
  "skin", "skin", ({ 0, 175, 0 }),
  "claw","claw",({"right rear paw",1,({"/std/bit", 4})}),
  "tail", "tail", ({0, 18, ({"/std/bit", 1}) }) });
  
  inedible = ({"skull", "claw", "tail", "teeth", "tooth" });
  unrottable = ({"skull", "claw", "teeth", "tooth" });
  set_skin( "skin" );
  }else{
   set_long("The Werewolf, in human form.\n");
   set_name("werewolf");
   set_weight(3000);
   set_height(250);
   set_desc( "a nasty violent monster");
   add_ac( "blunt", "blunt", 3 );
   add_ac( "blunt", "blunt", 2 );
   add_ac( "sharp", "sharp", 2 );
   set_stats( ({ 12, 10, 0, 12, 0 }) );
   set_sight( ({ 5, 20, 200, 300 }) );
   set_skin("pelt");
   inedible = ({ "skull", "teeth", "tooth" });
   unrottable = ({ "skull", "teeth", "tooth" });
   bits = ({
      "head", "head", ({ 0, 40, ({ "/std/bit", 1 }),
         "left ear", "right ear", "left eye", "right eye", "nose", "scalp",
         "tongue", "skull" }),
      "left ear", "ear", ({ "head", 1, ({ "/std/bit", 1 }) }),
      "right ear", "ear", ({ "head", 1, ({ "/std/bit", 1 }) }),
      "left eye", "eye", ({ "head", 1, ({ "/std/bit", 1 }) }),
      "right eye", "eye", ({ "head", 1, ({ "/std/bit", 1 }) }),
      "nose", "nose", ({ "head", 1, ({ "/std/bit", 1 }) }),
      "scalp", "scalp", ({ "head", 3, ({ "/std/bit", 1 }) }),
      "tongue", "tongue", ({ "head", 2, ({ "/std/bit", 1 }) }),
      "skull", "skull", ({ "head", 20, ({ "/std/bit", 1 }), "teeth", "brain" }),
      "brain", "brain", ({ "skull", 40, ({ "/std/bit", 1 }) }),
      "teeth", "teeth", ({ "skull", 2, ({ "/std/bit_set", 1}), "tooth" }),
      "tooth", "tooth", ({ "teeth", 1, ({ "/std/bit", 32}) }),
      "left arm", "arm", ({ 0, 80, ({ "/std/bit", 1 }), "left hand" }),
      "right arm", "arm", ({ 0, 80, ({ "/std/bit", 1 }), "right hand" }),
      "torso", "torso", ({ 0, 400, ({ "/std/bit", 1 }),
         "heart", "liver", "left kidney", "right kidney", "left lung",
         "right lung", "spleen" }),
      "left hand", "hand", ({ "left arm", 15, ({ "/std/bit", 1 }),
         "left little finger", "left third finger", "left index finger",
         "left ring finger", "left thumb" }),
      "right hand", "hand", ({ "right arm", 15, ({ "/std/bit", 1 }),
      "right little finger", "right third finger", "right index finger",
      "right ring finger", "right thumb" }),
      "left little finger", "finger", ({ "left hand", 1, ({ "/std/bit", 1 }) }),
      "left third finger", "finger", ({ "left hand", 1, ({ "/std/bit", 1 }) }),
      "left index finger", "finger", ({ "left hand", 1, ({ "/std/bit", 1 }) }),
      "left ring finger", "finger", ({ "left hand", 1, ({ "/std/bit", 1 }) }),
      "left thumb", "finger", ({ "left hand", 1, ({ "/std/bit", 1 }) }),
      "right little finger", "finger", ({ "right hand", 1, ({ "/std/bit", 1 }) }),
      "right third finger", "finger", ({ "right hand", 1, ({ "/std/bit", 1 }) }),
      "right index finger", "finger", ({ "right hand", 1, ({ "/std/bit", 1 }) }),
      "right ring finger", "finger", ({ "right hand", 1, ({ "/std/bit", 1 }) }),
      "right thumb", "finger", ({ "right hand", 1, ({ "/std/bit", 1 }) }),
      "heart", "heart", ({ "torso", 10, ({ "/std/bit", 1 }) }),
      "liver", "liver", ({ "torso", 5, ({ "/std/bit", 1 }) }),
      "left kidney", "kidney", ({ "torso", 5, ({ "/std/bit", 1 }) }),
      "right kidney", "kidney", ({ "torso", 5, ({ "/std/bit", 1 }) }),
      "left lung", "lung", ({ "torso", 5, ({ "/std/bit", 1 }) }),
      "right lung", "lung", ({ "torso", 5, ({ "/std/bit", 1 }) }),
      "spleen", "spleen", ({ "torso", 5, ({ "/std/bit", 1 }) }),
      "genitals", "genitals", ({ 0, 5, ({ "/std/bit", 1 }) }),
      "left leg", "leg", ({ 0, 300, ({ "/std/bit", 1 }), "left foot" }),
      "right leg", "leg", ({ 0, 300, ({ "/std/bit", 1 }), "right foot" }),
      "left foot", "foot", ({ "left leg", 50, ({ "/std/bit", 1 }), "left big toe",
         "left second toe", "left third toe",
         "left fourth toe", "left little toe" }),
      "right foot", "foot", ({ "right leg", 50, ({ "/std/bit", 1 }), "right big toe",
         "right second toe", "right third toe",
         "right fourth toe", "right little toe" }),
      "right little toe", "toe", ({ "right foot", 1, ({ "/std/bit", 1 }) }),
      "right second toe", "toe", ({ "right foot", 1, ({ "/std/bit", 1 }) }),
      "right third toe", "toe", ({ "right foot", 1, ({ "/std/bit", 1 }) }),
      "right fourth toe", "toe", ({ "right foot", 1, ({ "/std/bit", 1 }) }),
      "right big toe", "toe", ({ "right foot", 1, ({ "/std/bit", 1 }) }),
      "left little toe", "toe", ({ "left foot", 1, ({ "/std/bit", 1 }) }),
      "left second toe", "toe", ({ "left foot", 1, ({ "/std/bit", 1 }) }),
      "left third toe", "toe", ({ "left foot", 1, ({ "/std/bit", 1 }) }),
      "left fourth toe", "toe", ({ "left foot", 1, ({ "/std/bit", 1 }) }),
      "left big toe", "toe", ({ "left foot", 1, ({ "/std/bit", 1 }) }),
   });

  }
} /* setup() */ 
void start_player( object thing ) {
   ::start_player( thing );
   clone_object( SHADOW )->setup_shadow( thing );
} /* start_player() */

void set_unarmed_attacks( object thing ) {
      
   thing->remove_attack("feet");
   thing->remove_attack("hands");
   thing->add_attack( "claws", 75, ({ 32, 5, 15 }), "sharp", "unarmed", 0 );
   thing->add_attack( "bite", 25, ({ 60, 10, 50 }), "sharp", "unarmed", 0  );
   thing->add_attack_message( "claws", "sharp",
      ({
      20, ({
        "You tear at $hcname$ with your claws.\n",
        "$mcname$ tears at you with $mposs$ claws.\n",
        "$mcname$ tears $hcname$ with $mposs$ claws.\n"}),
      60, ({
        "You shred $hcname$ with your claws.\n",
        "$mcname$ shreds you with $mposs$ claws.\n",
        "$mcname$ shreds $hcname$ with $mposs$ claws.\n"}),
      100, ({
        "You rend the flesh of $hcname$.\n",
        "$mcname$ rends your flesh with $mposs$ claws.\n",
        "$mcname$ rends $hcname$ flesh with $mposs$ claws.\n"}),
      140, ({
        "You savagely tear $hcname$ to shreds.\n",
        "$mcname$ tears you to shreds.\n",
        "$mcname$ tears $hcname$ to shreds.\n"}),
      180, ({
        "You slice $hcname$ with your claws.\n",
        "$mcname$ slices you across the chest.\n",
        "$mcname$ slices $hcname$ across the chest.\n"}),
      220, ({
        "You rip large chunks of flesh out of $hcname$ with your claws.\n",
        "$mcname$ rips large chunks of flesh out of you with $mposs$ claws.\n",
        "$mcname$ rips large chunks of flesh out of $hcname$ with $mposs$ claws.\n"}),
      0, ({
        "You nearly disembowels $hcname$ with your claws.\n",
        "$mcname$ nearly disembowels you with $mposs$ claws.\n",
        "$mcname$ nearly disembowels $hcname$ with $mposs$ claws.\n"}),}) );
        
   thing->add_attack_message( "bite", "sharp",
      ({
      20, ({
        "You bite $hcname$.\n",
        "$mcname$ bites you deeply.\n",
        "$mcname$ bites $hcname$ deeply.\n"}),
      60, ({
        "You savage $hcname$.\n",
        "$mcname$ savagely tears at you with $mposs$ teeth.\n",
        "$mcname$ savagely tears at $hcname$ with $mposs$ teeth.\n"}),
      100, ({
        "You bites deeply into $hcname$ arm.\n",
        "$mcname$ bites deeply into your arm, tearing your flesh.\n",
        "$mcname$ bites deeply into $hcname$ arm.\n"}),
      140, ({
        "You bite off a large piece of $hcname$ flesh.\n",
        "$mcname$ bites a large piece of flesh off your side.\n",
        "$mcname$ bites large chunks of flesh from $hcname$.\n"}),
      180, ({
        "You rip into $hcname$ flesh with your teeth.\n",
        "$mcname$ rips into your flesh deeply, causing serious gashes.\n",
        "$mcname$ rips into $hcname$ causing serious gashes.\n"}),
      220, ({
        "You lunge for $hcname$ throat.\n",
        "$mcname$ lunges for your throat.\n",
        "$mcname$ lunges at $hcname$ biting deeply into $hposs$ throat.\n"}),
      0, ({
        "You sink your teeth deep into $hcname$'s muscle and sinew.\n",
        "$mcname$ sinks $mposs$ teeth deep into $hcname$'s muscle and sinew.\n",
        "$mcname$ sinks $mposs$ teeth into $hcname$'s muscle and sinew.\n"}),}) );  

} /* set_unarmed_attacks() */

           

          