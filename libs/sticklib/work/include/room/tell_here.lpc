/*
 * This function is used to tell every living thing in the room a
 * message. Since it uses tell_me in living.c, one doesn't have to worry
 * about line-wrapping. For this reason, this should be used instead of
 * tell_room and say where possible. Note however, that calling this is
 * quite costy if there are many livings in the room, so use just 1
 * tell_here / action, if you have multiple messages, combine them into
 * 1 string and call then tell_here.
 *
 * The second optional argument defines what livings shouldn't be told
 * the message. It may be either an object-pointer, or an array of
 * object-pointers. If you have only 1 such living, use rather object-
 * pointer than array.
 * 
 * If, for some reason, you don't want lines to be wrapped, use third
 * optional argument so that linewrapping is not used.
 *
 * -Doomdark, 14-apr-94.
 */
/* Although the code may look rather clumsy, it should be fast.
 * Effectiveness over elegancy...
 * -Doomdark.
 */

#define	TELL_X(x) { if(interactive(x))\
		x->tell_me(s,no_wrap);\
		else tell_object(x, s + "\n");\
		i++; }\
		x = next_inventory(x);

/* If we wanted to wrap lines for monsters too, we'd use different
 * define:
 * #define TELL_X(x) { x->tell_me(s,no_wrap); i++; } x = next_inventory(x);
 *
 * But, as it is, this is way too slow way (me thinks), so let's just
 * suppose that all those who 'snoop' monsters, can use linewrappers
 * themselves.
 * -Doomdark.
 */

varargs int
tell_here(string s, mixed dont_tell_these, status no_wrap)
{
object x;
int i;
	x = first_inventory(this_object());
	if (!dont_tell_these) {
	  while(x) {
	    if (living(x)) TELL_X(x);
	  }
	} else if(!pointerp(dont_tell_these)) {
	  while(x) {
	    if (living(x) && x != (object) dont_tell_these) TELL_X(x);
	  }
	} else switch(sizeof(dont_tell_these)) {
	object a, b;
	case 0: /* Shouldn't actually happen... */
	  while (x) {
	    if(living(x)) TELL_X(x);
	  }
	  break;
	case 1:
	  a = (object) dont_tell_these[0];
	  while(x) {
	    if (living(x) && x != a) TELL_X(x);
	  }
	  break;
	case 2:
	  a = (object) dont_tell_these[0];
	  b = (object) dont_tell_these[1];
	  while(x) {
	    if (living(x) && x != a && x != b) TELL_X(x);
	  }
	  break;
	default:
	  while(x) {
	    if (living(x) && member((object*) dont_tell_these, x) < 0) TELL_X(x);
	  }
	}
	return i;
}
