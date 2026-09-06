/* String-Lib
**
** A collection of routines handling strings.
**
**   31-Jul-92 [m] Extracted from ~mateese/obj/lpclib
**   02-Aug-92 [m] Included parts of ~hyp/lib/string
**   05-Aug-92 [m] smore()
**   26-Aug-92 [m] smore_prompt()
**   02-Sep-92 [m] SD_SDATE for stime()
**   30-Jul-93 [m] (mixed|val)_to_str() updated for new mappings.
**   05-May-94 [t] Editor-Function and (mixed|val)_to_string updated
**                 for closures
**   09-May-94 [t] Some additional Editor-Functions
**   18-May-94 [m] smore() now multi-player secure.
**   25-Jun-94 [m] genitive(), article() added (Idea: Thragor)
**                 sort_strings() improved.
**                 smore() no longer adds empty lines.
**   11-Oct-94 [t] improved Editor
**   22-Dec-94 [m] Added regexp search to smore().
**   18-May-95 [t] Added function 'wrap' to split lines
**   16-Aug-95 [t] mixed_to_string taken from /obj/tool/xtool/xtool.lib.c
**   15-Jan-98 [s] wrap adapted to terminal_colour to wrap colours correctly
**   15-Jan-98 [s] SMore moved here from string.h to avoid errors
**   07-Feb-98 [s] add_gen,add_a compat, more to lib/more
**
**  [m] Mateese, Biontic Magics & Darkness
**  [t] Thragor
**  [s] Softbyte
*/

#include <secure/wizlevels.h>
#include <properties.h>
#include <driver/lpctypes.h>
#include <driver/object_info.h>
#include <string.h>
#include <daemons.h>

#define MYFILE "/lib/string"
#define ME this_object()
#define TP this_player()

#pragma save_types

inherit "/lib/more";

public string chr(int val)
{
  return to_string(({val}));
}

/*-------------------------------------------------------------------------
** string mkstr (int len, void|string pattern)
**
**  Returns a string of length <len> made out of <pattern>, or of spaces if
**  <pattern> is not defined.
*/

varargs string mkstr (int len, string pattern) {
  string rc;
  int actlen;

  if (len <= 0) return "";
  if (!pattern) pattern = "          ";
  rc = pattern;
  actlen = sizeof(pattern);
  while (actlen < len) rc += rc, actlen *= 2;
  return rc[0..len-1];
}

/*-------------------------------------------------------------------------
** string ladjust (string str, int len, void|string pattern)
**
** Returns <str> adjusted to length <len> by repeatedly adding <pattern>
** (or spaces if <pattern> isn't given) to its tail. If <str> is longer than
** <len>, it remains unchanged.
*/

varargs string ladjust (string str, int len, string pattern) {
  int actlen;

  if (!str || len <= 0) return 0;
  if ((actlen = sizeof(str)) >= len) return str;
  return str+mkstr(len-actlen, pattern);
}

/*-------------------------------------------------------------------------
** string ladjcut (string str, int len, void|string pattern)
**
** Returns <str> adjusted to length <len> by repeatedly adding <pattern>
** (or spaces if <pattern> isn't given) to its tail if <str> is too short,
** or by removing extraneous characters from the tail if <str> is too long.
*/

varargs string ladjcut (string str, int len, string pattern) {
  int actlen;

  if (!str || len <= 0) return 0;
  if ((actlen = sizeof(str)) <= len) return str+mkstr(len-actlen, pattern);
  return str[0..len-1];
}

/*-------------------------------------------------------------------------
** string radjust (string str, int len, void|string pattern)
**
** Returns <str> adjusted to length <len> by repeatedly adding <pattern>
** (or spaces if <pattern> isn't given) to its head. If <str> is longer than
** <len>, it remains unchanged.
*/

varargs string radjust (string str, int len, string pattern) {
  int actlen;

  if (!str || len <= 0) return 0;
  if ((actlen = sizeof(str)) >= len) return str;
  return mkstr(len-actlen, pattern)+str;
}

/*-------------------------------------------------------------------------
** string radjcut (string str, int len, void|string pattern)
**
** Returns <str> adjusted to length <len> by repeatedly adding <pattern>
** (or spaces if <pattern> isn't given) to its head if <str> is too short,
** or by removing extraneous characters from the head if <str> is too long.
*/

