// addmem.c:  add members to domains
// created by Tim 16 Jun 1996

#include <cmdline.h>
#include <daemons.h>

int
main(string* argv, string* argv2)
{
  string domain, member;
  int optr = flag("r");

  if( sizeof(argv2) != 2 )
    return notify_fail("usage: addmem [-r] <member> <domain>\n");

  member = lower_case(argv2[0]);
  domain = capitalize(argv2[1]);

  if( !adminp(this_player()) &&
      !admin_domain(this_player()->query_name(), domain) )
    return notify_fail("You must be the domain administrator to add "
		       "members.\n");

  if( !optr )
  {
    if( SECURITY_D->add_domain_member(domain, member) )
    {
      printf("%s is now a MEMBER of domain %s.\n",
	     capitalize(member), domain);
      return 1;
    }
  }
  else
  {
    if( SECURITY_D->remove_domain_member(domain, member) )
    {
      printf("%s is no longer a member of domain %s.\n",
	     capitalize(member), domain);
      return 1;
    }
  }
  return 0;
}
