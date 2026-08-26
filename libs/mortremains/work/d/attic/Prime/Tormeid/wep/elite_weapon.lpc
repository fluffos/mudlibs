// Written by Chronos.
#include <mudlib.h>

inherit WEAPON;

void create() {
  int WEP ;
  seteuid(getuid());
  WEP = random(6) + 1 ;
  switch(WEP) {
  case 1:
    set("short", "a vorpal blade") ;
    set("id", ({ "blade", "vorpal", "ELITE_WEAPON" }) ) ;
    set("long", @ENDLONG
A masterfully crafted blade etched with runes and magical inscriptions.
The blade glistens with the desire to draw blood.
ENDLONG
  );
    set("name", "vorpal blade" ) ;
    set_weapon_type("sword/long") ;
    set_material_type("metal/fine steel") ;
    set("damage", ({ 6,15 }) ) ;
    break ;
  case 2:
    set("short", "an enormous two-handed sword") ;
    set("id", ({ "two-handed sword", "sword", "ELITE_WEAPON" }) ) ;
    set("long", @ENDLONG
A downright huge weapon, this sword is intimidating and lethal-looking.
The thought of the damage it could inflicts makes you shudder.
ENDLONG
  );
    set("name", "two-handed sword" ) ;
    set_weapon_type("sword/two-handed") ;
    set_material_type("metal/fine steel") ;
   set("damage", ({ 4, 15 }) ) ;
  set("nosecond", 1) ;
    break ;
  case 3:
    set("short", "a deadly battle-axe") ;
    set("id", ({ "axe", "battle-axe", "ELITE_WEAPON" }) ) ;
    set("nosecond", 1) ;
    set("long", @ENDLONG
A double-edged battle-axe with two deadly, razor-sharp edges.
There is no doubt that this mind could easily cleave a man in half
in the hands of a skilled wielder.
ENDLONG
  );
    set("name", "battle-axe" ) ;
    set_weapon_type("axe/battle") ;
    set_material_type("metal/fine steel") ;
    set("damage", ({ 4, 12 }) ) ;
    break ;
  case 4:
    set("short", "an enchanted halberd") ;
    set("id", ({ "halberd", "ELITE_WEAPON" }) ) ;
    set("nosecond", 1) ;
    set("long", @ENDLONG
An enchanted halberd of Tormeid's elite guard.  Runes and magical
inscriptions are carved along the entire length of the weapon.
It glows with a brilliant radiance.
ENDLONG
  );
    set("light", 1) ;
    set_weapon_type("halberd") ;
    set_material_type("metal/fine steel") ;
    set("damage", ({ 10, 18 }) ) ;
    set("name", "halberd") ;
    break ;
  default:
    set("short", "a deadly longsword") ;
    set("id", ({ "sword", "longsword", "ELITE_WEAPON" }) ) ;
    set("long", @ENDLONG
A longsword with a glistening, deadly edge.  It is rare to see such
craftsmanship in a weapon.
ENDLONG
  );
    set("name", "longsword" ) ;
    set_weapon_type("sword/long") ;
    set_material_type("metal/fine steel") ;
   set("damage", ({ 4, 12 }) ) ;
    break ;

 }
  if (WEP==4) set_verbs(({ "poke at", "thrust at", "attack" }) ) ;
  else {
    set_verbs(({ "swing at", "attack", "slash at", "cut at" }) );
    set_verbs2(({ "swings at", "attacks", "slashes at", "cuts at" }) );
  }
  set("value", 2400 + random(1000) ) ;
  set("size", 7) ;
}
