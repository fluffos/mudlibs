
object database;

#define BASE_DIR     "players/milamber/"
#define METADATABASE (BASE_DIR+"metadatabase")
#define BOARD        (BASE_DIR+"board")

#define allnotes()        ((int *)database->AllNotes())
#define lock(note)        ((status)database->Lock(note))
#define unlock(note)      ((status)database->Unlock(note))
#define get_new_note()    ((int)database->GetNewNote())
#define delete_note(note) ((status)database->DeleteNote(note))
#define current_note()    ((int)database->CurrentNote())
#define num_notes()       ((int)database->NumNotes())
#define deleted(note)     ((status)database->Deleted(note))
#define title(note)       ((string)database->Title(note))
#define made(note)        ((int)database->Made(note))
#define author(note)      ((string)database->Author(note))
#define body(note)        ((string)database->Body(note))
#define comments(note)    ((int *)database->Comments(note))
#define comments_to(note) ((int *)database->CommentsTo(note))
#define locked(note)      ((mixed *)database->Locked(note))
#define add_body(note,s)  ((void)database->AddBody(note,s))
#define add_comment(n,s)  ((void)database->AddComment(n,s))
#define add_comment_to(n,s)  ((void)database->AddCommentTo(n,s))
#define set_head(n,a,b,c,d) ((void)database->SetHead(n,a,b,c,d))
#define set_title(n,a)    ((void)database->SetTitle(n,a))
#define set_body(n,a)     ((void)database->SetBody(n,a))
#define init_database(s)  {if(name) database=METADATABASE->query_database(s);}
#define LINE "-----------------------------------------------------------------------------\n"

