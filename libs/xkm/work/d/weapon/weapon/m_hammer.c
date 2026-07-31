// m_hammer.c

#include <ansi.h>
#include <weapon.h>

inherit M_WEAPON;


int duanlian(object weapon);
int do_hui(object weapon);


string query_autoload() { return 1 + ""; }	//autoload weapon

void init()
{
	add_action("do_hui","hui");
}


void create()
{	
	object me;
	string w_name,w_id,w_or;
	int w_lv;
	me = this_player();
//读入数据
	w_name=me->query("weapon/name");
	w_id = me->query("weapon/id");
	w_or = me->query("weapon/or");
	w_lv = me->query("weapon/lv");
	set_name(w_name, ({w_id}));
	set("unit", "柄");   
	set("no_put",1);
	set("no_get",1);
	set("no_drop",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
	set_desc(w_lv,w_or,w_name);
	switch(w_or)
		{
		case "千年神木" :
			set_weight(500);
			set("material", "iron");
			break;
		case "海底金母" :
			set_weight(1000);
			set("material", "steel");
			break;
		case "寒丝羽竹" :
			set_weight(30);
			set("material", "bamboo");
			break;
		default :
		} 
	if( me->query("weapon/wield_msg"))
		set("wield_msg", me->query("weapon/wield_msg")+"\n");
	else
		set("wield_msg", "$N往后腰中一摸，取出了一柄"+w_name+"握在手中。\n");
	if( me->query("weapon/unwield_msg"))
		set("unwield_msg", me->query("weapon/unwield_msg")+"\n");
	else
		set("unwield_msg", "$N手中"+w_name+"往腰后一别，眨眼间已然不见影踪。\n");
    init_hammer(w_lv * 5);
	setup();
}	





int do_hui(object weapon)
{	
	string w_name;
	object me,ob;
	me=this_player();
	w_name=me->query("weapon/name");
	if( !weapon )
		return notify_fail("你要摧毁什么?\n");
	message_vision(HIR "$N大喝一声，一掌擎锤，一掌猛力击下。结果轰隆一声巨响"
			+w_name+HIR"裂为两半!\n" NOR,me);
	me->set("weapon/make",0);
	destruct( this_object() );
	me->delete("weapon");
	
	me->save();

	return 1;
}
/*void owner_is_killed()
{
        write(HIY"只见一声清脆的响声，"+query("name")+HIY"落在地上，断成数截。\n"NOR);
        this_object()->unequip();
        this_object()->reset_action();
        this_object()->set("name", query("name") + "的碎片");
        this_object()->set("value", 0);
        this_object()->set("weapon_prop", 0);
}*/

