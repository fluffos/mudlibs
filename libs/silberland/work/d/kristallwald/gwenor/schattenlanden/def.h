#define GEBIET "schattenlanden"
#include "../def.h"

#define CHECK_WLTASK(x) (x->QueryProp(P_GUILD) == "waldlaeufer" && x->QueryProp(P_GUILD_LEVEL) >= 5 && !test_bit(call_other("/gilden/waldlaeufer/master/master", "GetTask"), 6))