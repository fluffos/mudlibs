/****************************************************************
*                                                               *
*               This is a generic torch.                        *
*	It has been modified to produce darkness		*
*                                                               *
* It has some good initializations by default.                  *
* The torch can't be sold when lighted.                         *
*                                                               *
* Version 2.0 15-mar-96                                         *
*                                                               *
* Last modifications by Germ - 15-mar-96.                       *
* Graah 24-Jun-96: Hold it! Not wield! Not a weapon!		*
* Graah 2-Jul-96: More darkness. Dark elves sucked...		*
*                                                               *
*       NEW:                                                    *
*								*
* - The torch is now a weapon! It cannot be lit unless it	*
*   is wielded. This makes sense: it's silly to be able to	*
*   carry many lit torches at once.  This also prevents		*
*   players from cheating by carrying 20 lit torches.		*
* - The WC of the torch is 2 if lit and 1 if not lit.		*
*								*
*								*
* 20-sept-94:							*
* - light & extinguish-cmds don't check syntax any more,        *
*   that's done in the /bin/pub/_light.c, ~/_unlight.c and      *
*   ~/_extinguish.c.                                            *
* - "(lit)"-postfix when lit (in short-desc).                   *
* - Can't be put in bag etc. when lit.                          *
*                                                               *
* 07-Dec-94: Now using /basic/object/dimensions //Graah		*
*								*
****************************************************************/

#include <daemons.h>
#include <lights.h>
#include <living_defs.h>
#include <treasure.h>

#define LIGHT_LEVEL -2

#define TP this_player()

int amount_of_fuel;
status is_lighted;
int light_level;
status held;

status unlight_cmd(string str);

void
create_treasure()
{
    set_name("torch of darkness");
    set_id(({ "torch", "darkness", "dark_torch" }));
    set_weight(1);
    set_value(1000);
    set_size(({ 4, 45, 4 }));
    amount_of_fuel = 2000;
    light_level = LIGHT_LEVEL;
    held = 0;
}

void
init()
{
    if (!living(environment(this_object()))) held = 0;
    if (is_lighted && !held)
	unlight_cmd("torch");
    add_action("remove_cmd", "remove");
    add_action("remove_cmd", "unwield");
    add_action("hold_cmd", "hold");
}


/****************************************************************
*                                                               *
*                       Query-functions.                        *
*                                                               *
****************************************************************/

status is_torch() { return 1; }
status is_held() { return held; }

varargs string
query_long(string what, object me)
{
    if (!is_lighted) return ::query_long(what, me);
    return ::query_long(what, me) + (is_lighted?"\nIt is lit.":"");
}
varargs string
query_short(int mode, object me)
{
    string str;
    str = ::query_short(mode, me);
    if (held) str += " (held)";
    if (is_lighted) str += " (lit)";
    return str;
}

int query_value() { return (-light_level * amount_of_fuel) / 60; }
int query_light_level() { return light_level; }


/****************************************************************
*                                                               *
*                       Set-functions.                          *
*                                                               *
****************************************************************/

void set_fuel(int f) { amount_of_fuel = f; }
void set_light_level(int x) { light_level = x; }


/****************************************************************
*                                                               *
*                       And then all the rest...                *
*                                                               *
****************************************************************/

status prevent_insert(object who)
{
    if (is_lighted) 
    {
	if (!who) who = previous_object();
	who->tell_me("You can't, because "
	  +query_name(0, who)+" is lit!");
	return 1;
    }
    return 0;
}

/***************************************************************/
/***************************************************************/

status
light_cmd(string str)
{
    if ( !held )
    {
	TP->tell_me("You can't light a "+query_name()
	  +" that you aren't holding!");
	return 1;
    }
    if (is_lighted)
    {
	TP -> tell_me("It is already lighted.");
	return 1;
    }

    is_lighted = 1;
    call_out("out_of_fuel", amount_of_fuel * 2);
    set_light(light_level);
    TP->tell_me("You light the "+query_name()+".");
    environment(TP)->tell_here((string)TP->query_name()+
      " lights a "+ query_name() + ".", TP);
    amount_of_fuel = 0;

    return 1;
}
/****************************************************************/
/****************************************************************/


