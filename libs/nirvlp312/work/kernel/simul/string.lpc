/*
 * kernel/simul/string.c
 *
 * simul_efuns concerning string handling
 * Rumplemintz
 */

#include <prop/player.h>
#include <describe.h>
#include <libs.h>
#include <prop/item.h>
#include <ctype.h>
#include <regexps.h>
#include <termcol.h>

#include "/kernel/simul/lpc.h"
#include "/kernel/simul/list.h"

/*
 * Function_name: break_string
 * Description:   Breaks a continuous string without newlines into a string
 *                with newlines instead at regular intervals replacing spaces
 *                Each newline seperated string can be indented with a given
 *                number of spaces
 * Arguments:     str: Original message
 *                width: The total maximum width of each line
 *                indent: (optional) How many spaces to indent with or string
 *                        to indent with
 *                speicial_first_line: (optional) flag for handling of the
 *                                     indentation of first line:
 *                                     0 : handle as other lines
 *                                     >0: handle as if it was already indented
 *                                     <0: do not indent the first line
 *                align: (optional) String that says which align the result
 *                       shall have:
 *                       "" : right flushed
 *                       "-": left flushed (default)
 *                       "|": centered
 *                       Centered and left flushed do not work with a special
 *                       first line.
 * Returns:       A string with newline separated strings
 */

// Despite this function name, this function is in use
varargs string old_break_string(string str, int width, mixed indent,
                                int special_first_line, string align) {
  string format;

  if (!stringp(str))
    str = to_string(str);
  if (!width)
    width = ((this_player() &&
              this_player()->query_property(P_DISPLAY_WIDTH)) || 79);
  if (!align)
    align = "-";
  format = "%=" + align + "*s";
  if (!indent)
    return sprintf(format, width, str || "");
  if (intp(indent)) {
    if (special_first_line < 0)  // do not indent first line
      str = str[0..indent-1] + sprintf(format, width-indent, str[indent..]);
    else
      str = sprintf(format, width-indent, str);
    indent = sprintf("%*s", indent, "");
  }
  else if (special_first_line < 0) // do not indent first line
    str = str[0..strlen(indent)-1] + sprintf(format, width-strlen(indent),
                                             str[strlen(indent)..]);
  else
    str = sprintf(format, width-strlen(indent), str);
  if (str[<1] == '\n')
    str = implode(explode(str[0..<2], "\n"), "\n" + indent) + "\n";
  else
    str = implode(explode(str, "\n"), "\n" + indent);
  if (!special_first_line)
    str = indent + str;
  return str;
}

varargs string break_string(string str, int width, mixed indent,
                            int special_first_line, string align) {
  mixed colour_mapper;

  colour_mapper = (this_player() &&
                   (this_player()->get_terminal_colour_closure() ||
                    this_player()->get_terminal_colour_mapping()) ||
                   (: "" :));
  if (align && align != "-")
    return old_break_string(str, width, indent, special_first_line, align);
  if (!stringp(str))
    str = to_string(str);
  if (!width)
    width = ((this_player() &&
              this_player()->query_property(P_DISPLAY_WIDTH)) || 79);
  if (!indent)
    return terminal_colour(str || "", colour_mapper, width);
  if (intp(indent)) {
    if (special_first_line < 0) // do not indent first line
      return terminal_colour(str, colour_mapper, width, indent);
    else
      return terminal_colour(str, colour_mapper, width-indent);
    indent = sprintf("%*s", indent, "");
  }
  else if (special_first_line < 0) // do not indent first line
    str = (str[0..strlen(indent)-1] +
           terminal_colour(str[strlen(indent)..], colour_mapper,
                           width-strlen(indent)));
  else
    str = terminal_colour(str, colour_mapper, width-strlen(indent));
  if (str[<1] == '\n')
    str = implode(explode(str[0..<2], "\n"), "\n" + indent) + "\n";
  else
    str = implode(explode(str, "\n"), "\n" + indent);
  if (!special_first_line)
    str = indent + str;
  return str;
}

#define SHORT(item) ((this_player() && this_player()->query_int() < 1 && \
                      !living(item))? "a funny thing" : (item)->short())
#define NAME(item) ((this_player() && this_player()->query_int() < 1 && \
                     !living(item)) ? "thing" : (item)->query_name())
private varargs int position_of_object(object o, status full) {
  string desc;
  object n;
  int i;

  desc = ((full & DESCRIBE_FULL) ? SHORT(o) : (NAME(o) || SHORT(o)));
  if (desc && stringp(desc) && environment(o))
    for (n = first_inventory(environment(o)); n; n= next_inventory(n)) {
      if (n == o) {
        i++;
        break;
      }
      else if (desc == ((full & DESCRIBE_FULL) ? SHORT(n)
                                               : (NAME(n) || SHORT(n))))
        i++;
    }
  return i != 1 && i;
}

