/*
   Beach inheritable object for FR OMIQ ... bingle on
*/

inherit "/std/room";

init()
{
  add_action("get_sand", "*", 1000);
  ::init();
}


int get_sand(string bong)
{
  string *bing;  
  object wibble;
  bing=explode(bong, " ");
  if(bing[0]!="get" || bing[0]!="fill" || bing[0]!="put") return 0;
  if(member_array("bucket", bong)==-1 && (bong!="fill bucket with sand" || bong!="put sand in bucket" || bong!="get sand in bucket"))
  {
    notify_fail("The sand dribbles all over the place.  You'll need something solid "+
		"to carry it in.\n");
    return 0;
  }
  wibble=clone_object(SAND_OBJECT);
  wibble->move(present("bucket", this_player())); 
  return 1;
}
