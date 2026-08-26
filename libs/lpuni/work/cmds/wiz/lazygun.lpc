/* lazygun.c

 Tricky @ LPUni
 July 17th, 2006
 Wizard command

*/

#include <logs.h>

int main(string str)
{
    object tp = this_player();
    object here = environment(tp);
    int act = random(100);

    switch(act)
    {
        case 0..17:
          write("You run around flapping your arms about.\n");
          tell_room(here, capitalize(tp->query_name()) + " runs around looking like a complete loon.\n", ({ tp }));
          break;
        case 18..29:
        {
          mapping destinations = here->query_exits();
          string *arr = keys(destinations);
          int arr_sz = sizeof(arr);

          if(arr_sz)
          {
              string direction = arr[random(arr_sz)];

              if(here->valid_exit(direction))
              {
                  object there = here->query_exit(direction);

                  if(tp->moveAllowed(there))
                  {
                      tell_room(here, capitalize(tp->query_name()) + " leaves through the " + direction + " exit.\n", ({ tp }));
                      write("You move to " + there->query_short() + ".\n\n");
                      tell_room(there, capitalize(tp->query_name()) + " has entered the room.\n", ({ tp }));
                      tp->move(there);
                  }

              }

          }

          break;
        }
        case 30..36:
          if(random(100) < 75)
          {
              write("You fade out and then fade back into existence.\n");
              tell_room(here, capitalize(tp->query_name()) + " fades out and then fades back into existence.\n", ({ tp }));
          } else {
              previous_object()->exit_world();
              write("%^BOLD%^YELLOW%^Thank you for visiting " + mud_name() + "%^RESET%^\n");
              previous_object()->save_user();
              log_file(LOG_LOGIN, capitalize(previous_object()->query_name()) + " logged out from " +
                query_ip_number(previous_object()) + " on " + ctime(time()) + "\n");
              previous_object()->remove();
          }
          break;
        case 37..57:
        {
          write("You fumble about in your pockets and find a snowball.\n");
          tell_room(here, capitalize(tp->query_name()) + " fumbles about in some pockets and finds a snowball.\n", ({ tp }));

          call_out("throw_snowball", 2, tp);

          break;
        }
        case 58..65:
          foreach(object u in users())
              tell_object(u, "[%^MAGENTA%^Announce%^RESET%^] %^RED%^Lazygun%^RESET%^: The Surgeon General has deemed this mud good for your health.\n");
        default:
          write("Tacitus says 'Keep coding.'\n");
          break;
    }

    return 1;
}

void throw_snowball(object tp)
{
    object here = environment(tp);
    object *u = users();
    int u_sz = sizeof(u);

    tell_object(tp, "You take a step back, aim and launch the snowball.\n");
    tell_room(here, capitalize(tp->query_name()) + " takes a step back, aims and launches the snowball.\n", ({ tp }));

    call_out("snowball_hit", 5, u[random(u_sz)]);

    return;
}

void snowball_hit(object vict)
{
    object here = environment(vict);

    tell_object(vict, "A large snowball appears out of the sky and hits you on the back of the head.\n");
    tell_room(here, "A large snowball appears out of the sky and hits " + capitalize(vict->query_name()) + " on the back of the head.\n", ({ vict }));

    return;
}

string help()
{
     return(HIW + " SYNTAX: " + NOR + "lazygun\n"
     "Use this at your own risk. There is no telling what it will do.\n");
}
