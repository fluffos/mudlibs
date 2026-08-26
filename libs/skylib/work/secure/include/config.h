/**
 * This file contains all the basic configuration information for the
 * mudlib.  Controls all the bits which need to be setup for someone to get
 * somewhere.
 * @author Pinkfish
 */
#ifndef __SYS__CONFIG
/** @ignore yes */
#define __SYS__CONFIG

/**
 * A nice define for the configuration setting this place as discworld.
 */
#define __DISCWORLD__

#define __DISTRIBUTION_LIB__

/** A define setting the start location. */
#define CONFIG_START_LOCATION "/room/tavern"

/** The start location for newbies. */
#define CONFIG_NEWBIE_START_LOCATION "/room/tavern"

/** The players default race. */
#define CONFIG_DEFAULT_RACE "/std/races/human"

/** The players default guild. */
#define CONFIG_DEFAULT_GUILD "/std/guilds/standard"

/** The user to use to connect to mysql. */
#define CONFIG_DB_USER     "username"

/** The password to use to connect to mysql. */
#define CONFIG_DB_PASS     "password"

/** The clusters database name. */
#define CONFIG_DB_CLUSTERS "clusters"

/** The errors database name. */
#define CONFIG_DB_ERRORS   "errors"

/** The web address to use for the site. */
#define CONFIG_WEB_ADDRESS "http://www.divided-sky.com:7303/"

#endif /* __SYS__CONFIG */
