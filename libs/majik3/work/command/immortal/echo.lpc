/****
*  *    Command                         echo
* *     Description                     Displays msg to everyone in majik
**      Coder                           Dazzt
*/

int main(string str)
{
    if (!str)
      {
        write ("echo - echoes message to "+environment(THIS)->query_short()+"\n");
        write ("usage: echo <message>\n");
        return 1;
      }

    message("wizecho", str + "\n", all_inventory(environment(THIS)), THIS);
    message("wizecho", "You echo to "+environment(THIS)->query_short()+": " +
      str + "\n", THIS);
    return 1;
}

