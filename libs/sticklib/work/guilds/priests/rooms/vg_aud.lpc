#include "priest_room.h"

#define VG_ROOM PRIEST_ROOM_DIR "vg_off"

object *guests;

void create_room()
{
    set_light_level(LT_LIGHTS);
    set(ROOM_GUILD);
    set(ROOM_WD, WD_INDOORS);
    set(PREVENT_TELEPORT);
    set_short("The Vicegerant's Audience Room");
    set_long("You are in the Vicegerant's Audience Room. The \
magnificient scope of this room overwhelm's you. The walls are panelled \
in warm maple and ash, yet deepened by the beautiful tapestries that \
hang about the gilded inlays and crystal window panes. Through these \
windows, you look down upon the City and it's inhabitants. There are \
several leather covered chairs, and small writing desk. By the desk \
papers and quills on the desk you guess that a scribe has been taking \
dictation recently. The subtle path of countless supplicants making their \
way to the Vicegerant's private chamber over the ages can be seen in the \
soft wool carpeting laid over the burl oak flooring. This path leads north \
to a large oaken door with a small mithril plaque on it.");

    add_item(({"tapestry","tapestries"}),"These beautiful scenes from \
the past tell the history of the Church's struggle in the secular world.");
    add_item("carpet","Soft shag wool carpeting.  Years of use have \
begun to leave their mark on it.");
    add_item("desk","A scribe's writing desk, more than likely used \
when the Vicegerant issues a Judgement to the faithful.");
    add_item("papers","Papers used by a scribe. These seem to bear some \
dictation on them.");
    add_item("dictation","You stealthly read: One must consider the \
Immortal Kelgath and his place in the Church. Surely he is not as honest \
in his dealings as it appears. And what of his friends who have gone from \
this mortal plane; surely he cannot stand to be parted long from them? \
Perhaps care should be taken in trusting him and his meanings.......");
    add_item(({"window","windows","crystal"}),"You look out the \
transparent panes on to the City below. It is an awe inspiring sight.");
    add_item("plaque","It says: Ask Templar for admittance.");

    set_exits(([
	"south" : PRIEST_ROOM_DIR "relaxation",
	"north" : PRIEST_ROOM_DIR "vg_off"
      ]));

    add_monster(PRIEST_MON_DIR "templar",
      "Templar quitly returns to his post.",1); 
    add_monster(PRIEST_MON_DIR "templar",
      "Templar quitly returns to his post.",1);

    set_commands(([
	"north"  : "north_cmd",
	"ask" : "ask_cmd"
      ]));
    add_permanent(PRIEST_OBJ_DIR "guest_board");
    add_permanent(PRIEST_OBJ_DIR "excom_board");
}

status
north_cmd(){
    object me,blocker,Symbol;
    me=this_player();

    if(!guests) guests=({});

    Symbol = present(GUILD_ID,me);
    blocker = present("templar",this_object());

    if(blocker) {
	if (Symbol && (string) me->query_guild() == GN_PRIEST) {
	    if((int)Symbol->query_rank()>=VG_RANK) {
		return 0;
	    }
	    if(member(guests, me)<0) {
		me->tell_me("Templar tells you: I do not \
see your name on my copy of the Vicegerant's schedule. \
Would you like me to ask if he will see you now?");
		return 1;
	    }
	}
	if(member(guests, me)>-1){
	    guests-=({me});
	    return 0;
	}
	me->tell_me("Templar growls: I have no idea how you got this far \
impertanent heathen, but surely you don't think I would let you sully the \
Vicegerant's presence with your putrid stench!");
	return 1;
    }
    return 0;
}


status
ask_cmd(string s){
    object me;

    if((s != "Templar for admittance") &&
      (s != "templar for admittance")) { return 0; }

    me = this_player();
    me->tell_me("You ask the Templar for admittance to the Vicegerant.");
    environment(me)->tell_here(me->query_name()+" asks the Templar \
something.",me);

    VG_ROOM->knock(me->query_real_name());
    return 1;
}

admit(object who){
    if(!guests) guests=({});
    guests+=({who});
    who->tell_me("Templar says: The Vicegerant will see you now.");
    return 1;
}
