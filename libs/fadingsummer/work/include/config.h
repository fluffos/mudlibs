// mudlib: Fading Summer
// file:   config.h
// author: Lontau
// date:   20-6-2001

/* Synopsis: This file is included in every object in the mud. */

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "paths.h"
#include "objects.h"
#include "messages.h"
#include "daemons.h"

#define ROOT_UID      "Root"
#define BACKBONE_UID  "Backbone"

/* The following determines what state the mud is in.
   One of: ({ "development","building","testing","playable" })
   Use this in things like LOGON_D to have specific logon
   sequences for various phases of the mud.
*/
#define MUD_PHASE     "development"

#endif
