// Last edited by deforce on 02-11-2008
// channel.h -- defines for the channel system
// Created by Deathblade on 01-15-1996

#ifndef __CHANNEL_H__
#define __CHANNEL_H__

#define CHANNEL_TYPE_NORMAL     0
#define CHANNEL_TYPE_IMUD       1


#define CHANNEL_WIZ_ONLY        0x0001
#define CHANNEL_ADMIN_ONLY      0x0002
#define CHANNEL_TEAM_ONLY       0x0010
#define CHANNEL_GUILD_ONLY      0x0020
#define CHANNEL_RACE_ONLY       0x0100
#define CHANNEL_PK_ONLY         0x0200

#define CHANNEL_PERMANENT       0x1000
#define PLAYER_SILENT           0x2000

#endif /* __CHANNEL_H__ */