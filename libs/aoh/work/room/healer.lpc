/*
** /obj/healer.c
**
** 28feb95 [t] Creation
** 19jun95 [t] Adapted to new poison-healing
** 06jul95 [t] Rebuild to use /obj/lib/communication
** 07jul95 [t] Usage of P_INFO, P_VALUE, etc.
**
**
** [t] Thragor@nightfall
** TODO: Make me better and update /sys/stdrooms.h then.
*/

#include <properties.h>
#include <rooms.h>
#include <health.h>    // HEAL_COST, ...
#include <config.h>    // NOTIFY_...
#include <nightday.h>  // ND_..., NIGHTDAY
#include <moving.h>    // ME_NO_ENTER, M_GO
#include <secure/wizlevels.h> // IS_IMMORTAL
#include <money.h>     // MONEY_DEMON
#include <search.h>    // SM_

#define ME this_object()
#define TP this_player()
#define TO this_object()
#define PO previous_object()
#define STR "/lib/string"
#define NMB "/lib/number"
#define SF(x) #'x //'
#define LSF(x) symbol_function(x,TO)
#define SYMBOL(x) 'x //'
#define FALSE 1==0
#define TRUE 1==1
#define HEALER_ID    "I'm the healer"

inherit "/std/room";
inherit "/lib/money";
inherit "/obj/lib/communication";

/* prototypes */
public void RemoveHealer();

private nosave string desc_sign;
private nosave mixed treat_msg,poison_msg,virus_msg,curse_msg;
private nosave int allow_wounds,allow_poison,allow_virus,allow_curse,
                      open_day,open_night, no_healer;


/* ------------------------------------------------------------- *
 *        Setting up and configuring the healer                  *
 * ------------------------------------------------------------- */


/** ------------------------------------------------------------
@fun: public int QueryNoHealer()
@args: none
@returns: 0 if npc healer is used, 1 if virtual healer

@fun: public object QueryHealer()
@args: none
@returns: npc object if found, 0 if not
------------------------------------------------------------ */

public int QueryNoHealer()
{
  return no_healer;
}

public object QueryHealer()
{
  return present(HEALER_ID, this_object());
}

public varargs string Name(mixed cap)
{
  object healer;
  string name;

  if(!QueryNoHealer())
  {
    // if we're using an npc
    healer = QueryHealer();

    if(healer && (name = ({string})healer->QueryName() ))
      return capitalize(name);
  }
  return cap ? "The healer" : "the healer";
}


// ---- If the healer is just a detail and not an npc, or if npc is gone -- //
public string detail_healer()
{
  if (!QueryNoHealer())
    return QueryHealer() ? 0 : "The healer isn't here.\n";
  return "A gentle-looking woman with wise eyes.\n";
}

// -- removes the npc healer --
public void RemoveHealer()
{
  object ob;
  string fname;

  if (ob = QueryHealer())
    {
      fname = blueprint(ob);
      ob->remove();
      if (ob) destruct(ob);
      this_object()->RemoveItem(fname);
    }
}

// ---- creates the default npc healer. --//
public varargs void SetHealer(string file, mapping properties)
{
    RemoveHealer();
    if(!file)
        this_object()->AddItem("/std/npc",REFRESH_HOME,({
            ([P_NAME: "Healer",
              P_IDS: ({"healer"}),
              P_SHORT: "the healer",
              P_LONG: "A gentle-looking woman with wise eyes.\n",
              P_GENDER: GENDER_FEMALE,
              P_RACE: "human",
              P_ALIGN: 1000,
              P_LEVEL: 17,
              P_CON:19,
              P_STR:20,
              P_INT:20
            ]),
            properties})-({0}),
            LSF("healer_refresh"));
    else
        this_object()->AddItem(file,REFRESH_HOME,properties,LSF("healer_refresh"));
}

