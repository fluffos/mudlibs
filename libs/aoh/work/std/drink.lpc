/*
 * 1.1: no more cloning!
 * 1.2: several bugs fixed (with the aid of Jhary, Mutabor, Pepel, Pumuckel
 *      and Sique)
 * [softbyte] 29mar97: Added NotifyDrink
 * [mica] 14may97: Added drink from, drink x from y
 *
 * This piece of code defines a generic bottled drink object. The empty
 * bottle can be refilled in a room which defines the property
 *	"DrinkRefill"
 * which should be a string defining the liquid which can be refilled in
 * that room.
 *
 * An example of a room which allows to refill empty bottles is given in
 *	/d/archwiz/common/health/exroom1.c
 *
 * To set the drink up, you have to call the following functions (most of
 * them are optional) in this order:
 *
 * void Set_Drink_Name(string liquid_desc)
 *	sets name of drink (e.g. "firebreather")
 *
 * string SetFoodMsg1(string msg1)			[optional]
 *	sets the message which the user gets when drinking
 * string SetFoodMsg2(string msg2)			[optional]
 *	sets the message which the room gets when the user consumes the drink
 * int SetFoodAlc(int strength)				[optional]
 *	sets alcoholic strength of the drink
 * int SetFoodHeal(int heal)				[optional]
 *	sets how many HP the user gets instantly when consuming the drink
 * int SetValue(int value)				[optional]
 *	set value of drink (without vessel)
 *
 * string Set_Vessel_Name(string vessel_desc)
 *	sets name of vessel
 * string Set_Vessel_Value(int value)
 *	sets value of empty vessel
 * int Set_Vessel_Weight(int weight)
 *	sets how heavy the vessel is
 * int Set_Vessel_Volume(int vol)
 *	sets the volume (in ml) the vessel contains (or may contain). This
 *	together with the alcohol content directly determines the soak values.
 *
 * Examples:
 *
 * 1. A full bottle of firebreather.
 *
 * The bottle will show up as "a bottle of firebreather". It features a long
 * description. Drink messages are the defaults, that is "You drink a
 * firebreather." and "[name] drinks a firebreather.". The bottle has a volume
 * of 200 ml, but since the firebreather is a strong alcoholic beverage, its
 * soak is only 1. (The same amount of water would have a soak of 14.) The
 * weight of the empty bottle is 500 grams, its worth is 10 coins. The price
 * of the full drink is	calculated automatically.
 *
 * inherit "std/drink";
 * void create() {
 *	::create();
 *	Set_Drink_Name("firebreather");
 *	SetFoodStrength(25);
 *	SetFoodHeal(12);
 *	Set_Vessel_Name("bottle");
 *	Set_Vessel_Volume(200);
 *	Set_Vessel_Weight(500);
 *	Set_Vessel_Value(10);
 *	SetLong("This bottle is filled with fine 25-year-old firebreather.\n");
 * }
 *
 * 2. The same bottle when it is emptied.
 *
 * inherit "std/drink";
 * void create() {
 *	::create();
 *	Set_Vessel_Name("bottle");
 *	Set_Vessel_Volume(200);
 *	Set_Vessel_Weight(500);
 *	Set_Vessel_Value(10)
 *	fill_vessel(0);
 *	SetLong("This bottle was filled with firebreather once.\n");
 * }
 */

inherit "std/thing";

#include <health.h>
#include <properties.h>
#include <config.h>
#include <search.h>
#include <classes.h>

#define PL this_player()
#define TP this_player()
#define TO this_object()

/* This should probably move to <health.h> */
#define DRINKLIST "/log/DRINKLIST"
#define DRAUGHT	  250		/* how many ml can be drunken with one sip */

/* drink variables */
int	dvolume;	/* actual volume of drink */
int	alc, heal;
string	dname;		/* Name of liquid */
/* vessel variables */
int	vvalue, vweight, vvolume;
string	vname;		/* Name of vessel */
/* other variables */
string	kind, msg1, msg2, long_desc;

/* function declaration */
void	empty_vessel();
int	fill_vessel(int n);
void	log_drink(string me);

void create() {
    string *myname;

    /* log new stuff */
    if (sizeof(myname = explode(object_name(this_object()), "#")) == 1)
        log_drink(myname[0]);

    if (::create()) return;	/* what is this good for? */

    kind = "drink";
    alc  = heal = 0;
    dvolume = 0;
    vname   = "bottle";
    vvolume = 500;
    vweight = 500;
    vvalue  = 10;
    SetIds(({C_DRINK,C_VESSEL}));

    Set(P_HELP_MSG,
"A vessel to hold a drink. Simply drink it to quench your thirst.\n"
"If there is liquid in your vicinity, refilling the vessel might work, too.\n"
       );
}

/*
 * public functions
 */
void init()
{
    ::init();
    add_action("_drink","drink");
    add_action("_refill","refill");
    add_action("_refill","fill");
}

