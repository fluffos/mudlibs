#include <std.h>
inherit ROOM;
void init() {
	::init();
	add_action("cmd_rules","rules");
	add_action("cmd_fiat","fiat");
}
int cmd_rules(string str) { 
	if (str && str != "book") return 0;
        write(
	"%^BLUE%^+=+=%^BOLD%^( %^WHITE%^Rules%^BLUE%^ )%^RESET%^%^BLUE%^"
	"+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=%^RESET%^\n"
	"1) Never harm another member of this guild, or of guilds which are allied\n"
	"   with Ethereal. i.e.: The use of abilities or spells against any member\n"
	"   of Ethereal (or Ethereal Ally). \n"
	"2) Never harm other players in this realm simply because \"you can\", i.e.:\n"
	"   no bullying.  It is however acceptable to harm other players with good\n"
	"   reason. This applies to PK as well.\n"
	"3) Abide by the basic rules of PD. If for some reason you do not know the\n"
	"   rules here, type <help rules>.\n"
	"4) Do not involve Ethereal into personal altercations with players on PD.\n"
	"   i.e.: If someone referred to you as \"weak\" or  \"stupid\", or if you did\n"
	"   not like  a certain player IRL, it will not  be considered grounds for\n"
	"   you to report them to Ethereal to seek vengeance.\n"
	"5) If you are a Baby Cow, you are in Ethereal on a  trial-basis.  Do  not \n"
	"   expect  anyone  in  Ethereal  to  protect you, or to stand up for you.\n"
	"6) Do not ask for a promotion at any time.  When  the leaders of Ethereal\n"
	"   are interested in promotion someone, they will come to you.\n"
	"7) If you decide you no longer want to be a member of Ethereal,  you must\n"
	"   inform a leader before resignation.   \n"
	"%^BLUE%^+=+=+=+==+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=%^RESET%^\n\n"
	"Failure to comply with  any of these rules will lead to your eradication from\n"
	"this guild. Punishment is subject to change as the leaders see fit. Remember,\n"
	"this is an RPG, treat it as such. \n"
        );
        return 1;          
}



int cmd_fiat(string str) {
        if (!str || str != "justitia, ruat caelum") return notify_fail("fiat what?\n");
        message(
                "environment", this_player()->query_cap_name()+
                " mutters a few words, and dissapears!.",environment(this_player()), 
                ({ this_player()})
        );
        this_player()->move("/d/nopk/tirun/nranch");
	this_player()->describe_current_room(1);
        message(
                "environment", this_player()->query_cap_name()+
                " appears from nowhere.",environment(this_player()), 
                ({ this_player()})
        );
	return 1;
}
void create() {
::create();
   set_properties( ([ "light" : 1,"indoors" : 1,"no attack"   : 1,"no magic"    : 1,"no steal"    : 1,"no bump"     : 1,"no scry"     : 1,"no teleport" : 1 ]) );
}
