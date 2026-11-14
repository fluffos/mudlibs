inherit "/std/thing";

#include <properties.h>
#include <moving.h>

#define STOCK "/obj/holzstock"

int get(object target);

void create()
{
  if(!clonep(this_object())) return;
  ::create();
  SetProp (P_SHORT, "Ein Holzstock");
  SetProp (P_LONG,
      "Dieser feste Holzstock ist eine einigermaßen brauchbare Waffe.\n");
  SetProp (P_NAME, "Holzstock");
  AddId (({"holzstock", "stock", "\nstockautomat"}));
  SetProp (P_GENDER, MALE);
  SetProp (P_ARTICLE, 1);
  SetProp (P_WEIGHT, 500);
  SetProp (P_NOGET, "");
  SetProp(P_MATERIAL, MAT_WOOD);
}

varargs int move(mixed target, mixed method,mixed mess)
{
  if ((method & M_GET) && living(target))
    // Da sich das Objekt (der Automat) nach dem Nehmen nicht
    // im Inventory des Nehmers befindet, nimmt put_and_get::pick_obj()
    // an, dass das Nehmen nicht erfolgreich war. Wir bestaetigen das
    // hier einfach, da aber P_NOGET=="" ist, merkt der Spieler nix :)
    return get(target);
  else
    return ::move(target,method,mess);
}

int get(object target)
{
  object ob;
  int res;

  if (!target || !interactive(target) || target != this_player())
    return 0;
  if (present("\nholzstock", this_player()))
  {
    write("Du hast doch schon einen Holzstock...\n");
    return ME_CANT_BE_TAKEN;
  }
  res = (ob=clone_object(STOCK))->move(this_player(),M_GET);
  if (res == 1) {
    write("Du nimmst einen Holzstock.\n"
      "Sofort erscheint auf unerklärliche Weise ein neuer.\n");
    say(this_player()->Name(WER,1)+" nimmt einen Holzstock.\n"
      "Sofort erscheint auf unerklärliche Weise ein neuer.\n", this_player());
    return ME_CANT_BE_TAKEN;
  }
  ob->remove();
  return res;
}

