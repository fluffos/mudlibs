/* New Vesper daemon for the priest guild. This was handled originally
 * in Zagyg's code, but if you cloned several Zagygs, you got several
 * vesper messages. I hated that.
 * // Chopin 5/10/97
 *
 * Hour 6 = Matins, 18 = Vespers
 */

/* First change toward establishing a piety skill - Syzygy - 8/3/95 */


#define NO_LOG 1

#include "../priest.h"

mapping humble_monsies;
int min, hour;
status is_vespers;
string canon_hour;

// Prototypes of functions:
void go_to_vespers();
void check_hours();
mixed query_vespers() { return is_vespers ? canon_hour : 0; }

create() {
    humble_monsies = ([]);
    check_hours();
    is_vespers = 0;
    if(nature()->query_timerequest("go_to_vespers", this_object())==-1)
	nature()->add_timerequest(hour, min, "go_to_vespers");
}

void
add_me(object ob) {
    humble_monsies += ([ ob : 0 ]); // no data yet
    humble_monsies -= ([ 0 ]);
}


mapping
query_monsies() {
    return humble_monsies;
}

void
join_vespers(object me) {
    if(me)
	me->go_to_vespers(canon_hour);
}

go_to_vespers(){
    check_hours();
    // Sometimes there's more than one timerequest in the queue...
    // at least, when I try to test this daemon :)
    while(nature()->query_timerequest("go_to_vespers", this_object())>=0)
	nature()->clear_timerequest("go_to_vespers", this_object());
    nature()->add_timerequest(hour,min,"go_to_vespers");
    SERVER->inform("The Holy Order is called to " + canon_hour + ".",
      NO_LOG);
    walk_mapping(humble_monsies, #'join_vespers);
    is_vespers = 1;
    call_out("return_to_work", 450);
}

void leave_vespers(object ob) {
    if(ob)
	ob->back_to_work();
}

void
return_to_work() {
    SERVER->inform("The Holy Order is released from " + canon_hour + ".",
      NO_LOG);
    walk_mapping(humble_monsies, #'leave_vespers);
    is_vespers = 0;
}


check_hours(){
    int tmp_hour;

    tmp_hour = nature()->query_24_hour();

    if((tmp_hour >= 12) && (tmp_hour < 18)) {
	hour = 18;
	canon_hour = "Primes";
    }
    if(tmp_hour >= 18) {             
	hour = 0;
	canon_hour = "Vespers";
    }
    if(tmp_hour < 6) { 
	hour = 6;
	canon_hour = "Complins";
    }
    if((tmp_hour >=6) && (tmp_hour < 12)) {
	hour = 12;
	canon_hour = "Matins";
    }
    min=0;
    return 1;
}

set_do_time(int a,int b){
    hour=a;
    min=b;
    /* this is for testing only*/
    go_to_vespers();
    return hour;
}
