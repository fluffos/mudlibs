




















































































































































































































































































































# 7 "std.h" 2

# 1 "portability.h" 1
























































































































































































































# 225 "portability.h"






# 243 "portability.h"


























# 278 "portability.h"


















# 8 "std.h" 2

# 1 "macros.h" 1
























# 36 "macros.h"













































# 93 "macros.h"


# 107 "macros.h"


# 1 "malloc.h" 1

















# 30 "malloc.h"

















# 109 "macros.h" 2








































































































# 224 "macros.h"


















# 9 "std.h" 2










# 2 "func_spec.c" 2


# 1 "op_spec.c" 1





operator pop_value;

operator number, real, byte, nbyte, string, short_string, const0, const1;

operator index, rindex, nn_range, rn_range, rr_range, nr_range, ne_range, re_range;
operator aggregate, aggregate_assoc;







operator branch_when_zero, branch_when_non_zero, branch;
operator bbranch_when_zero, bbranch_when_non_zero, bbranch;

operator loop_cond;
operator loop_incr;
operator while_dec;

operator lor, land;

operator catch, end_catch;
operator time_expression, end_time_expression;

operator switch, break, pop_break;

operator call_function_by_address, call_inherited, return;

operator eq, ne, le, lt, ge, gt;

operator inc, dec, pre_inc, post_inc, pre_dec, post_dec;

operator local, global;
operator local_lvalue, global_lvalue;
operator index_lvalue, rindex_lvalue;

operator add, void_add_eq, add_eq;
operator subtract, sub_eq;
operator multiply, mult_eq;
operator divide, div_eq;
operator mod, mod_eq;
operator not;
operator and, and_eq;
operator or, or_eq;
operator xor, xor_eq;
operator lsh, lsh_eq, rsh, rsh_eq;
operator negate, compl;

operator assign, void_assign;

operator function_constructor;



operator simul_efun;

operator sscanf;
operator parse_command;

operator nn_range_lvalue, rn_range_lvalue, nr_range_lvalue, rr_range_lvalue;
operator call_extra;
# 4 "func_spec.c" 2




















unknown call_other(object | string | object *, string | mixed *,...);

unknown evaluate(mixed, ...);
unknown apply(mixed, mixed *);
function bind(function, object);

object present(object | string, void | object);
object this_object();
object this_player(int default: F_CONST0);
object this_interactive this_player( int default: F_CONST1 );
object new(string, ...);
object clone_object new(string, ...);
void move_object(object | string, void | object | string);
mixed previous_object(int default: F_CONST0);
object *all_previous_objects previous_object(int default: F_NBYTE 1);
int sizeof(mixed);
int strlen sizeof(string);
int destruct(object);
string file_name(object default:F_THIS_OBJECT);
object environment(void | object);
string capitalize(string);
string *explode(string, string);
string implode(string *, string);
object *all_inventory(object default:F_THIS_OBJECT);
object first_inventory(object|string default: F_THIS_OBJECT);
object next_inventory(object default: F_THIS_OBJECT);
void call_out(string | function, int,...);
int member_array(mixed, string | mixed *, void | int);
int input_to(string | function,...);
int random(int);


void add_action(string | function, string | string *, void | int);
string query_verb();
int command(string, void | object);
int remove_action(string, string);
int living(object);
mixed *commands();
void disable_commands();
void enable_commands();
void set_living_name(string);
object *livings();
object find_living(string);
object find_player(string);
int notify_fail(string | function);




string lower_case(string);
string replace_string(string, string, string,...);
int restore_object(string, void | int);
int save_object(string, void | int);
string save_variable(mixed);
mixed restore_variable(string);
object *users();
mixed *get_dir(string, int default:F_CONST0);
int strsrch(string, string | int, int default:F_CONST0);



