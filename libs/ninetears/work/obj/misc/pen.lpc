inherit "std/object";
#include "/include/forms.h"

object ob_write;
string text;
int sec_level;
mixed fields;

void setup() {
  set_name("pen");
  set_long("A pen, looks like you can writeon things with it.\n");
  set_weight(1);
}

string query_short(){
  return "std/paran/colour"->query_colour(sec_level)+" pen";
}

void init() {
  ::init();
  add_action("write_on","write");
  add_action("fill_in", "fill");
}

int start_writing();

int write_on(string str) {
  object ob;

  if (!str) {
    notify_fail("Usage: write <object>\n");
    return 0;
  }

  if (sizeof(ob_write)) {
    notify_fail("Already writing on something.\n");
    return 0;
  }

  ob = find_match(str, environment(this_player()), "query_no_writing", 1) + 
       find_match(str, this_player(), "query_no_writing", 1);

  if (!sizeof(ob)) {
    notify_fail("Could not find any "+str+"'s.\n");
    return 0;
  }
  ob_write = ob;
  start_writing();
  return 1;
}

int start_writing() {
  write("What do you wish to write on "+ob_write->query_short()+"?\n");
  write("** to finish writing and ~q to quit.\n");
  text = "";
  write("]");
  input_to("get_text");
  return 1;
}

int finished_writing() {
  string str;

  if (!text) {
    write("Quitting....\n");
    ob_write = 0;
    return 1;
  }
  str = ob_write->query_read();
  if (!str)
    str = "";
  ob_write->set_read(str+"Scribbled on in "+"std/colour"->query_colour(sec_level)+
               " ink is the message\n"+text);
  write("Ok wrote on "+ob_write->query_short()+"\n");
  say(this_player()->short()+" just wrote on a "+ob_write->query_short()+
      " with a "+query_short()+".\n");
//  ob_write = delete(ob_write,0);
  if (ob_write)
    start_writing();
  else
    ob_write = 0;
  return 1;
}

int get_text(string str) {
  if (str == "**") {
    finished_writing();
    return 1;
  }
  if (str == "~q") {
    text = 0;
    finished_writing();
  }
  text += str+"\n";
  write("]");
  input_to("get_text");
  return 1;
}

int finish_form();
int start_form();

int fill_in(string str) {
  object ob;

  if (sscanf(str, "in %s",str)!=1) {
    notify_fail("Usage: fill in <form>\n");
    return 0;
  }
  ob = find_match(str,environment());
  if (!sizeof(ob)) {
    notify_fail("Usage: fill in <form>\n");
    return 0;
  }
  ob_write = ob;
/* force it give me a copy */
  fields = ob_write->query_fields() + ({ });
  if (!sizeof(fields)) {
    write("Could not write on "+ob_write->query_short()+"\n");
    finish_form();
    return 1;
  }
  start_form();
  return 1;
}

int start_form() {
  int i;

  if (!sizeof(fields)) {
    write("Ok finished filling in form "+ob_write->query_short()+"\n");
    return 1;
  }
  if (fields[1][2] == FLG_TEXT_ONLY) {
    delete(fields,0,2);
    start_form();
    return 1;
  }
  i = ((strlen(fields[0])+2)/20)*20;
  printf("%-*s : ", i, fields[0]);
  input_to("get_field");
}

int get_field(string str) {
/*  if (strlen(str) > fields[1][1])
    str = extract(str,0,fields[1][1]); */
  ob_write->set_field(fields[0],str);
  delete(fields,0,2);
  if (!sizeof(fields)) {
    write("You have finished filling in "+ob_write->query_short()+"\n");
    finish_form();
    return 1;
  }
  printf("%-*s : ", ((strlen(fields[0])+2)/20)*20, fields[0]);
  input_to("get_field");
}

int finish_form() {
  delete(ob_write,0);
  if (!sizeof(ob_write)) {
    write("Finished filling the forms.\n");
    return 1;
  }
  fields = ob_write->query_fields();
  if (!sizeof(fields)) {
    write("Sorry "+ob_write->query_short()+" was not a form.\n");
    finish_form();
    return 1;
  }
  start_form();
}
