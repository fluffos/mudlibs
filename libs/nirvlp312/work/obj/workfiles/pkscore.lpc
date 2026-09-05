inherit "/obj/user/vdsfuns";

#define savepath "obj/pkscore"

mapping PK;
string *p_k;

void
restore_me() {
    restore_object(savepath);
    PK=reconstruct_mapping(p_k);
}

void
save_me() {
    p_k=deconstruct_mapping(PK);
    save_object(savepath);
}

void
reset(int arg) {
    if(!arg) {
      PK=([]);
      restore_me();
    }
}

void
add_score(string name, int howmuch) {
    PK[name] += howmuch;
    save_me();
}

mapping
query_scores() {
    return PK;
}

int
query_score(string name) {
    return PK[name];
}
