/*  -*- LPC -*-  */
// lsdom.c:  list domains and domain members
// created by Tim 16 Jun 1996

#include <command.h>
#include <daemons.h>

int
main(string d)
{
  string* list;
  string line = "";

  if( !d )
  {
    list = map(sort_array(SECURITY_D->get_domains(), 1),
		       (: capitalize :));

    line = sprintf("Domains: (total %d)\n", sizeof(list));

    if( sizeof(list) ) {
      if( sizeof(list) > 1 ) line += sprintf("%@s, ", list[0..<2]);
      line += list[<1] + ".";
    }
    else
      line += "none.";
  }
  else
  {
    if( !domain_exists(d = capitalize(d)) )
      return notify_fail("No such domain.\n");

    list = map(sort_array(SECURITY_D->get_domain_members(d), 1),
	       (: (admin_domain($1, $(d)) ? "+" : "") + capitalize($1) :));
    
    line = sprintf("Members of domain %s: (total %d)  ", d, sizeof(list));
    line += "(+Domain Administrator)\n";

    if( sizeof(list) ) {
      foreach(string wiz in list[0..<2])
	line += wiz + ", ";
      line += list[<1] + ".";
    }
    else
      line += "none.";
  }
  line = break_string(line, 60);

  this_player()->more(explode(line, "\n"));
  return 1;
}
