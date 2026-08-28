#include <level.h>

#define MORTAL_BELL_DELAY       120

int time;

int main (string str)
{
    object ob;
    string kruiks;
    int time2;
    if (!str) {
        write ("usage: bell <player>\n");
        return 1;
    }
    ob = find_player(lower_case(str));
    if (!ob) {
        write ("No such player!\n");
        return 1;
    }

    if (THIS->query_security() < 2)
        if ((time() - time) < MORTAL_BELL_DELAY)
        {
            time2 = (MORTAL_BELL_DELAY - (time() - time));
            message("standard", "Not enough power in the world. You have to wait ^c1" +
              time2 + "^c0 seconds.\n", THIS);
            return 1;
        }

    time = time ();
    kruiks = sprintf ("%c", 7);
    tell_object (ob, kruiks);
    tell_object (ob, "*KLONK!* " + capitalize(this_player()->query_name()) +
      " just rang a bell that echoes in your head!\n");


    write ("You just belled " + capitalize(str) + ".\n");
    return 1;

}

query_author()
{
  return "namhas";
}

query_synopsis()
{
  return "bell <player>";
}

query_help()
{
  return "This will send a beep character (ASCII 7) to <player>'s "
       + "terminal. Do NOT use this to harass other players.";
}

query_position ()
{
  return POS_RESTING;
}