//
public void healer_refresh(object ob)
{
  ob->AddId(HEALER_ID);
  //ob->AddDefence(DT_PSYCHO,100); // No one can shock them ;-)
  //ob->AddResistance(ST_PSYCHO,100);
  // commented out for now...
}

/** ------------------------------------------------------------
@fun: public void ForbidHealer()
@args: none
@returns: void
@note: Use in create() of your healer room to have a virtual healer

@fun: public void AllowHealer()
@args: none
@returns: void
@note: Use in create() of your healer room to have an npc healer
------------------------------------------------------------ */

public void ForbidHealer()
{
  no_healer = 1;
  RemoveHealer();
}

public void AllowHealer()
{
  no_healer = 0;
  SetHealer();
}

/*-------------------------------------------------------------*/

public void Message(mixed message)
{
  mixed ms;
  if (!TP) return;
  if (closurep(message))
    ms = funcall(message,TP,Name());
  else
    ms = message;
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
	    write(ms[0]?wrap(parse_string(ms[0]),0,3):"");
	    break;
	   case 2:
	    write(wrap(parse_string(ms[0]),0,3));
	    say(ms[1]?wrap(parse_string(ms[1]),0,3):"");
	    break;
	   case 3:
	    write(ms[0]?wrap(parse_string(ms[0]),0,3):"");
	    show(({ms[1]?wrap(parse_string(ms[1]),0,3):"",
                   ms[2]?wrap(parse_string(ms[2]),0,3):""}));
	    break;
	   default:
	    see(({ms[0]?wrap(parse_string(ms[0]),0,3):"",
                  ms[1]?wrap(parse_string(ms[1]),0,3):""}));
	    show(({ms[2]?wrap(parse_string(ms[2]),0,3):"",
                   ms[3]?wrap(parse_string(ms[3]),0,3):""}));
	  }
      }
}

protected varargs string *QueryFValuta(int force)
{
  return force?m_indices(({mapping})MONEY_DEMON->QueryCoinTypes()||([])):QueryValuta();
}

protected varargs string get_min_coin(int force)
// Return the minimal coin (as string) to be used e. g. in the 'list'.
{
  closure query_coin_value;
  int *vals,minval,i;
  string *mincoins;

  query_coin_value = symbol_function("QueryCoinValue",MONEY_DEMON);
  vals = map(QueryFValuta(force),query_coin_value);
  minval = ({int})NMB->min(vals);
  mincoins = ({});
  for (i=0;i<sizeof(vals);i++)
    if (vals[i]==minval)
      mincoins+=({QueryValuta()[i]});
  if (member(mincoins,"copper")!=-1
      ||!sizeof(mincoins))
    return "copper";
  return mincoins[0];
}

protected int convert_value(int copper)
{
  int c,new;
  c = ({int})MONEY_DEMON->QueryCoinValue("copper");
  new = ({int})MONEY_DEMON->QueryCoinValue(get_min_coin());
  if (!new) return 0;
  return (copper*c)/new+(copper*c%new!=0);
}

protected int round_value(int copper)
{
  int c,new;
  c = ({int})MONEY_DEMON->QueryCoinValue("copper");
  new = ({int})MONEY_DEMON->QueryCoinValue(get_min_coin());
  if (!new) return 0;
  return ((copper*c)/new+(copper*c%new!=0))*new;
}

public int CheckNight()
{
  return member(({ND_SUNSET,ND_EVENING,ND_NIGHT,ND_PREDAWN,ND_DAWN}),
                ({int})NIGHTDAY->QueryState())!=-1;
}

public int ModifyCost(int cost)
// modify the price depending if its night or not
// you may define your own ModifyPrice but you should keep this
// calculation for the night-price
{
  return CheckNight() ? NIGHT_COST(cost) : cost;
}

protected int calc_cost(int cost)
{
  int res;
  if (!cost) return 0;
  cost = round_value(cost);
  return (res = ModifyCost(cost))?res:cost;
}

