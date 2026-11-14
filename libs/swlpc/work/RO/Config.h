/*
 * Config - get all of the standard files which define
 * locations of objects, system constants, etc.
 */

#ifndef	STD_CONFIG_H
#define	STD_CONFIG_H

#include	"/RO/Consts.h"
#include	"/RO/Servers.h"
#include	"/RO/Objects.h"

#define		PERSIST_SERV	"/P"
#define		PLAYER_SERV	"/P/p"
#define		PLAYER_ONAME(x)	(PLAYER_SERV->GetPlayerObjName(x))

#endif
