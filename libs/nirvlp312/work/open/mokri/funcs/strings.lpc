#include "/players/mokri/ansi.h"

string strip_ansi(string str)
{
   string *colors, *tmp;
   int x;
   colors = ({ BLK,RED,GRN,YEL,BLU,MAG,CYN,WHT,HIBLK,HIK,HIR,HIG,HIY,HIB,HIM,HIC,HIW,BBLK,BRED,BGRN,BYEL,BBLU,BMAG,BCYN,BWHT,HBBLK,HBRED,HBGRN,HBYEL,HBBLU,HBMAG,HBCYN,HBWHT,NORM,BOLD,CLR,HOME,REF,BIGTOP,BIGBOT,SAVEC,REST,REVINDEX,SINGW,DBL,FRTOP,FRBOT,UNFR,BLINK,U,REV,HIREV });
   
   for(x = 0; x < sizeof(colors); x++)
   {
      tmp = explode(str,colors[x]);
      str = implode(tmp,"");
   }
   
   return str;
}
