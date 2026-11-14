/* A spray can  (Mateese, 21-Nov-1994)
**
** A spray can to spray graffiti on the walls.
** Originally invented for NF-I by Ploi.
*/

#include <config.h>
#include <properties.h>
#include <secure/wizlevels.h>

#define PRE previous_object()
#define TP  this_player()
#define THIS this_object()

#define GRAFFITI_TEXTS "graffiti texts"
#define GRAFFITI_EXTRA "graffiti extra"

inherit "/std/thing";

//---------------------------------------------------------------------------

private int sprays; // Number of graffities one might spray

//---------------------------------------------------------------------------

int QuerySprays()    { return sprays; }
int SetSprays(int i) { 
  if (i > 0)
    RemoveAdjective("empty");
  else
    RemoveAdjective("empty");
  return sprays = i > 0 ? i : 0;
}

//---------------------------------------------------------------------------

public int QueryWeight() { return ::QueryWeight() + QuerySprays()*5; }
public int QueryValue()  { return ::QueryValue() + QuerySprays()*5; }
public varargs string Short(string what) {
  string sh;
  if (!(sh = ::Short(what)) || QuerySprays() > 0)
    return sh;
  return "an empty "+strip_a(sh);
}
public varargs string ExaLong(string what) {
  string sh;
  int i;

  sh = "You can use it to spray graffiti";
  if (!(i = QuerySprays()))
    return "It is empty.";
  else if (IS_IMMORTAL(TP))
    sh += " ("+i+" units left)";
  return sh+".\n";
}

//---------------------------------------------------------------------------
public void create() 
{
  ::create();
  Set(P_SHORT, "a spray can");
  Set(P_LONG,
"A small spray can, bearing a label saying\n"
"    'Ploi's Colorful Spray'\n"
"in large friendly letters.\n"
         );
  Set(P_WEIGHT, 50);  // empty weight
  Set(P_VALUE, 20);   // empty value
  AddId(({ "can", "spray can", "spraycan"}));
  SetSprays(20);
}

public void init () {
  ::init();
  add_action("fspray", "spray");
}

//---------------------------------------------------------------------------
public string doDetail (string arg)

// Return the detail description for one graffiti.
// This function is called by name in the blueprint from the rooms.

{
  string *graf;

  if (-1 == member(({ "graffity", "graffiti" })
                  , lower_case(arg||"")))
    return "You see none.\n";
  graf = (string *)PRE->Query(GRAFFITI_TEXTS);
  if (!sizeof(graf)) {
    PRE->RemoveDetail(({"graffiti", "graffity"}));
    PRE->RemoveExtra(GRAFFITI_EXTRA);
    return "You see none.\n";
  }
  return graf[random(sizeof(graf))];
}

//---------------------------------------------------------------------------
public int fspray (string arg)
{
  string *graf, text;
  object here;
  int i;

  if (!(i = QuerySprays())) {
    notify_fail("The spraycan is empty.\n", NOTIFY_NOT_CMD);
    return 0;
  }
  if (!arg || lower_case(arg) == "graffiti" || lower_case(arg) == "graffity")
    arg = "Something illegible, but colorful like a box of smarties.\n";
  else {
    i -= strlen(arg) / 30;
    if (-1 == member(".!:?,", arg[<1]))
      arg += ".\n";
    else
      arg += "\n";
  }
  i--;
  show(({ TP->QueryName()+" sprays some graffiti.\n"
        , "You hear something hissing nearby.\n" }));
  write("Psst. Psst. You spray some graffiti.\n");
  here = environment(TP);
  graf = (string *)here->Query(GRAFFITI_TEXTS);
  if (!sizeof(graf)) {
    here->AddDetail( ({"graffiti", "graffity"})
                   , ({"#call_other", blueprint(THIS), "doDetail" })
                   );
    graf = ({});
  }
  graf += ({ arg });
  here->Set(GRAFFITI_TEXTS, graf);
  if (sizeof(graf) <= 3)
    here->SetExtra(GRAFFITI_EXTRA,
([ P_INT_LONG:"Someone has sprayed interesting graffiti here.\n" ])
                  );
  else
    here->SetExtra(GRAFFITI_EXTRA,
([ P_INT_LONG:"There are lots of interesting graffiti here.\n" ])
                  );
  SetSprays(i);
  if (i < 1)
    write("The spray can is empty now.\n");
  return 1;
}

//---------------------------------------------------------------------------
