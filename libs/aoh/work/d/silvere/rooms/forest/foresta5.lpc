#include <rooms.h>
#include <regions.h>
#include <properties.h>
#include <coordinates.h>
#include <moving.h>
#include <skills.h>
#include <herbs.h>
#include <nightday.h>
#include <msgclass.h>
#include "forest.h"

inherit FORESTROOM;

varargs void create()
{
  ::create();
  SetIntShort("A forest");
  SetIntLong(
"Moss can be seen all over the ground and even at some large stones "
"which are covering the whole area. To the east you can see the countryside "
"getting more and more hilly. Bushes are standing all between the "
"stones and to the south a huge forest raises high in the air. A path "
"branches off to the south where you can go deeper into the forest. "
"Another path leads east to the hills.\n");

  AddExit("west","./foresta4");
  AddExit("east","./foresta6");
  AddExit("south","./forestb5");

SetIntNoise ("A thumping sound makes you jump. You spin around only to "
"see nothing. It was probably just a rabbit. The scattering of birds' "
"wings also catches your attention. They must know something you do not.\n");

AddNoise("thumping","The rhythmic thumping of most likely a rabbit stamps "
"into the darkness of the forest. It sounds almost like a heartbeat. "
"It begins to fade almost as quickly as it appeared.\n");

AddNoise("birds","The flapping of wings is heard overhead, as birds scatter "
"in every direction.\n");

SetIntSmell (
"The forest smells like that of a library. The dust of books weighs almost "
"as heavily as the shade from the trees around. Though, as much as the  "
"forest smells old, it refreshes itself with every breath.\n");

// --- Added with Softbyte's Detailmaker by Aldrana
// Last update: Aldrana at Sun Mar 22 21:25:09 1998
  AddDetail( ({"path"}),
    "Shivers cause your body to shudder when you think about following the\n"
    "path. The dusty path leads into the deep forest. Should you dare?\n");
  AddDetail( ({"countryside"}),
    "The countryside is picturesque to your sight. Hills move up and down like\n"
    "ocean waves, and you become entranced at their magic. \n");
  AddDetail( ({"bushes"}),
    "The dense bushes make it difficult to move around easily. They are rich\n"
    "with life and sometimes seem to reach out to you. \n");
  AddDetail( ({"stones"}),
    "The smooth, marble-like stones offer a nice resting place for you. They\n"
    "wear tablecloth-like moss, and almost feel like pillows at the touch.\n");
  AddDetail( ({"moss"}),
    "The softness of moss covers most of the stones here. Its rich green color\n"
    "attracts your attention and your hands. It is spongey under your fingers.\n");

Set(P_NOWAY_MSG,
 "The moss seems to form a barrier to this direction.\n");
}
