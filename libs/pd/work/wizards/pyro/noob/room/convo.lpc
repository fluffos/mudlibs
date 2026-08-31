mapping convo_call_outs;

void create() {
  convo_call_outs = ([ ]);
}

void clear_convo(object tp) {
  if(tp)
    convo_call_outs[tp] = 0;
}

void continue_conversation(object tp, mixed *args) {
  if(!tp || !present(tp) || sizeof(args) < 1)
    return clear_convo(tp);
  if(sizeof(args[0]) > 5 && (args[0])[0..4] == "FUNC:") {
    string func = (args[0])[5..<1];
    if(!call_other(this_object(), func, tp))
      return clear_convo(tp);
  }
  else {
    message("say", args[0], tp);
  }

  if(sizeof(args) < 3)
    return clear_convo(tp);

  convo_call_outs[tp] = call_out("continue_conversation", args[1], tp, args[2..<1]);
}

int do_conversation(object tp, mixed *args) {
  if(!tp || !args) return 0;
  if(convo_call_outs[tp]) {
    // only one conversation for a player at a time.
    // stop the old one
    remove_call_out(convo_call_outs[tp]);
  }

  continue_conversation(tp, args);
  return 1;
}
