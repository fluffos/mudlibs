//ILz
// (04-06-98) Chronos fixed the help() and made it handle arguments better.
//            It also now makes sure you have all the arguments you need,
//            and makes sure the person is present before you start doing
//            anything substantial.  Why crunch numbers when all you have
//            to do is return an error msg?
 
#include <mudlib.h>
 
inherit DAEMON;

string help() ;
 
int cmd_mock(string str) {
  int last, x;
  object *people;
  string nam, name, verb_a = "say", verb_b = "says" ;
// Let's make sure we have both arguments that we need.
  if (!str || sscanf(str, "%s %s", name, str) != 2) {
    write(help()) ;
    return 1;
  }
// This is probably not even necessary.
  if (!name || !str) {
    write(help()) ;
    return 1;
  }
// Is our victim here?
  if (!present(lower_case(name),environment(TP))) {
    write("That person is not present.\n") ;
     return 1;
  }
// Now start calling all the functions that DO something.
  people = all_inventory(environment(TP)) ;
  last = str[<1];

  if (last == '?') {
    verb_a = "ask";
    verb_b = "asks";
  }
  if (last == '!') {
    verb_a = "exclaim";
    verb_b = "exclaims";
  }

  if (!(this_player()->query_skill("Ventriloquism"))){
   write("You require the ventriloquism skill to mock someone's voice!\n");
  return 1;
  }

  for (x=0;x<sizeof(people);x++) {
    if (!living(people[x])) continue;
    if (people[x]==this_player()) {
      message("say", wrap("You mock "+name+" and "+verb_a+": "+str+"\n"), this_player() );
    } else {
            tell_object(people[x] ,wrap(capitalize(name)+" "+verb_b+": "+str) );
        }
  }
  return 1;
}
 
string help() {

return @HelpText
Usage: mock <person> <msg>

This command allows you to attempt to use your Ventriloquism skills to
mock someone in the room.

See also: say, tell, whisper, shout, yell, wreply, to
HelpText;
}

