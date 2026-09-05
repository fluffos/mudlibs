inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("Shove who?\n", "#MN# looks confused.\n");
       target("You shove #TN# to the ground!\n", "#MN# shoves #TN# to the ground!\n", "#MN# shoves you to the ground!\n");
       afar("You shove #TN# to the ground from afar!\n", "#MN# shoves you to the ground from afar!\n");
    }
}

int
cmd_shove(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
