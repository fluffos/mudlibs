// A little device that counts time until a set date.
// Haw 230594
// Modified into a command 280497 --Haw
// 130597	Added timer action file support for coders

#include <cmd.h>
#include <config.h>

#define TIMER_DATA "open/timerdata"
#define TIMER_ACTION_FILE  PATH_USER+"%s/.timer"
#define TIMER_ACTION_FUNC "timerAction"
#define MINTIME 60
#define TELL(x) this_player()->tell_me(x)

#define DAY 86400
#define HOUR 3600
#define MIN 60

void clean();
void findMin();
string cTimeLeft(int i);

mapping data;


void
create()
{
    restore_object(TIMER_DATA);
    if(!data)
	data = ([]);
    clean();
    findMin();
}


status
timer_cmd(string str)
{
    string name, *tmp, t_unit;
    int mult, i, tmptime, T;

    if(!CHECK) return 0;

    name = (string)this_player()->query_real_name();
    if(!str) {
	TELL("# Do \"timer ?\" for usage info.");
	if(member(data, name))
	    TELL(sprintf("# Your timer is set to %s, which is %s from now.",
		ctime(data[name]), cTimeLeft(data[name] - time())));
	return 1;
    }
    if(str == "?") {
	TELL("\
# Usage: timer args\n# Args format:\n\
\t         wwd xxh yym zzs\n\
\t         (note: the number and the order of args\n\
\t         is not restricted)");
	return 1;
    }

    tmptime = 0;
    tmp = explode(str, " ");
    i = sizeof(tmp);
    while(i--) {
	if(sscanf(tmp[i], "%d%s", mult, t_unit)) {
	    switch(t_unit) {
	    case "d" : tmptime += mult * DAY;	break;
	    case "h" : tmptime += mult * HOUR;	break;
	    case "m" : tmptime += mult * MIN;	break;
	    case "s" : tmptime += mult;		break;
	    default :
		TELL("# Ignoring invalid argument \""+tmp[i]+"\"...");
	    }
	    continue;
	}
	TELL("# Ignoring invalid argument \""+tmp[i]+"\"...");
    }

    if(tmptime < MINTIME) {
	TELL("# Too short a time.");
	return 1;
    }

    T = time() + tmptime;
    if(member(data, name)) {
	data[name] = T;
	TELL("# Adjusting existing timer...");
    } else
	data += ([name:T]);
    TELL("# Timer set to "+ctime(T)+".");
    save_object(TIMER_DATA);
    findMin();

    return 1;
}


string
cTimeLeft(int T)
{
    int days, hours, mins;
    string timeleft;

    if(T <= 0)
	return "<negative>";

    T -= (days = (T / DAY)) * DAY;
    T -= (hours = (T / HOUR)) * HOUR;
    T -= (mins = (T / MIN)) * MIN;

    timeleft = "";
    if(days)
	timeleft += (days+" days ");
    if(hours)
	timeleft += (hours+" hours ");
    if(mins)
	timeleft += (mins+" minutes ");
    if(T)
	timeleft += (T + " seconds ");
    return timeleft;
}


void
notify()
{
    string *tmp;
    int i, T;
    object pl;

    T = time();
    i = sizeof(tmp = m_indices(data));
    if(i == 0)
	return;
    while(i--) {
	if(data[tmp[i]] <= T) {
	    if(!(pl = find_player(tmp[i])))
		continue;
	    pl->tell_me(sprintf("# Timer: It is now %s!", ctime(T)));
	    if(pl->query_coder_level())
		catch(call_other(sprintf(TIMER_ACTION_FILE, tmp[i]), TIMER_ACTION_FUNC));
	    data[tmp[i]] = 0;
	}
    }
    clean();
    findMin();
    return;
}


void
findMin()
{
    string *tmp;
    int i, min, T;

    remove_call_out("notify");
    T = time();
    i = sizeof(tmp = m_indices(data));
    if(i == 0)
	return;

    min = data[tmp[i - 1]];
    while(i--)
	if(data[tmp[i]] < min)
	    min = data[tmp[i]];

    call_out("notify", min - T);
    return;
}


void
clean()
{
    mapping m;
    string *tmp;
    int i, T;

    T = time();
    m = ([]);
    i = sizeof(tmp = m_indices(data));
    while(i--)
	if(!tmp[i] || !data[tmp[i]] || data[tmp[i]] < T)
	    continue;
	else
	    m += ([tmp[i]:data[tmp[i]]]);
data = m;
save_object(TIMER_DATA);
return;
}
