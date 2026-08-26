#include <forging.h>

inherit COMMAND_BASE;

int cmd(string str) {
  if(!str || !strlen(str)) {
    tell_object(TP, sprintf( "%-#*s\n\n", (int)TP->query_cols(),
        implode( sort_array( FORGE_H->query_items_allowed(), 1), "\n") ) );
    return 1;
  }
  tell_object(TP, str);
}

mixed query_patterns() {
  return ({ "allowed", (:cmd($3):), });
}
