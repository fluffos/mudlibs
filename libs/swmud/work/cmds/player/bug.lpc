// Last edited by deforce on 12-10-2007
// Rust wrote it
// Megaboz@ZorkMUD attached header 05-05-1994
// Converted to use new /std/reporter superclass (Deathblade 09-04-1994)
// Beek made one line reports work right 11-14-1994
// Rust made them post news

#include <mudlib.h>

inherit CMD;

void create()
{
  ::create();
  no_redirection();
}

private void main(string str)
{
   REPORTER_D->report_something("bug", str);
}