protected status pay_service(int cost,status force,string str)
{
  mixed msgs;
  cost = calc_cost(cost*(force?2:1));
  if (cost)
    {
      msgs = PayValue2(TP,cost,QueryFValuta(force));
      if (msgs == MONEY_NO_MONEY)
        return Say("Sorry, you don't have any money to pay the service.\n"),0;
      if (msgs == MONEY_NOT_ENOUGH)
        return Say("Sorry, you don't have enough money to pay the service.\n"),
               0;
      if (msgs == MONEY_CANT_PAY)
        return Say("Sorry, you can't afford the money in my currency. If "
                   "you need urgent help, type '"+query_verb()+" really"+
                   (str?" "+str:"")+"'.\n"),0;
      Message(
        ({"You pay "+msgs[0]+(msgs[1]?" and receive "+msgs[1]:"")+".\n",
          PlName("1")+" pays "+msgs[0]+(msgs[1]?" and receives "+msgs[1]:"")+
          ".\n",
          0
        }));
    }
  return 1;
}

public int allow_enter(int method,mixed extra)
// checks if the healer is closed
{
  if (query_once_interactive(PO))
    {
      if (CheckNight()&&open_night==FALSE)
        if (!IS_IMMORTAL(PO))
          {
	    notify_fail(
              Name(1)+" opens again in the morning. Come back later!\n",
              NOTIFY_NOT_VALID);
	    return ME_NO_ENTER;
	  }
      if (!CheckNight()&&open_day==FALSE)
        if (!IS_IMMORTAL(PO))
	  {
	    notify_fail(
	      Name(1)+" opens again in the night. Come back later!\n",
              NOTIFY_NOT_VALID);
	    return ME_NO_ENTER;
	  }
    }
  return (::allow_enter(method,extra));
}

/* ------------------------------------------------------------- *
 *        Functions to configure the healer shop                 *
 * ------------------------------------------------------------- */

public void CloseNight() { open_night = FALSE; }
public void OpenNight() { open_night = TRUE; }
public status QueryNight() { return open_night; }

public void CloseDay() { open_day = FALSE; }
public void OpenDay() { open_day = TRUE; }
public status QueryDay() { return open_day; }

public void AllowTreat() { allow_wounds = TRUE; }
public void ForbidTreat() { allow_wounds = FALSE; }
public status QueryTreat() { return allow_wounds; }

public void AllowPoison() { allow_poison = TRUE; }
public void ForbidPoison() { allow_poison = FALSE; }
public status QueryPoison() { return allow_poison; }

public void AllowVirus() { allow_virus = TRUE; }
public void ForbidVirus() { allow_virus = FALSE; }
public status QueryVirus() { return allow_virus; }

public void AllowCurse() { allow_curse = TRUE; }
public void ForbidCurse() { allow_curse = FALSE; }
public status QueryCurse() { return allow_curse; }

public mixed SetTreatMsg(mixed msg) { return treat_msg = msg; }
public mixed QueryTreatMsg()
{
  return
    treat_msg||
    lambda(0,
      ({SF(Emote),SYMBOL(({"tends to your wounds.\n",
                           "tends to @@PlGenitive@@ wounds.\n",0}))}));
}

// The messages below will be printed before any message of the
// removed object will appear.

public mixed SetPoisonMsg(mixed msg) { return poison_msg = msg; }
public mixed QueryPoisonMsg()
{
  return
    poison_msg||
    lambda(0,({SF(Emote),SYMBOL(({"cures your poisoned body.\n",
                                  "cures @@PlGenitive@@ body.\n",0}))}));
}

public mixed SetVirusMsg(mixed msg) { return virus_msg = msg; }
public mixed QueryVirusMsg()
{
  return
    virus_msg||
    lambda(0,({SF(Emote),SYMBOL(({"cures your disease.\n",
                                  "cures @@PlGenitive@@ disease.\n",0}))}));
}

