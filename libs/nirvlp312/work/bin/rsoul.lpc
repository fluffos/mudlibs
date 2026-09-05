//
// Original idea by Dworkin and/or Zellski.
// Enhanced by Macbeth@Tubmud.
//

inherit "/basic/daemon";
inherit "/basic/create";

#define VERB 0
#define SUBJECT 1
#define OBJECT 2
#define POSS 3

int remote;
object author;
object last_male, last_female;

void set_last(object ob)
{
  if (ob->query_female())
    last_female = ob;
  else if (ob->query_male())
    last_male = ob;
}

string second_person(string verb)
{
  switch (verb)
  {
    case "be":
      return "are";
  }
  return verb;
}

string third_person(string verb)
{
  switch (verb[<2..<1])
  {
    case "th":
    case "sh":
    case "ch":
      return verb + "es";
  }
  switch (verb[<1..<1])
  {
    case "s":
    case "z":
      return verb + "es";
    case "y":
      return verb[0..<2] + "ies";
  }
  switch (verb)
  {
    case "do":
    case "go":
      return verb + "es";
    case "don't":
      return "doesn't";
    case "will":
    case "won't":
      return verb;
    case "be":
      return "is";
  }
  return verb + "s";
}

object locate_player(string name)
{
  object ob;
  if (remote)
  {
    ob = find_player(name);
  }
  else
  {
    ob = find_player(name);
    if (!ob)
      ob = present(name, environment(author));
    if (!living(ob))
      ob = 0;
  }
  return ob;
}

mixed *parse_soul_command(string input)
{
  mixed *words;
  mixed word;
  mixed temp;
  object ob;
  int quoted;
  int i;
  quoted = 0;
  words = regexplode(input, "[@a-zA-Z'\"-][a-zA-Z'\"-]*");
  if (sizeof(words) == 1)
    return 0;
  words[1] = ({ VERB, words[1] });
  for (i=3; i<sizeof(words); i+=2)
  {
    word = words[i];
    switch (word[0..0])
    {
      case "'":
        words[i] = word[1..];
	continue;
      case "@":
        words[i] = ({ VERB, word[1..] });
	continue;
    }
    temp = explode(word, "\"");
    if (sizeof(temp) > 1)
    {
      if (sizeof(temp) % 2 == 0)
        quoted = !quoted;
      continue;
    }
    switch (word)
    {
      case "he":
        if (last_male)
	  word = ({ SUBJECT, last_male });
	break;
      case "she":
        if (last_female)
	  word = ({ SUBJECT, last_female });
	break;
      case "him":
        if (last_male)
	  word = ({ OBJECT, last_male });
	break;
      case "her":
        if (last_female)
	  word = ({ OBJECT, last_female });
	break;
      case "his":
        if (last_male)
	  word = ({ POSS, last_male });
	break;
      case "I":
        word = ({ SUBJECT, author });
	break;
      case "me":
      case "you":
      case "yourself":
        word = ({ OBJECT, author });
	break;
      case "my":
      case "your":
        word = ({ POSS, author });
	break;
      default:
        if (word[<2..<1] == "'s")
	{
	  if (ob = locate_player(word[0..<3]))
	  {
	    word = ({ POSS, ob });
	    set_last(ob);
	  }

	}
	else if (ob = locate_player(word))
	{
	  word = ({ OBJECT, ob });
	  set_last(ob);
	}

    }
    words[i] = word;
  }
  return words;
}

string name(object ob)
{
  if (remote)
    return ob->query_vis_name();
  else
    return ob->query_name();
}

string output_line(object target, mixed *words)
{
  string line;
  int i;
  mixed word;
  object ob;
  last_male = last_female = 0;
  set_last(author);
  if (remote)
    line = "from afar, ";
  else
    line = "";
  if (target == author)
    line += "you ";
  else
    line += name(author)+" ";
  for (i=0; i<sizeof(words); i++)
  {
    word = words[i];
    if (stringp(word))
      line += word;
    else
    {
      switch (word[0])
      {
        case VERB:
	  if (target == author)
	    line += second_person(word[1]);
	  else
	    line += third_person(word[1]);
	  break;
	case SUBJECT:
	  ob = word[1];
	  if (ob == target)
	    word = "you";
	  else if (ob == last_male)
	    word = "he";
	  else if (ob == last_female)
	    word = "she";
	  else
	    word = name(ob);
	  line += word;
	  set_last(ob);
	  break;
	case OBJECT:
	  ob = word[1];
	  if (ob == target)
	    word = (ob == author) ? "yourself" : "you";
	  else if (ob == last_male)
	    word = (ob == author) ? "himself" : "him";
	  else if (ob == last_female)
	    word = (ob == author) ? "herself" : "her";
	  else
	    word = name(ob);
	  line += word;
	  set_last(ob);
	  break;
	case POSS:
	  ob = word[1];
	  if (ob == target)
	    word = "your";
	  else if (ob == last_male)
	    word = "his";
	  else if (ob == last_female)
	    word = "her";
	  else
	    word = name(ob)+"'s";
	  line += word;
	  set_last(ob);
	  break;
	
      }
    }
  }
  switch (line[<1..<1])
  {
    case ".":
    case "!":
    case "?":
    case ";":
    case ",":
    case ":":
      break;
    default:
      line += ".";
  }
  return capitalize(line);
}

object find_target(string name)
{
  return find_player(name);
}

int rsoul(string arg)
{
  mixed *args;
  string *names;
  mixed targets;
  object ob;
  int i;
  if (!arg)
    return 0;
  remote = 1;
  args = regexplode(arg,"[ \t][ \t]*");
  i = 0;
  names = ({ });
  while (i < sizeof(args))
  {
    names += explode(args[i], ",") - ({ "" });
    i += 2;
    if (args[i-2][<1] != ',')
      break;
  }
  if (i >= sizeof(args))
    return 0;
  arg = implode(args[i..],"");
  author = this_player();
  last_male = last_female = 0;
  targets = ([ ]);
  for (i=0; i<sizeof(names); i++)
  {
    ob = find_target(names[i]);
    if (!ob)
    {
      notify_fail("Nobody known by the name \"" + names[i] + "\".\n");
      return 0;
    }
    set_last(ob);
    targets[ob] = 1;
  }
  if (!sizeof(targets))
  {
    notify_fail("No targets given.\n");
    return 0;
  }
  args = parse_soul_command(arg);
  targets[author] = 1;
  targets = m_indices(targets);
  for (i=0; i<sizeof(targets); i++)
    tell_object(targets[i], output_line(targets[i], args) + "\n");
  return 1;
}

int soul(string arg)
{
  int i;
  mixed *args;
  object *targets;
  if (!arg)
    return 0;
  remote = 0;
  author = this_player();
  last_male = last_female = 0;
  args = parse_soul_command(arg);
  if (!args)
    return 0;
  targets = filter(all_inventory(environment(this_player())),
                         #'query_once_interactive);
  for (i=0; i<sizeof(targets); i++)
    tell_object(targets[i], output_line(targets[i], args) + "\n");
  return 1;
}

void create()
{
  add_command("rsoul", "to");
  add_command("soul", "soul");
}
