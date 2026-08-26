// This is the mutable trainee weapon.
#include <mudlib.h>

inherit WEAPON;

void create() {
  int WEP ;
  seteuid(getuid());
  WEP = random(6) + 1 ;
  switch(WEP) {
  case 1: set("short", "a simple longsword") ; 
   set("id", ({ "longsword", "sword", "trainee weapon" }) ) ;
  set("long", @ENDLONG
This is a simple longsword used for training.
ENDLONG
  );
  set("name", "longsword" ) ;
  set_weapon_type("sword/long") ;
  set_material_type("metal/steel") ;
  set("damage", ({ 1, 8 }) ) ;
  break ;
  case 2: set("short", "a simple pole-axe") ;
  set("id", ({ "pole-axe", "axe", "poleaxe", "trainee weapon" }) ) ;
  set("nosecond", 1) ;  set("long", @ENDLONG
This is a simple pole-axe used for training.
ENDLONG
  );
  set_weapon_type("halberd") ;
  set_material_type("metal/steel") ;
  set("damage", ({ 1, 6 }) ) ;
  set("name", "pole-axe") ;
  break ;
  case 3: set("short",  "a simple halberd") ;
  set_weapon_type("halberd") ;
  set("damage", ({ 1, 10 }) ) ;
  set_material_type("metal/steel") ;
   set("nosecond", 1) ; set("long", @ENDLONG
This is a simple halberd used for training.
ENDLONG
  );  set("id", ({ "halberd", "trainee weapon" }) ) ;
  set("name", "halberd") ;
   break ;
  case 4: set("short", "a simple scimitar") ;
  set("damage", ({ 1, 8 }) ) ;
  set_weapon_type("sword/long") ;
 set("name", "scimitar") ;
  set("long", @ENDLONG
This is a simple scimitar used for training.
ENDLONG
  );  set("id", ({ "scimitar", "blade", "trainee weapon" }) ) ;
  break ;
  default: set("short", "a simple broadsword") ;
  set("long", @ENDLONG
This is a simple broadsword used for training.
ENDLONG
  ); set("damage", ({ 1, 8 }) ) ; set("id", ({ "sword", "broadsword",
  "trainee weapon" }) ) ;  set("name", "broadsword"); 
 set_weapon_type("sword/long") ;
   break ;
 }
  set("value", 100 + random(50)  ) ;
  if (WEP==1 || WEP>3) {
    set_verbs(({ "swing at", "attack", "slash at", "cut at" }) );
    set_verbs2(({ "swings at", "attacks", "slashes at", "cuts at" }) );
  }
  else {
    set_verbs(({ "poke at", "thrust at", "attack" }) ) ;
  }
  set("size", 6) ;
}