public string SetCurseMsg(string msg) { return curse_msg = msg; }
public mixed QueryCurseMsg()
{
  return
    curse_msg||
    lambda(0,
      ({SF(Emote),
        SYMBOL(({"makes a magical gesture and stares at you.\n",
                 "makes a magical gesture staring at @@PlName@@.\n",
                 0
               }))
      }) );
}

protected string format_sign(string what,int value)
// put the costs for the sign into the correct format
{
  int val;
  string cointype;
  cointype = get_min_coin();
  val = convert_value(value);
  return ({string})STR->ladjust(what+" ",25,".")+" "+
    ({string})STR->radjust(to_string(val),5," ")+
    " "+cointype+"\n";
}

public string SetSignDesc(string desc)
{
  return desc_sign = desc;
}

public string QuerySignDesc()
{
  return desc_sign ? desc_sign :
    (allow_wounds?
       format_sign("Treat light wounds",
                   calc_cost(HEAL_COST(LIGHT_WOUNDS)))+
       format_sign("Treat serious wounds",
                   calc_cost(HEAL_COST(SERIOUS_WOUNDS)))+
       format_sign("Treat critical wounds",
                   calc_cost(HEAL_COST(CRITICAL_WOUNDS)))
     :"")+
    (allow_poison||allow_virus||allow_curse?
       "\n"+
       (allow_poison?
          "I can cure poison. Syntax: cure poison\n"
        :"")+
       (allow_virus?
          "I can cure diseases such as a virus-infection.\n"
          "  Syntax: cure disease|illness|virus\n"
        :"")+
       (allow_curse?
          "I can remove curses. Syntax: remove curse"
        :"")
     :"")+
    "If you want to get general informations about your health,\n"
    "type 'inform health'. If you know of a certain disease you\n"
    "might type 'inform <disease>' to get to know more about it.\n";
}

public int cmd_treat(string str)
{
  string what;
  int maxhp,hp,heal;
  status force;

  if (!QueryNoHealer() && !QueryHealer())
  {
     notify_fail("There's no one here who can do that for you right now.\n",
                       NOTIFY_NOT_VALID);
     return 0;
  }
  if (!TP
      ||lower_case(str||"")==""
      ||!sizeof(regexp(({str}),"wounds")))
    return notify_fail("What shall "+Name()+" treat?\n",NOTIFY_ILL_ARG),0;
  show(({
    PlName("1")+" asks "+Name()+" to treat "+PlGenitive(0)+" wounds.\n",
    "Someone asks someone to treat their wounds.\n"}));
  if (str[0..5]=="really")
    {
      force = TRUE;
      str = str[7..];
    }
  if (!allow_wounds)
    return notify_fail(lambda(0,
      ({SF(Say),"Sorry, I don't offer this service.\n"})),
      NOTIFY_NOT_VALID),0;
  maxhp = ({int})TP->QueryMaxHP();
  hp = ({int})TP->QueryHP();
  if (hp>=maxhp)
    return notify_fail(lambda(0,
      ({SF(Say),"You don't have any wounds.\n"})),NOTIFY_NOT_VALID),0;
  if (str=="wounds")
    if (maxhp-hp<=LIGHT_WOUNDS)
      {
        Say("These are only light wounds.\n");
	str = "light wounds";
      }
    else
      if (maxhp-hp<=SERIOUS_WOUNDS)
	{
	  Say("These are serious wounds.\n");
	  str = "serious wounds";
	}
      else
        {
	  Say("These are critical wounds!\n");
	  str = "critical wounds";
	}
  sscanf(str,"%s wounds",what);
  switch(what)
    {
     case "light":
      heal = LIGHT_WOUNDS;
      break;
     case "serious":
      heal = SERIOUS_WOUNDS;
      break;
     case "critical":
      heal = CRITICAL_WOUNDS;
      break;
     default:
      return notify_fail(lambda(0,
        ({SF(Say),"What wounds should I treat? "+capitalize(str)+"?\n"})),
        NOTIFY_NOT_VALID),0;
    }
  if (!pay_service(calc_cost(HEAL_COST(heal)),force,str)) return 1;
  TP->SetHP(NMB->min(({maxhp,hp+heal})));
  Message(QueryTreatMsg());
  return 1;
}

