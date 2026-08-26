inherit COMMAND_BASE;

/** @ignore yes */
int cmd() {
    write( (string)SOUL_H->help_list() );
    return 1;
} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({ "", (: cmd() :),
              "list", (: cmd() :),
              });
} /* query_patterns() */
