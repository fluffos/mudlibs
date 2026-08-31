#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_id( ({ "orb", "posession orb" }) );
   set_name("posession orb");
   set_short("Posession Orb");
    set_long("This orb allows you to posess a creature, controlling it from afar.");
}

void init()
{
 ::init();
 add_action("filter", "");
}

int filter(string str)
{
  object ob;

  if(this_player()->query_forced())
    return 0;

  if (query_verb()[0] == '&')
   {
write(query_verb()[1..sizeof(query_verb())-1]+" "+str);
    this_player()->force_me(query_verb()[1..sizeof(query_verb())-1]+" "+str);
    return 1;
   }
 
 if (query_verb() == "stop")
   {
    write("You end your posession.");
    if(!this_player()->query("posessed"))
      return 1;
    this_player()->query("posessed")->set("posessed", 0);
    this_player()->set("posessed", 0);
    return 1;
   }

 if (query_verb() == "posess")
   {
     if(!ob = present(str, environment(this_player())))
    {
      write("Could not find "+str+".");
      return 1;
    }
    if(!ob->is_living())
    {
       write(ob->query_short()+" cannot be posessed.");
       return 1;
    }
    this_player()->set("posessed", ob);
    ob->set("posessed", this_player());
    write(ob->query_short()+" posessed.");
    return 1;
   }

 ob = this_player()->query("posessed");

 if(!ob)
   return 0;
 if(!ob->query("posessed")) {
   this_player()->set("posessed", 0);
   return 0;
 }

 if(query_verb() == "look" || query_verb() == "l")
 {
   message("info", environment(ob)->query_long(), this_player(), 0);
   message("info", environment(ob)->query_long_exits(), this_player(), 0);
   message("info", environment(ob)->describe_living_contents( ({ ob }) ), this_player(), 0);
   message("info", environment(ob)->describe_item_contents(({})), this_player(), 0);
   return 1;
 }

if(str)
 ob->force_me(query_verb()+" "+str);
else
 ob->force_me(query_verb());
 return 1;
}

int query_auto_load() { return 1; }
