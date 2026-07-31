int main(object me, string arg)
{
	string mail, str;

	if (!arg) return 0;
	if (sscanf(arg, "%s %s", mail, str) != 2) return 0;
	"/adm/daemons/smtpd"->send_mail(me, mail, "测试邮件", str);
	return 1;
}
private int test()
{
return 100;
}
