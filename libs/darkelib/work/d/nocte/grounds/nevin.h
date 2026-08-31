// Coder: %^GREEN%^nEv!N%^RESET%^ 
// %^GREEN%^nEv!N's%^RESET%^ Header File

//#define ENV 	environment
//#define CAP 	capitalize
//#define LOW 	lower_case
//#define FN 	file_name

//#define TP 	this_player()
//#define TPQN 	((string)this_player()->query_name())
//#define TPQCN	((string)this_player()->query_cap_name())
#define TPQR	((string)this_player()->query_race())
#define TPQC	((string)this_player()->query_class())
#define TPQL	((int)this_player()->query_level())
//#define TPQP	((string)this_player()->query_possessive())
#define TPQO	((string)this_player()->query_objective())
#define TPQS	((string)this_player()->query_subjective())
//#define TO	this_object()
#define TOQL    ((int)this_object()->query_level())

#define ROOMS	"/d/nocte/grounds/rooms/"
#define MON	"/d/nocte/grounds/mon/"
#define WEAP	"/d/nocte/grounds/weapon/"
#define ARM	"/d/nocte/grounds/armour/"
#define MAGIC	"/d/nocte/grounds/magic/"
