set_guild(str){
	string who,what;
	if(!str) return 0;
	if(sscanf(str,"%s %s",who,what));
	if(!find_player(who)) { write("Target is not in play.\n"); return 1; }
	find_player(who)->set_guild_name(what);
	tell_object(find_player(who),"Mishtar has changed your guild name to "+what+".\n");
	write("You have set "+capitalize(who)+"'s guild name to "+what+".\n");
	return 1; }

set_race(str) {
    string who,what;
    if(!str) return 0;
    if(sscanf(str,"%s %s",who,what));
    if(!find_player(who)) { write("Target is not in play.\n"); return 1; }
    find_player(who)->set_race(what);
    tell_object(find_player(who),"Mishtar has changed your race to "+what+".\n");
    write("You have set "+capitalize(who)+"'s race to "+what+".\n");
    return 1; }

set_align(string str){
	int s;
    string *words;
	string who,what;
    if(!str){
      notify_fail("Set who's title to what?\n");
      return 0;}
    if(sscanf(str,"%s %s",who,what));
    if(!find_player(who)) { write("Target is not in play.\n"); return 1; }
      words = explode(what, "$");
      s = sizeof(words);
      while(s --)
        if(find_player(who)->replace_ansi(words[s]))
          words[s] = (string)find_player(who)->replace_ansi(words[s]);
      str = (implode(words, "")) + esc + "[0m";
    tell_object(find_player(who),"Mishtar has changed your alignment to "+str+".\n");
	write("You have set "+capitalize(who)+"'s alignment to "+str+"\n");
    find_player(who)->set_al_title(str);
    return 1;}
