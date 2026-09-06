/*
** /obj/login/gmcp.c
**
**  Author: Tamarindo
**
**    Date: August 2019
**
** Purpose: This file processes the receiving, sending and caching of data
**	for the Generic Mud Communications Protocol (GMCP) to enhance
**	interaction with player clients.
**
**	Messages transferred between the game and the client are in JSON
**	format.  The mapping for the cache management is fairly close to the
**	format, but is optimized to enable the game to quickly parse the cache
**	when needed.
**
** References:
**
**	http://mudflinging.tumblr.com/post/37634529575/gmcp-negotiation-in-ldmud
**	https://www.gammon.com.au/gmcp
**	http://www.aardwolf.com/wiki/index.php/Clients/GMCP
**	http://nexus.ironrealms.com/GMCP
**	https://wiki.mudlet.org/w/Standards:MUD_Client_Media_Protocol
**
** See Also:
**
**	/include/gmcp.h
**	/obj/login/telopt.c
*/

#ifndef OBJ_LOGIN_GMCP_C
#define OBJ_LOGIN_GMCP_C

#ifndef LPC_LPCTYPES_H
#include <sys/lpctypes.h>
#endif // LPC_LPCTYPES_H

#ifndef TELNET_H__
#include <sys/telnet.h>
#endif // TELNET_H__

#ifndef GMCP_H
#include <gmcp.h>
#endif // GMCP_H

nosave mapping gmcp_cache; /* Stores the GMCP we have collected */

// Prototypes
public nomask int does_gmcp();
public nomask mapping query_gmcp_cache();
private void gmcp_input(int *optdata);
public nomask varargs int gmcp_output(string package, mixed value, int refresh);
private varargs mixed gmcp_cache_filter(string package, mixed gmcp_value);
private mixed parse_cache(string package, mixed gmcp, string *keys);

/*
** Function: does_gmcp
**
**  Purpose: Query whether the client supports GMCP.
**
**  Returns: int, 0 for false, 1 for true.
*/
public nomask int
does_gmcp() {
    return gmcp_cache ? 1 : 0;
}

/*
** Function: query_gmcp_cache
**
**  Purpose: This function is for debugging purposes.
**
**  Returns: mapping, all of the GMCP data that should sensibly be cached
**	         so not to continually send it on to the player's client
**               when they should already have the information.
*/
public nomask mapping
query_gmcp_cache() {
    return copy(gmcp_cache);
}

/*
** Function: gmcp_input
**
**  Purpose: The telopt_negotiate function routes inbound GMCP messages from
**           the player's client here for handling.
*/
private void
gmcp_input(int *optdata) {
    string package;
    string value;
    int i, space;

    // Parse the data
    for (i = 0; i < sizeof(optdata); i++) {
	if (!space && optdata[i] == ' ') {
	    space = i;
	} else if (!space) {
	    package = sprintf("%s%c", package ? package : "", optdata[i]);
	} else {
	    value = sprintf("%s%c", value ? value : "", optdata[i]);
	}
    }

    // Validate the GMCP package
    switch (package) {
    // Reply to the client
    case GMCP_PKG_CORE_HELLO:
	gmcp_cache_filter(package, json_parse(value));

	gmcp_output(GMCP_PKG_CLIENT_GUI, ([
	    GMCP_KEY_CLIENT_GUI_VERSION: GMCP_VALUE_CLIENT_GUI_VERSION
	    , GMCP_KEY_CLIENT_GUI_URL: GMCP_VALUE_CLIENT_GUI_URL
	  ]) );

	gmcp_output(GMCP_PKG_CLIENT_MAP, ([
	    GMCP_KEY_CLIENT_MAP_URL: GMCP_VALUE_CLIENT_MAP_URL
	  ]) );

	break;

    case GMCP_PKG_CORE_SUPPORTS_SET:
    case GMCP_PKG_CORE_SUPPORTS_ADD:
	gmcp_cache_filter(package, json_parse(value));

	if (member(gmcp_cache, GMCP_PKG_CORE_SUPPORTS) > 0) {
	    gmcp_output(GMCP_PKG_CLIENT_MEDIA_DEFAULT, ([
		GMCP_KEY_CLIENT_MEDIA_URL: GMCP_VALUE_CLIENT_MEDIA_URL
	      ]) );
	}

	break;

    case GMCP_PKG_CORE_SUPPORTS_REMOVE:
	gmcp_cache_filter(package, json_parse(value));
	break;

    case GMCP_PKG_CORE_KEEPALIVE:
	// Not yet supported
	break;

    case GMCP_PKG_CORE_PING:
	gmcp_cache_filter(package, json_parse(value ? value : "null"));
	gmcp_output(package, "");
	break;
    }
}

