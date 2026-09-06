#include <attack.h>

object shadowed;
int dur;

void create_iv(int duration)
{
    shadowed=this_player();

    shadow(shadowed,1);
    set_heart_beat(1);
    dur = duration;
    return;
}

int hit_player(int dam, int t, mixed hc, object enemy)
{
    if(t != DT_FORCE) dam = 0;
    return shadowed->hit_player(dam,t,hc,enemy);
}

void
heart_beat() {

    dur -= 2;
    if(dur <= 0) {
	destruct(this_object());
	if(shadowed)
	    tell_object(shadowed, "You feel suddenly feel weaker.\n");
    }
}
