/*
 * command                        /command/mortal/history.c
 * description                    shows last commands
 * coders                         namhas, dazzt
 * */


int main ()
{
	string *clh;
	int i, szi;

	clh = previous_object()->query_clh_arr();
	for (i = 0, szi = sizeof(clh); i < szi; i++)
		message("standard", (sizeof(clh) - i) + " " + clh[i][0..76] + "\n", THIS);
  return 1;
}

query_author ()
{
  return "dazzt";
}

query_help ()
{
  return 
  "This command shows you the last 9 commands you have sent to the " +
  "parser.";
}

query_see_also ()
{
  return "err(1), parser(1)";
}
