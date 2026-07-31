// gangdao.c
inherit ITEM;

void create()
{
    	set_name("铁掌", ({ "iron strike" }));
	set_weight(1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("material", "iron");
	}
	set("rigidity", 10);
	set("weapon_prop/damage", 30);
	set("flag", 4);
	set("skill_type", "strike");
	set("env/invisibility", 1);
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "slash", "slice", "hack" }) );
	}
	setup();
}
