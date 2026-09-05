/*   This is an example, how to use the parser-function add_rule.
 *   There are also some advises for the usage of message.
 */

#include <grammar.h>  // for parser macros
#include <message.h>  // for message macros

inherit "basic/parser";  // for using add_rule
inherit "basic/message"; // for using message
inherit "complex/item";  // standard for creating a simple object

void create() {       // create and configure the object
  set_name("tulip");
  set_short("a black tulip");
  set_long("This is a very beautiful black flower.\n");
  set_id(({"tulip","flower","black tulip","black flower"}));
  set_encumbrance(1000);   // set_weight but weight 1 = enc 2500;
  set_value(25);

  add_rule("smell <me>","smell");  // set action for smell;
  add_rule("stroke <living> with <me>","stroke"); // action for stroke;

  add_error_message("smell","Perhaps you want to smell the flower?\n");
/*  we don't have to add an error message for stroke because this is
 *  already a standard feeling 
 */
}

void init() {
  add_actions();  // without this call nothing will work
}

status do_action(string verb, mapping args) {
  object WHOM;

  switch(verb) {
  case "smell":
/*  You don't need any check because the parser checks all ids of the
 *  object automatically, and this case is called only if this check is true
 */
    message(({ ({ M_PLAYER," ",M_PL_VERB,"smell"," ",M_PL_POSSESSIVE,
		  " tulip and ",M_PL_VERB,"smile"," melancholically." }) }));
/*  will return "You smell your tulip and smile melancholically." for 
 *  this_player() and "Doro smells her tulip and smiles melancholically."
 *  for all other livings in the room. 
 */
    return 1;
  case "stroke":
    WHOM=args[G_LIVING];  // args[G_LIVING] returns the object given by <living>
    message(({ ({ M_PLAYER," ",M_PL_VERB,"stroke"," ",WHOM," with ",
		  M_PL_POSSESSIVE," tulip softly over the cheek." }),1,
	       ({ WHOM," ",M_VERB,"blush",WHOM," in the deepest red." }) }));
    return 1;
  }
  return 0;
}