varargs string radjcut (string str, int len, string pattern) {
  int actlen;

  if (!str || len <= 0) return 0;
  if ((actlen = sizeof(str)) <= len) return mkstr(len-actlen, pattern)+str;
  return str[<len..<1];
}

/*-------------------------------------------------------------------------
** string cadjust (string str, int len, void|string pattern)
**
** Returns <str> centered to length <len> by repeatedly adding <pattern>
** (or spaces if <pattern> isn't given).
** If <str> is longer than <len>, it remains unchanged.
*/

varargs string cadjust (string str, int len, string pattern) {
  int actlen;

  if (!str || len <= 0) return 0;
  if ((actlen = sizeof(str)) >= len) return str;
  return mkstr((len-=actlen)/2, pattern)+str+mkstr((len+1)/2, pattern);
}

/*-------------------------------------------------------------------------
** string cadjcut (string str, int len, void|string pattern)
**
** Returns <str> centered to length <len> by repeatedly adding <pattern>
** (or spaces if <pattern> isn't given) if <str> is too short, or by
** removing extraneous characters from its tail if <str> is too long.
*/

varargs string cadjcut (string str, int len, string pattern) {
  int actlen;

  if (!str || len <= 0) return 0;
  if ((actlen = sizeof(str)) <= len)
    return mkstr((len-=actlen)/2, pattern)+str+mkstr((len+1)/2, pattern);
  return str[0..len-1];
}

varargs string countup(string *foo, mixed separator) {
  if (!foo || !sizeof(foo))
    return "";
  else if (sizeof(foo) == 1)
    return foo[0];
  else if (sizeof(foo) == 2) {
    if (intp(separator) && separator == 1)
      return sprintf("%s or %s", foo[0], foo[1]);
    else if (stringp(separator))
      return sprintf("%s %s %s", foo[0], separator, foo[1]);
    else
      return sprintf("%s and %s", foo[0], foo[1]);
  }
  else {
    if (intp(separator) && separator == 1)
      return implode(foo[..<2], " or ") + " or " + foo[<1];
    else if (stringp(separator))
      return implode(foo[..<2], " " + separator + " ") +
                     " " + separator + " " + foo[<1];
    else
      return implode(foo[..<2], ", ") + ", and " + foo[<1];
  }
  return "";
}

/*-------------------------------------------------------------------------
** string string_replace (string str, string old, string new)
**
** Replace in <str> all occurences of <old> by <new>.
*/

string string_replace (string str, string old, string new) {
  string back;

  if (!(str && old && new)) return str;
  else if (str == old) return new;
  else if ( sizeof(str) < sizeof(old) ) return str;
  back = implode(explode(str, old), new);
/*
  if (str[0..len-1] == old) back = new + back;
  if (str[<len..<1] == old) back = back + new;
*/
  return back;
}

/*----------------------------------------------------------------------
** string strip_blanks (string str)
**
** Replace all blank-sequences in <str> by a single blank and return
** the result.
*/

string strip_blanks (string str) {
  return implode(explode(str, " ") - ({ "" }), " ");
}

/*----------------------------------------------------------------------
** string clip_blanks (string str)
**
** Remvoes leading and tailing blanks
*/
string clip_blanks(string str)
{
string s;
  s=strip_blanks(str);
  if (s[0..0]==" ") s=s[1..<1];
  if (s[<1..<1]==" ") s=s[0..<2];
  return s;
}


/*----------------------------------------------------------------------
** string genitive(string word)
**
** Return the word with the correct genetiv-ending, i. e. with
** "'" for all words ending with s, x or z and otherwise "'s".
**
** Obsolete function since add_gen is implemented. Should be removed.
**    Thragor, 18may95
*/

string genitive(string word)
{
 if (!word)
   return 0;
 return add_gen(word);
//  return word + (member("sxz", word[<1]) != -1 ? "'" : "'s");
}

/*----------------------------------------------------------------------
** string article(string word)
**
** Return the word with the correct undefined article, i. e. with
** "an" for all words beginning with a vocal and otherwise "a".
**
** Obsolete function since add_a is implemented. Should be removed.
**   Thragor, 18may95
*/

