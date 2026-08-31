#ifndef __SAURON_DEFS_H__
// 111296:  Saffrin debugged the xmas tree for use

#define __SAURON_DEFS_H__

#pragma strict_types
#pragma save_types

#include <lw.h>

#define MSCOBJ "/players/saffrin/fun/xmas/"

#define WRITE(x)	writelw(x)
#define TELLO(o,x)	tell_object(o,lw(x))

#define NF(x)		notify_fail(lw(x))
#define TP		this_player()
#define TO		this_object()
#define PO		previous_object()

#define MOVE		move_object
#define MOVEO	MOVE(CO)
#define FO		find_object
#define CO		clone_object
#define DE		destruct
#define ENV		environment
#define CAP		capitalize


#define RNAME(o)	(string)o->query_real_name()
#define CRNAME(o)	capitalize((string)o->query_real_name())

#endif // __SAURON_DEFS_H__
