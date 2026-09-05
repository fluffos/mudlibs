/*
 * prounoun sefun for compatibility
 * Rumplemintz
 */

string subjective(object ob) {
  string gender;

  if (!ob) {
    ob = this_player();
    if (!ob)
      return "it";
  }
  gender = (string)ob->query_gender();
  if (gender == "male")
    return "he";
  else if (gender == "female")
    return "she";
  else
    return "it";
}

string objective(object ob) {
  string gender;

  if (!ob) {
    ob = this_player();
    if (!ob)
      return "it";
  }
  gender = (string)ob->query_gender();
  if (gender == "male")
    return "him";
  else if (gender == "female")
    return "her";
  else
    return "it";
}

string possessive(object ob) {
  string gender;

  if (!ob) {
    ob = this_player();
    if (!ob)
      return "its";
  }
  gender = (string)ob->query_gender();
  if (gender == "male")
    return "his";
  else if (gender == "female")
    return "her";
  else
    return "its";
}

