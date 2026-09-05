#include <ansi.h>
#include <security.h>

int
cmd_page(string arg)
{
    object ob;
    string colour;

    if(!arg) return (notify_fail("Page who?\n"), 0);

    if(!(ob=find_player(arg)) || (int)ob->query_invis() > (int)this_player()->query_level())
      return (notify_fail("You don't see " + capitalize(arg)
                        + " anywhere on Nirvana.\n"), 0);

    if((int)ob->query_level() >= APPRENTICE &&
      (int)this_player()->query_level() < APPRENTICE)
      return (notify_fail("You may not page a wizard.\n"), 0);
    if((int)ob->query_tellblock())
      return (notify_fail((int)ob->query_name() + " is blocking tells.\n"), 0);

    if((int)ob->query_pageblock() ||
     member_array((string)this_player()->query_real_name(),
                  (string *)ob->query_blocking_pagers()) > -1)
      return (notify_fail((int)ob->query_name() + " is blocking pages.\n"), 0);

    write("Paging Dr. " + (string)ob->query_name()+"...\n");
    colour = (string)ob->get_ansi_pref("page");
    

    tell_object(ob, (colour ? colour : "") + BEEP +
                   "\n\t" + (string)this_player()->query_name()
                  + " is paging you!\n\n->> " + (colour ? NORM : ""));
    return 1;
}
