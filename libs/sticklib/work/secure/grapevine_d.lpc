/*
** /secure/grapevine_d.c
**
** Author: Tamarindo
**   Date: February 2019
**
** Purpose:
**
**	This daemon could have listened to Grapevine, but it
**	it was not able to to interface with the node-gossiphaus
**	client to send.
*/
#include "/sys/erq.h"

#include <coder_levels.h>

#define MAX_GRAPEVINE_TELL_LENGTH 1000

private int *ticket;

private string *allowed_objects = ({
  // For reboots
  "secure/shut"
  // For special events
  ,"bin/daemons/event_d"
  // For player deaths (mks & pks)
  ,"areas/tristeza/temple/grave_stone"
  // For Guild Raids
  ,"guilds/bards/npcs/entrance_guard"
  ,"guilds/fighters/npcs/entrance_guard"
  ,"guilds/healers/npcs/ggspirit"
  ,"guilds/mages/npcs/registrar"
  ,"guilds/necromancer/npcs/dracolich"
  ,"guilds/ninjas/npcs/gatekeeper"
  ,"guilds/priests/npcs/priest"
  ,"guilds/thieves/npcs/entrance_guard"
});

/*
**   Function: allow_event
**
**    Returns: int
**
** Parameters: object who, the object requesting to send
**
**    Purpose: Restrict access to send events
**
*/
nomask int
allow_event(object who) {
    object prev;
    string tmp, ob_name;
    int x;

    prev = previous_object();

    if (prev) {
	tmp = object_name(prev);

	if (sscanf(tmp, "%s#%d", ob_name, x) != 2) {
	    ob_name = tmp;
	}

	if (member(allowed_objects, ob_name) != -1) {
	    return 1;
	}

	if ((who || (who=this_player())) && who->query_coder_level() >= LVL_SENIOR) {
	    return 1;
	}
    }

    return 0;
}

/*
**   Function: monitor_grapevine
**
**    Returns: void
**
** Parameters:
**
**    Purpose: Monitor the Grapevine process
**
*/
nomask void
monitor_grapevine(mixed *data) {
    if (data && pointerp(data) && sizeof(data)) {
	if (!ticket) {
	    switch(data[0]) {
	    case ERQ_OK:
		ticket = data[1..];

		log_file("GRAPEVINE"
		  , sprintf("%s %s %s Command accepted, ticket: %s\n"
		    , ctime(time())
		    , "monitor_grapevine"
		    , "ERQ_OK"
		    , to_string(ticket)
		  )
		);
		return;
	    case ERQ_E_ARGLENGTH:
		log_file("GRAPEVINE"
		  , sprintf("%s %s %s Too long argument\n"
		    , ctime(time())
		    , "monitor_grapevine"
		    , "ERQ_E_ARGLENGTH"
		  )
		);
		break;
	    case ERQ_E_ARGNUMBER:
		log_file("GRAPEVINE"
		  , sprintf("%s %s %s Too many arguments\n"
		    , ctime(time())
		    , "monitor_grapevine"
		    , "ERQ_E_ARGNUMBER"
		  )
		);
		break;
	    case ERQ_E_PATHLEN:
		log_file("GRAPEVINE"
		  , sprintf("%s %s %s Too many pathname\n"
		    , ctime(time())
		    , "monitor_grapevine"
		    , "ERQ_E_PATHLEN"
		  )
		);
		break;
	    case ERQ_E_ARGFORMAT:
		log_file("GRAPEVINE"
		  , sprintf("%s %s %s Syntax error\n"
		    , ctime(time())
		    , "monitor_grapevine"
		    , "ERQ_E_ARGFORMAT"
		  )
		);
		break;
	    case ERQ_E_ILLEGAL:
		log_file("GRAPEVINE"
		  , sprintf("%s %s %s Illegal pathname\n"
		    , ctime(time())
		    , "monitor_grapevine"
		    , "ERQ_E_ILLEGAL"
		  )
		);
		break;
	    case ERQ_E_FORKFAIL:
		log_file("GRAPEVINE"
		  , sprintf("%s %s %s Fork failed\n"
		    , ctime(time())
		    , "monitor_grapevine"
		    , "ERQ_E_FORKFAIL"
		  )
		);
		break;
	    default:
		log_file("GRAPEVINE"
		  , sprintf("%s %s <UNKNOWN> Unknown error, command rejected\n"
		    , ctime(time())
		    , "monitor_grapevine"
		  )
		);
		break;
	    }

	    return;
	}

	switch(data[0]) {
	case ERQ_STDOUT:
	    data[0] = '\'';
	    log_file("GRAPEVINE"
	      , sprintf("%s %s %s %s\n"
		, ctime(time())
		, "monitor_grapevine"
		, "ERQ_STDOUT"
		, to_string(data)
	      )
	    );
	    return;
	case ERQ_STDERR:
	    data[0] = '\"';
	    log_file("GRAPEVINE"
	      , sprintf("%s %s %s %s\n"
		, ctime(time())
		, "monitor_grapevine"
		, "ERQ_STDERR"
		, to_string(data)
	      )
	    );
	    return;
	case ERQ_EXITED:
	    log_file("GRAPEVINE"
	      , sprintf("%s %s %s Exited with status %d\n"
		, ctime(time())
		, "monitor_grapevine"
		, "ERQ_EXITED"
		, data[1]
	      )
	    );
	      sprintf("Program exited with status %d.\n", data[1]);
	    break;
	case ERQ_SIGNALED:
	    log_file("GRAPEVINE"
	      , sprintf("%s %s %s Caught signal %d\n"
		, ctime(time())
		, "monitor_grapevine"
		, "ERQ_SIGNALED"
		, data[1]
	      )
	    );
	    break;
	case ERQ_E_UNKNOWN:
	    log_file("GRAPEVINE"
	      , sprintf("%s %s %s Unknown error\n"
		, ctime(time())
		, "monitor_grapevine"
		, "ERQ_E_UNKNOWN"
	      )
	    );
	    break;
	}

	ticket = 0;
    }
}

