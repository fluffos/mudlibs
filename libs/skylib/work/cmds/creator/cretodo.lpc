/**
 * Todo command for all cres, editable by lords.
 * @author Windy, March 2001.
 * @change Rewritten almost completely by Avelan, May 2002.
 */

#include <colors.h>

#define SAVEFILE "/save/todo_lists/cretodo.o"
#define MAX_DAYS 60

class todo_item {
    string taskname;
    string person;
    int priority;
    int time;
    int due;
    string description;
    string assignedby;
}

class completed_item {
    string taskname;
    string person;
    int time;
    string description;
}

mapping completed, tasks;

/** @ignore yes */
private void save_me() {
    unguarded( (: save_object, SAVEFILE :) );
} /* save_me() */

/** @ignore yes */
private void load_me() {
    if( file_size(SAVEFILE) > 0 )
        unguarded( (: restore_object, SAVEFILE :) );
} /* load_me() */

/** @ignore yes */
void create() {
    load_me();
    if( !mapp(tasks) )
        tasks = ([ ]);
    if( !mapp(completed) )
        completed = ([ ]);
} /* create() */

/** @ignore yes */
string get_priority( int num ) {
    if( num )
        switch( num ) {
            case 1: return "Very High";
            case 2: return "High";
            case 3: return "Normal";
            case 4: return "Low";
            case 5: return "Very Low";
        }
} /* get_priority() */

/** @ignore yes */
int check_valid_list( string list_name ) {
    if( member_array( list_name, keys(tasks) ) != -1 )
        return 1;
    return 0;
} /* check_valid_list() */

/** @ignore yes */
int check_valid_task( string task_name, string list_name ) {
    if( !sizeof(tasks[list_name]) )
        return 0;

    foreach( class todo_item item in tasks[list_name] )
        if( item->taskname == task_name )
            return 1;

    return 0;

} /* check_valid_task() */

/** @ignore yes */
int create_list( string list_name ) {
    if( !lordp(TP) ) {
        add_failed_mess("Sorry, only lords and above may create new "
            "lists.\n");
        return 0;
    }

    if( !list_name || list_name == "" ) {
        add_failed_mess("No list name defined.\n");
        return 0;
    }

    list_name = lower_case(list_name);

    if( check_valid_list( list_name ) ) {
        add_failed_mess("A list called "+CAP(list_name)+" already exists.\n");
        return 0;
    }

    tasks[list_name] = ({ });
    completed[list_name] = ({ });
    save_me();

    write("Created "+CAP(list_name)+" todo list.\n");
    return 1;

} /* create_list() */

/** @ignore yes */
int remove_list( string list_name ) {
    if( !adminp(TP) ) {
        add_failed_mess("Sorry, only the admin can remove todo lists.\n");
        return 0;
    }

    list_name = lower_case(list_name);

    if( !check_valid_list(list_name) ) {
        add_failed_mess("A list called "+CAP(list_name)+" doesn't exist.\n");
        return 0;
    }

    map_delete( tasks, list_name );

    if( !sizeof( completed[list_name] ) )
        map_delete( completed, list_name );

    save_me();

    tell_object( TP, "Removed the "+CAP(list_name)+" list.\n");
    return 1;

} /* remove_list() */

/** @ignore yes */
int remove_task( string task_name, string list_name ) {
    if( !lordp(TP) ) {
        add_failed_mess("Sorry, only lords and above may remove tasks.\n");
        return 0;
    }

    list_name = lower_case(list_name);

    if( !check_valid_list(list_name) ) {
        add_failed_mess("A list called "+CAP(list_name)+" doesn't exist.\n");
        return 0;
    }

    task_name = lower_case(task_name);

    if( !check_valid_task( task_name, list_name ) ) {
        add_failed_mess("There is no task called "+CAP(task_name)+
            " on the "+CAP(list_name)+" list.\n");
        return 0;
    }

    foreach( class todo_item item in tasks[list_name] ) {
        if( item->taskname == task_name ) {
            tasks[list_name] -= ({ item });
            break;
        }
    }

    save_me();

    tell_object( TP, "Removed the task called "+CAP(task_name)+" from the "+
        CAP(list_name)+" list.\n");
    return 1;

} /* remove_task() */