string article(string word)
{
 if (!word)
   return 0;
 return add_a(word);
//  return word + (member("aeiou", word[0]) != -1 ? "an " : "a");
}

/*----------------------------------------------------------------------
** int string_compare (str1, str2)
**
** Return if str1 is lexicographically greater than str2.
** This fun is meant mainly for use by sort_strings().
*/

int string_compare (string str1, string str2) {
  return str1 > str2;
}

/*----------------------------------------------------------------------
** string *sort_strings (string *strs, void|string|closure compare_fun)
**
** Sort an array <strs> of strings by using <compare_fun> (default is
** the lib's "string_compare") and return the sorted array.
** <compare_fun> should be of type  int (string, string) and return
** nonzero if the first string is 'greater' than the second.
*/

varargs string *sort_strings (string *strs, mixed compare_fun) {
  if (!strs) return 0;
  if (!compare_fun) compare_fun = #'>; /*'*/
  return sort_array (strs, compare_fun);
}

/*-------------------------------------------------------------------------
** string *break_string (string str, int len)
**
** Break <str> into parts of length <len> and return an array of these
** parts.
*/

string *break_string (string str, int len) {
  int i, m;
  string *parts;

  parts = ({});
  if (!(str && (len > 0))) return 0;
  if ((m = sizeof(str)) <= len) return ({ str });
  for (i = 0; i < m; i += len) parts += ({ str[i..i+len-1] });
  return parts;
}

/*-------------------------------------------------------------------------
** string *break_line (string str, void|int len, void|string prefix)
**
** Clips a <text> (w/o newlines!) wordwise down to a linelength <len>
** (default 78) and return the array of the resulting lines.
** Any additional line is prefixed with <prefix>.
** If a single word itself is longer than <len>, it will be splitted as
** as well.
*/

varargs string *break_line (string str, int len, string prefix) {
  int i, j, k, s, plen;
  string *strs, *words, *text, pfix;

  words = ({});
  text = ({});
  if (!len) len = 78;
  if (!prefix) prefix = "";
  plen = sizeof(prefix);
  pfix = "";
  if (!(str && (len > 0))) return 0;
  plen = sizeof(prefix);
  strs = explode(". "+str+" .", " ");
  for (i=1, s=sizeof(strs)-1; i < s; i++)
    words += break_string (strs[i], len);
  s = sizeof(words);
  for (i=0, j=0, k=0; j < s; j++) {
    k += sizeof(words[j]);
    if (k+j-i <= len) continue;
    text += ({ pfix+implode(words[i..j-1], " ") });
    if (!i) pfix = prefix;
    k = plen+sizeof (words[i=j]);
  }
  return text + ({ pfix+implode(words[i..j-1], " ") });
}

/*-------------------------------------------------------------------------
** string wrap(string str,void|int length,void|int lspace)
** Adds newlines to a string, if one part of the string is
** longer than <length>-<lspace> chars. <lspace> spaces will
** be added in front of the line. This is except for the first
** line. This line will have <length> chars and start in the
** first column.
*/

public varargs string wrap(string str,int length,int lspace)
{
mapping trans;
string euid;

  if (!length) length=78;
  euid=geteuid();
  seteuid(getuid());
  trans = ({mapping})COLOUR_D->QueryIdentTrans();
  seteuid(euid);
  return terminal_colour(str,trans,length,lspace);

/*
  return
    sprintf("%"+lspace+"s%-"+((length||78)-lspace)+"=s",
            str[0..lspace-1],str[lspace..]);
*/
}

/*-------------------------------------------------------------------------
** string lit_string (string str)
**
** Replace any control characters (tab, \, newline, CR) in <str> by their
** LPC-notation (\t, \\, \n, \r) and return the result.
*/

string lit_string (string str) {
  str = string_replace (str, "\\", "\\\\");
  str = string_replace (str, "\n", "\\n");
  str = string_replace (str, "\r", "\\r");
  str = string_replace (str, "\t", "\\t");
  return string_replace (str, "\"", "\\\"");
}

/*-------------------------------------------------------------------------
** string val_to_str (mixed value, void|int depth)
**
** Makes a printable string from any value.
** Arrays are expanded in <depth>-1 recursions.
** <depth> == 0 expands any depth.
*/

