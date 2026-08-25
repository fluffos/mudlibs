/* Do not remove the headers from this file! see /USAGE for more info. */

// simple test of cgi's with args
// cowl
#define MAX 2

string main(string arg) {
        string p;
        string ret;
	int index = 0;

        ret = sprintf ("<title>Demo for Chinese Viewer</Title>\n"
                        "<h2>The Result through this viewer</h2>\n");

/***************************************************************
        while (index <= MAX) {
               if ( (int) arg[index] < 0x80) {
                     ret += sprintf("%s",arg[index]);
                     index++;
                     continue;
                   }
		else{
*********************************************************************/

        ret += sprintf("<IMG SRC="gb/%02x/%02x\"",arg[index], arg[index+1]);
        ret += sprintf(" ALT=\"%c%c\"", arg[index], arg[index+1]);
        ret += sprintf(">");
//        index += 2;

/*                }
        }

*/      return ret;
}
