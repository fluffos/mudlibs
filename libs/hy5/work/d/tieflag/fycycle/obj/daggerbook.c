 inherit __DIR__"tutor";
void create()
{
        set_name("石凿大字", ({ "dagger","火墙","wall" }));    
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                        "火墙中央凿着「穷图匕露 揭竿而起」八个大字，四周围绕着的火线，似乎是一种招式。\n");
                set("no_shown", 1);
                set("no_get",1);
                set("teaching", "dagger");
                set("teaching_limit", 400);
        }
        
 }      
