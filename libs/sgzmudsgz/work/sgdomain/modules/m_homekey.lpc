// by fire on Dec 11 1997 m_silver.c 钱
// m_homekey.c
#include <sanguo.h> 
inherit OBJ;
inherit M_GETTABLE;

private string m_owner;
void setup()
{
    set_adj("小", "闪亮的");
    set_unit("把");
    set_id("key", "钥匙");
    set_in_room_desc("一个亮晶晶的钥匙。");
    set_size(VERY_SMALL);
    set_gettable(1);
    set_is_keeping(1);
    add_save(({"m_owner"}));
}
void set_owner(string owner) {
    m_owner=owner;
}
string long() {
	return "这是一把用来开"+CHAR_D->get_char(m_owner,"name")+"家的钥匙。\n";
}
mixed key_type()
{
    return m_owner;
}

int indirect_unlock_obj_with_obj() {
    return 1;
}

int indirect_lock_obj_with_obj() {
    return 1;
}
int not_give_npc() {
	return 1;
}