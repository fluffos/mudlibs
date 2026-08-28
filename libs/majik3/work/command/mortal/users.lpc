int total = 0;
string poks;

Recurse(string);

int main (string str) {
    poks = "";
    total = 0;
    message("standard", "All registered users are:\n\n", THIS);
    Recurse ("/data/player/");
    write_file ("/open/poks", sprintf ("%#-78s\n", poks) + "\nTotal users: "+total+".\n");
    THIS->more_file ("/open/poks");
    rm ("/open/poks");
    return 1 ;
}

Recurse(string dir) {
    mixed *junk;
    int i;

    junk = get_dir(dir, -1);
    for (i=0; i<sizeof(junk); i++) {
	if (junk[i][1] == -2 && strlen(junk[i][0]) < 2)
	    Recurse (dir + junk[i][0] + "/");
	else if (junk[i][1] > 0) {
            poks += junk[i][0][0..<3] + "\n";
	    total++;
        }
    }
    return 1;
}

query_author()
{
  return"namhas";
}

query_help()
{
  return "Gives you a full list of users who are logged on.";
}

query_see_also()
{
  return "who(1)";
}
query_position()
{
  return POS_RESTING;
}

