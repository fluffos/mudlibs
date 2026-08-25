// honour.c
// by fire on Feb 17, 2000
// the player use honour point to reward self

void start(string arg)
{
	string what;
	int n;
	string res;
	sscanf(arg,"%s %d",what,n);
	res=CHAR_D->tran_honor_point(this_body()->query_primary_id(),what,n);
	this_body()->other_action("$N好像遇到什么喜事，呆呆地立着，嘴角挂着憨憨的笑容。\n");
	write(res);
}
