// Updated by stefan on 10 Jan 1997 modified by fire on Jan 12 1998
/* Do not remove the headers from this file! see /USAGE for more info. */
// modified fy fire on March 1998
#include <mudlib.h>
inherit OBJ;
void hook_state(string, string, int);
//### Huh?  This appears to be unused.
private nosave string   wearmsg="$N穿上一件$o。\n";
private nosave string   removemsg="$N脱下$o。\n";
private nosave int      is_on;
#ifdef USE_BODYSLOTS
private nosave string   slot;
#endif
private nosave int m_attack_ability=0;
private nosave int m_defence_ability=0;
private nosave int m_defence_power=0;
private nosave int m_rongmao=0;
void set_defence_ability(int p_tmp)
{
	m_defence_ability=p_tmp;
}
int query_defence_ability()
{
	return m_defence_ability;
}
void set_defence_power(int p_tmp)
{
	m_defence_power=p_tmp;
}
int query_defence_power()
{
	return m_defence_power;
}
void set_attack_ability(int p_attack)
{
	m_attack_ability=p_attack;
}
void set_rongmao(int p_rongmao)
{
	m_rongmao=p_rongmao;
}
int query_attack_ability()
{
	return m_attack_ability;
}
int query_rongmao()
{
	return m_rongmao;
}
mixed ob_state() {
    if (!is_on) return 0;
    return slot;
}
void remove() {
    if(!slot)
        return 0;
 if(!objectp(environment()))
    return 0;
if(!(environment()->is_living()))
   return 0;
    environment()->depopulate_body_slot(slot, this_object());
}
void set_wearmsg( string s )
{
  wearmsg = s;
}
string query_wearmsg()
{
  return wearmsg;
}
void set_removemsg( string s )
{
  removemsg = s;
}
string query_removemsg()
{
  return removemsg;
}
void set_slot(string what)
{
    slot = what;
}
string query_slot()
{
    return slot;
}
void set_is_on( int g )
{
  is_on = g;
  hook_state("extra_short", "穿戴着", is_on);
  hook_state("prevent_drop", "你要先把它脱下来。\n", is_on);
}
void do_wear()
{
    object who;
    if(!slot)
    {   write("这东西好象不知该穿哪。\n");
        return;
    }
    who=owner(this_object());
    foreach (object ob2 in all_inventory(who)) 
    {
	
     	if ((slot==ob2->ob_state()))
	{
		write("你已经穿戴了同类装备了。\n");
		return;
	}
    }	
    environment()->populate_body_slot(slot, this_object());
    set_is_on(1);
    who->simple_action(wearmsg, this_object());
}
void do_remove() {
    if(!slot)
        return 0;
    environment()->depopulate_body_slot(slot, this_object());
    set_is_on(0);
    this_body()->simple_action(removemsg, this_object());
}
mixed  direct_wear_obj() {
    
    object who = owner(this_object());
    if (who != this_body())
        return 0;                                       
    if( is_on )                                         
        return "你正穿着呢！\n";
    return 1;
}
mixed direct_remove_obj() {
  
    object who = owner(this_object());
    if (who != this_body())
        return 0;                                 
    if (environment() != this_body() || !is_on)
        return "你根本就没有穿它！\n"; 
    return 1;
}
