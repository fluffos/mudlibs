#include <config.h>
#include <properties.h>
#include <string.h>

#define PL        this_player()
#define PL_EUID   geteuid(this_player())
#define PL_WLEVEL query_user_level(this_player())
#define PL_SHORT  this_player()->QueryShort()
#define PL_NAME   this_player()->query_name()
#define PL_RNAME  this_player()->query_real_name()

#define IPL        this_interactive()
#define IPL_EUID   geteuid(this_interactive())
#define IPL_WLEVEL query_user_level(this_interactive())
#define IPL_SHORT  this_interactive()->QueryShort()
#define IPL_NAME   this_interactive()->QueryName()
#define IPL_RNAME  this_interactive()->QueryRealName()

#define ME  this_object()
#define PO  previous_object()
#define HERE environment(this_player())

#define a_inv(ob)   all_inventory(ob)
#define cap(s)      capitalize(s)
#define clrb(a,b)   clear_bit(a,b)
#define clone(s)    clone_object(s)
#define d_inv(ob)   deep_inventory(ob)
#define env(ob)     environment(ob)
#define fdate(s)    file_date(s)
#define fname(s)    file_name(s)
#define fsize(s)    file_size(s)
#define liv(ob)     find_living(ob)
#define obj(ob)     find_object(ob)
#define pl(ob)      find_player(ob)
#define f_inv(ob)   first_inventory(ob)
#define flfun(a,b)  function_exists(a,b)
#define i_list(ob)  inherit_list(ob)
#define in_alist(a,b,c) insert_alist(a,b,c)
#define active(pl)  interactive(pl)
#define lcase(s)    lower_case(s)
#define moveme(d)   move_object(this_object(),d)
#define n_inv(ob)   next_inventory(ob)
#define o_alist(l)  order_alist(l)
#define pstring(s)  process_string(s)
#define idle(ob)    query_idle(ob)
#define ipname(ob)  query_ip_name(ob)
#define ipnr(ob)    query_ip_number(ob)
#define setb(a,b)   set_bit(a,b)
#define tstb(a,b)   set_bit(a,b)
#define r_alist(a,b) remove_alist(a,b)

inherit "/lib/string";

#define srepl(a,b,c) string_replace(a,b,c)

inherit "/players/mateese/obj/lpdlib";

#define set(n,v) demon->set_var(n,v)
#define get(n) demon->get_var(n)
#define del(n) demon->rm_var(n)
