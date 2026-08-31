#include <std.h>
#include <amun.h>
inherit OINTMENT;

void create()
{
    ::create();
    set_name("Holy Water");
    set_short("%^BOLD%^%^CYAN%^Holy %^WHITE%^Water%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This bottle of Holy Water was blessed for The Last Saints. If applied to a <limb> or to <all>, it will improve your stamina.%^RESET%^");
    set_id( ({ "holy water", "water" }) );
    set_mass(2);
    set_value(10);
    set_your_mess_limb("%^BOLD%^%^WHITE%^You apply the %^BOLD%^%^CYAN%^Holy %^WHITE%^Water over your wounds.%^RESET%^");
    set_your_mess_all("%^BOLD%^%^WHITE%^You apply the %^BOLD%^%^CYAN%^Holy %^WHITE%^Water over your wounds.%^RESET%^");
    set_their_mess_limb("$N applies the %^BOLD%^%^CYAN%^Holy %^WHITE%^Water%^RESET%^ to $P $L.");
    set_their_mess_all("$N applies the %^BOLD%^%^CYAN%^Holy %^WHITE%^Water%^RESET%^ onto $P body.");
    set_action("apply $I");

}
