string query_author() { return "alcal"; }

varargs
mixed compile_object(string file, object caller) {
  object ob, o;
  string path;
  string s;


/*
	if (find_player("alcal"))
		message("debug", sprintf("(%O) %O ,%O\n", THOB, file, caller), find_player("alcal"));
*/
  // remove the next line when not needed
  if (!caller) caller = previous_object();

  path = extract_path(file);
  ob = load_object(path + "/virtual/server");
  if (ob) o = ob->compile_object(file);

  return o;
}

int main(string args) {

  if (!args) return notify_fail("Need a parameter.\n");
  printf("got: %O\n", compile_object(args));
  return 1;
}
