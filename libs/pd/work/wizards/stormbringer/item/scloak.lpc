
#include <std.h>
inherit ARMOUR;

create() {
    ::create();
    set_name("Cloak of Stormy's");
    set_id( ({"cloak", "cloak of stormy's"}) );
    set_short("%^BOLD%^%^BLUE%^Cloak of Stormy's%^RESET%^");
    set_long("A long dark blue cloak having a strange magical "
      "ability let you know when Stormbringer has entered the "
      "world.");
    set_mass(0);
    set_value(0);
    set_type("cloak");
    set_ac(20);
    set_limbs( ({"torso", "head", "left arm", "right arm", "left leg", "right leg", "left hand", "right hand", "left foot", "right foot"}) );
    set_wear( (: this_object(), "extra_worn" :) );
    set_remove( (: this_object(), "extra_removed" :) );
}

int extra_worn() {
   if(this_player()->query_cap_name() !="Stormbringer") {
        message("info", "The voice of Stormbringer echoes through your "
          "mind, 'You are not worthy of such an item!'",
          this_player());
         message("info", this_player()->query_cap_name()+" attempts "
          "to wear the Cloak of Stormy's, but fails.",
          environment(this_player()), this_player());
        message("info", "The cloak bursts into flames. "
          +this_player()->query_cap_name()+" is burned as the cloak "
          "is consumed by the fire!", environment(this_player()) );
        this_player()->add_hp(-(51+random(50)-random(50)) );
        this_object()->remove();
        return 0;
    }
    else
    message("info", "%^BOLD%^%^BLUE%^"+this_player()->query_cap_name()+" enters the realm bringing great storms with him!", users());
    return 1;
}

int extra_removed() {
    message("info", "%^BOLD%^"+this_player()->query_cap_name()+" leaves the realm taking his storms with him.", users());
    return 1;
}

int query_auto_load() {
  if(this_player()->query_level() !="1000") return 1; }


