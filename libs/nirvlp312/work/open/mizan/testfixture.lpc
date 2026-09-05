inherit "obj/monster";

reset(arg)
{
   object gold, what;
   ::reset(arg);

   if(arg) return;
   
   /* descriptions */
   set_name("Combat Fixture");
   set_race("robot");
   set_alias("fixture");
   set_short("Combat Fixture (neutral)");
   set_long("This is a combat fixture, or training robot. You can use it to spar\n"+
            "against, but be careful as it can kill you like any other monster!\n"+
            "You are able to manipulate the AC and WC of this monster with the\n"+
            "commands 'setwc X' and 'setac X'. You can stop combat with the command\n"+
            "'chill'.\n");
   
   /* vital stats */
   set_level(19);
   set_hp(10000);
   set_al(0);
   set_wc(20);
   set_ac(20);
   
}

int old_hp;

init()
{
    ::init();
    add_action("on_setwc","setwc");
    add_action("on_setac","setac");
    add_action("on_chill","chill");

}

heart_beat()
{
   int my_hp;

   my_hp = query_hp();
   if(old_hp && old_hp != my_hp)
   {
      say("DAM INFLICTED: [" + (old_hp - my_hp) + "]\n");
   }

   old_hp = my_hp;

   ::heart_beat();
}

long()
{
    ::long();
    write("AC is currently: " + query_ac() + ".\n");
    write("WC is currently: " + query_wc() + ".\n");
}

on_setwc(arg)
{
    if(!arg) return 0;
    set_wc(arg);
    write("Done.\n");
    return 1;
}

on_setac(arg)
{
    if(!arg) return 0;
    set_ac(arg);
    write("Done.\n");
    return 1;
}

on_chill()
{
    this_object()->attack_object();
    this_player()->attack_object();

    this_object()->stop_hunted();
    this_player()->stop_hunted();

    this_object()->stop_fight();
    this_player()->stop_fight();

    this_object()->attack_object();
    this_player()->attack_object();

    write("Done.\n");
    return 1;
}