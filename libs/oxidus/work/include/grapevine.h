#ifndef __GRAPEVINE_H__
#define __GRAPEVINE_H__

#include <socket.h>
#include <socket_err.h>
#include <origin.h>
#include <daemons.h>
#include <websocket.h>

// Grapevine statuses
#define GR_STATUS_OK "success"
#define GR_STATUS_FAIL "failure"
#define GR_STATUS_ERROR "error"

// Grapevine events
#define GR_EVENT_AUTHENTICATE "authenticate"
#define GR_EVENT_HEARTBEAT "heartbeat"
#define GR_EVENT_RESTART "restart"

// Composite events
#define GR_EVENT_CHANNELS               "channels"
#define GR_EVENT_CHANNELS_SUBSCRIBE     GR_EVENT_CHANNELS "/subscribe"
#define GR_EVENT_CHANNELS_UNSUBSCRIBE   GR_EVENT_CHANNELS "/unsubscribe"
#define GR_EVENT_CHANNELS_BROADCAST     GR_EVENT_CHANNELS "/broadcast"
#define GR_EVENT_CHANNELS_SEND          GR_EVENT_CHANNELS "/send"

#define GR_EVENT_PLAYERS                "players"
#define GR_EVENT_PLAYERS_SIGN_IN        GR_EVENT_PLAYERS "/sign-in"
#define GR_EVENT_PLAYERS_SIGN_OUT       GR_EVENT_PLAYERS "/sign-out"
#define GR_EVENT_PLAYERS_STATUS         GR_EVENT_PLAYERS "/status"

#define GR_EVENT_TELLS                  "tells"
#define GR_EVENT_TELLS_SEND             GR_EVENT_TELLS "/send"
#define GR_EVENT_TELLS_RECEIVE          GR_EVENT_TELLS "/receive"

#define GR_EVENT_GAMES                  "games"
#define GR_EVENT_GAMES_CONNECT           GR_EVENT_GAMES "/connect"
#define GR_EVENT_GAMES_DISCONNECT        GR_EVENT_GAMES "/disconnect"
#define GR_EVENT_GAMES_STATUS            GR_EVENT_GAMES "/status"

#define GR_EVENT_ACHIEVEMENTS           "achievements"
#define GR_EVENT_ACHIEVEMENTS_SYNC      GR_EVENT_ACHIEVEMENTS "/sync"
#define GR_EVENT_ACHIEVEMENTS_CREATE    GR_EVENT_ACHIEVEMENTS "/create"
#define GR_EVENT_ACHIEVEMENTS_UPDATE    GR_EVENT_ACHIEVEMENTS "/update"
#define GR_EVENT_ACHIEVEMENTS_DELETE    GR_EVENT_ACHIEVEMENTS "/delete"

// Socket error codes
#define GR_AUTH_ERROR       4000
#define GR_HEARTBEAT_ERROR  4001

#endif // __GRAPEVINE_H__
