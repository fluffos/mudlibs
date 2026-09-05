/* grep
 * 
 * Illarion Nov 2004
 *
 * modified from code by Earwax 1/16/04
 *
 * Reads through the file in smaller pieces, which avoids running
 * into the limits on the string variable in larger files
 *
*/

#define PAGE_SIZE 300

string *results;
string pattern;
string filename;
int iterations;
int start;

void do_grep();

id(str) {
  return str=="grep_ob";
}

int cmd_grep(string arg) {

  if (!arg || sscanf(arg, "%s %s", pattern, filename) != 2)
  {
    notify_fail("See 'wizhelp grep' for help on using grep.\nSyntax: grep <pattern> <filename>\n");
    return 0;
  }

  if (sscanf(filename, "/%s", filename) == 1)
    filename = resolv_path("/"+filename);
  else
    filename = resolv_path((string)this_player()->query_pwd() + filename);
    
  if(file_size(filename) < 1) {
    write("File does not exist, or is unreadable.\n");
    return 1;
  }
  results=({});
  start=1;
  do_grep();
  return 1;
}

void do_grep() {
  int i,siz;
  string filetext;
  string *lines,*matches;

  filetext = read_file(filename, start, PAGE_SIZE);
  if (!filetext) {
    siz=sizeof(results);
    if(!siz) {
      write("No Matches found for: "+pattern+"\n");
      return;
    }
    siz = sizeof(results);
    write("Searching "+filename+" for \""+pattern+"\" returned "+siz+" matches.\n");
  
    for (i = 0; i < siz; i++)
      write(results[i]+"\n");
    write("Filesize: "+file_size(filename)+" bytes\n");
    return;
    
    
  }
  lines = explode(filetext, "\n");
  if (!sizeof(lines))
  {
    write("Could not explode file: "+filename+"\n");
    return;
  }

  matches = regexp(lines, pattern);
  /* Add the line number to the matches found.
     setting the line to an empty string afterward ensures it won't be matched again */
  if(matches && (siz=sizeof(matches))) {
    status extra_line;
    if(filetext[0..0]=="\n") /* corrects an issue with explode */
      extra_line=1;
    else
      extra_line=0;

    for(i=0; i< siz; i++) {
      int lnum;
      lnum= member_array(matches[i],lines);
      matches[i]=pad(""+(lnum+start+extra_line),-5)+": "+matches[i];
      lines[lnum]="";
    }
  }
  results+=matches;
  iterations++;
  start+=PAGE_SIZE;
  do_grep();
}
