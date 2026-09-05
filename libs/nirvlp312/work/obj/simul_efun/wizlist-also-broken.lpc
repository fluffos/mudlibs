#include "/sys/wizlist.h"

varargs void wizlist(string name)
{
    int i, pos, total_cmd;
    int *cmds;
    mixed *a;
    mixed *b;

    if ((int)this_player()->query_level() < 100)  {
        write("The wizlist command has no purpose outside of administration\n"+
              " diagnostics.  Therefore, it has been disabled.\n");
        return 0;
    }
    if (!name) {
      name = this_player()->query_real_name();
        if (!name) {
            write("Need to provide a name of 'ALL' to the wizlist function.\n");
            return;
        }
    }
    a = transpose_array(wizlist_info());
    cmds = a[WL_COMMANDS];
    a[WL_COMMANDS] = a[0];
    a[0] = a[WL_COMMANDS];
    a[WL_COMMANDS] = cmds;

    if ((pos = member(a[WL_NAME], name)) < 0 && name != "ALL") {
        write("No wizlist infor for '"+name+"' found.\n");
        return;
    }
    b = allocate(sizeof(cmds));
    for (i=sizeof(cmds); i;) {
        b[<i] = i;
        total_cmd += cmds[--i];
    }
    a = transpose_array(a + ({b}) );
    if (name != "ALL") {
        if (pos + 18 < sizeof(cmds)) {
            a = a[pos-2..pos+2] + a[<15..];
        } else if (pos < sizeof(cmds) - 13) {
            a = a[pos-2..];
        } else {
            a = a[<15..];
        }
    }
    write("\nWizard top score list\n\n");
    if (total_cmd == 0)
        total_cmd = 1;
    for (i=sizeof(a); i;) {
        b = a[<i--];
        if (b[WL_GIGACOST] > 1000)
            printf("%-15s %5d %2d%% (%d)\t[%d%4dk,%5d] %6d %d\n",
              b[WL_NAME], b[WL_COMMANDS],
              b[WL_COMMANDS] * 100 / total_cmd, b[<1],
              b[WL_GIGACOST] / 1000,
              b[WL_COST] / 1000 + (b[WL_GIGACOST] % 1000) * 1000000000,
              b[WL_HEART_BEATS], b[WL_EXTRA], b[WL_ARRAY_TOTAL]
            );
        else
            printf("%-15s %5d %2d%% (%d)\t[%4dk,%5d] %6d %d\n",
              b[WL_NAME], b[WL_COMMANDS],
              b[WL_COMMANDS] * 100 / total_cmd, b[<1],
              b[WL_COST] / 1000 + (b[WL_GIGACOST] % 1000) * 1000000000,
              b[WL_HEART_BEATS], b[WL_EXTRA], b[WL_ARRAY_TOTAL]
            );
    }
    printf("\nTotal         %7d     (%d)\n\n", total_cmd, sizeof(cmds));
}

/* Old code below....
  else if(wizard)
  {
    efun::wizlist(wizard);
  }
  else
  {
    efun::wizlist();
  }
*/

