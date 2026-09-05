#include <ansi.h>
inherit __DIR__"npc_item";
#include "/d/suzhou/obj/npc_only/throwing.h"
void create()
{
	set_name("勾魂镖", ({ "gouhun biao", "biao"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("long", "这是一枚勾魂镖<NPC专用>。\n");
		set("value", 10000);
		set("material", "iron");
		set("throw_type","qi");
		set("effect",1000);
		set("anti_job",({"jobs/completed/huyidao"}));
	}
	setup();
}

