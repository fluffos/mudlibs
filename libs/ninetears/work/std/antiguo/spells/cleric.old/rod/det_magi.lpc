/*** Priest Detect Magic ***/
/*** modified slightly by Eerevann ***/
 
mixed spell(string str, int cast);


string help() 
  {
  return
    ("This spell detects a magical item, i.e. cast detect magic <item>.\n");
  }
 
int cast_spell(string str) 
  {
  mixed ret;
  int skill;

  ret = spell(str, 1);
  if (stringp(ret)) 
    {
    notify_fail(ret);
    return 0;
    }
  return 1;
  }
 
mixed spell(string str, int cast) 
  {     
  mixed ob;
  int enchant;

  if (!str || str == "")
    return "You wave you hands in the air trying to touch nothing.\n";
  ob = find_match(str, this_player());
  if (sizeof(ob))
    ob = ob[0];
  else
    return "Where is " + str + " ?\n";
  if (living(ob))
    return ("You know this is a living object.\n");
  enchant = (int)ob->query_enchant();
  if (cast && (int)this_player()->adjust_gp(-(enchant+50)) < 0)
    return "You are too weak to draw more power from your diety.\n";

  write("You call upon the gods to help you detect the magic of this item.\n");
   switch (enchant = (int)ob->query_enchant())
   {
    case 40..100:
    return ("This item is highly magical.\n");

    case 26..39:
    return ("This item is fairly magical.\n");

    case 11..25:
    return ("This item is partially magical.\n");

    case 1..10:
    return ("This item is slightly magical.\n");

    default:
    write ("This item is just an ordinary item.\n");

    return 1;
   }
}