private string get_state_description(mixed fun, object o) {
  if (pointerp(fun) && !fun[0])
    return call_other(o, fun[1], 1, o);
  else if (stringp(fun))
    return fun;
  else
    return apply_function(fun, 1, o);
}

void analyze_coloured_string(string s, string verbatim, string colours,
                             string *tokens) {
  string *elements;
  string format;
  int i;

  elements = regexplode(s, REGEXP_TERMINAL_COLOUR_TOKEN);
  verbatim = elements[0];
  format = "%'\x01'*s";
  colours = sprintf(format, strlen(verbatim), "");
  tokens = ({});
  for (i=1; i<sizeof(elements); i++) {
    tokens += ({ elements[i++] });
    verbatim += elements[i];
    format[2]++;  // this is \x01 initially and is raised
    if (format[2] == '\'')
      colours += sprintf("%'\\''*s", strlen(elements[i]), "");
    else if (format[2] == '\\')
      colours += sprintf("%'\\\\'*s", strlen(elements[i]), "");
    else {
      colours += sprintf(format, strlen(elements[i]), "");
    }
  }
}

string synthesize_coloured_string(string verbatim, string colours,
                                  string *tokens) {
  int i, token_count;
  string result;

  result = "";
  token_count = 1;
  for (i=0; i<strlen(verbatim); i++) {
    while (i <= strlen(colours) && colours[i] > token_count)
      result += tokens[(token_count++)-1];
    result += verbatim[i..i];
  }
  result += implode(tokens[token_count-1..], "");
  return result;
}

varargs string subcoloured_string(string coloured_string, int start, int stop,
                                  status start_from_back,
                                  status stop_from_back) {
  string colours, chars;
  string *tokens;

  analyze_coloured_string(coloured_string, &chars, &colours, &tokens);
  if (start_from_back)
    if (stop_from_back) {
      chars = chars[<start..<stop];
      colours = colours[<start..<stop];
    }
    else { // stop from front
      chars = chars[<start..stop];
      colours = colours[<start..stop];
    }
    else // start from front
      if (stop_from_back) {
      chars = chars[start..<stop];
      colours = colours[start..<stop];
    }
    else { // stop from front
      chars = chars[start..stop];
      colours = colours[start..stop];
    }
  return synthesize_coloured_string(chars, colours, tokens);
}

/* This function capitalizes the input text even if there are colour control
 * tokens set around it.
 */
string capitalize_coloured(string input) {
  string *ss;

  ss = regexplode(input, "^("REGEXP_TERMINAL_COLOUR_TOKEN"| )*");
  return ss[1] + capitalize(ss[2]);
}

