inherit "/std/item";
string mytrap = "/baseobs/traps/acidtrap";

void setup()
{
   add_property("guild",({"assassin","bard", }));
   set_name("unarmedtrap");
   set_short("Trap");
  add_alias("trap");
   set_long("A small wooden rune covered box. The runes say: "
   "\"trap <player> to arm me.\"\n");
   set_value(3000);
   set_weight(50);
   set_holdable(1);
}
void init()
{
   ::init();
   add_action("trap","trap");
}
int trap(string str)
{
   object tr;
   if(!query_in_use())
   {
      notify_fail("You have to hold the trap to set it.\n");
     return 0;
   }
   tr = clone_object(mytrap);
   tr->add_property("player",str);
   tr->move(ENV(TP));
  tr->set_power(50);
   call_out("dest_me",0);
   tell_object(TP,"You carefully whisper the victims name to the trap and place it on the ground.\n");
   if(!TP->query_hide_shadow())tell_room(ENV(TP),"You hear the name \" "+str+"\" whispered.\n",({TP}));
   return 1;
}
