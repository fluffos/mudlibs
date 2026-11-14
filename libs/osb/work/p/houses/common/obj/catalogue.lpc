/* The catalogue with all items the player can buy for their houses */

#include <moving.h>
#include <properties.h>

#define CATALOGREC   "/p/houses/common/service/catalogrec"
#define CATALOGSTORE load_object("/p/houses/common/obj/catstore")

inherit "/std/thing";

create()
{
  (::create());
  seteuid(getuid());
  if(member(object_name(), '#') == -1) return;
  SetShort("the OEFC catalogue");
  SetLong("This is the offical catalogue of the OEFC, the\n\
Old England Furniture Company.\n\
Please 'read' the catalogue for to look at the aviable furnitures we sell.\n\
You can you 'inform' about every item,\n\
and 'order' them if you want to buy it.\n");
  AddId("catalogue");
  AddAdjective("OEFC");
  AddAdjective("oefc");
  SetWeight(300);
  SetValue(10);
  SetProp(P_HELP_MSG,"Just read the catalogue!\n");
}

init()
{
  (::init());
  add_action("inform","inform");
  add_action("order","order");
}

QueryReadMsg() { return CATALOGREC->QueryReadMsg(); }

AddItem(string path) { return CATALOGREC->AddItem(path); }

get_ob(string str) { return CATALOGREC->get_ob(str); }

QueryItems() { return CATALOGREC->QueryItems(); }

inform(string str)
{
  object ob;

  if(!str || str == "") {
    notify_fail("Please try 'inform [about] <nr>' or 'inform [about] <item>'!\n");
    return 0;
  }
  if(str[0..5] == "about ") str = str[6..];
  if(!(ob = get_ob(str))) return 0;
  write(ob->QueryLong());
  if(!environment(ob)) {
    ob->remove();
    if(ob) destruct(ob);
  }
  return 1;
}

order(string str)
{
  object ob, env;
  string fail;
  int    value;
  string *paid;

  if(!str || str == "") {
    notify_fail("Please try 'order <nr>' or 'order <item>'!\n");
    return 0;
  }
  if(!(ob = get_ob(str))) return 0;
  if(!(env = environment(this_player()))
     ->QueryIsOwner(getuid(this_player()))) {
    notify_fail("You can't order any item for this room. It's not your own.\n");
    return 0;
  }
  if(fail = ob->install(env)) {
    notify_fail("You can't buy that item.\n" + fail);
    return 0;
  }
  if("/lib/money"->QuerySomeonesValue(this_player())
     < (value = 3 * ob->QueryValue())) {
    notify_fail("You don't have enough money.\n");
    return 0;
  }
  paid = "/lib/money"->PayValue2(this_player(),value);
  if(!pointerp(paid)) switch(paid) {
      case 3: return notify_fail("You don't have enough coins of the right currencies, sorry.\n"),0;
      default: return notify_fail("You can't pay, but I don't know why.\n");
   }
  write("You order " + ob->QueryShort() + "\nand pay " + paid[0] +
	" therefor.\n" + (paid[1]?"You get " + paid[1] + " back.\n":""));
  env->AddItem(explode(object_name(ob),"#")[0]);
  env->update_file();
  if(!environment(ob) || object_name(environment(ob)) != CATALOGSTORE) {
    ob->remove();
    if(ob) destruct(ob);
  }
  return 1;
}
