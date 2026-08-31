#include <std.h>
inherit ROOM;
mapping quicksand;
void create()
{
 ::create();
 quicksand = ([]);
 set_short("IN QUICKSAND!");
 set_long("%^ORANGE%^The ground is extremely wet and seems to sink as you walk "
          "in it. There are several long branches from the near by trees "
          "overhanging you. %^RESET%^");
 
 set_exits( ([ "west" : "plateau2" ]) );
}
void init()
{
 ::init();
 if (this_player()->is_player()) call_out("sink", 5, this_player());
}
int use_exit()
{
 string exit;
 exit = query_verb();
 if (!quicksand[this_player()]) 
   {
    return ::use_exit();
   }
 write("%^YELLOW%^You attempt to swim out of the quick sand a little and succeed.");
 quicksand[this_player()]--;
 return 1;
}
int sink(object ob)
{
 if (environment(this_player())!=this_object()) 
   {
    map_delete(quicksand, ob); 
    return 0;
   }
 
 quicksand[ob] += 1;
 message("info", "%^ORANGE%^You sink into the ground slowly.", ob);
 message("info", "%^ORANGE%^"+ob->query_short()+" sinks into the ground slowly.", environment(ob), ob);
 if (quicksand[ob] > 12) 
   {
    write("%^YELLOW%^You suffocate and lose conciousness.");
    ob->die();
    map_delete(quicksand, ob);
   } else
 if (quicksand[ob] > 7)
   write("%^RED%^%^BOLD%^You are starting to lose conciousness.");
  else
if (quicksand[ob] > 5)
   write("%^RED%^Your starting to have trouble breathing.");
call_out("sink", 5, ob);
}
