#include <network.h>

private nosave string *imud_ignored;
int do_block(string);
int do_unblock(string);

void wiz_commands() {
  add_command("block", "", (:do_block(0):));
  add_command("block", "<word'name'>", (:do_block($4[0]):));
  add_command("unblock", "<word'name'>", (:do_unblock($4[0]):));
} /* wiz_commands() */

int do_block(string str) {
  if (!str) {
    if (!sizeof(imud_ignored)) {
      write("Not blocking anyone.\n");
      return 1;
    }
    write("Blocking "+query_multiple_short(imud_ignored)+".\n");
    return 1;
  }
  if (!pointerp(imud_ignored))
    imud_ignored = ({ lower_case(str) }); 
  else 
    imud_ignored += ({ lower_case(str) });
  write("Okay, now ignoring intermud channel messages from "+str+".\n");
  write("Use \"unblock\" to remove.\n");
  return 1;
}

int do_unblock(string str) {
  int idx;

  if (!str)
    return notify_fail("Syntax: unblock <name>|all\n");
  if (!pointerp(imud_ignored) || !sizeof(imud_ignored))
    return notify_fail("You are not blocking anyone.\n");
  if (str == "all") {
    imud_ignored = 0;
    write("Okay, unblocked everyone.\n");
    return 1;
  }
  if ((idx = member_array(lower_case(str), imud_ignored)) == -1)
    return notify_fail("You are not blocking "+str+".\n");
  imud_ignored = delete(imud_ignored, idx, 1);
  write("Okay, removed "+str+" from your blocked list.\n");
  return 1;
}

int check_not_ignored(string who) {
  if (!pointerp(imud_ignored))
    return 1;
  return member_array(lower_case(who), imud_ignored) == -1;
}
