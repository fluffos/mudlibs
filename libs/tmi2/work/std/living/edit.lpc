//
//  Basic editor object
//
// Zak, 930129:
//  - if using ed and the file is not modified (i.e, Q pressed, for
//    example), it will abort as the simple editor does when ~q entered
//    (I'm sick of not having an abort in ed when mailing/posting...)
//
// Watcher, 930228
//  - Added ~r, ~w, and ~h commands to the editor and allow '**' as
//    optional edit closer (for those use to the old system)

void display_ed_help();

private nosave string edit_filename, callback;
private nosave mixed edit_args;
private nosave object act_ob;
private nosave int mtime;

varargs int edit (string fname, string fun, object ob, mixed args) {
   string tmp;
   mixed *stat_buf;

   callback = fun;
   edit_args = args;
   if (!ob) ob = this_player();
   act_ob = ob;
   if(!fname) {
      write("No filename passed to edit.\n");
      return 0;
   }
   tmp = read_file (fname);
   if (!write_file(fname,"")) {
      write("Edit can't write to " + fname +".\n");
      return 0;
   }
   edit_filename = fname;
   if ((string)this_player()->query_env("editor") == "ed") {
      stat_buf = stat( fname, -1 );
      mtime = (int) stat_buf[ 1 ];
      ed (edit_filename, "stop_ed");
      this_player()->set_is_editing(fname + " (Edit object)");
      this_player()->set("buffer_flag", 1);
      return 1;
   }
   write("To end message type \".\". To abort, type ~q. To view help, " +
	 "type ~h.\n");
   write("__________________________________________________________________\n");
   if (tmp) write (tmp);
   this_player()->set("buffer_flag", 1);
   this_player()->set_is_editing(fname + " (Edit object)");
   input_to("lines");
   return 1;
}

protected void lines(string str) {
   string file;
 
   if (str == "." || str == "**") {
      this_player()->set_is_editing("");
      if (act_ob && function_exists(callback,act_ob)) {
	call_other(act_ob,callback,edit_args);
      } else write ("Can't find function: "+callback+"\n");
      this_player()->dump_buffer();
      return;
   }
   if (str == "~e") {
      ed(edit_filename,"stop_ed");
      return;
   }
   if (str == "~q") {
      write("Edit aborted.\n");
      this_player()->set_is_editing("");
      if (act_ob && function_exists ("abort",act_ob))
         act_ob->abort();
      this_player()->dump_buffer();
      return;
   }
   if (str == "~p") {
 
	  if(!file_exists(edit_filename) || !read_file(edit_filename)) 
	  write("Buffer empty.\n");
 
	  else write(read_file(edit_filename) + "\n");
 
	  input_to("lines");
	  return;
   }

   if (str == "~r" || str == "~w") {
	write("No filename given.\n");
	input_to("lines");
	return;
   }
 
   if(wizardp(this_object()) && sscanf(str, "~r %s", file) == 1) {
 
   	file = resolv_path("cwd", file);

	if(!file_exists(file)) {
	write("No such file : " + file + "\n");
	input_to("lines");
	return; }
 
	if((int)master()->valid_read(file, this_object()) == 0) {
  	write(file + " : Access denied.\n");
	input_to("lines");
	return; }
 
	write_file(edit_filename, read_file(file));
	write(file + " appended.\n");
	input_to("lines");
	return;

   }
 
   if(wizardp(this_object()) && sscanf(str,"~w %s", file) == 1) {

 	file = resolv_path("cwd", file);
 
	if((int)master()->valid_write(file, this_object()) == 0) {
	write(file + " : Write access denied.\n");
	input_to("lines");
	return; }

	if(file_exists(file))
	  write("Buffer appended to " + file + ".\n");
	else write("Buffer written to " + file + ".\n");
 
	write_file(file, read_file(edit_filename));
	input_to("lines");
	return;
 
   }
 
 
   if(str == "~h" || str == "~help") {
	display_ed_help();
	input_to("lines");
	return;
   }
 
   write_file(edit_filename,str + "\n");
   input_to("lines");
   return;
}

void stop_ed() {
   mixed *statbuf;

   this_player()->set_is_editing("");
   statbuf = stat( edit_filename, -1 );
   if ( !statbuf || mtime == statbuf[ 1] ) {
      write("Edit aborted.\n");
      if (act_ob && function_exists ("abort",act_ob))
         act_ob->abort();
      this_player()->dump_buffer();
      return;
   }
   if (act_ob && function_exists(callback,act_ob))
     call_other(act_ob,callback, edit_args);
   else
     write ("*Error: couldn't find target object when leaving ed.\n");
   this_player()->dump_buffer();
   return;
}

string query_edit_filename() {
   return edit_filename;
}

void set_edit_filename(string str) {
   edit_filename = str;
   return;
}
 
void display_ed_help() {

   write("\nStandard User Editor\n====================\n\n" +
	 "\t~e\t- Enter expanded editor system\n" +
	 "\t~h\t- This editor help display\n" +
	 "\t~p\t- Display contents of editor buffer\n" +
	 "\t~q\t- Abort editor without saving contents\n");
 
   if(wizardp(this_object()))
   write("\n\t~r [file]\t- Read contents of file into editor\n" +
	 "\t~w [file]\t- Write editor buffer to file\n");
 
   write("\n\tExit and save with \".\" or \"**\".\n\n");

return; }
 
