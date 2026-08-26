#define WHO find_player("pallando")
#define DEBUG(X) if(WHO) tell_object( WHO, wrap(X) )
#define DDBUG(X) DEBUG("X == "+identify(X))
/*
// File     :  /www/gateways/tell.c
// Desc     :  Allows mud users <--> web user communication
// 94-10-** :  Qualin@Crossed.Swords devised and wrote original code
//             ( Troels Therkelsen <mailto:troelst@diku.dk> )
// 94-11-12 :  Pallando adapted it for TMI-2 mudlibs
*/
#include <net/daemons.h>
#include <mudlib.h>

inherit DAEMON;

mapping msgs;

string rcve_mess(string me, string from);
string send_mess(string me, string to, string mess);
string repl_esc(string str);

string gateway( string input ) {
  string ret, *i;
  int s, c;
  
DDBUG(input);
  ret = "<h2>Response:</h2><p><hr><p>";
  input = repl_esc(input);
  i = explode(input, "&");
DDBUG(i);
  
  for (c = 0, s = sizeof(i); c < s; c++)
    if (i[c][<1] == '=')
      s = 0;
      
DDBUG(s);
  switch(s) {
    case 0:
      ret += "<h3>Error:</h3><p><i>You must fill out all required boxes!</i>";
      break;
    case 2:
      ret += rcve_mess(i[0], i[1]);
      break;
    case 3:
      ret += send_mess(i[0], i[1], i[2]);
      break;
  }
DDBUG(ret);
  return ret;
}

string send_mess(string me, string to, string mess) {
    object ob;
  me = me[5..<1];
  to = lower_case( to[5..<1] );
  mess = replace_string(mess, "+", " ");
  mess = replace_string(mess, "%0A", "\n");
  mess = mess[5..<1];

DDBUG(me); DDBUG(to); DDBUG(mess);
// I2:    return TS_D-> tell_user( me, "web", to, mess );
    ob = find_player(to);
    if (!ob)
        return (capitalize(to) + " not found online.\n");
    if (!interactive(ob))
        return (capitalize(to) + " is net dead.\n");
    if (ob->query("busy"))
        return (capitalize(to) + " is busy right now, please try again later...\n");

    message("tell", capitalize(me) + "@(web) tells you: " + mess + "\n", ob);

    return ("You tell " + ob->query("cap_name") + ": " + mess + "\n");
}

void add_message(string from, string to, string mess) {
  mess = sprintf("Message from %s MUD time %s: \"%s\".", 
		 capitalize(from), ctime(time()), mess);
  to = lower_case(to);

  if (!msgs)
    msgs = ([to: ({ ({from, mess}) })]);
  else if (undefinedp(msgs[to]))
    msgs += ([to: ({ ({from, mess}) })]);
  else
    msgs[to] += ({from, mess});
}

string rcve_mess(string me, string from) {
  int l, s;
  string mess;

  if (!msgs)
    msgs = ([]);
  me = lower_case(me[5..<1]);
  from = lower_case(from[5..<1]);

  if (undefinedp(msgs[me]))
    return "There are no pending messages for you.";

  for (l = 0, s = sizeof(msgs[me]); l < s; s++)
    if (msgs[me][l][0] == from) {
      mess = msgs[me][l][1];
      if (s == 1)
	map_delete(msgs, me);
      else if (!l)
	msgs[me] = msgs[me][1..s-1];
      else if (l = (s-1))
	msgs[me] = msgs[me][0..s-2];
      else
	msgs[me] = msgs[me][0..l-1]+msgs[me][l+1..s-1];
      return mess;
    }

  return "There are no pending messages from "+from+".";
}

string char(int c1, int c2) {
  c1 -= 48;
  c2 -= 48;
  if (c1 > 9)
    c1 -= 7;
  if (c2 > 9)
    c2 -= 7;

  return sprintf("%c", c1*16+c2);
}

/* This function replaces occurences of "%##" with the corresponding character.
   Might not work 100%. Might even be coded faster...*/
string repl_esc(string str) {
  int s, c;
  string ret;

  s = strlen(str);
  c = 0;
  ret = "";
  while (c < s) {
    if (str[c] == '%') {
      ret += char(str[c+1], str[c+2]);
      c += 3;
    }
    else {
      ret += str[c..c];
      c++;
    }
  }
  
  return ret;
}
