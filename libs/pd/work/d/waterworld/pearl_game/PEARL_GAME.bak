#include <std.h>
#include <waterworld.h>
void execute_pearl_game(int max, object tp)
{
    int x = random(max) + 1;
    object obj;

   switch (x) {
    
   case 10000:
        message("info", "You found a blood pearl!", tp);
        message("info", tp->query_cap_name() + " found " +
                "a blood pearl!", environment(tp), tp);
        new(PEARLS"blood_pearl.c")->move(tp);
        break;
  case 9995 .. 9999 :
        message("info", "You found a star pearl!", tp);
        message("info", tp->query_cap_name() + " found " +
                "a star pearl!", environment(tp), tp);
         new(PEARLS"star_pearl.c")->move(tp);
         break;
   case 9984 .. 9994 :
        message("info", "You found a rose pearl!", tp);
        message("info", tp->query_cap_name() + " found " +
                "a rose pearl!", environment(tp), tp);
        new(PEARLS"rose_pearl.c")->move(tp);
        break;
   case 9963 .. 9983 :
                 message("info","You found a purple pearl!!", tp);
                 message("info", tp->query_cap_name()+" found a Purple Pearl!!",environment(tp), tp);
                 new(PEARLS"purple_pearl.c")->move(tp);
                 break;
   case 9982 .. 9962 :
              message("info",tp->query_cap_name()+" located a Blue pearl!!",environment(tp),tp);
              new(PEARLS"blue_pearl.c")->move(tp);
              break;
    case 9361 .. 9861 :
               message("info","You located a black pearl!!",tp);
               message("info",tp->query_cap_name()+" located a Blue pearl!!",environment(tp),tp);
               new(PEARLS"black_pearl.c")->move(tp);
              break;
    case 7360 .. 9360 :
        message("info", "You found a white pearl!", tp);
        message("info", tp->query_cap_name() + " found " +
                "a white pearl!", environment(tp), tp);
               new(PEARLS"white_pearl.c")->move(tp);
              break;
    default:
       message("info","You only found a handful of sand.", tp);
        message("info", tp->query_cap_name() + " found " +
                "nothing but sand.", environment(tp), tp);
       break;
         } // end switch/case
}

