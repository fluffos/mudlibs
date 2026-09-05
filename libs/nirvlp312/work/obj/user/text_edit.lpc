/*
 *      File:             text_edit.c  
 *      Function:         general purpose text editor
 *      Author(s):        Illarion@Nirvana
 *      Created:          12 dec 2004
 *      Notes:            intended for use by bulletin boards, the mailwriter,
 *                        etc.
 *                        call the start_edit function using the arguments
 *                        listed in its description
 *                        a copy should be cloned- if one is not cloned, this
 *                        object will clone a copy automatically
 *      Change History:
 */

#include "/players/illarion/dfns.h"

object report_ob;
string report_str;
string *message;
int max_length;
int format_warning;

void line_prompt();
void show_text();

/* 
 * Function name: start_edit
 * Description: starts the editing process
 * Arguments:
 ob -   object to report to when done
 str -  function to call in that object
 max -  max number of lines (0 for unlimited)
 curr - (string) the message to start with (0 for none)
 * Returns: void
 */

void start_edit(object ob, string str, int max, string curr) {
  int s;
  if(!ob || !str) return;
  if(root()) {
    object bob;
    bob=clone_object(object_name(this_object()));
    bob->start_edit(ob,str,max,curr);
    return;
  }
  report_ob=ob;
  report_str=str;
  max_length=max;
  write("You have entered the text editor.  Enter ~h on a blank line for help.\n");
  if(curr) {
    message=explode(curr,"\n");
    s=sizeof(message);
    while(s--)
#ifndef __LDMUD__ /* Rumplemintz */
      if(message[s][-1..-1]!=" ") 
#else
      if (message[s][<1..<1] != " ")
#endif
        message[s]+=" ";
    show_text();
  } else
    message=({});
  line_prompt();
  input_to("enter_text");
}

/* Function name: show_help
 * Description: shows the various editor commands
 * Arguments: none
 * Returns: void
 */

void show_help() {
  write("The following text editor commands are available:\n"
       +"~h          This help listing\n"
       +"~s          Save your entry and stop editing (** also works)\n"
       +"~q          Stop editing without saving\n"
       +"~l          List your entered text so far\n"
       +"~f          Format your text\n"
       +"~c          Clear the whole thing and start over\n"
       +"~dl #       Delete the specified line of text\n"
       +"~rl # <new> Replace the specified line of text\n"
       +"~il # <new> Insert a new line before the specified line\n"
       );
  if(max_length)
    write("You are limited to "+max_length+" lines for this entry.\n");
}

/* Function name: line_prompt
 * Description: prints out a prompt displaying the current line number
 * Arguments: none
 * Returns: void
 */
void line_prompt() {
  write(pad(""+(1+sizeof(message)),2)+"]");
}

/* Function name: end_edit
 * Description: stop editing and contact the parent object with the result
 * Arguments: 1 to report the current text if any, 0 to report no text;
 * Returns: void
 */
 
void end_edit(status save) {
  string final;
  int x,siz;
  siz=sizeof(message);
  if(save && max_length && siz > max_length) {
    write("You are limited to "+max_length+" lines.   You must either delete\n"+
          "some lines(~dl) or cancel(~q).\n");
    line_prompt();
    input_to("enter_text");
    return;
  }
  if(save && !format_warning)
    for(x=0;x<siz;x++)
      if(strlen(message[x]) > 80) {
        write("Your text has some very long lines in it.  You should probably\n"+
              "use the format option (~f) before you save.  To override this\n"+
              "warning, just try to save again.\n");
        format_warning=1;
        line_prompt();
        input_to("enter_text");
        return;
      }
             
  if(save && siz)
    final=implode(message,"\n")+"\n";
  if(report_ob)
    call_other(report_ob,report_str,final);
  destruct(this_object());
}

/* Function name: show_text
 * Description: shows the current entered text, if any
 * Arguments: none
 * Returns: void
 */

void show_text() {
  int lnum,siz;
  siz=sizeof(message);
  if(!siz)
    return write("No text to display.\n");
  write("Your entered text so far:\n");
  for(lnum=0;lnum<siz;lnum++)
    write(pad(""+(lnum+1),3)+message[lnum]+"\n");
  if(max_length)
    write("Max lines: "+max_length+"\n");
}
/* Function name: format_text
 * Description: formats the message to 70 cols, leaving blank lines alone
 * Arguments:
 * Returns:
 */

