#include <std.h>
#include <guild.h>
inherit OINTMENT;

void create()
{
    ::create();
    set_name("Blood of Asmodeus");
    set_short("%^BOLD%^%^RED%^B%^RESET%^%^RED%^l%^BOLD%^%^RED%^ood %^WHITE%^of %^BLACK%^Asmodeus%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^You hold a small sac of %^RED%^b%^RESET%^%^RED%^l%^BOLD%^%^RED%^ood %^BLACK%^from the Dark Lord Asmodeus. If you apply it you would probably gain %^RED%^energy%^BLACK%^.%^RESET%^");
    set_id( ({ "blood", "blood of asmodeus" }) );
    set_mass(2);
    set_value(10);
    set_your_mess_limb("%^BOLD%^%^BLACK%^You quickly rub the %^RED%^b%^RESET%^%^RED%^l%^BOLD%^%^RED%^ood %^BLACK%^over your body and feel Asmodeus power.%^RESET%^");
    set_your_mess_all("%^BOLD%^%^BLACK%^You quickly rub the %^RED%^b%^RESET%^%^RED%^l%^BOLD%^%^RED%^ood %^BLACK%^over your body and feel Asmodeus power.%^RESET%^");
    set_their_mess_limb("$N applies the %^RED%^b%^RESET%^%^RED%^l%^BOLD%^%^RED%^ood to $P $L.");
    set_their_mess_all("$N applies the %^RED%^b%^RESET%^%^RED%^l%^BOLD%^%^RED%^ood onto $P body.");
    set_action("apply $I");

}
