#include <ansi.h>
inherit COMBINED_ITEM;
inherit F_EQUIP;

void init()
{
	add_action("do_drop", "drop");
	add_action("do_remove", "remove");
}

void create()
{
        set_name("布袋", ({ "bu dai", "dai", "bag" }));
        if (clonep())
		set_default_object(__FILE__);
        else {
		set("long", 
"一只用粗麻布织成的袋子，身上所带布袋的多少，是丐帮弟子江湖地位的标志。\n");
		set("material", "cloth");
		set("unit", "个");
		set("base_value", 0);
		set("base_unit", "个");
		set("base_weight", 100);
		set("remove_msg", "$N将布袋除了下来。\n");
		set("wear_msg", "$N将布袋别在身后。\n");
  set("armor_prop/armor", 5);
		set("no_get",1);
        }
}

int do_drop(string str)
{
	object me,obj;
	me = this_player();

	if ( !str ) return 0;
	if ( !objectp(obj = present(str, me))  
	|| obj->query("name") != "布袋" || userp(obj) ) 
		return 0;
	tell_object(me,"身为丐帮弟子，袋在人在，袋亡人亡！\n");
	return 1;
}

int do_remove(string str)
{
        object me,obj;
        me = this_player();

        if ( !str ) return 0;
	if ( !objectp(obj = present(str, me))    
	|| obj->query("name") != "布袋" || userp(obj) )
		return 0;
        tell_object(me,"布袋是丐帮弟子身份的象征，你不能把它除下！\n");
	return 1;
}

