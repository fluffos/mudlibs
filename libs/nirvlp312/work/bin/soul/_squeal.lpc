inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You squeal in delight!\n", "#MN# squeals in delight!\n");
       target("You squeal in delight at #TN#!\n", "#MN# squeals in delight at #TN#!\n", "#MN# squeals in delight at you!\n");
       afar("From far away, you squeal in delight at #TN#!\n", "From far away, #MN# squeals in delight at you!\n");
    }
}

int
cmd_squeal(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
