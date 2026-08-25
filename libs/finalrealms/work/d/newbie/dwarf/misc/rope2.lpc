inherit"std/object";
 
void init() {
    add_action("get_me","get");
     add_action("do_climb","climb");
     ::init();
}
 
void setup()
{
set_name("coil of rope");
add_alias("50 ft. of rope");
set_main_plural("ropes");
   set_short("Coil of rope (Tied off)");
   set_long("This is a 50 ft. section of rope.  It is tied off.\n");
 
  reset_get();
set_value(3000);
}
 
 
int get_me(string str)
{
if(str == "rope" || str =="all")
   {
      write("The rope is securely tied.  You can't get it.\n");
      return(1);
   }
return(0);
}
int do_climb(string str)
{
   if(str == "rope")
   {
   if(this_player()->query_property("skill_rope_climbing"))
     {
      write("You grasp the rope with both hands and begin to climb "
             "down the rope.  You were doing very well until the old, "
             "raggedy rope begins to fray.  You make it to within "
             "30 ft. of the bottom of the mountain before the rope "
             "breaks.\n\n"
             "You fall head over heals down the rocky slope and "
             "land at the base with a resounding THUD!. \n\n"
             "You awaken sometime later to hear voices all around "
             "you.  You can see several figures moving around you, "
             "but your eyes are unable to focus on them as you slip "
             "back into unconciousness .................\n\n"
                 "You awaken sometime later in new surroundings"
                 ".............\nYou had better look around.\n");


   //This is the code to add clans to the player
     switch(random(100) ) {
       case 0..50:
         this_player()->set_race_group_ob("/std/race_groups/stonereaver");
         write("Clan Stonereaver pays your hospital bill.\n");
    write_file("/d/newbie/logs/STONEREAVER",this_player()->query_cap_name()+" is now a member of Stonereaver clan at "+ctime(time())+"\n");
        break;

       case 51..99:
          this_player()->set_race_group_ob("/std/race_groups/blackanvil");
          write("Clan Black Anvil pays your hospital bill.\n");
    write_file("/d/newbie/logs/BLACKANVIL",this_player()->query_cap_name()+
     "is now a member of Blackanvil clan at "+ctime(time())+"\n");
       break;
             } //end code to add clans

    this_player()->move("/d/mm/Cities/khazad-khadum/rooms/clinic");
       this_object()->dest_me();
      return(1);
      }
   else
   {
      write("You are not skilled enough to climb down there.\n");
      return(1);
   }
   }
}
