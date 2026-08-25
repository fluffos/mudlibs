#include <lib.h>
#include <save.h>

inherit LIB_DAEMON;
string savefile = SAVE_MEETINGS;
mapping schedule = ([]);

protected void create() {
    daemon::create();
    RestoreObject(savefile,1);
}

mapping GetScheduleMapping(){
    return copy(schedule);
}
