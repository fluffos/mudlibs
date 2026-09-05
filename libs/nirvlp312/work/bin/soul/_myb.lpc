inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You glance around the room looking for your bitch.$N$\n", "#MN# glances around the room looking for something.$N$\n");
       target("You glance around the room and notice a scared look on #TN#'s face.#RET#You grin and say, \"Oh yeah....there's my bitch!\"$N$\n", "#MN# glances around the room and notices a scared look on #TN#'s face.#RET#MN# grins and says, \"Oh yeah....there's my bitch!\"$N$\n", "#MN# glances around the room and notices a scared look on your face.#RET#MN# grins and says, \"Oh yeah.....there's my bitch!\"$N$\n");
       afar("You glance around the mud and notice a scared look on #TN#'s face.#RET#You grin and say, \"Oh yeah....there's my bitch!\"$N$\n", "#MN# glances around the mud and notices a scared look on your face.#RET#MN# grins and says, \"Oh yeah....there's my bitch!\"$N$\n");
    }
}

int
cmd_myb(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
