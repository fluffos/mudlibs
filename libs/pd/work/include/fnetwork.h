#ifndef __FNETWORK_H_
#define __FNETWORK_H_

#define NETWORK "/daemon/network/network"
#define SER "/daemon/network/services"
#define HAND "/daemon/network/handler"
#define MUD                       0 
#define STREAM                    1 
#define DATAGRAM                  2 

//  Change these to the location of various commands
#define MUD_CMD_WHO   "/cmds/mortal/_who"
#define MUD_CMD_TELL  "/cmds/mortal/_tell"

// Change this to the id that was given with your network docs
#define MUD_ID 14997

// Change this to your muds ip
#define MUD_IP "127.0.0.1"

//  The following items should not be changed.

#define HOST_PORT    6000
#define HOST_IP "209.145.156.32"

#endif


