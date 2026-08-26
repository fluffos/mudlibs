// Petrarch
// Merentha Lib 1.0
// more.c

#include <std.h>

inherit DAEMON;

void continuep(string str, string *input, object tp, int lines, int start, object return_object, string return_function, string topic, int x);

varargs void display(mixed input, object tp, int lines, int start, object return_object, string return_function, string topic, int x) {
    if(!tp) return;
    if(!start) start=0;
    if(!lines=tp->getenv("LINES")) lines=18;
    if(stringp(input)) {
        display(explode(input, "\n"), tp, lines, start, return_object, return_function, topic, x);
        return;
    }
    message("more", implode(input[start..(start+lines)],"\n"), tp);
    if(sizeof(input)>start+lines) {
        message("prompt", "%^B_WHITE%^%^BLACK%^---MORE--- (q) to quit --- (enter) to continue %^RESET%^",tp);
        input_to("continuep", input, tp, lines, start, return_object, return_function, topic, x);
    }
    else {
      if(return_object && return_function) call_other(return_object,return_function, topic, x);
    }
}

void continuep(string str, string *input, object tp, int lines, int start, object return_object, string return_function, string topic, int x) {
    if(str) {
        str=lower_case(str);
        if(str=="q") return;
        if(member_array(str, ({ "", "\n", " "}))!=-1) {
            start+=lines+1;
            display(input, tp, lines, start, return_object, return_function, topic, x);
            return;
        }
        message("prompt", "%^B_WHITE%^%^BLACK%^---MORE--- (q) to quit --- (enter) to continue %^RESET%^",tp);
    }    
    input_to("continuep", input, tp, lines, start, return_object, return_function, topic, x);
}

