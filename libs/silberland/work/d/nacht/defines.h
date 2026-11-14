/* schlankes defines.h fuer /d/nacht
 * __________________________________________(i) Anatol@Silberland (2012) */

#ifndef _DEFINES_D_NACHT_H_
#define _DEFINES_D_NACHT_H_

#include <properties.h>
#include <moving.h>
#include <wizlevels.h>
#include <language.h>
#include <verben.h>
#include <new_skills.h>
#include <class.h>
#include <combat.h>
#include "sys/gema.h"
#include "sys/kraut.h"

/* strict_types fuer alle! */

#pragma strict_types

/* ---------------------------------------------------------------------- */

#define NACHT	"/d/nacht/"
#define ZODIAC NACHT "region/master/sky"

/* "easy loggin'" ausserhalb von /log */

#ifndef DO_LOG
#define DO_LOG(file, str)	write_file(file,sprintf("%s | %s\n",(dtime(time())[5..]),str))
#endif

// ----------------------------------------------------------------------
// P_NACHT - Property used in player object
/* P_NACHT ("nacht"), vorlaeufig als Bit-Array realisiert */

#define P_NACHT       "nacht"

#define PROPERTY_SET        1  
#define PERSONA_NON_GRATA   2  
#define KNOWLEDGE_SKY       4
#define ALLOWED_TO_XXXXA    8
#define ALLOWED_TO_XXXXB    16
#define ALLOWED_TO_XXXXC    32
#define ALLOWED_TO_XXXXD    64

// ----------------------------------------------------------------------
// P_NACHT_COORDINATES - Property used in rooms, should hold an array 
// containing a triple ({x, z, z}) (integer, -10000 < x,y,z  < 10000).

#define P_NACHT_COORDINATES	"nacht_coordinates"

#ifndef COORD_OFFSET_X          0
#define COORD_OFFSET_X          0
#endif

#ifndef COORD_OFFSET_Y          0
#define COORD_OFFSET_Y          0
#endif

#ifndef COORD_OFFSET_Z          0
#define COORD_OFFSET_Z          0
#endif


/* Diese Makros kann man zum Initialisieren und Setzen der P_NACHT-
 * Property nutzen. Damit geht auch keine Ver'und'ung oder so verloren. */


#define QNACHT(x,y)    (objectp(x)?((int)x->QueryProp(P_NACHT)&y):0)
#define SNACHT(x,y)    (objectp(x)?(x->SetProp(P_NACHT,\
                        ((int)x->QueryProp(P_NACHT))|y)):0)
#define PERSIST_NACHT(x)  (objectp(x)?(x->Set(P_NACHT, SAVE, F_MODE_AS)):0)

/* ---------------------------------------------------------------------- */

/* Standardverzeichnisse der Region fuer
 * std, sys, doc  */

#define NACHT_STD NACHT "std/"
#ifdef STD
#undef STD
#endif
#define STD NACHT_STD

#define NACHT_SYS NACHT "sys/"
#ifdef SYS
#undef SYS
#endif
#define SYS NACHT_SYS

#define NACHT_DOC NACHT "doc/"
#ifdef DOC
#undef DOC
#endif
#define DOC NACHT_DOC

#endif   /* ifndef _DEFINES_H_NACHT_H_ */
