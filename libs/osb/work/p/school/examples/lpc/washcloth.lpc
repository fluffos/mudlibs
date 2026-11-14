/* A washcloth  (Mateese, 21-Nov-1994)
**
** A washcloth to remove graffiti.
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
public void create() 
{
  ::create();
  Set(P_SHORT, "a wash cloth");
  Set(P_LONG, ({
 "A small piece of textile, which seems to be drained with a solvent.\n"
,"You can use it to clean graffiti.\n" }));
  Set(P_WEIGHT, 200);
  Set(P_VALUE, 5);
  AddId(({ "cloth", "wash cloth", "washcloth"}));
}

public void init () {
  ::init();
  add_action("fclean", "clean");
}

//---------------------------------------------------------------------------
public int fclean (string arg)
{
  string *graf, text;
  object here;
  mapping m;
  int i, j;

  if (!arg || arg == "") {
    notify_fail("Clean what?\n", NOTIFY_NOT_CMD);
    return 0;
  }
  if (lower_case(arg) != "graffiti" && lower_case(arg) != "graffity") {
    notify_fail("The washcloth is not suited for cleaning "+arg+".\n"
               , NOTIFY_NOT_OBJ);
    return 0;
  }
  here = environment(TP);
  graf = (string *)here->Query(GRAFFITI_TEXTS);
  if (!(i = sizeof(graf))) {
    notify_fail("There are no graffiti here.\n", NOTIFY_NOT_OBJ);
    return 0;
  }
  i = random(2)+1;
  for (; i-- && sizeof(graf); )
  {
    j = random(sizeof(graf));
    graf[j..j] = ({});
  }
  if (!(i = sizeof(graf)))
    graf = 0;
  here->Set(GRAFFITI_TEXTS, graf);

  show(TP->QueryName()+" scrubs with a washcloth some graffiti away.\n");
  write("You scrub for a while...\n\n\n     ..."+(i ? "some" : "the")
        +" graffiti are gone!\n");

  if (!sizeof(graf)) {
    here->RemoveDetail( ({"graffiti", "graffity"})
                      , ({"#call_other", blueprint(THIS), "doDetail" })
                      );
    here->RemoveExtra(GRAFFITI_EXTRA);
  }
  else if (sizeof(graf) <= 3)
    here->SetExtra(GRAFFITI_EXTRA,
([ P_INT_LONG:"Someone has sprayed interesting graffiti here.\n" ])
                  );
  else
    here->SetExtra(GRAFFITI_EXTRA,
([ P_INT_LONG:"There are lots of interesting graffiti here.\n" ])
                  );
  return 1;
}

//---------------------------------------------------------------------------
