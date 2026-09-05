inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You shake your head.#RET#You will stick to your reefer, ain't gonna be messin' 'round with no cocaine.\n", "#MN# shakes #MP# head.#RET##MN# will stick to #MP# reefer, ain't gonna be messin' 'round with no cocaine.\n");
       target("You shake your head at #TN#.#RET#You will stick to your reefer, ain't gonna be messin' 'round with no cocaine.\n", "#MN# shakes #MP# head at #TN#.#RET##MN# will stick to #MP# reefer, ain't gonna be messin' 'round with no cocaine.\n", "#MN# shakes #MP# head at you.#RET##MN# will stick to #MP# reefer, ain't gonna be messin' 'round with no cocaine.\n");
       afar("You shake your head at #TN# from afar.#RET#You will stick to your reefer, ain't gonna be messin' 'round with no cocaine.\n", "#MN# shakes #MP# head at you from afar.#RET##MN# will stick to #MP# reefer, ain't gonna be messin' 'round with no cocaine.\n");
    }
}

int
cmd_rcoke(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
