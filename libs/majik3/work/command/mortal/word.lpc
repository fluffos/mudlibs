#include <socket.h>
#include <driver/socket_err.h>

object sock;
object kuka;

string roina;
string *poks;
string answer;
string sana;

read_func (object socket, string data, string address)
{
  roina += data;
}

/* get rid of fucking html tags */

string
grofht (string str)
{
  int tag = 0;
  string ret = "";

  for (int i=0;i<strlen(str);i++)
    {
      if (!tag && (str[i]!='<' || str[i]!='>'))
        ret += str[i..i];

      if (str[i]=='<')
        tag = 1;

      if (str[i]=='>')
        tag = 0;
    }

  ret = replace_string(ret, "<", "");
  ret = replace_string(ret, ">", "");
  ret = replace_string(ret, "&auml;", "a");
  ret = replace_string(ret, "&ouml;", "o");

  return ret;
}

close_func ()
{
  int found;

  poks = explode(roina, "\n");
  // for (int i=30;i<sizeof(poks);i++) {
  // tell_object (kuka, i + " " + poks[i] + "\n");
  //  if (i>50)
  //    break;
  // }
  answer = "";
  for (int i=31;i<sizeof(poks);i++)
    {
      if (poks[i][<4..] == "ee>\r")
        {
          tell_object (kuka, "^c1"+sana+"^c0: "+grofht(poks[i])+"");
          found = 1;
        }
      if (poks[i][0..3] == "<i> ")
        tell_object (kuka, grofht(poks[i])+"\n");
      if (poks[i] == "</table></center>\r")
        break;
    }

  if (!found)
    tell_object (kuka, capitalize(sana)+" not found.\n");

  kuka = 0;

  return;

  for (int i=0;i<strlen(poks[30]);i++)
    {
      if (poks[30][i] == '<')
        break;

      answer += poks[30][i..i];
    }

  if (strlen(poks[30])==5) {
    tell_object (kuka, "The answer seems to be empty.\n");
  }
  else
  {
  for (int i=30;i<strlen(poks);i+=2) {
    if (strlen(grofht(poks[i])) == 1) {
      continue;
    }

    if (strsrch(grofht(poks[i]), "English-Finnish-English") != -1)
      break;

    tell_object (kuka, sana + ": " + poks[i] + " " +poks[i+1][1..] + "\n");

    if (strlen(grofht(poks[i+2])) == 1)
      continue;
    else
      break;
  }
  }
  kuka = 0;
}

int
main (string str)
{
  object ob;

  if (!str)
    {
      notify_fail ("Usage: word <word to search>\n");
      return 0;
    }

  sana = str;
  roina = "";

  if (kuka)
    {
      write ("Wait a moment...\n");
      return 1;
    }
  else
    kuka = THIS;

  ob = find_player(str);
  sock = new (SOCKET, SKT_STYLE_CONNECT, "194.252.52.2 80",
         (: read_func :), (: close_func :));
  sock->send ("GET /cgi-bin/mofind.exe/dr1?word="+str+" HTTP/1.0\r\n\r\n");

  if (!sock)
    write ("The dictionary is temperarily unavailable.\n");
  else
    write ("Searching the dictionary for ^c1"+sana+"^c0 ...\n");

  return 1;
}

query_author ()
{
  return "namhas";
}

query_help ()
{
  return "Word is a english-finnish-english dictionary. This command is "
+"very useful for finnish people and for those who want to learn finnish. "
+"The results are fetched from www.mofile.fi so it may take some time to "
+"receive respond."; 
}

query_synopsis ()
{
  return "word <word to search>";
}

query_example ()
{
  return "word huora";
}

query_position()
{
  return POS_RESTING;
}

