//passwd.c

//Tacitus @ LPUniversity
//17-OCT-05
//Standard command

/* Last edited on July 17th, 2006 by Tacitus */

int confirm_CurrentPassword(string str);
int i_NewPassword(string str);
int confirm_NewPassword(string str, string pass);

int main()
{
     write("Please enter your current password: ");
     input_to("confirm_CurrentPassword", 1);
     return 1;
}

int confirm_CurrentPassword(string str)
{

     if(crypt(str, str) != this_player()->query_link()->query_password())
     {
          write(RED + "\nError: " + NOR + "The password you provided does not match your current password.\n");
          return 1;
     }
     else
     {
          write("\nPlease enter your new password: ");
          input_to("i_NewPassword", 1);
          return 1;
     }
}

int i_NewPassword(string str)
{
    if(!stringp(str) || str == "")
    {
        write("\n\nError [passwd]: Invalid password.\n");
        return 1;
    }

     write("\nPlease enter your new password again: ");
     input_to("confirm_NewPassword", 1, str);
     return 1;
}

int confirm_NewPassword(string str, string pass)
{
     if(str != pass)
     {
          write(RED + "\nError: " + NOR + "Passwords do not match. Please try again.\n");
          return 1;
     }
     else
     {
          if(this_player()->query_link()->set_password(str)) 
            write(GRN + "\nSuccess: " + NOR + "Password changed succesfuly.\n");
          else write(RED + "\nError: " + NOR + "Unable to change password.\n");
          return 1;
     }
}

string help()
{
     return(" %^BOLD%^SYNTAX:%^RESET%^ passwd\n\n"
     "This command allows you to change your current passwd.\n"
     "You will be asked to enter your current passwd for\n"
     "security purposes and then it will request you to input\n"
     "your new passwd and then will ask again to confirm. After\n"
     "you have provided the requested information, the command\n"
     "will inform you if the change was succesful.\n");
}


