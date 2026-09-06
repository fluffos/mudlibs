/* Standard command header */

#define TP this_player()
#define TPNAME ((string)TP->query_name(0,TP))
#define CHECK	(interactive(this_player()) && this_player() == this_interactive())
#ifndef TOO_RELAXED
#define TOO_RELAXED "Nah, you feel too relaxed to do that."
#endif
#define	GET_NAME(x,y)	((string)x->query_name(0,y))
