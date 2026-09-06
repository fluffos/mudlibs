#include <coder_levels.h>

#define SAVEFILE "/data/d/mudlock_d/mudlock_d"

private int mudlock;

void save_me()
{
    save_object(SAVEFILE);
}

void create()
{
    if(!restore_object(SAVEFILE))
    {
	mudlock = 0;
	save_me();
    }
}

void toggle_mudlock()
{
    if(!this_player())
	return;
    if(this_player()->query_coder_level() < LVL_SENIOR)
	return;

    mudlock = !mudlock;
    save_me();

    if(mudlock)
	log_file("MUDLOCK", sprintf("Locked   at %s by %s.\n",
	    ctime(time()), capitalize(this_player()->query_real_name())));
    else
	log_file("MUDLOCK", sprintf("Unlocked at %s by %s.\n",
	    ctime(time()), capitalize(this_player()->query_real_name())));
}

nomask int query_mudlock()
{
    return mudlock;
}
