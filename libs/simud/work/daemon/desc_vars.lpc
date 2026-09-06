/** Code for new description variables goes here.
 *
 * Important: Please keep things in alphabetical order, see the create() at end
 */

/** ADJ (who): A player's adjectival description
 */
string adj( object who ) {
   mapping desc = who->query_env_var("desc");
   if ( !desc || !desc["adj"] ) return "bland";
   mixed adjs = desc["adj"];

   if (stringp(adjs)) {
      if (strlen(adjs)) {
         return "/daemon/dictionary"->a_an(adjs) + " " + adjs;
      } else {
         return "";
      }
   } else {
      return "an inexplicably buggy";
   }
}

/** CANREAD(dc): Pass a basic literacy check. If no DC is given, 30% is assumed.
 *
 * ?(CANREAD(20): The sign reads 'I hate everything')
 */
string canread( object env, string sdc ) {
   int dc = to_int(sdc);
   if( !dc ) dc = 30;
   if( this_player()->cached_skill_check(600, object_name(env), "knowledge.literacy", dc) ) return "";
   return 0;
}

/** CANELVEN(dc): Proficiency in the elven language.
 *
 * The guard ?(CANELVEN(40): says \"I hate your guts\" in Elven.):(says something angrily, but you can't understand it).
 */
string canelven( object env, string sdc ) {
   int dc = to_int(sdc);
   if( !dc ) dc = 30;
   if( this_player()->cached_skill_check(600, object_name(env), "knowledge.lang.elven", dc) ) return "";
   return 0;
}

/** CAPACITY (value): The remaining free capacity of this object, stated
 * as "mostly full", "half-full", "mostly empty", etc. This uses the maximum
 * of weight and bulk.
 */
string capacity( object env ) {
   int bpercent, wpercent, tmp;

   bpercent = env->query_held_bulk() * 100;
   wpercent = env->query_held_weight() * 100;
   if( (tmp = env->query_bulk_capacity()) > 0 ) bpercent = bpercent / tmp + 1; else bpercent = 0;
   if( (tmp = env->query_weight_capacity()) > 0 ) wpercent = wpercent / tmp + 1; else wpercent = 0;

   switch(bpercent > wpercent?bpercent:wpercent) {
      case 0: return "empty";
      case 1..20: return "nearly empty";
      case 21..40: return "less than half-full";
      case 41..49: return "half-empty";
      case 50..60: return "half-full";
      case 61..80: return "almost full";
      case 81..99: return "mostly full";
      case 100..101: return "completely full";
      default: return "overfilled";
   }

   return ""; // because ldmud complains about missing returns
}

/** EYES (who): An adjectival description of a player's eyes
 *
 */
string eyes( object who ) {
   mapping desc = who->query_env_var("desc");
   if ( !desc ) return "bland eyes";
   string eye_str;

   if (strlen(desc["eye_adj"]) > 0)
      eye_str = desc["eye_adj"] + " " + desc["eye_color"] + " eye";
   else
      eye_str = desc["eye_color"] + " eye";

   if (desc["eye_count"] == "0")
      eye_str = "one " + eye_str;
   else
      eye_str = eye_str + "s";

   return eye_str;
}

/** GENDERNOUN (who): Man/woman/person by gender */
string gendernoun( object who ) {
   if (who->query_gender() == 1)
      return "man";
   else if (who->query_gender() == 2)
      return "woman";
   else
      return "person";
}

/** HAIR (who): A nominal description of a player's hair.
 * For example, "long, straight, blond hair"
 */
string hair( object who ) {
   mapping desc = who->query_env_var("desc");
   if ( !desc || !desc["hair_length"] ) return "bland hair";

   return desc["hair_length"] + ", " + desc["hair_style"] + ", " + desc["hair_color"] + " hair";
}

/** HAIRADJ (who): The adjectives describing a player's hair
 * "long, straight, brown-haired"
 */
string hairadj( object who ) {
   mapping desc = who->query_env_var("desc");
   if ( !desc || !desc["hair_length"] ) return "bland hair";

   return desc["hair_length"] + ", " + desc["hair_style"] + ", " + desc["hair_color"] + "-haired";
}

