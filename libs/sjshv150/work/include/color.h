// ansi颜色控制系列函数
// By Mudring@sjsh

#include "ansi.h"

string *stand_color = ({
  BLK, RED, BLU, YEL, GRN, MAG, WHT, CYN, HIR, HIG, HIW, HIC, HIM, HIY, HIB, HBRED,
  HBBLU, HBYEL, HBGRN, HBCYN, HBMAG, HBWHT, BBLK, BRED, BYEL, BBLU, BMAG, BCYN,
  BGRN, NOR, BLINK, "[2;37;0m", ""
});
string *stand_input_color = ({
  "BLK", "RED", "BLU", "YEL", "GRN", "MAG", "WHT", "CYN", "HIR", "HIG", "HIW", "HIC", "HIM", "HIY",
  "HIB", "HBRED", "HBBLU", "HBYEL", "HBGRN", "HBCYN", "HBMAG", "HBWHT", "BBLK", "BRED", "BYEL",
  "BBLU", "BMAG", "BCYN", "BGRN", "NOR", "BLINK"
});


// 使player输入的$WHT$这种形式的颜色控制符生效(即转化为系统可以识别的ansi代码)
string give_color(string arg) {
  int i;
  for (i = 0; i < sizeof(stand_input_color); i++)
    arg = replace_string(arg, "$" + stand_input_color[i] + "$", stand_color[i]);
  return arg;
}
// 清除player输入的$WHT$这种形式的颜色控制符     
string clear_color(string arg) {
  int i;
  for (i = 0; i < sizeof(stand_input_color); i++)
    arg = replace_string(arg, "$" + stand_input_color[i] + "$", "");
  return arg;
}
// 清楚设定的ansi代码(即使颜色失效)
string clear_color2(string arg) {
  int i;
  for (i = 0; i < sizeof(stand_color); i++)
    arg = replace_string(arg, stand_color[i], "");
  return arg;
}
// 判断是什么颜色
string what_color(string arg) {
  int i;
  for (i = 0; i < sizeof(stand_color); i++)
    if (strsrch(arg, stand_color[i]) >= 0)
      return stand_input_color[i];
  return "";
}
// 这个函数用来修正由于ansi代码所引起的格式输出失灵
string wrong_color(string color, int len) {
  int i, n;
  for (n = 0; n < sizeof(stand_color); n++) {
    color = replace_string(color, stand_color[n], "");
  }
  if (len < strlen(color)) return "";
  else {
    i = len - strlen(color);
    color = "";
    while (i) {
      if (i > 20) { color += "                    "; i -= 20; } else if (i > 10) {
        color += "          "; i -= 10;
      } else if (i > 5) { color += "     "; i -= 5; } else { color += " "; i -= 1; }
    }
    return color;
  }
}
