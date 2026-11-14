/*
** Hrok, the traveling mage.
** He can sell you some spells.
** Author: Joern@Nightfall, 29jan94
** Update: Thragor@Nightfall, 16aug95
*/

#include <moving.h>
#include <money.h>
#include <living.h>
#include <config.h>
#include <search.h>

#define D(x,y) "/players/thragor/lib/debug"->debug("thragor",x,y)

#define COST 3
#define TP this_player()
#define ME this_object()
#define SF(x) #'x //'
#define SYM(x) 'x //'

inherit "/std/npc";
inherit MONEY_LIB;
inherit "/lib/number";

public void use_carpet(object envi)
{
  object carp;
  string dest, *keys;
  carp = present("carpet", envi);
  if (!carp || !carp->QueryKeys()) return;
  keys = carp->QueryKeys();
  dest = keys[random(sizeof(keys))];
  if (!dest) return;
  command("sit down");
  command("fly " + dest);
}

public int create()
{
  if (::create()) return 1;
  SetRace("human");
  SetName("Hrok");
  SetShort("Hrok, the traveling mage");
  SetLong(
    "Hrok is an old, wise mage who travels around\n"
    "making scrolls memorizeable.\n");
  SetLevel(28);
  SetMaxHP(565);
  SetHP(500);
  SetHands(({ ({"left hand",0,37}),({"right hand",0,36}) }) );
  SetAC(13);
  SetGender(GENDER_MALE);
  SetAlign(300);
  InitChats(2,
    ({
      "Hrok says: I can make your scroll memorizeable for a few sapphires.\n",
      "Hrok says: Just type 'revise <scroll>'.\n",
      "Hrok says: My help doesn't cost much!.\n"
    }) );
  AddQuestion(({"scrolls","revise scroll","scroll"}),
    "Hrok says: I can make your scrolls memorizeable.\n"
    "  Just type 'revise <scroll>'.\n");
  SetGoChance(20);
  return 0;
}

public void init()
{
  object envi;
  (::init());
  add_action("cmd_revise","revise");
  if (envi = environment())
    use_carpet(envi);
}

private int more_valueable(object a, object b)
{
  return a->QueryValuePerUnit() < b->QueryValuePerUnit();
}

private int PayJewels(int copper)
{
  string *pay,*idx;
  object *jewels;
  int total, i, needed;
  mapping payed, back;
  // ([id:pluralid;amount])

  if (!TP) return 0;
  jewels = filter(deep_inventory(TP),
    lambda(({SYM(ob)}),({SF(call_other),SYM(ob),"id","magic_jewel"})));
  total = sum(map_objects(jewels,"QueryValue"));
  D("jewels: ",jewels);
  D("total: ",total);
  D("copper: ",copper);
  if (total < copper)
    return notify_fail(
      lambda(0,({SF(say),
        "Hrok says: You only have jewels for "+to_string(total/1000)+
        " platinum coins.\n"})),
      NOTIFY_NOT_VALID),0;
  i = sizeof(jewels = sort_array(jewels,SF(more_valueable)));
  D("sorted jewels: ",jewels);
  payed = m_allocate(0,2);
  while(i--&&copper)
    {
      needed = copper/jewels[i]->QueryValuePerUnit();
      D("needed: ",needed);
      D("from (jewels[i]): ",jewels[i]);
      // we would need that much jewels to pay the price
      if (needed==0)
	{
	  back = MONEY_DEMON->CreateMoney(
	       -(copper-jewels[i]->QueryValuePerUnit()),QueryValuta());
	  // now the back contains the coins which have
          // to be payed in return to the player
          copper = jewels[i]->QueryValuePerUnit();
	  needed = 1;
	}
      copper-=needed*jewels[i]->QueryValuePerUnit();
      payed[jewels[i]->QueryShort(),0] = jewels[i]->QueryPluralShort();
      payed[jewels[i]->QueryShort(),1] = needed;
      (jewels[i]->SplitOff(min(({jewels[i]->QueryAmount(),needed}))))
        ->remove();
      // Remove the given amount of jewels
    }
  i = sizeof(idx = m_indices(payed));
  pay = ({});
  while(i--)
    pay+= ({itoa(payed[idx[i],1])+" "+
            (payed[idx[i],1]==1?idx[i]:payed[idx[i],0])});
  i = sizeof(pay);
  D("payed: ",payed);
  D("pay: ",pay);
  say(capitalize(TP->QueryName())+" pays "+
    (i<2?pay[0]:implode(pay[0..<2],", ")+" and "+pay[<1])+".\n",TP);
  write("You pay "+
    (i<2?pay[0]:implode(pay[0..<2],", ")+" and "+pay[<1])+".\n");
  if (back)
    {
      AdjustMoney(TP,back);
      say("Hrok gives "+MONEY_DEMON->QueryMoneyString(back,5)+" to "+
        TP->QueryName()+".\n",TP);
      write("Hrok gives "+MONEY_DEMON->QueryMoneyString(back)+" to you.\n");
    }
  return 1;
}

public int cmd_revise(string str)
{
  int price, chan, fail;
  object scr;
  if (!str||!TP)
    return notify_fail("Revise what?\n",NOTIFY_NOT_OBJ),0;
  if (!scr = search(TP,str,SM_OBJECT|SEARCH_INV|SM_IGNLIGHT))
    return notify_fail("You don't have "+str+".\n",NOTIFY_NOT_VALID),0;
  price = scr->QueryCastLevel();
  tell_room(environment(),
    "Hrok says: This will cost you jewels worth " + price + " platinum.\n"
    "  For example a sapphire is worth ten gold.\n");
  if (!PayJewels(price*1000))
    return 0;
  show("Hrok examines a scroll.\n");
  see("Hrok examines the "+strip_article(scr->QueryShort())+".\n");
  chan = random(100);
  fail = 80;
  if (TP->QueryLevel() < 20) fail = 40;
  if (TP->QueryLevel() < 10) fail = 20;  
  if (chan < fail)
    {
      show_room(environment(),
        "Hrok makes some complex gestures.\n"
        "Then he smiles and returns the scroll to ");
     show(TP->QueryName()+".\n");
     see(({"you.\n","You receive something.\n"}));
     scr->SetMemorize(1);
     return 1;
  }
  else
    {
      show_room(environment(),
        "Hrok makes some strange gestures.\n"
        "The scroll burns to ashes.\n"
        "Hrok blushes deeply.\n"
        "Hrok stumbles: I'm sooo sorry. I must have made a little mistake.\n");
      scr->remove();
    }
  return 1;
}
