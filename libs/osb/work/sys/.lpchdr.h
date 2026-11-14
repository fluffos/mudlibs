#pragma verbose_errors

#include "config.h"
#include "properties.h"
#include "moving.h"
#include "rooms.h"
#include "living.h"
#include "attributes.h"
#include "macros.h"
#include "msgclass.h"
#include "daemons.h"

get(str) {
  return previous_object()->XFindObj(str);
}

getfile(str) {
  return MASTER->make_path_absolute( str );
}
