/*
 * Finnish-english-finnish dictionary
 * 
 * coded by namhas, made to item by dazzt
 * 
 * */

#include <socket.h>

inherit ITEM;

object socket;
object who;
string word;
string data;

create_item()
{
	set_name(({ "dictionary", "book" , "tome", "huge tome", "pedestal" }));
	set_short("A pedestal with a huge tome labeled 'fin-eng-fin dictionary'");
	set_long("This is a pedestal made from granite. On top of it there is a huge " +
			 "tome chained into it. The huge tome is a book written by old monks " +
			 "in the monastery of Va l'Amo. It is an ancient project and very few copies " +
			 "of this book exist. You can only imagine how valuable this kind of book can " +
			 "be as it very thick and made from paper. It contains words both in " +
			 "finnish and english what you can 'search' from it.\n");
			 
	set_dimensions(40, 30, 10);
	set_material("stone");
	set_weight(92682);
	set_no_get();
	
	set_hp(30);
	set_max_hp(40);
}

init()
{
	add_action("do_search", "search");
}

read_func (object socket, string s, string address)
{
	data += s;
}

/* clean up the document from html crap */

string clean (string str)
{
	int tag = 0;
	string ret = "";
	int i, szi;
	

	for (i = 0, szi = strlen(str); i < szi; i++)
    {
		if (!tag && (str[i] != '<' || str[i] != '>'))
			ret += str[i..i];

		if (str[i]=='<')
			tag = 1;

		if (str[i]=='>')
			tag = 0;
    }

	ret = replace_string(ret, "<", "");
	ret = replace_string(ret, ">", "");
	ret = replace_string(ret, "&auml;", "a");
	ret = replace_string(ret, "&ouml;", "o");

	return ret;
}

close_func ()
{
	string *data_arr;
	string answer;
	int i, szi;
	
	message("standard", "You find the correct page and look at the answer.\n\n", who);

	data_arr = explode(data, "\n");
	answer = "";

	for (i = 0, szi = strlen(data_arr[30]); i < szi; i++)
    {
		if (data_arr[30][i] == '<')
			break;
		
		answer += data_arr[30][i..i];
    }

	if (strlen(data_arr[30]) == 5) 
	{
		message("standard", "You found the correct page but you are unable to find the word.\n", who);
	}
	else
	{
		message("standard", word + ":\n", who);
		
		for (i = 30, szi = strlen(data_arr);i < szi; i += 2) 
		{
			if (strlen(clean(data_arr[i])) == 1) 
				continue;

			if (strsrch(clean(data_arr[i]), "English-Finnish-English") != -1)
				break;

			message("standard",  "    " + clean(data_arr[i]) + " " + clean(data_arr[i+1])[1..] + "\n",
					who);
			
			if (strlen(clean(data_arr[i+2])) == 1)
				continue;
			else
				break;
		}
	}
	who = 0;
}

int do_search (string str)
{
	string targ;

	if (!str || sscanf(str, "%s from %s", word, targ) != 2)
          {
            write ("Usage: search <word> from <what>\n");
            return 1;
          }

	if (member_array(targ, ({ "book", "tome", "dictionary" })) == -1)
		return 0;
	
	data = "";
	if (who)
	{
		message("standard", "But " + who->query_cap_name() + " is currently browsing it!\n", THIS);
		return 1;
	}
	
	who = THIS;

	socket = new (SOCKET, SKT_STYLE_CONNECT, "194.252.52.2 80",
				(: read_func :), (: close_func :));
	socket->send ("GET /cgi-bin/mofind.exe/dr1?word=" + word + " HTTP/1.0\r\n\r\n");

	message("standard", "You start browsing the book.\n", THIS);
	message("standard", THIS->query_cap_name() + " starts browsing the dictionary.\n", 
			environment(THIS), THIS);
	return 1;
}
