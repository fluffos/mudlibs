#include <mudlib.h>

inherit WEAPON;

void create() {
  int WEP ;
  seteuid(getuid());
  WEP = random(6) + 1 ;
  switch(WEP) {
  case 1: set("short", "an ornate longsword") ; 
   set("id", ({ "longsword", "sword", "ROYAL_WEAPON" }) ) ;
  set("long", @ENDLONG
A beautifully crafted longsword with elaborate runes carved along
the blade and hilt.
ENDLONG
  );
  set("name", "longsword" ) ;
  set_weapon_type("sword/long") ;
  set_material_type("metal/fine steel") ;
  break ;
  case 2: set("short", "a golden pole-axe") ;
  set("id", ({ "pole-axe", "axe", "poleaxe", "ROYAL_WEAPON" }) ) ;
  set("nosecond", 1) ;  set("long", @ENDLONG
A shiny golden pole-axe.  The blade looks lethal.
ENDLONG
  );
  set_weapon_type("halberd") ;
  set_material_type("metal/gold") ;
  set("name", "pole-axe") ;
  break ;
  case 3: set("short",  "an ornate halberd") ;
  set_weapon_type("halberd") ;
  set_material_type("metal/gold") ;
   set("nosecond", 1) ; set("long", @ENDLONG
An elaborately decorated halberd.
ENDLONG
  );  set("id", ({ "halberd", "ROYAL_WEAPON" }) ) ;
  set("name", "halberd") ;
   break ;
  case 4: set("short", "a razor-sharp scimitar") ;
  set_weapon_type("sword/long") ;
 set("name", "scimitar") ;
  set("long", @ENDLONG
The blade of this fine weapon has been sharpened to a glistening
point.
ENDLONG
  );  set("id", ({ "scimitar", "blade", "ROYAL_WEAPON" }) ) ;
  break ;
  default: set("short", "a royal broadsword") ;
  set("long", @ENDLONG
This broadsword is emblazoned with the emblem of Tormeid, a mighty
falcon.
ENDLONG
  ); set("damage", ({ 2, 9 }) ) ; set("id", ({ "sword", "broadsword",
  "ROYAL_WEAPON" }) ) ;  set("name", "broadsword"); 
 set_weapon_type("sword/long") ;
   break ;
 }
  set("value", 1500 + random(1500) ) ;
  set("weapon", 27) ;
  if (WEP==1 || WEP>3) {
  set_verbs(({ "swing at", "attack", "slash at", "cut at" }) );
  set_verbs2(({ "swings at", "attacks", "slashes at", "cuts at" }) );
  }
  else {
  set_verbs(({ "poke at", "thrust at", "attack" }) ) ;
  }
  set("size", 6) ;
} 