/** @ignore yes */
int complete_task( string task_name, string list_name ) {
    if( !lordp(TP) ) {
        add_failed_mess("Sorry, only lords and above may mark tasks as "
            "completed.\n");
        return 0;
    }

    list_name = lower_case(list_name);

    if( !check_valid_list( list_name ) ) {
        add_failed_mess("A list called "+CAP(list_name)+" doesn't exist.\n");
        return 0;
    }

    task_name = lower_case(task_name);

    if( !check_valid_task( task_name, list_name ) ) {
        add_failed_mess("There is no task called "+CAP(task_name)+" on the "+
            CAP(list_name)+" list.\n");
        return 0;
    }

    foreach( class todo_item item in tasks[list_name] ) {
        if( item->taskname == task_name ) {
            completed[list_name] += ({ new( class completed_item,
                taskname : task_name,
                person : item->person,
                time : time(),
                description : item->description ) });
            tasks[list_name] -= ({ item });
        }
    }

    save_me();

    tell_object( TP, "Marked the task called "+CAP(task_name)+" as completed "
        "on the "+CAP(list_name)+" list.\n");
    return 1;

} /* complete_task() */

/** @ignore yes */
int disp_lists() {
    string ret;

    if( !sizeof(keys(tasks)) ) {
        add_failed_mess("No lists available.\n");
        return 0;
    }

    ret = "Todo lists for creators:\n\n"+
        implode( map( sort_array( keys(tasks), 1 ), (: "\t"+CAP($1) :) ),
            "\n")+"\n\nTotal lists: "+sizeof(keys(tasks))+"\n";

    TP->more_string(ret);
    return 1;

} /* disp_lists() */

/** @ignore yes */
string print_completed( int cols, string list, class completed_item item ) {
    return "List        : "+CAP(list)+"\n"
           "Task        : "+CAP(item->taskname)+"\n"
           "Completed   : "+ctime(item->time)+"\n"
           "Description :\n"+indent( item->description, 14, cols )+"\n\n";
} /* print_completed() */

/** @ignore yes */
int list_completed( string person ) {
    string ret, list;
    int amt, cols;
    class completed_item item;

    if( !person || person == "" ) {
        add_failed_mess("Who do you want to list the completed tasks for?\n");
        return 0;
    }

    person = lower_case(person);

    if( !rank(person) ) {
        add_failed_mess("There is no such player - "+CAP(person)+".\n");
        return 0;
    }

    if( !sizeof(keys(completed) ) ) {
        add_failed_mess("There are no completed tasks on any list.\n");
        return 0;
    }

    cols = (int)TP->query_cols();
    ret = sprintf("%s completed the following tasks:\n%|*'-'s\n",
        CAP( person == TP->query_name() ? "You have" : person+" has"),
        cols-1, "");

    foreach( list in keys(completed) ) {
        foreach( item in completed[list] ) {
            if( item->person == person ) {
                ret += print_completed( cols, list, item );
                ret += sprintf("%|*'-'s\n", cols-1, "");
                amt++;
            }
        }
    }

    if( !amt ) {
        write( ( person == TP->query_name() ? "You have" :
        CAP(person)+" has")+" not completed any tasks.\n");
        return 1;
    }

    ret += "Total completed : "+amt+"\n";
    TP->more_string(ret);
    return 1;

} /* list_completed() */

/** @ignore yes */
string print_task( int cols, string list, class todo_item item ) {
    return "List        : "+CAP(list)+"\n"
           "Task        : "+CAP(item->taskname)+"\n"
           "Assigned by : "+ctime(item->time)+" by "+CAP(item->assignedby)+"\n"
           "Assigned to : "+CAP(item->person)+"\n"
           "Priority    : "+get_priority(item->priority)+"\n"
           "Due on      : "+ctime(item->due)+( item->due > time() ? "" :
                          "(NOT COMPLETED IN TIME)")+"\n"
           "Description : "+indent( item->description, 14, cols )[14..]+"\n";
} /* print_task() */

