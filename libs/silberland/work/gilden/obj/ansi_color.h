//
// ansi_color.h
// (c) angrox@sl.mud.at
// NUR ZUR VERWENDUNG IM SILBERLAND sl.mud.at 4711
//
// release: 15.12.2000

// Prototyping
varargs string expand_color_strings(string msg, string pre, mixed pl, int flag);
varargs string color_tell(string msg, string pre, mixed pl, int flag);
varargs int check_color_syntax(string str, int firstocc);
varargs mixed grab_ansi_code(string str, int firstocc);
string color_break_string(string msg, int width, string indent);
