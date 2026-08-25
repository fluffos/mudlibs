
//      /adm/simul_efun/wrap.c
//      Part of the TMI distribution mudlib and now Nightmare's
//      Inserts "\n"'s into text so lines arn't wider than screens
//      Author unknown, but thanks to the MudOS driver team for sprintf
//      Moved to Nightmare by Pallando 93-05-28

#define SZ 75

varargs string wrap(string str, int width) {
	if (!width) return sprintf("%-="+SZ+"s", str + "\n");
	else return sprintf("%-="+width+"s", str + "\n");
}

