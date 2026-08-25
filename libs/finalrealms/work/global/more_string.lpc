/* (I think this was originally by Pinkfish)
   Mods by Hamlet, Aug 1997.
     * Fixed screen-size issues.
     * fixed odd bug with finish_func
     * removed annoying end-of-doc [more] thing.
     * Added quite a few commands.
     * Wrote /doc/more.help
*/
/* Notes:  Should probably change searches to regexp 
           Terrible hack in string_display_file() needs fixed...
              format now and send raw to player at the end, instead
              of double-formatting.
           Add a 'raw' variable that keeps system from converting colors.
              Convert more_file.c to inherit this to do the brunt of the
              work, probably.
*/

nosave int fsize,
    topl,
    used;
nosave string last_search, *the_bit, more_bit, stat_line;
nosave object finish_ob;
nosave mixed finish_func;

#define ROWS ((int)this_object()->query_rows() - 1)
#define COLS (int)this_object()->query_cols()

void call_finish_func(string str);

int string_display_file() {
  int botl, i, j, tmp;
  string out = "";
  int cols = COLS;

  botl = topl + ROWS;

  i = topl;
  
  tmp = sizeof(explode(sprintf("%-=*s", cols, the_bit[topl]), "\n")) - 1;

  if(tmp >= 0)
    j = tmp;

  while((i+j)<botl && i<fsize) {
    out += the_bit[i] + "\n";
 
    if((i+1) < fsize) {
      tmp = sizeof(explode(sprintf("%-=*s", cols, the_bit[i+1]), "\n")) - 1;  
                /* ^^^^ Extra lines it's gonna wrap. Terrible hack. */
      if(tmp > 0)
        j += tmp;
    }

    i++;
  }

  if(i == topl) { /* The first line is longer than a screen. */
    out += the_bit[i] + "\n";
    i++;
  }

  write(out);

  return (i - topl);
}

void more_string_status_line() {
  string *frog;
  string s;
  int i, percentage;

  if (!stat_line)
    stat_line = "$N From $T to $B of $S ($%%) - h for help. ";
  s = "";
  frog = explode(stat_line, "$");
  for (i=0;i<sizeof(frog);i++) {
    if (frog[i] == "") {
      s += "$";
      i ++;
    } else switch (frog[i][0]) {
      case 'N' :
          s += more_bit+frog[i][1..];
          break;
      case 'T' :
          s += (topl - used + 1)+frog[i][1..];
          break;
      case 'B' :
          if (topl > fsize)
            s += fsize+frog[i][1..];
          else
            s += topl+frog[i][1..];
          break;
      case '%' : {
          percentage = ((topl)*100)/fsize;
          if(percentage > 100) percentage = 100;
          s += percentage+frog[i][1..];
          break;
      }
      case 'S' :
         s += fsize+frog[i][1..];
         break;
    }
  }
  tell_object(this_object(), s);
  return;
}

void string_next_page(string str) {
  int num,
      noargs,
      i,
      redraw;
  string s1, s4, s5;

  if (!str)
    str = "";

  if (sscanf(str,"%d%s", num, str)!=2)
    noargs = 1;
  s1 = str[1..];
  str = str[0..0];
/* case statements WEEEEEE */
  switch(str) {
    case "" :
    case "f" :
               /* go on a number of pages... */
               if(!noargs)
                 topl += (ROWS * (num - 1));
               redraw = 1;
               break;
    case "b" :
               if(noargs)
                 num = 1;
               topl -= (ROWS * (num + 1)); 
               redraw = 1;
               break;
    case " " :
    case "z" :
               if(noargs)
                 num = 1;
               while(num--) {
                 write(the_bit[topl] + "\n");
                 topl++;
                 if(topl >= fsize)
                   break;
               }
               break;
    case "." :
               topl -= used;
               redraw = 1;
               break;
    case "s" : 
               topl += num;
               redraw = 1;
               break;
    case "q" :
    case "Q" : 
               call_finish_func(str);
               return;
    case "g" :
               topl = num;
               if(topl >= fsize)
                 topl = fsize - 2;
               redraw = 1;
               break;
    case "G" :
               redraw = 1;
               if (noargs)
                 topl = fsize - ROWS;
               else
                 topl = (fsize - num);
               break;
    case "/" :
               if (s1=="")
                 s1 = last_search;
               if (!s1 || s1 == "")
                 s1 = "bing!";
               last_search = s1;
               for (i=topl;i<fsize;i++)
                 if (sscanf(the_bit[i],"%s"+s1+"%s",s4,s5)==2)
                   if (num--<=0)
                     break;
               if (i==fsize)
                 write("Sorry "+s1+" not found.\n");
               else {
                 topl = i-3;
                 redraw = 1;
               }
               break;
    case "-" :
               if (s1=="")
                 s1 = last_search;
               if (!s1 || s1 == "")
                 s1 = "bing!";
               last_search = s1;
               for (i=(topl-ROWS);i>=0;i--)
                 if (sscanf(the_bit[i],"%s"+s1+"%s",s4,s5)==2)
                   if (num--<=0)
                     break;
               if (i<0)
                 write("Sorry "+s1+" not found.\n");
               else {
                 topl = i-3;
                 redraw = 1;
               }
               break;
    case "?" :
    case "h" :
               if(file_size("/doc/more.help") > 0)
                 tell_object(this_object(), read_file("/doc/more.help"));
               else
                 tell_object(this_object(), 
                             "The help document (/doc/more.help) "
                             "is missing.  Get someone to fix it.\n");
               break;
  }

  if(topl < 0)
    topl = 0;
  else if(topl >= fsize)
    topl = fsize - ROWS;

  if (redraw) {
    used = string_display_file();
    topl += used; 
  }

  if (topl<fsize) {
    more_string_status_line();
    input_to("string_next_page");
  } else
    call_finish_func(0);
}

varargs int more_string(mixed str, string bity, string more_fmt) {
  if (bity)
    more_bit = bity;
  else
    more_bit = "--- MORE";
  last_search = "";
 
  if(more_fmt)
    stat_line = more_fmt;
  else
    stat_line = 0;

  if (!pointerp(str)) 
    the_bit = explode(str,"\n");
  fsize = sizeof(the_bit);
  if (fsize == 0) {
    notify_fail("Empty String.\n");
    return 0;
  }
  topl = 0;
  used = string_display_file();
  topl += used;
  if (topl < fsize) {
    more_string_status_line();
    input_to("string_next_page");
  } else 
    call_finish_func(0);

  return 1;
}

int set_finish_func(mixed str, object ob) {
  finish_func = str;
  if (!functionp(str) && !ob)
    finish_ob = previous_object();
  else
    finish_ob = ob;
}

void call_finish_func(string str) {
  mixed f_func;

  if (finish_func) {
    f_func = finish_func;
    finish_func = 0;
    if(functionp(f_func))
// This will have to wait.  requires modifications of mailer.
//      evaluate(f_func, str);
      evaluate(f_func);
    else
//      call_other(finish_ob, f_func, str);
      call_other(finish_ob, f_func);
  }
}
