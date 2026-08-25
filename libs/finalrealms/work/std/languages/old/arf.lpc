/* Arf!  March 1995, Chrisy
 */

string long() {
  return "Arf! Try it and see...\n";
}

string prev_mess, prev_arf;

#define IS_CAPS(X) (X>='A' && X<='Z')
#define IS_LOWER(X) (X>='a' && X<='z')
#define IS_VOWEL(X) ([	'A':2,'E':2,'I':2,'O':2,'U':2,	\
			'a':1,'e':1,'i':1,'o':1,'u':1,	])[X]

protected int is_word_caps(string word)
{
	int i, j;

	i = strsrch(word, " ");
	if(i==-1)
		i = strlen(word);

	for(j=0; j<i; j++)
		if(!IS_CAPS(word[j]) && IS_LOWER(word[j]))
			return 0;
	return 1;
}

string do_arf(string start, string mess)
{
	int i, j, k, l, cap;
	string fix;
	if(mess == prev_mess)
		return prev_arf;

	prev_mess = mess;
	prev_arf = "";

	l = 9999;
	j = strlen(mess);
	for(i=0; i<j; i++)
	{
		if(!i || (i && mess[i-1]==' '))
			cap = is_word_caps(mess[i..j-1]);

		k = IS_VOWEL(mess[i]);

		if(i && k && mess[i-1] == mess[i])	k = 3;
		if(mess[i..i+2] == "ing")		{k = 4; i+=2;}
		if(mess[i..i+2] == "igh")		{k = 5; i+=2;}
		if(mess[i..i+2] == "ugh")		{k = 6; i+=2;}
		if(mess[i..i+1] == "in")		{k = 7; i+=1;}
		if(mess[i..i+1] == "ou")		{k = 8; i+=1;}
		if(i&&k==1&& (['f':1,'s':1])[mess[i-1]])	k = 10;

		switch(k)
		{
		case 0:	fix = mess[i..i];		break;
		case 1:	fix = (k!=l?"ar":"er");		break;
		case 2:	fix = "Ar";			break;
		case 3:	fix = "r";			break;
		case 4:	fix = "in'";			break;
		case 5:	fix = "arr";			break;
		case 6:	fix = "ff";			break;
		case 7:	fix = "een";			break;
		case 8:	fix = "'s";			break;

		case 10:	fix = "'";		break;
		default:	fix = "";		break;
		}
		if(cap)		prev_arf += upper_case(fix);
		else		prev_arf += fix;
		l = k;
	}
	write("Recipients see: "+prev_arf+"\n");
	return prev_arf;
}

mixed garble_tell(string start, string mess) {
  return ({ start, do_arf(start, mess) });
}

mixed garble_shout(string start, string mess) {
  return ({ start, do_arf(start, mess) });
}

mixed garble_say(string start, string mess) {
  return ({ start, do_arf(start, mess) });
}
