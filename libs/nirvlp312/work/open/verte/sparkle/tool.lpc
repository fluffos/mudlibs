object writeup;
drop() { return 1; }
get() { return 1; }

reset(x) {
  if(x) return;
  writeup = clone_object("/open/verte/writeup");
}

short() { return "area approval tool"; }

id(str) { return (str=="tool"); }

init() {
  add_action("cmd_writeup","writeup");
}

cmd_writeup(str)
{
  return (int)writeup->main(str);
}
