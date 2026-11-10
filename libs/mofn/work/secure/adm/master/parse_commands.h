string *parse_command_id_list() {
  return ({ "one", "thing" });
}

string *parse_command_plural_id_list() {
  return ({ "ones", "things", "them" });
}

string *parse_command_adjectiv_id_list() {
  return ({ "the", "a", "an" });
}

string *parse_command_prepos_list() {
  return ({ "in", "on", "at", "along", "upon", "by", "under", "behind",
            "with",
            "beside", "into", "onto", "inside", "within", "from" });
}

string parse_command_all_word() {
  return "all";
}

string *query_word_list(string word) {
  switch (word) {
    case "preposition" :
      return parse_command_prepos_list();
    default :
      return 0;
  }
}
