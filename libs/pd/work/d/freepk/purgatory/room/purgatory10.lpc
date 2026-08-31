#include <std.h>  
#include <daemons.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
    set_name("East Mortis Road");
    set_short("East Mortis Road");
    set_long("%^BOLD%^%^WHITE%^East Mortis Road\n"
      "%^BOLD%^%^BLACK%^Traveling along Mortis Road, children are playing alongside "
      "%^BOLD%^%^BLACK%^the gutters. The townspeople keep an eye out for their "
      "%^BOLD%^%^BLACK%^charges. A large stained %^RED%^r%^WHITE%^e%^RED%^d c%^WHITE%^r%^RED%^oss%^BLACK%^ hangs above a building "
      "%^BOLD%^%^BLACK%^that looks like it used to be a church. Moaning and the rare "
      "%^BOLD%^%^BLACK%^scream can be heard emerging from the old walls.  Rigor road leads back "
      "%^BOLD%^%^BLACK%^east.");
    set_night_long("%^BOLD%^%^WHITE%^West Mortis Road\n"
      "%^BOLD%^%^BLACK%^Traveling along Mortis Road, only the dumber children and "
      "%^BOLD%^%^BLACK%^parents have stayed out to this late hour. Everything is "
      "%^BOLD%^%^BLACK%^shrouded in darkness.");
    set_properties(([
	"light"       : 2,
	"night light" : 1,
	"no bump"     : 1,
	"outdoors"    : 1,
	"plain"       : 1,
	"no steal"    : 1,
      ]));
    set_exits( ([
	"west" : ROOMS"purgatory5",
	"south" : ROOMS"phosp"]) );
}   