/*********************************************
 * Built-in properties
 */
string SetFoodKind(string str)	{ return kind = str; }
string QueryFoodKind()		{ return kind; }
string SetFoodMsg1(string str)	{ return msg1 = str; }
string QueryFoodMsg1()		{ return msg1; }
string SetFoodMsg2(string str)	{ return msg2 = str; }
string QueryFoodMsg2()		{ return msg2; }
/* I think this is not optimal --- Organimedes */
string SetLong(string desc)	{ return long_desc = desc; }
varargs string QueryLong() {
    if (!dvolume) return("An empty "+vname+".\n");
    else if (long_desc && long_desc != "") return(long_desc);
    else return ("This "+vname+" is filled with "+dname+".\n");
}
int SetFoodAlc(int n)		{ return alc = n; }
int QueryFoodAlc()		{ return alc; }
int SetFoodHeal(int n)		{ return heal = n; }
int QueryFoodHeal()		{ return heal; }

/****************************************************
 * the following properties cannot be set directly
 */
varargs string QueryShort() {
    if (!dvolume) return("a "+vname);
    else return ("a "+vname+" filled with "+dname);
}

varargs int QueryWeight()	{ return (vweight + dvolume); }

varargs int QueryValue() {
    int min_value, value;

    value = ::QueryValue();
    min_value = MIN_FOOD_COST(dvolume/14, 0, alc, heal, QueryWeight());
		/* dvolume/14 is approx. equal to soak value of liquid */
    if (value < min_value) value = min_value;
    return (value + vvalue);
}

/* QueryFoodSoak() returns the soak value of one draught */
int QueryFoodSoak() {
  int soak;

  if (dvolume < DRAUGHT)
    soak = dvolume/14;
  else
    soak = DRAUGHT/14;
  /* Was: soak = dvolume/14; bugfixed by Pumuckel & Mutabor, 9th oct. 93 */
  /* adjust: 1000 ml for about 7200 heartbeats */
  if (alc > 0) soak = soak / alc;	/* empirical adjustment */
  if (!soak) soak = 1;
  return soak;
}

/* no stuffing with this kind of drink */
int QueryFoodStuff()	{ return 0; }

/* Jhary requested these functions: */
int QueryFull()		{ return dvolume; }
int QueryMaxFull()	{ return (dvolume == vvolume); }

/****************************************************
 * new functions; with "_" to avoid built-in properties
 */
string Set_Drink_Name(string str)	{
    AddId(str); return dname = str;
}
string Set_Vessel_Name(string str)	{
    AddId(str); return vname = str;
}
int Set_Vessel_Value(int n)	{ return vvalue = n; }
int Set_Vessel_Weight(int n) 	{ return vweight = n; }
int Set_Vessel_Volume(int n) {
    if (n < 0) n = 0;
    vvolume = n;
    dvolume = n;		/* fill vessel automagically */
    return n;
}

/**********************************Action*********************************/

/* drink something */
int _drink(string str) {
    int    p_soak, p_intox, value;
    int    factor, alc_factor, old_weight;
    string p_name;
    string a,b;
    int n;

    if ( ! str )
      return notify_fail("Drink what?\n", NOTIFY_NOT_OBJ), 0;

    str = norm_id( str ); n = 0;
    if ( sscanf( str, "%s from %s", a, b ) != 2 ) {
      if ( sscanf( str, "from %s", b ) == 1 ) {
	a = dname;
	notify_fail( "Drink from what?\n", NOTIFY_NOT_OBJ );
      }
      else {
	a = str;
	b = vname;
	n = 1;
	notify_fail( "Drink what?\n", NOTIFY_NOT_OBJ );
      }
    }
    else
      notify_fail( "Drink what from what?\n", NOTIFY_NOT_OBJ );

    if ( a == "from" )
      return notify_fail( "Drink from what?\n", NOTIFY_NOT_VALID ), 0;

    if ( ( search( PL, b, SEARCH_INV_ENV|SM_OBJECT ) ) != TO )
      return 0;

    if ( a == vname )
      return notify_fail( "You cannnot drink "+add_a(a)+", try to drink from it.\n" ), 0;

    if ( a != dname ) {
      if ( ! n )
	return notify_fail( "There is no "+a+" inside the "+b+".\n",
			    NOTIFY_NOT_OBJ ), 0;
      else
	return 0;
    }

    if (environment() != PL)
      return notify_fail("You have to get it first!\n", NOTIFY_NOT_VALID ), 0;

    if (dvolume <= 0) {
	notify_fail("The "+vname+" is empty!\n");
	return 0;
    }

    p_intox = ({int})PL->Query(P_ALCOHOL);
    p_soak  = ({int})PL->Query(P_DRINK);
    p_name  = ({string})PL->QueryName();
    if (dvolume - DRAUGHT <= 0)
	factor = 1000;
    else
	factor = DRAUGHT * 1000 / dvolume;	/* avoid rounding errors */
    alc_factor = alc * factor / 1000;
    if ((p_soak + QueryFoodSoak() <= ({int})PL->Query(P_MAX_DRINK)) &&
	(p_intox + alc_factor <= ({int})PL->Query(P_MAX_ALCOHOL))) {

	if (msg1 && msg1 != "")
	    write(msg1+"\n");
	else
	    write("You drink some "+dname+".\n");

	if (msg2 && msg2 != "")
	    say(p_name + " " + process_string(msg2)+"\n");
	else
	    say(p_name + " drinks some " + dname + ".\n");

	/* remember weight before drinking: */
	old_weight = QueryWeight();

	PL->AddDrink(QueryFoodSoak());
	PL->AddAlcohol(alc_factor);
	PL->Heal(heal*factor/1000);

        value = QueryValue();
	SetValue(value - value*factor/1000);
	alc     = alc   - alc  *factor/1000;
	heal    = heal  - heal *factor/1000;
	dvolume = dvolume - DRAUGHT;
	if (dvolume <= 0) empty_vessel();

        /* Notify us that we had been drunk */
        this_object()->NotifyDrink(this_player());
	/* update weight information for environment: */
	environment()->AddWeight(QueryWeight()-old_weight);

    }
    else if (p_intox + alc_factor > ({int})PL->Query(P_MAX_ALCOHOL)) {
	write("You fail to reach the "+dname+" with your mouth!\n");
	say(p_name + " tries to drink a "+dname+" but fails.\n");
    }
    else if (p_soak + QueryFoodSoak() > ({int})PL->Query(P_MAX_DRINK)) {
	write("You can't possibly drink that much right now!\n"+
	      "You feel crosslegged enough as it is.\n");
	say(p_name + " tries to drink a "+dname+" but fails.\n");
    }

    return 1;
}

