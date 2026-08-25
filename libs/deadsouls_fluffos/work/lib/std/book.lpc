#include <lib.h>
#include <daemons.h>

inherit LIB_ITEM;

string* chapters, globalheader;
string Title = "Generic Book";
string Source = "/obj/book_source";
nosave mapping BookItems = ([]);
nosave mapping BookReads = ([]);

string globalstr, globalstr2;

void LoadBook();

string ReadBook(mixed args...){
    return BOOKS_D->GetBookRead(Source, args);
}

string ReadBookIndex(){
    return BOOKS_D->GetBookIndex(Source);
}

void SetTitle(string title){
    if(title) Title = title;
    BOOKS_D->SetBookTitle(Source, title);
}

mixed GetTitle(){
    return BOOKS_D->GetBookTitle(Source);
}

void SetSource(string source){
    if(source && directory_exists(source)) Source = source;
}

string GetSource(){
    if(Source) return Source;
    else return "";
}

mixed *eventLoadChapters(){
    return BOOKS_D->LoadChapters(Source);
}

string eventLoadIndex(){
    return BOOKS_D->LoadIndex(Source);
}

void create(){
    ::create();
    call_out( (: LoadBook :), 1);
    SetDefaultRead("Try \"read chapter 1 in book\" or "
            "\"read index in book\"");
}

void init(){
    ::init();
}

void LoadBook(){
    mixed *map_array = this_object()->eventLoadChapters();
    if(!map_array || sizeof(map_array) == 0) return ;

    if (arrayp(map_array)) {
      foreach(mapping m in map_array) {
        foreach(mixed key, mixed val in m) {
          AddItem(key, val);
        }
      }
    } else {
      SetItems((mapping) map_array);
    }
    AddItem( "index", "This is a list of the chapters in this book.");
    SetRead("index", (: ReadBookIndex :));
    foreach(mixed key, mixed val in map_array){
        SetRead(key, (: ReadBook :));
    }
}
