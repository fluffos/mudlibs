string changecolor(string arg)
{
	string param;
	param = replace_string(arg, "$BLK$", BLK);
	param = replace_string(param, "$RED$", RED);
	param = replace_string(param, "$GRN$", GRN);
	param = replace_string(param, "$YEL$", YEL);
	param = replace_string(param, "$BLU$", BLU);
	param = replace_string(param, "$MAG$", MAG);
	param = replace_string(param, "$CYN$", CYN);
	param = replace_string(param, "$WHT$", WHT);
	param = replace_string(param, "$HIR$", HIR);
	param = replace_string(param, "$HIG$", HIG);
	param = replace_string(param, "$HIY$", HIY);
	param = replace_string(param, "$HIB$", HIB);
	param = replace_string(param, "$HIM$", HIM);
	param = replace_string(param, "$HIC$", HIC);
	param = replace_string(param, "$HIW$", HIW);
	param = replace_string(param, "$NOR$", NOR);
	param = replace_string(param, "$BNK$", BNK);
	param = replace_string(param, "$REV$", REV);
	return param;
}