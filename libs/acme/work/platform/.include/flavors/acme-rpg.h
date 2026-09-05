#include "flavors/acme-basic.h"
#define ParentFlavor Flavor
#undef Flavor
#define Flavor "acme-rpg"
#include <flavor_config.h>

#define CombatMixin          ModuleDir "/combat"
