inherit "players/cashimor/inherit/water";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="All at sea";
    long_desc="You are swimming out at the sea.\n";
    set_light(1);
    dest_dir=({"room/jetty2","west"});
    nodanger=1;
    floats="room/sea_bottom";
    smell="You have salt in your nose.";
  }
}

init() {
  ::init();
  this_player()->set_smell("You smell salt seawater.");
  add_action("dive","dive");
  add_action("enter", "enter" );
  add_action("enter", "climb" );
}

dive() {
  this_player()->move_player("down#room/sea_bottom");
  return 1;
}

enter( arg )
{
   if ( !arg )
      return;
      
   if ( arg == "ship" || arg == "junk" || arg == "cargo junk" ) {
      if ( present( "cargo_junk", this_object() ) )
         this_player()->move_player( "up to the junk#players/patience/ezo/cargoJunk" );
      else
         write( "Do you see a ship here ?\n" );
   
      return( 1 );
   }
   
   return( 0 );
}
