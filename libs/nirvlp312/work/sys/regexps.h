/*
 * /sys/regexps.h
 * Some useful regular expressions
 */

#ifndef _sys_regexps_h_
#define _sys_regexps_h_

/*
 * The following macros define the regular expression that define the view
 * of some frequent strings you might want to check for.
 * Example: if (IS_REGEXP(x,REGEXP_FLOAT)) write("It is a float!\n");
 */

#define IS_REGEXP(proband,rgxp) sizeof(regexp(({ proband }),"^"+(rgxp)+"$"))
#define REGEXP_OK(rgxp) (!!with_player(0,(#'regexp),({ ({ "" }),rgxp })))

// this is useful to quote any string to be interpreted literally by the
// regexp functions
#define QUOTE_FOR_REGEXP(str) regreplace(str,"([()[\\].*^$|\\\\])","\\\\\\1",1)
// this does the same for single characters appearing between [ and ]
#define QUOTE_CHARS_FOR_REGEXP(str) \
        regreplace(regreplace(str,"\\]","\\]",1),"([^-])-(..*)","\\1\\2-",1)

#define REGEXP_PLUS_MINUS_OR_NOT "([+-]|)"
#define REGEXP_PERIOD "\\."
#define REGEXP_PERIOD_OR_NOT "("REGEXP_PERIOD"|)"
#define REGEXP_UNSIGNED_INT_OR_NOT "[0-9]*"
#define REGEXP_UNSIGNED_INT "[0-9]"REGEXP_UNSIGNED_INT_OR_NOT
#define REGEXP_INT REGEXP_PLUS_MINUS_OR_NOT\
                   REGEXP_UNSIGNED_INT
#define REGEXP_MANTISSE REGEXP_PLUS_MINUS_OR_NOT\
                        "("\
                           "("\
                              REGEXP_UNSIGNED_INT\
                              REGEXP_PERIOD_OR_NOT\
                              REGEXP_UNSIGNED_INT_OR_NOT\
                           ")"\
                        "|"\
                           "("\
                              REGEXP_PERIOD\
                              REGEXP_UNSIGNED_INT\
                           ")"\
                        ")"
#define REGEXP_FLOAT REGEXP_MANTISSE\
                     "("\
                        "[eE]"\
                        REGEXP_INT\
                     "|"\
                        ""\
                     ")"
// the following has a bug. it does not recognize
#define REGEXP_COMMENT_1 "/\\*"\
                         "("\
                            "(\\**[^/])*"\
                         "|"\
                            "[^*]*"\
                         ")"\
                         "\\**\\*/"
#define REGEXP_COMMENT_2 "//[^\n]*\n"
#define REGEXP_COMMENT    "("\
                             REGEXP_COMMENT_1\
                          ")"\
                       "|"\
                          "("\
                             REGEXP_COMMENT_2\
                          ")"
#define REGEXP_INNER_STRING "("\
                               "[^\"\\\\]"\
                            "|"\
                               "\\\\."\
                            ")*"
#define REGEXP_STRING "\"" REGEXP_INNER_STRING "\""
#define REGEXP_INNER_CHAR    "[^\'\\\\]"\
                          "|"\
                             "\\\\."
#define REGEXP_CHAR "\'(" REGEXP_INNER_CHAR ")\'"
#define REGEXP_PREP "\n#[^\n]*[^\\\\]\n"  // preprocessor directive lines
#define REGEXP_COMMENT_OR_STRING\
             REGEXP_COMMENT\
          "|"\
             REGEXP_STRING
#define REGEXP_COMMENT_OR_STRING_OR_CHAR\
             REGEXP_COMMENT_OR_STRING\
          "|"\
             REGEXP_CHAR
#define REGEXP_HEXDIGIT "[0-9a-zA-Z]"
#define REGEXP_HEXDIGIT_OR_NOT "(" REGEXP_HEXDIGIT "|)"
#define REGEXP_OCTDIGIT "[0-7]"
#define REGEXP_OCTDIGIT_OR_NOT "(" REGEXP_OCTDIGIT "|)"

#define REGEXP_QUOTED "\\\\"\
                      "("\
                         "[^x0-9]"\
                      "|"\
                         "x" REGEXP_HEXDIGIT REGEXP_HEXDIGIT_OR_NOT\
                      "|"\
                         REGEXP_OCTDIGIT REGEXP_OCTDIGIT_OR_NOT\
                         REGEXP_OCTDIGIT_OR_NOT\
                      ")"

#define REGEXP_SENTENCE_END "[\\.!?]"

/*
 * The following macro is to get all names from a list of names, no matter
 * how that list is separated (using commas, periods, spaces or whatever).
 * Example:
 *    REGEXPLODE_LIST("rump rump fred") --> ({ "rump","rump","fred" }),
 *    REGEXPLODE_LIST("rump ,rump, and fred") --> ({ "rump","rump","fred" }),
 *    REGEXPLODE_LIST(" ,  rump, and fred..") --> ({ "","rump","fred","" }),
 *    REGEXPLODE_LIST("") --> ({ "" }),
 * so you might want to subtract all empty strings from the result before
 * you process it.
 */

#define REGEXPLODE_LIST(input) (split_array(({ "" })+regexplode(input,\
                                REGEXP_SEPARATOR_OR_AND),2)[1])

#define REGEXP_SEPARATOR_OR_NOT "[ .,;|\t\n]*"
#define REGEXP_SEPARATOR "[ .,;|\t\n]" REGEXP_SEPARATOR_OR_NOT
#define REGEXP_SEPARATOR_OR_AND "("\
                                   "("\
                                      REGEXP_SEPARATOR\
                                      "and"\
                                      REGEXP_SEPARATOR\
                                   ")"\
                                "|"\
                                   REGEXP_SEPARATOR\
                                ")"

#define REGEXP_CTIME "(Mon|Tue|Wed|Thu|Fri|Sat|Sun)"\
                     " (Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Oct|Nov|Dec)"\
                     " [1-3 ][0-9] [0-2][0-9]:[0-5][0-9]:[0-5][0-9]"\
                     " [1-2][0-9][0-9][0-9]"

#define REGEXP_LETTER \
           "a-zA-ZäâæÀÃÆÇéËÈïîÌñòÖÒÕßúÙý
#define REGEXP_PARSER_WORD \
    "["REGEXP_LETTER"0-9][-"REGEXP_LETTER"0-9'_]*["REGEXP_LETTER"0-9]|[^ \t\n]"

#define REGEXP_TERMINAL_COLOUR_TOKEN "%\\^([^%]|(%%*[^%^]))*%%*\\^"

#endif // _sys_regexps_h_

