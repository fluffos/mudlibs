
/* 	The Jewelry Shop where players can customize and buy 
	wedding and engagement rings.
				- Minx Sept. 28, 1995           */

#include <room.h>
#include "weddings.h"

string view_short, view_long;
status ring_flag, metal_flag, stone_flag, short_flag, spouse_flag;
status extra_flag, inscrip_flag, choose_flag, view_flag, ordering;
int ring_type, metal_type, short_type, stone_type, extra_type, cost;
string inscription, spouse;
object orderer, ring;
do_speech();

void
create_room(){

    set(NO_PK);
    set(PREVENT_TELEPORT);	
    set_light_level(LT_LIGHTS);
    set_outdoors(WD_INDOORS);
    set_short("A jewelry shop"); 
    set_long("This jewelry shop is very elite. The rich wood paneling \
flatters the displays around the room of beautiful rings. Every ring \
made in this shop is custom made to order. There is usually a jeweler, \
named Gordon, here to answer your questions. Feel free to <ask Gordon \
about rings>."); 
    set_exits((["east":"/areas/tristeza/virtual/S10_3"]));   

    add_monster( WEDDINGS+"jeweler", "The jeweler \
strools in from a break.", 1); 	


    set_commands(([
	"order":"order_cmd",
	"choose":"choose_cmd",
	"spell":"spouse_cmd",
	"inscription":"inscrip_cmd",
	"out":"out_cmd",
	"purchase":"purchase_cmd",
	"preview":"preview_cmd",
	"erase":"reset_choices"]));

}

order_cmd(string what){

    if (!present ("jeweler",this_object())){
	this_player()->tell_me("You cannot order a ring right now. \
The jeweler is not here to take your order.");
	return 1;
    }

    if (what != "ring" && what != "a ring"){
	this_player()->tell_me("The jeweler says: Would you like \
to order a ring?");
	return 1;
    } 


    if (ordering) {
	this_player()->tell_me("The jeweler says: Could you please \
come back later. I'm with another customer right now.");
	return 1; 
    }

    ordering++;
    orderer=this_player();

    orderer->tell_me(
      "The jeweler says: I would be delighted to take your order. And who is \
going to be the lucky one getting this ring? Can you please <spell name>? \
For example: 'spell kelgath'.");

    return 1;
}

choose_cmd(string what){

    if (this_player() != orderer || !ordering) { 
	this_player()->tell_me("The jeweler points out that you \
must first order a ring, before you can choose anything.");
	return 1;
    }

    if (!what){
	orderer->tell_me("The jeweler says: Excuse me? I didn't \
get that.");
	return 1;
    }

    if (what == "wedding" || what == "engagement" || 
      what == "friendship"){
	if (what == "wedding") ring_type=1;
	if (what == "engagement") ring_type=0;
	if (what == "friendship"){
	    if (orderer != find_player("minx")){
		TP->tell_me("Please mail Minx if you \
would like a friendship ring. MINX IS THE ONLY ONE I CAN GIVE A \
FRIENDSHIP RING TO. After which she may give it to you.\n\
The jeweler then mumbles something about rules are rules.");
		return 1;
	    }
	    ring_type=2;
	}

	ring_flag++;
	do_speech();
	return 1;
    }

    if (what == "gold" || what == "silver" || 
      what == "platinum" || what == "mithril" ||
      what == "white" || what == "onyx" ){
	if (what == "gold") metal_type=0;
	if (what == "silver") metal_type=1;
	if (what == "platinum") metal_type=2;
	if (what == "mithril") metal_type=3;
	if (what == "white") metal_type=4;
	if (what == "onyx") metal_type=5;
	metal_flag++;
	do_speech();
	return 1;
    }

    if (what == "none" || what == "diamond" || what == "sapphire" || 
      what == "ruby" || what == "emerald" || what == "pearl" || 
      what == "opal" || what == "chips" || what == "two" || 
      what == "mysterious"){
	if (what == "none") stone_type=0;
	if (what == "diamond") stone_type=1;
	if (what == "sapphire") stone_type=2;
	if (what == "ruby") stone_type=3;
	if (what == "emerald") stone_type=4;
	if (what == "pearl") stone_type=5;
	if (what == "opal") stone_type=6;
	if (what == "chips") stone_type=7;
	if (what == "two") stone_type=8;
	if (what == "mysterious") stone_type=9;
	stone_flag++;
	do_speech();
	return 1;
    } 

    if (what == "beautiful" || what == "splendid" || 
      what == "gorgeous" || what == "breath taking" || 
      what == "exquisite" || what == "radiant" || 
      what == "brilliant" || what == "divine" || 
      what == "marvelous" || what == "impressive" || 
      what == "elegant" || what == "artistic" || 
      what == "charming"){
	if (what == "beautiful") short_type=0;
	if (what == "splendid") short_type=1;
	if (what == "gorgeous") short_type=2;
	if (what == "breath taking") short_type=3;
	if (what == "exquisite") short_type=4;
	if (what == "radiant") short_type=5;
	if (what == "brilliant") short_type=6;
	if (what == "divine") short_type=7;
	if (what == "marvelous") short_type=8;
	if (what == "impressive") short_type=9;
	if (what == "elegant") short_type=10;
	if (what == "artistic") short_type=11;
	if (what == "charming") short_type=12;

	short_flag++;
	do_speech();
	return 1;
    }

    if (what == "soul" || what == "respect" || what == "only" || 
      what == "gift" || what == "divide" || what == "heart" ||
      what == "friend" || what == "bond" ){
	if (what == "soul") extra_type=0;
	if (what == "respect") extra_type=1;
	if (what == "only") extra_type=2;
	if (what == "gift") extra_type=3;
	if (what == "divide") extra_type=4;
	if (what == "heart") extra_type=5;
	if (what == "friend") extra_type=6;
	if (what == "bond") extra_type=7;
	extra_flag++;
	do_speech();
	return 1;

    } 

    orderer->tell_me("The jeweler says: Excuse me? I didn't \
get that.");
    return 1;
}