status
unlight_cmd(string str)
{
    int i;
    if (!id(str)) return 0;
    if (!is_lighted) 
    {
	if (TP) TP->tell_me("It isn't even lighted yet.");
	return 1;
    }
    i = remove_call_out("out_of_fuel");
    if(i > 2000) i = 2000;
    if (i == -1)
    {
	notify_fail(
	  "There's something strange with it...it doesn't go out...\n");
	return 0;
    }
    amount_of_fuel = i*3/4;     /* Was i / 2. -Doomdark. */
    is_lighted = 0;
    if (set_light(-light_level) >= 0) 
    {
	if (TP) {
	    TP->tell_me("The darkness ends.");
	    environment(TP)->tell_here(TP->query_name()
	      +" turns off a "+query_name()+".",TP);
	}
    }
    else 
    {
	if (TP) {
	    TP->tell_me("You extinguish the "+query_name()+".");
	    environment(TP)->tell_here(TP->query_name()
	      + " extinguishes a "+query_name()+".", TP);
	}
    }

    return 1;
}

/****************************************************************/
/****************************************************************/

status
hold_cmd(string str)
{
    object *ob;
    int i;

    if (!id(str))
    {
	notify_fail("Hold what?\n");
	return 0;
    }

    if (!present(this_object(), TP))
    {
	notify_fail("You are not carrying it.\n");
	return 0;
    }

    /* Fucking cheaters! */
    ob = all_inventory(TP);

    for (i = sizeof(ob) - 1; i >= 0; i--)
	if (ob[i]->is_torch() && ob[i]->is_held())
	{
	    TP->tell_me("You are already holding something!");
	    return 1;
	}

    TP->tell_me("Ok. You hold " + query_name() + ".");
    environment(TP)->tell_here((string)TP->query_name() +
      " holds " + query_name() + ".", ({ TP }));
    held = 1;
    return 1;
}


/****************************************************************/
/****************************************************************/

void out_of_fuel()
{
    object ob;

    ob = environment();
    while (environment(ob)) ob = environment(ob);
    if (ob)
        ob->tell_here("The "+query_name()+" stops emitting darkness.");
    set_light(-light_level);
    if (living(ob=environment())) {
        ob->add_weight(-(query_weight()));

        if (ob->query(LIV_IS_PLAYER) && ob->query_env("gmcp")) {
            TELOPT_D->send_char_items_remove(ob, "inv", this_object());
        }
    } else {
        foreach (object you : filter(all_inventory(environment()), (: $1->query(LIV_IS_PLAYER) :))) {
            if (you->query_env("gmcp")) {
                TELOPT_D->send_char_items_remove(you, "room", this_object());
            }
        }
    }

    destruct(this_object());
}

/***************************************************************/
/***************************************************************/

status
unwield(object me, object wielder)
{
    if (me!=this_object() || !wielder) return 0;
    if ( is_lighted ) unlight_cmd("torch");
    return 0;
}

status
remove_cmd(string str)
{
    if (!id(str)) return 0;
    if (!held)
    {
	notify_fail("You aren't even holding it.");
	return 0;
    }
    held = 0;
    if (is_lighted) unlight_cmd("torch");
    TP->tell_me("Ok.");
    return 1;
}


/****************************************************************
*                                                               *
*                   Compatability functions                     *
*                                                               *
****************************************************************/

status
light(string str) { /* Not to be used anymore, use 'light_cmd' instead. */
    return light_cmd(str);
}
status
extinguish(string str) { /* Not to be used anymore, use 'unlight_cmd' instead. */
    return unlight_cmd(str);
}
status
unlight(string str) {  /* Not to be used anymore, use 'unlight_cmd' instead. */
    return unlight_cmd(str);
}
