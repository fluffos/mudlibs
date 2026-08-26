/* color.c write by -Acme-
*/

#pragma optimize
// #pragma save_binary

#include <ansi.h>

string color(string msg)
{
	if( !msg ) return 0;
	
	msg = replace_string(msg, "$BLK$", BLK);
	msg = replace_string(msg, "$RED$", RED);
	msg = replace_string(msg, "$GRN$", GRN);
	msg = replace_string(msg, "$YEL$", YEL);
	msg = replace_string(msg, "$BLU$", BLU);
	msg = replace_string(msg, "$MAG$", MAG);
	msg = replace_string(msg, "$CYN$", CYN);
	msg = replace_string(msg, "$WHT$", WHT);

	msg = replace_string(msg, "$HIK$", HIK);
	msg = replace_string(msg, "$HIR$", HIR);
	msg = replace_string(msg, "$HIG$", HIG);
	msg = replace_string(msg, "$HIY$", HIY);
	msg = replace_string(msg, "$HIB$", HIB);
	msg = replace_string(msg, "$HIM$", HIM);
	msg = replace_string(msg, "$HIC$", HIC);
	msg = replace_string(msg, "$HIW$", HIW);

	msg = replace_string(msg, "$BBLK$", BBLK);
	msg = replace_string(msg, "$BRED$", BRED);
	msg = replace_string(msg, "$BGRN$", BGRN);
	msg = replace_string(msg, "$BYEL$", BYEL);
	msg = replace_string(msg, "$BBLU$", BBLU);
	msg = replace_string(msg, "$BMAG$", BMAG);
	msg = replace_string(msg, "$BCYN$", BCYN);
	msg = replace_string(msg, "$BWHT$", BWHT);

	msg = replace_string(msg, "$NOR$", NOR);
	msg = replace_string(msg, "$LINE$", LINE);
	msg = replace_string(msg, "$BLINK$", BLINK);
	msg = replace_string(msg, "$REV$", REV);

	return msg+NOR;
}

string uncolor(string msg)
{ 
	if( !msg ) return 0;
	msg = replace_string(msg, BLK, "");
	msg = replace_string(msg, RED, "");
	msg = replace_string(msg, GRN, "");
	msg = replace_string(msg, YEL, "");
	msg = replace_string(msg, BLU, "");
	msg = replace_string(msg, MAG, "");
	msg = replace_string(msg, CYN, "");
	msg = replace_string(msg, WHT, "");
	msg = replace_string(msg, HIK, "");
	msg = replace_string(msg, HIR, "");
	msg = replace_string(msg, HIG, "");
	msg = replace_string(msg, HIY, "");
	msg = replace_string(msg, HIB, "");
	msg = replace_string(msg, HIM, "");
	msg = replace_string(msg, HIC, "");
	msg = replace_string(msg, HIW, "");

	msg = replace_string(msg, BBLK, "");
	msg = replace_string(msg, BRED, "");
	msg = replace_string(msg, BGRN, "");
	msg = replace_string(msg, BYEL, "");
	msg = replace_string(msg, BBLU, "");
	msg = replace_string(msg, BMAG, "");
	msg = replace_string(msg, BCYN, "");
	msg = replace_string(msg, BWHT, "");

	msg = replace_string(msg, NOR, "");
	msg = replace_string(msg, LINE, "");
	msg = replace_string(msg, BLINK, "");
	msg = replace_string(msg, REV, "");

	return msg;
}

string color_to_html(string msg)
{
	if( !msg ) return 0;
	msg = replace_string(msg, BLK, "<font color=\"#000000\">");
	msg = replace_string(msg, RED, "<font color=\"#990000\">");
	msg = replace_string(msg, GRN, "<font color=\"#009900\">");
	msg = replace_string(msg, YEL, "<font color=\"#999900\">");
	msg = replace_string(msg, BLU, "<font color=\"#000099\">");
	msg = replace_string(msg, MAG, "<font color=\"#990099\">");
	msg = replace_string(msg, CYN, "<font color=\"#669999\">");
	msg = replace_string(msg, WHT, "<font color=\"#EEEEEE\">");

	msg = replace_string(msg, HIK, "<font color=\"#BBBBBB\">");
	msg = replace_string(msg, HIR, "<font color=\"#FF0000\">");
	msg = replace_string(msg, HIG, "<font color=\"#00FF00\">");
	msg = replace_string(msg, HIY, "<font color=\"#FFFF00\">");
	msg = replace_string(msg, HIB, "<font color=\"#0000FF\">");
	msg = replace_string(msg, HIM, "<font color=\"#FF00FF\">");
	msg = replace_string(msg, HIC, "<font color=\"#00FFFF\">");
	msg = replace_string(msg, HIW, "<font color=\"#FFFFFF\">");
	
    msg = replace_string(msg, BBLK, "<span style=\"background-color: #FFFF00\">");
	msg = replace_string(msg, BRED, "<span style=\"background-color: #990000\">");
	msg = replace_string(msg, BGRN, "<span style=\"background-color: #009900\">");
	msg = replace_string(msg, BYEL, "<span style=\"background-color: #999900\">");
	msg = replace_string(msg, BBLU, "<span style=\"background-color: #000099\">");
	msg = replace_string(msg, BMAG, "<span style=\"background-color: #990099\">");
	msg = replace_string(msg, BCYN, "<span style=\"background-color: #669999\">");
	msg = replace_string(msg, BWHT, "<span style=\"background-color: #EEEEEE\">");

    msg = replace_string(msg, NOR, "");
	msg = replace_string(msg, LINE, "");
	msg = replace_string(msg, BLINK, "");
	msg = replace_string(msg, REV, "");

	return msg;
}