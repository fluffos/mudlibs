/**
 * A creator/project management handler for Lords. This handler tracks
 * projects and creators.
 *
 * This handler is currently under development, please do not use!
 *
 * @author Ceres
 */

#define SAVE_FILE "/save/projects/"

/**
 * This class is used to store notes about a given project.
 */
class note {
  string author;
  int date;
  string contents;
}

/**
 * This class is the project itself.
 */
class project {
  string name;
  string description;
  class note *notes;

  int target_completion_date;
  int estimated_completion_date;

  string progress_so_far;

  int date_started;
  int date_completed;

  string *assigned_to;
}

/**
 * This class stores information about which creators are working on which
 * projects and which projects they have completed.
 */
class creator {
  string *completed_projects;
  int *projects_in_progress;
  class note *notes;
}

mapping projects;
mapping creators;
mapping projects_in_progress;
int pid, nid;

nosave string current_domain;

private void save_file(string domain);
private void load_file(string domain);

/**
 * @ignore yes
 */
void create() {
  projects = ([ ]);
  creators = ([ ]);
  projects_in_progress = ([ ]);
  pid = 0;
  nid = 0;
}

/*****************************************************************************
 * Lord functions.
 *
 * These functions are used by the lord of the domain for management purposes.
 *****************************************************************************/
/**
 * Create a new project.
 *
 * @param domain The domain this project belongs in.
 * @param name The name of the project.
 * @param description A description of the project.
 *
 * @return int
 */
int create_project(string domain, string name, string desc) {
  class project tmp;

  load_file(domain);
  
  if(projects[name])
    return 0;

  tmp = new(class project,
            name: name,
            description: desc,
            notes : ({ }),
            target_completion_date : 0,
            estimated_completion_date : 0,
            progress_so_far : 0,
            date_started : 0,
            date_completed : 0,
            assigned_to : ({ }) );
  projects[pid++] = tmp;

  save_file(domain);
  
  return 1;
}

/**
 * Delete a project
 *
 * @param domain The domain this project belongs in.
 * @param pid The id of the project.
 *
 * @return int
 */
int delete_project(string domain, int pid) {
  string cre;
  
  load_file(domain);
  
  if(!projects[pid])
    return 0;

  foreach(cre in projects[pid]->assigned_to) {
    creators[cre]->projects_in_progress -= ({ pid });
  }
  
  map_delete(projects, pid);
  save_file(domain);
  
  return 1;
}

/**
 * Set the target completion date for a project.
 *
 * @param domain The domain this project belongs in.
 * @param pid The project id (this must be unique within a domain).
 * @param date The target completion date.
 *
 * @return int
 */
int set_target_date(string domain, int pid, int date) {

  load_file(domain);
  
  if(projects[pid])
    return 0;

  projects[pid]->target_completion_date = date;
  save_file(domain);
  
  return 1;
}

/**
 * Set the date a project was started or assigned to a creator.
 *
 * @param domain The domain this project belongs in.
 * @param pid The id of the project.
 * @param date The start date.
 *
 * @return int
 */
int set_start_date(string domain, int pid, int date) {

  load_file(domain);
  
  if(projects[pid])
    return 0;

  projects[pid]->date_started = date;
  save_file(domain);
  
  return 1;
}

/**
 * Assign a project to a creator (or creators).
 *
 * @param domain The domain this project belongs in.
 * @param pid The id of the project.
 * @param date The creators assigned.
 *
 * @return int
 */
int set_assigned_to(string domain, int pid, string *assigned) {
  string who;
  
  load_file(domain);
  
  if(!projects[pid])
    return 0;

  projects[pid]->assigned_to = assigned;

  foreach(who in assigned) {
    if(!creators[who])
      creators[who] = new(class creator,
                          completed_projects : ({ }),
                          projects_in_progress : ({ pid }));
    else if(member_array(pid, creators[who]->projects_in_progress) == -1)
      creators[who]->projects_in_progress += ({ pid });
  }
  
  save_file(domain);
  
  return 1;
}

