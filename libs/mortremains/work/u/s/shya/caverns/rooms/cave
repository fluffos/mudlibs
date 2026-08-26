#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "author", "shya" );
    set( "light", 0 );
    set( "short", "cave entrance (e,w)" );
    set( "exits", ([
      "east" : "/u/s/shya/cave3.c",
      "west" : "/u/s/shya/cave1.c",
    ]) );
    set("pre_exit_func", ([
        "east" : "roots_check"
    ]) );
    set( "item_desc", ([
            "cave": "The sheer size of it makes you feel insignificant and alone.\n",
            "sounds" : "Low rumbling noises."        
    ]));
}
int roots_check()
{
  if (present("roots", TO)) {
    write("The roots block your way.\n");
    return 1;
  }
  return 0;
}


void on_roots_die ()
{
    set( "long", @EndText
You are still in the entrance of a cave. 
The cave continues to the east further into the darkness.  
This seems like a good enough place to hide, 
except for the wierd sounds coming from further inside. 
Is that a dragon??? A hole has been hacked
through the tangled mass of roots allowing you to proceed east.
EndText
    );
}


void reset ()
{
    object bat, roots;

    seteuid( getuid() );
    ::reset();
    if (! present("roots")) {
        set( "long", @EndText
You are still in the entrance of a cave. 
The cave continues to the east further into the darkness.  
This seems like a good enough place to hide, 
except for the wierd sounds coming from further inside. 
Is that a dragon???
A tangled mass of roots blocks your progress east.
EndText
        );
        roots = clone_object("/u/s/shya/roots.c");
	  if (roots)
          roots->move(this_object());
    }

    if (! present("bat")) {
        bat = clone_object("/u/s/shya/bat.c");
	  if (bat)
            bat->move(this_object());
    }

}
