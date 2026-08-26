inherit "/std/races/ruminant";

void setup() {
   set_name( "elephant" );
   set_long( "This is an elephant.  A large creature with a thick grey "
      "hide.  He seems to weigh a lot so don't let him step on your "
      "toe.\n" );
   set_height( 280 );
   set_weight( 100000 );
   set_desc( "an elephant that looks back at you with small nice eyes" );

   remove_bit( "nose" );
   remove_bit( "head" );

   add_bit( "head", "head", ({ 0, 135, 0,
      "left eye", "right eye", "skull", "tongue", "left ear", "right ear",
      "tusk", "tusks", "trunk" }) );
   add_bit( "tail", "tail", ({ 0, 15, 0 }) );
   add_bit( "tusk", "tusk", ({ "head", 20, ({"/std/bit_set", 1}),
      "tusks" }) );
   add_bit( "tusks", "tusks", ({ "head", 40, ({"/std/bit", 2}) }) );
   add_bit( "trunk", "trunk", ({ "head", 30, 0 }) );

   inedible += ({ "tail", "tusk", "tusks" });  
   unrottable += ({ "tusk", "tusks" });

   add_ac( "blunt", "blunt", ({ 40, 20}) );
   add_ac( "pierce", "pierce", ({ 30, 20 }) );
   add_ac( "sharp", "sharp", ({ 50, 20 }) );
   add_ac( "acid", "acid", 20 );
   add_ac( "fire", "fire", 20 );

   set_stats( ({ 10, -8, -4, 16, -2 }) );
} /* setup() */

void set_unarmed_attacks( object thing ) {
   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );

   thing->remove_attack( "tusks" );
   thing->remove_attack( "crush" );
   thing->remove_attack( "ram" );
   thing->remove_attack( "trunk" );

   thing->add_attack( "tusks", 20, ({75, 5, 30}),
      "pierce", "unarmed", 0 );

   thing->add_attack( "crush", 10, ({100, 5, 50}),
      "blunt", "unarmed", 0 );

   thing->add_attack_message( "crush", "unarmed", ({
      100, ({
         "You stand on your hind legs and crash down on $hcname$, who rolls "
            "away and only gets lightly crushed.\n",
         "$mcname$ stands on $mposs$ hind legs and crashes down on you, but "
            "you roll away and only get lightly crushed.\n",
         "$mcname$ stands on $mposs$ hind legs and crashes down on "
            "$hcname$, who rolls away and only gets lightly crushed.\n" }),
      150, ({
         "You stand on your hind legs and crash down on $hcname$, crushing "
            "$hobj$ with your great weight.\n",
         "$mcname$ stands on $mposs$ hind legs and crashes down on you, "
            "crushing you with $mposs$ great weight.\n",
         "$mcname$ stands on $mposs$ hind legs and crashes down on "
            "$hcname$, crushing $hobj$ with $mposs$ great weight.\n" }),
      0, ({ 
         "You stand on your hind legs and crash down on $hcname$, crushing "
            "$hobj$ into a bloody mess with your great weight.\n",
         "$mcname$ stands on $mposs$ hind legs and crashes down on you, "
            "crushing you into a bloody mess with $mposs$ great weight.\n",
         "$mcname$ stands on $mposs$ hind legs and crashes down on "
            "$hcname$, crushing $hobj$ into a bloody mess with $mposs$ "
            "great weight.\n" }),
      }) );

   thing->add_attack( "ram", 10, ({50, 3, 20}),
      "blunt", "unarmed", 0 );

   thing->add_attack_message( "ram", "unarmed", ({
      100, ({
         "You charge $hcname$ and strike $hobj$ to the ground.  $hcname$ "
            "swiftly jumps up.\n",
         "$mcname$ charges you and strikes you to the ground.  You swiftly "
            "jump up.\n",
         "$mcname$ charges $hcname$ and strikes $hobj$ to the ground.  "
            "$hcname$ swiftly jumps up.\n" }),
      150, ({
         "You charge $hcname$ and strike $hobj$ hard, making $hobj$ stagger "
            "around.",
         "$mcname$ charges you and strikes you hard, making you stagger "
            "around.",
         "$mcname$ charges $hcname$ and strikes $hobj$, making $hobj$ "
            "stagger around.\n" }),
      0, ({ 
         "You charge $hcname$ and strike $hobj$ to the ground.  $hcname$ "
            "stands up and stumbles around a little groggily.",
         "$mcname$ charges you and strikes you to the ground.  You stand "
            "up and stumble around a little groggily.\n",
         "$mcname$ charges $hcname$ and strikes $hobj$ to the ground.  "
            "$hcname$ stands up and stumbles around groggily.\n" }),
      }) );

   thing->add_attack( "trunk", 20, ({50, 3, 20}),
      "blunt", "unarmed", 0 );

   thing->add_attack_message( "trunk", "unarmed", ({
      100, ({
         "You swing your trunk at $hcname$, hitting $hobj$ hard.\n",
         "$mcname$ swings $mposs$ trunk at you, hitting you hard.\n",
         "$mcname$ swings $mposs$ trunk at $hcname$, hitting $hobj$ "
            "hard.\n" }),
      150, ({
         "You swing your trunk, which thumps forcefully into $hcname$.\n",
         "$mcname$ swings $mposs$ trunk, which thumps forcefully into "
            "you.\n",
         "$mcname$ swings $mposs$ trunk, which thumps forcefully into "
            "$hcname$.\n" }),
      0, ({ 
         "You swing your trunk at $hcname$, knocking $hobj$ down.  $hpron$ "
            "picks $hobj$self up groggily.\n",
         "$mcname$ swings $mposs$ trunk at you, knocking you down.  You "
            "pick yourself up groggily.\n",
         "$mcname$ swings $mposs$ trunk at $hcname$ and knocks $hobj$ "
            "down.  $hpron$ picks $hobj$self up groggily.\n" })
      }) );
} /* set_unarmed_attacks() */
