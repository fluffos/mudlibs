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
  tell_object (kuka, "Your magic worked, you received answer from the web!\n\n");
  poks = explode(roina, "\n");
  // for (int i=30;i<sizeof(poks);i++) {
  // tell_object (kuka, i + " " + poks[i] + "\n");
  //  if (i>50)
  //    break;
  // }
  answer = "";
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

    tell_object (kuka, sana + ": " + grofht(poks[i]) + " " + grofht(poks[i+1])[1..] + "\n");

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

  sana = str;
  roina = "";

  if (kuka)
    {
      write ("You whisper cryptic words of magic and fail.\n");
      return 1;
    }
  else
    kuka = THIS;

  ob = find_player(str);
  sock = new (SOCKET, SKT_STYLE_CONNECT, "194.252.52.2 80",
         (: read_func :), (: close_func :));
  sock->send ("GET /cgi-bin/mofind.exe/dr1?word="+str+" HTTP/1.0\r\n\r\n");
  write ("You whisper cryptic words of magic and wait.\n");
  return 1;
}
