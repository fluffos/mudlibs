varargs string strip_prepending_spaces(string str, int flag1, int flag2)
{
  int x, y;
  string *lines;
  y = sizeof(lines = explode(str, "\n"));
    if(y == 1 && !flag2) return str;
    for(x=(flag2?0:1); x < y; x ++)
    if(lines[x][0..1] == "  ") lines[x] = lines[x][2..strlen(lines[x])-1];
  return implode(lines, "\n") + (flag1 ? "\n" : "");
}
