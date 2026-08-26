/*
 * Original by Ember.
 * Improved version by Pinkfish.
 * Debugged by Deutha.
 */

#include <nroff.h>

#define ROWS ( (int)this_player()->query_rows() - 1 )
#define COLS (int)this_player()->query_cols()

private nosave int fsize, topl, botl, charl, real_rows, search_flag;
private nosave mixed mark_data;
private nosave string fname,
              *mark_name,
              *filenames,
              finish_func,
              stat_line,
              last_search;

private void display_file() {
   int i, ncols, nrows;
   string file, *bits, *lines;
   ncols = COLS;
   nrows = ROWS;
   file = read_file( fname, topl, nrows );
   if ( !file )
      return;
   file = replace( file, ({ "\t", "<TAB>", sprintf( "%c", 13 ), "\\n" }) );

   /* We add the extra character and then remove it from the resulting
    * array because this won't work on totally blank lines. :( */
   bits = explode( "x\n" + file, "\n" )[1 .. ];
   if ( charl )
      bits[ 0 ] = bits[ 0 ][ charl .. strlen( bits[ 0 ] ) - 1 ];
   real_rows = 0;
   lines = ({ });
   for ( i = 0; i < sizeof( bits ); i++ ) {
      if ( strlen( bits[ i ] ) > ncols ) {
         lines += ({ bits[ i ][ 0 .. ncols - 1 ] });
         bits[ i ] = bits[ i ][ ncols .. strlen( bits[ i ] ) - 1 ];
         charl += ncols;
         i--;
      } else {
         lines += ({ bits[ i ] });
         charl = 0;
         real_rows++;
      }
      if ( sizeof( lines ) == nrows )
         break;
   }
   printf( "%s\n", implode( lines, "\n" ) );
   botl = topl + real_rows - 1;
   if ( botl > fsize )
      botl = fsize;
} /* display_file() */

private void get_next_filename() {
  string str;

  fname = filenames[0];
  fsize = file_length( fname );
  if( !file_size( fname ) ) {
    printf( "Empty file.\n" );
    if(sizeof(filenames) > 1) {
      filenames = filenames[1..sizeof(filenames) - 1];
      get_next_filename();
      return;
    }
    else
      return;
  }
  if (fsize == -1) {
    printf( "File does not exist.\n" );
    if(sizeof(filenames) > 1) {
      filenames = filenames[1..sizeof(filenames) - 1];
      get_next_filename();
      return;
    }
    else
      return;
  }
  if (fsize == -2) {
    printf( "You cannot more a directory.\n" );
    if(sizeof(filenames) > 1) {
      filenames = filenames[1..sizeof(filenames)-1];
      get_next_filename();
      return;
    }
    else
      return;
  }
  topl = 1;
  if(sizeof(filenames) > 1)
    filenames = filenames[1..sizeof(filenames) - 1];
  else
    filenames = ({ });
  printf( "\n" );
  str = read_file(fname, 1, 1);
  if(!str)
    return;

  if (str[0] == '.') {
    string s2;

/*
 * Nroff file...  do horrible things!  Turn into a mushroom!  Blow up
 * all the hairy crater eating womble doovalacies...
 * In the case of a nroff file we push the file through nroff then shove it
 * through more_string...
 */
    str = "/tmp/nroffed_file";
    if (NROFF_HAND->create_nroff(fname, "/tmp/nroffed_file")) {
      s2 = NROFF_HAND->cat_file("/tmp/nroffed_file");
      rm("/tmp/nroffed_file.o");
      if (s2) {
        this_player()->more_string(s2, fname);
        fsize = ROWS-3;
        return ;
      }
    }
  }
  display_file();
} /* get_next_file_name() */

private string *expand_path(string s) {
  string *s1;

  s1 = (string *)this_player()->get_files(s);
  if (!s1)
    return ({ s });
  return s1;
} /* expand_path() */

int set_mark(string s) {
   int i;

   if (!mark_name) {
      mark_name = ({ });
      mark_data = ({ });
   }
   if ((i=member_array(s,mark_name))!=-1)
      mark_data[i] = ({ fname, topl });
   else {
      mark_name += ({ s });
      mark_data += ({ ({ fname, topl }) });
   }
   return 1;
} /* set_mark() */

private void status_line() {
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
         s += fname+frog[i][1..1000];
         break;
       case 'T' :
         s += topl+frog[i][1..1000];
         break;
       case 'B' :
         if (botl > fsize)
            s += fsize+frog[i][1..100];
         else
            s += botl+frog[i][1..100];
         break;
       case '%' : {
          percentage = (botl*100)/fsize;
          if(percentage > 100) percentage = 100;
          s += percentage+frog[i][1..100];
          break;
       }
       case 'S' :
         s += fsize+frog[i][1..1000];
         break;
      }
   }
   printf( "%s", s );
   return;
   printf( fname +" From "+ topl +" to "+ botl +" of "+ fsize +" ("+
          ( ( botl * 100 ) / fsize ) +"%) - h for help. " );
} /* status_line() */

