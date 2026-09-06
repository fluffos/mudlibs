/* This is the master wedding/engagement ring file by Minx

	*These rings are to be purchase in the jewelry shop
	(also coded by Minx). The rings are customizable, yet
	the players can do the customizing themselves with
	a minimal amount of int_arg.
	*The rings are to be purchased for the loved one not
	for themselves.
	*The prices and a description of the rings can be found
	either here, in the jeweler, or in the shop.
	*The only commands available at this time are: the two
	person channel, the showoff command (shows the ring off
	to everyone in the room), and the divorce command
	(destroys one's ring). Sooner or later I would like to
	add a few emotes.
	*I hope all this is pretty self explainatory... if not
	I can write more later.
					-Minx Sept 30, 1995

	Friendship rings added by Minx Jan. 7, 1995

*/

#include <treasure.h>
#include "weddings.h"

void create_ring();
void set_ring(int a, int b, int c, int d, int e, string f, string g);

int giveable, short_type, ring_type, metal_type, stone_type, extra_type;
string *metal, *type, *short, *extra_descrp, *stone_descrp, *look_descrp;
string spouse, inscription;
object beloved;

//Seems to be the only way I can get the ring to call int_arg *boggle*

void
create_treasure(){
    call_out("create_ring",1);
}

void
create_ring(){
    //Enter messages...
    if (giveable != 0){
	if ((beloved=find_player(spouse))){
	    beloved->tell_me("You get a warm and fuzzy \
feeling as you realize that "+(string)this_player()->query_name()+" has \
just entered the game.");
	    this_player()->tell_me("You get a warm and \
fuzzy feeling as you realize "+capitalize(spouse)+" is here.");
	}
	if (!beloved){
	    this_player()->tell_me("You feel a bit sad, \
because "+capitalize(spouse)+" isn't here.");
	}
    }

    short=({"a beautiful","a splendid","a gorgeous","a breath taking", 
      "an exquisite", "a radiant","a brilliant", "a divine","a marvelous","an impressive",
      "an elegant", "an artistic","a charming"});

    type=({"engagement","wedding","friendship"});

    metal=({"brilliant gold","pure silver","impressive platinum",
      "the finest mithril","brilliant white gold","the finest onyx"});

    stone_descrp=({" "," A rainbow of colors dance before your \
eyes, as the large diamond setting sparkles in the light. ",
      " The deep blue sapphire setting sparkles in the light. ", " The perfect \
deep red ruby stone catches your eye immediately. ", " The rich emerald \
stone setting is both impressive and radiant. ", " The pearl setting in \
the center of the ring, is both an unusual and elegant touch. ", " The \
opal gem setting is perfect and beautiful in every way. ", " There are \
several fine diamond chips set into the band, creating an intricate \
design. ", " The two karat diamond is quite impressive and awesome, with \
its array of reflected rainbow colors. ", " The stone embedded at the \
top of the ring looks both mysterious and unknown. The stone \
pulsates light from its origin, as a star would emit light. ", " This \
extraordinary rings looks as if it is made of pure white light. Its white \
light glows brightly and warmly. The power of this ring creates a warmth \
which penetrates through ones very heart and soul. "});

    extra_descrp=({"This ring represents the promise between two \
souls to live life together as one united soul.","This ring represents \
the love and respect between husband and wife.","This ring represents \
the only happiness in life, to love and to be loved.", "This ring \
represents the love, which above all, is the gift of one's self to \
another.", "To get the full value of love, you must have someone to \
divide it with. This ring represents half of such a division.",
      "This ring may be treasured above all other material possessions, but, \
more importantly, it represents the love in one's heart, which is \
treasured above all else.", "This ring represents a strong friendship \
bond. Shall it never be severed, through good times and bad, through \
laughter and tears.", "This ring symbolizes the bond of friendship between \
two individuals. It is crafted of precious metals and like a strong \
friendship is tempered and forged, tried and true and shines with an \
inner light."});

    look_descrp=({"sparkles as the light catches it just right.", 
      "casts a rainbow of light around the room.", "casts beautiful \
blue twinkles around the room.", "casts radiant deep red glimpses of \
light around the room.", "reflects rich hues of green around the room",
      "is truely amazing.","is breath taking.", "sparkles as the light \
catches it just right.", "casts an almost blinding rainbow of light \
around the room.", "pulsates a strange mysterious light.", "glows with an \
extraordinary white light."});

    set_short(capitalize(short[short_type])+" "+type[ring_type]+" ring \
(worn)");
    set_long("This "+type[ring_type]+" ring is made of "
      +metal[metal_type]+"."+stone_descrp[stone_type]+
      extra_descrp[extra_type]+" There is an inscription on the inside \
of the ring, which reads: \n"+inscription);

    set_id(({"ring",type[ring_type]+" ring", type[ring_type] }));
    set_weight(0);
    set_value(0);

}

void
init_treasure(){
    add_action("present_cmd","present");
    if ( ring_type < 2 ) add_action("rich_cmd","rich");
    add_action("showoff_cmd","showoff");
    add_action("destroy_cmd","divorce");
    add_action("help_cmd","help");
    if (this_player()->query_coder_level())
	add_action("replace_cmd","replace");
}


