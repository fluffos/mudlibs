// this is use misc for warai_d
// by fire on July 11, 1999
// this function is used to get the maximum possible soldier number
// for a troop, for a char or a group of char
int get_max_soldier(mixed inp) {
	int ret;
	mapping sk;
	if(stringp(inp)) // this is a char
	{
		if(!CHAR_D->char_exist(inp))
			return 0;
		sk=CHAR_D->get_char(inp,"skills");
		if(!mapp(sk)) return 0;
		ret=bmax(sk["sk_wuli"],sk["sk_meili"]);
		ret=bmax(ret,sk["sk_zhimou"]);
		return ret*50;
	}
	if(arrayp(inp)) {
		ret=0;
		foreach(string s in inp) {
			ret+=get_max_soldier(s);
		}
		return ret;
	}
	if(intp(inp)) {
		mixed chs;
		chs=TROOP_D->get_troops(inp,"chars");
		if(arrayp(chs))
			return get_max_soldier(chs);
	}
	return 0;
}