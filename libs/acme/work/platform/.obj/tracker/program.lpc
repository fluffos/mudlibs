/**
 * A module for tracking programs, their clones and blueprints.
 *
 * @author devo@eotl
 * @alias ProgramTracker
 */
#pragma no_clone
#include <sys/objectinfo.h>
#include <sql.h>

inherit SqlMixin;

private inherit ProgramLib;
private inherit ArrayLib;

#define PROGRAM_TABLE     "program"
#define PROGRAM_ID        "program_id"
#define PROGRAM_NAME      "program_name"
#define PROGRAM_TIME      "program_time"
#define PROGRAM_SIZE      "program_size"

// program_id = "program_name#program_time3program_count"
// ([ str program_id : ProgramInfo info ])
private mapping programs;
// ([ str program_name : ({ str program_id }) ])
private mapping program_names;
// ([ obj ob : str program_id ])
private mapping object_map;
private int program_counter;

public void setup();
protected string get_id(string program_name, int program_time,
                        int program_count);
public string new_program(object blueprint);
public string program_cloned(object clone);
public mapping query_program_ids(string program_name);
public string query_program_id(object ob);
public int query_program_count(string id);
public mapping query_clones(string program_id);

/**
 * Setup the ProgramTracker.
 */
public void setup() {
  SqlMixin::setup();
  SqlMixin::table_info(PROGRAM_TABLE, (:
    if (!$1) {
      SqlMixin::create_table(PROGRAM_TABLE, mapping_array(
        ({ SQL_COL_NAME, SQL_COL_TYPE, SQL_COL_FLAGS, SQL_COL_DEFAULT }),
        ({ 
           ({ SQL_ID_COLUMN, SQL_TYPE_INTEGER, 
              SQL_FLAG_PRIMARY_KEY|SQL_FLAG_AUTOINCREMENT }),
           ({ PROGRAM_ID, SQL_TYPE_TEXT, SQL_FLAG_UNIQUE }),
           ({ PROGRAM_NAME, SQL_TYPE_TEXT }),
           ({ PROGRAM_TIME, SQL_TYPE_INTEGER }),
           ({ PROGRAM_SIZE, SQL_TYPE_INTEGER })
        })
      ));
    }
    return;
  :));
  programs = ([ ]);
  program_names = ([ ]);
  object_map = ([ ]);
  // TODO retroactively track existing programs/clones from objdump
}

/**
 * Get a program id its constitutent components.
 * 
 * @param  program_name  the program name
 * @param  program_time  the program time
 * @param  program_count the program count
 * @return the program id
 */
protected string get_id(string program_name, int program_time, 
                        int program_count) {
  return sprintf("%s#%d#%d", program_name, program_time, program_count);
}

/**
 * Invoked by the HookService when a new blueprint is created.
 * 
 * @param  blueprint     the blueprint being created
 * @return the blueprint's program id
 */
public string new_program(object blueprint) {
  string program_name = program_name(blueprint);
  int program_time = program_time(blueprint);
  int program_count = ++program_counter;
  string id = get_id(program_name, program_time, program_count);

  programs[id] = (<ProgramInfo> 
    id: id,
    blueprint: blueprint,
    clones: ([ ]),
    program_count: program_count
  ); 
  if (!member(program_names, program_name)) {
    program_names[program_name] = ({ });
  }
  program_names[program_name] += ({ id });
  object_map[blueprint] = id;

  mapping pdata = ([ 
    PROGRAM_ID : id,
    PROGRAM_NAME : program_name,
    PROGRAM_TIME : program_time,
    PROGRAM_SIZE : object_info(blueprint, OINFO_MEMORY, OIM_PROG_SIZE)
  ]);
  SqlMixin::insert(PROGRAM_TABLE, pdata);

  return id;
}

/**
 * Invoked by the HookService when a new clone is created.
 * 
 * @param  clone         the clone object
 * @return the program id of the clone
 */
public string program_cloned(object clone) {  
  string id = program_names[program_name(clone)][<1];
  m_add(programs[id]->clones, clone); 
  object_map[clone] = id;
  return id;
}

/**
 * Get a list of all known program names.
 * 
 * @return an unsorted list of all known program names
 */
public string *query_program_names() {
  return m_indices(program_names);
}

/**
 * Get a collection of known program ids for a given program name.
 * 
 * @param  program_name  the program name
 * @return a zero-width mapping of program ids from program 
 */
public mapping query_program_ids(string program_name) {
  return program_names[program_name];
}

/**
 * Get the program id of an object.
 * 
 * @param  ob            the object being queried
 * @return the program of the object
 */
public string query_program_id(object ob) {
  if (!ob) {
    return 0;
  }
  return object_map[ob];
}

/**
 * Get the program count portion of a program id.
 * 
 * @param  id            the program id
 * @return the program count
 */
public int query_program_count(string id) {
  if (!member(programs, id)) {
    return 0;
  }
  return programs[id]->program_count;
}

/**
 * Get a collection of all the clones for a given program id.
 * 
 * @param  program_id    the program id being queried
 * @return a zero-width mapping of clones from the given program
 */
public mapping query_clones(string program_id) {
  if (member(programs, program_id)) {
    programs[program_id]->clones -= ([ 0 ]);
    return programs[program_id]->clones;
  }
  return 0;
}

/**
 * Constructor.
 */
public void create() {
  setup();
}

