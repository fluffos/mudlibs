#include <std.h>
#include <daemons.h>

#define BASE_DIR "/d/nopk/tirun/obj/"
#define ARMOUR_DIR BASE_DIR+"armour/"
#define WEAPON_DIR BASE_DIR+"weapon/"
#define ROSE_DIR BASE_DIR+"misc/gifts/"

inherit MONSTER;

int test_heart;
mapping items;

void create()
{
 ::create();
 set_name("rejik the peddler");
 set_level(20);
 set_short("Rejik the peddler");
 set_long("A stout middle aged man selling gifts. Say list items to have Rejik "
          "tell you what he has and how much it costs. It is rumored he may also sell armour and weapons.");
 set_race("human");
 set_body_type("human");
 set_gender("male");
 set_id( ({ "rejik", "peddler", "rejik the peddler" }) );
 set_heart_beat(1);
 set_patrol(12, ({ "west", "south", "south", "east", "east", "north", "north", "west", }) );
 set_emotes(3,({
   "%^CYAN%^Rejik exclaims: %^RESET%^Fresh cut roses for sale!",
}),0);
 set_exp(1);
 add_money("copper", random(1000));

  items = ([]);
  items["red rose"] = ({ ROSE_DIR+"redrose", "copper", 52 });
  items["redrose"] = items["red rose"];
  items["white rose"] = ({ ROSE_DIR+"whiterose", "copper", 52 });
  items["whiterose"] = items["white rose"];
  items["yellow rose"] = ({ ROSE_DIR+"yellowrose", "copper", 52 });
  items["yellowrose"] = items["yellow rose"];

  items["newbie guide"] = ({ BASE_DIR+"misc/newbieguide", "gold", 1 });
  items["newbieguide"] = items["newbie guide"];
  items["guide"] = items["newbie guide"];

  items["sword"] = ({ WEAPON_DIR+"noobsword", "gold", 1 });
  items["club"] = ({ WEAPON_DIR+"noobclub", "gold", 1 });
  items["dagger"] = ({ WEAPON_DIR+"noobdagger", "gold", 1 });
  items["axe"] = ({ WEAPON_DIR+"noobaxe", "gold", 1 });
  items["flail"] = ({ WEAPON_DIR+"noobflail", "gold", 1 });
  items["spear"] = ({ WEAPON_DIR+"noobspear", "gold", 1 });
  items["bow"] = ({ WEAPON_DIR+"noobbow", "gold", 1 });

  items["helmet"] = ({ ARMOUR_DIR+"helmet", "gold", 1 });
  items["boots"] = ({ ARMOUR_DIR+"boots", "gold", 1 });
  items["chainmail"] = ({ ARMOUR_DIR+"chainmail", "gold", 1 });
  items["breastplate"] = ({ ARMOUR_DIR+"breastplate", "gold", 1 });
  items["raknidarmour"] = ({ ARMOUR_DIR+"raknidarmour", "gold", 1 });
  items["centaurblanket"] = ({ ARMOUR_DIR+"centaurblanket", "gold", 1 });
  items["weimicblanket"] = ({ ARMOUR_DIR+"weimicblanket", "gold", 1 });
}
int is_invincible() {return 1;}
void init()
{
 ::init();
 add_action("fBuy", "buy");
 add_action("fList", "list");
}
int fBuy(string str) {

  mixed *tmp;
  object tp = this_player();
  object ob;
  string file;
  string cur;
  string short;
  int cost;
  int ret;

  if (!str) {
    command("say Buy what?");
    return 1;
  }

  if (str == "armour") {
    switch (tp->query_race()) {
      case "raknid":
        str = "raknidarmour";
      break;

      case "minotaur":
      case "weimic":
      case "centaur":
        str = "breastplate";
      break;

      default:
        str = "chainmail";
    }
  }
  else if (str == "blanket") {
    switch (tp->query_race()) {
      case "weimic":
        str = "weimicblanket";
      break;

      default:
        str = "centaurblanket";
    }
  }

  tmp = items[str];
  if (nullp(tmp) || !arrayp(tmp) || sizeof(tmp) < 3) {
    command("say I don't have that for sale.");
    return 1;
  }

  file = tmp[0];
  cur = tmp[1];
  cost = tmp[2];

  if (tp->query_money(cur) < cost) {
    command("say You don't have enough "+cur+" for that, "+
      tp->query_cap_name()+".");
    return 1;
  }

  tp->add_money(cur, -cost);

  ob = new(file);
  short = indefinite_article(strip_color(ob->query_short()));

  if (ob->move(this_object())) {
    ob->move(environment(tp));
    command("emote drops "+short+".");
  }
  else {
    ret = command("give "+ob->query_id()[0]+" to "+tp->query_name());
    if (!ret)
      command("drop "+ob->query_id()[0]);
  }

  return 1;
}

int fList(string str) {

  if (!str)
    str = "items";

  switch (str) {
    case "items":
      command("say I have red, white, and yellow roses "
        "on sale for 52 copper each.");
      command("say I also sell newbie guides for 1 gold coin each.");
    break;

    case "armor":
    case "armors":
    case "armour":
    case "armours":
      command("say I have armour, helmets, boots, and blankets "
        "for 1 gold each.");
    break;

    case "weapons":
      command("emote glances around nervously.");
      command("say How did you find out??");
      command("say Well don't tell anyone, the law around here is strict about who sells weapons.");
      command("say I have swords, clubs, daggers, axes, flails, spears, "
        "and bows for 1 gold each.");
    break;

    default:
      command("say I don't sell that.");
  }

  return 1;
}

int test_heart() { 
    if(!heart_beat_on) set_heart_beat(heart_beat_on = 1);
 return 1; 
}

void catch_tell(string str) {
  string cmd, what;

  if (!str) return;

  str = strip_color(str);

  if (sscanf(str, "%*s says: %s %s", cmd, what) == 3) {
    if (cmd == "list")
      fList(what);
    else if (cmd == "buy")
      fBuy(what);
  }

}

