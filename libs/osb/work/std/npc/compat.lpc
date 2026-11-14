/* std/npc/compat
**
**  Here are the compatibility functions to convert old savefiles, 
**  adapt for new functions and all that.
**
**  16-Jun-95 [Mateese] /std/living/life considered.
**  31-Jul-96 [Mateese] Some LOGs changed to ERRors.
*/

#include <attributes.h>

inherit "/std/living/compat";

#define THIS this_object()
#define TP   this_player()
#define ENV  environment
#define PREV previous_object()

#define NETDEAD  (!interactive() && query_once_interactive(THIS))

/*--------------------------------------------------------------------------*/

public varargs mixed Set(string pname, mixed value, int sc);
                                 // std/base

// std/living/attributes
public mapping QueryAttrs();
public mapping SetAttrs(mapping attrs);
public mapping QueryAttributes();
public mapping SetAttributes(mixed attrs);
public varargs mixed QueryAttr(string aname, int sc);
public varargs mixed SetAttr(string aname, mixed value, int sc);

// std/npc/body
public int AddAlcohol(int strength);
public int AddDrink(int strength);
public int AddFood(int strength);

/*--------------------------------------------------------------------------*/

#define LOG(fun) log_file("COMPAT", sprintf("%O: %O->%s\n", THIS, PREV, fun))
#define CLOG(fun) if (PREV!=THIS) log_file("COMPAT", sprintf("%O: %O->%s\n", THIS, PREV, fun))
#define LOGO(fun,file) log_file("COMPAT", sprintf("%O: %s overloaded in %s\n", THIS, fun, file))
#define ERRO(fun,fun2,file) do { log_file("COMPAT", sprintf("%O: %s overloaded in %s\n", THIS, fun, file)); raise_error("Function '"+fun+"' has been replaced by '"+fun2"'.\n"); } while(0)
#define ERR(fun,txt) do { log_file("COMPAT", sprintf("%O: %O->%s\n", THIS, PREV, fun)); raise_error(txt); } while(0)
#define EFUN(fun) do { log_file("COMPAT", sprintf("%O: %O->%s\n", THIS, PREV, fun)); raise_error("Unsupported function '"+fun+"'.\n"); } while(0)
#define OFUN(fun) do { log_file("COMPAT", sprintf("%O: %O->%s\n", THIS, PREV, fun)); raise_error("Outdated function '"+fun+"'.\n"); } while(0)

/*--------------------------------------------------------------------------*/

/* ======================= /std/npc/life =============================== */

drink_alcohol(strength) {
  OFUN("drink_alcohol");
  return AddAlcohol(strength);
}

drink_soft(strength) {
  OFUN("drink_soft");
  return AddDrink(strength);
}

eat_food(strength) {
  OFUN("eat_food");
  return AddFood(strength);
}

do_digest() {
  OFUN("do_digest");
  DoDigest();
}

/* ======================= /std/living/moving ============================= */

/* ======================================================================== */

void check_overloads()
{
  string file;

  ::check_overloads();

  // std/living/life
  if (   (file = function_exists("eat_food", THIS)) 
      && file != "/std/npc/compat")
    ERRO("eat_food", "AddFood", file);
  if (   (file = function_exists("drink_soft", THIS)) 
      && file != "/std/npc/compat")
    ERRO("drink_soft", "AddDrink", file);
  if (   (file = function_exists("drink_alcohol", THIS)) 
      && file != "/std/npc/compat")
    ERRO("drink_alcohol", "AddAlcohol", file);
}

/****************************************************************************/
