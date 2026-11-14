#include <properties.h>
#include <combat.h>
#include <moving.h>
#include <new_skills.h>
#include <defines.h>
#include <moredef.h>
#include <ansi.h>

#define GUILDNAME "berserker"
#define GUILD "/gilden/berserker"
#define SPELLBOOK "/spellbooks/berserker_spells"

#ifndef NPC
#define NPC     "/gilden/berserker/npc/"
#endif

#ifndef OBJ
#define OBJ     "/gilden/berserker/obj/"
#endif
#ifndef ARMOUR
#define ARMOUR  "/gilden/berserker/obj/"
#endif
#ifndef WEAPON
#define WEAPON  "/gilden/berserker/weapon/"
#endif
#ifndef LOG
#define LOG     "/gilden/berserker/log/"
#endif
#ifndef ROOM 
#define ROOM    "/d/dschungel/feyaria/felseninsel/room/"
#endif

#define BMASTER      "/gilden/berserker/master/berserkermaster"
#define MEMBERLIST   "/gilden/berserker/members/members"
#define MEMBERBACKUP "/gilden/berserker/members/members_backup"
#define SAVEMASTER   "/gilden/obj/savefilemaster"
#define TOPLIST      "/gilden/berserker/members/toplist"
#define REALTOPLIST  "/gilden/berserker/members/toplist.read"

#define RES_CHECKER "/gilden/obj/restriction_checker"

#include "./berserker_extern.h"
#include "./berserker_talente.h"

#define LATEST_STIRNBAND_VERSION "09. Sep 2024"

#ifndef DB
#define DB(x) if (find_player("gwenshara")) tell_object(find_player("gwenshara"),ANSI_BOLD+ANSI_RED+(x)+ANSI_NORMAL+" \n")
#endif

#define NOT_ALLOWED_MEMBER (["rakulan": "Berserkerunwuerdiges Verhalten",\
                             "nakaros": "Berserkerunwuerdiges Verhalten",])

// Friday, June 04 2010: angrox: Fuer blinde Spieler keine Abfrage auf P_WIMPY
#define NOWIMPYPLAYERS ({"mendra", "lirandra", "uck", "glaurum", "elonea", "gitana", "kandamir", "rivana", "luther", "celmak" })

#define CL(x) #'x