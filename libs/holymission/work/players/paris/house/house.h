#define CHANCES 4

int _goRead(string str) {
  if (str == "scraps of paper" || str == "scrap of paper") 
    if ("players/paris/house/study"->readpaper() <= CHANCES) {
      printf("The scrap of paper says: %s.\n", 
	     (random(100) < this_player()->query_int()) ?
	     "players/paris/house/study"->query_pass()  :
	     "players/paris/house/study"->gen_str()
	     );
      say(capitalize((string)this_player()->query_name())
	  + " reads a scrap of paper on the desk.\n",
	  this_player());
      return 1;
    } else {
      printf("You cannot see any other scraps of paper to read.\n");
      return 1;
    }
  return 0;
}