void write(mixed);
void tell_object(object, string);
void say(string, void | object | object *);
void shout(string);
int receive(string);
void tell_room(object | string, string | object | int | float, void | object *);
void message(mixed, string, string | string * | object | object *,
	          void | object | object *);



    object find_object(string, int default: F_CONST0);
    object load_object find_object(string, int default: F_CONST1);
    int find_call_out(string);



    mapping allocate_mapping(int);
    void map_delete(mapping, mixed);
    mixed *values(mapping);
    mixed *keys(mapping);




    mixed match_path(mapping, string);



    int clonep(mixed default:F_THIS_OBJECT);
    int intp(mixed);
    int undefinedp(mixed);
    int nullp(mixed);
    int floatp(mixed);
    int stringp(mixed);
    int virtualp(object);
    int functionp(mixed);
    int pointerp(mixed);
    int arrayp pointerp(mixed);
    int objectp(mixed);
    int typeof(mixed);


    int bufferp(mixed);


    int inherits(string, object);
    void replace_program(string);


    buffer allocate_buffer(int);

    string *regexp(string *, string, void | int);
    mixed *reg_assoc(string, string *, mixed *, mixed | void);
    mixed *allocate(int);




    int to_int(string | float | int | buffer);
    float to_float(string | float | int);

    mixed *call_out_info();


    int crc32(string | buffer);




    mixed read_buffer(string | buffer, void | int, void | int);

    int write_file(string, string, void | int);
    int rename(string, string);
    int write_bytes(string, int, string);


    int write_buffer(string | buffer, int, string | buffer | int);

    int file_size(string);
    string read_bytes(string, void | int, void | int);
    string read_file(string, void | int, void | int);
    int cp(string, string);


    int link(string, string);

    int mkdir(string);
    int rm(string);
    void rmdir(string);



    string clear_bit(string, int);
    int test_bit(string, int);
    string set_bit(string, int);

    string crypt(string, string | int);	
    string ctime(int);
    int exec(object, object);
    mixed *localtime(int);
    string function_exists(string, object default:F_THIS_OBJECT);

    object *objects(void | string | function, void | object);
    string process_string(string);
    mixed process_value(string);
    string break_string(int | string, int, void | int | string);
    string query_host_name();
    int query_idle(object);
    string query_ip_name(void | object);
    string query_ip_number(void | object);
    object query_snoop(object);
    object query_snooping(object);
    int remove_call_out(string);
    int set_heart_beat(int);
    int query_heart_beat(object default:F_THIS_OBJECT);
    void set_hide(int);





    void set_reset(object, void | int);


    object shadow(object, int default: F_CONST1);
    object query_shadowing(object);

    object snoop(object, void | object);
    mixed *sort_array(mixed *, int | string | function, void | object | string);
    void tail(string);
    void throw(mixed);
    int time();
    mixed *unique_array(mixed *, string | function, void | mixed);
    mapping unique_mapping(mixed *, string | function, string | object | void, ...);
    string *deep_inherit_list(object default:F_THIS_OBJECT);
    string *inherit_list(object default:F_THIS_OBJECT);
    void printf(string,...);
    string sprintf(string,...);
    int mapp(mixed);
    mixed *stat(string, int default:F_CONST0);




    int interactive(object default:F_THIS_OBJECT);
    string in_edit(object default:F_THIS_OBJECT);
    int in_input(object default:F_THIS_OBJECT);
    int userp(object);


    void enable_wizard();
    void disable_wizard();
    int wizardp(object);


    object master();





# 1 "packages/mudlib_stats.spec" 1

    package mudlib_stats;

    mapping domain_stats(void | string);
    void set_author(string);
    mapping author_stats(void | string);

# 247 "func_spec.c" 2


    int memory_info(object | void);
    mixed get_config(int);



# 1 "packages/uids.spec" 1
package uids;

int export_uid(object);
string geteuid(function | object default:F_THIS_OBJECT);
string getuid(object default:F_THIS_OBJECT);
int seteuid(string | int);
# 254 "func_spec.c" 2









    void get_char(string | function,...);
    object *children(string);

    void reload_object(object);


# 1 "packages/sockets.spec" 1
package sockets;




    int socket_create(int, string, string | void);
    int socket_bind(int, int);
    int socket_listen(int, string);
    int socket_accept(int, string, string);
    int socket_connect(int, string, string, string);
    int socket_write(int, mixed, string | void);
    int socket_close(int);
    int socket_release(int, object, string);
    int socket_acquire(int, string, string, string);
    string socket_error(int);
    string socket_address(int | object);
    void dump_socket_status();
# 269 "func_spec.c" 2



    void error(string);
    int errorp(mixed);
    int uptime();
    int strcmp(string, string);


    mapping rusage();



    void ed(string | void, string | void, string | int | void, int | void);







# 1 "packages/math.spec" 1
package math;

    float cos(float);
    float sin(float);
    float tan(float);
    float asin(float);
    float acos(float);
    float atan(float);
    float sqrt(float);
    float log(float);
    float pow(float, float);
    float exp(float);
    float floor(float);
    float ceil(float);

# 290 "func_spec.c" 2








    void cache_stats();


    object *deep_inventory(object);









    mixed filter(mixed * | mapping, string | function, object | string | void, ...);
    mixed filter_array filter(mixed *, string | function, void | object | string, ...);
    mapping filter_mapping filter(mapping, string | function, object | string | void, ...);

    mixed map(string | mapping | mixed *, string | function, object | string | void, ...);
    mapping map_mapping map(mapping, string | function, object | string | void, ...);
    mixed *map_array map(mixed *, string | function, object | string | void, ...);



    void malloc_status();
    void mud_status(int default:F_CONST0);
    void dumpallobj(string | void);

    void dump_file_descriptors();
    string query_load_average();



    int set_light(int);


    int origin();



    int reclaim_objects();

    void set_eval_limit(int);
    void reset_eval_cost set_eval_limit(int default: F_CONST0);
    int eval_cost set_eval_limit(int default: F_NBYTE 1);
    int max_eval_cost set_eval_limit(int default: F_CONST1);
























# 1 "packages/develop.spec" 1
package develop;

    mixed debug_info(int, object);
    int refs(mixed);




    void dump_prog(object,...);




















# 367 "func_spec.c" 2













    int resolve(string, string);


    void shutdown(void | int);
