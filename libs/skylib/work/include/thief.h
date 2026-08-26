/**
 * This is the main include for all thief type things.
 * @author Sandoz
 */

/** This defines the time in which the "stolen" property will wear out. */
#define THEFT_PROP_TIMEOUT  (60*60*24) // 1 day.

/** This defines the skill requirements for different covert commands. */
#define SKILL_REQS ([ \
        "hide"     : ([ "covert.hiding.person" : 15 ]), \
        "sneak"    : ([ "covert.stealth" : 15 ]), \
        "slip"     : ([ "covert.manipulation.sleight-of-hand" : 20 ]), \
        "plant"    : ([ "covert.manipulation.sleight-of-hand" : 30 ]), \
        "palm"     : ([ "covert.manipulation.sleight-of-hand" : 15 ]), \
        "steal"    : ([ "covert.manipulation.stealing" : 25 ]), \
        "shoplift" : ([ "covert.manipulation.sleight-of-hand" : 25 ]), \
        "peek"     : ([ "covert.stealth" : 10 ]), \
        "lpick"    : ([ "covert.lockpick.doors" : 50, \
                        "covert.casing.place"   : 30 ]), \
        ])

#define LPICK_COST 50
