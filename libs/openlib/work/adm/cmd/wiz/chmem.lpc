// chmem.c:  change status of domain members
// created by Tim 16 Jun 1996

#include <cmdline.h>
#include <daemons.h>

int
main(string* argv, string* argv2)
{
  string domain, member;

  if( sizeof(argv2) != 3 || (argv2[0] != "adm" && argv2[0] != "mem") )
    return notify_fail("usage: chmem adm <member-name> <domain>\n"
		       "       chmem mem <member-name> <domain>\n");

  member = lower_case(argv2[1]);
  domain = capitalize(argv2[2]);

  if( !adminp(this_player()) &&
      !admin_domain(this_player()->query_name(), domain) )
    return notify_fail("You must be the domain administrator to change "
		       "the status of domain members.\n");

  if( SECURITY_D->change_domain_status(domain, member, argv2[0] == "adm") )
  {
    printf("%s is now %s of domain %s.\n",
	   capitalize(member),
	   (argv2[0] == "adm" ? "an ADMINISTRATOR" : "a MEMBER"),
	   domain);
    return 1;
  }
  return 0;
}
