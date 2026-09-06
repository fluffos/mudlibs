/*
 * /lib/pub.c   - Standard inherited pub code
 *
 * -	bartender must have one of its ids as "bartender"
 * -	for now, all drinks must weigh 1 (got to fix it some day...)
 *
 */
// Modified 10.07.95 by Tommy
// Now optional argument that allows to make drinks that cannot be taken
// out from the pub, but are instantly drank. Argument added in an array
// with price, 0 if can be taken out, 1 if not.

// Change approved 10-jul-95 by Doomdark.

#include <room.h>
#include <drink_defs.h>
#include <criminal.h>



#define TP this_player()

mixed *drinks;
object bartender;	/* Monster to serve as bartender */

#define DDATA_BLOCK	8

void init_drinks() {
    /* ids, container, short, alco value, heal, cost/drink here?, long desc, drink msg */
    drinks = ({
      ({"beer"}),"bottle","Bottle of Standard Beer", 2, 1, ({12,0}),
      "This is just a normal bottle of the (boring) Standardized Beer.\n",
      "Glug-glug-glug. What a bald taste"
    });
}

/* Redefinable functions */
int
pub_open() {
    object ob;

    if (!(ob = present("bartender", this_object()))) {
	notify_fail("You can't see the bartender.\n");
	return 0;
    }

    if ((int)TP->query_crime_level() > CR_THEFT) {
	notify_fail((string)ob->query_name() +
	  " tells you: We do not trade with criminals!\n");
	return 0;
    }

    return 1;
}

string query_drink_obj_object_name() { return DRINK_FILE; }
string query_default_drink() { return "beer"; }
int check_open() { return pub_open(); }
void extra_purchase_msg() { }
void extra_handle_drink(object drink) { }

/* Modify drink cost for non-members etc. */
int modify_cost(int c) {
    int cri;

    if (!(cri = (int)TP->query_crime_level()))
	return c;
    else
	return c * cri; /* Won't normally deal with crime > 1 */
}

/* Option 1: write the list, otherwise just return it. */
string
list_drinks(int option) {
    string l,x,n; 
    int i,no;

    l = sprintf("  %-30s %s\n","Drink","Cost gc");
    no=1;
    for (i = 0; i < sizeof(drinks); i += DDATA_BLOCK) {
	if(drinks[i + 5][1]) x=" (To be drunk here.)\n";
	else x="\n";
	l += sprintf("%d. %-30s %6d %s",no , drinks[i + 2],
	  modify_cost((int)drinks[i + 5][0]), x);
	n=sprintf("%d", no);
	drinks[i]+=({n});
	no++;
    }
    if (option != 1) return l;

    TP->tell_me(l);
    return 0;
}


// Must be compatible.
void
check_drinks()
{
    int t;

    for(t=0; t<sizeof(drinks); t+=DDATA_BLOCK) 
    {
	if(!pointerp(drinks[t+5])) 
	    drinks[t+5]=({ drinks[t+5], 0 });
    }
    return;
}



void reset_room() {
    this_object()->reset_pub();
}

void create_room() {
    set_light_level(LT_LIGHTS);
    set_outdoors(WD_INDOORS);
    set(NO_CLEANUP);
    init_drinks();
    check_drinks();
    this_object()->create_pub();
    this_object()->reset_pub();
    add_command("order","order");
    add_command("buy","order");
    add_command("fill","fill");   
}


