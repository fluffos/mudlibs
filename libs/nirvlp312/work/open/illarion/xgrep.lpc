/* grep
 * 
 * Illarion Nov 2004
 *
 * modified from code by Earwax 1/16/04
 *
 * Reads through the file in smaller pieces, which avoids running
 * into the limits on the string variable in larger files
 *
 * Searching directories or groups of files may be supported later
 *
*/

#define PAGE_SIZE 300 /* How many lines of a file to read at once */

string *results; /* All results found searching file */
string pattern;  /* regexp to search for */
string filename; /* filename being searched */
int iterations;  /* Number of times do_grep has called itself recursively */
int start;       /* Where to start in the file on the next call of do_grep */
int last_size;   /* Used to estimate the number of lines in a file */

/* prototype */
void do_grep();

/* Function name: cmd_grep
 * Description: checks for file existence and initializes variables
 * Arguments: file to be searched
 * Returns: 0 for incorrect syntax, 1 otherwise
 */

int cmd_grep(string arg) {

  if (!arg || sscanf(arg, "%s %s", pattern, filename) != 2)
  {
    notify_fail("See 'wizhelp grep' for help on using grep.\nSyntax: grep <pattern> <filename>\n");
    return 0;
  }

  filename=resolv_path((string)this_player()->get_path(),filename);
    
  if(file_size(filename) < 1) {
    write("File does not exist, or is unreadable.\n");
    return 1;
  }
  results=({});
  start=1;
  do_grep();
  return 1;
}
/* Function name: do_grep
 * Description: calls itself recursively to search for the regexp
 specified in cmd_grep.  If performance problems arise, input_to
 can be used to require the user send a return to continue searching
 * Arguments: none
 * Returns: void
 */

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
    write("Filesize: "+file_size(filename)+" bytes (approximately "+(start-PAGE_SIZE+last_size)+" lines)\n");
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
    int extra_line;
    i=0;
    while(filetext[i..i++]=="\n") /* corrects an issue with explode */
      extra_line++;
    for(i=0; i< siz; i++) {
      int lnum;
      lnum= member_array(matches[i],lines);
      matches[i]=pad(""+(lnum+start+extra_line),-5)+": "+matches[i];
      lines[lnum]="";
    }
  }
  last_size=sizeof(lines)+extra_line;
  results+=matches;
  iterations++;
  start+=PAGE_SIZE;
  do_grep();
}