/*
**   Function: gmcp_output
**
**    Purpose: The mudlib will send GMCP messages here to route to the
**                 player's client.
**
** Parameters: string package, the GMCP package matching values from
**                 the gmcp.h header file (i.e. Char.Vitals)
**
**             mixed value, a mapping, array, string, number or float
**                 that will be encoded as JSON for the client
**
**             int refresh, an optional parameter to force an update
**                 of the GMCP cache
**
**    Returns: 1 for success, 0 for failure (invalid data)
*/
public nomask varargs int
gmcp_output(string package, mixed value, int refresh) {
    mixed cache_value;

    if (interactive() && package) {
	// validate value
	if (package != GMCP_PKG_CLIENT_GUI) {
	    switch (typeof(value))
	    {
	    case T_MAPPING:
		/* only string keys are valid */
		if (sizeof(filter(value, (:!stringp($1):)))) {
		    return 0;
		}
	    case T_POINTER:
	    case T_STRING:
		// GMCP_PKG_CLIENT_GUI needs sent raw for Mudlet versions < 4.0.4
		if (package == GMCP_PKG_CLIENT_GUI && stringp(value)) {
		    binary_message(({IAC, SB, TELOPT_GMCP}));
		    binary_message(to_bytes(sprintf("%s %s", package, value), "UTF-8"));
		    binary_message(({IAC, SE}));

		    return 1;
		}
	    case T_NUMBER:
	    case T_FLOAT:
		// Only send what has changed
		cache_value = gmcp_cache_filter(package, value);
		break;
		/* Invalid types */
	    case T_OBJECT:
	    case T_CLOSURE:
		return 0;
	    }

	    // Send only if the cache changed
	    if (refresh ? value : cache_value) {
		string json_serialized_value = json_serialize(refresh ? value : cache_value);

		// send the client the value
		binary_message(({IAC, SB, TELOPT_GMCP}));
		binary_message(to_bytes(sprintf("%s %s", package, json_serialized_value), "UTF-8"));
		binary_message(({IAC, SE}));
	    }
	}

	return 1;
    }

    return 0;
}