status
present_cmd(string what){
    object here, who;

    if (what != "ring") {
	this_player()->tell_me("Present what?");
	return 1;
    }

    if (giveable != 0){
	return notify_fail("You can only present this \
ring once.\n"),0;
    }

    if (!(who=find_player(spouse))){
	this_player()->tell_me(capitalize(spouse)+" isn't here. Try \
again later.");
	return 1;
    }


    this_player()->tell_me("You present a beautiful ring \
to your true love, "+capitalize(spouse)+".");
    here=environment(this_player());
    here->tell_here(
      (string)this_player()->query_name()+" takes out "+short[short_type]+
      " "+type[ring_type]+" ring and presents it to "+this_player()->Possessive()+
      " one true love, "+capitalize(spouse)+".",({this_player(),beloved}));

    spouse = (string)this_player()->query_real_name();
    move_object(this_object(),who);
    who->tell_me(
      (string)this_player()->query_name()+" gives you "+short[short_type]+
      " "+type[ring_type]+" ring. Try <help ring> to get a list of current \
command options.");
    giveable++;
    who->save();
    return 1;
}

status
help_cmd(string what) {
    if (what != "ring") return 0;

    if ( ring_type == 0 || ring_type == 1 ){
	this_player()->tell_me("The following commands are \
currently available: \n\
<present ring> = gives the ring to your  (can only be done once)\n\
<rich> message = sends a message to your partner\n\
<showoff> = shows off your ring to everyone in the room\n\
<showoff name> = shows off your ring only to name\n\
<divorce> = destroys your ring, but not your partner's ring\n\
Hopefully, more commands are on the way.\n\
			Best Wishes, Minx");
	return 1;
    }
    this_player()->tell_me("The following commands are \
currently available for the friendship rings: \n\
<present ring> = presents the ring to your friend \
(can only be done once)\n\
<showoff> = shows off your ring to everyone in the room\n\
<showoff name> = shows off your ring only to name\n\
<divorce> = destroys your ring\n\
			Best Wishes, Minx");
    return 1;
}

//The Channel....
status
rich_cmd(string mess){
    object who;

    if(!(who=find_player(spouse))){
	this_player()->tell_me(capitalize(spouse)+" \
isn't in the game right now. Try later.");
	return 1;
    }
    if (!interactive(who)){
	this_player()->tell_me(capitalize(spouse)+" is linkdead \
right now and cannot hear you.");
	return 1;
    }

    this_player()->tell_me("Ok.");
    who->tell_me("<*<Ring>*> "+
      capitalize((string)this_player()->query_real_name())+
      " : "+mess);

    return 1;
}


status
showoff_cmd(string who){
    object here, WHO;

    here=environment(this_player());
    WHO=find_player(who);
    if (!who){
	here->tell_here(
	  (string)this_player()->query_name()+" shows you "+short[short_type]+
	  " "+type[ring_type]+" ring.",this_player());
	here->tell_here((string)this_object()->query_long(),
	  this_player());
	this_player()->tell_me("You show off "
	  +short[short_type]+" "+type[ring_type]+" ring to everyone in the room.");
	return 1;
    }

    if (!present(who,here)){
	this_player()->tell_me(capitalize(who)+" isn't in the \
room with you and cannot see your ring.");
	return 1;
    }

    WHO->tell_me(
      (string)this_player()->query_name()+" shows you "+short[short_type]+
      " "+type[ring_type]+" ring.");
    WHO->tell_me((string)this_object()->query_long());
    this_player()->tell_me("You show off "
      +short[short_type]+" "+type[ring_type]+" ring to "+capitalize(who)+".");
    return 1;
}

status
destroy_cmd(){
    this_player()->tell_me("You have just destroyed your \
ring. Better luck next time.");
    destruct(this_object());
    return 1;
}

int get() { return 1; }
int drop() { return 1; }

string
extra_look(){
    return (string) environment()->query_name()+"'s ring "+
    look_descrp[stone_type];
}

string
query_auto_load(){
    return WEDDINGS+"ring:"+ring_type+"#"+
    metal_type+"#"+short_type+"#"+stone_type+"#"+extra_type+"#"+
    spouse+"#"+inscription+"#"+giveable;

}

void
set_ring(int a, int b, int c, int d, int e, string f, string g) {
    ring_type = a;
    metal_type = b;
    short_type = c;
    stone_type = d;
    extra_type = e;
    spouse = f;
    inscription = g;
}

void
init_arg(string arg) {
    if (!arg) this_player()->tell_me("Oh no. Something is wrong \
with your wedding or engagement ring. Better contact a coder.");

    sscanf(arg, "%d#%d#%d#%d#%d#%s#%s#%d",
      ring_type, metal_type, short_type, stone_type, extra_type, spouse,
      inscription, giveable);
}

status
replace_cmd(string xx){
    string who;	// the owner/buyer of the ring
    int cost;   	// cost will be 0 if it is a replacement ring
    object owner;

    sscanf(xx, "%s %d", who, cost);
    find_player("minx")->tell_me(who+","+cost);

    if (this_player() != find_player("minx")) return 0;

    owner = find_player(who);

    if ( !owner ) {
	this_player()->tell_me("That person is not in the \
game right now.");
	return 1;
    }

    if (giveable != 0){
	return notify_fail("You can only present this \
ring once.\n"),0;
    }

    this_player()->tell_me("You have just given a ring to "
      +capitalize(who)+".");

    move_object(this_object(),owner);
    owner->add_money(-cost);
    owner->tell_me("Minx takes "+cost+" gold coins from you to pay \
for the new ring.");
    owner->tell_me("Minx gives you "+short[short_type]+
      " "+type[ring_type]+" ring. Try <help ring> to get a list of current \
command options.");
    if (cost == 0) giveable++;
    owner->save();
    return 1;

}
