/*
 * format_columns
 * Arranges strings in columns
 * 
 * Example: sending 10 items and 2 columns will print like this:
 * 1 | 6
 * 2 | 7
 * 3 | 8
 * 4 | 9
 * 5 | 10
 *
 * Nulvect 2010-12-01
 */

varargs string format_columns(
string *items, int cols, int screenwidth, string separator, string align) {
  int colwidth;
  int rows;
  int mod;
  int len_sep;
  string ret;

  if (nullp(items) || !sizeof(items)) return 0;

  // argument defaults:
  if (nullp(cols)) cols = 2;
  if (nullp(screenwidth)) screenwidth = 80;
  if (nullp(separator)) separator = "  ";
  if (nullp(align)) align = "left";

  if (cols > sizeof(items)) cols = sizeof(items);

  len_sep = strlen(strip_color(separator));
  rows = sizeof(items) / cols;
  mod = sizeof(items) % cols;

  // this section handles combinations that don't work, such as 9 items and 4 columns,
  // 11 items and 5 columns, 16 items and 5 columns, etc
  if (mod && sizeof(items) > cols) {
    rows += 1;
    while (rows * cols - sizeof(items) >= rows) {
      cols -= 1;
    }
  }

  colwidth = (screenwidth - (len_sep * (cols-1)) - 1) / cols;

  ret = "";
  
  for (int i = 0; i < rows; i++) {
    string line = "";

    for (int col = 0; col < cols; col++) {
      int index = i + col*rows;

      if (index >= sizeof(items)) {
        line += repeat_string(" ", colwidth);
      }
      else {
        string tmp = items[index][0..(colwidth-1)];
        int len_tmp = strlen(strip_color(tmp));

        switch (align) {
          default:
          case "left":
            line += tmp + repeat_string(" ", colwidth-len_tmp);
          break;
          case "right":
            line += repeat_string(" ", colwidth-len_tmp) + tmp;
          break;
          case "center":
            tmp = repeat_string(" ", (colwidth-len_tmp)/2) + tmp;
            line += tmp + repeat_string(" ", colwidth-strlen(strip_color(tmp)));
          break;
        }
      }

      if (col < cols-1)
        line += separator;
    }
    ret += line + "\n";
  }

  return ret;
}
