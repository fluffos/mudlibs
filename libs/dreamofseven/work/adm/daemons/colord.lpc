// #pragma save_binary

#include <ansi2.h>
                /*  Foreground Colors  */
mapping color_map = ([
     "$NOR$"    :       NOR,
     "$BLK$"    :       BLK,
     "$RED$"    :       RED,
     "$GRN$"    :       GRN,
     "$YEL$"    :       YEL,
     "$BLU$"    :       BLU,
     "$MAG$"    :       MAG,
     "$CYN$"    :       CYN,
     "$WHT$"    :       WHT,
     "$HIR$"    :       HIR,
     "$HIG$"    :       HIG,
     "$HIY$"    :       HIY,
     "$HIB$"    :       HIB,
     "$HIM$"    :       HIM,
     "$HIC$"    :       HIC,
     "$HIW$"    :       HIW,
     "$HBRED$"  :       HBRED,
     "$HBGRN$"  :       HBGRN,
     "$HBYEL$"  :       HBYEL,
     "$HBBLU$"  :       HBBLU,
     "$HBMAG$"  :       HBMAG,
     "$HBCYN$"  :       HBCYN,
     "$HBWHT$"  :       HBWHT,
     "$BBLK$"   :       BBLK,
     "$BRED$"   :       BRED,
     "$BGRN$"   :       BGRN,
     "$BYEL$"   :       BYEL,
     "$BBLU$"   :       BBLU,
     "$BMAG$"   :       BMAG,
     "$BCYN$"   :       BCYN,
     "$U$"      :       U,
     "$REV$"    :       REV,
     "$HIREV$"  :       HIREV,
]);

mapping spc_color_map = ([
     "$CLR$"    :       CLR,
     "$HOME$"   :       HOME,
     "$REF$"    :       REF,
     // "$BOLD$"        :       BOLD,
     // "$SAVEC$"       :       SAVEC,
     // "$REST$"        :       REST,
     // "$SINGW$"       :       SINGW,
     // "$DBL$" :       DBL,
     "$FRTOP$"  :       FRTOP,
     "$FRBOT$"  :       FRBOT,
     "$UNFR$"   :       UNFR,
     "$BLINK$"  :       BLINK,
]);

string trans_color(string arg)
{
  string        *color;
  int   i;

  if (!arg || arg=="") return arg;

  color = keys(color_map);
  for (i=0; i<sizeof(color); i++)
    arg = replace_string(arg, color[i], color_map[color[i]]);
  return arg;
}

string trans_spc_color(string arg)
{
  string        *color;
  int   i;

  if (!arg || arg=="") return arg;

  color = keys(spc_color_map);
  for (i=0; i<sizeof(color); i++)
    arg = replace_string(arg, color[i], spc_color_map[color[i]]);
  return arg+NOR;
}

string clear_withinansi(string arg)
{
  string *color;
  color = keys(color_map);
  if( !arg || arg == "" ) return arg;
  for(int i=0;i<sizeof(color);i++)
    arg = replace_string(arg, color[i], "");
  return arg;
}


