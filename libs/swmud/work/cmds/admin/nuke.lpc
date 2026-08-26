inherit CMD;
inherit M_INPUT;

private nomask void nuke_user(string userid, int skip_save)
{
   object o;
   mixed err;

   set_privilege(1);

   if (o = find_user(userid))
   {
      o->receive_private_msg("Sorry.  You're being nuked.\n");
      o->quit();
   }

   MAILBOX_D->get_mailbox(userid)->nuke_mailbox(1);
   MAILBOX_D->unload_mailbox(userid);

   // remove a bunch of files. note: some might not exist.
   err = rm(LINK_PATH(userid) + __SAVE_EXTENSION__);
   err = rm(USER_PATH(userid) + __SAVE_EXTENSION__);
   err = rm(PSHELL_PATH(userid) + __SAVE_EXTENSION__);
   err = rm(WSHELL_PATH(userid) + __SAVE_EXTENSION__);

   LAST_LOGIN_D->remove_user(userid, skip_save);

   err = SECURE_D->delete_wizard(userid);

   //### deal with clearing privs and stuff
   //### this should be enough, but may need more thought (this was a quicky)
   //### need to set it to something like @disabled so that unguarded() code
   //### in the wiz dir doesn't have priv 1 now.
   SECURE_D->set_protection(wiz_dir(userid), 1, -1);

   printf("'%s' has been nuked.\n", capitalize(userid));
}

private nomask void confirm_nuking(string name, string str)
{
   str = lower_case(str);

   if ((str != "y") && (str != "yes"))
   {
      write("Nuke aborted!\n");
      return;
   }

   nuke_user(name, 0);
}

private nomask void main(string arg)
{
   if (!arg)
   {
      out("Usage: nuke <user>\n");

      return;
   }

   if (!check_privilege(1) && (SECURE_D->query_is_wizard(this_body()->query_userid()) < 3))
   {
      out("You need to be an admin in order to delete characters.\n");

      return;
   }

   arg = lower_case(arg);

   if (!user_exists(arg))
   {
      out("User " + capitalize(arg) + " doesn't exist.\n");

      return;
   }

   printf("Are you sure you want to nuke '%s' ? ", capitalize(arg));
   modal_simple((: confirm_nuking, arg :));
}