inherit CMD;

private nomask void main(string arg)
{
   object ob;
   string err;

   if (!arg)
   {
      out("Usage: removewizard <user>\n");

      return;
   }

   if (!check_privilege(1) && (SECURE_D->query_is_wizard(this_body()->query_userid()) < 4))
   {
      out("You need to be an admin in order to remove wizards.\n");

      return;
   }

   arg = lower_case(arg);

   if (adminp(arg))
   {
      error(sprintf("** '%s' is an admin and cannot be dewizzed.\n", capitalize(arg)));

      return;
   }
   else if (!USER_D->user_exists(arg))
   {
      printf("** Error: '%s' doesn't actually exist as a user.\n", arg);

      return;
   }
   else if (!SECURE_D->query_is_wizard(arg))
   {
      printf("** '%s' is not a wizard.\n", capitalize(arg));

      return;
   }

   err = SECURE_D->delete_wizard(arg);

   if (err)
   {
      printf("** Error: %s\n", err);
      return;
   }

   SECURE_D->set_protection(wiz_dir(arg), 1, -1);

   printf("'%s' is no longer a wizard.\n", capitalize(arg));

   //### switch to an action?
   ob = find_user(arg);

   if (ob)
   {
      tell(ob, "You are no longer a wizard.  Changing bodies...\n");

      ob->force_me("su");

      ob = find_user(arg);

      ob->remove_channel("admin");
      ob->remove_channel("wiz");
   }
}