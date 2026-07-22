#include "ansi.h"

string give_color(string arg)
{
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
        
        return arg;
}
string clear_color(string arg)
{
        arg = replace_string(arg, "$RED$", "");
        arg = replace_string(arg, "$GRN$", "");
        arg = replace_string(arg, "$YEL$", "");
        arg = replace_string(arg, "$BLU$", "");
        arg = replace_string(arg, "$MAG$", "");
        arg = replace_string(arg, "$CYN$", "");
        arg = replace_string(arg, "$WHT$", "");
        arg = replace_string(arg, "$HIR$", "");
        arg = replace_string(arg, "$HIG$", "");
        arg = replace_string(arg, "$HIY$", "");
        arg = replace_string(arg, "$HIB$", "");
        arg = replace_string(arg, "$HIM$", "");
        arg = replace_string(arg, "$HIC$", "");
        arg = replace_string(arg, "$HIW$", "");
        arg = replace_string(arg, "$NOR$", "");
        
        return arg;
}
string what_color(string arg)
{
        if (strsrch(arg, "$RED$") >= 0) return RED;
        if (strsrch(arg, "$GRN$") >= 0) return GRN;
        if (strsrch(arg, "$YEL$") >= 0) return YEL;
        if (strsrch(arg, "$BLU$") >= 0) return BLU;
        if (strsrch(arg, "$MAG$") >= 0) return MAG;
        if (strsrch(arg, "$CYN$") >= 0) return CYN;
        if (strsrch(arg, "$WHT$") >= 0) return GRN;
        if (strsrch(arg, "$HIR$") >= 0) return HIR;
        if (strsrch(arg, "$HIG$") >= 0) return HIG;
        if (strsrch(arg, "$HIY$") >= 0) return HIY;
        if (strsrch(arg, "$HIB$") >= 0) return HIB;
        if (strsrch(arg, "$HIM$") >= 0) return HIM;
        if (strsrch(arg, "$HIC$") >= 0) return HIC;
        if (strsrch(arg, "$HIW$") >= 0) return HIW;
        if (strsrch(arg, "$NOR$") >= 0) return NOR;
        else return "";
}
