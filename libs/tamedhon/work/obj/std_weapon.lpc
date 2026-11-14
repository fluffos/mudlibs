// /obj/std_weapon.c      Eine Standardwaffe (Schwert)
// inherit "/obj/std_weapon";
// [...]
// create_default_weapon(waffenklasse, gewicht, preis, streuung in %)
// 02-03-1996  - Mupfel@AnderLand -

inherit "std/weapon";

#include <properties.h>
#include <combat.h>
#include <language.h>
#include <defines.h>

varargs void create_default_weapon(int wc, int weight, int value, int var);

void create()
{
  if (IS_BLUE(ME)) return;
  ::create();
  SetProp(P_SHORT, "Ein Schwert");
  SetProp(P_LONG, "Ein Schwert.\n");
  SetProp(P_NAME, "Schwert");
  SetProp(P_GENDER, FEMALE);
  // Zur Sicherheit Waffen-/Schadenstyp setzen
  SetProp(P_WEAPON_TYPE, WT_SWORD);
  SetProp(P_DAM_TYPE, DT_SLASH);
  create_default_weapon(10, 1000, 100);
  AddId("schwert");
}

varargs void create_default_weapon(int wc, int weight, int value, int var)
{
  // Abweichung fuer alle 3 Parameter gleich
  var = 100+random(2*var+1)-var;
  // WC 0, Gewicht 0 und Preis 0 sollte explizit gesetzt werden
  wc = (wc*var)/100;
  weight = (weight*var)/100;
  value = (value*var)/100;
  if (wc <= 0)
    wc = 1;
  else if (wc > MAX_WEAPON_CLASS)
    wc = MAX_WEAPON_CLASS;
  SetProp(P_WC, wc);
  SetProp(P_WEIGHT, (weight <= 0 ? 1 : weight));
  SetProp(P_VALUE, (value <= 0 ? 1 : value));
  // printf("wc = %i, weight = %i, value = %i.\n", wc, weight, value);
}


