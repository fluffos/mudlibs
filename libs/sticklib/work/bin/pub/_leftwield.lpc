
inherit "/bin/pub/_wield";

varargs nomask status
leftwield_cmd(string s, object me)
{
    if (!s) return notify_fail("Wield what in left hand?\n"), 0;
    return wield_cmd(sprintf("%s in left hand", s), me);
}
