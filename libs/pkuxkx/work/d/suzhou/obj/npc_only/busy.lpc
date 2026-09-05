#include <ansi.h>
inherit __DIR__"npc_item";
#include "/d/suzhou/obj/npc_only/drug.h"
void create()
{
	set_name("不忙丹", ({ "bumang dan", "dan"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("long", "这是一枚解busy用的不忙丹<NPC专用>。\n");
		set("value", 4000);
		set("material", "herb");
		set("drug_type","anti_busy");
		//set("effect",8000);
		set("anti_job",({"jobs/completed/huyidao"}));
	}
	setup();
}