varargs string describe(mixed what, mixed the, int full, int count,
                        status possessive_s,
                        string *uninteresting_state_descriptions) {
  mixed h, h2;
  string desc, article, state, behind_number;
  string colours;
  string *tokens;
  status is_plural, has_no_article;
  int first_space, amount;
  int has_number;   // 1=number in digit(s), 2=number in word(s)

  if (stringp(what)) {
    desc = what;
    if (full & DESCRIBE_IS_PLURAL)
      is_plural = 1;
  }
  else if (objectp(what)) {
    if (count < 0)  // flag for "first torch" instead of "torch" set
      h = position_of_object(what, full);
    is_plural = what->query_plural();
    h2 = what->query_property(P_STATE_DESCRIPTION);
    state = ((full & DESCRIBE_WITH_STATE) && pointerp(h2) &&
             sizeof(h2 = map(h2, #'get_state_description, what) - ({ 0 }) -
                    (uninteresting_state_descriptions || ({}))) &&
             implode(h2, ", "));
    has_no_article = what->query_no_article();
    if (!(full & DESCRIBE_FULL)) {
      if (!((desc = NAME(what)) && stringp(desc)))
        desc = SHORT(what);
    }
    else {
      desc = SHORT(what);
    }
#ifdef DESCRIBE_WITH_INVENTORY
    if (desc && (full & DESCRIBE_WITH_INVENTORY) &&
        !what->hide_inventory()) {
      if (sizeof(h2 = describe_list(all_inventory(what),
                                    ARTICLE_A, full))) {
        desc += (" (" + (living(what) ? "carrying" : "containing") +
                 " " + make_list(h2) + ")");
      }
    }
#endif
  }
#ifdef RAISE_ERRORS
  else
    raise_error("Bad argument 1 to describe()\n");
#endif
  if (!desc || !stringp(desc))
    return 0;
  analyze_coloured_string(desc, &desc, &colours, &tokens);
  if (this_player() && objectp(what)) {
    int ind;
    while ((ind = member(tokens, TERMCOL_DESC_LIVING)) > -1) {
      tokens[ind] = LIB_CNTL_SEQUENCES->
                       get_living_colour_description(this_player(), what);
    }
  }
  if (!has_no_article)
    switch (desc[0]) {
    case 'a': case 'A':
      if (desc[1..2] == "n ") {
        article = "an";
        desc[0..2] = "", colours[0..2] = "";
      }
      else if (desc[1] == ' ') {
        article = "a";
        desc[0..1] = "", colours[0..1] = "";
      }
      break;
    case 'm': case 'M':
      if (desc[1..4] == "any ") {
        article = "many";
        desc[0..4] = "", colours[0..4] = "";
        is_plural = 1;
      }
      break;
    case 's': case 'S':
      if (desc[1..4] == "ome ") {
        article = "some";
        desc[0..4] = "", colours[0..4] = "";
        is_plural = 1;
      }
      break;
    case 't': case 'T':
      if (desc[1..3] == "he ") {
        article = "the";
        desc[0..3] = "", colours[0..3] = "";
      }
      break;
    }
  if (count < 0) {
    count = 0;
    if (h) {
      h2 = LIB_PARSE->get_ordinal(h) + " ";
      desc = h2 + desc;
      colours = sprintf("%'\x01'*s", strlen(h2),"") + colours;
    }
  }
  // find out if the description starts with a numeral
  first_space = strstr(desc, " ");
  if (first_space < 0)
    first_space = strlen(desc);
  behind_number = "";
  if (isdigit(desc[0])) {
    has_number = 1; // 1 means numberis given in digits
    sscanf(desc, "%d%s %s", amount, behind_number, h);
    if (strlen(desc) <= first_space) // too long?
      desc = "", colours = "";
    else
      desc[0..first_space] = "", colours[0..first_space] = "";
  }
  else if (amount = LIB_PARSE->parse_numeral(desc[0..first_space-1])) {
    has_number = 2; // 2 means number is given in word(s)
    if (strlen(desc) <= first_space) // too long
      desc = "", colours = "";
    else
      desc[0..first_space] = "", colours[0..first_space] = "";
  }
  else // no number given
    amount = 1;
  if (amount > 1)
    is_plural = 1;
  amount *= (count || 1);
  if (amount > 1 && !has_number && is_plural) {
    h2 = (objectp(what) && living(what)) ? "group of " : "set of ";
    desc = h2 + desc;
    colours = sprintf("%'\x01'*s", strlen(h2), "") + colours;
    is_plural = 0;
  }
  if (!has_number && amount != 1)
    has_number = 2; // 2 default for numerating is in word
  if (amount > 1 && !is_plural) {
    desc = efun::call_other(LIB_LANGUAGE, "plural_sentence", desc, &colours);
    // TODO: adapt colours here
  }
  if (intp(the))  // is an article from the macros given?
    switch (the) {
    case ARTICLE_A:
      if (!has_number && islower(desc[0])) {
        if (!has_no_article) {
          if (is_plural)
            article = article || "some";
          else
            article = article || call_other(LIB_LANGUAGE, "article", desc);
        }
      }
      else if (has_number)
        article = 0;
      break;
    case ARTICLE_THE:
      if (has_number || islower(desc[0]) || article)
        article = "the";
      else
        article = 0;
      break;
    case ARTICLE_NONE:
      article = 0;
      break;
    }
  if (has_number == 1) { // number in digits?
    h2 = amount + behind_number + " ";
    desc = h2 + desc;
    colours = sprintf("%'\x01'*s", strlen(h2), "") + colours;
  }
  else if (has_number == 2) { // number in words?
    h2 = LIB_LANGUAGE->word_number(amount) + " ";
    desc = h2 + desc;
    colours = sprintf("%'\x01'*s", strlen(h2), "") + colours;
  }
  if (stringp(the))
    article = the;
  if (possessive_s) {
    h = regexplode(desc, "[ \t]*[ \t]\\(");
#ifdef SIMPLE_POSSESSIVE_S_ENDING
    h2 = strlen(h[0]) - 1;
    if (h[0][<1] == 's')
      h[0] += "\'", colours[h2+1..h2] = colours[h2..h2];
    else
      h[0] += "\'s", colours[h2+1..h2] = colours[h2..h2] + colours[h2..h2];
#else
    // #else part not adopted to colourd string
    if ((is_plural || count > 1) && 's' == h[0][<1])
      h[0] += "\'";
    else
      h[0] += "\'s";
#endif
    desc = implode(h, "");
  }
  desc = synthesize_coloured_string(desc, colours, tokens);
  return ((article ? article + " " + desc : desc) +
          (((full & DESCRIBE_WITH_STATE) && state) ? " (" + state + ")" : ""));
}

string mprintf(string str, mapping ins) {
  mixed fmt;
  string i;
  int t;

  fmt = explode(str, "%");
  for (t=1; t<sizeof(fmt); t++)
    if (fmt[t] == "")
      fmt[t++] = "%";
    else if (i = ins[fmt[t][0]])
      fmt[t][0..0] = funcall(i);
  return implode(fmt, "");
}