/** HASFUEL (condition): If the object has any fuel left, then true, else
 * false. Applies only to ignitable objects, everything else will always
 * return false.
 */
string has_fuel( object env ) {
   return env->query_fuel()>1?"":0;
}

/** HASINV (condition): If the object is holding at least one other object, then
 * returns true, else false.
 *
 * The pig ?(HASINV:appears to be carrying something):(is empty-handed).
 */
string has_inv( object env, string scount ) {
   int icount;

   icount = to_int(scount);
   if( icount )
      return sizeof(all_inventory(env)) == icount?"":0;
   if( !first_inventory(env) )
      return 0;
   else
      return "";
}

/** HAS_SIGN(): returns whether or not something has a sign.
 */
string has_sign( object ob ) {
   if( ob->query_sign_desc() ) return "";
      else return 0;
}

/** HEIGHT (who): how tall they are for their species
 */
string height( object who ) {
   // unfinished because I want to define height alongside weight and can'd see query_weight()
   return "of indeterminate height";
}

/** ISCLOTHED (condition): If the object is wearing at least one other object,
 * then returns true, else false.
 *
 * The man ?(ISCLOTHED:~Name ~verbis wearing $(WORN)):(is nekkid!).
 */
int is_clothed( object env, string scount ) {
   return sizeof( filter(all_inventory(env), (: $1->query_worn() :)) ) > 0;
}

/** INV (value): A comma-separated list of all the objects carried by the
 * object; "nothing" if it doesn't have any.
 *
 * The dog is carrying $(INV).
 */
string inv( object env ) {
   string ret;

   ret = inventory_string( all_inventory(env) );
   if( ret == "" )
      return "nothing";
   else
      return ret;
}

/** HASLIQUID (condition): True if env contains a liquid, false if not.
 *
 * A bag?(HASLIQUID: of $(LIQUID))
 */
string has_liquid( object env ) {
   object ob;
   foreach( ob : all_inventory(env) )
      if( ob->query_liquid() ) return "";
   return 0;
}

/** HELD (value): A comma-separated list of all the objects held by the
 * object (i.e. query_held() returns true).
 */
string held( object env ) {
   string ret;

   ret = inventory_string( filter(all_inventory(env), (: $1->query_held() :)) );
   if( ret == "" )
      return "nothing";
   else
      return ret;
}

/** HP: Two modes of operation:
 *
 * HP, by itself, returns a string describing \a env's condition. If \a env
 * is animate, different strings are used than for inanimate objects.
 *
 * If a range (bottom-top) is passed in, then any value falling in that
 * range returns true, otherwise false. If a single number is passed in,
 * an exact match is required.
 *
 * The wolf is $(HP).
 * The tree is ?(HP(0-50):nearly falling down):(?(HP(51-75):damaged):(?(HP(100):unscratched):(lightly scratched)))
 */
string hp( object env, string range ) {
   int cond;
   int animate = env->query_is_living();

   cond = (animate?env->query_max_hp():env->query_max_condition());

   if( cond == 0 )
      cond = 100;
   else
      cond = (animate?env->query_hp():env->query_condition()) * 100 / cond;

   if( cond < -1 )
      cond = -1;
   if( cond > 101 )
      cond = 101;
   if( cond == 0 && (animate?env->query_hp():env->query_condition()) > 0 )
      cond = 1;

   if( !range ) {
      switch( cond ) {
         case -1: return animate?"stone cold dead":"broken beyond hope of repair";
         case 0: return animate?"dead":"broken";
         case 1..20: return animate?"mortally wounded":"smashed and hammered, nearly to the point of breaking";
         case 21..40: return animate?"severely wounded":"badly damaged";
         case 41..60: return animate?"badly wounded":"damaged";
         case 61..80: return animate?"hurt, but still strong":"obviously worn, but serviceable";
         case 81..99: return animate?"lightly scratched":"in good condition";
         case 100: return animate?"completely unhurt":"in perfect condition";
         case 101: return animate?"glowing with life":"perfectly new, almost magically so";
      }
   }
   else {
      int bot, top;
      if( sscanf(range, "%d-%d", bot, top) == 2 ) {
         if( cond >= bot && cond <= top ) return "";
         return 0;
      }
      if( cond == to_int(range) && !query_to_int_fail() )
         return "";
   }
   return 0;
}

