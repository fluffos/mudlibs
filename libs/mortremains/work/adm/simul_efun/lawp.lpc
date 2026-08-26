// 29 Jun 2000  Cyanide created the file
// 30 Jun 2000  Cyanide fixed it so it wouldn't crap out.
// 01 Jul 2000  For the second time this week, Chronos fixes
//              this file for Cy.  :)

#define LAW "law"

int lawp( mixed ob_or_str ) {
    if ((stringp(ob_or_str) &&
	(int)master()->query_member_group(ob_or_str, LAW)) ||
      (objectp(ob_or_str) &&
	(int)master()->query_member_group(geteuid(ob_or_str), LAW)))
	return 1;
    return 0;
}
