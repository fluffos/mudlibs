/*******************************************************************************
 * Unique NPC System header Datei
 * Datei: unique_npc.h
 * Autor: Angel (avs@sbox.tu-graz.ac.at)
 */

#include "./def.h"

#ifndef __UNIQUE_NPC_H__
#define __UNIQUE_NPC_H__

// Defines:
#define P_UNIQUE_NAMES_LIBRARY          LIB_UNIQUE_LIBS "names/std_names"
#define P_UNIQUE_SURNAMES_LIBRARY       LIB_UNIQUE_LIBS "names/std_surnames"
#define P_UNIQUE_EXTRAS_LIBRARY         LIB_UNIQUE_LIBS "extras/std_extras"
#define P_UNIQUE_DETAILS_LIBRARY        LIB_UNIQUE_LIBS "details/std_details"
#define P_CHILD_COST                    10
#define P_MAX_HERITAGE_PROBABILITY      95

// Properties

// Passenspezifisch:
#define P_UNIQUE_RACE_DECLINATIONS      "unique_race_declinations"
#define P_UNIQUE_GENDER_RESTRICTIONS    "unique_gender_restrictions"
#define P_UNIQUE_AVERAGE_SIZE           "unique_average_size"
#define P_UNIQUE_AVERAGE_WEIGHT         "unique_average_weight"
#define P_UNIQUE_RACE_PROBABILITY       "unique_race_probability"
#define P_UNIQUE_SURNAME                "unique_surname"
#define P_UNIQUE_FIRSTNAME              "unique_firstname"

// Global angegebene Namen (fuer spezielle Zwecke):
#define P_UNIQUE_FEMALE_NAMES           "unique_female_names"
#define P_UNIQUE_MALE_NAMES             "unique_male_names"

// Verhalten des NPC:
#define P_UNIQUE_LIKES_PUBS             "unique_likes_taverns"
#define P_UNIQUE_PREFERRED_PUB          "unique_preferred_pub"
#define P_UNIQUE_PREFERRED_FOOD         "unique_preferred_food"
#define P_UNIQUE_PREFERRED_DRINK        "unique_preferred_drink"

// Fuer Debugzwecke:
#define P_UNIQUE_DEBUG_LOG              "unique_debug_log"
#define P_UNIQUE_BANISHING_LIST         "/players/angel/log/unique_banishing_list.log"

#endif // __UNIQUE_NPC_H__

#ifdef NEED_PROTOTYPES_UNIQUE_NPC
#ifndef __UNIQUE_NPC_H_PROTOTYPES__
#define __UNIQUE_NPC_H_PROTOTYPES__

  // Prototypes for the unique NPC:
  void reset_ids();                       // Clears all player-accessible IDs of the object.
  varargs string get_race(int gender);    // Chooses a race from P_RACE_PROBABILITY.
  int get_gender(int prob_male);          // Provides a random gender for the UNPC.
  varargs string get_name(string lib, int no_first_name); // Chooses a name from the Library.
  varargs string get_surname(int policy, string sur_names, string first_names, string parental_name, int parental_gender );
  string get_special_name();              // Chooses a name from P_UNIQUE_MALE/FEMALE_NAME.
  varargs void set_extras(mixed type, int probability, string lib); // Sets descriptions for extras like scars and wounds.
  varargs void set_details(string lib, int distributed);            // Installs all avaliable details into the UNPC.
  string get_race_declination(int casus); // Provides the racestring for the given case.
  int get_between(int min, int max);      // Provides a value between min and max.
  mixed get_familiy_tree();               // Provides the family tree (list of deceased ancestors and family members).
  void greet_player(mixed people);      // Greets a player once in a reset-cycle.
  mixed load_names(string race, int gender, string lib); // Loads the race specific names into the props.
                                                         // UNPC using a race key and a gender the programmer
                                                         // provided.
  mixed load_extras(string type, string lib);    
//  mixed load_details(string type, string race, int gender, string lib);  -> gibt einen missplaced prototype fehler..

  varargs string get_long(string male, string female);   // Provides a compiled long-description using details.
  string distinguish_gender(string male, string female); // Allows a correct gender distinction.

  // Sets everything needed for a default unique NPC
  varargs void create_default_unique_npc( int level, int prob_male, int special_name, string first_names, string sur_names ); 
  varargs void create_unique_family ( int probability, int settlingtime, int level, int prob_male, int special_name, string first_names, string sur_names ) ;
  
  // Yet unimplemented funs:
  int entered_tavern ();
  
#endif
#endif

