#include <ansi.h>
inherit __DIR__"song_officer";
#include "/d/song/npc/entry.h"
#include "/d/song/config/mokan.h"
void create()
{
	call_out("npc_to_player",1,"知审官院事",40,-1);
	set("inquiry", ([
	
		 "入职": (: get_me_in :),
		 "join": (: get_me_in :),
		]));
	set("profession","文");
	set("mokan_high",7);
	set("mokan_low",9);
	::create();
}

