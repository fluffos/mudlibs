// This is a Library handler, (as in books rather than quest information)
#define SAVE_FILE "/save/handlers/book_libraries"
#include "/secure/std/classes/book_repository"
mapping libraries;


/** @ignore yes */
void load_me(){
  if ( unguarded( (: file_exists, SAVE_FILE + ".o" :) ) )
    unguarded( (: restore_object, SAVE_FILE :) );
} /* load_me() */

/** @ignore yes */
void save_me(){
  unguarded( (:save_object, SAVE_FILE :) );
} /* save_me() */

/** @ignore yes */
void create()
{
  load_me();
  if(!libraries)
    libraries = ([ ]);
} /* create() */

/** @ignore yes */
void dest_me(){
 save_me();
}

int setup_library(string lib_name, object lib_room_ob){
 if(member_array(lib_name,keys(libraries)) > -1)
   return 0;

   libraries[lib_name] = new(class library, name: lib_name, books: ([ ]), 
      owners: ({ }), authorised_librarians: ({ }), 
         location: file_name(lib_room_ob) );
   save_me();
   return 1;
}

void delete_library(string lib_name){
 if(member_array(lib_name,keys(libraries)) == -1)
   return ;
   
  map_delete(libraries,lib_name);
  save_me();
}

string *query_libraries(){return keys(libraries); }

void add_owner(string lib_name, string owner){
 if(member_array(lib_name,keys(libraries)) == -1)
   return;
 
 libraries[lib_name]->owners += ({ owner });
 save_me();
}

void remove_owner(string lib_name, string owner){
 if(member_array(lib_name,keys(libraries)) == -1)
   return;
 libraries[lib_name]->owners -= ({ owner });
 if(!sizeof(libraries[lib_name]->owners))
  event(users(),"inform",file_name(TO)+" reports no owners listed in library"+
      libraries[lib_name]->name+":"+libraries[lib_name]->location,"debug");

  save_me();
  return;
}

string *query_owners(string lib_name){
   if(member_array(lib_name,keys(libraries)) == -1)
   return 0;
   
   return libraries[lib_name]->owners;
}

string *query_librarians(string lib_name){
   if(member_array(lib_name,keys(libraries)) == -1)
   return 0;
   
   return libraries[lib_name]->authorised_librarians;
}

void add_librarian(string lib_name, string librarian){
 if(member_array(lib_name,keys(libraries)) == -1)
   return;
 
 libraries[lib_name]->authorised_librarians += ({ librarian });
 save_me();
}

void remove_librarian(string lib_name, string librarian){
 if(member_array(lib_name,keys(libraries)) == -1)
   return;
 libraries[lib_name]->authorised_librarians -= ({ librarian });
 
 save_me();
  return;
}

string *query_all_books_short(string lib_name){
 string *bks = ({ });
 if(member_array(lib_name,keys(libraries)) == -1)
         return ({ });
 foreach (class book b in  values(libraries[lib_name]->books)){
         bks += ({ b->short });        
 }
 return bks;
}

class book *query_all_books_details(string lib_name){
 class book *bks = ({ });
 if(member_array(lib_name,keys(libraries)) == -1)
         return ({ });
 foreach (class book b in  values(libraries[lib_name]->books)){
         bks += ({ b });        
 }
 return bks;
}

class book query_book_details(string lib_name, string book){
 if(member_array(lib_name,keys(libraries)) == -1)
   return 0;
   
  if(member_array(book,keys(libraries[lib_name]->books))== -1)
   return 0;
   
   return libraries[lib_name]->books[book];
}

void add_book(string lib_name, string book_filename, int copyable){
  
  if(member_array(lib_name,keys(libraries)) == -1)
   return;
   
   if(member_array(book_filename,keys(libraries[lib_name]->books)) > -1)
      if(load_object(book_filename)->query_short() ==
            libraries[lib_name]->books[book_filename]->short){
         return;
      }else{
   event(users(),"inform",file_name(TO)+" duplicate book title found trying to "
      "be added to library:" +libraries[lib_name]->location+" "+book_filename+
      " & " + libraries[lib_name]->books[book_filename]->filename,"debug");
      return ;
     }
 
  libraries[lib_name]->books[book_filename] = new(class book, 
     short: load_object(book_filename)->query_short(),
     filename: book_filename,
     author: find_object(book_filename)->query_author(),
     keywords: find_object(book_filename)->query_keywords(),
     loanee: 0,
     copyable: copyable);
 
    save_me();
    return;
 }

 
 void remove_book(string lib_name, string book_filename){
    if(member_array(lib_name,keys(libraries)) == -1)
   return;
   
   if(member_array(book_filename,keys(libraries[lib_name]->books)) == -1)
     return ;
      map_delete(libraries[lib_name]->books,book_filename);
    save_me();
   
   return;
 }
 
string query_loanee(string lib_name, string book_filename){
  if(member_array(lib_name,keys(libraries)) == -1)
   return 0;
   
   if(member_array(book_filename,keys(libraries[lib_name]->books)) == -1)
     return 0;
   
   return libraries[lib_name]->books[book_filename]->loanee;
 }
 
 void delete_loanees(string lib_name, string book_filename){
      if(member_array(lib_name,keys(libraries)) == -1)
   return ;
   
   if(member_array(book_filename,keys(libraries[lib_name]->books)) == -1)
     return ;
   
   libraries[lib_name]->books[book_filename]->loanee = 0;     
 }
 
 // Warning this wipes the loan info from all books in the library
 void delete_library_loans(string lib_name){
      if(member_array(lib_name,keys(libraries)) == -1)
        return;
      
      foreach(string str in keys(libraries[lib_name]->books)){
              libraries[lib_name]->books[str]->loanee = 0;      
      }
      
      save_me();
 }
 
 int add_loanee(string lib_name, string book_filename, string p_name){
     if(member_array(lib_name,keys(libraries)) == -1)
   return 0;
   
   if(member_array(book_filename,keys(libraries[lib_name]->books)) == -1)
     return 0;      
   
   if(libraries[lib_name]->books[book_filename]->loanee != 0)
     return 0;
   
   libraries[lib_name]->books[book_filename]->loanee =  p_name ;
   save_me();
   return 1;
 }
 
 void remove_loanee(string lib_name, string book_filename, string p_name){
   if(member_array(lib_name,keys(libraries)) == -1)
   return ;
   
   if(member_array(book_filename,keys(libraries[lib_name]->books)) == -1)
     return ;    
   
     if(p_name != libraries[lib_name]->books[book_filename]->loanee)
        return ;
   
   libraries[lib_name]->books[book_filename]->loanee = 0;
   save_me();
   return ;
 }
 
string query_filename_from_title(string lib_name, string b_title){
    if(member_array(lib_name,keys(libraries)) == -1)
     return 0;

    foreach (string str in keys(libraries[lib_name]->books)){
      if(libraries[lib_name]->books[str]->short == b_title)
          return str;
    }
   return 0;
}

string *query_all_titles_in_library(string lib_name){
        string *bks = ({ });
        if(member_array(lib_name,keys(libraries)) == -1)
     return 0;
        
        foreach (string str in keys( libraries[lib_name]->books)){
                bks += ({ libraries[lib_name]->books[str]->short });     
        }
    return bks;
}
