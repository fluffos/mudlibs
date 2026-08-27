// Vilat 31.10.2002
int longitud(string str) {
	string *cadenas=explode(str,"%^");
	string *filtrado=({});
	string nocolor;
	for (int i=0;i<sizeof(cadenas);i++) if (upper_case(cadenas[i])==cadenas[i]) continue;
	else filtrado+=({cadenas[i]});
	filtrado-=({0});
	nocolor=implode(filtrado,"");
	return strlen(nocolor);
	}
