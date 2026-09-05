
#ifndef MACROS_H
#define MACROS_H

#define TU 	this_user()
#define TP 	this_player()
#define TO 	this_object()
#define ENV(x) 	environment(x)
#define ETU 	environment(this_user())
#define ETP 	environment(this_player())
#define ETO 	environment(this_object())
#define PO(x) 	previous_object(x)
#define APO	all_previous_objects()
#define	FO	first_object()

#endif /* MACROS_H */
