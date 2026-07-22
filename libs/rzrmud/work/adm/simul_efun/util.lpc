// trans_color
// raw = 0, only forecolor
// raw = 1, include backround color
// raw = 2, include blink & others
string trans_color(string arg, int raw)
{
        // forecolor
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);

        if (raw)
        {
                // Background color
                arg = replace_string(arg, "$BBLK$", BBLK);
                arg = replace_string(arg, "$BRED$", BRED);
                arg = replace_string(arg, "$BGRN$", BGRN);
                arg = replace_string(arg, "$BYEL$", BYEL);
                arg = replace_string(arg, "$BBLU$", BBLU);
                arg = replace_string(arg, "$BMAG$", BMAG);
                arg = replace_string(arg, "$BCYN$", BCYN);
                arg = replace_string(arg, "$HBRED$", HBRED);
                arg = replace_string(arg, "$HBGRN$", HBGRN);
                arg = replace_string(arg, "$HBYEL$", HBYEL);
                arg = replace_string(arg, "$HBBLU$", HBBLU);
                arg = replace_string(arg, "$HBMAG$", HBMAG);
                arg = replace_string(arg, "$HBCYN$", HBCYN);
        }

        if (raw == 2)
        {
                // special effect
                arg = replace_string(arg, "$U$", U);
                arg = replace_string(arg, "$BLINK$", BLINK);
                arg = replace_string(arg, "$REV$", REV);
                arg = replace_string(arg, "$HIREV$", HIREV);
                arg = replace_string(arg, "$BOLD$", BOLD);
        }

        arg += NOR;
        return arg;
}