/*
**   Function: gmcp_cache_filter
**
**    Purpose: A method that controls whether GMCP data will be cached within
**             a nosave mapping (gmcp_cache) within the player object to
**             reduce the amount of duplicate data sent to the player's
**             client.
**
** Parameters: string package, a GMCP package name, such as those found in
**             /include/gmcp.h that start with GMCP_PKG and resolve to
**             examples like "Char.Status" and "Room.Info".
**
**             mixed gmcp_value, a string, array or mapping containing GMCP
**             data.
**
**    Returns: mixed, a string, array or mapping containing GMCP data or 0 if
**             the information in the cache matched with the input data and
**             nothing needs sent back to the player's client.
*/
private varargs mixed
gmcp_cache_filter(string package, mixed gmcp_value) {
    mixed filtered_result;

    if (!gmcp_cache || !mappingp(gmcp_cache)) {
	gmcp_cache = ([ ]);
    }

    if (gmcp_value) {
	switch (package) {

	case GMCP_PKG_CORE_HELLO:
	    if (member(gmcp_cache, package) < 1) {
		gmcp_cache[package] = filtered_result = gmcp_value;
	    } else filtered_result = parse_cache(package, gmcp_value, ({
		    GMCP_KEY_CORE_HELLO_CLIENT
		    , GMCP_KEY_CORE_HELLO_VERSION
		  }));
	    break;

	case GMCP_PKG_CLIENT_GUI:
	case GMCP_PKG_CLIENT_MAP:
	case GMCP_PKG_CLIENT_MEDIA_DEFAULT:
	case GMCP_PKG_CLIENT_MEDIA_LOAD:
	case GMCP_PKG_CLIENT_MEDIA_PLAY:
	case GMCP_PKG_CLIENT_MEDIA_STOP:
	    filtered_result = gmcp_value;
	    break;

	case GMCP_PKG_CORE_SUPPORTS_SET:
	case GMCP_PKG_CORE_SUPPORTS_ADD:
	    foreach (string element : gmcp_value) {
		string pkg, version;

		if (sscanf(element, "%s %s", pkg, version) == 2) {
		    if (member(gmcp_cache, GMCP_PKG_CORE_SUPPORTS) < 1) {
			gmcp_cache[GMCP_PKG_CORE_SUPPORTS] = ([ pkg: version ]);
		    } else { // Per the standard, we overwrite existing values
			gmcp_cache[GMCP_PKG_CORE_SUPPORTS][pkg] = version;
		    }
		}
	    }

	    filtered_result = gmcp_cache[GMCP_PKG_CORE_SUPPORTS];
	    break;
	case GMCP_PKG_CORE_SUPPORTS_REMOVE:
	    // Cache cleanup
	    foreach (string pkg : gmcp_value) {
		if (member(gmcp_cache, GMCP_PKG_CORE_SUPPORTS) > 0) {
		    m_delete(gmcp_cache[GMCP_PKG_CORE_SUPPORTS], pkg);
		}
	    }

	    filtered_result = gmcp_cache[GMCP_PKG_CORE_SUPPORTS];
	    break;

	case GMCP_PKG_EXTERNAL_DISCORD_HELLO:
	    filtered_result = gmcp_value;
	    break;
	case GMCP_PKG_EXTERNAL_DISCORD_INFO:
	    if (member(gmcp_cache, package) < 1) {
		gmcp_cache[package] = filtered_result = gmcp_value;
	    } else filtered_result = parse_cache(package, gmcp_value, ({
		    GMCP_KEY_EXTERNAL_DISCORD_INFO_INVITEURL,
		    GMCP_KEY_EXTERNAL_DISCORD_INFO_APPLICATIONID
		  }));
	    break;
	case GMCP_PKG_EXTERNAL_DISCORD_STATUS:
	    if (member(gmcp_cache, package) < 1) {
		gmcp_cache[package] = filtered_result = gmcp_value;
	    } else filtered_result = parse_cache(package, gmcp_value, ({
		    GMCP_KEY_EXTERNAL_DISCORD_STATUS_GAME,
		    GMCP_KEY_EXTERNAL_DISCORD_STATUS_STARTTIME
		  }));
	    break;
	}
    }

    return filtered_result;
}

