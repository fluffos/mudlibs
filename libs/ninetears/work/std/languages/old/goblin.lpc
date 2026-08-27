/*
 * The grunting goblinoid language.
 */
string garbler(string mess);

string long() {
  return "Consists of mostly grunting.\n";
}

mixed garble_say(string start, string mess) {
  int i;
  string ret;

  mess = garbler(mess);

  ret = "";
  for (i=0;i<strlen(mess);i++)
    if (mess[i] != ' ')
      ret += "*";
    else
      ret += " ";
  return ({ start, mess });
}

mixed garble_shout(string start, string mess) {
  int i;
  string ret;

  mess = garbler(mess);

  ret = "";
  for (i=0;i<strlen(mess);i++)
    if (mess[i] != ' ')
      ret += "*";
    else
      ret += " ";
  return ({ start, mess });
}
string garbler(string mess)
{
  mess = lower_case(mess);
  mess = implode(explode(mess, "k"), "kk");
  mess = implode(explode(mess, "p"), "hr");
  mess = implode(explode(mess, "g"), "ck");
  mess = implode(explode(mess, "p"), "");
  mess = implode(explode(mess, "t"), "fr");
  mess = implode(explode(mess, "y"), "o");
  mess = implode(explode(mess, "e"), "a");
  mess = implode(explode(mess, "a"), "e");
  mess = implode(explode(mess, "d"), "g");
  mess = implode(explode(mess, "ick"), "aal");
  mess = implode(explode(mess, "h"), "d");
  mess = implode(explode(mess, "ave"), "ertt");
  mess = implode(explode(mess, "I"), "Ick");
  mess = implode(explode(mess, "s"), "tha");
  mess = implode(explode(mess, "v"), "s");
  mess = implode(explode(mess, "m"), "");
  mess = implode(explode(mess, "v"), "f");
  return capitalize(mess);
}
