init() {
  ::init();
  add_action("nu","nu");
  add_action("nd","nu");
  add_action("su","su");
  add_action("sd","sd");
  add_action("wu","wu");
  add_action("wd","wd");
  add_action("eu","eu");
  add_action("exd","ed");
}

nu() { return ::move("northup"); }
nd() { return ::move("northdown"); }
su() { return ::move("southup"); }
sd() { return ::move("southdown"); }
wu() { return ::move("westup"); }
wd() { return ::move("westdown"); }
eu() { return ::move("eastup"); }
exd() { return ::move("eastdown"); }