void next_page(string str) {
   int num, noargs, i, j, k, redraw;
   string s1, *s3;

   if (!str)
      str = "";

   if (sscanf(str,"%d%s", num, str)!=2)
      noargs = 1;
   s1 = extract(str,1);
   /* case statements WEEEEEE */
   switch(str[0..0]) {
    case "" :
    case " " :
      topl += real_rows;
      redraw = 1;
      break;
    case "f" :
      /* go on a number of pages... */
      if (noargs)
         num = 1;
      topl += ROWS * num;
      redraw = 1;
      break;
    case "q" :
      printf( "Ok.\n" );
      return ;
    case "/" :
      /* sigh */
      search_flag = 0;
      j = topl+4;
      if (s1[0] == '!') {
         search_flag = 1;
         s1 = extract(s1,1);
      }
      set_mark("'");
      if (s1=="" || !s1)
         s1 = last_search;
      if (s1 == "") {
         printf( "No previous search string.\n" );
         break;
      }
      do {
         i = j;
         j = i+900;
         if (j>fsize)
            j = fsize;
         s3 = explode(read_file(fname,i,j),"\n");
         for (k=0;k<sizeof(s3);k++)
            if (!search_flag) {
               if (sscanf(s3[k],"%*s"+s1+"%*s")==2)
                  if (num--<=0)
                     break;
            } else
            if (sscanf(s3[k],"%*s"+s1+"%*s")!=2)
               if (num--<=0)
                  break;
      } while (j<fsize && k == sizeof(s3));
      if (k==sizeof(s3))
         printf( "Sorry "+ s1 +" not found.\n" );
      else {
         topl = i+k-3;
         redraw = 1;
      }
      last_search = s1;
      break;
    case "?" :
      i = topl;
      if (s1[0] == '!') {
         s1 = extract(s1,1);
         search_flag = 3;
      } else
         search_flag = 2;
      set_mark("'");
      if (s1=="" || !s1)
         s1 = last_search;
      if (s1 == "") {
         printf( "No previous search string.\n" );
         break;
      }
      do {
         j = i-900;
         if (j<0)
            j = 0;
         s3 = explode(read_file(fname,j,i),"\n");
         for (k=0;k<sizeof(s3);k++)
            if (search_flag == 2) {
               if (sscanf(s3[k],"%*s"+s1+"%*s")==2)
                  if (num--<=0)
                     break;
            } else
            if (sscanf(s3[k],"%*s"+s1+"%*s")!=2)
               if (num--<=0)
                  break;
         i = j;
      } while (j>0 && k == sizeof(s3));
      if (k==sizeof(s3))
         printf( "Sorry "+ s1 +" not found.\n" );
      else {
         topl = k+i-2;
         redraw = 1;
      }
      last_search = s1;
      break;
    case "n" :
      switch (search_flag) {
       case 0 : next_page(num+"/");
         break;
       case 1 : next_page(num+"/!");
         break;
       case 2 : next_page(num+"?");
         break;
       case 3 : next_page(num+"?!");
         break;
      }
      return;
    case "b" :
      if (noargs)
         num = 1;
      if (topl>0) {
         topl -= ROWS * num;
         redraw = 1;
         if (topl<0)
            topl = 0;
      }
      break;
    case "G" :
      if (noargs)
         num = fsize-ROWS+1;
    case "g" :
      set_mark("'");
      topl = num;
      if (topl>=fsize)
         topl = fsize-2;
      redraw = 1;
      break;
    case "P" :
      if (noargs)
         num = 100;
    case "p" :
    case "%" :
      redraw = 1;
      set_mark("'");
      topl = (num*fsize)/100;
      if (topl+ROWS-1>fsize)
         topl -= ROWS-1;
      break;
    case "d" :
      if (noargs)
         num = ROWS/2;
      topl += num;
      redraw = 1;
      break;
    case "u" :
      if (noargs)
         num = ROWS/2;
      topl -= num;
      redraw = 1;
      break;
    case "r" :
      redraw = 1;
      break;
    case "m" :
      if (s1=="") {
         printf( "Sorry, you must specify a name.\n" );
         break;
      }
      set_mark(s1);
      printf( "Okay, mark "+ s1 +" set.\n" );
      break;
    case "'" :
      if (!mark_name) {
         printf( "Sorry, must go to a mark.\n" );
         break;
      }
      if ((i=member_array(s1,mark_name))!=-1) {
         if (fname != mark_data[i][0]) {
            fname = mark_data[i][0];
            redraw = 1;
         }
         if (topl != mark_data[i][1]) {
            topl = mark_data[i][1];
            redraw = 1;
         }
      } else
         printf( "Mark "+ s1 +" not set.\n" );
      break;
    case "F" :
      filenames = expand_path(str);
      if (!sizeof(filenames)) {
         printf( "No matching files.\n" );
         break;
      }
      last_search = "";
      get_next_filename();
      redraw = 1;
      break;
    case "h" :
      cat("/doc/helpdir/more");
      break;
   }
   if (redraw)
      display_file();
   if ( ( botl < fsize ) || charl ) {
      status_line();
      input_to( "next_page" );
   } else
      if(sizeof(filenames)) {
         get_next_filename();
         input_to("next_page");
      } else {
         if (finish_func)
            call_other(this_player(), finish_func);
      }
} /* next_page() */

int more_file(string str) {
   filenames = expand_path(str);
   if (!sizeof(filenames)) {
      notify_fail("No matching files.\n");
      return 0;
   }
   last_search = "";
   get_next_filename();
   if ( ( botl < fsize ) || charl ) {
      status_line();
      input_to( "next_page" );
   } else
      if (finish_func)
         call_other(this_player(), finish_func);
   return 1;
} /* more_file() */
