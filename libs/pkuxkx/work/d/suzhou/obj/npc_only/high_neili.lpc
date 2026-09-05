#include <ansi.h>
inherit __DIR__"npc_item";
#include "/d/suzhou/obj/npc_only/drug.h"
void create()
{
	set_name("高级内力丹", ({ "adv neili dan","neili dan", "dan"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("long", "这是一枚高级内力丹<NPC专用>。\n");
		set("value", 12000);
		set("material", "herb");
		set("drug_type","neili");
		set("effect",6000);
		set("anti_job",({"jobs/completed/huyidao"}));
	}
	setup();
}

