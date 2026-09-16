#ifndef __SIMUL_EFUN_H__
#define __SIMUL_EFUN_H__

// File: array.c
varargs mixed *slice(mixed *arr, int start, int end);
varargs int in_array(mixed needle, mixed *haystack, function f);
varargs mixed *distinct_array(mixed *arr, int same_order);
mixed *uniq_array(mixed *arr);
varargs mixed *remove_array_element(mixed *arr, int start, int end);
varargs mixed *merge_arrays(mixed *array, mixed *new_array, int at);
varargs mixed *splice(mixed *arr, int start, int delete_count, mixed *items_to_add);
varargs mixed* reverse_array(mixed *elements, int in_place);
mixed *shuffle_array(mixed *items);
int uniformp(mixed *arr, string type);
int sum_array(int *nums);
varargs mixed fill_array(mixed *arr, mixed value, int size, int start_index);
varargs mixed *pad_array(mixed *arr, int sz, mixed val);
varargs string array_columns(string *items, int col, int width);
string *sort_alpha(string *list);
int *sort_num(int *list);
float *sort_float(float *list);
string *reverse_sort_alpha(string *list);
int *reverse_sort_num(int *list);
float *reverse_sort_float(float *list);
varargs mixed *intersection(mixed *arr1, mixed *arr2, function f);
varargs int intersects(mixed *arr1, mixed *arr2, function f);
mixed pop(mixed ref *arr);
int push(mixed ref *arr, mixed value);
mixed shift(mixed ref *arr);
int unshift(mixed ref *arr, mixed value);
int set_push(mixed ref *arr, mixed value);
int set_unshift(mixed ref *arr, mixed value);
mixed eject(mixed ref *arr, int index);
varargs int eject_value(mixed ref *arr, mixed value);
varargs int eject_value_all(mixed ref *arr, mixed value);
mixed insert(mixed ref *arr, mixed value, int index);
mixed *flatten(mixed *arr);
varargs int find_index(mixed *arr, function fun, mixed extra...);
varargs mixed find(mixed *arr, function fun, mixed extra...);
int in_range(int index, mixed *arr);
varargs mixed eval_first(mixed *src, function fun, mixed extra...);
varargs mixed eval_last(mixed *src, function fun, mixed extra...);
int every(mixed *arr, mixed criteria);
int some(mixed *arr, mixed criteria);
varargs int includes(mixed *arr, mixed elem, function f);
varargs int same_array(mixed *one, mixed *two, int exact);
int same_array_precisely(mixed *one, mixed *two);
varargs mixed reduce(mixed *arr, function fun, mixed init, mixed arg...);
varargs void each(mixed src, function fun, mixed extra...);

// File: base64.c
string base64_encode(mixed source_str);
string base64_decode(string source);

// File: colour.c
string gradient_hex(string hex, int step);

// File: data.c
varargs mixed data_value(string file, string key, mixed def);
varargs void data_write(string file, string key, mixed data...);
varargs int data_inc(string file, string key, int inc);
int data_del(string file, string key);

// File: daemon.c
object body_d();

// File: description.c
string get_short(object ob);
string get_long(object ob);

// File: english.c
string cap_words(string str);
varargs string cap_significant_words(string str, int title);
string possessive_noun(mixed ob);
string possessive_pronoun(mixed ob);
string possessive(mixed ob);
string reflexive(mixed ob);
string objective(mixed ob);
string subjective(mixed ob);
string article_of(string str);
varargs string article(string str, int definite);
varargs string add_article(string str, int definite);
string remove_article(string str);
string number_word(int num);

// File: existence.c
int directory_exists(string dirname);
int file_exists(string file);
int cfile_exists(string file);
int ofile_exists(string file);
int user_exists(string user);

// File: file.c
int file_lines(string file);
int log_file(string file, string str);
int touch(string file);
string *dir_file(string path);
string *explode_file(string file);
string file_owner(string file);
varargs string query_file_name(object ob);
varargs string *valid_dir_file(string path, int file_too);
varargs string tail(string path, int line_count);
varargs string temp_file(mixed arg);
varargs void implode_file(string file, string *lines, int overwrite);
varargs mixed load_lpml(string file, string root);
mixed load_json(string file);
void assure_file(string file);
varargs string source_file(string path_and_file, string relative_to);
mapping as_directory(string str);
mapping as_file(string str);
varargs mapping read_directory(string directory, string pattern);
void recursive_delete(mapping dir, int include_self);
string resolve_path(string base_dir, string path);
string valid_path(string base_dir, string path);
string valid_file(string base_dir, string path);
string valid_dir(string base_dir, string path);
string resolve_file(string base_dir, string path);
string resolve_dir(string base_dir, string path);
string *get_files(string base_dir, string path);
int assure_dir(string path);
varargs string query_directory(object ob);

// File: function.c
int valid_function(mixed f);
mixed *assemble_call_back(mixed arg...);
mixed call_back(mixed *cb, mixed new_arg...);
async mixed async_call_back(mixed *cb, mixed new_arg...);
varargs mixed call_if(mixed ob, string func, mixed arg);
varargs int delay_act(string act, float delay, mixed *cb);
varargs string call_trace(int colour);
varargs void assert(mixed statement, string message);
void assert_arg(mixed condition, int arg_num, string message);
mixed pipe(mixed result, function *funcs...);

// File: grammar.c
string int_string (int num);
string ordinal (int n);

// File: identify.c
string identify(mixed arg);

// File: json.c
mixed json_decode(string str);
varargs string json_encode(mixed value, mixed* pointers);

// File: lpml.c
varargs mixed lpml_decode(string text, string path);
mixed lpml_encode(string text);

