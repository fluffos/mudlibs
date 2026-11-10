// communication efuns

varargs void say(mixed str, object ob) {
  if(!this_player()) 
    error("say() makes no sense with no this_player()\n");

  if(!str)
    return;
  if(TP)
    TP -> receive_message("say", str+"");
  else
    message("say", str+"", environment(this_player()) || TP,
      (objectp(ob) ? ({ this_player(), ob }) : ({ this_player() })));
}

void tell_object(object ob, mixed str) { 
  message("com.tell", str+"", ob); 
}

varargs void tell_room(object ob, mixed str, mixed exclude) {
  if(!ob) return;

  message("com.tell", (str ? str+"" : ""), ob,
    (exclude ? (pointerp(exclude) ? exclude : ({exclude})) : ({})));
}

varargs void shout(mixed str, mixed exclude) {
  if(objectp(exclude)) 
    exclude = ({ exclude });
  else if(!pointerp(exclude)) 
    exclude = ({});

  if(this_player()) 
    exclude += ({ this_player() });

  message("com.shout", str+"", users(), exclude);
}

void write(string str) {
  if(TP)
    TP -> add_message(str+"");
  else
    efun::write(str);
}

string add_a(string s) {
  int i;

  if (!stringp(s))
    return 0;     
  i = 0;
  while (s[i] == ' ') i++;

  switch (s[i]) {
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
  case 'A':
  case 'E':
  case 'I':
  case 'O':
  case 'U':
    return "an " + s[i..];
  default:
    return "a " + s[i..];
  }
}
