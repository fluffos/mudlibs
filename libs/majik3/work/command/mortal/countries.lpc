int main ()
{
    object *list;
    string host, country, buf;

    list = users();

    country = "Unknown";

    buf = "^cW^bb";
    buf += sprintf ("%-78s\n", "COUNTRIES ("+query_load_average()+")"[0..77]);
    buf += "^c0";

    for(int i=0;i<sizeof(list);i++)
    {
	if (query_ip_number(list[i]) == "127.0.0.1")
	    country = "Finland";
	host = query_ip_name(list[i]);
	if (member_array(host[0..0], ({ "1", "2" })) != -1)
	    country = "Unknown";
	if (host [<3..] == "edu") country = "Educational";
	if (host [<3..] == "com") country = "Commercial";
	if (host [<3..] == "net") country = "Network Organization";
	if (host [<3..] == "mil") country = "Military Network";
	if (host [<3..] == "org") country = "Organization";
	if (host [<2..] == "kw") country = "Kuwait";
	if (host [<2..] == "us") country = "United States";
	if (host [<2..] == "fr") country = "France";
	if (host [<2..] == "se") country = "Sweden"; 
	if (host [<2..] == "uk") country = "United Kingdom";
	if (host [<2..] == "no") country = "Norway";
	if (host [<2..] == "dk") country = "Denmark";
	if (host [<2..] == "jp") country = "Japan";
	if (host [<2..] == "nl") country = "Netherlands";
	if (host [<2..] == "de") country = "Deutschland";
	if (host [<2..] == "es") country = "Spain";
	if (host [<2..] == "ie") country = "Ireland";
	if (host [<2..] == "at") country = "Austria";
	if (host [<2..] == "fi") country = "Finland";
	if (host [<2..] == "il") country = "Israel";
	if (host [<2..] == "au") country = "Australia";
	if (host [<2..] == "pl") country = "Poland";
	if (host [<2..] == "hu") country = "Hungary";
	if (host [<2..] == "br") country = "Brazil";
	if (host [<2..] == "ca") country = "Canada";
	if (host [<2..] == "be") country = "Belgium";
	if (host [<2..] == "sg") country = "Singapore";
	if (host [<2..] == "su") country = "Sovjet Union";
	if (host [<2..] == "ru") country = "Sovjet Union";
	if (host [<2..] == "lv") country = "Latvia";
	if (host [<2..] == "it") country = "Italy";
	if (host [<2..] == "cl") country = "Chile";
	if (host [<2..] == "gr") country = "Greece";
	if (host [<2..] == "lt") country = "Lithuania";
	if (host [<2..] == "hr") country = "Hungary";
	if (host [<2..] == "za") country = "South Africa";
	if (host [<2..] == "ee") country = "Estonia";
	if (host [<2..] == "ua") country = "Ukraine";
	if (host [<2..] == "my") country = "Malaysia";
	if (host [<2..] == "jm") country = "Jamaica";
	if (host [<2..] == "tr") country = "Turkey";
	if (host [<2..] == "sk") country = "Slovakia";
	if (host [<2..] == "cz") country = "Czech Republic";

        if (list[i]->query_security())
          buf += sprintf ("^cp<^c0^c1%|20s^c0^cp>^c0 %-55s\n", country, list[i]->short()[0..54]);
       else
          buf += sprintf ("^cc[^c0^c1%|20s^c0^cc]^c0 %-55s\n", country, list[i]->short()[0..54]);
    }
    buf += "^c1"+ sizeof(users()) + "^c0 players shown (best: ^c156^c0 players). (^cp<>^c0=immortal, ^cc[]^c0=mortal)\n";
    message ("0", buf, THIS);

    return 1;
}

query_author()
{
  return "namhas";
}

query_help ()
{
  return "Will list all players currently logged in to the murpe and "
       + "will try to tell you where they are logged in from, based on "
       + "the top-level domain name.";
}

query_see_also ()
{
  return "who(1)";
}