varargs string val_to_str (mixed value, int depth) {
  if (intp(value)||floatp(value)) return ""+value;
  else if (stringp(value)) return "'"+value+"'";
  else if (objectp(value)) return "["+object_name(value)+"]";
  else if (closurep(value)) return sprintf("%O",value);	// added by Thragor
  else if (pointerp(value)) {
    if (!sizeof(value)) return "({ })";
    if (depth == 1) return "({..})";
    return
       "({ "
       +implode(map(value,"val_to_str",this_object(),depth?depth--:0)
               ,", ")
       +" })";
  }
  else if (mappingp(value)) {
    if (!sizeof(value)) return "([ ])";
    if (depth == 1) return "([..])";
    return "([ "+implode(map(m_indices(value), "map_value"
                                 ,this_object(), ({value, depth?depth--:0}))
                , ", ")
           +" ])";
  }

  return "???";
}

string map_value (mixed key, mixed *data) {
  int i, width, depth;
  mapping value;
  mixed *rc;
  value = data[0]; depth = data[1];
  width = get_type_info(value,1);
  rc = ({});
  for (i=0; i < width; i++)
    rc += ({ value[key,i] });
  return val_to_str(key, depth)+":"
         +implode(map(rc,"val_to_str",this_object(),depth), ";");
}

/*-------------------------------------------------------------------------
** string mixed_to_string (mixed value, void|int depth)
**
** Makes a string in LPC-notation from any value.
** Arrays are expanded in <depth>-1 recursions.
** <depth> == 0 expands any depth.
*/

varargs string mixed_to_string(mixed mix, int lvl)
{
  int i, j, s, t;
  string str;
  mixed *keys;

  switch(typeof(mix))
    {
     default:
     case T_INVALID:
      return "<invalid>";
     case T_LVALUE:
      return "&"+mixed_to_string(mix, lvl-1);
     case T_NUMBER:
     case T_FLOAT:
      return to_string(mix);
     case T_STRING:
      return "\""+lit_string(mix)+"\"";
     case T_POINTER:
      if (!sizeof(mix)) return "({ })";
      if (lvl==1) return "({...})";
      return "({"+implode(map(mix,#'mixed_to_string, //'
				    lvl?lvl--:0),",")+"})";
     case T_OBJECT:
      return "["+object_name(mix)+"]";
     case T_CLOSURE:
     case T_SYMBOL:
      return sprintf("%O", mix);
     case T_QUOTED_ARRAY:
      return "'"+mixed_to_string(funcall(lambda(0, mix)), lvl-1);
     case T_MAPPING:
      if (!s=sizeof(keys=m_indices(mix)))
        return "([ ])";
      if (lvl==1) return "([...])";
      t=get_type_info(mix, 1);
      str="([";
      for(i=0;i<s;i++)
        {
	  str+=mixed_to_string(keys[i],lvl?lvl-1:0);
	  if(t)
            {
	      str+=":"+mixed_to_string(mix[keys[i],0],lvl?lvl-1:0);
	      for(j=1;j<t;j++)
	        str+=";"+mixed_to_string(mix[keys[i],j],lvl?lvl-1:0);
	    }
	  if(i<s-1) str+=",";
	}
      return str+"])";
    }
  return "...";
}
/*
varargs string mixed_to_string (mixed value, int depth) {
  if (intp(value)||floatp(value)) return ""+value;
  else if (stringp(value)) return "\""+lit_string(value)+"\"";
  else if (objectp(value)) return "["+object_name(value)+"]";
  else if (closurep(value)) return sprintf("%O",value);	// added by Thragor
  else if (symbolp(value)) return sprintf("%O",value);	// added by Thragor
  else if (pointerp(value)) {
    if (!sizeof(value)) return "({ })";
    if (depth == 1) return "({..})";
    return
       "({ "
       +implode(map(value,"mixed_to_string",this_object(),depth?depth--:0),", ")
       +" })";
  }
  else if (mappingp(value)) {
    if (!sizeof(value)) return "([ ])";
    if (depth == 1) return "([..])";
    return "([ "+implode(map(m_indices(value), "mapping_value"
                                 ,this_object(), ({value, depth?depth--:0}))
                , ", ")
           +" ])";
  }

  return "???";
}

string mapping_value (mixed key, mixed *data) {
  int i, depth, width;
  mapping value;
  mixed *rc;
  value = (mapping)data[0]; depth = (int)data[1];
  width = get_type_info(value,1);
  rc = ({});
  for (i=0; i < width; i++)
    rc += ({ value[key,i] });
  return mixed_to_string(key, depth)+":"
         +implode(map(rc,"mixed_to_string",this_object(),depth), ";");
}
*/
/*-------------------------------------------------------------------------
** string stime (int date, void|int fmt)
**
** Like cdate() this converts a numeric date into a string, but in a more
** european manner: 'Mon 15-Jun-1992 20:00:00'
** 'fmt' specifies which parts appear:
**    SD_WDAY  : day of the week
**    SD_DATE  : the date itself
**    SD_SDATE : the date itself, but w/o the century
**    SD_TIME  : the time
** fmt==0 defaults to (SD_WDAY | SD_DATE | SD_TIME) == SD_FULL
*/

