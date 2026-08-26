// Last modified by deforce on 11-20-2006
#include <mudlib.h>
#include <commands.h>

inherit M_INPUT;
inherit M_MESSAGES;
inherit CMD;

#include <suicide_messages.h>

private nomask void nuke_player()
{
   object user_object;
   mixed err;
   string userid = this_user()->query_userid();

   if (user_object = find_user(userid))
   {
      string suicide_message = get_suicide_message();

//      tell(user_object, "\n%^YELLOW%^" + action(({ user_object }), suicide_message)[0] + "%^RESET%^\n");
      tell(user_object, "\nGoodbye.\n");
      tell(users() - ({ user_object }), this_body()->action(({ this_body() }), "\n%^YELLOW%^" + suicide_message + "%^RESET%^\n")[1]);

      user_object->quit();
   }

   MAILBOX_D->get_mailbox(userid)->nuke_mailbox(1);
   MAILBOX_D->unload_mailbox(userid);

   // remove a bunch of files. note: some might not exist.
   err = rm(LINK_PATH(userid) + __SAVE_EXTENSION__);
   err = rm(USER_PATH(userid) + __SAVE_EXTENSION__);
   err = rm(PSHELL_PATH(userid) + __SAVE_EXTENSION__);
   err = rm(WSHELL_PATH(userid) + __SAVE_EXTENSION__);

   LAST_LOGIN_D->remove_user(userid, 1);

   err = SECURE_D->delete_wizard(userid);

   SECURE_D->set_protection(WIZ_DIR "/" + userid, 1, -1);
}

private nomask void confirm_current_password(string s)
{
   write("\n");

   if (!this_user()->matches_password(s))
   {
      write("Invalid password: Suicide cancelled.\n");
   }
   else
   {
      unguarded(1, (: nuke_player() :));
   }
}

private void main()
{
   modal_simple((: confirm_current_password :),
      "\nEnter your current password to confirm suicide: ", 1);
}

nomask int valid_resend(string ob)
{
   return ob == CMD_OB_SUICIDE;
}