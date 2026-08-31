These GMCP modules are called from the GMCP_D and are intended to handle
outbound GMCP data. They are not intended to be called directly.

The function GMCP_D::send_gmcp() is used to parse out and make decisions
before passing the information to the appropriate module in this directory.

The file name is the GMCP package name, and the function name is either
the subpackage or the command being sent to the client.

For example, from anywhere in the game, you can:
    GMCP_D->send_gmcp(this_player(), GMCP_PKG_CHAR_STATUSVARS) ;

    From /include/gmcp.h:
    GMCP_PKG_CHAR_STATUSVARS = "Char.StatusVars"

This will call the file Char.c in this directory, and the function
StatusVars() in that file, passing along the player object.

You could build one for Comm.Channel in this way:
    GMCP_D->send_gmcp(this_player(), GMCP_PKG_COMM_CHANNEL_TEXT, ([
        "channel": "gossip",
        "message": "Hello, world!",
        "sender": "Bob",
    ])) ;

    From /include/gmcp.h:
    GMCP_PKG_COMM_CHANNEL_TEXT = "Comm.Channel.Text"

And in Comm.c, have a function:
    void Channel(object player, string command, mapping payload)

This would call the file Comm.c in this directory, and the function Channel()
in that file, passing along the player object and the payload.

The system is build this way in order to facilate the addition of new GMCP
without having to manipulate the GMCP_D directly.

The module is responsible for generating the inormation, or can pass along
a payload from the GMCP_D to the player, and subsequently the client.
