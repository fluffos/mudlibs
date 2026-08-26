/**
 * Defines for the general crime system.
 * Started by Sandoz, 09th August 2001
 */

/**
 * This is an array of all the places this handler keeps track of.
 * This is to prevent people from adding criminals to places
 * which don't exist and making numerous useless save files.
 */
#define ALL_PLACES ({ "calarien" })

/**
 * This is the modifier used in calculating sentence lengths.
 */
#define SENTENCE_LENGTH_MOD 100

/**
 * These are the main crime type defines.
 */
#define VANDALISM  1 // vandalism
#define THEFT      2 // stealing
#define SHOPLIFT   3 // shoplifting
#define RESIST     4 // resisting the law
#define SLAUGHTER  5 // killing innocents
#define GUARDKILL  6 // killing the upholders of law
#define KIDNAP     7 // kidnapping
#define NUISANCE   8 // Public Nuisance, such as throwing crowsbeak into jail

/**
 * This is a mapping of crime types, their severity and descriptions.
 * format - ([ type : ({ severity, string }) ])
 */
#define CRIME_MAP ([ \
    VANDALISM  : ({ 1, "destroying others' property $times$" }), \
    THEFT      : ({ 2, "stealing $times$" }), \
    SHOPLIFT   : ({ 2, "shoplifting $times$" }), \
    RESIST     : ({ 3, "resisting the law $times$" }), \
    SLAUGHTER  : ({ 4, "attacking or slaughtering $number$ innocent$s" }), \
    GUARDKILL  : ({ 5, "killing $number$ upholder$s of the law" }), \
    KIDNAP     : ({ 3, "kidnapping $number$ citizen$s" }), \
    NUISANCE   : ({ 1, "public nuisance, on $times$ count$s" }), \
    ])

/**
 * This is the sorted crime types array.
 */
#define CRIME_TYPES sort_array( keys(CRIME_MAP), 1 )
