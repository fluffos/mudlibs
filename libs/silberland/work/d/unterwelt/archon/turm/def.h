/* Files.h (Archon - 12.01.2003)
 Rev 1.0 12.01.2003 Archon: erstellt
*/

#ifndef __TURM_H__
#define __TURM_H__

#define MAGIERNAME "archon"
#define GEBIET "turm"

#include "../../def.h"
#include "/players/archon/standard/standard.h"
#include "quest.h"

#define P_TURMDEFENDER  "archon_turmdefender"

#ifndef STD
#define STD "/d/unterwelt/" MAGIERNAME "/" GEBIET "/std/"
#endif

#ifndef LIB
#define LIB "/d/unterwelt/" MAGIERNAME "/" GEBIET "/lib/"
#endif

#ifndef DNPC
#define DNPC "/d/unterwelt/" MAGIERNAME "/" GEBIET "/dunkelelfen/npc/"
#endif

#define P_DIR_WEAPON "/p/weapon/"
#define P_DIR_ARMOUR "/p/armour/"
#define P_DIR_GILDE  "/gilden/paladine/armour/"

#define OBJ_ARCHON_TUNNEL   "/d/unterwelt/" MAGIERNAME "/tunnel/obj/"

#endif