varargs string stime (int date, int fmt) {
  string cdate, rc;
  if (!fmt) fmt = SD_FULL;
  if (fmt & SD_DATE && fmt & SD_SDATE) fmt ^= SD_SDATE;
  cdate = ctime(date);
  rc = "";
  if (SD_WDAY & fmt) {
    rc = cdate[0..2];
    if (fmt & (SD_DATE | SD_TIME | SD_SDATE)) rc += " ";
  }
  if (SD_DATE & fmt) {
    rc = rc+cdate[8..9]+"-"+cdate[4..6]+"-"+cdate[20..23];
    if (fmt & SD_TIME) rc += " ";
  }
  if (SD_SDATE & fmt) {
    rc = rc+cdate[8..9]+"-"+cdate[4..6]+"-"+cdate[22..23];
    if (fmt & SD_TIME) rc += " ";
  }
  if (SD_TIME & fmt) rc = rc+cdate[11..18];
  return rc;
}

/*
* An editor which you may use anywhere
* by Thragor@Nightfall V1.0
* The editor is called with:
*  void input_text(void|string func,void|object ob,void|object pl)
* So it doesn't need any argument. It will set default-values then.
* The default values are:
*  func = "input_done"
*  ob = this_object()||previous_object()
*  pl = this_player()
* <func> is the function which will be called, when all inputs are
* done and the text is finished (or the input got aborted). If aborted,
* the function will get a 0 as argument, if not, it will be called with
* the whole text as argument.
* <ob> is the object in which the function <func> should be called.
* <pl> is the player editing this text and who will receive all messages.
* The editor is meant to be used by players, e. g. to write notes or
* letters. It does not offer any usage of files.
* For more info read the doc or look at the example-file:
* ~thragor/item/input_exm.c
*/

/*
* break_input()
* Return 0 to the defined function, if the player aborted the input.
*/

public varargs void break_input(object pl,closure func,mixed args)
{
  if (!pl) return;
  tell_object(pl,"You canceled the input.\n");
  apply(func,0,args); // no text
}

/*
* show_help()
* Shows all available commands to the player
*/

public varargs void show_help(object pl)
{
  if (!pl) return;
  tell_object(pl,"\
~q         : cancel input\n\
~h         : show this help\n\
~d[line]   : delete last or specified line\n\
~w[from,to]: wrap all lines, or from one line to a certain line;\n\
             for wrapping a screen of at least 78 chars width is assumed;\n\
             empty lines will end a paragraph\n\
~r         : redisplay what you've written so far\n"+
(IS_IMMORTAL(pl)?"~s[file]   :      save text in file [file]\n"
                "~l[file]   :      load text from file [file]\n"
               :""
)
+"\nUse ** or . to end the input.\n");
}

/*
* del_line()
* Delete the line before and jump to it
*/

int del_line(string *message,int current_line,int delline)
{
  if (delline<0) return 0;
  if (delline>=sizeof(message)) return 0;
  message = message[0..delline-1]+message[delline+1..];
  current_line--;
  return 1;
}

/*
* wrap_lines(string *message,int current_line,int from,int to)
* Wraps the lines in a certain region. Blank lines will be recognized
* as the end of a paragraph.
*/

