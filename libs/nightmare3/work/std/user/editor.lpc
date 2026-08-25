/*    /std/user/editor.c
 *    from Nightmare IV
 *    an editor object for users
 *    created by Descartes of Borg 940715
 */

#include <dirs.h>
#include "editor.h"

#define EDITOR_HELP DIR_USER_HELP + "/editor"
nosave private int __Time;
nosave private string __FileName;
nosave private function __Callback, __Abort;
nosave private mixed __Arguments;

void create() {
    clear_editor();
  }

varargs int edit(string nom, function f, function abort, mixed args) {
    string tmp;

    if(!stringp(nom)) error("Bad argument 1 to edit().\n");
    if(!write_file(nom, "")) {
        message("system", "Permission denied.", this_object());
        return 0;
      }
    __FileName = nom;
    if(!functionp(f)) error("Bad argument 2 to edit().\n");
    else __Callback = f;
    if(!abort) abort = (: previous_object(), "abort" :);
    else if(!functionp(abort)) error("Bad argument 2 to edit().\n");
    __Abort = abort;
    if(args) __Arguments = args;
    tmp = read_file(__FileName);
    if(creatorp(this_object()) && getenv("EDITOR") == "ed") {
        __Time = stat(__FileName, -1)[1];
        ed(__FileName, "end_edit", !creatorp(this_object()));
        return 1;
      }
    message("system", "Nightmare IV Mudlib System Editor", this_object());
    message("system", sprintf("On a line by itself, type \".\" to end "
      "editing and \"%sq\" to abort.\nTo get help, type \"%sh\".",
      query_escape(), query_escape()), this_object());
    message("system", "____________________________________________________________________________", this_object());
    if(tmp) message("system", tmp, this_object());
    input_to("enter_line");
    return 1;
  }

nomask  private  void enter_line(string str) {
    string tmp;

    if(str == ".") {
        if(!((int)master()->valid_function(__Callback)))
          error("Illegal function pointer.\n");
        else (*__Callback)(__Arguments);
        return;
        clear_editor();
      }
    if(strlen(str) == 2 && str[0] == (query_escape())[0]) {
        switch(str[1]) {
	case 'h':
            this_object()->more(EDITOR_HELP, "help", (: "return_to_edit" :));
            return;
        case 'e': ed(__FileName, "end_edit", !creatorp(this_object())); return;
        case 'q':
            message("system", "Edit aborted.", this_object());
            if(!((int)master()->valid_function(__Abort)))
              error("Illegal function pointer.\n");
            else (*__Abort)();
            clear_editor();
            return;
	case 'l':
            edit(__FileName, __Callback, __Abort, __Arguments);
            return;
        case 'r': case 'w':
            if(!creatorp(this_object()))
              message("system", "Function not available to mortals.",
                this_object());
            else message("system", "You must specify a file.", this_object());
            input_to("enter_line");
            return;
        }
      }
    else if(str[0..0] == query_escape()) {
        if(str == sprintf("%shelp", query_escape())) {
            enter_line(str[0..1]);
            return;
	  }
        else if(strlen(str) > 3) {
            if(str[1] == 'r') {
                if(!creatorp(this_object())) {
                    message("system", "Function not available to mortals.",
                      this_object());
                    input_to("enter_line");
                    return;
		  }
                if(!(tmp = read_file(absolute_path(query_cwd(),
                  str[3..strlen(str)-1])))) {
                    message("system", "File not found.", this_object());
                    input_to("enter_line");
                    return;
		  }
                write_file(__FileName, sprintf("%s\n", tmp));
                input_to("enter_line");
                return;
	      }
            else if(str[1] == 'w') {
                if(!creatorp(this_object())) {
                    message("system", "Function not available to mortals.",
                      this_object());
                    input_to("enter_line");
                    return;
		  }
                else if(!write_file(absolute_path(query_cwd(),
                  str[3..strlen(str)-1]), read_file(__FileName))) {
                    message("system", "Permission denied.", this_object());
                    input_to("enter_line");
                    return;
		  }
                input_to("enter_line");
                return;
	      }
	  }
      }
    write_file(__FileName, sprintf("%s\n", str));
    input_to("enter_line");
    return;
  }

nomask void end_edit() {
    if(__Time == stat(__FileName, -1)[1]) {
        message("system", "Edit aborted.", this_object());
        if(!((int)master()->valid_function(__Abort)))
          error("Illegal function pointer.\n");
        else (*__Abort)();
        clear_editor();
        return;
      }
    if(!((int)master()->valid_function(__Callback)))
      error("Illegal function pointer.\n");
    else (*__Callback)(__Arguments);
    clear_editor();
    return;
  }

nomask  private  private void clear_editor() {
    __FileName = 0;
    __Time = 0;
    __Callback = 0;
    __Abort = 0;
    __Arguments = 0;
  }

nomask void return_to_edit() {
    input_to("enter_line");
    return;
}

nomask string query_edit_file() { return __FileName; }

string query_escape() {
    string tmp;

    if(!(tmp = getenv("ESCAPE"))) return "~";
    if(!stringp(tmp)) return "~";
    else return tmp;
  }

string getenv(string key) { return 0; }

string query_cwd() { return DIR_TMP; }

string query_edit_filename() { return __FileName; }
