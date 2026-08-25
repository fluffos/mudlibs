// Updated by stefan on 10 Jan 1997 modified by fire on Jan 7 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
/*
** wieldable.c /std/modules/m_wieldable.c
*/
inherit M_DAMAGE_SOURCE;
private string wield_message="$N拔出一把$o。\n";
private string unwield_message="$N将$o插回腰间。\n";
void hook_state(string, mixed, int);
void mark_wielded_by(object);
nosave protected function move_hook = (: unwield_me :);
int valid_wield()
{
    // return 1 if they can wield this.
    return 1;
}
void set_wield_message(string p_m)
{
	wield_message=p_m;
}
string query_wield_message()
{
    return wield_message;
           
}
void set_unwield_message(string p_m)
{
	unwield_message=p_m;
}
string query_unwield_message()
{
    return unwield_message;
           
}
void mark_wielded_by(object which)
{
    hook_state("extra_short", "装备", which && which != this_object());
    hook_state("move", move_hook, which && which != this_object());
    m_damage_source::mark_wielded_by(which);
}
mixed ob_state()
{
    return query_wielded_by();
}
int direct_wield_obj()
{
    object who = owner(this_object());
    if (who && who != this_body()) return 0;
return 1;
}
