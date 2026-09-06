// A Tinning Kit by Graah
// 300395 updated this too... Haw
// And once again, Nov 8, 95 -Kelgath

#include <treasure.h>

#include <generic_items.h>

#define TP this_player()
#define HIS (TP->Possessive())
#define HIM (TP->Objective())

object material;
int times;

void
create_treasure()
{
    set_name("tinning kit");
    set_id(({ "tinning", "kit" }));
    set_short("Magic Metalworks Inc. Tinning Kit");
    set_long(
      "This is a standard Tinning Kit of Magic Metalworks Inc. It looks like a \
combination of a meat-minching machine and a squeezer. There is an opening \
on the top of the thing, where you are supposed to pack the sliced materials. \
After that you must rotate a crank on the side of the machine. After enough \
material has been inserted a tin is magically created and comes out from \
the side opening. You can start this process by typing 'tin [x]', \
where [x] is the material used (usually a corpse).\n");
    set_weight(3);

    times = 15 + random(8); /* From 15 to 22 tins */
    set_value(400 + times * 49 + random(10));
}

void
init_treasure()
{
    add_action("tin","tin");
    add_action("stop","stop");
}

status
stop(string arg)
{
    if (arg != "tinning" && arg != "tin") return 0;

    if (!material)
	return notify_fail("But you're not tinning anything at the moment!\n"),0;

    remove_call_out("tin2");
    material = 0;

    TP->tell_me("Ok. Stopped tinning.");
    environment(TP)->tell_here(TP->query_name()+" stopped working with "+HIS+
      " tinning kit.",TP);

    return 1;
}

status
tin(string arg)
{
    string tmp;

    if (!arg)
	return notify_fail("What did you want to tin?\n"),0;

    if (material)
	return notify_fail("You are already making one tin. \
Type 'stop tinning' to stop that.\n"),0;

    arg = lower_case(arg);

    material = present(arg, environment(TP));

    if (material == TP || (!material && (arg == "me" || arg == "myself"))) {
	TP->tell_me("What?!??! Make a tin of yourself? *LAUGH*");
	environment(TP)->tell_here(TP->query_name()+" tries to preserve "+HIM+
	  "self into a tin, but fails.",TP);
	material = 0;
	return 1;
    }

    /* Must not carry the corpse; too hard to check weights... */
    if (!material) {
	material = present(arg, TP);
	if (material) {
	    notify_fail("Place " + material->short() + " on the ground first.\n");
	    material = 0;
	    return 0;
	}
    }

    if (!material)
	return notify_fail("You can't see any "+arg+" nearby.\n"),0;

    if (living(material)) {
	TP->tell_me(material->query_name()+" doesn't let you do that!");
	environment(TP)->tell_here(TP->query_name()+
	  " tries to preserve "+material->query_name()+
	  " into a tin, but the latter doesn't allow it.",({material,TP}));
	material->tell_me(TP->query_name() +  " tries to feed you into " +
	  HIS + " tinning kit!");
	material = 0;
	return 1;
    }

    /* Todo: tinning other foodstuff? */

    if (sscanf(object_name(material), "lib/corpse#%s", tmp) != 1) {
	notify_fail(
	  "Your tinning kit whispers: That material doesn't qualify for tinning.\n");
	material = 0;
	return 0;
    }

    if (material->query_decay() < 2) {
	notify_fail("Those remains are too old to be preserved.\n");
	material = 0;
	return 0;
    }

    tmp = (string)material->query_short();
    if (!tmp) tmp = "something invisible";

    TP->tell_me("Ok. You start to cram " + tmp + " into the tinning kit.");
    environment(TP)->tell_here(TP->query_name() + " starts packing " + tmp +
      " into " + HIS + " tinning kit.",TP);

    call_out("tin2",5);// delay was 7 ... a bit long
    return 1;
}

void
tin2()
{
    object tin, *inv;
    string sh, tmp1;
    int i;

    if (!material) {
	TP->tell_me("You've lost your raw materials somehow. Tinning stopped.");
	return 0;
    }

    if (environment(TP) != environment(material)) {
	TP->tell_me("Hey, you cannot see your raw materials around here \
any more.\nTinning process stopped.");
	material = 0;
	return 0;
    }

    TP->tell_me("Ok, you have now packed the whole " + 
      material->query_short() + " into the tinning kit.");
    environment(TP)->tell_here(TP->query_name() + " has crammed the whole " + 
      material->query_short()+" into "+HIS+" tinning kit.",TP);

    TP->tell_me("You wind the crank a few more rounds, and...",1);

    sh = capitalize((string)material->query_orig_name());

    if (sscanf(sh, "Ghost of %s", tmp1) == 1) sh = tmp1;

    switch(random(7)) {
    case 0: sh += " meat"; break;
    case 1: sh += " soup"; break;
    case 2: sh = "pickled " + sh; break;
    case 3: sh += " jam"; break;
    case 4: sh = "marinaded " + sh; break;
    case 5: sh = "sour " + sh; break;
    default: sh = "deep fried " + sh; break;
    }

    /* Create the tin */
    tin = clone_object(GENERIC_TIN);
    tin->set_short("Tin of " + sh);
    tin->set_long("This is a normal tin of " + sh + ", made with the \
Magical Metalworks Inc. Tinning Kit. This kind of preserved food never \
spoils unless opened.");
    tin->set_id(({lower_case(sh),"tin"}));

    i = (int)material->query_orig_level();
    i -= -(4 * ((int)material->query_decay() - 5));
    if ((string)TP->query_race() == "hobbit") i+=random(i); // hobbit bonus.
    tin->set_tin_level(i);

    /* Move material's inventory outside it */
    inv = all_inventory(material);
    for (i = 0; i < sizeof(inv); i++)
	if (!inv[0]->drop()) move_object(inv[i], environment(material));

    destruct(material);

    material = 0;

    TP->tell_me("The tin is ready!");

    if (!TP->add_weight(tin->query_weight())) {
	move_object(tin, environment(TP));
	TP->tell_me("Oops, you fumbled with the " + tin->query_short() +
	  ". Dropped.");
	environment(TP)->tell_here(TP->query_name() + " fumbled with the " + 
	  tin->query_short() + " and drops it.", TP);
    } else {
	move_object(tin, TP);
	TP->tell_me("You get the " + tin->query_short() + ".");
	environment(TP)->tell_here(TP->query_name() + " gets a " + 
	  tin->short() + ".", TP);
    }

    /* Add a big bonus for hobbits using this.... Their supposed to be 
       super dextrous, so wouldn't break it as often, plus, they need the
       food in order to be a viable choice for race. */

    if ((string)TP->query_race() != "hobbit" || !random(5)) times--;

    if (times < 0) {
	TP->tell_me("Your tinning machine is a wreck. It falls into pieces.");
	environment(TP)->tell_here(TP->query_name() + 
	  "'s tinning machine falls into pieces.",TP);
	TP->add_weight(-(query_weight()));
	destruct(this_object());
	return;
    } else if (times < 2)
	TP->tell_me("Your tinning machine is almost gone. \
Perhaps it can do a one more tin.");
    else if (times < 4)
	TP->tell_me("Your tinning machine is in a very poor condition.");
    else if (times < 6)
	TP->tell_me("Your tinning machine starts to look much used.");

    set_value(377 + times * 49);

    return;
}
