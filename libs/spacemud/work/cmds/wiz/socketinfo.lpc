/* Do not remove the headers from this file! see /USAGE for more info. */

//: COMMAND
//$$ see: netstat
// USAGE: ``socketinfo``
//
// Displays details of sockets
//
// .. TAGS: RST

inherit CMD;

private
void main(string str)
{
   string ret = "Fd    State      Mode       Local Address          Remote Address\n"
                "--  ---------  --------  ---------------------  ---------------------\n";
   foreach (mixed *item in socket_status())
   {
      ret += sprintf("%2d  %|9s  %|8s  %-21s  %-21s\n", item[0], item[1], item[2], item[3], item[4]);
   }
   write(ret);
}
