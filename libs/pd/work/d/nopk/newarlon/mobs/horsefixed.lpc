#include <std.h>
#include <arlon2.h>
inherit MOUNT;
void create() {
    ::create();
   set_name("horse");
   set_id( ({ "horse" }) );
   set_short("%^RESET%^%^BOLD%^horse of%^BLUE%^ New Arlon%^RESET%^");
  set_level(10);
  set_stats("dexterity", 40);
  set_stats("strength", 40); 
  set_hp(query_max_hp());
  set_mp(query_max_mp());
  set_sp(query_max_sp());
   set_long("This is a beautiful horse of New Arlon.  It is very well groomed,
and equipped with a platinum saddle and legwraps.");
    set_body_type("equine");
    set_race("horse");
   set_gender("male"); 
  set_mount_message("The horse kneels down for you as you mount him.");
  set_unmount_message("The horse bucks you off.");
  new(ARM "saddle")->move(this_object());
  new(ARM "legwraps")->move(this_object());
    force_me("wear saddle");
    force_me("wear legwraps");
}

