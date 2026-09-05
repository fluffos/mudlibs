inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You say: \"I think that I'll have a Samuel Jackson, please.\"#RET#Quickly, a bartender hands you a glass of Samuel Jackson beer.#RET#From out of no where, someone yells: \"Mmm mmm that's some good shit motherfucker!\"$N$\n", "#CMN# says: \"I think that I'll have a Samuel Jackson, please.\"#RET#Quickly, a bartender hands #CMN# a glass of Samuel Jackson beer.#RET#From out of no where, someone yells: \"Mmm mmm that's some good shit motherfucker!\"$N$\n");
       target("You say: \"I think that #CTN# will have a Samuel Jackson, please.\"#RET#Quickly, a bartender hands #CTN# a glass of Samuel Jackson beer.#RET#From out of no where, someone yells: \"Mmm mmm that's some good shit motherfucker!\"$N$\n", "#CMN# says: \"I think that #CTN# will have a Samuel Jackson, please.\"#RET#Quickly, a bartender hands #CTN# a glass of Samuel Jackson beer.#RET#From out of no where, someone yells: \"Mmm mmm that's some good shit motherfucker!\"$N$\n", "#CMN# says: \"I think that you'll have a Samuel Jackson, please.\"#RET#Quickly, a bartender hands you a glass of Samuel Jackson beer.#RET#From out of no where, someone yells: \"Mmm mmm that's some good shit motherfucker!\"$N$\n");
       afar("[afar] You say: \"I think that #CTN# will have a Samuel Jackson, please.\"#RET#[afar] Quickly, a bartender hands #CTN# a glass of Samuel Jackson beer.#RET#[afar] From out of no where, someone yells: \"Mmm mmm that's some good shit motherfucker!\"$N$\n", "[afar] #CMN# says: \"I think that you'll have a Samuel Jackson, please.\"#RET#[afar] Quickly, a bartender hands you a glass of Samuel Jackson beer.#RET#[afar] From out of no where, someone yells: \"Mmm mmm that's some good shit motherfucker!\"$N$\n");
    }
}

int
cmd_samjack(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "forbin"; }
