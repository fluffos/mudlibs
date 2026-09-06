#include <coord.h>
#include <shape.h>
#include <object.h>
#include <inven.h>
#include <desc.h>
#include <scenedesc.h>

NAME( "altar" )
DISTANT( "an altar" )
SPECIFIC( "the altar" )
LOOK( "You gaze upon a white marble altar." )
PLURAL( "altars" )
GETTABLE( 0 )
DROPPABLE( 1 )

int query_scenery() {
   return 1;
}

void on_map_paint( object painter ) {
   painter->paint_shape( query_x(), query_y(), "\t___\n|___|", 15, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+2, "(", 7, LAYER_WALL );
   painter->paint_shape( query_x()+1, query_y()+2, "***", 4, LAYER_WALL );
   painter->paint_shape( query_x()+4, query_y()+2, ")", 7, LAYER_WALL );
}

void init() {
	::init();
	add_action("on_pray","pray");
}

int on_pray(string arg) {
	if (arg == "at altar" || arg == "toward altar" || arg == "facing altar") {
		mapping godlist = (["Example"]);
		int count = 0;
		if (this_player()->query_mana() < 20)
			return notify_fail("You are too spiritually drained to pray at the altar right now.\n");
		set_actor(this_player());
		set_target(this_object());
		this_player()->msg_local("~CACT~Name ~verbkneel while facing ~targ and ~verbbegin to pray.~CDEF");
		this_player()->set_stance(ST_CROUCHING);
		this_player()->add_readiness(-500);
		while (sizeof(godlist) && this_player()->query_mana() >= 20) {
			string god = m_indices(godlist)[random(sizeof(godlist))];
			count++;
			this_player()->add_busy(2);
			call_out("report_favor", count * 4, this_player(), god);
			godlist -= ([ god ]);
			this_player()->add_mana(-20);
		}
		this_player()->add_busy(1);
		"/bin/stand"->main();
		return 1;
	} else
		return 0;
}

void report_favor(object player, string god) {
	int f = player->query_favor(god);
	string buf;
	if (!player->skill_check("magic.faith", 20))
		buf = "~CDRKYou receive no answer from "+god+" at this time.";
	else if (f > 95)
		buf = "~[140You feel "+god+"'s presence next to you.";
	else if (f > 80)
		buf = "~[140You feel very close to "+god+".";
	else if (f > 60)
		buf = "~CBRTYou feel close to "+god+".";
	else if (f > 40)
		buf = "You can barely feel "+god+"'s influence.";
	else if (f > 20)
		buf = "You have difficulty communicating with "+god+".";
	else if (f > 0)
		buf = "~[030You cannot feel "+god+"'s influence.";
	else if (f > -20)
		buf = "~[030"+god+" appears to be slightly displeased with you.";
	else if (f > -40)
		buf = "~CWRNYou can feel "+god+"'s displeasure strongly.";
	else
		buf = "~CWRN"+god+"'s hatred washes over you like the flames of a furnace.";
	msg_object(player, buf+"~CDEF");
}
