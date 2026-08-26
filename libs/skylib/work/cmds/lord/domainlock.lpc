/**
 * Domain lock command.
 * For those who are in control(tm).
 * <p>
 * @author Taffyd
 */

#define PATRICIAN "/d/am/patrician/patrician"

inherit COMMAND_BASE;

int domain_check() {
    return PATRICIAN->do_domaincheck();
} /* domain_check() */

int cmd( string domain, string status ) { 
    PATRICIAN->domain_lock3( status, domain );
    return 1;
} /* cmd() */

mixed *query_patterns() { 
    return ({ "<string'domain'> off", (: cmd( $4[0], "off" ):),
      "<string'domain'> on", (: cmd( $4[0], "on"  ):),
      "list", (: domain_check() :) });
} /* query_patterns() */
