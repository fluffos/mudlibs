///////////////////////////////////////////////////
// Header:  Headerfile fuer Pflanzen
// Silberlandmudlib
// Autoren: Angel@SL / Khory@GL
// File:  <path>+std_plant.h
// Datum: 15.07.2002
///////////////////////////////////////////////////

// INCLUDES
#include <properties.h>
#include "std_soil.h"
#include "oekosystem.h"

// DEFINES Pollination:
#define BY_WIND 1
#define BY_INSECTS 2

// DEFINES Reproduction:
#define BY_SEED 1
#define BY_SPAWN 2

// DEFINES Harvest Type:
#define HARVEST_BLOOM 1
#define HARVEST_FRUIT 2
#define HARVEST_PLANT 3


// PROPERTIES
#define P_PLANT_SPAWNS_FRUIT       "plant_spawns_fruit"       // ([ life_periode : filename, fruit_number/cycle ])
#define P_PLANT_SPAWNS_BLOSSOM     "plant_spawns_blossom"     // ([ life_periode : filename, blossom_number/cycle ])
#define P_PLANT_WITHERS            "plant_withers"            // ({ filename, resets }) / 0 ... plant does NOT wither
#define P_PLANT_IS_PERENNIAL       "plant_is_perennial"       // integer: 0 (dies after one cycle), max_cycles
#define P_PLANT_LIFECYCLE          "plant_lifecycle"          // mapping with details
#define P_PLANT_POLLINATION        "plant_pollination"        // flags: BY_WIND/BY_INSECTS
#define P_PLANT_WAS_POLLINATED     "plant_was_pollinated"     // integer: has the plant been pollinated?
#define P_PLANT_REPRODUCTION       "plant_reproduction"       // flags: BY_SEED/BY_SPAWN
#define P_PLANT_WAS_HARVESTED      "plant_was_harvested"      // integer: What was taken from the plant?
#define P_PLANT_NEEDS_CLIMATE      "plant_needs_climate"      // mapping: ([ FERTILITY, HUMIDITY, TEMPERATURE, TERRAIN_TYPE ])
#define P_PLANT_CLIMATIC_TOLERANCE "plant_climatic_tolerance" // mapping: ([ FERTILITY, HUMIDITY, TEMPERATURE ])
#define P_PLANT_PERSISTENCE        "plant_persistence"        // integer: can the plant hold its ground?
#define P_PLANT_TYPE               "plant_type"               // integer: with the type of the plant
#define P_PLANT_FULLY_GROWN        "plant_fully_grown"        // integer: With which cycle is the plant fully grown?
#define P_PLANT_HARVESTABLE        "plant_harvestable"        // mapping: ([ ID: type ])
#define P_PLANT_CHANGE_MSG         "plant_change_msg"         // string: Message displayed to the room when the life-periode changes

// PROPERTIES (for cloned Plants only):
#define P_PLANT_LIFE_PERIODE       "plant_life_periode"    // integer: Which periode of the plant shall be cloned?
#define P_PLANT_SEASON_COUNT       "plant_season_count"    // integer: Which season is the plant in?
#define P_PLANT_RESET_COUNT        "plant_reset_count"     // integer: How many resets since last periode-change.
#define P_PLANT_IS_GROWING         "plant_is_growing"      // integer: Is the plant still growing?

// PROTOTYPES:
object harvest_plant ( int life_periode, int cycle, int state );
object harvest_fruit ( int life_periode, int cycle, int state );
object harvest_blossoms ( int life_periode, int cycle, int state );
int count_fruit ();
int count_bloom ();
string percent_to_words ( int value );
string fruit_look ();
string bloom_look ();
string long ();
object get_bloom ();
object get_fruit ();
void reset_plant ( int lp );
void manage_details ();
string fruit_detail ( string det );
string bloom_detail ( string det );
mixed get_blind ();