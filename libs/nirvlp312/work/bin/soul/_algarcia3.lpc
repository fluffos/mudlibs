inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You calmly remark: You guys are DEFINITELY on my shit list.$N$\n", "#MN# calmly remarks: You guys are DEFINITELY on my shit list.$N$\n");
       target("You point at #TN#.#RET#You calmly remark: You guys are DEFINITELY on my shit list.$N$\n", "#MN# points at #TN#.#RET##MN# calmly remarks: You guys are DEFINITELY on my shit list.$N$\n", "#MN# points at you.#RET##MN# calmly remarks: You guys are DEFINITELY on my shit list.$N$\n");
       afar("You point at #TN# from afar.#RET#You calmly remark to #TN# from afar: You guys are DEFINITELY on my shit list.$N$\n", "#MN# points at you from afar.#RET##MN# calmly remarks to you from afar: You guys are DEFINITELY on my shit list.$N$\n");
    }
}

int
cmd_algarcia3(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