void format_text() {
  string mess;
  int pos,len;
  string *lines;
  if(!sizeof(message))
    return write("Nothing to format.\n");
  mess=implode(message,"\n");
  len=strlen(mess);
  while(pos < len) {
    if(mess[pos..pos]=="\n") {
      if(mess[pos+1..pos+2]!=" \n") {
#ifndef __LDMUD__ /* Rumplemintz */
        mess=mess[0..pos-1]+mess[pos+1..-1];
#else
        mess = mess[0..pos-1] + mess[pos+1..<1];
#endif
        len--;
      } else {
        pos+=3;
      }
    } else
      pos++;
  }
  mess=format(mess,75);
  message=explode(mess,"\n");
  len=sizeof(message);
  while(len--)
    if(message[len]==0 || message[len]=="")
      message[len]=" ";
#ifndef __LDMUD__ /* Rumplemintz */
    else if(message[len][-1..-1]!=" ")
#else
    else if (message[len][<1..<1] != " ")
#endif
      message[len]+=" ";
  write("Formatted.\n");
}

/* Function name: delete_line
 * Description: deletes a line from the message
 * Arguments: string, number entered by the user to delete
 * Returns: void
 */

void delete_line(string str) {
  int lnum;
  if(!str)
    return;
  sscanf(str,"%d",lnum);
  if(lnum < 0 || lnum > sizeof(message))
    return write("There is no line "+lnum+" to delete.\n");
  message[lnum-1]="BALETED\nBALETED";  /* newline should exist nowhere else in the message array */
  message-=({"BALETED\nBALETED"});
  write("Line "+lnum+" deleted.\n");
}

/* Function name: replace_line
 * Description: replaces the specified line in the message
 * Arguments: string containing line number and replacement line
 * Returns: void
 */

void replace_line(string str) {
  int lnum;
  string newstr;
  if(!str)
    return;
  sscanf(str,"%d %s",lnum,newstr);
  if(lnum < 0 || lnum > sizeof(message))
    return write("There is no line "+lnum+" to replace.\n");
  if(!newstr) newstr=" ";
#ifndef __LDMUD__ /* Rumplemintz */
  else if(newstr[-1..-1]!=" ")
#else
  else if (newstr[<1..<1] != " ")
#endif
    newstr+=" ";
  message[lnum-1]=newstr;
  write("Line "+lnum+" replaced.\n");
}

/* Function name: insert_line
 * Description: inserts a new line before the specified line in the message array
 * Arguments: string contianing the line number and string to insert
 * Returns: void
 */

void insert_line(string str) {
  int lnum,index,siz;
  string newstr,*newmess;
  if(!str)
    return;
  sscanf(str,"%d %s",lnum,newstr);
  if(lnum < 0 || lnum > (siz=sizeof(message)))
    return write("There is no line "+lnum+" to insert before.\n");
  if(!newstr) newstr=" ";
#ifndef __LDMUD__ /* Rumplemintz */
  else if(newstr[-1..-1]!=" ")
#else
  else if (newstr[<1..<1] != " ")
#endif
    newstr+=" ";
  newmess=allocate(siz+1);
  for(index=0;index<lnum-1;index++)
    newmess[index]=message[index];
  newmess[lnum-1]=newstr;
  for(index=lnum-1;index<siz;index++)
  newmess[index+1]=message[index];
  message=newmess;
  write("Line inserted before line "+lnum+".\n");
}

/* Function name: clear_text()
 * Description: clears out the text to allow starting over
 * Arguments: none
 * Returns: void
 */
 
void clear_text() {
  message=({});
  write("Cleared.\n");
}

/* Function name: enter_text
 * Description: input_to function for entering text and commands
 * Arguments: line typed by user
 * Returns: void
 */
 
void enter_text(string str) {
  if(!str) str="";
  if(str[0..0]=="~") {
    switch(str[1..2]) {
      case "h": 
        show_help();
        break;
      case "s":
        end_edit(1);
        return;
      case "q":
        end_edit(0);
        return;
      case "l":
        show_text();
        break;
      case "f":
        format_text();
        break;
      case "c":
        clear_text();
        break;
      case "dl":
#ifndef __LDMUD__ /* Rumplemintz */
        delete_line(str[4..-1]);
#else
        delete_line(str[4..<1]);
#endif
        break;
      case "rl":
#ifndef __LDMUD__ /* Rumplemintz */
        replace_line(str[4..-1]);
#else
        replace_line(str[4..<1]);
#endif
        break;
      case "il":
#ifndef __LDMUD__ /* Rumplemintz */
        insert_line(str[4..-1]);
#else
        insert_line(str[4..<1]);
#endif
        break;
      default:
        write("Unknown ~ command.\n");
        break;
    }
  } else if(str=="**") {
    end_edit(1);
    return;
  } else {
    format_warning=0;
    message+=({str+" "});
  }
  line_prompt();
  input_to("enter_text");
}
