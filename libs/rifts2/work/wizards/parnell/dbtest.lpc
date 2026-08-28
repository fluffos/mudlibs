inherit "/std/Object";
void run_test();
int use_me();

void create() 
{
    ::create();
    set("short", "dbtest");
    set("id", ({"thing", "test", "dbtest", "it"}));
    set_long("this is a dbtest thing. try 'test' to use it");
}

void init()
{
    add_action((: use_me :), "test");
}

int use_me()
{
    run_test();
    return 1;
}
int db_handle;
void run_test()
{
    string result;
    int close_result;
     write("trying sqlite");
    result = catch(db_handle = db_connect("localhost", "/sqlitedata/mud.db", "muduser", 1));
    write(sprintf("db_handle: %d",db_handle));
    write(result);
    result = catch(close_result = db_close(db_handle));
    write(result);
    write(sprintf("close_result %d",close_result));
}