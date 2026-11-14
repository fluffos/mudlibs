/*
 * Master defines fuer Queros Objecte 
 *
 * Querolin@tamedhon
 *
 */

#define CLOSURE(x) #'x
#define BS(x)  break_string(x, 78)
#define TO     this_object()
#define TP     this_player()
#define TPN    this_player()->Name()
#define TI     this_interactive()
#define TIPO   this_interactive()||previous_object()
#define CAP_TPN capitalize(this_player()->Name() )
#define ENV(x) environment(x)
//#define CAP(x) capitalize(x)