/* refill vessel */
int _refill(string str) {
    object room;
    string empty_vessel, liquid;

    if (!str || sscanf(str,"%s with %s",empty_vessel,liquid) != 2) {
	notify_fail("Refill <vessel> with <liquid>.\n");
	return 0;
    }
    if (present(empty_vessel,PL) != this_object()) {
	notify_fail("You don't have a "+empty_vessel+".\n");
	return 0;
    }
    if (dvolume > 0 && (lower_case(dname) != lower_case(liquid))) {
	notify_fail("You can't mix different liquids.\n");
	return 0;
    }

    room = environment(PL);
    if (lower_case(({string})room->Query(P_REFILL)||"") != lower_case(liquid)
     && !present(lower_case(liquid), room)
       )
    {
	write("There is no "+liquid+" here.\n");
	return 1;
    }
    write("You fill "+QueryShort()+" with "+liquid+".\n");
    say(({string})PL->QueryName()+ " fills "+QueryShort()+" with "+liquid+".\n");

    fill_vessel(vvolume);		/* fill vessel completely */
    Set_Drink_Name(liquid);
    return 1;
}

/******* Internal procedures *********/

/*
 * make current vessel empty and give it the current values
 * of: vessel's name, weight, value and volume.
 * The user may overload a long description.
 */
void empty_vessel() {
    SetFoodMsg1("");
    SetFoodMsg2("");
    SetFoodAlc(0);
    SetFoodHeal(0);
    SetValue(0);
    fill_vessel(0);

    /* do the naming */
    SetIds(({"drink","vessel",vname}));		/* delete old ids */
    SetLong("");				/* delete old long desc */
    AddAdjective("empty");
}

/*
 * fill current vessel with a defined volume (ml)
 */

int fill_vessel(int volume) {
    SetAds(({ }));
    if (volume > vvolume)
	dvolume = vvolume;
    else if (volume > 0)
	dvolume = volume;
   else
	dvolume = 0;
    return dvolume;
}

/*
 * log drink into drinklist
 */

void log_drink(string me) {
    string list;

    if (file_size(DRINKLIST) > 0) {
	list = read_file(DRINKLIST);
	if (!sscanf(list,"%~s"+me+"%~s"))
	    write_file(DRINKLIST,me+"\n");
    }
    else
	write_file(DRINKLIST,me+"\n");
}

public string Pl_Name() { return capitalize(({string})TP->QueryName()); }
public string Pl_name() { return ({string})TP->QueryName(); }
public string Pl_Pronoun() { return capitalize(({string})TP->QueryPronoun()); }
public string Pl_pronoun() { return ({string})TP->QueryPronoun(); }
public string Pl_Possessive() { return capitalize(({string})TP->QueryPossessive()); }
public string Pl_possessive() { return ({string})TP->QueryPossessive(); }
public string Pl_Objective() { return capitalize(({string})TP->QueryObjective()); }
public string Pl_objective() { return ({string})TP->QueryObjective(); }
public string Pl_Genetive() { return capitalize(add_gen(({string})TP->QueryName())); }
public string Pl_genetive() { return add_gen(({string})TP->QueryName()); }
