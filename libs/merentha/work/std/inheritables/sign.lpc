// Petrarch
// Merentha Lib 1.0
// sign.c

#include <std.h>
#include "sign.h"

inherit OBJECT;

string __Message;

void create() {
    ::create();
    __Message="The sign is worn with age and you can not read what it once said.";
    set_prevent_get("The sign is nailed into the ground and can not bet gotten.");
}

void init() {
    ::init();
    add_action("cmd_read", "read");
}

void set_message(string str) { __Message=str; }
int cmd_read(string str) {
    if(!str || !id(str)) return 0;
    message("read", ""+this_player()->query_cap_name()+" reads over "+query_short()+".", environment(), this_player());
    message("read", ""+__Message, this_player());
    return 1;
}