/** @ignore yes */
int disp_list( string list_name ) {
    string ret;
    int amt, cols;

    list_name = lower_case(list_name);

    if( !check_valid_list(list_name) ) {
        add_failed_mess("A list called "+CAP(list_name)+" doesn't exist.\n");
        return 0;
    }

    if( !sizeof(tasks[list_name] ) ) {
        add_failed_mess("The "+CAP(list_name)+" list doesn't contain any "
            "tasks.\n");
        return 0;
    }

    cols = (int)TP->query_cols();
    ret = sprintf("%s todo list:\n%|*'-'s\n", CAP(list_name), cols-1, "");

    foreach( class todo_item item in tasks[list_name] ) {
        ret += print_task( cols, list_name, item );
        ret += sprintf("%|*'-'s\n", cols-1, "");
        amt++;
    }

    ret += "Total tasks : "+amt+"\n";
    TP->more_string(ret);
    return 1;

} /* disp_list() */

/** @ignore yes */
int disp_tasks( string person ) {
    string ret, list;
    int amt, cols;
    class todo_item item;

    if( !person || person == "" ) {
        add_failed_mess("Who do you want to list the tasks for?\n");
        return 0;
    }

    person = lower_case(person);

    if( !rank(person) ) {
        add_failed_mess("There is no such player - "+CAP(person)+".\n");
        return 0;
    }

    if( !sizeof(keys(tasks) ) ) {
        add_failed_mess("There are no active tasks on any list.\n");
        return 0;
    }

    cols = (int)TP->query_cols();
    ret = sprintf("The following tasks have been assigned to %s:\n%|*'-'s\n",
        ( person == TP->query_name() ? "you" : CAP(person) ), cols-1, "");

    foreach( list in keys(tasks) ) {
        foreach( item in tasks[list] ) {
            if( item->person == person ) {
                ret += print_task( cols, list, item );
                ret += sprintf("%|*'-'s\n", cols-1, "");
                amt++;
            }
        }
    }

    if( !amt ) {
        write("No tasks have been assigned to "+( person == TP->query_name() ?
            "you" : CAP(person) )+".\n");
        return 1;
    }

    ret += "Total tasks : "+amt+"\n";
    TP->more_string(ret);
    return 1;

} /* disp_tasks() */

/** @ignore yes */
private void add_list_item( string list, class todo_item item ) {

    tasks[list] += ({ item });

    tell_object( TP, "Added a task called "+CAP(item->taskname)+" to the "+
        CAP(list)+" list.\n");

    if( item->person != TP->query_name() ) {
        TCRE( item->person, GREEN+TP->query_cap_name()+" assigned you a task "
            "called "+CAP(item->taskname)+" on the "+CAP(list)+" list."+
            RESET+"\n");
    }

    save_me();

} /* add_list_item() */

/** @ignore yes */
void finish_add_task( string str, mixed data ) {
    class todo_item item;
    string list;

    if( !lordp(TP) ) {
        tell_object( TP, "Sorry, only lords and above may add tasks.\n");
        return;
    }

    if( !str || str == "" ) {
        tell_object( TP, "No task description.  Aborting...\n");
        return;
    }

    list = data[0];
    item = data[1];

    if( !list || list == "" || !classp(item) ) {
        tell_object( TP, "Oops, something has gone wrong.  Aborting...\n");
        return;
    }

    item->assignedby = TP->query_name();
    item->description = str;
    return add_list_item( list, item );

} /* finish_add_task() */

/** @ignore yes */
private void set_deadline( mixed due, string list, class todo_item item ) {
    if( due == "q" || due == "Q" ) {
        tell_object( TP, "Aborting...\n");
        return;
    }

    due = to_int(due);

    if( due < 1 || due > MAX_DAYS ) {
        tell_object( TP, "The deadline of the task must be between 1 and "+
            MAX_DAYS+".\n] ");
        input_to( (: set_deadline :), list, item );
        return;
    }

    item->time = time();
    item->due = time() + ( due * 24 * 60 * 60 );
    item->description = "";

    tell_object( TP, "Please edit the description of the task.\n");
    TP->do_edit( 0, (: finish_add_task :), 0, 0, ({ list, item }) );

} /* set_deadline() */

