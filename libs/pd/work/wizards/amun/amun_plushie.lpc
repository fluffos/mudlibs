#include <std.h>

inherit OBJECT;

int cmd_pull(string);

void create() {
    ::create();
    set_name("A cuddly Amun plushie");
    set_id(({ "plushie", "a cuddly amun plushie", "amun plushie", "cuddly amun plushie", "cuddly", "cuddly amun" }));
    set_short("A cuddly Amun plushie");
    set_long("%^BOLD%^%^WHITE%^The small plushie version of Amun looks up at you and bats her eyes; sweet and innocent, she sits and plays with her shoelace. She loves to play and loves to give %^RED%^hugs%^WHITE%^.%^RESET%^");
    set_weight(1);
}

void init(){

    ::init();
    add_action("cmd_hug", "hug"); 
}

int cmd_hug(string str)
{
    string msg_tp = "";
    string msg_room = "";
    int rand = 0;

    if( !str || str != "plushie" )
	return notify_fail("What do you wish to hug?\n");

    if( this_player()->query_disable() )
	return notify_fail("The Amun plushie slaps your hand and says, 'No no!'\n");

    rand = random(50 + random(50 + random(100)));
    rand = random(7);

    msg_tp = "%^BOLD%^%^WHITE%^The Amun Plushie%^RESET%^ ";
    msg_room = this_player()->query_cap_name() + "'s Amun plushie ";

    switch( rand )
    {
    case 0:
	msg_tp = "%^BOLD%^%^WHITE%^The Amun Plushie giggles and blows you a kiss.%^RESET%^";
	msg_room = msg_tp;
	break;
    case 1:
	msg_tp = "%^BOLD%^%^RED%^The Amun Plushie votes you out of the guild!%^RESET%^";
	msg_room = msg_tp;
	break;
    case 2:
	msg_tp = "%^BOLD%^%^WHITE%^The Amun Plushie sits and plays with the %^CYAN%^bu%^MAGENTA%^tt%^GREEN%^er%^RESET%^%^MAGENTA%^fl%^BOLD%^%^YELLOW%^ie%^BOLD%^%^WHITE%^s in the grass.%^RESET%^";
	msg_room += msg_tp;
	break;
    case 3:
	msg_tp = "%^BOLD%^%^RED%^The Amun Plushie starts a guild war!%^RESET%^";
	msg_room = msg_tp;
	break;
    case 4:
	msg_tp = "%^CYAN%^The Amun Plushie asks: %^BOLD%^%^WHITE%^Should I bring back dues?%^RESET%^";
	msg_room = msg_tp;
	break;
    case 5:
	msg_tp = "%^BOLD%^%^BLACK%^The Amun Plushie slaps your wrist an makes tsking motions at you.%^RESET%^";
	msg_room += "%^BOLD%^%^BLACK%^slaps " + this_player()->query_objective() + "wrist and makes tsking motions at them.%^RESET%^";
	break;
    }

    this_player()->set_disable();

    message("info", "You hug the cuddly Amun plushie.", this_player());
    message("info", this_player()->query_cap_name() + " hugs the cuddly Amun plushie.", environment(this_player()), this_player());

    message("info", msg_tp, this_player());
    message("info", msg_room, environment(this_player()), this_player());
    return 1;
}

int query_auto_load()
{
    return 1;
}
