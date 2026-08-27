/* Hamlet, March 1996.  -- This one gets rough with those manual pages. */

#include <man.h>

/* This one will store the directory structure as mappings within mappings.
   Will be used for the brousing system.
   The actual documents in the directory will be stored with an index
   of "." as an array.
*/
mapping directories;

/* This one will be of the form  "document" : "/where/to/find" for 
   specific queries.  If the document is the name of a directory,
   dir/README will be displayed.
*/
mapping files;

/* this is the same list as above, except the "full path" to
   the file is used as an index.
*/
mapping path_files;

/* This is used to keep work-in-progress during startup. */
string *todo;

void sort_manual_dirs();

void create() {
  seteuid("abxzyx");  /* Castration */
  directories = ([ ]);
  files = ([ ]);
  path_files = ([ ]);
  call_out("sort_manual_dirs",2);
}

/* The actual things that can be queried */

/* This should receive a docname either in the form  path/file or file. */
string get_doc_fname(string docname) {
  if(!docname || !strlen(docname))
    return "local/README";
    
  if(path_files[docname])
    return copy(path_files[docname]);
    
  return copy(files[docname]);
}

mapping get_doc_dir(string dirname) {
  string *tmp;
  mapping t;
  int i;
  
  if(!dirname || !strlen(dirname))
    return copy(directories);
    
  tmp = explode(dirname,"/");
  t = directories;
  
  for(i=0;i<sizeof(tmp);i++) {
    t = t[tmp[i]];
    if(!t)
      break;
  }
    
  return copy(t);
}

string *get_subdirs(string dirname) {
  mapping t;
  
  t = get_doc_dir(dirname);
  
  if(!t || !sizeof(t))
    return ({ });
    
  return (m_indices(t) - ({ "." }));
}

string *get_docs_in_dir(string dirname) {
  mapping t;
  
  t = get_doc_dir(dirname);
  
  if(!t || !sizeof(t))
    return ({ });
    
  return t["."];
}

/* Is the index currently being built? */
int doc_index_building() {
  if(!todo)
    return 1;
  if(!sizeof(todo))
    return 0;
    
  return 1;
}

/* This one updates everything in the event that you've added pages. */
void rebuild_manual_index() {
  directories = ([ ]);
  files = ([ ]);
  path_files = ([ ]);
  todo = ({ "" });
  sort_manual_dirs();
}

void dest_me() {
  rebuild_manual_index();
}

/* This one builds the data that the get_ commands read from. */
void sort_manual_dirs() {
  string *dirs;
  int i,j,k,m;
  string *f;
  string *tmp = ({ });
  string *tmp2;
  mapping t;
  int sz;
  string *newtodo = ({ });
  
  if(!todo)  /* The system is just starting up... */
    todo = ({ "" });
  else if(!sizeof(todo))
    return;
  
  for(k=0;k<sizeof(todo);k++) {
    f = ({ });
    dirs = ({ });
    tmp = ({ });
    
    for(i=0;i<sizeof(MERGEDIRS);i++) {
      tmp2 = get_dir(MANDIR+MERGEDIRS[i]+todo[k]);
      if(tmp2)
        tmp += (tmp2 - tmp);
    }
    
    for(i=0;i<sizeof(tmp);i++) {
      if(tmp[i][strlen(tmp[i])-6..strlen(tmp[i])-1] == "README")
        continue; /* We'll deal with these later. */
        
      for(j=0;j<sizeof(MERGEDIRS);j++)
        if((sz = file_size(MANDIR+MERGEDIRS[j]+todo[k]+tmp[i])) != -1)
          break;
      if(sz == -2) { /* It's a directory */
        for(m=0;m<sizeof(MERGEDIRS);m++)  /* Find the README */
          if(file_size(MANDIR+MERGEDIRS[m]+todo[k]+tmp[i]+"/README") >= 0)
            break;
        
        if(m == sizeof(MERGEDIRS))
          m = 0;
        
        files[tmp[i]] = MERGEDIRS[m]+todo[k]+tmp[i]+"/README";
        path_files[todo[k]+tmp[i]] = MERGEDIRS[m]+todo[k]+tmp[i]+"/README";
        newtodo += ({ todo[k]+tmp[i]+"/" });
        dirs += ({ tmp[i] });
      }
      else { /* It's a document. */
        files[tmp[i]] = MERGEDIRS[j]+todo[k]+tmp[i];
        path_files[todo[k]+tmp[i]] = MERGEDIRS[j]+todo[k]+tmp[i];
        f += ({ tmp[i] });
      }
    }
    
    tmp = explode(todo[k],"/");
    t = directories;
    for(i=0;i<sizeof(tmp);i++)
      t = t[tmp[i]];
    
    for(i=0;i<sizeof(dirs);i++)
      t[dirs[i]] = ([ ]);
    t["."] = f; 
  }
  
  todo = newtodo;
  
  if(sizeof(todo))
    call_out("sort_manual_dirs",2);
} 

/* Diagnostics.  I'll probably leave them in.  If these are different
   sizes, you have name-collisions somewhere.  Not the greatest thing,
   but I guess it can be lived with.
*/
int size_of_files() {  return sizeof(files);  }
int size_of_path_files() {  return sizeof(path_files);  }
