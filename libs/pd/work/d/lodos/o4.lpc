#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Obstacle Course: Room 3");
   set_long("%^RESET%^%^ORANGE%^"
     "The top of this tall rock is about twenty feet above the lava "
     "pool. The crag steeply slopes downwards, closer to the lava pool. An iron "
     "bar streches from this rock north to a platform a little higher than "
     "this. Below, liquid hot magma bubbles and spits into the air. Sharp rocks "
     "make it a bit easier to decend the slope of the rock. The end of a single "
     "branch can be seen on the eastern edge of the rock.");
   set_items(([
     "branch" : "A small branch grows out of the eastern side of this rock. It "
                "has a few leaves, but it's main feature is a tiny hand, gripping "
                "it for dear life.",
     "hand"   : "A child's hand holds on tight to the small branch. The little "
                "girl can barely be seen.",
     "girl"   : "She was trying to complete this obstacle course to join the "
                "glorious ranks of the archangels. She must have slipped and "
                "fallen from the rock. Now, she hangs on the brink of death, "
                "crying to herself. From your position, it is possible to save "
                "the girl. The only problem with rescuing her, is that by the "
                "way the rocks are positioned above the lava pool, you would "
                "definatly forfeit your own life in exchange for hers. Perhaps "
                "it would be best to look at your options.",
     "options": "You could either save the girl or leave her. It may be hard to "
                "sleep for a few nights, but knowing that in her quest for angels "
                "she found heaven might soothe you. On the other hand, she had "
                "fallen while trying to complete this obstacle course. She knew "
                "the risks before trying to cross the bar. You cannot make a "
                "desicion on what to do.",
     "foo"    : "bar",
     "bar"    : "A single iron bar streches from this rock across the pool of  "
                "hot magma to a platform. You could cross it with minimal "
                "difficulty.",
     "pool"   : "A boiling pool of liquid hot magma.",
     "sky"    : "The sky is a white expanse as far as the eye can see."
   ]));
   set_properties(([ "light" : 2, "night light" : 2, "outdoors" : 1,
     "no bump" : 1, "no attack" : 1, "no magic" : 1, "no teleport" : 1,
     "no steal" : 1 ]));
   set_exits(([
     "down" : ROOMS"o5"
   ]));
}

void finish_crossing(object tp) {
   message("info", "You hop off the end of the bar and land on a platform. On "
     "your landing you slip and fall towards the pool of lava! You manage to "
     "grab the bar and save yourself, though suffer a few injuries.", tp);
   tp->damage(90);
   tp->move(ROOMS"o3");
}

int cross(string str) {
   if (!str || str != "bar") return notify_fail("Cross what?\n");
   this_player()->set_paralyzed(3, "You must concentrate completely on crossing "
     "the pool of lava.");
   write("You carefully balance on top of the bar and begin to cross.");
   call_out("finish_crossing", 3, this_player());
   return 1;
}

int save(string str) {
   if (!str || str != "girl") return 0;
   write(@ENDTEXT
%^YELLOW%^You extend your hand to help the girl.
%^BOLD%^%^WHITE%^With her free hand, she grasps yours and holds on tightly.
%^YELLOW%^Leaning back, you pull the little girl onto the rocks.
%^YELLOW%^You feel more experienced from your good deed.
%^BOLD%^%^WHITE%^She stumbles onto the rocks. You are safe! A rocks slips from beneath
%^BOLD%^%^WHITE%^you, sending you plummeting towards the lava!
%^RED%^Your body sinks slowly into the lava, and you can only think if this
%^RED%^torture was worth the girls life...
ENDTEXT);
write(@INFERNO
You die a horrible death.

                                _,.-----.,_
                             ,-~           ~-.
                           ,^___           ___^.
                          /~"   ~"   .   "~   "~\
                         Y  ,--._    I    _.--.  Y
                         | Y   / ~-. | ,-~ \   Y |
                         | |  |     }:{     |  | |
                         j l  (    / | \    )  ! l
                      .-~  (__,.--" .^. "--.,__)  ~-.
                     (           / / | \ \           )
                      \.____,   ~  \/"\/  ~   .____,/
                       ^.____                 ____.^
                          | |T ~\  !   !  /~ T| |
                          | |l   _ _ _ _ _   !| |
                          | l \/V V V V V V\/ j |
                          l  \ \|_|_|_|_|_|/ /  !
                           \  \[T T T T T TI/  /
                            \  `^-^-^-^-^-^'  /
                             \               /
                              \.           ,/
                                "^-.___,-^"
INFERNO);
   this_player()->move(ROOMS"adeath");
   return 1;
}

void init() {
 ::init();
   add_action("save",  "rescue");
   add_action("cross", "cross");
}
