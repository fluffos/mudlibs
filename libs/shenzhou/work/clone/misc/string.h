// code for shenzhou
// create by Karlopex@sz

#include <ansi.h>

string setcolor(string msg)
{
        msg = replace_string(msg, "$BLK$", BLK);
        msg = replace_string(msg, "$RED$", RED);
        msg = replace_string(msg, "$GRN$", GRN);
        msg = replace_string(msg, "$YEL$", YEL);
        msg = replace_string(msg, "$BLU$", BLU);
        msg = replace_string(msg, "$MGA$", MAG);
        msg = replace_string(msg, "$CYN$", CYN);
        msg = replace_string(msg, "$WHT$", WHT);
        msg = replace_string(msg, "$HIR$", HIR);
        msg = replace_string(msg, "$HIG$", HIG);
        msg = replace_string(msg, "$HIY$", HIY);
        msg = replace_string(msg, "$HIB$", HIB);
        msg = replace_string(msg, "$HIM$", HIM);
        msg = replace_string(msg, "$HIC$", HIC);
        msg = replace_string(msg, "$HIW$", HIW);
        msg = replace_string(msg, "$NOR$", NOR);
        msg = replace_string(msg, "$HBRED$", HBRED);
        msg = replace_string(msg, "$HBGRN$", HBGRN);
        msg = replace_string(msg, "$HBYEL$", HBYEL);
        msg = replace_string(msg, "$HBBLU$", HBBLU);
        msg = replace_string(msg, "$HBMAG$", HBMAG);
        msg = replace_string(msg, "$HBCYN$", HBCYN);
        msg = replace_string(msg, "$HBWHT$", HBWHT);
        msg = replace_string(msg, "$BBLK$", BBLK);
        msg = replace_string(msg, "$BRED$", BRED);
        msg = replace_string(msg, "$BGRN$", BGRN);
        msg = replace_string(msg, "$BYEL$", BYEL);
        msg = replace_string(msg, "$BBLU$", BBLU);
        msg = replace_string(msg, "$BMAG$", BMAG);
        msg = replace_string(msg, "$BCYN$", BCYN);
        msg = replace_string(msg, "$SPARK$", BLINK);
/*	msg = replace_string(msg, "$BOLD$", BOLD);
        msg = replace_string(msg, "$CLR$", CLR);
        msg = replace_string(msg, "$HOME$", HOME);
        msg = replace_string(msg, "$REF$", REF);
        msg = replace_string(msg, "$BIGTOP$", BIGTOP);
        msg = replace_string(msg, "$BIGBOT$", BIGBOT);
        msg = replace_string(msg, "$SAVEC$", SAVEC);
        msg = replace_string(msg, "$REST$", REST);
        msg = replace_string(msg, "$SINGW$", SINGW);
        msg = replace_string(msg, "$DBL$", DBL);
        msg = replace_string(msg, "$FRTOP$", FRTOP);
        msg = replace_string(msg, "$FRBOT$", FRBOT);
        msg = replace_string(msg, "$UNFR$", UNFR);
        msg = replace_string(msg, "$U$", U);
        msg = replace_string(msg, "$REV$", REV);
        msg = replace_string(msg, "$HIREV$", HIREV);*///discard by Karlopex@sz
	return msg+NOR;
}

string delcolor(string msg)
{
        msg = replace_string(msg, BLK, "");
        msg = replace_string(msg, RED, "");
        msg = replace_string(msg, GRN, "");
        msg = replace_string(msg, YEL, "");
        msg = replace_string(msg, BLU, "");
        msg = replace_string(msg, MAG, "");
        msg = replace_string(msg, CYN, "");
        msg = replace_string(msg, WHT, "");
        msg = replace_string(msg, HIR, "");
        msg = replace_string(msg, HIG, "");
        msg = replace_string(msg, HIY, "");
        msg = replace_string(msg, HIB, "");
        msg = replace_string(msg, HIM, "");
        msg = replace_string(msg, HIC, "");
        msg = replace_string(msg, HIW, "");
        msg = replace_string(msg, NOR, "");
        msg = replace_string(msg, HBRED, "");
        msg = replace_string(msg, HBGRN, "");
        msg = replace_string(msg, HBYEL, "");
        msg = replace_string(msg, HBBLU, "");
        msg = replace_string(msg, HBMAG, "");
        msg = replace_string(msg, HBCYN, "");
        msg = replace_string(msg, HBWHT, "");
        msg = replace_string(msg, BBLK, "");
        msg = replace_string(msg, BRED, "");
        msg = replace_string(msg, BGRN, "");
        msg = replace_string(msg, BYEL, "");
        msg = replace_string(msg, BBLU, "");
        msg = replace_string(msg, BMAG, "");
        msg = replace_string(msg, BCYN, "");
        msg = replace_string(msg, BLINK, "");
/*	msg = replace_string(msg, BOLD, "");
        msg = replace_string(msg, CLR, "");
        msg = replace_string(msg, HOME, "");
        msg = replace_string(msg, REF, "");
        msg = replace_string(msg, BIGTOP, "");
        msg = replace_string(msg, BIGBOT, "");
        msg = replace_string(msg, SAVEC, "");
        msg = replace_string(msg, REST, "");
        msg = replace_string(msg, SINGW, "");
        msg = replace_string(msg, DBL, "");
        msg = replace_string(msg, FRTOP, "");
        msg = replace_string(msg, FRBOT, "");
        msg = replace_string(msg, UNFR, "");
        msg = replace_string(msg, U, "");
        msg = replace_string(msg, REV, "");
        msg = replace_string(msg, HIREV, "");*///discard by Karlopex@sz
	return msg;
}
int string_l(string msg, int mode)
{
	if ( mode == 1 )
		return strlen(delcolor(msg));
	else return strlen(msg);
}
string string_m(string name, int long)
{
	int cnt, s, x = string_l(name,1);
	string blk, newstring = "", blank = "                                                                                                        ";
	s = ( (long - x)/2 )-1;
	cnt = sizeof(explode( name, "\n" ));
	blk = blank[0..s];
	if (cnt <= 1){
		if (x == long) return name;
		else if (x < long) return blk + name + blk;
		else return "未知数据";
	}else{
		for(int i=0;i<cnt;i++){
			newstring += (i==0 || i==cnt)?"":"\n";
			newstring += replace_string(string_m(explode( name, "\n" )[i],long), "\n", "");
		}
		return newstring;
	}
}
