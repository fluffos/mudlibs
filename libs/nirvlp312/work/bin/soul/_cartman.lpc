inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You point at everyone in the room and say, \"Screw you guys, I'm going home!\"\n", "#MN# points at everyone in the room and says, \"Screw you guys, I'm going home!\"\n");
       target("You point at #TN# and say, \"Screw you #TN#, I'm going home!\"\n", "#MN# points at #TN# and says, \"Screw you #TN#, I'm going home!\"\n", "#MN# points at you and says, \"Screw you #TN#, I'm going home!\"\n");
       afar("You point at #TN# from afar and say, \"Screw you #TN#, I'm going home!\"\n", "#MN# points at you from afar and says, \"Screw you #TN#, I'm going home!\"\n");
    }
}

int
cmd_cartman(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
