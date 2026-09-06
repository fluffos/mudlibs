/* made by RoomMaker V0.991 (c) Sique 2/1993 */

#include <moving.h>
#include <secure/wizlevels.h>
#include "/sys/houses.h"
#define PL this_player()
#define ME this_object()
#define SK_ID lower_case(({string})QueryShopkeeper()->QueryName())
#define SK_SHORT ({string})QueryShopkeeper()->QueryShort()
#define SK_CSHORT capitalize(({string})QueryShopkeeper()->QueryShort())
#define CUSTOMER_NAME (({string})PL->QueryName())
#define LSF(x) symbol_function(x,ME)
#define ESF(x) symbol_function(x)

inherit "/std/shop";

varargs void SetStore() { }
object GetStore()
{
  return load_object(POOLFILE);
}

varargs int GetPrice(object ob) { return ({int})ob->QueryValue(); }

public varargs void create()
{
  (::create());
  SetIntShort("an estate agency");
  SetIntLong(
    "You are in an estate agency. You can buy properties here.\n"
    "The estate agent offers you some buildings somewhere in the world.\n");
  // BEGONE SetShopkeeper("/d/avalon/common/livings/agent");
  RemoveDustbin();
  RemoveStore();
  SetIdentify(0);
  SetSell(0);
  SetAppraise(0);
  SetSecurity(1);
  SetSignDesc(
    "The shop-assistant can understand the following commands:\n"
    "'list'      gives you an overview about the buyable properties.\n"
    "'buy <nr>'  Buy the property with number <nr> from the last list that\n"
    "            the shop-assistant has showed to you.\n");

//  reset(1); /* kludge, but now it clones the makler *shrug * */
}

public varargs int buy_routine(object ob)
{
  string dir;

  if(IS_WIZARD(this_player()))
    return notify_fail(
      lambda(0,
        ({LSF("SkSay"),
          CUSTOMER_NAME+
          ", I don't sell you a property. Code it yourself!\n"
        })));
  if(IS_IMMORTAL(this_player()))
    return notify_fail(
      lambda(0,
        ({LSF("SkSay"),
          CUSTOMER_NAME+
          ", I don't sell you a property. Become a wizard "
          "and code it yourself!\n"
        })));
  if(getuid(this_player()) == "guest")
    return notify_fail(
      lambda(0,
        ({LSF("SkSay"),
          CUSTOMER_NAME+
          ", you can't buy properties. Please choose your own character.\n"
        })));
  if(!CheckTrade(ob) || !CheckLivingTrade(ob))
    {
      SkSay("Oh, I don't trade with " + ({string})ob->QueryShort() + "!\n");
      Say(SK_CSHORT+" removes "
	  +({string})ob->QueryShort()+" from the store.\n");
      destruct(ob);
      return 1;
    }

  /* Test coins of customer. */
  if(!check_money(GetPrice(ob), 1)) return 0;

  /* Check if player can carry the item. */
  if(!({int})PL->MayAddWeight(({int})ob->QueryWeight()))
    return notify_fail(
      lambda(0,
        ({LSF("SkSay"),
          CUSTOMER_NAME+
          ", you can't carry that much.\n"
        })));

    /* Check if the player has already a property in this region */
  if(file_size(dir = ({string})ob->QueryHomedir() + "/" + getuid(this_player())) == -2)
    return notify_fail(
      lambda(0,
        ({LSF("SkSay"),
          CUSTOMER_NAME+
          ", you have already a property in that region!\n"
        })));

    /* Check if we can connect the property to the world */
  if(!({int})ob->ConnectProperty(getuid(this_player())))
    return notify_fail(
      lambda(0,
        ({LSF("SkSay"),
          CUSTOMER_NAME+
          ", you can't buy that property. It isn't connected to a road yet.\n"
        })));

    /* Check if we can build the property */
    if(!({int})ob->MakeProperty(getuid(this_player())))
      {
        (({string})ob->QueryExitpath())->DeleteHome(getuid(this_player()));
        return notify_fail(
          lambda(0,
            ({LSF("SkSay"),
              CUSTOMER_NAME+
              ", you can't buy a property in that region!\n"
            })));
      }
  /* Get coins from customer. */
  if(!check_money(GetPrice(ob))) return 0;

  /* remove the property from list */

  GetStore()->RemoveProperty(({string})ob->QueryHomedir(),
                             ({string})ob->QueryExitverb(),
                             ({string})ob->QueryExitpath());

  /* Move player to the new property */

  call_out("to_new_property",2,
           ({PL,dir + "/garden1"}));
  /* Handle item. */
//  write (SK_CSHORT + " gives " + ob->QueryShort() + " to you.\n");
//  show ( ({ SK_CSHORT+" hands "+ob->QueryShort()
//    +" to "+ CUSTOMER_NAME+".\n"
//    , "Something happens.\n" }));
  QueryShopkeeper()->Give(ob, PL);
  return 1;
}

void to_new_property(mixed player_home)
{

  object goback;

  tell_object(player_home[0],SK_CSHORT +
              " tells you: lets go to your new property.\n");
  goback = clone_object("/d/avalon/common/std/goback");
  goback->Set("go_back",object_name());
  goback->move(player_home[0],M_SILENT);
  player_home[0]->move(player_home[1], M_GO, "home");
}

void reset() {
  if (object_name(this_object())=="/room/agency") return;
  ::reset();
}
