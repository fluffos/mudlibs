#include <npc.h>

void
create_monster()
{
    set_name("mayor's secretary");
    set_id(({"secretary"}));
    set_short("Mayor's secretary");
    set_long("The mayor's secretary has always much work to do.");
    set_alignment(AL_GOOD);
    set_level(12);
    set_ac(15);
    set_wc(15);
    set_gender(G_FEMALE);
    load_chat(10, ({
	"Secretary says: Please, don't disturb the mayor.",
	"Secretary says: The mayor is a busy man.",
	"Secretary says: The mayor is in a meeting.",
	"Secretary asks: May I help you?"
      }));
    load_a_chat(15, ({
	"Secretary says: Please leave!",
	"Secretary says: You are disturbing the mayor!",
	"Secretary screams: Someone, call the guards!",
	"Secretary screams: Help, call the guards!"
      }));
}
