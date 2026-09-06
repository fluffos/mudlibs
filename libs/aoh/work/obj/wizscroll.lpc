/* The Wizard Scroll  (Mateese, 16-Feb-1993)
**
** Tells new wizards and seers important things.
*/

#include <properties.h>
#include <secure/wizlevels.h>

#define TO this_object()
#define TP this_player()

inherit "/std/thing";

varargs void create() {
  ::create();
  SetWeight (100);
  Set(P_VALUE, 10);
  AddId ("scroll");
  AddId ("wizscroll");
}

void init() {
  ::init();
  add_action ("fread", "read");
}

#define O_NONE 0
#define O_PLAYER 1
#define O_ANCIENT 2
#define O_WIZARD 3

int _owner (object this) {
  int wlvl;
  if (!this) this = environment();
  if (!living(this) || !this->QueryIsPlayer()) return O_NONE;
  wlvl = query_user_level(this);
  if (wlvl < LVL_ANCIENT) return O_PLAYER;
  if (wlvl == LVL_ANCIENT) return O_ANCIENT;
  return O_WIZARD;
}

varargs string QueryShort () {
  int who;
  if (!(who = _owner(TP))) return 0;
  return (who == O_PLAYER ? "a scroll" : "an important scroll");
}

varargs string QueryLong () {
  int who;
  string rc;
  if (!(who = _owner(TP))) return 0;
  if (who == O_PLAYER)
    return
 "This is a small scroll. There is something written on it, but you can't\n"
+"read it.\n";

  rc = 
 "This scroll contains valuable information for freshly promoted dwellers "
 "of OSB.\n";
  if (who == O_ANCIENT) rc += "Just read it.\n";
  else {
    rc += "Just read it for your special information.\n";
    rc += "The rules are readable with 'read rules'.\n"
         +"The scroll ids as 'scroll' and 'wizscroll'.\n";
  }
  return rc;
}

varargs int QueryValue () { return _owner(TP) < O_ANCIENT ? 5 : 0; }
varargs int QueryWeight () { return _owner(TP) < O_ANCIENT ? 100 : 0; }
int QueryNoDrop () { return _owner(TP) >= O_ANCIENT; }
int QueryNoSell () { return 1; }
int QueryNoBuy () { return _owner(TP) >= O_ANCIENT; }
int QueryAutoObject () { return _owner(TP) >= O_ANCIENT; }

mixed fread (string arg) {
  int who;
  string fname;

  if (!arg)
    return notify_fail ("Read what?\n");

  if ((who = _owner(TP)) < O_ANCIENT) 
    return notify_fail ("You fail to decipher the writing.\n");

  if (id(arg))
    fname = ({ "ancient", "wizard" })[who-O_ANCIENT];
  else
    switch (lower_case(arg)) {
      case "rules": if (who >= O_ANCIENT) fname = "RULES"; break;
      case "ancient" : if (who >= O_ANCIENT) fname = "ancient"; break;
      case "wizard" : if (who >= O_WIZARD) fname = "wizard"; break;
    }
  if (!fname) 
    return notify_fail ("Read what?\n");
  return TP->more("/doc/intro/"+fname);
}
