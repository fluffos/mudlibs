/*
 * New priest scalpel. It doesn't have any real use anymore, but don't
 * tell it to players. :)
 * -= Chopin =-
 */

#include <treasure.h>
#include "../priest.h"

#define FILE_NAME PRIEST_OBJ_DIR "scalpel"

query_auto_load() {
    return FILE_NAME + ":";
}

void
create_treasure(){
    set_name("scalpel");
    set_id(({"s_scalpel"}));
    set_short("A slim silver scalpel");
    set_long("A finely wrought scalpel. The blade is \
razor edged silver with the Order's arms etched in it.");
    set_weight(0);
    set_value(0);
}

status get() { return 1; }
status drop() {
    return 1;
}
