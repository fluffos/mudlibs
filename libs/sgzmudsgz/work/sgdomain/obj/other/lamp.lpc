// lamp.c used for gini
#include <sanguo.h>
inherit OBJ;
inherit M_GETTABLE;
private string m_owner;
private string m_type;
void setup()
{   
    //m_owner = environment(this_object());
    if (!sizeof(m_type)) m_type = "gini";
    clear_id();
    set_id(GINI_D->get_msg(m_type,"lamp_id"),GINI_D->get_msg(m_type,"lamp_name"));
    add_id("gini lamp");
    set_unit(GINI_D->get_msg(m_type,"lamp_unit"));
    //set_id("gini lamp", "%^YELLOW%^神灯%^RESET%^");
    set_size(VERY_SMALL);
    set_gettable(1);
    set_can_drop(0);
    set_can_give(0);
    set_is_keeping(1);
    add_save(({"m_owner"}));
    add_save(({"m_type"}));
}

string long() {
	if (sizeof(m_type))
		return GINI_D->get_msg(m_type,"lamp_long");
	else
		return "一盏%^YELLOW%^神灯%^RESET%^";
}

mixed set_owner(string owner)
{
    m_owner = owner;
    if (objectp(find_body(m_owner))) {
    	m_type = find_body(m_owner)->get_gini();
    	clear_id();
    	set_id(GINI_D->get_msg(m_type,"lamp_id"),GINI_D->get_msg(m_type,"lamp_name"));
    	add_id("gini lamp");
    	set_unit(GINI_D->get_msg(m_type,"lamp_unit"));
    	set_long(GINI_D->get_msg(m_type,"lamp_long"));
    }
    else
    	m_type = "gini";
}

string get_owner()
{
    return m_owner;
}

string get_type()
{
    return m_type;
}

int not_give_npc()
{
	return 1;
}
