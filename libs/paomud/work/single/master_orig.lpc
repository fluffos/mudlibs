#include <globals.h>

object connect() {
    object user_ob;
    user_ob = new(USER_OB);
    return user_ob;
}

void create() {
}

string get_root_uid() {
    return ROOT_UID;
}

string get_bb_uid() {
    return BACKBONE_UID;
}

string creator_file(string str) {
    return (string)call_other(SINGLE_DIR + "/simul_efun", "creator_file", str);
}

int valid_socket(object eff_user, string fun, mixed *info) {
    return 1;
}
