inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("Who do you want to kick in the shin?\n", "#MN# attempts to kick someone in the shin, but looks like a jackass instead.\n");
       target("#MN# kicks #TN# in the shin!\n", "#MN# kicks #TN# in the shin!\n", "#MN# kicks you in the shin!\n");
       afar("You kick #TN# in the shin from afar!\n", "#MN# kicks you in the shin from afar!\n");
    }
}

int
cmd_shins(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