/**
 * Mark a project as completed.
 *
 * @param domain The domain this project belongs in.
 * @param pid The id of the project.
 *
 * @return int
 */
int set_completed(string domain, int pid) {
  string who;
  int pos;
  
  load_file(domain);
  
  if(projects[pid])
    return 0;

  projects[pid]->date_completed = time();

  foreach(who in projects[pid]->assigned_to) {
    if(creators[who]) {
      // Remove the project from the creators in progress list.
      pos = member_array(pid, creators[who]->projects_in_progress);
      if(pos != -1)
        creators[who]->projects_in_progress =
          creators[who]->projects_in_progress[0..pos-1] +
          creators[who]->projects_in_progress[pos..];

      // Add it to their completed list.
      creators[who]->completed_projects += ({ pid });
    }
  }
  save_file(domain);
  
  return 1;
}

/*****************************************************************************
 * Creator functions.
 *
 * These functions are used by the creators assigned to projects to report and
 * record their progress.
 *****************************************************************************/
/**
 * Set the currently estimated completion date for a project.
 *
 * @param domain The domain this project belongs in.
 * @param pid The id of the project.
 * @param date The estimated completion date.
 *
 * @return int
 */
int set_estimated_date(string domain, int pid, int date) {

  load_file(domain);
  
  if(!projects[pid])
    return 0;

  projects[pid]->estimated_completion_date = date;
  save_file(domain);
  
  return 1;
}

/**
 * Set the progress for far for a project. This may be a date, a percentage
 * completion or even an estimate of work left, which it is will be determined
 * by the creator and/or lord.
 *
 * @param domain The domain this project belongs in.
 * @param pid The id of the project.
 * @param date The progress so far.
 *
 * @return int
 */
int set_progress(string domain, int pid, string progress) {

  load_file(domain);
  
  if(!projects[pid])
    return 0;

  projects[pid]->progress_so_far = progress;
  save_file(domain);
  
  return 1;
}

/*****************************************************************************
 * Creator & Lord functions.
 *
 * These functions are used by the lord of the domain or by the creator
 * assigned to a project..
 *****************************************************************************/
/**
 * Add a note to a project.
 *
 * @param domain The domain this project belongs in.
 * @param pid The id of the project.
 * @param author The author of the note.
 * @param note The note to be added.
 *
 * @return int
 */
int add_project_note(string domain, int pid, string author, string note) {
  class project tmp;
  
  load_file(domain);
  
  if(!projects[pid])
    return 0;

  tmp = projects[pid];
  
  tmp->notes += ({ new(class note,
                       author : author,
                       date : time(),
                       contents : note) });
  save_file(domain);
  
  return 1;
}

/*****************************************************************************
 * Reporting functions.
 *
 * These functions are used to report various information.
 *****************************************************************************/

string *query_projects(string domain, string creator) {
  string *names;
  int pid;
  
  load_file(domain);

  if(!creators[creator])
    return 0;

  names = ({ });
  foreach(pid in creators[creator]->projects_in_progress)
    names += ({ pid + ". " + projects[pid]->name });
}

string *query_all_projects(string domain, string creator) {
  string *names;
  int pid;
  
  load_file(domain);

  names = ({ });
  foreach(pid in keys(projects))
    names += ({ pid + ". " + projects[pid]->name });

  return names;
}

/*****************************************************************************
 * Utility functions.
 *
 * These functions are used internally by the handler to perform various tasks.
 *****************************************************************************/
/**
 * @ignore yes
 */
private void load_file(string domain) {
  if(domain == current_domain)
    return;
  
  if (file_size(SAVE_FILE+domain+".o") > 0)
    unguarded((: restore_object, SAVE_FILE+domain :));

  current_domain = domain;
}

/**
 * @ignore yes
 */
private void save_file(string domain) {
  unguarded((: save_object, SAVE_FILE+domain :));
}

void print_info(string domain) {
  load_file(domain);

  printf("Creators:%O\nProjects:%O", creators, projects);
}
