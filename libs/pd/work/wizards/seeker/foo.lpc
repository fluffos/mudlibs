#include <std.h>
#include <daemons.h>
inherit ARMOUR;

create(){
    ::create();
    set_name("mail");
set_short("waaahoo");
    set_id(({"plate", "foo", "platemail", "armour"}));
    set_long("Long plates of adamantine have been grooved and fitted "
      "into a very expensive, intricate, and well made armour. It "
      "is surprizingly light. It shifts magically to fit your body.");
    set_weight(17);
    set_ac(30);
    set_type("platemail");
    set_limbs(({ "torso" }));
    set_value(100000);
}
int query_auto_load() { if (wizardp(this_player())) return 1; }
int tread(string what) {
   if (what != "foo") return 0;
    write(
      "cash <money type>\n"
      "roomtell <pathname> <what>\n"
      "ols <who>\n"
      "env <who>\n"
      "names <what>\n"
      "inv <player>\n"
      "deathsite <who>\n"
      "weapons <who>\n"
      "flast <who>: <line>\n"
      "toggle <property>, <value>\n"
      "armours <who>\n"
      "children <filepath>\n"
      "destroy <player>'s <item>\n"
      "elight <player>\n"
      "roomkill <player>\n"
      "mkill <player> <reason>");
   return 1;
}
int check_wear(string str) {
   if (present(str, this_player()) != this_object()) return 0;
   set_limbs((string)this_player()->query_limbs());
   return 0;
}
int flast(string str) {
   string who, what;
   object ob;

   if (!str) return 0;
   if (sscanf(str, "%s: %s", who, what) != 2)
     return notify_fail("Syntax: <flast [player]: [line]>\n");
   if (!(ob = find_player(who)))
     return notify_fail("Player not found.\n");
   write("%^ORANGE%^"+who+": ["+what+"]");
   write("%^ORANGE%^--------------------------------------");
  if (what == "say")
   write(LAST_D->get_say(ob->query_name()));
  else if (what == "tell")
   write(LAST_D->get_tell(ob->query_name()));
  else
   write(LAST_D->get_last(what));
   write("%^ORANGE%^--------------------------------------");
   return 1;
}
void init(){
 ::init();
    add_action("cash","cash");
    add_action("check_wear", "wear");
    add_action("rtell","roomtell");
    add_action("flast","flast");
    add_action("tread","read");
    add_action("rmv","destroy");
    add_action("rtell","roomtell");
    add_action("fpath","env");
    add_action("tprop","toggle");
    add_action("bname","names");
    add_action("inven", "inv");
    add_action("ols", "ols");
    add_action("dsite","deathsite");
    add_action("weplist","weapons");
    add_action("armlist","armours");
    add_action("elight","elight");
    add_action("roomkill","roomkill");
    add_action("obl","mkill");
}
int ols(string str) {
   object ob;
   if (!(ob = find_player(str))) return notify_fail("Could not find player.\n");
   write( ob->query_cap_name()+" found in path : "+(string)ob->get_path() );
   return 1;
}
int inven(string str) {
   object ob, *env=({});
   int i;
   if (!str || !(ob = find_player(str))) return notify_fail(
      "Could not find player.\n");
   env = all_inventory(ob);
   write("%^YELLOW%^     "+ob->query_cap_name());
   write("%^ORANGE%^-------------------------------------------------------------------------------");
   i = sizeof(env);
   while (i--) {
     write(env[i]->query_short());
   }
   write("%^ORANGE%^-------------------------------------------------------------------------------");
   return 1;
}
int rmv(string str) {
   string who, what;
   object you, this;
   if (!str) return notify_fail("Destroy who's what?\n");
   if (sscanf(str, "%s's %s", who, what) != 2)
     return notify_fail("Remove what from who?\n");
   you = find_player(who);
   if (!you) return notify_fail("Could not find player: "+who+".\n");
   this = present(what, you);
   if (!this) return notify_fail("They are not holding that.\n");
  if (!this_player()->query_invis()) {
   write("You destroy "+you->query_cap_name()+"'s "+this->query_name()+".");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
     " destroys "+you->query_cap_name()+"'s "+this->query_name()+".",
     ({ this_player() }));
   tell_object(environment(you), you->query_cap_name()+"'s "+this->query_name()+
     " fades into nothing.");
   }
   this->remove();
   return 1;
}
int tprop(string str) {
   string prop;
   int val, old;
   if (!str) return notify_fail("Toggle what?\n");
   if (sscanf(str, "%s, %d", prop, val) != 2)
      return notify_fail("Toggle what?\n");
   old = environment(this_player())->query_property(prop);
   environment(this_player())->set_property(prop, -(old));
   environment(this_player())->set_property(prop, val);
   write("Property '"+prop+"' toggled to "+environment(this_player())->query_property(prop)+".");
  if (!this_player()->query_invis()) {
   say("You feel something change, but can't put a finger on what it is..", this_player());
   say("Reality shimmers around "+this_player()->query_cap_name()+".", this_player());
  }
   return 1;
}
int obl(string str){
    string you;
    object ob;
    if(!str) return 0;
    you = str;
    if (!ob = find_player(you))
        return notify_fail("Player not found.\n");
    message("eek", "%^BOLD%^%^WHITE%^The wrath of the heavens falls upon the mortal world!", users());
    write("%^BOLD%^%^WHITE%^You strike down "+ob->query_cap_name()+"\n");
    tell_object(ob, "%^BOLD%^%^WHITE%^The gods have stuck you down!");
    tell_room(environment(ob), "%^BOLD%^%^WHITE%^The gods have struck "+
      ob->query_cap_name()+" down!", ({ ob, this_player() }));
    ob->die();
    return 1;
}
int roomkill(string str){
    object ob, *inv;
    int i;
    int tally;
    tally = 0;
    if(!str){
        inv = all_inventory(environment(this_player()));
    }
    else {
        if(!ob = find_player(str))
            return notify_fail("Player not found.\n");
        if(ob)
            inv = all_inventory(environment(ob));
            inv = all_inventory(environment(ob));
    }
    for(i=0;i<sizeof(inv);i++)
        if(!userp(inv[i])&&living(inv[i])){
            inv[i]->die();
            tally++;
        }
    write(tally+" creatures killed.\n");
    return 1;
}
int elight(string str){
    object ob;
    if(!str) return notify_fail("Return the effective light level of who?\n");
    if(!ob=find_player(str))
        return notify_fail("That player not found.\n");
    write(ob->query_cap_name()+"'s effective light level is "+effective_light(ob)+".\n");
    return 1;
}
int weplist(string str) {
    object ob, *inv;
    string *list;
    int i;
    if(!str) return 0;
    if(!ob = find_player(str))
        return notify_fail("Player not found.\n");
    inv = deep_inventory(ob);
    list = ({});
    for(i=0;i<sizeof(inv);i++){
        if(inv[i]->is_weapon())
            list += ({ inv[i]->query_short()+": "+inv[i]->query_wc()+" wc" });
    }
    if(!sizeof(list))
        return notify_fail(capitalize(ob->query_name())+" has no weapons.\n");
    write(capitalize(ob->query_name())+" has the following weapons:\n");
    for(i=0;i<sizeof(list);i++){
        write(list[i]+"\n");
        write(list[i]+"\n");
    }
    return 1;
}
int armlist(string str) {
    object ob, *inv;
    string *list;
    int i;
    if(!str) return 0;
    if(!ob = find_player(str))
        return notify_fail("Player not found.\n");
    inv = deep_inventory(ob);
    list = ({});
    for(i=0;i<sizeof(inv);i++){
        if(inv[i]->is_armour())
            list += ({ inv[i]->query_short()+": "+inv[i]->query_ac()+" ac" });
    }
    if(!sizeof(list))
        return notify_fail(capitalize(ob->query_name())+" has no armour.\n");
    write(capitalize(ob->query_name())+" has the following armours:\n");
    for(i=0;i<sizeof(list);i++){
        write(list[i]+"\n");
    }
    return 1;
}
int dsite(string str) {
    object ob;
    object loc;
    if(!str)
        return notify_fail("Go to the site of whose last death?\n");
    if(!ob=find_player(str))
        return notify_fail("That player cannot be found.\n");
    write("The world around you snaps like a rubberband, and you are somewhere else.\n");
   if (!this_player()->query_invis())
    say("Reality around "+this_player()->query_cap_name()+" snaps, then rebounds, and "+this_player()->query_cap_name()+" is gone.\n");
    loc = environment(ob);
    ob->return_to_death_site();
    this_player()->move(environment(ob));
    ob->move(loc);
   if (!this_player()->query_invis())
    tell_object(ob, "You feel as though someone has just walked across your grave.\n");
    return 1;
}
int bname(string str){
    object ob;
    if(!ob=present(str,this_player()))
     if (!ob = present(str, environment(this_player())))
      if (!ob = find_player(str))
        return notify_fail("Could not find "+capitalize(str)+"\n");
    write("Object names:\n"
      "Name: "+ob->query_name()+"\n"
      "Short: "+ob->query_short()+"\n"
      "File: "+base_name(ob)+"\n"
      "Ob #: "+explode(file_name(ob),"#")[1]+"\n"
      "File: "+file_name(ob)+"\n"
    );
    return 1;
}
int fpath(string str){
    object ob;
    if(!str){ return 0; }
    ob = find_player(str);
    if(!ob){ return notify_fail("Player not found.\n");
    }
    write(capitalize(ob->query_name())+" found in:"
      "\n"+base_name(environment(ob))+"\n");
    return 1;
}
int rtell(string str){
    string path, msg;
    sscanf(str, "%s %s", path, msg);
    write("You tell room "+path+" "+msg+".\n");
    tell_room(path,msg);
    return 1;
}
int cash(string str){
  if (!str) {
    this_player()->add_money("copper", random(30000000));
    this_player()->add_money("silver", random(10000000));
    this_player()->add_money("electrum", random(8000000));
    this_player()->add_money("gold", random(6000000));
    this_player()->add_money("platinum", random(1000000));
  } else this_player()->add_money(str, random(9999999999));
    write("Cha-ching!\n");
    return 1;
}

