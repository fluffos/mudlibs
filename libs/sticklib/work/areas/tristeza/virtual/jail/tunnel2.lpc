#include "defs.h"

#include <room.h>

void
create_room()
{
    set_short("Y-Tunnel");
    set_long(
      "Three tunnels connect here in an 'Y'. There seems to be a bigger open "+
      "space to the south.");

    set_light_level(LT_DIM);
    set_wd(WD_INDOORS);

    add_exit("south", DIRR + "/cavern1");
    add_exit("northwest", DIRR + "/tunnel1");
    add_exit("northeast", DIRR + "/tunnel4");
}