int wrap_lines(string *message,int current_line,int from,int to)
{
  string *towrap,*result;
  int blankpos;
  if (to<from||from<0||to>sizeof(message)) return 0;
  towrap = message[from..to];
  result = ({});
  while(sizeof(towrap))
    {
      string *actwrap;

      blankpos = member(towrap,"");
      if (blankpos==-1)
	actwrap = towrap;
      else
	actwrap = towrap[0..blankpos-1];
      actwrap = explode(wrap(implode(actwrap," ")),"\n");
      result+=actwrap+(blankpos==-1?({}):({""}));
      if (blankpos==-1) towrap = ({});
      else if (blankpos+1<sizeof(towrap)) towrap = towrap[blankpos+1..];
      else towrap = ({});
    }
  message = message[0..from-1]+result+
    (sizeof(message)>to?message[to+1..]:({}));
  current_line = sizeof(message);
  return 1;
}

/*
* ed_display()
* Display the whole text, which the player has written so far
*/

varargs void ed_display(object pl,string *message)
{
  int i;
  if (pl)
    for (i=0;i<sizeof(message);i++)
      tell_object(pl,to_string(i+1)+". "+message[i]+"\n");
}

varargs void end_input(object pl,closure func,string *message,mixed args)
{
  if (!pl) return;
  tell_object(pl,"You ended your input.\n");
  apply(func,implode(message,"\n")+"\n",args);
}

/*
* load_message()
* Load a file into the editor
*/

string *load_message(string fname)
{
  string text;
  text = read_file(fname);
  return text?explode(text,"\n"):0;
}

/*
* save_message()
* Save message from editor
*/

int save_message(string *message,string fname)
{
  int res,i;
  res = 1;
  for(i=0;i<sizeof(message||({}));i++)
    res &= write_file(fname,message[i]+"\n");
  return res;
}

/*
* input_loop()
* The loop which handles all input and calls all edit-functions.
*/

void input_loop(string str,object pl,closure func,
                string *message,int line,mixed args)
{
  int go_on,from,to;
  string hstr,*hmessage,fname;

  if (!pl) return;
  go_on = 1;
  if (str[0]=='~')
    switch(str[1])
      {
        case 'q': return break_input(pl,func,args); break;
        case 'h': show_help(pl); go_on = 0; break;
        case 'd': go_on = 0;
                  if (str!="~d"
                      &&!(sscanf(str,"~d%s",hstr)
                      && sscanf(hstr,"%d",from)))
                    {
                      tell_object(pl,"Give a number as argument!\n");
                      break;
                    }
                  if (!from) from = line;
                  if (!del_line(&message,&line,from-1))
                    write("Wrong line specified.\n");
                  break;
        case 'w': go_on = 0;
	          if (   str!="~w"
		      && !(   sscanf(str,"~w%s",hstr)
			   && sscanf(hstr,"%d,%d",from,to)==2
                          )
		     )
		    {
		      tell_object(pl,"Give <from>,<to> as argument!\n");
		      break;
		    }
		  if (!from) from = 1;
		  if (!to) to = sizeof(message);
		  if (!wrap_lines(&message,&line,from-1,to-1))
		    write("Wrong lines specified.\n");
		  break;
        case 'r': ed_display(pl,message);
                  go_on = 0;
                  break;
	case 's': if (!IS_IMMORTAL(pl)) break;
                  if (!sscanf(str,"~s%s",fname))
                    {
                      tell_object(pl,"Give a filename as argument!\n");
                      break;
                    }
                  if (sizeof(explode(fname," "))>1)
                    {
                      tell_object(pl,"No spaces allowed in Filenames.\n");
                      break;
                    }
                  if (!save_message(message,fname))
                    tell_object(pl,"Errer when writing file.\n");
                  break;
	case 'l': if (!IS_IMMORTAL(pl)) break;
                  if (!sscanf(str,"~l%s",fname))
                    {
                      tell_object(pl,"Give a filename as argument!\n");
                      break;
                    }
                  if (sizeof(explode(fname," "))>1)
                    {
                      tell_object(pl,"No spaces allowed in Filenames.\n");
                      break;
                    }
                  if (hmessage = load_message(fname))
                    {
                      message = hmessage;
                      line = sizeof(message);
                      if (line&&message[<1]=="")
                        {
                          message = message[0..<2];
                          line--;
                        }
                    }
                  else
                    tell_object(pl,"Error when reading file.\n");
                  break;
	default:  go_on = 0;
                  tell_object(pl,"Unknown function.\n");
      }
  if (str=="."||str=="**")
    return end_input(pl,func,message,args);
  if (go_on)	// if no special command has been called
    {
      message+=({str});
      line++;
    }
  tell_object(pl,to_string(line+1)+".]");
  input_to("input_loop",0,pl,func,message,line,args);
}

