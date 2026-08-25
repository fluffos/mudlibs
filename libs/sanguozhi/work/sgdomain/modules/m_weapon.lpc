// m_weapon.c
// by fire on March 1, 1998
#include <mudlib.h>
inherit OBJ;
inherit M_WIELDABLE;
inherit M_GETTABLE;
inherit M_MESSAGES;
private nosave int m_defence_ability=0;
private nosave int m_attack_ability=0;
private nosave int m_attack_power=0;
void set_defence_ability(int p_tmp)
{
	m_defence_ability=p_tmp;
}
int query_defence_ability()
{
	return m_defence_ability;
}
void set_attack_power(int p_tmp)
{
	m_attack_power=p_tmp;
}
int query_attack_power()
{
	return m_attack_power;
}
void set_attack_ability(int p_attack)
{
	m_attack_ability=p_attack;
}
int query_attack_ability()
{
	return m_attack_ability;
}
void mudlib_setup()
{
    ::mudlib_setup();
    set_gettable(1);
}
void remove() {
    object::remove();
    m_wieldable::remove();
}           
int indirect_kill_liv_with_obj()
{
  return 1;
}