protected void inform_health()
{
  int maxhp,hp,heal;

  maxhp = ({int})TP->QueryMaxHP();
  hp = ({int})TP->QueryHP();
  if (hp>=maxhp)
    return Say("You don't have any wounds.\n");
  if (maxhp-hp<=LIGHT_WOUNDS)
    {
      Say("These are only light wounds.\n");
      heal = LIGHT_WOUNDS;
    }
  else if (maxhp-hp<=SERIOUS_WOUNDS)
    {
      Say("These are serious wounds.\n");
      heal = SERIOUS_WOUNDS;
    }
  else
    {
      Say("These are critical wounds!\n");
      heal = CRITICAL_WOUNDS;
    }
  Say("I'll take "+convert_value(calc_cost(HEAL_COST(heal)))+" "+
      get_min_coin()+" to treat them.\n");
}

protected mapping get_diseases()
// Will return all diseases in this form:
// ([D_POISON:({<poisons>}),
//   D_CURSE:({<curses>}),
//   D_DISEASE:({<diseases>})])
{
  mapping res;
  int i;
  object *inv;

  i = sizeof(inv = all_inventory(TP));
  res = ([]);
  res[D_POISON] = ({});
  res[D_CURSE] = ({});
  res[D_DISEASE] = ({});
  while(i--)
    {
      if (({int})inv[i]->id(D_POISON))
	res[D_POISON]+=({inv[i]});
      else if (({int})inv[i]->id(D_CURSE))
	res[D_CURSE]+=({inv[i]});
      else if (({int})inv[i]->id(D_DISEASE))
        res[D_DISEASE]+=({inv[i]});
    }
  return res;
}

protected int cost_poison(object *poisons,int poison)
{
  int *vals;
  vals = map_objects(poisons,"QueryValue");
  return ({int})NMB->sum(vals)+poison*10;
}

protected int cure_poison(mapping diseases)
// 0: No success, player has to get full amount of money back
// 1: successful, calculate the costs with <oldcost>-<newcost>.
{
  object *poisons;
  int i,size,p;
  mixed msg;
  poisons = diseases[D_POISON];

  p = ({int})TP->QueryPoison();
  if ((!size = i = sizeof(poisons))&&!p)
    return Say("You are not poisoned.\n"),0;
  Message(QueryPoisonMsg());
  while(i--)
    {
      if (msg = ({mixed})poisons[i]->QueryCureMsg())
        Message(msg);
      poisons[i]->remove();
    }
  poisons-=({0});
  TP->SetPoison(0);
  if ((i = sizeof(poisons))||({int})TP->QueryPoison())
    if (i<size)
      {
	Say("I am not able to cure all of the poisons in your body. Damn! "
            "Did you visit a snakepit?\n");
        return 1;
      }
    else if (({int})TP->QueryPoison()>=p)
      return Say("I can't do anything against the poison.\n"),0;
  return 1;
}

protected void inform_poison(object *poisons)
{
  int p;
  string *infos;

  p = ({int})TP->QueryPoison()?1:0;
  Say("Your body is tortured by "+itoa(sizeof(poisons)+p)+" poison"+
     (sizeof(poisons)+p==1?"":"s")+".\n");
  if (sizeof(poisons)+p)
    Say("It'll cost "+
        convert_value(calc_cost(cost_poison(poisons,({int})TP->QueryPoison())))+" "+
        get_min_coin()+" to cure you completely.\n");
  infos = map_objects(poisons,"QueryInfo")-({0,""});
  if (sizeof(infos))
    {
      Say("I know the following about the poisons ravaging your body:\n");
      Message(({
        implode(infos,"\n")+"\n",
        "@@PlName|1@@ gets to know a lot about the poisons ravaging "
        "@@PlPossessive@@ body.\n"}));
    }
}

