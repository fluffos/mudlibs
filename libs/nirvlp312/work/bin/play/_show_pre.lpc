int cmd_show_pre()
{
  if (!this_player()->is_testchar())
    return 0;
  this_player()->toggle_test_pretitle();
  write("Your test character pretitle is "
        this_player()->query_show_test_pretitle() ? "showing"
                                                  : "not showing"
        + ".\n");
  return 1;
}
