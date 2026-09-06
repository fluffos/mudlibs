/*
** /obj/lib/communication.c
** Used to do several things to emote, say something, etc.
**
** 19jun95 [t] Creation
**
** [t] Thragor
*/

#define TP this_player()
#define ME this_object()

inherit "/lib/string";

public varargs string Name(int cap)
// Write this function into your file inheriting /obj/lib/communication
// to evaluate the correct name of the person emoting, speaking, etc.
// If 'cap' is !=0 the name should be returned capitalized.
{
  string name;
  name = ({string})ME->QueryName()||"someone";
  return cap?capitalize(name):name;
}

public varargs string PlName(string cap)
// Used for process_string to determine the name of the player.
// To give 'cap' in the string use: @@PlName|1@@
{
  string name;
  name = TP?({string})TP->QueryName():"someone";
  return cap?capitalize(name):name;
}

public varargs string PlPronoun(string cap)
// Used for process_string to determine the pronoun of the player.
// To give 'cap' in the string use: @@PlPronoun|1@@
{
  string pron;
  pron = TP?({string})TP->QueryPronoun():"they";
  return cap?capitalize(pron):pron;
}

public string PlPossessive(string cap)
// Used for process_string to determine the possessive pronoun of the player.
// To give 'cap' in the string use: @@PlPossessive|1@@
{
  string poss;
  poss = TP?({string})TP->QueryPossessive():"their";
  return cap?capitalize(poss):poss;
}

public string PlObjective(string cap)
// Used for process_string to determine the objective pronoun of the player.
// To give 'cap' in the string use: @@PlObjective|1@@
{
  string obj;
  obj = TP?({string})TP->QueryObjective():"them";
  return cap?capitalize(obj):obj;
}

public string PlGenitive(string cap)
// Used for process_string to determine the objective pronoun of the player.
// To give 'cap' in the string use: @@PlGenitive|1@@
{
  string gen;
  gen = add_gen(TP?({string})TP->QueryName():"someone");
  return cap?capitalize(gen):gen;
}

public string parse_string(string str)
{
  int pos;
  string msg;
  msg = process_string(str);
  pos = sizeof(msg)-1;
  while(msg[pos--]==' ');
  msg = msg[0..pos+1];
  if (member(({'.','!','?','"',39,'>','<','\n'}),msg[<1])==-1)
    msg+=".";
  if (msg[<1]!='\n')
    msg+="\n";
  return msg;
}

public void Emote(mixed message)
// The head of the message will be the result of Name():
// <Name> <message>.\n.
// If no punctuation-mark and no newline is given ".\n"
// will be appended, if just the newline is missing this
// will be appended.
// sizeof(<message>):
// 1: it's handled as if it is just a string;
// 2: the first message is printed to the player and the
//    second one to her/his environment;
// 3: the first message is printed to the player, the second
//    one to all persons in the environment who can see and
//    the third one to all who can't;
// 4: the first message is printed to the player if (s)he can
//    see, the second one if (s)he can't, the third one to
//    the environment who can see and the last one to the
//    environment who can't.
// If the message is a closure, this will be called and the
// result interpreted in the way mentioned above.
// The closure function will be called with this_player() and
// Name() as arguments.
// If the function called already handled the output, it should
// return 0 as result, else a string or an array of strings.
{
  mixed ms;
  if (!TP) return;
  if (closurep(message))
    ms = funcall(message,TP,Name());
  else
    ms = message;
  if (stringp(ms))
    write(Name()+" "+ms);
  else
    if (pointerp(ms))
      {
        switch(sizeof(ms))
	  {
	   case 0:
	    break;
	   case 1:
	    write(ms[0]?wrap(Name(1)+" "+parse_string(ms[0]),0,3):"");
	    break;
	   case 2:
	    write(wrap(Name(1)+" "+parse_string(ms[0]),0,3));
	    say(ms[1]?wrap(Name(1)+" "+parse_string(ms[1]),0,3):"");
	    break;
	   case 3:
	    write(ms[0]?wrap(Name(1)+" "+parse_string(ms[0]),0,3):"");
	    show(({ms[1]?wrap(Name(1)+" "+parse_string(ms[1]),0,3):"",
                   ms[2]?wrap("Someone "+parse_string(ms[2]),0,3):""}));
	    break;
	   default:
	    see(({ms[0]?wrap(Name(1)+" "+parse_string(ms[0]),0,3):"",
                  ms[1]?wrap("Someone "+parse_string(ms[1]),0,3):""}));
	    show(({ms[2]?wrap(Name(1)+" "+parse_string(ms[2]),0,3):"",
                   ms[3]?wrap("Someone "+parse_string(ms[3]),0,3):""}));
	  }
      }
}

public void Say(mixed message)
// The message will be printed like the rules of Emote(), but you may
// just give one string as argument.
// The result of Name() and " says: " will be printed in front of the
// message.
{
  string ms;
  if (!TP||!environment(TP)) return;
  if (closurep(message))
    ms = funcall(message,TP,Name());
  else
    ms = message;
  if (stringp(ms))
    {
      see(({wrap(Name(1)+" says: "+parse_string(ms),0,3),
            wrap("Someone says: "+parse_string(ms),0,3)}));
      show(({wrap(Name(1)+" says: "+parse_string(ms),0,3),
             wrap("Someone says: "+parse_string(ms),0,3)}));
    }
}
