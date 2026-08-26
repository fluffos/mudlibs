// Last edited by deforce on 12-04-2007
// Rust wrote this and was a bad boy and didn't attach a header - Beek

#include <mudlib.h>

inherit CMD;
inherit M_INPUT;

private nomask void confirm_new_password(string pass1, string pass2)
{
   if (pass1 != pass2)
   {
      write("\nPassword confirmation did not match.\n");
   }
   else
   {
      this_user()->set_password(pass1);
      write("\nPassword successfully changed.\n");
   }
}

private nomask void get_new_password(string pass)
{
   if (strlen(pass) < 6)
   {
      write("\nYour password must be at least 6 characters.\n");
   }
   else
   {
      modal_simple((: confirm_new_password, pass :), "\nAgain to confirm: ", 1);
   }
}

private nomask void confirm_current_password(string pass)
{
   if (!this_user()->matches_password(pass))
   {
      write("\nInvalid password.\n");
   }
   else
   {
      modal_simple((: get_new_password :), "\nEnter new password: ", 1);
   }
}

private void main()
{
   modal_simple((: confirm_current_password :), "Enter your current password: ", 1);
}