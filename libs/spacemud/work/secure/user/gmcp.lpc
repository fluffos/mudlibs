/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** gmcp.c -- gmcp handling
**
** 2024, Tsath created.
*/

object query_body();
private
int gmcp;

void gmcp_enable()
{
   TBUG("GMCP enabled");
   gmcp = 1;
}

int uses_gmcp()
{
   TBUG("uses_gmcp?");
   return has_gmcp();
}

void gmcp_message(string s)
{
   if (!s)
      return;
   if (uses_gmcp())
   {
      send_gmcp(s);
   }
}