spouse_cmd(string what){

    if (this_player() != orderer || !ordering) { 
	this_player()->tell_me("The jeweler points out that you \
must first order a ring.");
	return 1;
    }

    if (!what){
	orderer->tell_me("The jeweler says: Excuse me? I didn't \
get that.");
	return 1;
    }

    spouse = lower_case(what);
    spouse_flag++;
    do_speech();
    return 1;
}

inscrip_cmd(string what){

    if (this_player() != orderer || !ordering) { 
	this_player()->tell_me("The jeweler points out that you \
must first order a ring.");
	return 1;
    }

    if (!what){
	orderer->tell_me("The jeweler says: Excuse me? I didn't \
get that.");
	return 1;
    }

    if (sizeof(what) > 35){

	orderer->tell_me("The jeweler says: Your inscription is \
too long. Please pick another one.");
	return 1;
    }

    inscription = what;
    inscrip_flag++;
    do_speech();
    return 1;

}

do_speech(){

    if (!spouse_flag){
	orderer->tell_me("The jeweler says: I need you to \
<spell> the name of the person this ring will be given to. For example: \
<spell kelgath>");
	return 1;
    } 

    if (!ring_flag){
	orderer->tell_me("The jeweler says: Great. Now, would you \
like to <choose>: an <engagement> (10K gc), a <wedding> (25K gc) or a \
<friendship> (15K gc) ring.");
	return 1;
    }

    if (!metal_flag){
	orderer->tell_me("The jeweler says: Okay. What kind of \
metal would you like to <choose>: <gold> (1000 gc), <white> gold \
(1500 gc), <silver>, <platinum> (2000 gc), <mithril> (5000 gc), or \
<onyx> (800 gc)?");	
	return 1;
    }

    if (!stone_flag){
	orderer->tell_me("The jeweler says: How nice. Please, \
<choose> what kind of stone you would like. Remember, your choices are \
<none>, <diamond> (3000 gc), diamond <chips> (1000 gc), a <two> karat \
diamond (10000 gc), <sapphire> (800 gc), <ruby> (800 gc), <emerald> \
(1000 gc), <pearl> (1200 gc), <opal> (1200 gc) or <mysterious> \
(1000 gc).");
	return 1;
    }

    if (!short_flag){
	orderer->tell_me("The jeweler says: Sounds wonderful. \
What kind of short description would you like to <choose>: <beautiful>, \
<splendid>, <gorgeous>, <breath taking>, < exquisite>, <radiant>, \
<brilliant>, <divine>, <marvelous>, <impressive>, <elegant>, <artistic>, \
or <charming>.");
	return 1;
    }

    if (!extra_flag){
	orderer->tell_me("The jeweler says: Now time to pick the \
overall appearance. Please <choose> from:\n\
This ring represents the promise between two souls to live life together \
as one united <soul>.\n\
This ring represents the love and <respect> between husband and wife.\n\
This ring represents the <only> happiness in life, to love and to be \
loved.\n\
This ring represents the love, which above all, is the <gift> of one's \
self to another.\n\
To get the full value of love, you must have someone to \
<divide> it with. This ring represents half of such a division.\n\
This ring may be treasured above all other material possessions, but, \
more importantly, it represents the love in one's <heart>, which is \
treasured above all else.\n\
This ring represents a strong <friend>ship bond. Shall it never be \
severed, through good times and bad, through laughter and tears.\n\
This ring symbolizes the <bond> of friendship between two individuals. \
It is crafted of precious metals and like a strong friendship is \
tempered and forged, tried and true and shines with an inner light.");
	return 1;
    }

    if (!inscrip_flag){
	orderer->tell_me("The jeweler says: Well, we're almost \
done here. Finally, what would you like the <inscription> to be? \
For example: 'inscription My love forever'.");
	return 1;
    }

    choose_flag ++;
    if (ring_type == 0) cost = 10000;
    if (ring_type == 1) cost = 25000;
    if (ring_type == 2) cost = 15000;
    if (metal_type == 0) cost += 1000; 
    if (metal_type == 2) cost += 2000;
    if (metal_type == 3) cost += 5000;
    if (metal_type == 4) cost += 1500;
    if (metal_type == 5) cost +=  800;
    if (stone_type == 1) cost += 3000;
    if (stone_type == 2) cost += 800;
    if (stone_type == 3) cost += 800;
    if (stone_type == 4) cost += 1000;
    if (stone_type == 5) cost += 1200;
    if (stone_type == 6) cost += 1200;
    if (stone_type == 7) cost += 1000;
    if (stone_type == 8) cost += 10000;
    if (stone_type == 9) cost +=  1000;

    orderer->tell_me("The jeweler says: I think that's it. I have all \
the information I need. At this point you can <preview> what the ring \
will look like, <purchase> the ring, or <erase> your choices and start all \
over again.\n\
The jeweler totals up the cost and says: Your total is "+cost+". If you \
do not have the money with you, you will have to come back later and \
place you order again. I cannot keep your order for you.");

    return 1;
}

