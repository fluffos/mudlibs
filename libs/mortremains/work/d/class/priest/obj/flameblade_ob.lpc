//ilz-2

#include <m_spells.h>              
#include <magic.h>
#include <mudlib.h>

inherit WEAPON;


void create() {
  seteuid(getuid());
  set("id", ({ "blade", "sword", "flameblade" }) );
  set("short", "flameblade");
  set("name", "flameblade");
  set("long", "a magical, flaming blade created through prayer.\n");
  set_weapon_type("sword/long");
  set_bonus(1);
  set("damage_type", "fire");
  set("damage", ({ 2,8 }) );  
  set("prevent_drop", 1);
  set("prevent_sell", 1);
  set("dest_at_die", 1);
 set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ; 
}

int begin_spell(object caster) {
  set("level", caster->query_level());

  set("enchantment", DIM);
  set("schools", ({ "evocation" }) );
   write("Make sure you wield the flame blade if you want to use it!\n");
  call_out("remove", caster->query_level() * 60 );
  return 1;
}

/* EOF */
