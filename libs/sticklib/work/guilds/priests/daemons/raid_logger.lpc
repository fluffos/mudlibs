#include "../priest.h"

#define DELAY 600

mapping raiders;

create() {
    raiders = ([]);
}

void
log_me(string name) {
    if(raiders[name] + DELAY > time()) return;
    if(!member(raiders, name))
	raiders += ([name: time()]);
else raiders[name] = time();
write_file(RAIDLOG,sprintf("%s: %s\n",capitalize(name),ctime(time())));
}

status is_raider(string name) {
    if(raiders[name]) return 1;
    return 0;
}


void
debug() {
    printf("%O\n", raiders);
}