/** @ignore yes */
private void set_priority( mixed priority, string list, class todo_item item ) {
    if( priority == "q" || priority == "Q" ) {
        tell_object( TP, "Aborting...\n");
        return;
    }

    priority = to_int(priority);

    if( priority < 1 || priority > 5 ) {
        tell_object( TP, "The priority must be between 1 and 5.\n] ");
        input_to( (: set_priority :), list, item );
        return;
    }

    item->priority = priority;
    tell_object( TP, "Please enter the number of days the task must be "
        "completed in, or 'q' to quit: ");
    input_to( (: set_deadline :), list, item );

} /* set_priority() */

/** @ignore yes */
void set_creator( string cre, string list, class todo_item item ) {
    cre = lower_case(cre);

    if( cre == "q" ) {
        tell_object( TP, "Aborting...\n");
        return;
    }

    if( !cre || !rank(cre) ) {
        tell_object( TP, "No such player - "+CAP(cre)+".\n] ");
        input_to( (: set_creator :), list, item );
        return;
    }

    if( !creatorp(cre) ) {
        tell_object( TP, CAP(cre)+" is not a creator.\n] ");
        input_to( (: set_creator :), list, item );
        return;
    }

    item->person = cre;
    tell_object( TP, "Please enter the priority level of the task (1-5), "
        "or 'q' to quit: ");
    input_to( (: set_priority :), list, item );

} /* set_creator() */

/** @ignore yes */
private void set_name( string name, string list ) {
    class todo_item item;

    if( name == "q" || name == "Q" ) {
        tell_object( TP, "Aborting...\n");
        return;
    }

    if( !name || name == "" ) {
        tell_object( TP, "You must enter a name for the task.\n] ");
        input_to( (: set_name :), list );
        return;
    }

    foreach( item in tasks[list] ) {
        if( item->taskname == name ) {
            tell_object( TP, "A task called \""+name+"\" already exists on "
                "the "+list+" list, please choose another name.\n] ");
            input_to( (: set_name :), list );
            return;
        }
    }

    item = new( class todo_item, taskname : name );
    tell_object( TP, "Please enter the name of the creator to "
        "assign the task to, or 'q' to quit: ");
    input_to( (: set_creator :), list, item );

} /* set_name() */

/** @ignore yes */
private void set_list( string list ) {
    if( list == "q" || list == "Q" ) {
        tell_object( TP, "Aborting...\n");
        return;
    }

    if( !check_valid_list(list) ) {
        tell_object( TP, "There is no list by the name \""+list+"\".\n] ");
        input_to( (: set_list :) );
        return;
    }

    tell_object( TP, "Please enter the name of the new task, or 'q' to "
        "quit: ");
    input_to( (: set_name :), list );

} /* set_list() */

/** @ignore yes */
private int cmd() {
    if( !lordp(TP) ) {
        tell_object( TP, "Sorry, only lords and above may add tasks.\n");
        return 1;
    }

    tell_object( TP, "Please enter the name of the list to add the task to, "
        "or 'q' to quit: ");
    input_to( (: set_list :) );
    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({
        "add list <word'name'>",(: create_list( $4[0] ) :),
        "add task", (: cmd :),
        "list <word'list name'>",(: disp_list( $4[0] ) :),
        "remove list <word'name'>",(: remove_list( $4[0] ) :),
        "remove task <word'task'> from <word'list'>",
        (: remove_task( $4[0], $4[1] ) :),
        "complete task <word'task'> on <word'list'>",
        (: complete_task( $4[0], $4[1] ) :),
        "list", (: disp_lists() :),
        "list my tasks", (: disp_tasks( TP->query_name() ) :),
        "list <word'person'>", (: disp_tasks( $4[0] ) :),
        "list tasks <word'person'>", (: disp_tasks( $4[0] ) :),
        "list completed <word'person'>", (: list_completed( $4[0] ) :),
    });
} /* query_patterns() */