protected int cost_disease(object *diseases)
{
  return ({int})NMB->sum(map_objects(diseases,"QueryValue"));
}

protected int cure_disease(mapping diseases)
{
  object *d;
  int i,size;
  mixed msg;
  d = diseases[D_DISEASE];
  if (!size = i = sizeof(d))
    return Say("You don't suffer from any disease.\n"),0;
  Message(QueryVirusMsg());
  while(i--)
    {
      if (msg = ({mixed})d[i]->QueryCureMsg())
        Message(msg);
      d[i]->remove();
    }
  d-=({0});
  if (i = sizeof(d))
    if (i<size)
      {
	Say("I am not able to cure you completely.\n");
        return 1;
      }
    else
      return Say("I can't do anything against your diseases.\n"),0;
  return 1;
}

protected void inform_disease(object *diseases)
{
  string *infos;

  Say("Your body is tortured by "+itoa(sizeof(diseases))+" disease"+
     (sizeof(diseases)==1?"":"s")+".\n");
  if (sizeof(diseases))
    Say("It'll cost "+
        convert_value(calc_cost(cost_disease(diseases)))+" "+
        get_min_coin()+" to cure you completely.\n");
  infos = map_objects(diseases,"QueryInfo")-({0,""});
  if (sizeof(infos))
    {
      Say("I know the following about the diseases ravaging your body:\n");
      Message(({
        implode(infos,"\n")+"\n",
        "@@PlName|1@@ gets to know a lot about the diseases ravaging "
        "@@PlPossessive@@ body.\n"}));
    }
}

public int cmd_cure(string str)
{
  int cost,rem;
  status force;
  mapping diseases,amount;
  object money;

  if (!Name())
    return notify_fail("There's noone here who can do that for you.\n",
		       NOTIFY_NOT_VALID),0;
  if (!TP
      ||lower_case(str||"")==""
      ||!sizeof(regexp(({str}),"^poison$|^virus$|^illness$|^disease$")))
    return notify_fail("What shall "+Name()+" cure?\n",
                            NOTIFY_ILL_ARG);
  if (str[0..5]=="really")
    {
      force = TRUE;
      str = str[7..];
    }
  show(({PlName("1")+" wants "+Name()+" to cure "+PlObjective(0)+
         " from "+str+".\n",
         "Someone wants someone to cure them from "+str+".\n"}));

  diseases = get_diseases();
  if (money=QueryMoneyObject(TP))
    amount = ({mapping})money->QueryMoney();
  switch(str)
    {
     case "poison":
      if (!allow_poison)
        return notify_fail(lambda(0,
          ({SF(Say),"Sorry, I don't offer this service.\n"})),
          NOTIFY_NOT_VALID)&&0;
      cost = calc_cost(cost_poison(diseases[D_POISON],({int})TP->QueryPoison()));
      if (!pay_service(cost,force,str)) return 1;
      if (!cure_poison(diseases))
	{
	  if (cost)
	    {
	      Say("I'll give your money back to you.\n");
	      Emote(({"hands some money to you.\n",
                      "hands some money to @@PlName@@.\n",0}));
	      money->SetMoney(amount);
	    }
	  return 1;
	}
      if (rem = calc_cost(cost_poison(get_diseases()[D_POISON],
          ({int})TP->QueryPoison())))
	{
	  Say("I'll give you some of your money back to you.\n");
	  Emote(({"hands some money to you.\n",
                  "hands some money to @@PlName@@.\n",0}));
	  AdjustMoney(TP,({mixed})MONEY_DEMON->CreateMoney(rem,QueryValuta()));
	}
      break;
     case "virus":
     case "illness":
     case "disease":
      if (!allow_virus)
        return notify_fail(lambda(0,
          ({SF(Say),"Sorry, I don't offer this service.\n"})),
          NOTIFY_NOT_VALID)&&0;
      cost = calc_cost(cost_disease(diseases[D_DISEASE]));
      if (!pay_service(cost,force,str)) return 1;
      if (!cure_disease(diseases))
	{
	  if (cost)
	    {
	      Say("I'll give your money back to you.\n");
	      Emote(({"hands some money to you.\n",
                      "hands some money to @@PlName@@.\n",0}));
	      money->SetMoney(amount);
	    }
	  return 1;
	}
      if (rem = calc_cost(cost_disease(get_diseases()[D_DISEASE])))
	{
	  Say("I'll give you some of your money back to you.\n");
	  Emote(({"hands some money to you.\n",
                  "hands some money to @@PlName@@.\n",0}));
	  AdjustMoney(TP,({mixed})MONEY_DEMON->CreateMoney(rem,QueryValuta()));
	}
    }
  return 1;
}