// File: mapping.c
string pretty_map(mapping map);
varargs mixed find_key(mapping map, mixed value, mixed arg...);
varargs mixed *find_keys(mapping map, mixed value, mixed arg...);
mixed dot_walk(mapping map, string path);

// File: messaging.c
varargs void tell_up(object ob, string str, int msg_type, mixed exclude);
varargs void tell_down(object ob, string str, int msg_type, mixed exclude);
varargs void tell_all(object ob, string str, int msg_type, mixed exclude);
varargs void tell_direct(object ob, string str, int msg_type, mixed exclude);
varargs void tell(object ob, string str, int msg_type, mixed exclude);
varargs void tell_me(string str, int message_type);
varargs void tell_them(string str, object *exclude, int message_type);

// File: number.c
float percent_of(float a, float b);
float percent(float a, float b);
float clamp(float val, float min, float max);
int clamped(float val, float min, float max);
int between(float val, float min, float max);
varargs float remainder(mixed a, mixed b);
int sum(mixed *arr);
int evaluate_number(int number, string condition);
float diminish(mixed val, mixed scale);
float dim_square_root(mixed val, mixed scale);
float dim_logarithmic(mixed val, mixed scale);
float dim_hyperbolic(mixed val, mixed scale);
float dim_exponential_decay(mixed val, mixed scale);
varargs float dim_sigmoid(mixed val, mixed scale, mixed k);

// File: object.c
int caller_is(mixed ob);
varargs int same_env_check(object ob1, object ob2, int top_env);
object *get_livings(mixed names, object room);
object *get_players(mixed names, object room);
object *present_clones(mixed file, object room);
object *present_livings(object room);
object *present_players(object room);
object *present_npcs(object room);
object get_living(string name, object room);
object get_player(string name, object room);
object this_body();
object this_caller();
varargs object get_object(string str, object player);
varargs object top_environment(object ob);
varargs object *all_environment(object ob);
varargs object *find_targets(object tp, string str, object env, function f);
varargs object find_target(object tp, string str, object env, function f);
varargs object *clones(mixed file, int env_only);
varargs mixed *accessible_objects(object container, object pov);
varargs object *accessible_objects_flat(object container, object pov);
string ob_short(object ob);
string ob_long(object ob);

// File: predicates.c
int alarmp(object ob);
int errorp(mixed input);
int pendingp(promise p);
int rejectedp(promise p);
int resolvedp(promise p);
int roomp(object ob);
int settledp(promise p);

// File: prompt.c
varargs void prompt_colour(object body, mixed *cb, string prompt);
void prompt_password(object user, int attempts, mixed *cb);

// File: random.c
int *prandom(int seed, int max);
mixed *prandom_float(mixed seed, float size);
int *prandom_clamp(int seed, int min, int max);
mixed *pelement_of(int seed, mixed *arr);
mixed *pelement_of_weighted(int seed, mapping weights);
float random_float(mixed upper_bound);
mixed element_of_weighted(mapping m);
int random_clamp(int min, int max);
int *sanitize_seed(mixed seed);

// File: save.c
string object_data_directory(object ob);
string object_data_file(object ob);
string assure_object_data_dir(object ob);

// File: security.c
int is_member(string user, string group);
int has_role(string user, string role);
string *get_roles(string user);
int adminp(mixed user);
varargs int ownerp(mixed user);
int devp(mixed user);
int wizardp(mixed user);
mixed run_as_caller(function f, mixed arg...);

// File: signal.c
varargs void emit(string sig, mixed arg...);
int slot(string sig, string func);
int unslot(string sig);

// File: string.c
string append(string source, string to_append);
string no_ansi(string str);
string prepend(string source, string to_prepend);
varargs string chop(string str, string sub, int dir);
varargs string extract(string str, int from, int to);
varargs string simple_list(mixed *arr, string conj);
varargs string substr(string str, string sub, int reverse);
varargs mixed from_string(string str, int flag);
string stringify(mixed val);
string add_commas(mixed number);
string reverse_string(string str);
varargs int reverse_strsrch(string str, string sub, int start);
varargs int pcre_strsrch(string str, string pattern, int start);
int colourp(string str);
string all_caps(string str);
int is_numeric(string str);
int starts_with(string str, string starting_string);
int ends_with(string str, string ending_string);
string sanitize_regex(string msg);
varargs string safe_string(string str, string replacement);

// File: system.c
int port();
object simul_efun();
mixed mud_config(string str);
string admin_email();
string arch();
string baselib_name();
string baselib_version();
string driver_version();
string lib_name();
string lib_version();
string mud_name();
string open_status();
varargs void debug(string str, mixed args...);
int boot_number();
string log_dir();
string tmp_dir();
varargs int _debug(mixed args...);
varargs int _ok(mixed args...);
varargs int _info(mixed args...);
varargs int _error(mixed args...);
varargs int _question(mixed args...);
varargs int _warn(mixed args...);

// File: time.c
varargs string ldate(int x, int brief);
varargs string ltime(int x, int brief);
int time_ms();
float time_frac(int nanoseconds);

// File: user.c
string user_data_file(string name);
string user_mob_data(string name);
string user_data_directory(string priv);
string home_path(string name);
string account_path(string name);
string account_file(string name);
int valid_account(string name);
int ghostp(object user);
int pcp(object user);
int npcp(object user);
varargs int valid_user(mixed user);

// File: util.c
string generate_uuid();
int of(mixed needle, mixed haystack);
int truthy(mixed val);
int falsy(mixed val);

#endif // __SIMUL_EFUN_H__
