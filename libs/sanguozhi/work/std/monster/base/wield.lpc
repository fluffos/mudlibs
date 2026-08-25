// Updated by stefan on 10 Jan 1997 
// modified by fire on Jan 6 1998
// /std/monster/base/wield.c 
/* Do not remove the headers from this file! see /USAGE for more info. */
/*
 * Handle the ability of 'monsters' to wield other objects.
 * Also handle caching of some data.
 */
void simple_action(string, object);
private nosave object weapon;
nosave protected string weapon_type;
string query_weapon_type() {
    return weapon_type;
}
//:FUNCTION wield
//wield the specified object
void wield(object ob)
{
    if (weapon)
        weapon->mark_wielded_by(0);
    weapon = ob;
    weapon->mark_wielded_by(this_object());
    weapon_type = weapon->query_wield_type();
}
//:FUNCTION unwield
//stop wielding the weapon we were wielding
void unwield() {
    if (weapon)
	{
        	weapon->mark_wielded_by(0);
            simple_action(weapon->query_unwield_message(), weapon);
	}
	else
		write("你没装备武器呀！/n");
    wield(this_object());
}
//:FUNCTION query_weapon
//return the weapon we are using.  The weapon will be us if we are
object query_weapon()
{
    // The odd handling here is due to the possibility of our weapon getting
    // dested.
    if (weapon) return weapon;
    wield(this_object());
    return weapon;
}
//:FUNCTION do_wield
//wield the specified object, as well as checking if it is valid and printing
//the appropriate message
int do_wield(object ob) {
    if (!(ob->valid_wield())) return 0;
    simple_action(ob->query_wield_message(), ob);
    wield(ob);
    return 1;
}
