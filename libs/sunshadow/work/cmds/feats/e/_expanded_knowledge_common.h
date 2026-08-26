int ret;
mapping srow;
int maxpow, sminpow = 0;

if (!stringp(args)) {
    write("%^YELLOW%^Your current expanded knowledge " + expanded_level + " is %^BLUE%^" + TP->query("expanded_knowledge_" + expanded_level) + "%^YELLOW%^.");
    return 1;
}

if (TP->query("expanded_knowledge_" + expanded_level)) {
    //if(TP->query("expanded_knowledge_change")>time()-60*60*24*3)
    if(this_player()->cooldown("expanded knowledge")){
        write("%^BOLD%^%^BLACK%^You can only exchange expanded knowledge powers once per three days.");
        return 1;
    }
}

if (member_array(args, TP->query_mastered_spells("psion") + TP->query_mastered_spells("psywarrior")) != -1) {
    write("%^YELLOW%^You already know %^BLUE%^" + args + "%^YELLOW%^ as a mastered power.");
    return 1;
}

srow = MAGIC_D->query_index_row(args);

if (!mapp(srow)) {
    write("%^YELLOW%^The power %^BLUE%^" + args + "%^YELLOW%^ can't be found.");
    return 1;
}

maxpow = max(({TP->query_class_level("psion"), TP->query_class_level("psywarrior")}));

if (srow["levels"]["psion"] && srow["levels"]["psywarrior"]) {
    sminpow = min(({srow["levels"]["psion"], srow["levels"]["psywarrior"]}));
} else {
    if (srow["levels"]["psion"]) {
        sminpow = srow["levels"]["psion"];
    }
    if (srow["levels"]["psywarrior"]) {
        sminpow = srow["levels"]["psywarrior"];
    }
}

if (!(sminpow > 0 && sminpow < maxpow)) {
    write("%^YELLOW%^The power %^BLUE%^" + args + "%^YELLOW%^ is not of appropriate level to be cast as expanded knowledge.");
    return 1;
}

write("%^YELLOW%^You have gained knowledge of %^BLUE%^" + args + "%^YELLOW%^ through your expanded knowledge " +expanded_level + " feat.");

if (TP->query("expanded_knowledge_" + expanded_level)) {
    //TP->set("expanded_knowledge_change",time());
    this_player()->add_cooldown("expanded knowledge", 259200);
}
TP->set("expanded_knowledge_" + expanded_level, args);


return 1;
