///////////////////////////////////////////////////
// Header:  Headerfile fuer Boden
// Silberlandmudlib
// Autoren: Angel@SL / Khory@GL
// File:  <path>+std_soil.h
// Datum: 15.07.2002
///////////////////////////////////////////////////

#include <properties.h>

// Definitions:
#define FERTILITY    "fertility"
#define HUMIDITY     "humidity"
#define TEMPERATURE  "temperature"
#define TERRAIN_TYPE "terrain_type"

#define TREE     0
#define BUSH     1
#define WHEED    2
#define FLOWER   3
#define HERB     4
#define MUSHROOM 5
#define MOSS     6
#define ALGA     7
//                                              T   B   W   F   H  Mu  Mo   A
#define SOIL_DEFAULT_LIMITATIONS ([ TOWN:       1;  1;  2;  1;  0;  0;  0;  0,\
                                    FOREST:     5;  3;  5;  3;  5;  4;  3;  0,\
                                    SWAMP:      2;  3;  5;  3;  5;  1;  5;  0,\
                                    SAND:       1;  5;  5;  5;  5;  5;  4;  0,\
                                    SNOW:       1;  5;  5;  5;  5;  5;  4;  0,\
                                    CAVE:       0;  5;  5;  5;  5;  5;  4;  0,\
                                    GRASSLAND:  2;  5;  5;  5;  5;  5;  4;  0,\
                                    MOUNTAIN:   1;  5;  5;  5;  5;  5;  4;  0,\
                                    ROAD:       1;  5;  5;  5;  5;  5;  4;  0,\
                                    WATER:      0;  0;  0;  0;  0;  0;  0;  5 ]);

// SOIL_DEFAULT_CONDITION: ([ LANDSCAPE: fertility, humidity, 
//                            temperatuer (as long as there is no 
//                            own property for that!) ])
#define SOIL_DEFAULT_CONDITION  ([ TOWN:      15;  20; 20,\
                                   FOREST:    70;  40; 20,\
                                   SWAMP:     60;  80; 25,\
                                   SAND:       5;   0; 40,\
                                   SNOW:       5;  20; -5,\
                                   CAVE:      15;  35; 15,\
                                   GRASSLAND: 30;  20; 30,\
                                   MOUNTAIN:  10;  25; 10,\
                                   ROAD:      25;  25; 20,\
                                   WATER:      0; 100; 20 ]);

// Properties:
#define P_SOIL_FERTILITY    "soil_fertility"
#define P_SOIL_HUMIDITY     "soil_humidity"

// Prototypes:
string plant_info ();
object get_bp ( string path );
varargs int add_plant ( string bp, int lp );