/*
* input_text()
* This starts the whole editing. If pl is not defined, it is replaced by
* this_player() or the previous_object(), if the function is not defined
* the standard function to be called when the text is finished is
* 'input_done'. If ob is not defined it is replaced by this_object() or,
* if this_object() is this file, it is replaced by the previous_object().
* Text is a predefined text, e. g. if you want to modify an existing text.
*
* You may choose where to put the variables freely. These are the possible
* arguments you may give:
* string text: The text which is already written (default "")
* string|closure function: The function to be called after input
*                          (default "input_to")
* object ob: The object in which the function shall be called
*            (default: this_object() or previous_object()
*                      if /lib/string got called via call_other)
* mixed args: An array of all args which shall be passed to the
*             function in addition to the returned text (first arg of
*             the function).
*             Because the function will be called via apply, all args
*             are given in order, i. e. if you give ({"test",1}) as
*             arguments, the function will be called like this:
*                 function(written_text,"test",1)
* object pl: Finally you may give the player who shall edit.
*            pl has to be a player and NO npc.
*/

varargs void input_text(mixed arg1,mixed arg2,mixed arg3,mixed arg4,
                        mixed arg5)
{
  string *message;
  object ob, pl;
  string text;
  mixed args,func;
  int line;

  ob = (objectp(arg1) && !query_once_interactive(arg1) && arg1 ||
        objectp(arg2) && !query_once_interactive(arg2) && arg2 ||
        objectp(arg3) && !query_once_interactive(arg3) && arg3 ||
        objectp(arg4) && !query_once_interactive(arg4) && arg4 ||
        objectp(arg5) && !query_once_interactive(arg5) && arg5);
  func = (closurep(arg1) && arg1 ||
          closurep(arg2) && arg2 ||
          closurep(arg3) && arg3 ||
          closurep(arg4) && arg4 ||
          closurep(arg5) && arg5);
  if (!ob) ob = ME;
  if (!ob || (object_name(ob)==MYFILE)) ob = previous_object();
  if (!func&&ob)
    func = (stringp(arg1) && function_exists(arg1,ob) && arg1 ||
            stringp(arg2) && function_exists(arg2,ob) && arg2 ||
            stringp(arg3) && function_exists(arg3,ob) && arg3 ||
            stringp(arg4) && function_exists(arg4,ob) && arg4 ||
            stringp(arg5) && function_exists(arg5,ob) && arg5);
  if (!func) func = "input_done";
  pl = (objectp(arg1) && query_once_interactive(arg1) && arg1 ||
        objectp(arg2) && query_once_interactive(arg2) && arg2 ||
        objectp(arg3) && query_once_interactive(arg3) && arg3 ||
        objectp(arg4) && query_once_interactive(arg4) && arg4 ||
        objectp(arg5) && query_once_interactive(arg5) && arg5);
  if (!pl) pl = TP;
  text = (stringp(arg1) && !stringp(func) && arg1 ||
          stringp(arg2) && arg2 ||
          stringp(arg3) && arg3 ||
          stringp(arg4) && arg4 ||
          stringp(arg5) && arg5);
  args = (pointerp(arg1) && arg1 ||
          pointerp(arg2) && arg2 ||
          pointerp(arg3) && arg3 ||
          pointerp(arg4) && arg4 ||
          pointerp(arg5) && arg5)|| ({});
  line = sizeof(message = text?explode(text,"\n"):({}));
  if (line&&message[<1]=="")
    {
      message = message[0..<2];
      line--;
    }
  if (!pl) return 0;
  if (!ob)
    {
      tell_object(pl,"Sorry, an error occured. Tell it to a wizard.\n");
      return;
    }
  if (stringp(func)) func = symbol_function(func,ob);
  tell_object(pl,"End input with '.' or '**'. Type '~h' for help.\n");
  tell_object(pl,to_string(line+1)+".]");
  input_to("input_loop",0,pl,func,message,line,args);
}

/***************************************************************************/
