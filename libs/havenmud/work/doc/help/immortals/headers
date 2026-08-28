.h files
--------

.h files are pretty easy to use.  There are examples everywhere (looking 
in the /domains/ directories is a good place to look if you want more 
examples).  They are important for various reasons, like cleaner code 
and the ability to move whole areas around the mud without having to 
change more than just one file.  Here is an example of what one looks 
like (you can find it in /domains/soleil/soleil.h):

#define SOLEIL_DIR   "/domains/soleil"
#define S_ROOM       SOLEIL_DIR + "/room"
#define S_NPC        SOLEIL_DIR + "/npc"
#define S_OBJ        SOLEIL_DIR + "/obj"

The first line (#define SOLEIL_DIR "/domains/soleil") tells the mud that 
whenever the string SOLEIL_DIR shows up, replace it with "/domains/soleil".
The second line (#define S_ROOM SOLEIL_DIR + "/room") tells the mud that
whenever S_ROOM comes up, it should replace it with SOLEIL_DIR + "/room",
which amounts to "/domains/soleil/room" when it's all done.  The third 
and fourth lines do just about the same thing, except that they reference 
where the NPC's and OBJ's are.

To make your own, you just need to replace the info in there with 
whatever your directories are and whatever you want your key phrases 
to be.  Just remember to #include the .h file in all the files you use 
those key phrases in.  Here are some examples of using it:

SetExits( ([
             "east" : S_ROOM + "/temple",
        ]) );

SetInventory( ([
                 S_NPC + "/banker_aegri" : 1,
            ]) );

SetInventory( ([
                 S_OBJ + "/pole_short" : "wield pole in right hand",
            ]) );

SetDoor("out",S_ROOM + "/cemet");

It's just like using any normal SetExits() or SetInventory() or 
SetDoor() or anything else that references a path, only you replace
part of that path with a shorter phrase.

Now go look at some of the /domains, like /domains/haven/ or 
/domains/jidoor, to see some more examples.

