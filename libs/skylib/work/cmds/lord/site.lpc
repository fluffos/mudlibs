
#include <parser.h>
#include <access.h>

inherit COMMAND_BASE;

int print_access(string bit, mapping bing, int depth, int cols);

/*
 * This will ban a site
 */
mixed cmd(string ip, string ident, string level, string reason) {

    seteuid("Root");

    if (this_player() != this_player(1))
        return 0;

    switch(level) {
    case "nonew":
        level = "2";
        break;
    case "noacccess":
        level = "3";
        break;
    case "normal":
        level = "1";
        break;
    }

    if (!BASTARDS_H->change_access(explode(ip, "."), ident,
        to_int(level), reason)) {
        write("Error changing permissions.\n");
        return 0;
    }

    write("Access permisions changed.\n");
    printf("User %s at site %s set to %s for %s\n",
      ident, ip, PERM_NAMES[to_int(level)], reason);
    return 1;
} /* cmd() */

int access() {
    mixed bing;

    seteuid("Root");

    if (this_player() != this_player(1))
        return 0;

    bing = (mixed)BASTARDS_H->query_all_access();

    if (!m_sizeof(bing)) {
        notify_fail("No access control defined.\n");
        return 0;
    }

    write("Current access list:\n");
    print_access("", bing, 0, (int)this_player()->query_cols());
    return 1;
}

int print_access(string bit, mapping bing, int depth, int cols) {
    mixed *bits;
    int i;

    if (this_player() != this_player(1))
        return 0;
    bits = m_indices(bing);
    if (depth == 4) {
        /* Do the ident printing... */
        for (i=0;i<sizeof(bits);i++) {
            printf("%s@%s set to %s [%s]\n", bits[i], bit,
              PERM_NAMES[bing[bits[i]][0]],
              BASTARDS_H->query_reason(explode(bit, "."), bits[i]));
        }
        return 1;
    }
    for (i=0;i<sizeof(bits);i++)
        print_access(bit+"."+bits[i], bing[bits[i]], depth+1, cols);
    return 1;
} /* print_access() */

int help() {
    return notify_fail(
      "Syntax: site access\n"+
      "        site ban <ip number> <ident> <level> <reason>\n"+
      "                 <level> := normal [1] normal access,\n"+
      "                            nonew [2] no new players, \n"+
      "                            noaccess [3] no access.\n");
}
mixed *query_patterns() {
    return ({ "ban <word'address'> <word'ident'> <word'level'> "
      "<string'reason'>",
      (: cmd($4[0], $4[1], $4[2], implode($4[3..], "")) :),
      "access", (: access() :),
      "", (: help() :),
      "help", (: help() :)
    });
} /* query_patterns() */
