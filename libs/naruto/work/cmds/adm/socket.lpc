// socket.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
#ifdef FLUFFOS
	printf("%O\n", socket_status());
#else
	write(dump_socket_status());
#endif
	return 1;
}
