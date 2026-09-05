#define LOCATION "/room/plane12"

reset(arg) {
  if(!arg) {
    start_shadow();
  }
}

start_shadow() {
  shadow(find_object(LOCATION),1);  
}

void stop_shadow() {
  shadow(find_object(LOCATION),0);
}

/*
The id's listed here are for item descriptions.
*/
id(str) {
  return str=="structure" ||
         str=="columns" ||
         str=="shrine";
}

long(str) {
  if(!str)
    write(
"  Here, in the middle of the windswept plains of northwestern Nirvana,\n\
a time-worn structure, constructed of marble, has stood the test of time.\n\
A flight of steps leads between a pair of towering corinthian columns, and\n\
into the marble shrine.  To the west is a forest.\n\
    There are three obvious exits: west, east and south\n"
    );
  else
    switch(str) {
      case "structure": write("They look nifty.\n");
                        break;
      case "columns": write("They look really nifty.\n");
                      break;
      case "shrine": write("That also looks nifty.\n");
                     break;
   }
}

query_long() {
  return 0;
}
