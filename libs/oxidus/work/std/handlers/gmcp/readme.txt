This directory contains the modules that handle incoming GMCP messages sent
from the client.

The modules are named for the base package name and contain functions that
which are named after either the subpackage or the command.

Example:

Char.Status
Char is the package name and therefore the name of the module is Char.c.
The command being issued by the client is Status, and therefore the function
name is Status().

Messages may also come in as Package.Subpackage.Command, in which case the
the function name should be Subpackage(command, mixed data) [where mixed
data is whatever data type you are expecting to receive from the client],
and accommodate for the command and data (if present) in the function.

See the Supports() function in Core.c.

All data being passed will have native values as they will have been decoded
from the incoming JSON.

It is possible to throttle requests from the client by using the cooldown
mechanism. This is done by creating a setup() function and in it, set
the mapping cooldown_limits to a mapping of commands and the time in seconds.

An example is in Core.c where we can respond to Core.Ping requests.

void setup() {
    cooldown_limits = ([
        GMCP_PKG_CORE_PING : 60,
    ]) ;
}

void Ping(int time) {
    object prev = previous_object();

    if(!cooldown_check(GMCP_PKG_CORE_PING, prev))
        return;

    apply_cooldown(GMCP_PKG_CORE_PING, prev) ;

    if(!time)
        return;

    GMCP_D->send_gmcp(prev, GMCP_PKG_CORE_PING) ;
}

You can use whatever labels you want for your commands, but OOB we are using
the names from /include/gmcp.h.
