inherit "/std/item";
int query_auto_load() { return 1; }

void setup()
{
  reset_drop();
   set_name("aura of menace");
   set_long("An aura of extremem menace.\n");
}
void init()
{
   ::init();
/*
   if(TP && (! TP->query_creator() || !(TP->query_race() == "stalker")))
   {
      call_out("dest_me",0);
   return;
   }
*/
   tell_object(TP,"'superhide' to disappear, 'sneak' to sneak.\n");
   add_action("hide","superhide");
   add_action("sneak","sneak");
}
int sneak(string str)
{
   return "/std/commands/sneak"->sneak(str,TP);
}
int hide(string str)
{
    return "/std/commands/omiq_hide"->hide_in_shadows(str,TP);
}
