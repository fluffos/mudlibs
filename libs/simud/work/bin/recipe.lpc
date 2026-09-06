/*
 * Coded by : Zarylse
 * Date     : 2003-09-07
 * Notes    : Autogenerates a recipe help file.
 *
 * Update   : 2004-08-01 (Allaryin)
 *            The thing now lists skill difficulties as well
 * Update   : 2005-01-09 (Allaryin)
 *            The command now displays a player's list of known recipes if no
 *            argument is given on the command line
 *              If an argument is given, the help file displays whether or not
 *            the player actually knows the recipe
 *              Difficulty listings are simplified to between 1 and 4 stars
 * Update   : 2005-10-04 (Allaryin)
 *            Recipes now actually know the name of the file they came from,
 *            this allows for the category to be listed at the top of the
 *            generated help file - and for the listing of known recipes to
 *            be sorted by type.
 * Upate    : 2005-10-08 (Allaryin)
 *            Recipes that produce a liquid will now also require that an
 *            appropriate target container of sufficient volume is specified
 *            in the crafting. Listings now inform the crafter of this
 *            requirement.
 *              Items that specify "aspect" requirements for their mutable
 *            ingredients will have this requirement displayed and enforced.
 */

#include <const.h>
#include <textdraw.h>

string difficulty_string( int diff ) {
   string buf = "*";
   int x;
   for (x = 0; x < diff / 25; x++)
      buf += "*";
   buf = " ~CBRT" + pad( buf, 5, JUST_RIGHT) + "~CHLP";
   return buf;
}

string difficulty_got( int diff, int skill ) {
   int dc = (int)(skill - (floor(diff / 25) * 25));
   if( skill == 0 )
      return "~CDRKunknown~CDEF";
   if( dc < 0 )
      return "~CWRNno~CDEF";
   if( dc < 25 )
      return "~CTITyes~CDEF";
   return "~CACTeasy~CDEF";
}

