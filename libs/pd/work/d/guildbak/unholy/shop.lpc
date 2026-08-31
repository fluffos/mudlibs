#include <std.h>
#include <guild.h>
inherit ROOM;

void
create()
{
    ::create();
    set_short("unholy guild shop");
#define R "%^BOLD%^%^RED%^"
    set_long(R"The ground is a mere finger of the great demon.  Muddy dirt "
      R"makes up the walls and the area is quite small.  The "
      R"\"ceiling\" is held up by fresh iron supports.  The message "
      R"board and main guild area is located east.");
    set_properties(([
	"light":2, "night light":2, "no attack":1, "no magic":1, 
	"no bump":1, "no steal":1, "indoors":1, "no teleport":1,
      ]));

    set_exits(([ "east" : ROOMS "unholy/hall", ]));    
}

void
reset()
{
    ::reset();
    if (!present("demon"))
	new(ROOMS "unholy/demon")->move(this_object());
}
