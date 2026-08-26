/**
 * An nroff like object for formating text files.
 *<p>
 * This creates a saveable file format thingy.
 *
 * @author Pinkfish
 */
#include <nroff.h>

mixed *nroffed_file;
string nroffed_file_name;
int modified_time;
nosave int new_string;
nosave int force_string;

void create() {
  nroffed_file = ({ });
  seteuid("Root"); /* Security risk?  nahhhhh */
} /* create() */

#define do_bounds(bing) (bing<0?bing+cols:bing)

/**
 * Creates a string from a nroffed file.
 * <p>
 * If update is non zero it will look to see if the source file has been 
 * modified since the saved nroff file was created.  If it has, this
 * function returns 0 and the nroff file needs to be recreated.
 *
 * @param fname the file to process
 * @param update force update if file is newer?
 * @return the string representation of the nroff file
 */
string cat_file(string fname, int update) {
   int i, cols;
   string ret;
   
   if (!master()->valid_read(fname, geteuid(previous_object()),
                             "restore_object")) {
      return 0;
   }
   nroffed_file_name = 0;
   modified_time = 0;
   if (!restore_object(fname))
      return 0;
   if (!nroffed_file_name && update)
      return 0;
   if (update) {
      mixed *something;
      
      if (!master()->valid_read(nroffed_file_name,
                                geteuid(previous_object()),
                                "restore_object"))
         return 0;
      if (file_size(nroffed_file_name) <= 0)
         return 0;
      something = stat(nroffed_file_name);
      if (something[1] > modified_time)
         return 0;
   }
   ret = "";
   if (this_player()) {
      cols = (int)this_player()->query_cols() - 1;
   } else {
      cols = 79;
   }
   for (i=0;i<sizeof(nroffed_file);i++) {
      if (stringp(nroffed_file[i])) {
         ret += nroffed_file[i];
      } else {     
         switch (nroffed_file[i]) {
          case V_HEADER :
            ret += sprintf("%%^BOLD%%^%s%%^RESET%%^\n", nroffed_file[i+1]);
            i++;
            break;
          case V_CENTER :
            ret += sprintf("%|=*s", cols, nroffed_file[i+1]);
            i++;
            break;
          case V_ALL :
            ret += sprintf("%-*s%|*s%*s\n", nroffed_file[i+1],
                           nroffed_file[i+2],
                           cols - nroffed_file[i+1]*2,
                           nroffed_file[i+3],
                           nroffed_file[i+1],
                           nroffed_file[i+4]);
            i += 4;
            break;
          case V_INDENT :
            ret += sprintf( "%*=s%-=*s", nroffed_file[ i + 1 ], "",
                           cols - nroffed_file[ i + 1 ], nroffed_file[ i + 2 ] );
            i += 2;
            break;
          case V_PARA :
            if (nroffed_file[i+1])
            ret += sprintf("%*=s%-=*s%=*s\n", nroffed_file[i+1], "",
                           cols-nroffed_file[i+1]-
                           nroffed_file[i+2], nroffed_file[i+3],
                           nroffed_file[i+2], "");
            else if (nroffed_file[i+2])
            ret += sprintf("%-=*s%=*s\n", cols-nroffed_file[i+2],
                           nroffed_file[i+3],
                           nroffed_file[i+2], "");
            else
            ret += sprintf("%-=*s\n", cols, nroffed_file[i+3]);
            i += 3;
            break;
          case V_LEFT :
            ret += sprintf("%-=*s", cols, nroffed_file[i+1]);
            i++;
            break;
          case V_TABLE :
            ret += sprintf("%-#*s", cols, nroffed_file[i+1]);
            i++;
            break;
          case V_COLUMN : {
             int j;
             
             switch (sizeof(nroffed_file[i+1])) {
              case 2 :
                for (j=0;j<sizeof(nroffed_file[i+2]);j++)
                ret += sprintf("%*-=s%*-=s\n", do_bounds(nroffed_file[i+1][0]),
                               nroffed_file[i+2][j],
                               do_bounds(nroffed_file[i+1][1]),
                               nroffed_file[i+3][j]);
                i += 3;
                break;
              case 3 :
                for (j=0;j<sizeof(nroffed_file[i+2]);j++)
                ret += sprintf("%*-=s%*-=s%*-=s\n",
                               do_bounds(nroffed_file[i+1][0]),
                               nroffed_file[i+2][j],
                               do_bounds(nroffed_file[i+1][1]),
                               nroffed_file[i+3][j],
                               do_bounds(nroffed_file[i+1][2]),
                               nroffed_file[i+4][j]);
                i += 4;
                break;
             }
             break;
          }
         }
      }
   }
   return " \n"+ret;
} /* cat_file() */

