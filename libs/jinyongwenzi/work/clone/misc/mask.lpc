// mask.c yujue
#include <armor.h>

inherit HEAD;

void create()
{
	set_name("面罩", ({ "mian zhao", "zhao", "mask" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "付");
                set("material", "cloth");
                set("armor_prop/armor", 1);
		set("wear_msg", "$N取出一个面罩套在头上。\n");
		set("remove_msg", "$N把面罩脱了下来。\n");
		set("no_drop", 1);
		set("unique", 3);
        }
        setup();
}

int wear()
{
	object ob = environment();
	string id;
	int ret;

	if (!living(ob)) {
		message_vision("面罩从$N头上掉了下来。\n", ob);
		return 0;
	}

	if (ret=::wear()) {
		id = ob->query("id");
		id = id[0..0]+id[<1..<1];
		if (userp(ob)) ob->set_temp("apply/id", ({ id }));
		id = capitalize(id);
		if (wizardp(ob)) {
			ob->set_temp("apply/name", ({ "蒙面巫师" }));
			ob->set_temp("apply/short", ({ "蒙面巫师(Mengmian wushi)" }));
		} else if (ob->query("gender") == "女性") {
			ob->set_temp("apply/name", ({ "蒙面女子" }));
			ob->set_temp("apply/short", ({ "蒙面女子("+id+")" }));
		} else {
			ob->set_temp("apply/name", ({ "蒙面男子" }));
			ob->set_temp("apply/short", ({ "蒙面男子("+id+")" }));
		}
		ob->set_temp("apply/long", ({ "一个莫名其妙的家伙，由于带着面罩，你看不清楚这家伙的面目。\n" }));
	}
	return ret;
}

int unequip()
{
	object ob = environment();
	int ret = ::unequip();

	if (ret) {
		ob->delete_temp("apply/id");
		ob->delete_temp("apply/name");
		ob->delete_temp("apply/short");
		ob->delete_temp("apply/long");
	}
	return ret;
}
