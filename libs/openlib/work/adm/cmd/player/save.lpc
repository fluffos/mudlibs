#include <command.h>
#include <daemons.h>

int
main()
{
  // Just save body, connection should not have changed
  if( unguarded((: SAVE_D->request_save(this_player()) :), 1) &&
      this_player()->save_player() )
    printf("save: user %s saved.\n", this_player()->query_cap_name());
  else
    printf("save: unable to save!! Please report this to a wizard.\n");

  return 1;
}
