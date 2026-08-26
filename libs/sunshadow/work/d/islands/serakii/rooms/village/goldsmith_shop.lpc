// Goldsmith Shop for Port Serith Institute

#include <std.h>
#include "../../serakii.h"

inherit ROOM;

void create() {
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);

    set_name("jewelers workshop");
    set_property("light",2);
set_short("%^C226%^jewe%^C220%^l%^C226%^"+
"e%^C154%^r%^C226%^s w%^C184%^o%^C226%^"+
"rks%^C220%^h%^C226%^op%^CRST%^");
set_long("The %^C226%^jeweler's %^C059%^"+
"workshop %^CRST%^is %^C214%^warm%^CRST%^, "+
"owing to the handful of %^C244%^small "+
"furnaces%^CRST%^ that stand near %^C094%^"+
"work tables%^CRST%^ covered in %^C033%^gem "+
"chips%^CRST%^ and drops of %^C244%^metal "+
"%^CRST%^yet to be scraped and collected. "+
"Jars of various %^C043%^chemicals %^CRST%^used "+
"as %^C094%^flux%^CRST%^, for %^C245%^acid "+
"etching%^CRST%^, %^C220%^oxidization %^CRST%^"+
"and %^C173%^polishing %^CRST%^litter the %^C094%^"+
"worktops%^CRST%^, along with %^C094%^vices%^CRST%^"+
", %^C059%^arms %^CRST%^with %^C247%^lenses %^CRST%^"+
"to magnify detail work, and piles of crucibles. "+
"Some %^C094%^tables%^CRST%^ have small %^C241%^horn anvils%^CRST%^ "+
"set up; one has a %^C059%^draw plate%^CRST%^ where "+
"an %^RESET%^apprentice can turn %^C245%^metal ingots%^CRST%^ "+
"into %^C227%^wire%^CRST%^; another is clear of most "+
"clutter, but coated in a %^C142%^thick wax%^CRST%^ "+
"that has designs carved into it. A %^C094%^wall of "+
"shelving%^CRST%^ and %^C246%^hooks %^CRST%^store "+
"%^C246%^tools %^CRST%^and %^C226%^materials%^CRST%^; "+
"some student projects sit neatly in %^C094%^boxes "+
"%^CRST%^there, while others litter the %^C094%^"+
"worktops%^CRST%^. The far wall has several "+
"annealed %^C244%^kilns%^CRST%^, designed to slow "+
"the %^C158%^cooling process%^CRST%^ and protect "+
"pieces from damage.\n");

    set_items(([
    ({"furnace"}) : "Small %^C242%^furnaces %^CRST%^look "+
	"like %^C095%^beehives%^CRST%^, with an opening in "+
	"the front to fill with %^C094%^fuel %^CRST%^and "+
	"a %^C242%^hole %^CRST%^in the top that jets "+
	"%^C124%^heat%^CRST%^. %^C095%^Small bellows%^CRST%^ "+
	"can be worked with one hand, while the %^C226%^"+
	"jeweler %^CRST%^guides the %^C220%^crucible %^CRST%^"+
	"or %^C242%^ingot %^CRST%^with the other.\n",
    ({"tools"}) : "There are a multitude of %^C094%^"+
	"hammers%^CRST%^, %^C059%^files%^CRST%^, %^C245%^"+
	"tongs%^CRST%^, %^C241%^chisels%^CRST%^, %^C059%^"+
	"calipers %^CRST%^and %^C142%^gagues%^CRST%^, %^C220%^"+
	"coils of wire%^CRST%^ for soldering or weaving, "+
	"%^C253%^rabbit's feet%^CRST%^ for polishing, slabs "+
	"of %^C220%^beeswax%^CRST%^, %^C111%^glass rods%^CRST%^ "+
	"for lampwork, containers of %^C242%^metal "+
	"shavings%^CRST%^ and dust to be melted down, a box "+
	"of low-value uncut %^C068%^gems%^CRST%^ to practice "+
	"engraving or cutting, and a %^C039%^rainbow%^CRST%^ "+
	"of powdered glass in jars for enamelling.\n",
    ({"projects"}) : "Examples of %^C059%^piercework%^CRST%^, "+
	"%^C172%^repousse%^CRST%^, %^C061%^chasing%^CRST%^, "+
	"%^C248%^filigree%^CRST%^, cloissone, lampwork, and "+
	"%^C062%^gemcutting%^CRST%^ fill student's "+
	"%^C094%^project boxes%^CRST%^. Items have been "+
	"etched, carved, cast, enamelled, and set with gems.\n",
({"floor","flagstone"}) : "The floor here is simple flagstone.\n",
    ]));


set_smell("default","%^C221%^The metalic scent of gold and silver mixes with chemicals and the sweet scent of beeswax.%^CRST%^");
set_listen("default","%^C241%^Most sounds are drowned out by the grand forge to the west.%^CRST%^");


   set_exits(([

          "west" : TOWN"metals_vendor",


   ]));

}
