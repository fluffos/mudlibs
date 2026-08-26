// Last edited by deforce on 01-27-2007
// userinfo.c -- user information
// Created by Deathblade on 08-21-1995
#include <config.h>
#include <mudlib.h>
#include <security.h>

void sw_body_handle_new_logon();
object query_body();
void save_me();

varargs void modal_push(function input_func, mixed prompt, int secure, function return_to_func);
varargs void modal_func(function input_func, mixed prompt, int secure);
void modal_pop();

// States
#define GENDER_QUERY            0
#define GOT_GENDER              1
#define GOT_EMAIL               2
#define GOT_REAL_NAME           3
#define GOT_URL                 4

private string  email;
private string  real_name;
private int     ed_setup;
private string  url;

// Temporary new user vars
nosave private int n_gen = -1;

//### wah! get rid of this. need by sw_body.c; should move to NEW_USER_D
protected nomask int query_n_gen()
{
   return n_gen;
}

nomask void set_ed_setup(int code)
{
   ed_setup = code;
   save_me();
}

nomask int query_ed_setup()
{
   return ed_setup;
}

nomask void set_real_name(string new_name)
{
   if (this_user() != this_object()) { error("Illegal attempt to set real name.\n"); }

   real_name = new_name;
   save_me();
}

nomask void set_email(string new_email)
{
   if (this_user() != this_object()) { error("Illegal attempt to set e-mail address.\n"); }

   email = new_email;
   save_me();
}

nomask void set_url(string new_url)
{
   if (this_user() != this_object()) { error("Illegal attempt to set URL.\n"); }

   url = new_url;
   save_me();
}

nomask string query_url()
{
   return url;
}

protected nomask varargs void userinfo_handle_logon(int state, mixed extra, string arg)
{
   switch(state)
   {
      case GENDER_QUERY:
         modal_push((: userinfo_handle_logon, GOT_GENDER, 0 :), "Are you male or female? ");
         break;
      case GOT_GENDER:
         arg = lower_case(arg);

         if ((arg == "y") || (arg == "yes"))
         {
            write("OK, which one are you?\n");
            return;
         }
         else if ((arg == "n") || (arg == "no"))
         {
            write("Well, which one would you have liked to be?\n");
            return;
         }
         else if ((arg == "f") || (arg == "female")) { n_gen = 2; }
         else if ((arg != "m") && (arg != "male"))
         {
            write("Please try again.  Are you male or female?\n");
            return;
         }
         else
         {
            n_gen = 1;
         }

         write("\nIf you prepend a # to the following responses (example, \"#Name\"), the info will be seen only by you and administrators.\n");

         modal_func((: userinfo_handle_logon, GOT_EMAIL, 0 :), "Your email address: ");
         break;
      case GOT_EMAIL:
         email = arg;
         modal_func((: userinfo_handle_logon, GOT_REAL_NAME, 0 :), "Your real name: ");
         break;
      case GOT_REAL_NAME:
         real_name = arg;
         modal_func((: userinfo_handle_logon, GOT_URL, 0 :), "Your website address: ");
         break;
      case GOT_URL:
         url = arg;

         // Done with this series of inputs
         modal_pop();

         write("\n");

         // Let's move on to introducing the character to the mud.
         if (file_size(NEW_PLAYER) <= 0)
         {
            sw_body_handle_new_logon();
            return;
         }

         more_file(NEW_PLAYER, 0, (: sw_body_handle_new_logon :));
   }
}