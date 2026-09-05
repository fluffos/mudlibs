/*
 * /sys/filter_funs.h
 * A set of functions often used by filter
 */

#define FILTER_LIVE(x) filter(x,"filter_living",this_object())
filter_living(ob) { return living(ob); }

#define FILTER_OTHER_LIVE(x) filter(x,"filter_o_living",this_object())
filter_o_living(ob) { return (living(ob) && (this_player()!=ob)); }

#define FILTER_DEAD(x) filter(x,"filter_dead",this_object())
filter_dead(ob) { return (living(ob)==0); }
