string *saved_aliases;

cmd_compare_aliases(string str){
  string who1, who2;
  string *who1_aliases, *who2_aliases, *g, *h;
  string *matched;
  int    x, y, a, b, p, q;
  
  if(!str || sscanf(str, "%s %s", who1, who2) < 2) return 0;
  
  if(!valid_player(who1) || !valid_player(who2)){
    write("One of the names was not found.\n");
    return 1;
  }
  
  if(!restore_object("pfiles/"+who1[0..0]+"/"+who1))
  {
    write(who1+" was not found.\n");
    return 1;
  }
  who1_aliases = saved_aliases;
  
  if(!restore_object("pfiles/"+who2[0..0]+"/"+who2))
  {
    write(who2+" was not found.\n");
    return 1;
  }
  who2_aliases = saved_aliases;
  
  saved_aliases = 0;
  
  y = sizeof(who1_aliases);
  b = sizeof(who2_aliases);
  
  if(y > b) { q = y; g = who1_aliases; h = who2_aliases; }
  else { q = b; g = who2_aliases; h = who1_aliases; }
  
  write(capitalize(who1)+" has "+y/2+" aliases.\n");
  write(capitalize(who2)+" has "+b/2+" aliases.\n");
  
  matched = ({ });
  
  for(p = 0; p < q; p +=2)
  {
    if(member_array(g[p], h) > -1)
    {
      matched += ({ g[p] });
    }
  }
  
  write("Matches: "+sizeof(matched)+"\n");
  return 1;
}