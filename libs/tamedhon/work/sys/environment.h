// SilberLand MUDlib
//
// sys/environment.h -- environment header
//
// $Date: 1997/05/13 10:25:12 $
/* $Revision: 1.2 $
 * $Log: environment.h,v $
 * Revision 1.2  1997/05/13 10:25:12  Crea
 * added terrain types and ENV_TERRAIN
 *
 * Revision 1.1  1997/03/31 12:49:44  Woody
 * prepared for revision control
 *
// 22.12.1995	20:55	Mupfel
// 29.01.1996	14:40	Mupfel	Temperature Defines
// 19.02.1996	18:55	Mupfel	Protection Defines nach armour.h verlegt
// 19.02.1996	20:20	Mupfel	Temperature Define nach living/life.h
//
 */
 
#ifndef __ENVIRONMENT_H__
#define __ENVIRONMENT_H__

// properties

#define P_ENVIRONMENT	"environment"

// special defines

#define	ENV_FLAGS	"env_flags"
// diverse Flags, s.u.
#define	ENV_TEMPERATURE	"env_temp"
// Umgebungstemperatur
#define ENV_WATER	"env_water"
// Wassertiefe, falls Env. Wasser ist
#define	ENV_USER	"env_user"
// benutzerdefinierte Infos
#define ENV_TERRAIN "env_terrain"
// gedacht als Landschaftstyp, siehe Landschaftstypen

// environment flags

#define	EF_INDOORS	0x01
// Wird bei SetProp(P_INDOORS) gesetzt

// #define EF_UNDERWATER	0x02
// Unterwasser
// removed -> TT_UNDERWATER (woody)

// weitere Flags??

// Landscape types

#define TT_OTHER        0
#define TT_CAVE         1       // indoor-types
#define TT_HOUSE        2

#define TT_HILL         3       // outdoor-types
#define TT_FOREST       4
#define TT_TOWN         5
#define TT_MOUNTAIN     6
#define TT_DESERT       7
#define TT_JUNGLE       8
#define TT_SWAMP        9
#define TT_PLAIN       10
#define TT_ARCTIC      11
#define TT_UNDERWATER  12
#define TT_ROAD        13
#define TT_TUNDRA      14
#define TT_WATER       15

#endif // __ENVIRONMENT_H__

#ifdef NEED_PROTOTYPES

#ifndef __ENVIRONMENT_H_PROTO__
#define __ENVIRONMENT_H_PROTO__

// no prototypes

#endif // __ENVIRONMENT_H_PROTO__

#endif // NEED_PROTOTYPES

