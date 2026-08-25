#include "ed.h"
/* cute line editor thing.  Which even a player could use!
 */

nosave string *lines, end_func;
nosave object end_object;
nosave int insertion_point;

void main_bit(string str);
void editor_do_quit(string str);

int do_edit(string str, string end_f, object end_o) {

  if (!end_f) {
    write("Someone has stuffed up.\n");
    return 0;
  }
  end_func = end_f;
  if (!end_o)
    end_object = previous_object();
  else
    end_object = end_o;
  if (!str)
    lines = ({ });
  else
    lines = explode(str, "\n");
  write("Ok, enter your text.  ** on a line by itself to exit.\n");
  write("] ");
  insertion_point = sizeof(lines);
  input_to("editor_loop");
  return 1;
}

void main_bit(string str) {
  int i;
  string s;

  if (str != "") {
    while (str[0] == ' ')
      str = str[1..100];
    switch (str[0]) {
      case 'i' :
      case 'I' :
                write("Insert before line : ");
                input_to("editor_insert");
                return ;
      case 'd' :
      case 'D' :
                write("Delete (line no, or n..m ie 1..2) : ");
                input_to("editor_delete");
                return ;
      case 'l' :
      case 'L' :
                s = "";
                for (i=0;i<sizeof(lines);i++)
                  s += sprintf("%3d: %s\n", i+1, lines[i]);
                this_player()->set_finish_func("end_of_edit_more");
                this_player()->more_string(s);
                return ;
      case 'm' :
      case 'M' :
                write("Modify which line (line no, or n..m ie 1..2) : ");
                input_to("editor_modify");
                return ;
      case 'c' :
      case 'C' :
                write("Ok, back into insertion mode, ** on a line by "+
                      "itself to exit.\n] ");
                insertion_point = sizeof(lines);
                input_to("editor_loop");
                return ;
      case 'e' :
      case 'E' :
                write("Entering ed....  Use 'q' to quit, 'x' to save and "+
                      "exit, 'Q' to quit without saveing changes and 'h' "+
                      "for help.\n");
                write_file(TMP_FILE, implode(lines,"\n"));
                ed(TMP_FILE, "editor_exit_ed");
                return ;
      case 's' :
      case 'S' :
                write("Quiting and saving.\n");
                editor_do_quit(implode(lines, "\n"));
                return ;
      case 'q' :
      case 'Q' :
                write("Are you sure you want to quit (Y/N)? ");
                input_to("editor_check_quit");
                return ;
      case 'h' :
      case 'H' :
                s = read_file(ED_HELP_FILE);
                this_player()->set_finish_func("end_of_edit_more");
                this_player()->more_string(s);
                return ;
                
    }
  }
  write(sizeof(lines)+" lines - Choose from IDLMCESQ H for help. ");
  input_to("main_bit");
  return ;
}

void end_of_edit_more() {
  this_player()->set_finish_func(0);
  main_bit("");
}

void editor_delete(string str) {
  int num1, num2, tmp;

  if (sscanf(str, "%d..%d", num1, num2) == 2) {
    if (num1 > num2) {
      tmp = num1;
      num1 = num2;
      num2 = tmp;
    }
    if (num1 < 1 || num2 > sizeof(lines)+1) {
      write("Out of bounds.\n");
      main_bit("");
    }
    write("Deleteing from line "+num1+" to line "+num2+".\n");
    lines = delete(lines, num1-1, num2-num1+1);
    write("Ok.\n");
    main_bit("");
    return ;
  }
  if (sscanf(str, "%d", num1) == 1) {
    if (num1 < 1 || num1 > sizeof(lines)) {
      write("Line number out of range.\n");
      main_bit("");
      return ;
    }
    write("Deleteing line "+num1+".\n");
    lines = delete(lines, num1-1, 1);
    write("Ok.\n");
    main_bit("");
    return ;
  }
  write("Error, invalid data "+str+".\n");
  main_bit("");
  return ;
}

void editor_insert(string str) {
  int num;

  if (sscanf(str, "%d", num) != 1) {
    write("ERROR! Must be a number.\n");
    main_bit("");
    return ;
  }
  if (num < 1 || num > sizeof(lines)+1) {
    write("Number out of bounds.\n");
    main_bit("");
    return ;
  }
  insertion_point = num -1;
  write("Inserting before line "+num+".  Entering insertion mode, ** on a "+
        "line by itself to exit\n] ");
  input_to("editor_loop");
  return ;
}

void editor_loop(string str) {
  if (str == "**") {
    main_bit("");
    return ;
  }
  lines = lines[0..insertion_point-1]+({ str })+lines[insertion_point..1000];
  insertion_point++;
  write("] ");
  input_to("editor_loop");
  return ;
}

nosave int range1, range2;
nosave string modify_string;

void editor_modify(string str) {
  int num1, num2, tmp;

  if (sscanf(str, "%d..%d", num1, num2) == 2) {
    if (num1 > num2) {
      tmp = num1;
      num1 = num2;
      num2 = tmp;
    }
    if (num1 < 1 || num2 > sizeof(lines)+1) {
      write("Out of bounds.\n");
      main_bit("");
    }
    write("Modifying from line "+num1+" to line "+num2+".\n");
    write("Text to change ? ");
    range1 = num1;
    range2 = num2;
    input_to("editor_modify2");
    return ;
  }
  if (sscanf(str, "%d", num1) == 1) {
    if (num1 < 1 || num1 > sizeof(lines)) {
      write("Line number out of range.\n");
      main_bit("");
      return ;
    }
    write("Modifying line "+num1+".\n");
    write("Text to change ? ");
    input_to("editor_modify2");
    range1 = range2 = num1;
    return ;
  }
  write("Error, invalid data "+str+".\n");
  main_bit("");
  return ;
}

void editor_modify2(string str) {
  if (!str || str == "") {
    write("Aborting.\n");
    main_bit("");
    return ;
  }
  write("Change to ? ");
  input_to("editor_modify3");
  modify_string = str;
  return ;
}

void editor_modify3(string str) {
  int i;
  string s1, s2, s3;

  write("Changing all occurances of '"+modify_string+"' to '"+str+"' "+
        "from "+range1+" to "+range2+".\n");
  for (i=range1-1; i<range2;i++)
    if (sscanf(lines[i], "%s"+modify_string+"%s", s1, s2) == 2) {
      s1 += str;
      while (sscanf(s2, "%s"+modify_string+"%s", s3, s2) == 2)
        s1 += s3+str;
      lines[i] = s1 + s2;
      write(sprintf("%3d: %s\n", i+1, lines[i]));
    }
  write("Done.\n");
  main_bit("");
  return ;
}

void editor_exit_ed() {
  string str;

  str = read_file(TMP_FILE);
  if (!rm(TMP_FILE))
    log_file(LOG_FILE, "ed: couldn't rm "+TMP_FILE+"\n");
  lines = explode(str, "\n");
  main_bit("");
  return ;
}

void editor_do_quit(string str) {
  lines = ({ });
  call_other(end_object, end_func, str);
  end_object = 0;
}

void editor_check_quit(string str) {
  if (str != "" && str[0] != 'y' && str[0] != 'Y') {
    write("Returing to the editor.\n");
    main_bit("");
    return ;
  }
  write("Quiting.\n");
  end_object = 0;
  return ;
}

void editor_check() {
  if (end_object) {
    write("You lost your connection whilst in the editor.  Restarting.\n");
    main_bit("");
  }
}

void quit_editor_check() {
  if (end_object) {
    write("You were editing something when you quit.  Forceing a finish.\n");
    main_bit("s");
  }
}