/*
**   Function: parse_cache
**
**    Purpose: Accepts data matching up to the GMCP spec (or this game's
**             customizations) and stores it in a nosave mapping within
**             the player object if there is no value in the cache or if
**             the cache needs updated because the data has has changed.
**
** Parameters: string package, one of the GMCP_PKG defines from
**             /include/gmcp.h (i.e. GMCP_PKG_ROOM_INFO is "Room.Info").
**
**	       mixed gmcp, often a string, array or mapping containing
**             various GMCP_KEY keys from /include/gmcp.h and data
**             values (i.e. a mapping related to "Room.Info" like
**             ([ "num": 1, "name": "Temple Yard" ]).
**
**             string *keys, GMCP_KEY keys that relate with a single
**             GMCP_PKG as defined in /include/gmcp.h (i.e. related to
**             "Room.Info" ({ "num", "name", etc }) although these will
**             actually be defines like ({ GMCP_KEY_ROOM_INFO_NUM,
**             GMCP_KEY_ROOM_INFO_NAME, etc. })
**
**    Returns: mixed, if the cache was updated, this will contain the results
**             in the format similar to what was originally sent in to
**             this function that aligns with the GMCP specification.
**             If the cache was not updated then this function will
**             return 0, prompting the function that called this to send
**             no data to the intended recipient, because they should
**             already have it.
**
**       Note: This took a while to get all the processing of the mappings,
**             arrays, strings, numbers and floats cached in a way that
**             was sensible to store and also reasonable to parse through
**             for changes, so more code will be left in this example
**             than may be needed for what is implemented in this mudlib
**             at this time, but you're welcome.
*/
private mixed
parse_cache(string package, mixed gmcp, string *keys) {
    mixed result;
    int updated = 0;

    if (pointerp(gmcp)) {
	foreach (mixed element : gmcp) {
	    if (stringp(element)) {
		if (member(gmcp_cache, package) < 1) {
		    gmcp_cache[package] = ({ element });
		} else {
		    gmcp_cache[package] += element;
		}
	    } else if (mappingp(element)) {
		string id = element[keys[0]];

		if (member(gmcp_cache, package) < 1) {
		    gmcp_cache[package] = ([ ]);
		}

		for (int key = 1; key < sizeof(keys); key++) {
		    if (member(gmcp_cache[package], id) < 1) {
			updated = 1;

			gmcp_cache[package][id] = ([ keys[key]: element[keys[key]] ]);
#if 0 // This is here so the indenter in 'ed' keeps things nice for us
		    {
#endif
		    } else if (member(gmcp_cache[package][id], keys[key]) < 1) {
			updated = 1;

			gmcp_cache[package][id][keys[key]] = element[keys[key]];
		    } else {
			mixed sent = element[keys[key]];
			mixed cached = gmcp_cache[package][id][keys[key]];

			if (sent != cached) {
			    updated = 1;
			}

			gmcp_cache[package][id][keys[key]] = element[keys[key]];
		    }
		}
	    }

	    if (!result || !pointerp(result)) {
		result = ({ element });
	    } else result += ({ element });
	}
    } else if (mappingp(gmcp)) {
	if (package == GMCP_PKG_CHAR_ITEMS) {
	    string location = gmcp[GMCP_KEY_CHAR_ITEMS_LOCATION];
	    int dummy;

	    if (member(({ GMCP_VALUE_CHAR_ITEMS_LOCATION_INV,
		  GMCP_VALUE_CHAR_ITEMS_LOCATION_ROOM }), location) < 0
	      && sscanf(location, GMCP_VALUE_CHAR_ITEMS_LOCATION_CONTAINER, dummy) != 1) {
		return 0; // Shouldn't happen
	    }

	    if (member(gmcp_cache, package) < 1) {
		gmcp_cache[package] = ([ ]);
	    }

	    if (member(gmcp_cache[package], location) < 1) {
		updated = 1;
		gmcp_cache[package][location] = ([ ]);

		// List package uses GMCP_KEY_CHAR_ITEMS_ITEMS, while
		// Add/Update packages use GMCP_KEY_CHAR_ITEMS_ITEM per the spec
		string items_key = member(gmcp, GMCP_KEY_CHAR_ITEMS_ITEMS) > 0
		? GMCP_KEY_CHAR_ITEMS_ITEMS
		: GMCP_KEY_CHAR_ITEMS_ITEM;

		foreach (mapping map : gmcp[items_key]) {
		    string id = map[keys[0]];

		    for (int key = 1; key < sizeof(keys); key++) {
			if (member(gmcp_cache[package][location], id) < 1) {
			    gmcp_cache[package][location][id] = ([ keys[key]: map[keys[key]] ]);
#if 0 // This is here so the indenter in 'ed' keeps things nice for us
			{
#endif
			} else {
			    gmcp_cache[package][location][id][keys[key]] = map[keys[key]];
			}
		    }

		    if (!result || !pointerp(result)) {
			result = ([
			  GMCP_KEY_CHAR_ITEMS_LOCATION: location,
			  items_key: ({ map })
			]);
		    } else result[items_key] += ({ map });
		}
	    } else {
		// List package uses GMCP_KEY_CHAR_ITEMS_ITEMS, while
		// Add/Update packages use GMCP_KEY_CHAR_ITEMS_ITEM per the spec
		string items_key = member(gmcp, GMCP_KEY_CHAR_ITEMS_ITEMS) > 0
		? GMCP_KEY_CHAR_ITEMS_ITEMS
		: GMCP_KEY_CHAR_ITEMS_ITEM;

		foreach (mapping map : gmcp[items_key]) {
		    string id = map[keys[0]];

		    for (int key = 1; key < sizeof(keys); key++) {
			if (member(gmcp_cache[package][location], id) < 1) {
			    gmcp_cache[package][location][id] = ([ keys[key]: map[keys[key]] ]);
#if 0 // This is here so the indenter in 'ed' keeps things nice for us
			{
#endif
			    updated = 1;
			} else if (member(gmcp_cache[package][location][id], keys[key]) < 1) {
			    gmcp_cache[package][location][id][keys[key]] = map[keys[key]];
			    updated = 1;
			} else {
			    mixed sent = map[keys[key]];
			    mixed cached = gmcp_cache[package][location][id][keys[key]];

			    if (sent != cached) {
				gmcp_cache[package][location][id][keys[key]] = map[keys[key]];
				updated = 1;
			    }
			}
		    }

		    if (!result || !pointerp(result)) {
			result = ([
			  GMCP_KEY_CHAR_ITEMS_LOCATION: location,
			  items_key: ({ map })
			]);
		    } else result[items_key] += ({ map });
		}
	    }
	} else if (package == GMCP_PKG_GROUP) {
	    foreach (string key : keys) {
		if (member(gmcp, key) > 0) {
		    if (member(gmcp_cache, package) < 1) {
			gmcp_cache[package] = ([ ]);
		    }

		    if (key == GMCP_KEY_GROUP_MEMBERS && pointerp(gmcp[key])) {
			string *names;

			// Let's first fetch a list of player names in our party from the cache,
			// if they exist, so we could determine if someone had dropped out of the
			// party and we need to update the cache and send to the client.
			if (member(gmcp_cache[package], key) > 0 && sizeof(gmcp_cache[package][key])) {
			    names = m_indices(gmcp_cache[package][key]);
			}

			foreach (mapping player : gmcp[key]) {
			    if (member(player, GMCP_KEY_GROUP_MEMBERS_NAME) > 0) {
				// Remove this player from the balance of the names we were tracking.
				// We'll check if any names are left at the end in our balance and if
				// so we'll trigger an update to the client.
				if (names && sizeof(names) && member(names, player[GMCP_KEY_GROUP_MEMBERS_NAME]) != -1) {
				    names -= ({ player[GMCP_KEY_GROUP_MEMBERS_NAME] });
				}

				// If none of the players in the party exist, add this to the cache!
				if (member(gmcp_cache[package], key) < 1) {
				    updated = 1;

				    gmcp_cache[package][key] = ([
				      player[GMCP_KEY_GROUP_MEMBERS_NAME] : ([
					GMCP_KEY_GROUP_MEMBERS_INFO_HP: player[GMCP_KEY_GROUP_MEMBERS_INFO][GMCP_KEY_GROUP_MEMBERS_INFO_HP],
					GMCP_KEY_GROUP_MEMBERS_INFO_MAXHP: player[GMCP_KEY_GROUP_MEMBERS_INFO][GMCP_KEY_GROUP_MEMBERS_INFO_MAXHP],
					GMCP_KEY_GROUP_MEMBERS_INFO_SP: player[GMCP_KEY_GROUP_MEMBERS_INFO][GMCP_KEY_GROUP_MEMBERS_INFO_SP],
					GMCP_KEY_GROUP_MEMBERS_INFO_MAXSP: player[GMCP_KEY_GROUP_MEMBERS_INFO][GMCP_KEY_GROUP_MEMBERS_INFO_MAXSP],
					GMCP_KEY_GROUP_MEMBERS_INFO_FP: player[GMCP_KEY_GROUP_MEMBERS_INFO][GMCP_KEY_GROUP_MEMBERS_INFO_FP],
					GMCP_KEY_GROUP_MEMBERS_INFO_MAXFP: player[GMCP_KEY_GROUP_MEMBERS_INFO][GMCP_KEY_GROUP_MEMBERS_INFO_MAXFP],
					GMCP_KEY_GROUP_MEMBERS_INFO_LEVEL: player[GMCP_KEY_GROUP_MEMBERS_INFO][GMCP_KEY_GROUP_MEMBERS_INFO_LEVEL],
					GMCP_KEY_GROUP_MEMBERS_INFO_HERE: player[GMCP_KEY_GROUP_MEMBERS_INFO][GMCP_KEY_GROUP_MEMBERS_INFO_HERE],
				      ])
				    ]);
				} else if (member(gmcp_cache[package][key], player[GMCP_KEY_GROUP_MEMBERS_NAME]) < 1) {
				    // If the player does not exist in the cache, add the player!
				    updated = 1;

				    gmcp_cache[package][key][player[GMCP_KEY_GROUP_MEMBERS_NAME]] = ([
				      GMCP_KEY_GROUP_MEMBERS_INFO_HP: player[GMCP_KEY_GROUP_MEMBERS_INFO][GMCP_KEY_GROUP_MEMBERS_INFO_HP],
				      GMCP_KEY_GROUP_MEMBERS_INFO_MAXHP: player[GMCP_KEY_GROUP_MEMBERS_INFO][GMCP_KEY_GROUP_MEMBERS_INFO_MAXHP],
				      GMCP_KEY_GROUP_MEMBERS_INFO_SP: player[GMCP_KEY_GROUP_MEMBERS_INFO][GMCP_KEY_GROUP_MEMBERS_INFO_SP],
				      GMCP_KEY_GROUP_MEMBERS_INFO_MAXSP: player[GMCP_KEY_GROUP_MEMBERS_INFO][GMCP_KEY_GROUP_MEMBERS_INFO_MAXSP],
				      GMCP_KEY_GROUP_MEMBERS_INFO_FP: player[GMCP_KEY_GROUP_MEMBERS_INFO][GMCP_KEY_GROUP_MEMBERS_INFO_FP],
				      GMCP_KEY_GROUP_MEMBERS_INFO_MAXFP: player[GMCP_KEY_GROUP_MEMBERS_INFO][GMCP_KEY_GROUP_MEMBERS_INFO_MAXFP],
				      GMCP_KEY_GROUP_MEMBERS_INFO_LEVEL: player[GMCP_KEY_GROUP_MEMBERS_INFO][GMCP_KEY_GROUP_MEMBERS_INFO_LEVEL],
				      GMCP_KEY_GROUP_MEMBERS_INFO_HERE: player[GMCP_KEY_GROUP_MEMBERS_INFO][GMCP_KEY_GROUP_MEMBERS_INFO_HERE],
				    ]);
				} else {
				    // Let's see if anything changed with this player
				    foreach (string info : ({
					GMCP_KEY_GROUP_MEMBERS_INFO_HP, GMCP_KEY_GROUP_MEMBERS_INFO_MAXHP,
					GMCP_KEY_GROUP_MEMBERS_INFO_SP, GMCP_KEY_GROUP_MEMBERS_INFO_MAXSP,
					GMCP_KEY_GROUP_MEMBERS_INFO_FP, GMCP_KEY_GROUP_MEMBERS_INFO_MAXFP,
					GMCP_KEY_GROUP_MEMBERS_INFO_LEVEL,
					GMCP_KEY_GROUP_MEMBERS_INFO_HERE })) {
					mixed sent = player[GMCP_KEY_GROUP_MEMBERS_INFO][info];
					mixed cached = gmcp_cache[package][key][player[GMCP_KEY_GROUP_MEMBERS_NAME]][info];

					if (sent != cached) {
					    updated = 1;
					    gmcp_cache[package][key][player[GMCP_KEY_GROUP_MEMBERS_NAME]][info] = sent;
					}
				    }
				}
			    }
			}

			if (sizeof(names)) {
			    updated = 1;

			    // Delete names of party members who are no longer in the party from the cache.
			    foreach (string name : names) {
				m_delete(gmcp_cache[package][key], name);
			    }
			}

			// This ends the block of code for the special handling of GMCP_KEY_GROUP_MEMBERS information 
		    } else if (member(gmcp_cache[package], key) < 1) {
			updated = 1;
			gmcp_cache[package][key] = gmcp[key];
		    } else {
			mixed sent = gmcp[key];
			mixed cached = gmcp_cache[package][key];

			if (sent != cached) {
			    updated = 1;
			    gmcp_cache[package][key] = sent;
			}
		    }

		    if (!result && !mappingp(result)) {
			result = ([ key: gmcp[key] ]);
#if 0 // This is here so the indenter in 'ed' keeps things nice for us
		    {
#endif
		    } else result[key] = gmcp[key];
		}
	    }
	} else {
	    foreach (string key : keys) {
		if (member(gmcp, key) > 0) {
		    if (pointerp(gmcp[key]) || mappingp(gmcp[key])) {
			updated = 1;
			gmcp_cache[package][key] = gmcp[key];
		    } else {
			mixed sent = gmcp[key];
			mixed cached = gmcp_cache[package][key];

			if (sent != cached) {
			    updated = 1;
			    gmcp_cache[package][key] = sent;
			}
		    }

		    if (!result && !mappingp(result)) {
			result = ([ key: gmcp[key] ]);
#if 0 // This is here so the indenter in 'ed' keeps things nice for us
		    {
#endif
		    } else result[key] = gmcp[key];
		}
	    }
	}
    }

    return updated ? result : 0;
}

/*
**    Function: gmcp_test
**
**     Purpose: Test GMCP from the MUD Client Sound Protocol  specification found at
**              https://wiki.mudlet.org/w/Standards:MUD_Client_Media_Protocol.
**
**  Parameters: int arg, number of the test.
**
**     Returns: void
*/
public varargs void gmcp_test(int test) {
    switch (test) {
	case 0:
	    // Preload the tornado.
     	    gmcp_output(GMCP_PKG_CLIENT_MEDIA_LOAD, ([
		"name": "weather/tornado.wav"
              ]) );
	    break;
	case 1:
	    // The music of wind continuously plays.
     	    gmcp_output(GMCP_PKG_CLIENT_MEDIA_PLAY, ([
		"name": "weather/wind.wav"
		, GMCP_KEY_CLIENT_MEDIA_TYPE: GMCP_VALUE_CLIENT_MEDIA_TYPE_MUSIC
		, GMCP_KEY_CLIENT_MEDIA_VOLUME: GMCP_VALUE_CLIENT_MEDIA_VOLUME_LOW
		, GMCP_KEY_CLIENT_MEDIA_LOOPS: GMCP_VALUE_CLIENT_MEDIA_LOOPS_REPEAT
		, GMCP_KEY_CLIENT_MEDIA_TAG: "weather"
              ]) );
	    break;
	case 2:
	    // A lightning strike at low volume must be far off.
     	    gmcp_output(GMCP_PKG_CLIENT_MEDIA_PLAY, ([
		"name": "weather/lightning.wav"
		, GMCP_KEY_CLIENT_MEDIA_TYPE: GMCP_VALUE_CLIENT_MEDIA_TYPE_SOUND
		, GMCP_KEY_CLIENT_MEDIA_VOLUME: GMCP_VALUE_CLIENT_MEDIA_VOLUME_LOW
		, GMCP_KEY_CLIENT_MEDIA_LOOPS: GMCP_VALUE_CLIENT_MEDIA_LOOPS_DEFAULT
		, GMCP_KEY_CLIENT_MEDIA_TAG: "weather"
              ]) );
	    break;
	case 3:
	    // A tornado is spinning somewhere in the distance.
     	    gmcp_output(GMCP_PKG_CLIENT_MEDIA_PLAY, ([
		"name": "weather/tornado.wav"
		, GMCP_KEY_CLIENT_MEDIA_TYPE: GMCP_VALUE_CLIENT_MEDIA_TYPE_SOUND
		, GMCP_KEY_CLIENT_MEDIA_VOLUME: GMCP_VALUE_CLIENT_MEDIA_VOLUME_DEFAULT
		, GMCP_KEY_CLIENT_MEDIA_LOOPS: GMCP_VALUE_CLIENT_MEDIA_LOOPS_DEFAULT
		, GMCP_KEY_CLIENT_MEDIA_TAG: "weather"
              ]) );
	    break;
	case 4:
	    // Two back-to-back lightning strikes at high volume!
     	    gmcp_output(GMCP_PKG_CLIENT_MEDIA_PLAY, ([
		"name": "weather/lightning.wav"
		, GMCP_KEY_CLIENT_MEDIA_TYPE: GMCP_VALUE_CLIENT_MEDIA_TYPE_SOUND
		, GMCP_KEY_CLIENT_MEDIA_VOLUME: GMCP_VALUE_CLIENT_MEDIA_VOLUME_MAX
		, GMCP_KEY_CLIENT_MEDIA_LOOPS: 2
		, GMCP_KEY_CLIENT_MEDIA_TAG: "weather"
              ]) );
	    break;
	case 5:
	    // High volume tornado!
     	    gmcp_output(GMCP_PKG_CLIENT_MEDIA_PLAY, ([
		"name": "weather/tornado.wav"
		, GMCP_KEY_CLIENT_MEDIA_TYPE: GMCP_VALUE_CLIENT_MEDIA_TYPE_SOUND
		, GMCP_KEY_CLIENT_MEDIA_VOLUME: GMCP_VALUE_CLIENT_MEDIA_VOLUME_HIGH
		, GMCP_KEY_CLIENT_MEDIA_LOOPS: GMCP_VALUE_CLIENT_MEDIA_LOOPS_DEFAULT
		, GMCP_KEY_CLIENT_MEDIA_TAG: "weather"
              ]) );
	    break;
	case 6:
	    // Very loud lightning!
     	    gmcp_output(GMCP_PKG_CLIENT_MEDIA_PLAY, ([
		"name": "weather/lightning.wav"
		, GMCP_KEY_CLIENT_MEDIA_TYPE: GMCP_VALUE_CLIENT_MEDIA_TYPE_SOUND
		, GMCP_KEY_CLIENT_MEDIA_VOLUME: GMCP_VALUE_CLIENT_MEDIA_VOLUME_HIGH
		, GMCP_KEY_CLIENT_MEDIA_LOOPS: GMCP_VALUE_CLIENT_MEDIA_LOOPS_DEFAULT
		, GMCP_KEY_CLIENT_MEDIA_TAG: "weather"
              ]) );
	    break;
	case 7:
	    // This stops the repeating wind sound
     	    gmcp_output(GMCP_PKG_CLIENT_MEDIA_STOP, ([
              ]) );
	    break;
    }
}
#endif // OBJ_LOGIN_GMCP_C