int
order(string str)
{
    string drink_name;
    object drink;
    int i, dnum, value,no_carry;

    if (!check_open()) return 0;

    if (!str) {
	notify_fail(query_verb() + " what?\n");
	return 1;
    }

    str = lower_case(str);

    dnum = -1;

    for (i = 0; i < sizeof(drinks); i += DDATA_BLOCK)
	if (member(drinks[i], str) != -1) {
	    dnum = i;
	    break;
	}

    if (dnum == -1) {
	TP->tell_me("They don't seem to have \"" + str + "\" for sale here.");
	return 1;
    }

    value = modify_cost((int)drinks[dnum + 5][0]);

    if (TP->query_money() < value) {
	TP->tell_me("That costs " + value + " gold coins, which you don't have.");
	return 1;
    }


    drink = clone_object(query_drink_obj_object_name());

    if (!drink || !drink->set_value(drinks[dnum][0] + "#" +
	drinks[dnum + 2] + "#" + drinks[dnum + 7] +
	"#" + drinks[dnum + 4] + "#" + value + "#" +
	drinks[dnum + 3])) {
	TP->tell_me("Error in creating drink.");
	destruct(drink);
	return 1;
    }

    drink->set_long(drinks[dnum + 6]);
    drink->set_id(drinks[dnum]); /* Add id's... */
    drink->set_pub();
    drink_name = (string) drink -> query_name(0, TP);
    if (!drink_name) drink_name = "something";

    extra_handle_drink(drink);

    // If drink set so that it cannot be taken out from the pub, player is
    // forced to drink it as he/she buys it.
    no_carry=(int)drinks[dnum+5][1];
    if(no_carry==1 && TP->drink_alcohol(drinks[dnum+3])) 
    {
	TP->tell_me("OK, you order "+drink_name+" and drink it.\n"+
	  drinks[dnum+7]);
	TP->heal_self(drinks[dnum+4]);
	destruct(drink);
    }
    else if(no_carry==1){
	TP->tell_me("The bartender takes your drink away and says: You seem "+
	  "to have had enough drinks already.");
	environment(TP)->tell_here("Bartender takes "+TP->query_name()+"'s glass away and says: You seem to have had enough drinks already.", TP);
	destruct(drink);
	return 1;
    }
    if (drink && !TP->add_weight((int)drink->query_weight())) {
	TP->tell_me("Oops, the " + drinks[dnum + 1] +
	  " slips through your fingers.");
	move_object(drink, environment(TP));
    }  else if(drink) move_object(drink, TP);
    TP->add_money(-value);
    TP -> tell_me(sprintf("You pay %d for %s.", value, drink_name));
    environment(TP) -> tell_here(sprintf("%s orders %s.", (string)TP->query_name(),
	drink_name), TP);
    extra_purchase_msg();

    return 1;
}


int
fill(string str) {
    string tmp1, tmp2;
    object bag, drink;
    int amount, dnum, i, value;

    if (!check_open()) return 0;

    if (!str) {
	notify_fail("Fill what (and, perhaps, with what)?\n");
	return 0;
    }

    str = lower_case(str);

    if (sscanf(str,"%s with %s",tmp1,tmp2) != 2) {
	tmp1 = str;
	tmp2 = query_default_drink();
    }

    bag = present(tmp1, TP);

    if (!bag || !bag->query_max_weight()) {
	notify_fail("Hmm...are you sure that " + tmp1 + " is a container?\n");
	return 0;
    }

    if (living(bag)) {
	notify_fail("Please! Let " + tmp1 + " do that itself...\n");
	return 0;
    }

    if (((int)bag->query_max_weight() -
	(int)bag->query_inserted_weight()) < 1) {
	TP->tell_me("I'm afraid that " + tmp1 + " is already full.");
	return 1;
    }

    dnum = -1;

    for (i = 0; i < sizeof(drinks); i += DDATA_BLOCK)
	if (member(drinks[i], tmp2) != -1) {
	    dnum = i;
	    break;
	}

    if (dnum == -1) {
	TP->tell_me("They don't seem to have \"" + tmp2 + "\" for sale here.");
	return 1;
    }
    if(drinks[dnum+5][1]) {
	TP->tell_me("That would just make a big mess.");
	return 1;
    }

    /* We assume that all drinks weigh 1  :-(... */
    amount = ((int)bag->query_max_weight() -
      (int)bag->query_inserted_weight());

    if (amount < 1 || amount > 15) {
	TP->tell_me("There's something really wrong with your container."+
	  "You should tell about this to some higher authority.");
	return 1;
    }

    TP->tell_me("Your container can hold " + amount + " pieces of that.");

    value = modify_cost((int)drinks[dnum + 5][0]);

    if (TP->query_money() < (value * amount)) {
	TP->tell_me("Such an amount of that drink costs " + (value * amount) +
	  " gold coins, and you don't have that much cash.");
	return 1;
    }

    for (i = 0; i < amount; i++) {
	drink = clone_object(query_drink_obj_object_name());

	if (!drink || !drink->set_value(drinks[dnum][0] + "#" +
	    drinks[dnum + 2] + "#" + drinks[dnum + 7] +
	    "#" + drinks[dnum + 4] + "#" + value + "#" +
	    drinks[dnum + 3])) {
	    TP->tell_me("Error in creating drink.");
	    destruct(drink);
	    return 1;
	}

	drink->set_long(drinks[dnum + 6]);
	drink->set_id(drinks[dnum]); // Let's add id's here too //Chopin
	drink->set_pub();

	bag->add_weight((int)drink->query_weight());
	move_object(drink, bag);
    }

    TP->add_money(- (value * amount));

    TP->tell_me("You fill your " + tmp1 + " with " + tmp2 + ".\n" +
      "That cost you " + (value * amount) + " coins.");

    environment(TP)->tell_here(TP->query_name() + " orders some drinks.",TP);
    extra_purchase_msg();

    return 1;
}
