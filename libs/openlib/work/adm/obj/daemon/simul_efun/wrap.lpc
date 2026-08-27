string
wrap(string str)
{
  string* lines = explode(str, "\n");
  int nl = (str != "" && str[<1] == '\n');
  int width;

  width = (this_player() ? this_player()->query_screen_width() : 80);
  if(!width) width = 80;

  for(int i = 0; i < sizeof(lines); i++) {
    lines[i] = break_string(lines[i], width);
  }

  return implode(lines, "\n") + (nl ? "\n" : "");
}
