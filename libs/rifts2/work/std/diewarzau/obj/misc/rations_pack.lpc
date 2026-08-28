inherit "/std/Object";

int picks_left;
int ration_type;

int id(string str) {
  if(!::id(str)) {
    if(ration_type && (str == "rich rations" ||
                       str == "pack of rich rations"))
      return 1;
    else if(!ration_type && (str == "standard rations" ||
                       str == "pack of standard rations"))
      return 1;
    return 0;
  }
  else return 1;
}

void create() {
  ::create();
  set_name("pack");
  set_id( ({ "pack", "rations pack", "rations" }) );
  set_short("A pack of 5 standard rations");
  picks_left = 5;
  ration_type = 0;
  set_long(
"This is a cloth pack containing rations which can be used for sustenance "
"on long journeys.  Before eating one, you must 'get' a ration from the "
"pack.");
  set_weight(50);
  set_value(20);
  return;
}

void set_rations(int num, int type) {
  picks_left = num;
  ration_type = (type?1:0);
  set_value((4 + ration_type*3) * num);
  set_short("A pack of "+consolidate(num, (ration_type?"rich":"standard")+
				     " ration"));
  return;
}

void init() {
  ::init();
  add_action("get_pick", "take");
  add_action("get_pick", "get");
  return;
}

int get_pick(string str) {
  string tmp1, tmp2;
  object ob;

  if(sscanf(str, "%s from %s", tmp1, tmp2) != 2) return 0;
  if(present(tmp2, this_player()) != this_object()) return 0;
  seteuid(getuid());
  ob = new("/std/food");
  ob->set_name("rations");
  ob->set_id(({ "ration", "rations", 
		  (ration_type?"rich ration":"standard ration") }) );
  ob->set_short("A "+(ration_type?"rich":"standard")+" ration");
  ob->set_long("A ration for travels, which may be eaten");
  ob->set_my_mess("The rations are satisfying.");
  ob->set_your_mess("eats a "+(ration_type?"rich":"standard")+" ration.");
  ob->set_strength(ration_type?25:13);
  if(!ob->id(tmp1)) {
    ob->remove();
    write("There is no '"+str+"'in the pack.");
    return 1;
  }
  picks_left--;
  write("Ok.");
  ob->move(this_player());
  if(picks_left <= 0) {
    write("Having taken the last ration from the pack, you discard it.");
    remove();
    return 1;
  }
  set_rations(picks_left, ration_type);
  return 1;
}