/**
 * @ignore yes
 */
private string htmlify(string  str) {
  return replace(str, ({ "&", "&amp;", "<", "&lt;", ">", "&gt;"}));
} /* htmlify() */

/**
 * Turns the nroff file into a html output.  This works on nroff files
 * creating a html output from the mud source.
 *
 * @param file the name to process
 * @param title the title to give the document
 * @return the html file
 */
string html_file(string file, string title) {
   int i, j, cols, in_bold, in_italic;
   string ret, *bits;
   
   if (!master()->valid_read(file, geteuid(previous_object()),
                             "restore_object"))
      return 0;
   nroffed_file_name = 0;
   modified_time = 0;
   if (!restore_object(file))
      return 0;
   ret = "";
   cols = 78;

   for (i=0;i<sizeof(nroffed_file);i++)
     if (stringp(nroffed_file[i]))
       nroffed_file[i] = htmlify(nroffed_file[i]);
     else if(arrayp(nroffed_file[i])) {
       for (j=0;j<sizeof(nroffed_file[i]);j++)
         if(stringp(nroffed_file[i][j]))
           nroffed_file[i][j] = htmlify(nroffed_file[i][j]);
     }           

   
   for (i=0;i<sizeof(nroffed_file);i++) {
      if (stringp(nroffed_file[i])) {
         ret += "<h2>"+nroffed_file[i]+"</h2>";

#ifdef UNUSED         
         if(strsrch(nroffed_file[i], "See also") > -1) {
           for(j=i+1; j < sizeof(nroffed_file); j++) {
             if(stringp(nroffed_file[j])) {
               nroffed_file[j] = make_links(nroffed_file[j]);
             }
           }
         }
#endif         
      } else {
         switch (nroffed_file[i]) {
          case V_HEADER :
            ret += "<h2>"+replace_string(nroffed_file[i+1], "\n", "<br>")+
              "</h2>";
            i++;
            break;
          case V_CENTER :
            ret += "<center>"+replace(nroffed_file[i+1], "\n", "<br>")+
            "</center>";
            i++;
            break;
          case V_ALL :
            i += 4;
            break;
          case V_INDENT :
            ret += replace(nroffed_file[i+2], ({"<", "&lt;", ">",
               "&gt;", "\n", "<br>"}));
            i += 2;
            break;
          case V_PARA :
            ret += replace(nroffed_file[i+3], "\n", "<p>");
            i += 3;
            break;
          case V_LEFT :
            ret += "<left>"+nroffed_file[i+1]+"</left>";
            i++;
            break;
          case V_TABLE :
            ret += "<ul><li>"+replace(nroffed_file[i+1], "\n", "<li>")+"</ul>";
            i++;
            break;
          case V_COLUMN : {
             ret += "<table cellpadding=10>";
             switch (sizeof(nroffed_file[i+1])) {
              case 2 :
                for (j=0;j<sizeof(nroffed_file[i+2]);j++) {
                  ret += "<tr>\n";
                  ret += "<td nowrap>"+nroffed_file[i+2][j] + "</td>";
                  ret += "<td>"+nroffed_file[i+3][j] + "</td>";
                  ret += "</tr>";
                }
                i += 3;
                break;
              case 3 :
                for (j=0;j<sizeof(nroffed_file[i+2]);j++) {
                  ret += "<tr>\n";
                  ret += "<td nowrap>"+nroffed_file[i+2][j] + "</td>";
                  ret += "<td nowrap>"+nroffed_file[i+3][j] + "</td>";
                  ret += "<td>"+nroffed_file[i+4][j] + "</td>";
                  ret += "</tr>";
                }
                i += 4;
                break;
             }
             ret += "</table>";
             break;
          }
         }
      }
   }
   
   bits = explode(ret, "%^");
   ret = "";
   for (i=0;i<sizeof(bits);i+=2) {
      ret += bits[i];
    if (i+1 < sizeof(bits)) {
       switch (bits[i+1]) {
        case "BOLD" :
          if (!in_bold)
             ret += "<strong>";
          else
             ret += "</strong>";
          in_bold = !in_bold;
          break;
        case "RESET" :
          if (in_bold)
             ret += "</strong>";
          if (in_italic)
             ret += "</i>";
          in_bold = 0;
          in_italic = 0;
          break;
        default :
          if (!in_italic)
             ret += "<i>";
          else
             ret += "</i>";
          in_italic = !in_italic;
          break;
       }
    }
   }
   return ret;
} /* html_file() */

