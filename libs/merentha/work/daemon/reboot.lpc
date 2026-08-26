// Petrarch
// Merentha Lib 1.0
// reboot daemon

#include <std.h>

inherit DAEMON;

string *__messages=({
"The rains continue to get worse, there appears to be no one left around.  A giant wave splashes over you and pulls you deep under the water's surface.",
"The rain water is now head high, the currents are too strong to swim in.  The few people who have found refuse on floating objects are toppled and fall into the raging waters.",
"The rains get even worse.  Giant balls of hail join the rains.  The hail destroyes nearly everything still standing.",
"The rain water is now waste high, the currents are strong.  Giant bolts of lightning strike from the sky.",
"The rains continue to fall, strong currents sweep some people under the water and to a drowning death.",
"Excess rain water from the ever increasing storm begins to form a sea over the land.",
"The sudden downpour begins to get worse as the ground can hold no more water.",
"Cold rains begin to pour down upon the land.",
"A giant clap of thinder shakes the ground.",
"The sky fills with dark clouds and lightning begins to strike within them.",
"A single dark cloud appears over the horizon.",
});

int rebooting;

string  reboot_message(int count) {
    if(count>=0 && sizeof(__messages)>=count+1) return __messages[count];
    return "";
}

void print_message(int count) {
    message("reboot", "%^BOLD%^"+reboot_message(count), users());
    if(count==0) {
        object *u;
        int i=sizeof(u=users());
        while(i--) u[i]->save_player(u[i]->query_name());
        shutdown();
        return;
    }
    message("reboot", "%^BOLD%^%^CYAN%^"+(count--)+" minute"+(count?"s":"")+" till reboot.", users());
    call_out("print_message", 60, count);
}

void reboot(int count) {
    if(rebooting) return;
    rebooting=1;
    print_message(count);
}

int query_rebooting() { return rebooting; }
