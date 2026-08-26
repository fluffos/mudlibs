/* (cre) Nevvyn: So, this is a vicious, man eating (with one tooth) red,
         bladdered piece of fin clad seaweed with extra special sauce?
   (cre) Presto: if a seaweed leaves New York, traveling west at 30 miles per
     hour, and Nevvyn puts on his fins and leaves Los Angeles 3 hours later
     heading east at 35 miles per hour, how many bladders does the sewaeed have
     at 2:00 */

inherit "/std/races/base";

void setup() {
   set_name( "sargassum" );
   set_long( "A seaweed monster.\n" );
   set_height( 500 );
   set_weight( 5000 );
   set_desc( "a large sapient lump of seaweed" );

   bits = ({ 
      "tendril", "tendril", ({ 0, 35, ({ "/std/bit", 15 }) }),
//      "bladder", "bladder", ({ "tendril", 1, ({ "/std/bit", 3 }) }),
// I wanted to have 3 bladders per tendril, but the bit handler won't allow
// me to do this for some reason.
      "root", "root", ({ 0, 70, ({ "/std/bit", 15 }) })
   });

   inedible = ({ "root" });
   unrottable = ({ });
   set_skin( "exocuticule" );

   add_ac( "blunt", "blunt", 100 );
   add_ac( "pierce", "pierce", 75 );
   add_ac( "sharp", "sharp", 25 );

   set_stats( ({ 2, -4, -2, 4, -4 }) );
} /* create() */

void set_unarmed_attacks( object thing ) {
   int number;

   number = (int)thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
   number = 2 + sqrt( number );

   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );

   thing->remove_attack( "tendrils" );

   thing->add_attack( "tendrils", 100, ({ number, 10, number }),
      "blunt", "blunt", 0 );

   thing->add_attack_message( "tendrils", "blunt", ({
      20, ({
        "You tap $hcname$ with your tendrils.\n",
        "$mcname$ taps you with $mposs$ tendrils.\n",
        "$mcname$ taps $hcname$ with $mposs$ tendrils.\n" }),
      60, ({
        "You hit $hcname$ with your tendrils.\n",
        "$mcname$ hits you with $mposs$ tendrils.\n",
        "$mcname$ hits $hcname$ with $mposs$ tendrils.\n" }),
      100, ({
        "You bruise $hcname$ with your tendrils.\n",
        "$mcname$ bruises you with $mposs$ tendrils.\n",
        "$mcname$ bruises $hcname$ with $mposs$ tendrils.\n" }),
      140, ({
        "You hit $hcname$ hard with your tendrils.\n",
        "$mcname$ hits you hard with $mposs$ tendrils.\n",
        "$mcname$ hits $hcname$ hard with $mposs$ tendrils.\n" }),
      180, ({
        "You smash your tendrils into $hcname$.\n",
        "$mcname$ smashes $mposs$ tendrils into you.\n",
        "$mcname$ smashes $mposs$ tendrils into $hcname$.\n" }),
      220, ({
        "You crush $hcname$ with your tendrils.\n",
        "$mcname$ crushes you with $mposs$ tendrils.\n",
        "$mcname$ crushes $hcname$ with $mposs$ tendrils.\n" }),
      0, ({
        "You mash $hcname$ with your tendrils.\n",
        "$mcname$ mashes you with $mposs$ tendrils.\n",
        "$mcname$ mashes $hcname$ with $mposs$ tendrils.\n" }),
    }) );
} /* set_unarmed_attacks() */

void start_player( object thing ) {
   ::start_player( thing );
   thing->add_property( "gills", 1 );
} /* start_player() */