private void add_array(mixed *i) {
  if (!sizeof(nroffed_file))
    nroffed_file += ({ i });
  else if (force_string)
    nroffed_file += ({ "", i });
  else
    nroffed_file += ({ i });
  force_string = 0;
  new_string = 0;
} /* add_array() */

private void add_int(int i) {
  if (!sizeof(nroffed_file))
    nroffed_file += ({ i });
  else if (force_string)
    nroffed_file += ({ "", i });
  else
    nroffed_file += ({ i });
  force_string = 0;
  new_string = 0;
} /* add_int() */

private void add_string(string s) {
  if (!sizeof(nroffed_file) || new_string)
    nroffed_file += ({ s });
  else if (stringp(nroffed_file[<1]))
    nroffed_file[<1] += s;
  else
    nroffed_file += ({ s });
  new_string = 0;
  force_string = 0;
} /* add_string() */

/**
 * Makes the nroff saveable file.  Turns the input nroff file into a saved
 * output format.
 *
 * @param in_file the file name been processed
 * @param out_file the file to save it as
 * @return 1 if the operation was successful
 */
int create_nroff(string in_file, string out_file) {
  string text,
         tmp,
         *bits;
  string *bing;
  mixed  *cols;
  int strip_crs,
      col_mode,
      conv_tabs,
      i, j, k, fluff,
      num_cols;

  if (!master()->valid_read(in_file, geteuid(previous_object()),
                            "read_file"))
    return 0;
/*  if (!"/secure/master"->valid_write(out_file, geteuid(previous_object()),
                                    "save_object"))
    return 0; */
  nroffed_file_name = in_file;
  modified_time = time();
  text = read_file(in_file);
  if (!text)
    return 0;
    text = replace(text,"$MUDNAME$",mud_name());
  bits = explode("#\n"+text, "\n.");
  bits[0] = bits[0][1..];
  nroffed_file = ({ 0 });
  if (strlen(bits[0]))
    add_string(bits[0]);
  for (i=1;i<sizeof(bits);i++) {
/*
    if (!strlen(bits[i])) {
      if (col_mode) {
        for (j=0;j<num_cols;j++)
          cols[j] += "\n";
      } else if (strip_crs)
        add_string("\n\n");
      else
        add_string("\n");
    } else if (bits[i][0] == '.') {
 */
     if (sscanf(bits[i], "%s\n%s", tmp, bits[i]) != 2) {
        tmp = bits[i];
        bits[i] = "";
        fluff = 1;
     } else
        fluff = 0;
     switch (tmp[0..1]) {
      case "SH" : /* Section header */
        add_int(V_HEADER);
        add_string(tmp[3..]);
        new_string = 1;
        break;
      case "SI" : /* Start indent */
        add_int(V_INDENT);
        j = 0;
        sscanf(tmp[2..], "%d%s", j, tmp);
        add_int(j);
        force_string = 1;
        break;
      case "EI" : /* End indent */
        add_string("");
        new_string = 1;
        break;
      case "SP" : /* Start paragraph */
        add_int(V_PARA);
        j = 0;
        sscanf(tmp[2..], "%d%s", j, tmp);
        add_int(j);
        j = 0;
        sscanf(tmp, " %d%s", j, tmp);
        add_int(j);
        force_string = 1;
        strip_crs = 1;
        break;
      case "EP" : /* End paragraph */
        add_string("");
        new_string = 1;
        strip_crs = 0;
        break;
      case "SC" : /* start centering */
        add_int(V_CENTER);
        force_string = 1;
        break;
      case "EC" : /* End centering */
        new_string = 1;
        break;
      case "SL" : /* Start left justify */
        add_int(V_LEFT);
        force_string = 1;
        break;
      case "EL " : /* End left justify */
        new_string = 1;
        break;
      case "ST" : /* Start table mode (Turn tabs into new lines) */
        add_int(V_TABLE);
        force_string = 1;
        conv_tabs = 1;
        break;
      case "ET" : /* End table mode */
        new_string = 1;
        conv_tabs = 0;
        break;
      case "DT" : /* Do title.  Take the next three lines... */
        bing = explode(bits[i], "\n");
        if (sizeof(bing) < 3) {
           if (creatorp(TP)) {
              tell_object(this_player(), "Text file "+in_file+
                          " did not have enough lines after the .DT directive.\n");
              tell_object(this_player(), sprintf("%O\n", bing));
           }
           return 0; /* failed! */
        }
        add_int(V_ALL);
        if (strlen(bing[0]) > strlen(bing[2]))
           add_int(strlen(bing[0]));
        else
           add_int(strlen(bing[2]));
        new_string = 1;
        add_string("%^BOLD%^" + bing[0]);
        new_string = 1;
        add_string(bing[1]);
        new_string = 1;
        add_string(bing[2] + "%^RESET%^");
        new_string = 1;
        bits[i] = implode(bing[3..], "\n");
        break;
      case "SO" : /* starts column mode. The numbers after it
                   * are column size */
        num_cols = 0;
        tmp = tmp[2..];
        cols = ({ });
        while (sscanf(tmp, "%d%s", j, tmp) == 2) {
           cols += ({ j });
           num_cols++;
           while (strlen(tmp) && tmp[0] == ' ')
           tmp = tmp[1..];
        }
        add_int(V_COLUMN);
        if (sscanf(tmp, "%d", j) == 1) {
           cols += ({ j });
           num_cols++;
        }
        add_array(cols);
        cols = allocate(num_cols);
        for (j=0;j<num_cols;j++) cols[j] = ({ });
        col_mode = 1;
        break;
      case "EO" : /* End column mode */
        for (j=0;j<num_cols;j++) {
           add_array(cols[j]);
        }
        col_mode = 0;
        break;
      case "NF" : /* New File.  Take the next line and ignore everything
                   * else in the file */
        bing = explode(bits[i], "\n");
        if (sizeof(bing) < 1) {
           if (creatorp(TP)) {
              tell_object(this_player(), "Text file "+in_file+
                          " did not have enough lines after the .NF directive.\n");
              tell_object(this_player(), sprintf("%O\n", bing));
           }
           return 0; /* failed! */
        }
        /* read the new file and start again, but keep the old name */
        text = read_file(bing[ 0 ]);
        if (!text)
          return 0;
        bits = explode("#\n"+text, "\n.");
        bits[0] = bits[0][1..];
        nroffed_file = ({ 0 });
        if (strlen(bits[0]))
           add_string(bits[0]);
        strip_crs = col_mode = conv_tabs = fluff = num_cols = i = 0;
        break;
     }
     if (fluff) continue;
     if (conv_tabs)
        bits[i] = replace(bits[i], "\t", "\n");
     if (col_mode) {
        string *frog;
        
        frog = explode(bits[i], "\n");
        for (k=0;k<sizeof(frog);k++) {
           bing = explode("#"+frog[k], "\t");
           bing[0] = bing[0][1..];
           for (j=0;j<num_cols && j < sizeof(bing);j++)
              cols[j] += ({ bing[j] });
           for (j=sizeof(bing);j<num_cols;j++)
              cols[j] += ({ "\n" });
        }
     } else if (strip_crs) {
        bits[i] = replace_string(bits[i], "\n\n", "$%^NeW_LiNe^%$");
        bits[i] = replace_string(bits[i], ".\n", ".  ");
        bits[i] = replace_string(bits[i], "\n", " ");
        bits[i] = replace_string(bits[i], "$%^NeW_LiNe^%$", "\n\n");
        add_string(bits[i]+" ");
     } else
        add_string(bits[i]+"\n");
     /*
      }
      */
  }
  new_string = 0;
  force_string = 0;
  unguarded((: save_object, out_file :));
  return 1;
} /* create_nroff() */

/*
void create_help(string path, string file) {
  if (path[0..4] == "/doc/")
    this_object()->create_nroff(path+file, NROFF_DIR+file);
  else
    write("Invalid path. "+path+"\n");
}

void create_chelp(string path, string file) {
  if (path[0..4] == "/doc/")
    this_object()->create_nroff(path+file, CNROFF_DIR+file);
  else
    write("Invalid path.\n");
}

void create_man(string path, string file) {
  if (path[0..4] == "/doc/")
    this_object()->create_nroff(path+file, MNROFF_DIR+file);
  else
    write("Invalid path.\n");
} */

/**
 * Will attempt to find the name of the nroffed file.  Will attempt to
 * find the name of the source file associated with the save file.
 *
 * @param fname the name of the file to check
 * @return the source file name or 0
 */
string query_file_name( string fname ) {
   if (!master()->valid_read(fname, geteuid(previous_object()),
                             "restore_object"))
      return 0;
   nroffed_file_name = 0;
   modified_time = 0;
   if (!restore_object(fname))
      return 0;
   return nroffed_file_name;
} /* query_file_name() */

