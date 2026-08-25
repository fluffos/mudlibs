/*
    /std/user/more.c
    from Nightmare IV
    inherited player functions for paging files and string arrays
    created by Descartes of Borg 931204
*/

#include "more.h"

nosave private mapping __More;

void create() { __More = ([]); }

varargs int more(mixed what, string cl, function endmore, mixed args) {
    string *tmp;

    if(!pointerp(what) && !stringp(what))
      return notify_fail("Unknown file reference.\n");
    if(__More["lines"]) __More = ([]);
    if(!(__More["class"] = cl)) __More["class"] = "info";
    if(!(__More["screen"]=to_int((string)this_object()->getenv("LINES"))))
      __More["screen"] = 20;
    if(stringp(what)) {
        if(sizeof(tmp = (string *)this_object()->wild_card(what)) != 1)
          return notify_fail("Ambiguous file reference.\n");
        if(file_size(tmp[0]) < 1)
          return notify_fail("Ambiguous file reference.\n");
        __More["total"] = sizeof(__More["lines"] =
          explode(read_file(tmp[0]), "\n"));
    }
    else if(pointerp(what))
      __More["total"] = sizeof(__More["lines"] = what);
    else return notify_fail("Illegal file reference.\n");
    if(creatorp(this_object()) && tmp && tmp[0])
      message(__More["class"], "--==** "+tmp[0]+" **==--", this_object());
    if(!__More["total"]) {
        __More = ([]);
        if(functionp(endmore)) {
            if(!((int)master()->valid_function(endmore)))
              error("Illegal function pointer.\n");
            else (*endmore)(args);
        }
        return 1;
    }
    __More["current"] = 0;
    if(functionp(endmore)) __More["endfun"] = endmore;
    __More["args"] = args;
    do_more(" ");
    return 1;
}

protected void do_more(string cmd) {
    string args;
    int i, x;

    if(!cmd || cmd == "" || cmd == "\r" || cmd == "\n" || cmd[0] == 10) cmd = " ";
    if((x = strlen(cmd)) > 1) {
        args = cmd[1..x-1];
        cmd = cmd[0..0];
    }
    switch(cmd) {
        case " ": break;
        case "b": case "B":
          __More["current"] -= __More["screen"]*2;
          if(__More["current"] < 0) __More["current"] = 0;
          break;
        case "<": __More["current"] = 0; break;
        case ">": __More["current"] = __More["total"]-1; break;
        case "/":
          if(getenv("MORE") == "off") regexp_fwd(args);
          else input_to("regexp_fwd");
          return;
        case "?":
            if(getenv("MORE") == "off") regexp_bkwd(args);
            else input_to("regexp_bkwd");
            return;
        case "n":
          if(!__More["regexp"] || __More["regexp"] == "") {
            message(__More["class"], "\nNo previous search.", this_object());
            if(getenv("MORE") == "off") input_to("do_more");
            else get_char("do_more");
            return;
          }
          if(__More["regexp"][0] == '/')
            regexp_fwd(__More["regexp"][1..strlen(__More["regexp"])-1]);
          else regexp_bkwd(__More["regexp"][1..strlen(__More["regexp"])-1]);
          return;
        case "=":
          message(__More["class"], "\nCurrent line: "+
            __More["current"], this_object());
          if(getenv("MORE") == "off") input_to("do_more");
          else get_char("do_more");
          return;
        case "v": case "V":
          message(__More["class"], "\nNightmare Mudlib \"more\" "+
            "version 2.1 by Descartes of Borg 931204.", this_object());
          if(getenv("MORE") == "off") input_to("do_more");
          else get_char("do_more");
          return;
        case "h": case "H":
            do_help();
            if(getenv("MORE") == "off") input_to("do_more");
            else get_char("do_more");
            return;
        case "Q": case "q":
          message(__More["class"], "", this_object());
          if(functionp(__More["endfun"]) && (int)master()->valid_function(__More["endfun"]))
            (*__More["endfun"])(__More["args"]);
          __More = ([]);
          return;
        default:
          message(__More["class"], "\nUnrecognized command.", this_object());
          if(getenv("MORE") == "off") input_to("do_more");
          else get_char("do_more");
          return;
    }
    message(__More["class"], "", this_object());
    for(i=__More["current"];
      i<__More["current"] + __More["screen"]; i++) {
        if(i>= __More["total"]) {
          if(functionp(__More["endfun"]) &&
            (int)master()->valid_function(__More["endfun"]))
              (*__More["endfun"])(__More["args"]);
          __More = ([]);
          return;
        }
        message(__More["class"], __More["lines"][i], this_object());
    }
    if((__More["current"] = i) >= __More["total"]) {
        if(functionp(__More["endfun"]) &&
          (int)master()->valid_function(__More["endfun"]))
            (*__More["endfun"])(__More["args"]);
        __More = ([]);
        return;
    }
    __More["current"] = i;
    message("prompt", "%^B_WHITE%^BLACK%^--More-- ("+
      to_int(percent(__More["current"], __More["total"]))+"%) ", this_object());
    if(getenv("MORE") == "off") input_to("do_more");
    else get_char("do_more");
    return;
}

void do_help() {
    message("Nhelp",
      "Help for the \"more\" utility:\n\n"
      "<spacebar> Display the next page of text.\n"
      "B or b     Display the previous page of text.\n"
      "<          Goto the beginning of the document.\n"
      ">          Goto the end of the document.\n"
      "=          Display the current line number.\n"
      "/\<exp>     Goto the next line with the expression <exp> in it.\n"
      "?<exp>     Goto the previous line with the expression <exp> in it.\n"
      "v or V     See the version information about this pager.\n"
      "h or H     This help screen.\n"
      "q or Q     Quit out of the pager.\n", this_object()
    );
}

protected void regexp_fwd(string str) {
    string *matches;
    int i;

    __More["regexp"] = "/"+str;
    if(!sizeof(matches = regexp(__More["lines"][__More["current"]..__More["total"]-1], str))) {
        message(__More["class"], "\nPattern not found.\n", this_object());
        if(getenv("MORE") == "off") input_to("do_more");
        else get_char("do_more");
        return;
    }
    for(i=__More["current"]; i<__More["total"]; i++) {
        if(__More["lines"][i] != matches[0]) continue;
        __More["current"] = i;
        break;
    }
    message(__More["class"], "\nSkipping to line "+__More["current"]+"...",
      this_object());
    do_more(" ");
}

protected void regexp_bkwd(string str) {
    string *matches;
    int i;

    __More["regexp"] = "?"+str;
    if(!sizeof(matches=regexp(__More["lines"][0..__More["current"]], str))) {
        message(__More["class"], "\nPattern not found.", this_object());
        if(getenv("MORE") == "off") input_to("do_more");
        else get_char("do_more");
        return;
    }
    __More["current"] = member_array(matches[0],__More["lines"][0..__More["current"]]);
    message(__More["class"], "\n...Backing up...", this_object());
    do_more(" ");
}

string getenv(string val) { return 0; }
