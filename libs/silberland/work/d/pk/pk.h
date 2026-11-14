#include "../def.h"
#define REGION "pk"

#define PK_RACES \
        ({ "elf", "zwerg", "fee", "oger", "mensch", "dunkelelf", \
                      "troll",  "hobbit" })
#define PK_VALID_RACE(t) (member_array(lower_case(t), \
             PK_RACES)  != -1)

