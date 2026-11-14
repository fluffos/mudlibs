#include <properties.h>
#include <combat.h>
#include <defines.h>
#include <moredef.h>
#include <new_skills.h>
#include "../itemd.h"
#include <wizlevels.h>
#include <vt100.h>
#include <class.h>
#include <moving.h>

//int setmight();
#define RAUBTIERE ({"katze","wolf","baer", "raubkatze", "fuchs", "marder",\
    "dachs", "hund", "otter", "loewe", "jaguar", "tiger", "puma", "leopard" }) 
#define HUFTIERE ({ "pferd", "hirsch", "reh", "ziege", "kuh", "schaf",\
    "schwein", "antilope", "gazelle", "giraffe", "tapir", "elefant", "nashorn",\
    "mammut"})
#define NAGETIERE ({ "biber", "maulwurf",  "hoernchen", "hase", "kaninchen",\
    "nagetier", "maus", "ratte"})
#define AFFEN ({"schimpanse", "gorilla", "pavian", "affe"})
#define ANDERETIERE ({})

#define ANIMALS RAUBTIERE+HUFTIERE+NAGETIERE+AFFEN+ANDERETIERE

#ifndef P_BERSERKER_BONUS
#define P_BERSERKER_BONUS "berserker_bonus"
#endif
