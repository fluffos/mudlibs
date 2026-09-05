inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You cross your arms and smugly look around.#RET#You then blurt out: \"It's like fun, only boring.\"$N$\n", "#CMN# crosses #MP# arms and smugly looks around.#RET##CMN# then blurts out: \"It's like fun, only boring.\"$N$\n");
       target("You cross your arms and smugly look towards #CTN#.#RET#You then blurt out: \"It's like fun, only boring.\"$N$\n", "#CMN# crosses #MP# arms and smugly looks towards #CTN#.#RET##CMN# then blurts out: \"It's like fun, only boring.\"$N$\n", "#CMN# crosses #MP# arms and smugly looks towards you.#RET##CMN# then blurts out: \"It's like fun, only boring.\"$N$\n");
       afar("$HY$[$HW$afar$HY$]$N$#RET#You cross your arms and smugly look towards #CTN#.#RET#You then blurt out: \"It's like fun, only boring.\"#RET#$HY$[$HW$afar$HY$]$N$$N$\n", "$HY$[$HW$afar$HY$]$N$#RET##CMN# crosses #MP# arms and smugly looks towards you.#RET##CMN# then blurts out: \"It's like fun, only boring.\"#RET#$HY$[$HW$afar$HY$]$N$$N$\n");
    }
}

int
cmd_likefun(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "forbin"; }
