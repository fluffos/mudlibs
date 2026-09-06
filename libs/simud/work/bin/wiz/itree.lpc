#include <const.h>
#include <wizard.h>
//#include <sys/inherit_list.h>

void usage();
void print_tree(mixed tree);
void print_tree_helper(mixed tree, int depth);

//string spaces;

int main(string arg) {
    object targ;
    mixed tree;

    WIZ_CHECK

    if(!arg || arg == "") targ = environment(this_player());
    if(!(targ ||
         (targ = find_thing(arg)))) {
        usage();
        return 1;
    }
    msg( "~[150Objects inherited by " + object_name(targ) + " (" + targ->query_name() + " / " + targ->query_distant() + ")" );
    tree = inherit_list(targ,3); // tree form, tag virtuals
    print_tree(tree);
    return 1;
}

void print_tree(mixed tree) {
    print_tree_helper(tree,0);
}

print_tree_helper(mixed tree, int depth) {
    int i, j;

    if(!pointerp(tree) || sizeof(tree) == 0) return;

    if(!depth) {
        msg("~CCOM"+tree[0][2..]+"~CDEF");
        print_tree_helper(tree[1..],1);
        return;
    }
    for(j = sizeof(tree); i < j; i++) {
        int virt;

        write(tab(" ", 4*depth-1));
        if(pointerp(tree[i])) {
            if(tree[i][0][0] == 'v') virt = 1;
        } else {
            if(tree[i][0] == 'v') virt = 1;
        }
        if(pointerp(tree[i])) {
            write(tree[i][0][2..]+"\n");
            print_tree_helper(tree[i][1..],depth+1);
            continue;
        }
        write(tree[i][2..]+"\n");
    }
}

//void create() {
//    spaces = "                                                              ";
//}

void usage() {
    write("Usage: itree <filename | living name>\n");
}