protected int cost_curse(object *curses,int frog)
{
  return ({int})NMB->sum(map_objects(curses,"QueryValue"))+frog*100;
}

protected int remove_curse(object *curses)
{
  int i,size,frog;
  mixed msg;

  frog = ({int})TP->QueryFrog();
  if ((!size = i = sizeof(curses))&&!frog)
    return Say("You are not cursed.\n"),0;
  Message(QueryCurseMsg());
  while(i--)
    {
      if (msg = ({mixed})curses[i]->QueryCureMsg())
        Message(msg);
      curses[i]->remove();
    }
  curses-=({0});
  TP->SetFrog(0);
  if (i = sizeof(curses)||({int})TP->QueryFrog())
    if (i<size)
      return Say("I am not able to remove all curses. Damn, did you have a "
                 "quarrel with a witch?\n"),1;
    else
      return Say("I can't do anything against the curses.\n"),0;
  return 1;
}

public int cmd_remove(string str)
{
  int cost,rem;
  status force;
  mapping amount;
  object *curses,money;

  if (!Name())
    return notify_fail("There's noone here who can do that for you.\n",
		       NOTIFY_NOT_VALID),0;
  if (!TP
      ||lower_case(str||"")==""
      ||(str!="curse"&&str!="really curse"))
    return notify_fail("What shall "+Name()+" remove?\n",
                       NOTIFY_ILL_ARG),0;
  show(({PlName("1")+" wants "+Name()+" to remove a curse from "+PlObjective(0)+
         ".\n",
         "Someone wants someone to remove a curse from them.\n"}));
  if (!allow_curse)
    return notify_fail(lambda(0,
      ({SF(Say),"Sorry, I don't offer this service.\n"})),
      NOTIFY_NOT_VALID),0;
  if (str[0..5]=="really")
    {
      force = TRUE;
      str = str[7..];
    }
  curses = get_diseases()[D_CURSE];
  if (money=QueryMoneyObject(TP))
    amount = ({mapping})money->QueryMoney();
  cost = calc_cost(cost_curse(curses,({int})TP->QueryFrog()));
  if (!pay_service(cost,force,str)) return 1;
  if (!remove_curse(curses+({})))
    {
      if (cost)
	{
	  Say("I'll give your money back to you.\n");
	  Emote(({"hands some money to you.\n",
                  "hands some money to @@PlName@@.\n",0}));
	  money->SetMoney(amount);
	}
      return 1;
    }
  if (rem = calc_cost(cost_curse(get_diseases()[D_CURSE],({int})TP->QueryFrog())))
    {
      Say("I'll give you some of your money back to you.\n");
      Emote(({"hands some money to you.\n",
              "hands some money to @@PlName@@.\n",0}));
      AdjustMoney(TP,({mixed})MONEY_DEMON->CreateMoney(rem,QueryValuta()));
    }
  return 1;
}