preview_cmd(string what){

    if (this_player() != orderer || !ordering) { 
	this_player()->tell_me("The jeweler points out that you \
must first order a ring, before you can preview one.");
	return 1;
    }

    if (!choose_flag){
	this_player()->tell_me("You must finish customizing \
your ring first. After doing so you can preview the ring.");
	return 1;
    }

    if (!view_flag){
	ring = clone_object(WEDDINGS+"ring");
	ring -> set_ring(ring_type, metal_type, short_type, 
	  stone_type, extra_type, spouse, inscription);
	ring->create_ring();
	view_flag++;
    }

    this_player()->tell_me("The jeweler shows you what your ring \
would look like:  \n\
Your beloved is recoreded as: "+capitalize(spouse)+".\n\
The short description is: "+(string)ring->query_short()+".\n\
The long description is:  "+(string)ring->query_long());
    this_player()->tell_me("The jeweler says: Now would you like to \
purchase this ring? If you remember the choices feel free to choose \
again. If you would like to start all over, please <erase> your current \
choices and <order> again.");
    return 1;

}

reset_choices(){

    if (view_flag){
	this_player()->tell_me("The jeweler crumbles up your \
order and tosses it in the trash.");
    }
    ordering = 0;
    orderer = 0;
    ring_flag = 0;
    metal_flag = 0;
    stone_flag = 0;
    short_flag = 0;
    extra_flag = 0;
    spouse_flag = 0;
    inscrip_flag = 0;
    choose_flag = 0;
    view_flag = 0;
    return 1;
}

purchase_cmd(string what){

    if (!present ("jeweler",this_object())){
	this_player()->tell_me("You cannot purchase a ring right \
now. The jeweler is not here to take your order.");
	reset_choces();
	return 1;
    }

    if (this_player() != orderer || !ordering) { 
	this_player()->tell_me("The jeweler points out that you \
must first order a ring, before you can purchase one.");
	return 1;
    }

    if (cost > (int) orderer->query_money()){
	orderer->tell_me("The jeweler gives you the evil eye and \
says: You don't seem to have enough money. You'll have to come back \
when you are better prepared and start all over again.");
	reset_choices();
	return 1;
    } 


    this_player()->add_money(-cost);
    view_flag = 0;
    write_file(WEDDINGS+"ring_log", (string)orderer->query_real_name()+
      ": "+ring_type+"#"+metal_type+"#"+short_type+"#"+stone_type+
      "#"+extra_type+"#"+spouse+"#"+inscription+"\n");	
    ring = clone_object(WEDDINGS+"ring");
    ring -> set_ring(ring_type, metal_type, short_type, 
      stone_type, extra_type, spouse, inscription);
    move_object(ring, orderer);

    orderer->tell_me("You have just purchased a very wonderful ring. \
You will be able to give this ring to your specified spouse. And once you \
have done so, they will have the ring with them forever. To do this you \
must use the <present ring> command.");

    orderer->save();
    reset_choices();
    return 1;
}

out_cmd(){

    if (this_player() == orderer){
	reset_choices();
	return 0;
    }
}




