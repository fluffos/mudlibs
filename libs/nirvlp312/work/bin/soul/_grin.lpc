inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You grin evilly.$N$\n", "#MN# grins evilly.$N$\n");
       target("You grin evilly at #TN#.$N$\n", "#MN# grins evilly at #TN#.$N$\n", "#MN# grins evilly at you.$N$\n");
       afar("You grin evilly at #TN# from afar.$N$\n", "#MN# grins evilly at you from afar.$N$\n");
    }
}

int
cmd_grin(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "shinshi"; }
