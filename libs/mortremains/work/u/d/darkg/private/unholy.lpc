#include <mudlib.h>

inherit WEAPON;

void create() {
  seteuid(getuid());
   set("author", "Darkgoth the Delinquest");
   set("name", "sword");
   set_weapon_type("dagger");
   set_material_type("metal/iron");
set ("id", ({ "sword", "#BSKB#" }) );
set("bksb_mult", 100);
  set("damage", ({ 2374,10000 }) );
  set("short", "Darkgoth's Unholy Death-Sword");
 set("long", "This extraordanadry finely crafted sword is the first\n"+
       "Blasphmous creation made by Darkgoth. The very metal emits\n"+
       "a soft blue aura. Ancient runes that line the handle give off\n"+
       "a Chilling feeling of pure evil.\n");
   set_bonus(3,2,5);
  set("nosecond", 1);
  set_verbs( ({ "cut", "cleave", "swing at", "slice at" }) ) ;
set_verbs2( ({ "cuts", "cleaves", "swings at", "slices at" }) );
}
int query_auto_load() {return 1;}
