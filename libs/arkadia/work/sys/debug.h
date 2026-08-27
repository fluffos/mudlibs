/*
 *  Kilka przydatnych funkcji przydatnych podczas debugowania i przy
 *  tworzeniu logow.
 *
 *  /sys/debug.h
 *
 *  dzielo Silvathraeca 1997
 */

#ifndef DEBUG_DEF
#define DEBUG_DEF

#define DEBUG_FILE "/sys/global/debug"

/*
 * DEBUG_CFUNS     - Tablica calling_function(x), calling_function(x-1), ...
 *
 * DEBUG_COBJS     - Tablica calling_object(x), calling_object(x-1), ...
 *
 * DEBUG_CPROGS    - Tablica calling_program(x), calling_program(x-1), ...
 *
 * DEBUG_POBJS     - Tablica previous_object(x), previous_object(x-1), ...
 *
 * DEBUG_CALLS     - Tablica ({CFUNS[0], COBJS[0], CPROGS[0]}), ...
 *
 * DEBUG_FMT_CALLS - DEBUG_CALLS sformatowane w formacie debugloga.
 */

#define DEBUG_CFUNS(x)   ((string *)DEBUG_FILE->calling_functions(x))
#define DEBUG_COBJS(x)   ((string *)DEBUG_FILE->calling_objects(x))
#define DEBUG_CPROGS(x)  ((string *)DEBUG_FILE->calling_programs(x))
#define DEBUG_POBJS(x)   ((string *)DEBUG_FILE->previous_objects(x))
#define DEBUG_CALLS(x)    ((mixed *)DEBUG_FILE->all_calling(x))
#define DEBUG_FMT_CALLS(x) ((string)DEBUG_FILE->format_all_calling(x))

/*
 * DEBUG_EVALOST   - Eval_cost aktualnego ciagu wywolan.
 */

#define DEBUG_EVALCOST	(find_object("/secure/master")->do_debug("get_eval_cost"))

/* Koniec definicji... */
#endif DEBUG_DEF