#define GRAPEVINE_PROGRAM "gossiphaus /home/game/ldmud/libexec/node_modules/gossiphaus/kandawen/example.js"

/*
**   Function: spawn_grapevine
**
**    Returns: int
**
** Parameters:
**
**    Purpose: Spawn the Grapevine process
**
*/
nomask int
spawn_grapevine() {
    log_file("GRAPEVINE"
      , sprintf("%s %s %s Connecting to Grapevine via %s\n"
	, ctime(time())
	, "spawn_grapevine"
	, "ERQ_SPAWN"
	, GRAPEVINE_PROGRAM
      )
    );

    return send_erq(ERQ_SPAWN, GRAPEVINE_PROGRAM, #'monitor_grapevine);
}

/*
**   Function: kill_reply
**
**    Returns: int
**
** Parameters:
**
**    Purpose: Receive reply from kill_grapevine
**
*/
nomask void
kill_reply(mixed *data, int signal) {
    switch (data[0]) {
    case ERQ_OK:
	log_file("GRAPEVINE"
	  , sprintf("%s %s Confirmed kill\n"
	    , ctime(time())
	    , "kill_reply"
	  )
	);
	break;
    case ERQ_E_TICKET:
	log_file("GRAPEVINE"
	  , sprintf("%s %s Trying to kill a dead process\n"
	    , ctime(time())
	    , "kill_reply"
	  )
	);
	break;
    case ERQ_E_ILLEGAL:
	log_file("GRAPEVINE"
	  , sprintf("%s %s Illegal signal\n"
	    , ctime(time())
	    , "kill_reply"
	  )
	);
	break;
    default:
	log_file("GRAPEVINE"
	  , sprintf("%s %s Kill error\n"
	    , ctime(time())
	    , "kill_reply"
	  )
	);
	break;
    }
}

/*
**   Function: kill_grapevine
**
**    Returns: int
**
** Parameters: s, string signal to send to kill
**
**    Purpose: Kill the Grapevine process
**
*/
nomask int
kill_grapevine(string s) {
    int signal;

    if (!ticket) {
	log_file("GRAPEVINE"
	  , sprintf("%s %s No program running\n"
	    , ctime(time())
	    , "kill_grapevine"
	  )
	);
	return 1;
    }

    if (!(s && sscanf(s, "%d", signal))) {
	signal = 9;
    }

    send_erq(ERQ_KILL, ticket + ({0, 0, 0, signal}), lambda(({'data}),
	({#'kill_reply, 'data, signal})));

    return 1;
}
