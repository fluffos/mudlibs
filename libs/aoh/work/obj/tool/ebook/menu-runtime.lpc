/*
** Book of Errors
** Runtime-Errors-Menu
** Author: Thragor@Nightfall, 05jun96
** Update: Thragor@Nightfall, 18jun96
**
** Code continues at line: 28
**
** Functions:
**  void runtime_command()
**    Parse the input the player made and call the corresponding function (or print
**    an error-message).
**    Commands:
**      ? Help
**      d<nr> Delete error in Line
**      q Back to overview
**      h<nr> Help on errors in line <nr>
**      e Edit file
**      <nr> Print more detailed informations about the errors.
**
**  void runtime_prompt()
**    Print the prompt and await the input from the user. The prompt consists of a
**    brief help.
**
**  void print_runtime()
**    Print the list of runtime-errors.
*/

#include "ebook.h"

inherit EBOOK("menu-base");

public void runtime_command(string cmd)
{
  int line,*lines;

  if (!TP) return;

  write("\n");

  if (cmd=="?")
    return print_menu_help(RUNTIME);

  lines = sort_array(m_indices(QueryLines()),SF(>));

  if (sscanf(cmd,"%d",line))
    if (!check_line(line,lines,SF(print_runtime))) return;
    else return print_err(lines[line-1],RUNTIME);

  if (cmd=="e") return edit_err(RUNTIME);

  if (sscanf(cmd,"d%d",line))
    if (!check_line(line,lines,SF(print_runtime))) return;
    else return delete_err(lines[line-1],RUNTIME);

  if (sscanf(cmd,"h%d",line))
    if (!check_line(line,lines,SF(print_runtime))) return;
    else return help_err(lines[line-1],"print_runtime");

  if (cmd=="s")
    return save_err(SF(print_runtime));

  if (cmd=="q") return print_dir();

  write("--- !!! Unknown command!\n");
  print_runtime();
}

public void runtime_prompt()
{
  write("\nEBook Runtime-Menu [<nr>, h<nr>, d<nr>, e, q, ?] ");
  input_to("runtime_command");
}

public varargs void print_runtime(string err)
{
  mapping errors,lineerrs;
  string text;
  int *lines,i;
  if (!TP) return;
  if (!err) err = QueryError();
  SetError(err);
  errors = QueryErrors();
  lineerrs = errors[err,ERRORS][RUNTIME];
  SetLines(lineerrs);
  lines = sort_array(m_indices(lineerrs),SF(>));
  text = "Runtime-Errors in "+err+"\n";
  text+= mkstr(strlen(text)-1,"=")+"\n\n";
  for(i=0;i<sizeof(lines);i++)
    text+=wrap(sprintf("%02d. Line: %04d, Error(s): %s\n",i+1,lines[i],
		       implode(m_indices(lineerrs[lines[i]]),mkstr(26)+"\n")),
	       75,28);
  smore(text,TP->QueryPageSize(),ME,"runtime_prompt");
}
