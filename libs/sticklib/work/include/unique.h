#ifndef _UNIQUE_H
#define	_UNIQUE_H

// Definitions for handling unique and pseudo-unique items.
// V1.0 28-mar-95 by Doomdark.

#include "daemons.h"

#define	UNIQUENESS_FULL		1
#define	UNIQUENESS_PARTIAL	2
#define	UNIQUENESS_NONE		0

#define		IS_UNIQUE(x)	(x->query_uniqueness())

#endif
