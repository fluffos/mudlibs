string posess(object who) {
  if((string)who->query_gender() == "male")   return "his";
  if((string)who->query_gender() == "female") return "her";
  return "its";
}
string posessive() {
  return posess(this_player());
}
string pro(object who) {
  if((string)who->query_gender() == "male")   return "he";
  if((string)who->query_gender() == "female") return "she";
  return "it";
}
string pronoun() {
  return pro(this_player());
}
string noun(object who) {
  if(!who) who = this_player();
  if((string)who->query_gender() == "male")   return "him";
  if((string)who->query_gender() == "female") return "her";
  return "it";
}  
