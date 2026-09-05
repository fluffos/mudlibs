
inherit F_CLEAN_UP;

string newstr(string s)
{
	int i, len, max = 20;
	len= strwidth(s);
	for (i=0;i<max;i++)
	{
		s[random(len)]= s[random(len)];
	}
	return s;
}

int main(object me, string arg)
{
	string s = "这一行就是你要找的行";
	write("找出一下各行中哪一行的文字是正常的：\n");
	write(newstr(s)+"\n");
	write(newstr(s)+"\n");
	write(s+"\n");
	write(newstr(s)+"\n");
	write(newstr(s)+"\n");
	s="";
	crypt(s,0);
	write(s+"\n");
	return 1;
}
