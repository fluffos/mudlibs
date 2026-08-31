#include <std.h>
#include <arlon.h>
inherit MOUNT;

void create() {
    ::create();
   set_name("horse");
   set_id( ({ "horse" }) );
   set_short("A white horse");
  set_level(10);
  set_stats("dexterity", 40);
  set_stats("strength", 40); 
  set_hp(query_max_hp());
  set_mp(query_max_mp());
  set_sp(query_max_sp());
   set_long("The horses fur is pure white. It stands tall and awaits "
            "somebody to ride him.");
    set_body_type("equine");
    set_race("horse");
   set_gender("male"); 
  set_mount_message("You climb into the saddle of the horse.");
  set_unmount_message("You leap out of the saddle and dismount the horse.");
  new(ARM "saddle")->move(this_object());
}