protected void inform_curse(object *curses)
{
  int f;
  string *infos;

  f = ({int})TP->QueryFrog()?1:0;
  Say("You are tortured by "+itoa(sizeof(curses)+f)+" curse"+
     (sizeof(curses)+f==1?"":"s")+".\n");
  if (sizeof(curses)+f)
    Say("It'll cost "+
        convert_value(calc_cost(cost_curse(curses,({int})TP->QueryFrog())))+" "+
        get_min_coin()+" to cure you completely.\n");
  infos = map_objects(curses,"QueryInfo")-({0,""});
  if (sizeof(infos))
    {
      Say("I know the following about the curses ravaging you:\n");
      Message(({
        implode(infos,"\n")+"\n",
        "@@PlName|1@@ gets to know a lot about the curses ravaging "
        "@@PlObjective@@.\n"}));
    }
}

public int cmd_inform(string str)
{
  object ob;
  string info,msg;
  mapping diseases;

  if (!Name())
    return notify_fail("There's noone here who can do that for you.\n",
		       NOTIFY_NOT_VALID),0;
  if (!TP
      ||lower_case(str||"")=="")
    return notify_fail("Inform about what?\n",NOTIFY_ILL_ARG),0;
  show(({PlName("1")+" wants "+Name()+" to inform "+PlObjective(0)+
         " about "+str+".\n",
         "Someone wants someone to inform them about "+str+".\n"}));
  diseases = get_diseases();
  if (str=="health")
    {
      if (allow_wounds) inform_health();
      if (allow_virus) inform_disease(diseases[D_DISEASE]);
      if (allow_poison) inform_poison(diseases[D_POISON]);
      if (allow_curse) inform_curse(diseases[D_CURSE]);
    }
  else
    {
      if (!ob=search(TP,str,SM_IGNLIGHT|SM_OBJECT|SEARCH_INV))
        return notify_fail(lambda(0,({SF(Say),
          "You don't have that.\n"})),NOTIFY_ILL_ARG),0;
      if (!(  (allow_virus&&({int})ob->id(D_DISEASE))
            ||(allow_curse&&({int})ob->id(D_CURSE))
            ||(allow_poison&&({int})ob->id(D_POISON))))
        return notify_fail(lambda(0,
          ({SF(Say),"I can't identify that.\n"})),NOTIFY_ILL_ARG),0;
      if (!info = ({string})ob->QueryInfo())
	{
          if (({int})ob->id(D_CURSE))
            msg = "It's a curse";
	  else if (({int})ob->id(D_POISON))
	    msg = "It's a poison";
	  else
            msg = "It's a disease";
	  msg+=" and it will cost you "+
               convert_value(calc_cost(({int})ob->QueryValue()))+" "+
	       get_min_coin()+" to get rid of it.\n";
	  Say(msg);
	}
      else
	Say(info);
    }
  return 1;
}

public varargs void create()
{
  (::create());
  SetIntShort("a healer");
  SetIntLong(
    "You're in the house of a healer.\n"
    "There's a sign at the entrance.\n");
  // You should mention the sign somewhere, so that it can be read.
  OpenDay();
  CloseNight();
  AllowTreat();
  AllowPoison();
  AllowVirus();
  ForbidCurse();

  AddReadMsg("sign",SF(QuerySignDesc));

  AddDetail("sign",SF(QuerySignDesc));
  AddDetail("house","It's small.\n");
  AddDetail("entrance","That's where you entered.\n");

  AddDetail("healer",SF(detail_healer));  // in case healer dies
  SetHealer();    // sets up npc healer
  no_healer = 0;  // use npc by default

  AddRoomCmd("treat",SF(cmd_treat));   // treat wounds
  AddRoomCmd("cure",SF(cmd_cure));     // cure poison, illness/virus
  AddRoomCmd("remove",SF(cmd_remove)); // remove curse
  AddRoomCmd("inform",SF(cmd_inform)); // inform about poisons, health, etc.
  "/obj/lib/register"->Register(ME,"HEALER");
}
