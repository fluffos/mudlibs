/*
   time.c

   Some time functions
*/

#pragma save_binary

/*
 * Time in secs to  nn days xx hours yy minutes ss seconds
 */
string
convtime(int time)
{
    string res;
    int n;
    
    res = "";

    n = time / 86400;
    if (n > 0)
    {
	if (n != 1)
	    res = n + " dni";
	else
	    res = n + " dzien";
	time -= n * 86400;
    }

    n = time / 3600;
    if (n > 0)
    {
	if (strlen(res) != 0)
	    res += " ";

	if (n == 1)
	    res += n + " godzina";
	else if ((n > 20 || n < 10) && n % 10 < 5 && n % 10 > 1)
	    res += n + " godziny";
	else 
	    res += n + " godzin";
	time -= n * 3600;
    }

    n = time / 60;
    if (n > 0)
    {
	if (strlen(res) != 0)
	    res += " ";
	    
	if (n == 1)
	    res += n + " minuta";
	else if ((n > 20 || n < 10) && n % 10 < 5 && n % 10 > 1)
	    res += n + " minuty";
	else 
	    res += n + " minut";

	time -= n * 60;
    }

    if (time)
    {
	if (strlen(res) != 0)
	    res += " ";

	if (time == 1)
	    res += time + " sekunda";
	else if ((time > 20 || time < 10) && time % 10 < 5 && time % 10 > 1)
	    res += time + " sekundy";
	else 
	    res += time + " sekund";
    }

    return res;
}
