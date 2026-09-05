inherit CommandCode;

#include <sys/trace.h>
#define MSG_CALL         "lfun calls (-l)"
#define MSG_CALL_OTHER   "call_others (-o)"
#define MSG_RETURN       "function returns (-r)"
#define MSG_ARGS         "function arguments (-a)"
#define MSG_EXEC         "instructions (-i)"
#define MSG_HEART_BEAT   "heart_beat (-h)"
#define MSG_APPLY        "driver applies (-d)"

private variables private functions inherit ArgsLib;
private variables private functions inherit GetoptsLib;
private variables private functions inherit ObjectLib;

int do_command(string arg) {
  mixed *args;
  args = getopts(explode_args(arg), "xloraihdpv");

  if (member(args[1], 'v')) {
    string traceprefix = traceprefix(0);
    traceprefix(traceprefix);
    int trace = trace(0);
    trace(trace);
    printf("        trace lfun calls (-l): %s\n"
           "       trace call_others (-o): %s\n"
           "  trace function returns (-r): %s\n"
           "trace function arguments (-a): %s\n"
           "      trace instructions (-i): %s\n"
           "         trace heartbeat (-h): %s\n"
           "    trace driver applies (-d): %s\n"
           "      print object names (-p): %s\n"
           "            trace prefix: %s\n",
           (trace &       TRACE_CALL ? "on" : "off"),
           (trace & TRACE_CALL_OTHER ? "on" : "off"),
           (trace &     TRACE_RETURN ? "on" : "off"),
           (trace &       TRACE_ARGS ? "on" : "off"),
           (trace &       TRACE_EXEC ? "on" : "off"),
           (trace & TRACE_HEART_BEAT ? "on" : "off"),
           (trace &      TRACE_APPLY ? "on" : "off"),
           (trace &    TRACE_OBJNAME ? "on" : "off"),
           (traceprefix ? traceprefix : "tracing all files")
          );
  } else {
    int trace = trace(0);
    string traceprefix = traceprefix(0);
    if (member(args[1], 'x')) {
      trace = 0;
      traceprefix = 0;
    } else {
      if (member(args[1], 'l')) { trace ^= TRACE_CALL; }
      if (member(args[1], 'o')) { trace ^= TRACE_CALL_OTHER; }
      if (member(args[1], 'r')) { trace ^= TRACE_RETURN; }
      if (member(args[1], 'a')) { trace ^= TRACE_ARGS; }
      if (member(args[1], 'i')) { trace ^= TRACE_EXEC; }
      if (member(args[1], 'h')) { trace ^= TRACE_HEART_BEAT; }
      if (member(args[1], 'd')) { trace ^= TRACE_APPLY; }
      if (member(args[1], 'p')) { trace ^= TRACE_OBJNAME; }
      traceprefix = sizeof(args[0]) ? args[0][0] : "";
      if (traceprefix[0] == '/') { traceprefix = traceprefix[1..]; }
    }
    traceprefix(traceprefix);
    trace(trace);
    if (trace) {
      string *msg = ({ });
      if (trace & TRACE_CALL) { msg += ({ MSG_CALL }); }
      if (trace & TRACE_CALL_OTHER) { msg += ({ MSG_CALL_OTHER }); }
      if (trace & TRACE_RETURN) { msg += ({ MSG_RETURN }); }
      if (trace & TRACE_ARGS) { msg += ({ MSG_ARGS }); }
      if (trace & TRACE_EXEC) { msg += ({ MSG_EXEC }); }
      if (trace & TRACE_HEART_BEAT) { msg += ({ MSG_HEART_BEAT }); }
      if (trace & TRACE_APPLY) { msg += ({ MSG_APPLY }); }
      tell_player(THISP, "Now tracing: " + implode(msg, ", ") + ".\n");
    } else {
      tell_player(THISP, "Tracing terminated.\n");
    }
  } 

  return 1;
}