int main( string str ) {
   mapping recipe, aspects;
   int qty, asp, asps, i;
   string ingred, buf, skill;
   object ob;

   if ( !str ) {
      string *recipes = sort_array(this_player()->query_known_recipes(), #'>);
      if( sizeof(recipes) ) {
         mapping cats = ([]);
         string cat;
         for(i = 0; i < sizeof(recipes); i++ ) {
            int err = catch(cat = RECIPE_DAEMON->query_recipe_category(recipes[i]));
            if( err )
               cat = "zzz_testing_zzz";
            if( !pointerp(cats[cat]) )
               cats[cat] = ({});
            cats[cat] += ({ recipes[i] });
         }
         buf = "~CBRTYou know the following recipes:";
         foreach( cat : sort_array(m_indices(cats), #'>) ) {
            buf += "\n~CTIT"+capitalize(cat)+"~CDEF: ";
            for(i = 0; i < sizeof(cats[cat]); i++ )
               buf += (i?", ":"") + cats[cat][i];
         }
         msg(buf);
      } else {
         msg("You do not know any recipes.");
      }
      return 1;
   }

   recipe = RECIPE_DAEMON->query_recipe(str);

   if ( !recipe )
      return notify_fail( "There is no recipe by that name.\n" );

   buf = "RECIPE HELP\n" + upper_case(str) +
         " (" + upper_case(recipe["category"]) + ") - ";

   // decide if the player knows the recipe
   if ( this_player()->query_recipe(str) )
      buf += "KNOWN\n";
   else
      buf += "~CWRNUNKNOWN\n~CHLP";

   // include comments
   if (recipe["comment"])
      buf += "~CDEF"+recipe["comment"]+"\n\n~CHLP";

   if( recipe["output"] )
      catch( ob = funcall(recipe["output"]) );
   if( !ob )
      ob = clone_object("/obj/trinket");

   buf += "In order to create " + ob->query_distant() +
         ", you will need the following:\n ~CLABAmount  Ingredient~CHLP\n";


   for ( i = 0; i < sizeof(recipe["ingredients"]); i++ ) {
      asps = 0;  // reset for each ingredient
      aspects = recipe["ingredients"][i][0];
      qty = recipe["ingredients"][i][1];

      buf += pad( qty, 7, JUST_RIGHT ) + "  ";

	  /// MINERALS
      if ( member(aspects, C_CRYSTAL) ) {
         if ( member(aspects, C_FIRE_MANA) )
            buf += "fire spell crystal (fully charged)\n";
         else if ( member(aspects, C_SPIRIT_MANA) )
            buf += "spirit spell crystal (fully charged)\n";
		 else if ( member(aspects, C_ICE_MANA) )
            buf += "ice spell crystal (fully charged)\n";
		 else if ( member(aspects, C_CHAOS_MANA) )
            buf += "chaos spell crystal (fully charged)\n";
		 else if ( member(aspects, C_EARTH_MANA) )
            buf += "earth spell crystal (fully charged)\n";
		 else if ( member(aspects, C_WATER_MANA) )
            buf += "water spell crystal (fully charged)\n";
		 else if ( member(aspects, C_ORDER_MANA) )
            buf += "order spell crystal (fully charged)\n";
		 else if ( member(aspects, C_LIGHTNING_MANA) )
            buf += "lightning spell crystal (fully charged)\n";
		 else if ( member(aspects, C_WIND_MANA) )
            buf += "wind spell crystal (fully charged)\n";
		 else if ( member(aspects, C_DARK_MANA) )
            buf += "dark spell crystal (fully charged)\n";
         else
            buf += "~CWRN??? ~CHLPspell crystal (fully charged)\n";
	  } else if ( member(aspects, C_RAW) && member(aspects, C_COAL) )
         buf += "coal\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_STONE) )
         buf += "stone" + (qty > 1 ? "s" : "") + "\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_METAL) )
         buf += "metal\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_IRON) )
         buf += "iron\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_LEAD) )
         buf += "lead\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_IRONORE) )
         buf += "iron ore\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_COPPERORE) )
         buf += "copper ore\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_NICKELORE) )
         buf += "nickel ore\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_SILVERORE) )
         buf += "silver ore\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_GOLDORE) )
         buf += "gold ore\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_LEADORE) )
         buf += "lead ore\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_PLATINUMORE) )
         buf += "platinum ore\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_ALUMINUMORE) )
         buf += "aluminum ore\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_ORICHALCUMORE) )
         buf += "orichalcum ore\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_ADAMANTORE) )
         buf += "adamant ore\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_TINORE) )
         buf += "tin ore\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_GOLD) )
         buf += "gold\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_WHITE_GOLD) )
         buf += "white gold\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_SILVER) )
         buf += "silver\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_COPPER) )
         buf += "copper\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_NICKEL) )
         buf += "nickel\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_TIN) )
         buf += "tin\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_PLATINUM) )
         buf += "platinum\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_BRASS) )
         buf += "brass\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_ZINCORE) )
         buf += "zinc ore\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_ZINC) )
         buf += "zinc\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_STEEL) )
         buf += "steel\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_FLINT) )
         buf += "flint\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_SALT) && !member(aspects, C_WATER) )
         buf += "unrefined salt brick\n";
	
	  /// COOKING
	  else if ( member(aspects, C_RAW) && member(aspects, C_WATER) && member(aspects, C_SALT) )
         buf += "ml of sea water\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_WATER) && member(aspects, C_LIQUID) )
         buf += "ml of water\n";
	  else if ( member(aspects, C_FOOD) && member(aspects, C_SUGAR) )
         buf += "ml of sugar\n";
	  else if ( member(aspects, C_FOOD) && member(aspects, C_SALT) )
         buf += "ml of salt\n";
      else if ( member(aspects, C_CROP) && member(aspects, C_CARROT) )
         buf += "carrot\n";
      else if ( member(aspects, C_CROP) && member(aspects, C_ONION) )
         buf += "onion\n";
      else if ( member(aspects, C_CROP) && member(aspects, C_LETTUCE) )
         buf += "lettuce\n";
      else if ( member(aspects, C_CROP) && member(aspects, C_TOMATO) )
         buf += "tomato\n";
      else if ( member(aspects, C_CROP) && member(aspects, C_POTATO) )
         buf += "potato\n";
      else if ( member(aspects, C_CROP) && member(aspects, C_PUMPKIN) )
         buf += "pumpkin\n";
	  else if ( member(aspects, C_CROP) && member(aspects, C_SUGAR_BEET) )
         buf += "sugar beet\n";
	  else if ( member(aspects, C_SEED) && member(aspects, C_LEMON) )
         buf += "lemon\n";
	  else if ( member(aspects, C_SEED) && member(aspects, C_FRUIT) && member(aspects, C_RAW) )
         buf += "piece"+(qty>1?"s":"")+" of fruit\n";
	  else if ( member(aspects, C_CROP) && member(aspects, C_VEGETABLE) )
         buf += "vegetable"+(qty>1?"s":"")+"\n";
	  else if ( member(aspects, C_RAW) && member(aspects, C_MEAT) )
         buf += "piece"+(qty>1?"s":"")+" of meat\n";
	  else if ( member(aspects, C_CROP) && member(aspects, C_GRAIN) )
         buf += "bundle of grain (or ear of corn)\n";
	  else if ( member(aspects, C_GRAIN) && member(aspects, C_SEED) )
         buf += "ml of processed grain\n";
      else if ( member(aspects, C_SEED) )
         buf += "seed" + (qty > 1 ? "s" : "") + "\n";

	  /// CARPENTRY
      else if ( member(aspects, C_RAW) && member(aspects, C_WOOD) && member(aspects, C_APPLEWOOD) )
         buf += "apple wood plank" + (qty > 1 ? "s" : "") + "\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_WOOD) && member(aspects, C_CHERRYWOOD) )
         buf += "cherry wood plank" + (qty > 1 ? "s" : "") + "\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_WOOD) && member(aspects, C_LEMONWOOD) )
         buf += "lemon wood plank" + (qty > 1 ? "s" : "") + "\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_WOOD) && member(aspects, C_ORANGEWOOD) )
         buf += "orange wood plank" + (qty > 1 ? "s" : "") + "\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_WOOD) && member(aspects, C_PLUMWOOD) )
         buf += "plum wood plank" + (qty > 1 ? "s" : "") + "\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_WOOD) && member(aspects, C_BANANAWOOD) )
         buf += "banana wood plank" + (qty > 1 ? "s" : "") + "\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_WOOD) && member(aspects, C_COCONUTWOOD) )
         buf += "coconut wood plank" + (qty > 1 ? "s" : "") + "\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_WOOD) && member(aspects, C_OLIVEWOOD) )
         buf += "olive wood plank" + (qty > 1 ? "s" : "") + "\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_WOOD) && member(aspects, C_PINEWOOD) )
         buf += "pine wood plank" + (qty > 1 ? "s" : "") + "\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_WOOD) )
         buf += "wood plank" + (qty > 1 ? "s" : "") + "\n";
	
	  /// PAPER
      else if ( member(aspects, C_RAW) && member(aspects, C_PAPER) )
         buf += "sheet" + (qty > 1 ? "s" : "") + " of paper\n";

	  /// CLOTH
	  else if( member(aspects, C_RAW) && member(aspects, C_CLOTH) )
         buf += "yard" + (qty>1?"s":"") + " of cloth\n";

	  /// LEATHERWORKING
      else if ( member(aspects, C_RAW) && member(aspects, C_DRAGONSCALE) )
         buf += "dragon scale\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_PELT) && member(aspects, C_THIN) )
         buf += "square" + (qty > 1 ? "s" : "") + " of thin hide\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_PELT) && member(aspects, C_THICK) )
         buf += "square" + (qty > 1 ? "s" : "") + " of thick hide\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_LEATHER) && member(aspects, C_THIN) && member(aspects, C_SOFT) )
         buf += "square" + (qty > 1 ? "s" : "") + " of thin soft leather\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_LEATHER) && member(aspects, C_THICK) && member(aspects, C_SOFT) )
         buf += "square" + (qty > 1 ? "s" : "") + " of thick soft leather\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_LEATHER) && member(aspects, C_THIN) && member(aspects, C_RIGID) )
         buf += "square" + (qty > 1 ? "s" : "") + " of thin rigid leather\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_LEATHER) && member(aspects, C_THICK) && member(aspects, C_RIGID) )
         buf += "square" + (qty > 1 ? "s" : "") + " of thick rigid leather\n";
      else if ( member(aspects, C_RAW) && member(aspects, C_LEATHER) )
         buf += "square" + (qty > 1 ? "s" : "") + " of any type of leather\n";
      		
	  /// BONECARVING
      else if ( member(aspects, C_CARAPACE) ) {
	     if( member( aspects, C_SMALL ) )
		    buf += "small carapace"+(qty>1?"s":"")+"\n";
	     else if( member( aspects, C_MEDIUM ) )
		    buf += "medium carapace"+(qty>1?"s":"")+"\n";
	     else if( member( aspects, C_LARGE ) )
		    buf += "large carapace"+(qty>1?"s":"")+"\n";
         else
		    buf += "carapace"+(qty>1?"s":"")+" of any size\n";
	  }
	
	  /// SMITHING SUBMATERIALS
      else if ( member(aspects, C_BUCKLE) )
         buf += "metal buckle(s)\n";
      else if ( member(aspects, C_GEAR) )
         buf += "metal gear(s)\n";
      else if ( member(aspects, C_RING) )
         buf += "metal ring(s)\n";
      else if ( member(aspects, C_ROD) )
         buf += "metal rod(s)\n";
      else if ( member(aspects, C_SCREW) )
         buf += "metal screw(s)\n";
      else if ( member(aspects, C_SHEET) )
         buf += "metal sheet(s)\n";
      else if ( member(aspects, C_STUD) )
         buf += "metal stud(s)\n";
      else if ( member(aspects, C_SPIKE) )
         buf += "metal spike(s)\n";
      else if ( member(aspects, C_TUBE) )
         buf += "metal tube(s)\n";
      else if ( member(aspects, C_WIRE) )
         buf += "metal wire(s)\n";
      /// UNKNOWN
      else
         buf += "~CWRNunknown ingredient~CHLP\n";
   }

   /**
	* Tools are not yet required, no reason to scare people.
	*
   if( recipe["tools"] ) {
      buf += "\n~CLABTools~CHLP   ";
      for( i = 0; i < sizeof(recipe["tools"]); i++ ) {
         if( i )
            buf += ", ";
         switch( recipe["tools"][i] ) {
            case C_SCISSORS: buf += "scissors"; break;
            case C_NEEDLE: buf += "needle"; break;
            case C_HAMMER: buf += "hammer"; break;
            case C_ANVIL: buf += "anvil"; break;
            case C_FORGE: buf += "forge"; break;
            case C_PICK: buf += "pick"; break;
            case C_PLOW: buf += "plow"; break;
            case C_SAW: buf += "saw"; break;
            case C_AXE: buf += "axe"; break;
            case C_KNIFE: buf += "knife"; break;
            case C_VAT: buf += "brewing vat"; break;
            default: buf += "~CWRNunknown tool~CHLP";
         }
      }
      buf += "\n";
   }
   */

   if( sizeof( recipe["skills"] ) ) {
      buf += "\n~CHLPYou will also need the following skills:\n";
      int padlen = 10;
      foreach (skill : recipe["skills"])
         padlen = max(padlen, strlen(skill));
      buf += "  ~CLABLevel  "+pad("Skill",padlen,JUST_LEFT)+"  Known?~CHLP\n";
      foreach (skill : recipe["skills"]) {
         if (mappingp(recipe["skills"]))
            i = recipe["skills"][skill];
         else
            i = 0;
         buf += " " + difficulty_string(i)+"  "+pad(skill,padlen,JUST_LEFT)+"  "
+difficulty_got(i,this_player()->query_skill(skill))+"\n";
      }
   } else {
      buf += "\n~CHLPThis recipe is simple enough that it does not require any particular skills to learn.\n";
   }

   if( recipe["liquid"] ) {
      buf += "\n~CHLPThis recipe produces ~CLAB"+recipe["liquid"]+" ml~CHLP of "+(ob->query_solid()?"'solid' ":"")+"liquid.";
   }
   if( recipe["aspect"] )
      buf += "\n~CHLPValid aspects for this recipe are ~CLAB"+
			 comma_list("/daemon/material"->query_aspect_array(recipe["aspect"]))+
			 "~CHLP.";
   if( recipe["pure"] )
      buf += "\n~CHLPAspects may ~CLABnot~CHLP be mixed.";

   // ob was needed for query_distant, but the clone itself shouldn't exist
   // update - we also need it for solidity testing, so moved dest down here
   destruct( ob );

   buf += "~CLAB\n\nSee also: ~CREFcraft~CHLP, ~CREFbuild~CHLP";
   help_frame( buf );
   return 1;
}
