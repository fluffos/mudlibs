inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You start flirting with everyone in the room.$N$\n", "#MN# starts flirting with everyone in the room.$N$\n");
       target("You start flirting with #TN#.$N$\n", "#MN# starts flirting with #TN#.$N$\n", "#MN# starts flirting with you.$N$\n");
       afar("You start flirting with #TN# from afar.$N$\n", "#MN# starts flirting with you from afar.$N$\n");
    }
}

int
cmd_flirt(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
