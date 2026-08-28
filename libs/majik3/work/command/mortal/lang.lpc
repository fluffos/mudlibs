
int main(string args)
{
    string *lans = (({"alande","kvanya","uruzden","draz","ohrim","sartog",
    "grahnik","hgrzag","palen","choui","yavahe","ugal","tzhimsal",
    "yiunda"}));
    if(!args)
    {
	write("You are currently speaking "+THIS->query_current_language()+
	  ".\n");
	return 1;
    }
    if(member_array(args,lans) < 0)
    {
   write(wrap("Valid languages are, alande, kvanya, uruzden, draz, ohrim,"+
       " sartog, grahnik, hgrzag, palen, choui, yavahe,"+
       " ugal, tzhimsal and yiunda\n"+
       "Type 'help languages' to get info about languages\n"));
	return 1;
    }
    else
    {
	if(THIS->query_skill_chance(args) < 50)
	{
	    write("You don't know that language well enough to speak it.\n");
	    return 1;
	}
	else
	{
	    if(THIS->set_current_language(args))
	    {
		write("Now speaking in "+capitalize(args)+".\n");
		return 1;
	    }
            else 
	    {
		write("Get new object you don't support that language.\n");
		return 1;
	    }  
	} 
    }
 
return 0;
}

query_help ()
{
  return "Using this command you can set the default language for communications. By typing 'lang list' you get list of available languages.";
}

query_synopsis ()
{
 return "lang [language | list]";
}

query_example ()
{
 return "lang sartog";
}

query_author ()
{
  return "ondoval";
}

query_position ()
{
  return POS_RESTING;
}

