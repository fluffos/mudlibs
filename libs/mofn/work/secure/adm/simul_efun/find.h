object find_living(string word) {
  object thing;
 
  if(!word || word == "")
    return 0;
 
  thing = LIVING_H -> find_player(word);
 
  if(!thing || !this_player())
    return thing;
 
  return thing;
 
  return 0;
}

object find_player(string word) {
  object thing;

  if(!word || word == "")
    return 0;

  thing = LIVING_H -> find_player(word);

  if(!thing || !this_player())
    return thing;

  return thing;

  return 0;
}