/** LIQUID (value): The name of the liquid(s) inside of env.
 * Uses inventory_string to build a list.
 *
 * A bag?(HASLIQUID: of $(LIQUID))
 */
string liquid( object env ) {
   object ob, *oblist;
   foreach( ob : all_inventory(env) )
      if( ob->query_liquid() ) oblist += ({ ob });
   return inventory_string(oblist);
}

/** ISINV (value): If the object has one inventory item, then "is", otherwise
 * "are". Handy for grammar.
 *
 * Inside the box $(ISINV) $(INV).
 *
 * This might become "Inside the box is a bucket." or "Inside the box are two cards."
 */
string is_inv( object env ) {
   if( sizeof(all_inventory(env)) == 1 &&
      // Only one thing
      (first_inventory(env)->query_quantity() <= 1 ||
      // Amorphous objects (water, dough, flour)
      first_inventory(env)->query_name() == first_inventory(env)->query_plural()) )
      return "is";
   else
      return "are";
}

/** ISLIT (condition): True if the object has been ignited (ovens,
 * fireplaces, fires, etc.)
 */
string is_lit( object env ) {
   return env->query_lit()?"":0;
}

/** INVPLURAL (condition): If there is one inventory object, this is false. Otherwise,
 * it's true.
 *
 * You can see the ?(INVPLURAL:souls):(soul) of $(INV).
 */
string inv_plural( object env ) {
   if( sizeof(all_inventory(env)) == 1 )
      return 0;
   else
      return "";
}

/** ISCLOSED: True if the object is closed (query_closed() returns true)
 *
 * The chest is ?(ISCLOSED:closed):(not closed).
 */
string is_closed( object env ) {
   return env->query_closed()?"":0;
}

/** ISNIGHT: True if it's between sunset and sunrise.
 *
 * It is ?(ISNIGHT:night):(day)time.
 */
string is_night( object env ) {
   // this is a bad ugly hack
   // /daemon/time should isntead be determining sunrise/sunset by equinoxes
   return ("/daemon/time"->query_hour() < 6 || "/daemon/time"->query_hour() >= 18)?"":0;
}

/** ISOPEN: True if the object is open (query_closed() returns false)
 *
 * The door is ?(ISOPEN:open):(closed).
 */
string is_open( object env ) {
   return !env->query_closed()?"":0;
}

/** METAL (value): The type of metal an object is made of.
 *  $(METAL)
 *
 */
string metal( object ob ) {
   return "/daemon/material"->get_metal_type( ob->query_aspects() );
}

/** Something like $(HP), but specialized for milkable critters.
 */
string milkhp( object env ) {
   int percent;

   if( env->query_stat("con") <= 0 ) return "bone dry";
   percent = env->query_env_var("milk") * 100 / env->query_stat("con");
   switch(percent) {
      case 0: return "bone dry";
      case 1..30: return "almost empty";
      case 31..60: return "quite milkable";
      case 61..90: return "heavy with milk";
      case 91..100: return "absolutely sloshing full of milk";
   }

   return ""; // because ldmud complains about missing returns
}

/** OWNER (value): The owner of an object, or "Nobody" if
 * the object has no owner.
 *
 * This is $(OWNER)'s widget.
 */
string owner( object ob ) {
   string s;

   s = ob->query_owner();
   if( !stringp(s) ) s = "Nobody";
   else s = capitalize(s);
   return s;
}

/** RECO (condition): True if the player recognizes the object, but false
 * if the player does not.
 *
 * A fertile patch of ?(RECO:basil):(green herbs).
 */
