/*
 * command                             effects
 * description                         displays the active effects
 * coder                               dazzt
 * */

int main()
{
	string *fxs;
	mixed *fx;
	string str;
	int i;
	
	if (!THIS->query_effects())
		THIS->reset_effects();
	
	fxs = keys(THIS->query_effects());
	fx = values(THIS->query_effects());
	
	str = "^bb^cW effect name          duration (sec)   origin                                ^c0\n";
	if (sizeof(fxs) > 0)
		for (i = 0; i < sizeof(fxs); i++)
			str += sprintf(" %-25s %4d/%-4d  %s \n",
						   fxs[i], fx[i][0], fx[i][1], fx[i][2]);
	else
		str += "None.\n";
	
	message("0", str, THIS);
	return 1;
}
	
	
	
