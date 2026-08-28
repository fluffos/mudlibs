/****
*  *    Command                         echo
* *     Description                     Displays msg to everyone in majik
**      Coder                           Dazzt
*/

int main(string str)
{
    if (!str)
      {
        write ("gecho - echoes message to all player objects\n");
        write ("usage: gecho <message>\n");
        return 1;
      }
    message("wizecho", str + "\n", users(), THIS);
    message("wizecho", "You echo to all: " + str + "\n", THIS);
    return 1;
}