string recognizes( object env, string param ) {
   if( !env ) env = this_player();
   if( !param && env ) param = env->query_name();
   if( !param ) return 0;
   if( query_listener() && query_listener()->query_recognize(param) )
      return "";
   else
      return 0;
}

/** SIGN_DESC(): Returns the sign description.
 */
string sign_desc( object ob ) {
   return ob->query_sign_desc();
}

/** SKIN (who): An adjectival description of a player's skin
 *
 */
string skin( object who ) {
   mapping desc = who->query_env_var("desc");
   if ( !desc || !desc["skin_color"] ) return "bland skin";

   string skin_str;
   if (desc["skin_adj"])
      skin_str = desc["skin_adj"] + " " + desc["skin_color"] + " skin";
   else
      skin_str = desc["skin_color"] + " skin";

   return skin_str;
}

/** Something like $(HP), but specialized for trees.
 */
string treehp( object env ) {
   int percent;

   if( env->query_size() <= 0 ) return "still just a sprout";
   percent = env->query_damage() * 100 / env->query_size();
   switch(percent) {
      case 0: return "intact and undamaged";
      case 1..30: return "lightly scored, with some of the bark chipped away";
      case 31..60: return "chipped and marred from repeated hacking";
      case 61..90: return "deeply indented from chopping";
      case 91..100: return "mostly gone, and ready to tip over at any moment";
   }

   return ""; // because ldmud complains about missing returns
}

/** WEIGHT (who): how heavy they are for their height
 */
string weight( object who ) {
   // unfinished, see height()
   return "of indeterminate weight";
}

/** WORN (value): A comma-separated list of all the objects worn by the
 * object (i.e. query_orn() returns true).
 *
 * The man ?(ISCLOTHED:~Name ~verbis wearing $(WORN)):(is nekkid!).
 */
string worn( object env ) {
   string ret;

   ret = inventory_string( filter(all_inventory(env), (: $1->query_worn() :)) );
   if( ret == "" )
      return "nothing";
   else
      return ret;
}

void create() {
   // Please keep this alphabetized!
   set_global_desc_var( "ADJ", #'adj );
   set_global_desc_var( "CANREAD", #'canread );
   set_global_desc_var( "CANELVEN", #'canread );
   set_global_desc_var( "CAPACITY", #'capacity );
   set_global_desc_var( "EYES", #'eyes );
   set_global_desc_var( "GENDERNOUN", #'gendernoun );
   set_global_desc_var( "HAIR", #'hair );
   set_global_desc_var( "HAIRADJ", #'hair );
   set_global_desc_var( "HASFUEL", #'has_fuel );
   set_global_desc_var( "HASINV", #'has_inv );
   set_global_desc_var( "HASLIQUID", #'has_liquid );
   set_global_desc_var( "HASSIGN", #'has_sign );
   set_global_desc_var( "HEIGHT", #'height );
   set_global_desc_var( "INV", #'inv );
   set_global_desc_var( "INVPLURAL", #'is_inv );
   set_global_desc_var( "ISCLOSED", #'is_closed );
   set_global_desc_var( "ISCLOTHED", #'is_clothed );
   set_global_desc_var( "ISINV", #'is_inv );
   set_global_desc_var( "ISLIT", #'is_lit );
   set_global_desc_var( "ISNIGHT", #'is_night );
   set_global_desc_var( "ISOPEN", #'is_open );
   set_global_desc_var( "HELD", #'held );
   set_global_desc_var( "HP", #'hp );
   set_global_desc_var( "LIQUID", #'liquid );
   set_global_desc_var( "METAL", #'metal );
   set_global_desc_var( "MILKHP", #'milkhp );
   set_global_desc_var( "OWNER", #'owner );
   set_global_desc_var( "RECO", #'recognizes );
   set_global_desc_var( "SIGNDESC", #'sign_desc );
   set_global_desc_var( "SKIN", #'skin );
   set_global_desc_var( "TREEHP" , #'treehp );
   set_global_desc_var( "WEIGHT" , #'weight );
   set_global_desc_var( "WORN", #'worn );
}
