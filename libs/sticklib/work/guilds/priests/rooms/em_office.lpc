#include "../priest.h"
#include <room_defs.h>
inherit PRIEST_ROOM_DIR "officer_room";
inherit "basic/misc/emote";

void
create_room(){
    ::create_room();
    officer_title = "Elector Medicus";
    set(ALLOW_EMOTE);
    set_short("The Office of the Elector Medico");
    set_long(
      "This cluttered room eminates smells of rare herbs and strange and \
exotic tinctures. Partial covering the dark bloodwood paneling \
on the back wall is a large tapestry. Where it can be seen from \
under the alchemy table and the assorted hermetical apparati \
filling the room, the carpet is of a fine mulberry woolen. \
The only tidy spot in the room is the ornate bloodwood desk. \
On the desk sit a featherpen and ink well, several cups and \
suacers, and a large steaming teapot. The vapors from this \
seem to lighten your mood immediately. There are also \
manuscripts on the desk. A large map hangs on the wall \
above the desk. On the opposite wall the black eyes of \
the largest mounted dragonhead you have ever seen \
glitter menacingly in the diffuse light.");

    set_items(([
	({"desk","manuscripts"}):"The desk has several hand written manuscripts \
bearing titles of 'The Secrets of Alchemy' and 'A Young Alchemists Life'.",
	"map":"A ornately drawn map of the world. The more you look, the less \
resemblences to reality it bears. It must be kept for some other reason.",
	({"table","alchemy table"}):"The top of this low table is made from \
polished granite to resist the potent elements of the alchmists art. \
The table is covered with alchemical apparati.",
	"apparati":"An alchemists globe, a descensory furnace, several burrettes \
containing assorted reagants, and a hand centrifuge.",
	"dragonhead":"On closer inspection, you realize that the dragonhead is \
not from a dragon. It is a finely crafted mithril sculpture. The scales \
are made from flakes of some iridescent gem. It bears a small tag \
reading: 'A small token of our gratitude to you. We will be in your \
debt as long as these lives you saved for us last.' This is followed \
by the mark of a dwarven mining guild. If this head isn't real, why \
does it seem that the eyes are following you?",
	"teapot":"The teapot hums merrily, although no source of heat can be \
discovered beneath it. It smells so inviting you can hardly resist the \
urge to fill one of the cups on the desk beside it.",
	"tapestry":"This large tapestry is an intricately repeating pattern \
that, taken as a whole, displays the sacred Symbol of the Holy Order \
of Boccob. If you look closely, you will see that each small \
piece is also in the shape of the Symbol." ]));
    add_command("emote", "emote_cmd");
    add_exit("north", PRIEST_ROOM_DIR "basement");
}
