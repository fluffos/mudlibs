#ifndef __DISCORD_BOT_H__
#define __DISCORD_BOT_H__

#include <discord.h>
#include <discord_intents.h>
#include <socket.h>
#include <socket_err.h>
#include <origin.h>
#include <daemons.h>

#define DISCORD_ENDPOINT "https://discord.com/api/"

#define DISCORD_MESSAGE_TYPES ([ \
    EVENT_MESSAGE_CREATE : ([ "endpoint" : "channels/%s/messages", "method" : "POST" ]), \
])

#endif // __DISCORD_BOT_H__
