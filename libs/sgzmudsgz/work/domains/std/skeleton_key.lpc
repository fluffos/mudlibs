// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
inherit OBJ;
inherit M_GETTABLE;

void setup()
{
    set_adj("小", "闪亮的");
    set_unit("把");
    set_id("key", "钥匙");
    set_in_room_desc("一个亮晶晶的保险柜钥匙。");

    set_gettable(1);
    set_long("这是一把用来开保险柜的钥匙。\n");
}

mixed key_type()
{
    return "skeleton";
}

int indirect_unlock_obj_with_obj() {
    return 1;
}

int indirect_lock_obj_with_obj() {
    return 1;
}