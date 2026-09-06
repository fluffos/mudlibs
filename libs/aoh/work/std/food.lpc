/*
** /std/food.c
**
** This may be eaten or drunk, depending on what you tell it to be.
** A drink will be a drink without vessel (compare to /std/drink).
**
** ??????? [?] Creation
** 13jun95 [t] Overworked the whole thing
** 03dec96 [c] exchanged heal_self by Heal
** 29mar97 [s] introduced NotifyEat
**
** [t] Thragor
** [c] Cadra
** [s] Softbyte
*/

inherit "/std/thing";

#include <health.h>
#include <properties.h>
#include <search.h>
#include <config.h>
#include <classes.h>

#define SF(x) #'x //'
#define TP this_player()
#define ME this_object()
#define KIND_FOOD "food"
#define KIND_DRINK "drink"

private nosave int stuff, alc, soak, heal;
private nosave string kind;
private nosave mixed msgs;

public void create()
{
  (::create());
  SetWeight(1);
  SetShort(C_FOOD);
  SetIds(({KIND_FOOD}));
  SetLong("A standard food.\n");
  Set(P_HELP_MSG,
"Some food, meant to satiate hunger. Simply eat it.\n"
     );
  seteuid(getuid()); /* For the following, which might cause a load */
  "/obj/lib/register"->Register(ME,"FOODLIST");
}

public void init()
{
  (::init());
  add_action("consume","eat");
  add_action("consume","drink");
  add_action("consume","consume");
}

public string SetFoodKind(string str)
{
  if (member(({KIND_FOOD,KIND_DRINK}),str)==-1)
    return kind;
  RemoveId(kind||KIND_FOOD);
  AddId(str);
  return kind = str;
}
public string QueryFoodKind() { return kind; }

public void SetDrink() { SetFoodKind(KIND_DRINK); }
public void SetFood() { SetFoodKind(KIND_FOOD); }
public int QueryDrink() { return kind == KIND_DRINK; }
public int QueryFood() { return kind == KIND_FOOD||!kind; }

public mixed SetFoodMsgs(mixed ms)
// ms = string: message to the player
//      array(2): message to player/environment
//      array(3): message to player/environment(see)/environment(cantsee)
//      array(4): message to player(see)/player(cantsee)/
//                environment(see)/environment(cantsee)
// ms = closure: function called to either return the appropriate message
//               like the scheme above or handling the messages itself;
//               in this case the function has to return 0.
//               The function will be called with the player-object and
//               the calling object as argument.
// The strings will be passed through process_string. Some functions
// which may be called are predefined:
// Pl_Name, Pl_name, Pl_Pronoun, Pl_pronoun, Pl_Possessive, Pl_possessive,
// Pl_Objective, Pl_objective, Pl_Genetive, Pl_genetive
{
  return msgs = ms;
}
public mixed QueryFoodMsgs() { return msgs; }

public int SetFoodSoak(int n) { return soak = n; }
public int QueryFoodSoak() { return soak; }
public int SetFoodStuff(int n) { return stuff = n; }
public int QueryFoodStuff() { return stuff; }
public int SetFoodAlc(int n) { return alc = n; }
public int QueryFoodAlc() { return alc; }
public int SetFoodHeal(int n) { return heal = n; }
public int QueryFoodHeal() { return heal; }

public varargs int QueryValue()
{
  int min_value, value;
  value = (::QueryValue());
  min_value = MIN_FOOD_EVAL(soak,stuff,alc,heal,QueryWeight());
  SetValue(value = value<min_value?min_value:value?value:random(10)+1);
  return value;
}

protected varargs int do_consume(string verb)
{
  int p_stuff,p_intox,p_soak,
      p_max_stuff,p_max_intox,p_max_soak;
  string p_name,*ms;
  mixed tmp;

  if (!verb) verb = "consume";

  p_intox = ({int})TP->QueryAlcohol();
  p_stuff = ({int})TP->QueryFood();
  p_soak = ({int})TP->QueryDrink();
  p_max_intox = ({int})TP->QueryMaxAlcohol();
  p_max_stuff = ({int})TP->QueryMaxFood();
  p_max_soak = ({int})TP->QueryMaxDrink();
  p_name  = ({string})TP->QueryName();
  if (  (!stuff || p_stuff + stuff <= p_max_stuff)
      &&(!alc   || p_intox + alc   <= p_max_intox)
      &&(!soak  || p_soak  + soak  <= p_max_soak))
    {
      if (!call_resolved(&tmp, TP, "AddFood", stuff))
        TP->eat_food(stuff);
      if (!call_resolved(&tmp, TP, "AddAlcohol", alc))
        TP->drink_alcohol(alc);
      if (!call_resolved(&tmp, TP, "AddDrink", soak))
        TP->drink_soft(soak);
      if (!call_resolved(&tmp, TP, "Heal", heal))
        TP->Heal(heal);
      if (!msgs)
	{
	  write("You "+verb+" "+add_a(QueryShort())+".\n");
	  show(p_name+" "+verb+"s "+QueryShort()+".\n");
	}
      else
	{
	  if (closurep(msgs))
	    ms = funcall(msgs,TP,ME);
          else
            ms = msgs;
          if (stringp(ms))
            write(ms);
	  else
            if (pointerp(ms))
	      {
	        switch(sizeof(ms))
		  {
		   case 0:
		    break;
		   case 1:
		    write(process_string(ms[0]));
		    break;
		   case 2:
		    write(process_string(ms[0]));
		    say(process_string(ms[1]));
		    break;
		   case 3:
		    write(process_string(ms[0]));
		    show(({process_string(ms[1]),process_string(ms[2])}));
		    break;
		   default:
		    see(({process_string(ms[0]),process_string(ms[1])}));
		    show(({process_string(ms[2]),process_string(ms[3])}));
		  }
	      }
	}
      /* Notify us that we had been eaten */
      this_object()->NotifyEat(this_player());
      if ( ({int})this_object()->QueryAmount() )
        this_object()->ReduceAmount( 1 );
      else
        remove();
    }
  else
    if (p_intox + alc > p_max_intox)
      {
	write("You fail to reach "+QueryShort()+" to your mouth.\n");
        show(p_name+" is too drunk to "+verb+" "+QueryShort()+".\n");
      }
    else
      if (p_stuff + stuff > p_max_stuff)
        {
	  write("This is much too rich for you right now! "
	        "Perhaps something lighter?\n");
	  show(p_name+" tries to "+verb+" "+QueryShort()+" but fails.\n");
	}
      else
        if (p_soak + soak > p_max_soak)
	  {
	    write("Your belly already sounds like a full bottle.\n");
	    say(p_name+" tries to "+verb+" "+QueryShort()+" but fails.\n");
	  }
  return 1;
}

public int consume(string str)
{
  if (!str)
    return notify_fail(capitalize(query_verb())+" what?\n",
		       NOTIFY_NOT_OBJ),0;
  if (!foundp(ME,search(TP,str,SEARCH_INV|SM_OBJECT|SM_IGNLIGHT))
      ||(query_verb()=="drink"&&!QueryDrink())
      ||(query_verb()=="eat"&&!QueryFood()))
    return notify_fail("You find no "+str+" to "+query_verb()+".\n",
		       NOTIFY_NOT_OBJ),0;
  return do_consume(query_verb());
}

/*
* Functions to be used in process_string
*/

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
